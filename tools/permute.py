#!/usr/bin/env python3
"""Set up (and optionally run) decomp-permuter on one function, wired to the
exact pipeline the gate uses.

    python tools/permute.py func_00112345                 # set up + verify
    python tools/permute.py func_00112345 --run -j2       # ... then permute (600 s, nice 10)
    python tools/permute.py func_00112345 --run --time 0  # ... without a time limit

Writes work/permute/<name>/ with base.c (the preprocessed unit), target.o (the
original), compile.sh (calls tools/cc.py with the unit's own cflags) and
settings.toml. Before anything runs it checks for drift: compile.sh on base.c
must produce the same .text as match.py's compile of the unit, and the
permuter's verdict (score 0 or not) must agree with match.py. thps64 lost days
to permuter setups that silently scored a different pipeline.

Weights: settings.toml gets a clean [weight_overrides] profile (CLEAN_WEIGHTS) by
default, so winners stay portable (no junk statements); --all-passes uses the
permuter's own defaults instead.

--run is bounded and low priority: --time SECONDS (default 600, 0 = none) and
--nice N (default 10) apply to the permuter and its compiles; outputs are
--best-only by default (--all-outputs to write every candidate). Any argument
permute.py does not know (-j2, --show-errors, ...) goes to the permuter.

decomp-permuter parses C, not C++. base.c drops extern "C" and declares bool
and a typedef per struct so pycparser reads it; compile.sh wraps the file in
extern "C" { } again before compiling, as C++.

C++ units (--cxx; automatic when the unit uses classes, members or this) are
first converted to C, and drift check 1 then proves that the C conversion
compiles to the same .text as the C++ unit (refused otherwise). Supported:
  - one `RET Class::Method(params) { ... }` definition (also const or static
    methods): it becomes `RET func_XXXXXXXX(struct Class* self, params)`;
  - classes/structs/unions with data members (anonymous unions/structs too) and
    single non-virtual inheritance: the base becomes a first member `_base`;
  - unqualified member names and `this` in the body -> self->x (self->_base.x);
    locals and parameters of the same name shadow members (a best-effort scan);
  - inline member helpers (also on other objects: p->Get(), o.Get(), Base::Get())
    -> `static inline RET Class_Get(struct Class* self, ...)`, emitted before the
    function; g++ inlines them exactly as it inlines the members;
  - virtual methods declared but not defined: a `struct _vte* _vtbl` goes after
    the fields of the class that first declares a virtual (g++ 2.95 layout), and
    virtual calls go through the 8-byte vtable entries {short delta; short index;
    void* pfn;} (entry 0 is RTTI, so the k-th virtual is _vtbl[k + 1]; the SN build uses no
    vtable thunks):
    ((RET (*)(void*, ...)) p->_vtbl[k + 1].pfn)((char*)p + p->_vtbl[k + 1].delta, ...);
  - out-of-line non-virtual members without a body: called through their g++ 2.95
    mangled name (Method__5ClassUiPv) declared extern, with self first.
Refused with a message: constructors/destructors/operators as the defined
function or used in it, new/delete, local objects of classes with a
constructor, destructor or vptr, multiple or virtual inheritance, overloaded
members, default arguments, static data members, templates, namespaces, C++
casts, virtual calls on expressions with
side effects, and calls whose class cannot be told (the receiver's type is
inferred from fields, parameters, locals, globals and function return types,
else the method name must belong to one class). Port the winner back with the
printed hint (also in <dir>/port_back.txt): self->x -> x, Class_M(p, ...) ->
p->M(...), the vtable expression -> p->Virtual(...), func_XXXXXXXX(self, ...) ->
Class::Method(...). Anything outside the subset: permute a hand-written C copy
with an explicit self pointer (--src work/<copy>.cpp) and port the shape back.
"""
import argparse
import os
import re
import shlex
import signal
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
from common import ROOT, compiler_config, file_cflags, tool, unit_path  # noqa: E402

PERMUTER = ROOT / "toolchain" / "decomp-permuter"


# The default weight profile ("clean"): favour passes whose output is natural, portable C++ and
# switch off passes that only win with dead or junk code (self-assignment, `if (x) {}`, `^ 0`, dummy
# comma, padding declarations, `if (1)` blocks, empty statements, removed AST nodes), which units
# may not contain. Written to settings.toml as [weight_overrides]; --all-passes leaves it out.
CLEAN_WEIGHTS = {
    "perm_temp_for_expr": 100,
    "perm_expand_expr": 25,
    "perm_reorder_stmts": 30,
    "perm_reorder_decls": 30,
    "perm_commutative": 20,
    "perm_inequalities": 15,
    "perm_condition": 10,
    "perm_reverse_cond": 10,
    "perm_compound_assignment": 10,
    "perm_chain_assignment": 8,
    "perm_long_chain_assignment": 3,
    "perm_split_assignment": 15,
    "perm_randomize_internal_type": 15,
    "perm_randomize_external_type": 5,
    "perm_randomize_function_type": 15,
    "perm_struct_ref": 10,
    "perm_inline": 10,
    "perm_cast_simple": 8,
    "perm_factor_mult": 4,
    "perm_factor_shift": 4,
    "perm_add_sub": 4,
    "perm_alias_array": 3,
    "perm_float_literal": 2,
    "perm_remove_var": 3,
    "perm_var_cond_block": 0,
    "perm_add_mask": 0,
    "perm_xor_zero": 0,
    "perm_refer_to_var": 0,
    "perm_sameline": 0,
    "perm_ins_block": 0,
    "perm_empty_stmt": 0,
    "perm_mult_zero": 0,
    "perm_dummy_comma_expr": 0,
    "perm_add_self_assignment": 0,
    "perm_duplicate_assignment": 0,
    "perm_pad_var_decl": 0,
    "perm_remove_ast": 0,
}

TI_TYPEDEF = re.compile(r"typedef\s+(\w+)\s+(\w+)\s+__attribute__\s*\(\s*\(\s*mode\s*\(\s*TI\s*\)\s*\)\s*\)\s*;")
# for pycparser only (compile.sh drops both lines): C has no bool, true or false
PRELUDE = "typedef _Bool bool;\nenum { false, true };\n"
EXTERN_C_BLOCK = re.compile(r'extern\s+"C"\s*\{')
EXTERN_C = re.compile(r'extern\s+"C"\s*')


def to_c(src):
    """The preprocessed unit as C the permuter can parse: no extern "C" (compile.sh wraps the whole
    file in one), and bool declared for pycparser (compile.sh removes that line again)."""
    out, depth = [], 0
    i = 0
    while i < len(src):
        m = EXTERN_C_BLOCK.match(src, i)
        if m:
            depth += 1
            i = m.end()
            # find the matching close brace of this block and drop it
            level, j = 1, i
            while j < len(src) and level:
                level += {"{": 1, "}": -1}.get(src[j], 0)
                j += 1
            src = src[:j - 1] + src[j:] if level == 0 else src
            continue
        out.append(src[i])
        i += 1
    text = EXTERN_C.sub("", "".join(out))
    # C++ uses struct names bare; C needs a typedef (also valid C++, so compile.sh keeps it)
    tags = dict.fromkeys(re.findall(r"\b(struct|union)\s+([A-Za-z_]\w*)\s*[{;]", text))
    typedefs = "".join(f"typedef {kw} {n} {n};\n" for kw, n in tags)
    # 128-bit types: pycparser cannot read __attribute__((mode(TI))); compile.sh restores it
    text = TI_TYPEDEF.sub(r"typedef \1 \2;", text)
    return PRELUDE + typedefs + text


def to_cpp(src_c, dst, ti_names):
    """Inverse of to_c for compile.sh: works on the permuter's regenerated source too."""
    t = Path(src_c).read_text()
    t = re.sub(r"^\s*typedef\s+_Bool\s+bool\s*;\s*$", "", t, flags=re.M)
    t = re.sub(r"enum\s*\{\s*false\s*,\s*true\s*\}\s*;", "", t)
    for n in ti_names:
        t = re.sub(rf"typedef\s+(\w+)\s+{n}\s*;", rf"typedef \1 {n} __attribute__((mode(TI)));", t)
    Path(dst).write_text('extern "C" {\n' + t + "\n}\n")


# ------------------------------------------------------------------------------------------------
# C++ -> C conversion (--cxx): see the module docstring for the supported subset.

class CxxError(Exception):
    pass


TOKEN = re.compile(r'''\s+|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'|[A-Za-z_$][\w$]*
    |0[xX][0-9a-fA-F]+[uUlL]*|(?:\d+\.?\d*|\.\d+)(?:[eE][-+]?\d+)?[fFuUlL]*
    |->\*?|::|<<=|>>=|\.\.\.|[-+*/%&|^<>=!]=|&&|\|\||\+\+|--|<<|>>|.''', re.X | re.S)
IDENT = re.compile(r"[A-Za-z_$][\w$]*$")
CLOSE = {"(": ")", "[": "]", "{": "}"}
BUILTIN_TYPES = {"void", "char", "short", "int", "long", "float", "double", "signed", "unsigned", "bool",
                 "_Bool", "const", "volatile", "register", "static", "struct", "union", "enum"}
KEYWORDS = BUILTIN_TYPES | {"if", "else", "for", "while", "do", "return", "switch", "case", "default", "break",
                            "continue", "goto", "sizeof", "typedef", "extern", "inline", "__inline",
                            "__attribute__", "true", "false", "self"}
NOT_SUPPORTED = {"new": "new-expressions", "delete": "delete-expressions", "throw": "exceptions",
                 "try": "exceptions", "static_cast": "C++ casts", "reinterpret_cast": "C++ casts",
                 "const_cast": "C++ casts", "dynamic_cast": "C++ casts", "typeid": "RTTI",
                 "operator": "operators", "template": "templates", "namespace": "namespaces",
                 "using": "using-declarations"}
MANGLE = {("void",): "v", ("char",): "c", ("signed", "char"): "Sc", ("unsigned", "char"): "Uc",
          ("short",): "s", ("short", "int"): "s", ("unsigned", "short"): "Us",
          ("unsigned", "short", "int"): "Us", ("int",): "i", ("signed",): "i", ("signed", "int"): "i",
          ("unsigned",): "Ui", ("unsigned", "int"): "Ui", ("long",): "l", ("long", "int"): "l",
          ("unsigned", "long"): "Ul", ("unsigned", "long", "int"): "Ul", ("long", "long"): "x",
          ("unsigned", "long", "long"): "Ux", ("float",): "f", ("double",): "d", ("bool",): "b"}


def tokenize(src):
    return [t for t in TOKEN.findall(src) if not t.isspace()]


def close_of(toks, i):
    """Index of the bracket closing toks[i]."""
    want, level = CLOSE[toks[i]], 0
    for j in range(i, len(toks)):
        if toks[j] == toks[i]:
            level += 1
        elif toks[j] == want:
            level -= 1
            if level == 0:
                return j
    raise CxxError(f"unbalanced {toks[i]!r}")


def open_of(toks, j):
    """Index of the bracket opening toks[j] (a closing bracket)."""
    want = {v: k for k, v in CLOSE.items()}[toks[j]]
    level = 0
    for i in range(j, -1, -1):
        if toks[i] == toks[j]:
            level += 1
        elif toks[i] == want:
            level -= 1
            if level == 0:
                return i
    raise CxxError(f"unbalanced {toks[j]!r}")


def top(toks):
    """(index, token) of toks outside any bracket group, groups reported by their opening token."""
    i = 0
    while i < len(toks):
        yield i, toks[i]
        i = close_of(toks, i) + 1 if toks[i] in CLOSE else i + 1


def split_top(toks, sep=","):
    parts, start = [], 0
    for i, t in top(toks):
        if t == sep:
            parts.append(toks[start:i])
            start = i + 1
    parts.append(toks[start:])
    return [p for p in parts if p]


def emit(toks):
    """Tokens back to source text (one space between tokens keeps every token intact)."""
    out, par = [], 0
    for t in toks:
        par += (t == "(") - (t == ")")
        out.append(t)
        out.append("\n" if t in (";", "{", "}") and par == 0 else " ")
    return "".join(out)


def is_funcdef(item):
    """item ends with a {...} group: is it a function body (not a struct body or initializer)?"""
    pre = [t for _, t in top(item[:open_of(item, len(item) - 1)])]
    assign = any(t == "=" and (k == 0 or pre[k - 1] != "operator") for k, t in enumerate(pre))
    return "(" in pre and not assign and not (pre and pre[0] in ("typedef", "enum"))


def split_items(toks, members=False):
    """Split a token list into declarations / definitions (top level or a class body)."""
    items, cur, i = [], [], 0
    while i < len(toks):
        t = toks[i]
        if not members and t == "extern" and toks[i + 1:i + 3] == ['"C"', "{"]:
            j = close_of(toks, i + 2)
            items += split_items(toks[i + 3:j])
            i = j + 1
            continue
        if members and not cur and t in ("public", "private", "protected") and toks[i + 1:i + 2] == [":"]:
            i += 2
            continue
        if t in CLOSE:
            j = close_of(toks, i)
            cur += toks[i:j + 1]
            i = j + 1
            if t == "{" and is_funcdef(cur):
                if i < len(toks) and toks[i] == ";":
                    i += 1
                items.append(cur)
                cur = []
            continue
        cur.append(t)
        i += 1
        if t == ";":
            items.append(cur)
            cur = []
    if cur:
        items.append(cur)
    return items


def declarator_name(piece):
    """The declared name in one declarator (`*p`, `a[4]`, `(*fp)(int)`, `x : 3`), or None."""
    piece = [t for t in piece]
    for k, t in top(piece):
        if t == "(" and (k == 0 or piece[k - 1] != "__attribute__"):
            inner = piece[k + 1:close_of(piece, k)]
            if inner and inner[0] in ("*", "&"):
                return next((x for x in inner if IDENT.match(x) and x not in KEYWORDS), None)
            break
    cut = len(piece)
    for k, t in top(piece):
        if t in ("[", ":", "=") or (t == "(" and k and piece[k - 1] == "__attribute__"):
            cut = k - (t == "(")
            break
    names = [t for t in piece[:cut] if IDENT.match(t) and t not in KEYWORDS]
    return names[-1] if names else None


def tag(k):
    return "union" if k.kw == "union" else "struct"


class Method:
    def __init__(self, cls, name, kind, ret, params, body, virtual, static, const):
        self.cls, self.name, self.kind, self.ret, self.params = cls, name, kind, ret, params
        self.body, self.virtual, self.static, self.const = body, virtual, static, const

    @property
    def key(self):
        return "~" if self.kind == "dtor" else self.name


class Klass:
    def __init__(self, name, kw):
        self.name, self.kw = name, kw
        self.base = None
        self.members = []        # member declarations kept verbatim (data members)
        self.fields = {}         # name -> declaration tokens
        self.methods = {}        # name -> Method (None if overloaded)
        self.static_data = set()
        self.hoisted = []        # nested typedefs / enums / classes
        self.has_ctor = self.has_dtor = False
        self.slots, self.own_vptr = [], False

    def poly(self):
        return bool(self.slots)

    def chain(self):
        k = self
        while k:
            yield k
            k = k.base

    def root(self):
        """The class whose layout holds the vptr."""
        return [k for k in self.chain() if k.own_vptr][0]

    def find_field(self, name):
        path = []
        for k in self.chain():
            if name in k.fields:
                return path
            path.append("_base")
        return None

    def find_method(self, name):
        for k in self.chain():
            if name in k.methods:
                if k.methods[name] is None:
                    raise CxxError(f"{k.name}::{name} is overloaded: not supported")
                return k.methods[name]
        return None


class Converter:
    """Parse the preprocessed unit, turn it into C (that is also valid C++ inside extern "C")."""

    def __init__(self, src, func):
        self.func = func
        self.classes = {}
        self.typenames = set()
        self.fn_ret = {}         # free function name -> class it returns (pointer to), for inference
        self.var_types = {}      # global variable name -> class
        self.helpers = {}        # (class, method) -> rewritten static inline definition tokens
        self.helper_order = []
        self.externs = {}        # mangled name -> declaration tokens
        self.vcalls = set()
        self.target = None
        self.dropped = set()
        self.items = split_items(tokenize(src))
        for t in ("template", "namespace", "using"):
            if t in tokenize(src):
                raise CxxError(f"{NOT_SUPPORTED[t]} ({t!r}) are not supported")
        self.out = []
        self.items = [item for item in self.items if not self.scan(item)]
        for k in self.classes.values():
            self.layout(k)

    # ---- pass 1: declarations
    def scan(self, item):
        item = self.unqualify(self.strip_extern_c(item))
        if not item:
            return
        if item[-1] == "}" and is_funcdef(item) and "inline" in item[:open_of(item, len(item) - 1)]:
            return self.inline_member(item)
        if item[0] == "typedef":
            name = declarator_name(item[1:-1]) if item[-1] == ";" else None
            if name:
                self.typenames.add(name)
            return
        if item[0] in ("struct", "class", "union") and len(item) > 2 and IDENT.match(item[1]) \
                and item[2] in ("{", ":", ";"):
            if item[2] == ";":
                self.classes.setdefault(item[1], Klass(item[1], item[0]))
                self.typenames.add(item[1])
                return
            self.parse_class(item)
            return
        names = [t for _, t in top(item)]
        if "(" in names and item[-1] == ";":
            k = names.index("(")
            fname = names[k - 1] if k else None
            cls = [t for t in names[:k] if t in self.classes]
            if fname and cls:
                self.fn_ret[fname] = cls[-1]
        elif item[-1] == ";":
            for piece in split_top(item[:-1]):
                n = declarator_name(piece)
                cls = [t for t in piece if t in self.classes]
                if n and cls:
                    self.var_types[n] = cls[-1]

    def inline_member(self, item):
        """`inline RET K::M(...) { ... }` outside the class: becomes the body of the declared member."""
        o = open_of(item, len(item) - 1)
        head = self.unqualify(item[:o])
        p = next((i for i, t in top(head) if t == "("), None)
        if p is None or "::" not in head[:p]:
            return False         # a free inline function: converted like any other definition
        q = head.index("::")
        k = self.classes.get(head[q - 1])
        if head[q + 1] in ("operator", "~") or (k and head[q + 1] == k.name):
            if k:
                self.dropped.add(k.name)
            return True          # inline operators / ctors / dtors: dropped like the in-class ones
        meth = k.methods.get(head[q + 1]) if k else None
        if meth is None:
            raise CxxError(f"inline {' '.join(head[q - 1:q + 2])}: not a declared (non-overloaded) method")
        meth.body = item[o + 1:-1]
        return True              # consumed: emitted as a helper if used

    @staticmethod
    def strip_extern_c(item):
        out = []
        for i, t in enumerate(item):
            if t == '"C"' and out and out[-1] == "extern":
                out.pop()
                continue
            out.append(t)
        return out

    def parse_class(self, item):
        kw, name = item[0], item[1]
        k = self.classes.get(name) or Klass(name, kw)
        if k.members or k.methods:
            raise CxxError(f"class {name} defined twice")
        k.kw, k.defined = kw, True
        self.classes[name] = k
        self.typenames.add(name)
        b = item.index("{")
        if b > 2:   # bases
            bases = split_top(item[3:b])
            if len(bases) > 1:
                raise CxxError(f"{name}: multiple inheritance is not supported")
            bt = [t for t in bases[0] if t not in ("public", "private", "protected")]
            if "virtual" in bt or len(bt) != 1 or bt[0] not in self.classes:
                raise CxxError(f"{name}: unsupported base {' '.join(bases[0])}")
            k.base = self.classes[bt[0]]
        e = close_of(item, b)
        if item[e + 1:] != [";"]:
            raise CxxError(f"{name}: declarators after a class body are not supported")
        for m in split_items(item[b + 1:e], members=True):
            self.parse_member(k, m)

    def parse_member(self, k, m):
        while m and m[0] in ("inline", "explicit", "__inline"):
            m = m[1:]
        if not m or m == [";"]:
            return
        if m[0] == "friend":
            return
        if m[0] in ("typedef", "enum"):
            k.hoisted.append(m)
            if m[0] == "typedef":
                self.typenames.add(declarator_name(m[1:-1]))
            return
        m = self.unqualify(m)
        if m[0] in ("struct", "class", "union") and len(m) > 2 and IDENT.match(m[1]) and m[2] in ("{", ":"):
            e = close_of(m, m.index("{"))
            self.parse_class(m[:e + 1] + [";"])
            k.hoisted.append(("class", m[1]))
            if m[e + 1:] != [";"]:       # struct Inner { ... } member;
                decl = ["struct", m[1]] + m[e + 1:]
                k.members.append(decl)
                self.collect_fields(k, decl)
            return
        tl = list(top(m))
        paren = next((i for i, t in tl if t == "(" and (i == 0 or m[i - 1] != "__attribute__")), None)
        is_method = paren is not None and not (m[paren + 1:paren + 2] and m[paren + 1] in ("*", "&"))
        if not is_method:
            if m[0] == "static":
                for piece in split_top(m[1:-1]):
                    k.static_data.add(declarator_name(piece))
                return
            k.members.append(m)
            self.collect_fields(k, m)
            return
        name = m[paren - 1]
        pre = m[:paren - 1]
        if "operator" in m[:paren]:
            self.dropped.add(k.name)   # operators are dropped: a body that uses one will not compile
            return
        kind = "fn"
        if pre[-1:] == ["~"]:
            kind, pre = "dtor", pre[:-1]
            k.has_dtor = True
        elif name == k.name:
            kind = "ctor"
            k.has_ctor = True
        virtual = "virtual" in pre
        static = "static" in pre
        ret = [t for t in pre if t not in ("virtual", "static", "inline", "explicit")]
        close = close_of(m, paren)
        params = m[paren + 1:close]
        if params == ["void"]:
            params = []
        rest = m[close + 1:]
        const = rest[:1] == ["const"]
        body = None
        if rest and rest[-1] == "}":
            o = open_of(rest, len(rest) - 1)
            body = rest[o + 1:-1]
        meth = Method(k, name, kind, ret, params, body, virtual, static, const)
        meth.init = body is not None and ":" in rest[:open_of(rest, len(rest) - 1)]
        if kind == "ctor":
            k.ctors = getattr(k, "ctors", []) + [meth]
        if kind == "fn":
            k.methods[name] = None if name in k.methods else meth
        if virtual:
            k.vdecl = getattr(k, "vdecl", []) + [meth]

    def unqualify(self, toks):
        """Outer::Inner (a nested class) -> Inner: C has one tag scope."""
        out = []
        for i, t in enumerate(toks):
            if t == "::" and out and out[-1] in self.classes and i + 1 < len(toks) and \
                    ("class", toks[i + 1]) in self.classes[out[-1]].hoisted:
                out.pop()
                continue
            out.append(t)
        return out

    @staticmethod
    def needs_construction(k, after):
        """Does a local `K name ...` run code in C++ (a ctor with a body, a dtor, a vptr)?"""
        if k.has_dtor or k.poly() or after == "(":
            return True
        ctors = getattr(k, "ctors", [])
        if not ctors:
            return False
        default = [c for c in ctors if not c.params]
        return not default or default[0].body is None or bool(default[0].body) or default[0].init

    def collect_fields(self, k, m):
        body = m[:-1] if m[-1] == ";" else m
        if "{" in body:   # anonymous / inline struct or union member
            b = body.index("{")
            e = close_of(body, b)
            decls = body[e + 1:]
            if decls:
                for piece in split_top(decls):
                    n = declarator_name(piece)
                    if n:
                        k.fields[n] = body
            else:
                for inner in split_items(body[b + 1:e], members=True):
                    self.collect_fields(k, inner)
            return
        for piece in split_top(body):
            n = declarator_name(piece)
            if n:
                k.fields[n] = body

    def layout(self, k):
        if getattr(k, "laid_out", False):
            return
        if k.base:
            self.layout(k.base)
        k.laid_out = True
        slots = list(k.base.slots) if k.base else []
        for name, meth in k.methods.items():   # an override is virtual without the keyword
            if meth and name in slots:
                meth.virtual = True
        for meth in getattr(k, "vdecl", []):
            if meth.key in slots and meth.kind == "fn" and k.methods.get(meth.name) is None:
                raise CxxError(f"{k.name}::{meth.name}: overloaded virtual")
            if meth.key not in slots:
                slots.append(meth.key)
        k.slots = slots
        k.own_vptr = bool(slots) and not (k.base and k.base.poly())

    # ---- pass 2: output
    def struct_tokens(self, k):
        out = []
        for h in k.hoisted:
            if h[0] == "class":
                continue      # nested classes were emitted when parsed (they are in self.classes order)
            out += h
        body = []
        if k.base and (k.base.members or k.base.poly() or k.base.base):
            body += [tag(k.base), k.base.name, "_base", ";"]
        for m in k.members:
            body += ["struct" if t == "class" else t for t in m]
        if k.own_vptr:
            body += ["struct", "_vte", "*", "_vtbl", ";"]
        if not body:
            body = ["char", "_empty", ";"]   # a C++ empty class has size 1
        kw = "union" if k.kw == "union" else "struct"
        return out + [kw, k.name, "{"] + body + ["}", ";"]

    def convert(self):
        out = []
        if any(k.poly() for k in self.classes.values()):
            out += tokenize("struct _vte { short delta; short index; void* pfn; };")
        emitted = set()
        for item in self.items:
            item = self.strip_extern_c(item)
            if not item:
                continue
            if item[0] in ("struct", "class", "union") and len(item) > 2 and item[1] in self.classes \
                    and item[2] in ("{", ":", ";"):
                if item[2] == ";":
                    kw = "union" if item[0] == "union" else "struct"
                    out += [kw, item[1], ";"]
                    if not getattr(self.classes[item[1]], "defined", False):
                        out += ["typedef", kw, item[1], item[1], ";"]
                    continue
                for name in self.nested_first(self.classes[item[1]]):
                    if name not in emitted:
                        emitted.add(name)
                        out += self.struct_tokens(self.classes[name])
                continue
            if item[-1] == "}" and is_funcdef(item):
                out += self.function(item)
                continue
            item = self.unqualify(item)
            if "::" in item:
                raise CxxError(f"unsupported declaration: {emit(item[:12]).strip()} ...")
            out += ["struct" if t == "class" else t for t in item]
        return emit(out)

    def nested_first(self, k):
        for h in k.hoisted:
            if h[0] == "class":
                yield from self.nested_first(self.classes[h[1]])
        yield k.name

    def function(self, item):
        o = open_of(item, len(item) - 1)
        head, body = self.unqualify(item[:o]), item[o + 1:-1]
        tl = [i for i, t in top(head) if t == "("]
        if not tl:
            raise CxxError("cannot parse a function definition")
        p = tl[0]
        params = head[p + 1:close_of(head, p)]
        if params == ["void"]:
            params = []
        if "::" not in head[:p]:          # a free function: rewrite member calls in it
            ctx = Ctx(None, params, self)
            return head + ["{"] + self.rewrite(body, ctx) + ["}"]
        q = head.index("::")
        cname = head[q - 1]
        k = self.classes.get(cname)
        if k is None:
            raise CxxError(f"{cname}:: of an unknown class")
        name = head[q + 1]
        if name == cname and q == 1:
            return self.constructor(k, head, p, params, body)
        if name in ("~", "operator") or name == cname:
            raise CxxError(f"{cname}::{''.join(head[q + 1:p])}: destructors and operators are not supported")
        meth = k.methods.get(name)
        if meth is None:
            raise CxxError(f"{cname}::{name} is not declared in class {cname} (or is overloaded)")
        if ":" in head[close_of(head, p) + 1:]:
            raise CxxError(f"{cname}::{name}: initializer list")
        ret = head[:q - 1]
        self.target = meth
        ctx = Ctx(k if not meth.static else None, params, self)
        new_body = self.rewrite(body, ctx)
        selfp = [] if meth.static else [tag(k), k.name, "*", "self"] + ([","] if params else [])
        proto = ret + [self.func, "("] + selfp + params + [")"]
        return self.assemble(proto, new_body)

    def constructor(self, k, head, p, params, body):
        """K::K(params) : inits { body } -> struct K* func(struct K* self, params): base ctor call, vptr
        store, member initializers in declaration order, body, return self (g++ 2.95 order)."""
        nparams = len(split_top(params))
        meth = next((c for c in getattr(k, "ctors", []) if len(split_top(c.params)) == nparams), None)
        if meth is None:
            raise CxxError(f"{k.name}::{k.name}: constructor not declared in the class (or overloaded)")
        self.target = meth
        after = head[close_of(head, p) + 1:]
        base_args, inits = None, {}
        if after:
            if after[0] != ":":
                raise CxxError(f"{k.name}::{k.name}: cannot parse {' '.join(after)}")
            for piece in split_top(after[1:]):
                if len(piece) < 3 or piece[1] != "(" or close_of(piece, 1) != len(piece) - 1:
                    raise CxxError(f"{k.name}::{k.name}: cannot parse initializer {' '.join(piece)}")
                if k.base and piece[0] == k.base.name:
                    base_args = piece[2:-1]
                elif piece[0] in k.fields:
                    inits[piece[0]] = piece[2:-1]
                else:
                    raise CxxError(f"{k.name}::{k.name}: unsupported initializer {piece[0]}")
        for f, decl in k.fields.items():
            cls = [x for x in decl if x in self.classes]
            if cls and "*" not in decl and self.needs_construction(self.classes[cls[-1]], None):
                raise CxxError(f"{k.name}::{k.name}: member {f} of class {cls[-1]} needs its own constructor")
        ctx = Ctx(k, params, self)
        pro = []
        if k.base:
            b = k.base
            nargs = len(split_top(base_args or []))
            cands = [c for c in getattr(b, "ctors", []) if len(split_top(c.params)) == nargs]
            if not cands:
                if b.poly() or base_args:
                    raise CxxError(f"{k.name}::{k.name}: no declared {b.name} constructor to call")
            elif len(cands) > 1:
                raise CxxError(f"{k.name}::{k.name}: overloaded {b.name} constructors")
            elif cands[0].body is not None:
                if cands[0].body or cands[0].init or b.poly():
                    raise CxxError(f"{k.name}::{k.name}: inline base constructor {b.name}() with a body")
            else:
                bc = cands[0]
                mangled = self.mangle(bc, ctor=True)
                selfp = [tag(b), b.name, "*", "self"] + ([","] if bc.params else [])
                self.externs[mangled] = ["extern", tag(b), b.name, "*", mangled, "("] + selfp + bc.params + [")", ";"]
                args = self.rewrite(base_args or [], ctx)
                pro += [mangled, "(", "(", tag(b), b.name, "*", ")", "self"] + ([","] if args else []) + args + [")", ";"]
                self.base_ctor = (mangled, b.name)
        if k.poly():
            vt = f"_vt_{len(k.name)}{k.name}"
            hops = [x for kk in k.chain() if not kk.own_vptr for x in ("_base", ".")]
            self.externs[vt] = ["extern", "struct", "_vte", vt, "[", "]", ";"]
            pro += ["self", "->"] + hops + ["_vtbl", "=", vt, ";"]
        for f in k.fields:
            if f in inits:
                pro += ["self", "->", f, "=", "("] + self.rewrite(inits[f], ctx) + [")", ";"]
        new_body = self.rewrite(body, ctx)
        new_body = [x for i, t in enumerate(new_body)
                    for x in (["return", "self"] if t == "return" and new_body[i + 1:i + 2] == [";"] else [t])]
        proto = [tag(k), k.name, "*", self.func, "(", tag(k), k.name, "*", "self"] + ([","] if params else []) \
            + params + [")"]
        return self.assemble(proto, pro + new_body + ["return", "self", ";"])

    def assemble(self, proto, body):
        pre = []
        for key in self.helper_order:
            pre += self.helpers[key][0] + [";"]
        for key in self.helper_order:
            pre += self.helpers[key][0] + ["{"] + self.helpers[key][1] + ["}"]
        ext = [t for d in self.externs.values() for t in d]
        return ext + proto + [";"] + pre + proto + ["{"] + body + ["}"]

    # ---- body rewriting
    def rewrite(self, toks, ctx):
        out, i, n = [], 0, len(toks)
        while i < n:
            t = toks[i]
            nxt = toks[i + 1] if i + 1 < n else None
            prev_src = toks[i - 1] if i else None
            if t in NOT_SUPPORTED:
                raise CxxError(f"{NOT_SUPPORTED[t]} ({t!r}) are not supported")
            if t == ";":
                ctx.decl = None
            if t == "this":
                if not ctx.cls:
                    raise CxxError("'this' outside a member function")
                out.append("self")
                i += 1
                continue
            if not IDENT.match(t) or t in KEYWORDS - {"self"}:
                out.append(t)
                i += 1
                continue
            if t in self.classes and nxt == "::" and i + 2 < n and ("class", toks[i + 2]) in self.classes[t].hoisted:
                i += 2              # Outer::Inner -> Inner
                continue
            if t in self.classes and nxt == "::":         # Base::Method(...) qualified call
                k, name = self.classes[t], toks[i + 2]
                if i + 3 < n and toks[i + 3] == "(":
                    meth = k.find_method(name)
                    if meth is None:
                        raise CxxError(f"{t}::{name} is not a known method")
                    objp = None if meth.static else self.self_ptr(ctx, meth.cls)
                    i = self.call(out, toks, i + 3, meth, objp, ctx, virtual_ok=False)
                    continue
                raise CxxError(f"{t}::{name}: class-scoped names are not supported")
            if out and out[-1] in (".", "->"):
                if nxt == "(":
                    acc = out.pop()
                    obj = self.pop_object(out)
                    meth, k = self.resolve(t, obj, acc, ctx)
                    objp = obj if acc == "->" else ["&", "("] + obj + [")"]
                    if len(objp) > 1 and acc == "->":
                        objp = ["("] + objp + [")"]
                    if k is not meth.cls and not meth.virtual:   # inherited (or receiver type unknown)
                        objp = ["(", tag(meth.cls), meth.cls.name, "*", ")"] + objp
                    i = self.call(out, toks, i + 1, meth, objp, ctx)
                    continue
                out.append(t)
                i += 1
                continue
            # local declarations shadow members
            if self.is_decl(toks, i, ctx):
                cls = [x for x in ctx.decl_type if x in self.classes]
                if cls:
                    kk = self.classes[cls[-1]]
                    if "*" not in toks[ctx.decl_start:i] and \
                            self.needs_construction(kk, toks[i + 1] if i + 1 < n else None):
                        raise CxxError(f"local object of class {kk.name} needs its constructor/destructor")
                    ctx.types[t] = kk.name
                ctx.shadow.add(t)
                out.append(t)
                i += 1
                continue
            if ctx.cls and t not in ctx.shadow:
                path = ctx.cls.find_field(t)
                if path is not None:
                    out += ["self", "->"] + [x for p in path for x in (p, ".")] + [t]
                    i += 1
                    continue
                if t in set().union(*(kk.static_data for kk in ctx.cls.chain())):
                    raise CxxError(f"static data member {t} is not supported")
                meth = ctx.cls.find_method(t) if nxt == "(" else None
                if meth:
                    objp = None if meth.static else self.self_ptr(ctx, meth.cls)
                    i = self.call(out, toks, i + 1, meth, objp, ctx)
                    continue
            out.append(t)
            i += 1
        return out

    def is_decl(self, toks, i, ctx):
        nxt = toks[i + 1] if i + 1 < len(toks) else None
        if nxt not in ("=", ";", ",", "[", ")"):
            return False
        j = i - 1
        while j >= 0 and toks[j] in ("*", "const", "volatile"):
            j -= 1
        if j >= 0 and (toks[j] in BUILTIN_TYPES or toks[j] in self.classes or toks[j] in self.typenames) \
                and toks[j] not in ("const", "volatile"):
            s = j
            while s > 0 and (toks[s - 1] in BUILTIN_TYPES or toks[s - 1] in ("struct", "union")):
                s -= 1
            ctx.decl, ctx.decl_start, ctx.decl_type = i, s, toks[s:i]
            return nxt != ")" or (s > 0 and toks[s - 1] in ("(", ","))
        if ctx.decl is not None and toks[j] == "," and nxt != ")":
            seg = toks[ctx.decl:i]   # a further declarator of the same statement, not a call argument
            return seg.count("(") == seg.count(")") and seg.count("{") == seg.count("}")
        return False

    @staticmethod
    def pop_object(out):
        """Pop the postfix expression before `->` / `.` off the output (`a`, `self->b`, `f(x)`, `(e)`)."""
        j = len(out)
        while j > 0:
            t = out[j - 1]
            if t in (")", "]"):
                j = open_of(out, j - 1)
                if t == ")" and not (j > 0 and (IDENT.match(out[j - 1]) or out[j - 1] in (")", "]"))
                                      and out[j - 1] not in KEYWORDS - {"self"}):
                    break
                continue
            if IDENT.match(t) or re.match(r"\d", t):
                j -= 1
                if j > 0 and out[j - 1] in ("->", "."):
                    j -= 1
                    continue
                break
            break
        obj = out[j:]
        del out[j:]
        if not obj:
            raise CxxError("cannot find the object of a member call")
        return obj

    def static_class(self, obj, ctx):
        """Best-effort static type of an object expression (rewritten tokens)."""
        if obj == ["self"]:
            return ctx.cls
        if obj[0] == "(" and close_of(obj, 0) < len(obj) - 1:      # a cast: (Class*) expr
            cast = [x for x in obj[1:close_of(obj, 0)] if x in self.classes]
            return self.classes[cast[-1]] if cast else None
        if obj[-1] == ")" and len(obj) > 1:
            o = open_of(obj, len(obj) - 1)
            if o == 0:
                return self.static_class(obj[1:-1], ctx) if len(obj) > 2 else None
            if IDENT.match(obj[o - 1]) and obj[o - 1] in self.fn_ret:
                return self.classes[self.fn_ret[obj[o - 1]]]
            return None
        if obj[-1] == "]":                       # a[i]: the element has the array's class
            o = open_of(obj, len(obj) - 1)
            return self.static_class(obj[:o], ctx) if o else None
        last = obj[-1]
        if len(obj) >= 3 and obj[-2] in ("->", "."):
            owner = self.static_class(obj[:-2], ctx)
            decl = None
            if owner:
                for kk in owner.chain():
                    decl = kk.fields.get(last) or decl
                    if decl:
                        break
            else:
                ds = {tuple(kk.fields[last]) for kk in self.classes.values() if last in kk.fields}
                decl = list(ds.pop()) if len(ds) == 1 else None
            cls = [x for x in (decl or []) if x in self.classes]
            return self.classes[cls[-1]] if cls else None
        name = ctx.types.get(last) or self.var_types.get(last)
        return self.classes.get(name) if name else None

    def resolve(self, name, obj, acc, ctx):
        k = self.static_class(obj, ctx)
        if k:
            meth = k.find_method(name)
            if meth:
                return meth, k
        cands = [kk.methods[name] for kk in self.classes.values() if name in kk.methods]
        if any(c is None for c in cands):
            raise CxxError(f"method {name} is overloaded: not supported")
        if len(cands) == 1:
            return cands[0], None
        raise CxxError(f"cannot tell which class's {name}() `{' '.join(obj)}{acc}{name}()` calls "
                       f"({', '.join(c.cls.name for c in cands) or 'none declared'})")

    def self_ptr(self, ctx, owner):
        if not ctx.cls:
            raise CxxError("member call without an object outside a member function")
        return ["self"] if owner is ctx.cls else ["(", tag(owner), owner.name, "*", ")", "self"]

    def call(self, out, toks, p, meth, objp, ctx, virtual_ok=True):
        """toks[p] is the '(' of a member call; append its C form to out, return the index after it."""
        e = close_of(toks, p)
        saved, ctx.decl = ctx.decl, None
        args = self.rewrite(toks[p + 1:e], ctx)
        ctx.decl = saved
        if any(t == "=" for _, t in top(meth.params)) and len(split_top(args)) < len(split_top(meth.params)):
            raise CxxError(f"{meth.cls.name}::{meth.name}: default arguments are not supported")
        sep = [","] if args else []
        if meth.kind != "fn":
            raise CxxError(f"call to {meth.cls.name}::{meth.name}: not supported")
        if meth.virtual and virtual_ok:
            if any(t in ("++", "--", "=", "+=", "-=") for t in objp) or \
                    any(objp[k] == "(" and k and IDENT.match(objp[k - 1]) for k in range(len(objp))):
                raise CxxError(f"virtual call {meth.name}() on an expression with side effects")
            root = meth.cls.root()
            slot = meth.cls.slots.index(meth.key) + 1   # entry 0 is the RTTI entry
            vp = ["(", "(", tag(root), root.name, "*", ")", "("] + objp + [")", ")", "->", "_vtbl", "[", str(slot), "]"]
            ptypes = meth.params or []
            fty = ["("] + meth.ret + ["(", "*", ")", "(", "void", "*"] + ([","] if ptypes else []) + ptypes + [")", ")"]
            out += ["(", "("] + fty + vp + [".", "pfn", ")", "(", "(", "char", "*", ")", "("] + objp + [")", "+"] \
                + vp + [".", "delta"] + sep + args + [")", ")"]
            self.vcalls.add((meth.cls.name, meth.name, slot))
            return e + 1
        recv = [] if meth.static else objp + sep
        if meth is self.target:
            out += [self.func, "("] + recv + args + [")"]
        elif meth.body is not None:
            fname = f"{meth.cls.name}_{meth.name}"
            key = (meth.cls.name, meth.name)
            if key not in self.helpers:
                self.helpers[key] = None         # recursion guard
                hctx = Ctx(None if meth.static else meth.cls, meth.params, self)
                body = self.rewrite(meth.body, hctx)
                selfp = [] if meth.static else [tag(meth.cls), meth.cls.name, "*", "self"] + ([","] if meth.params else [])
                self.helpers[key] = (["static", "inline"] + meth.ret + [fname, "("] + selfp + meth.params + [")"], body)
                self.helper_order.append(key)
            out += [fname, "("] + recv + args + [")"]
        else:
            mangled = self.mangle(meth)
            selfp = [] if meth.static else [tag(meth.cls), meth.cls.name, "*", "self"] + ([","] if meth.params else [])
            self.externs[mangled] = ["extern"] + meth.ret + [mangled, "("] + selfp + meth.params + [")", ";"]
            out += [mangled, "("] + recv + args + [")"]
        return e + 1

    def mangle(self, meth, ctor=False):
        """g++ 2.95 name of an out-of-line member. Only the symbol name depends on it (never the .text the
        drift check compares), so the rare forms (N<count><n> runs, typedef'd parameters) are best effort."""
        codes = []
        for p in split_top(meth.params):
            if p == ["..."]:
                codes.append("e")
                continue
            n = declarator_name(p)
            ty = [t for t in p if t != n] if n and n not in self.typenames and n not in self.classes else p
            stars = [t for t in ty if t in ("*", "&")]
            base = [t for t in ty if t not in ("*", "&", "const", "volatile", "struct", "class", "union")]
            const = "const" in ty[:ty.index(stars[0])] if stars else False
            if tuple(base) in MANGLE:
                code = MANGLE[tuple(base)]
            elif len(base) == 1:
                code = f"{len(base[0])}{base[0]}"
            else:
                raise CxxError(f"{meth.cls.name}::{meth.name}: cannot mangle parameter {' '.join(p)}")
            if const and stars:
                code = "C" + code
            for s in stars:
                code = ("P" if s == "*" else "R") + code
            if not tuple(base) in MANGLE and code in codes:   # a repeated class type: T<n> (n from 1)
                code = f"T{codes.index(code) + 1}"
            codes.append(code)
        head = "" if ctor else meth.name
        return f"{head}__{'C' if meth.const else ''}{len(meth.cls.name)}{meth.cls.name}{''.join(codes)}"

    def port_back(self):
        t = self.target
        lines = []
        if t:
            self_arg = "" if t.static else f"{tag(t.cls)} {t.cls.name}* self, "
            lines.append(f"{self.func}({self_arg}...)  ->  {t.cls.name}::{t.name}(...)")
            lines.append("self->x  ->  x;  self->_base.x  ->  x;  self  ->  this")
            if t.kind == "ctor":
                if getattr(self, "base_ctor", None):
                    lines.append(f"{self.base_ctor[0]}((struct {self.base_ctor[1]}*)self, a...);  ->  "
                                 f": {self.base_ctor[1]}(a...)")
                lines.append("self->..._vtbl = _vt_...;  and the final  return self;  ->  drop (g++ adds them)")
                lines.append("leading self->m = (v); stores  ->  : m(v) initializers, or keep them in the body")
        for cname, mname in self.helper_order:
            lines.append(f"{cname}_{mname}(p, ...)  ->  p->{mname}(...)   [inline {cname}::{mname}]")
        for cname, mname, slot in sorted(self.vcalls):
            lines.append(f"((RET (*)(void*, ...))((struct R*)(p))->_vtbl[{slot}].pfn)((char*)(p) + ...delta, ...)  ->  "
                         f"p->{mname}(...)   [virtual {cname}::{mname}]")
        for m in self.externs:
            if "__" in m and not m.startswith("__"):
                lines.append(f"{m}(p, ...)  ->  p->{m.split('__')[0]}(...)")
        return lines


class Ctx:
    def __init__(self, cls, params, conv):
        self.cls = cls
        self.shadow, self.types = set(), {}
        self.decl, self.decl_start, self.decl_type = None, 0, []
        for p in split_top(params):
            n = declarator_name(p)
            if n:
                self.shadow.add(n)
                c = [t for t in p if t in conv.classes]
                if c:
                    self.types[n] = c[-1]


def looks_cxx(src):
    toks = tokenize(src)
    if {"::", "class", "virtual", "this", "public", "private", "protected", "operator"} & set(toks):
        return True
    try:
        conv = Converter(src, "f")
    except CxxError:
        return False   # not parseable as the supported subset: keep the plain-C path (and its errors)
    return any(k.methods or k.has_ctor or k.has_dtor for k in conv.classes.values())


def cxx_to_c(src, func):
    """The unit as C (Class::Method -> func(Class* self, ...)); returns (text, port-back lines)."""
    conv = Converter(src, func)
    text = conv.convert()
    if conv.dropped:
        print(f"note: operator members of {', '.join(sorted(conv.dropped))} are not converted; "
              "a body that uses them will not compile")
    if conv.target is None and not any(re.search(rf"\b{func}\s*\(", emit(i)) for i in conv.items):
        raise CxxError(f"no definition of {func} or of a Class::Method found")
    return text, conv.port_back()


def text_bytes(o, name):
    return match.read_obj(o, match.func_row(name)["addr"]).words


def settings_text(name, all_passes):
    s = (f'func_name = "{name}"\ncompiler_type = "gcc"\n'
         f'objdump_command = "{tool("mipsel-linux-gnu-objdump")} -drz -m mips:5900"\n')
    if not all_passes:
        s += ("\n# clean profile (tools/permute.py): passes that only win with dead or junk code are off,\n"
              "# since such winners cannot be ported to a unit; --all-passes drops this section\n"
              "[weight_overrides]\n" + "".join(f"{k} = {v}\n" for k, v in CLEAN_WEIGHTS.items()))
    return s


def lowered(n):
    return (lambda: os.nice(n)) if n else None


def run_bounded(cmd, seconds, nice):
    """Run the permuter at low priority; stop it (and its compile children) after `seconds`."""
    sys.stdout.flush()
    proc = subprocess.Popen(cmd, preexec_fn=lowered(nice), start_new_session=True)
    try:
        proc.wait(timeout=seconds or None)
    except (subprocess.TimeoutExpired, KeyboardInterrupt) as e:
        if isinstance(e, subprocess.TimeoutExpired):
            print(f"\n--time {seconds}s reached: stopping the permuter")
        for sig, wait in ((signal.SIGINT, 15), (signal.SIGKILL, 5)):
            try:
                os.killpg(proc.pid, sig)
                proc.wait(timeout=wait)
                break
            except ProcessLookupError:
                break
            except subprocess.TimeoutExpired:
                continue
    return proc.returncode


def report_outputs(d, before=()):
    outs = []
    for o in set(d.glob("output-*")) - set(before):
        m = re.match(r"output-(\d+)-(\d+)$", o.name)
        if m:
            outs.append((int(m.group(1)), int(m.group(2)), o))
    if not outs:
        print("no new outputs (nothing beat or tied the base score)")
        return
    outs.sort()
    best = outs[0]
    print(f"{len(outs)} new output(s); best score {best[0]}: {best[2].relative_to(ROOT)}/source.c")


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--to-cpp":   # internal: called by the generated compile.sh
        to_cpp(sys.argv[2], sys.argv[3], sys.argv[4:])
        return
    ap = argparse.ArgumentParser(description="set up (and run) decomp-permuter on one unit; "
                                 "unknown arguments (-j2, --show-errors, ...) go to the permuter")
    ap.add_argument("name")
    ap.add_argument("--run", action="store_true", help="run the permuter after the drift checks")
    ap.add_argument("--src", help="permute this draft instead of src/funcs/<name>.cpp")
    ap.add_argument("--out", help="permuter directory (default work/permute/<name>)")
    ap.add_argument("--cxx", action="store_true",
                    help="convert C++ (Class::Method, members) to C first (automatic when the unit needs it)")
    ap.add_argument("--no-cxx", action="store_true", help="never convert; use the plain-C path")
    ap.add_argument("--all-passes", action="store_true",
                    help="use the permuter's default weights (junk passes included) instead of the clean profile")
    ap.add_argument("--time", type=int, default=600, metavar="SECONDS",
                    help="stop --run after this many seconds (default 600; 0 = no limit)")
    ap.add_argument("--nice", type=int, default=10, metavar="N", help="niceness for the permuter (default 10)")
    ap.add_argument("--best-only", dest="best_only", action="store_true", default=True,
                    help="only write outputs that tie or beat the best score (default)")
    ap.add_argument("--all-outputs", dest="best_only", action="store_false",
                    help="write every improved/different output (fills the disk quickly)")
    a, rest = ap.parse_known_args()
    name = a.name
    unit = (ROOT / a.src).resolve() if a.src else unit_path(name)
    if not unit.exists():
        sys.exit(f"{unit.relative_to(ROOT)} missing: python tools/new_func.py {name}")
    d = (ROOT / a.out).resolve() if a.out else ROOT / "work" / "permute" / name
    d.mkdir(parents=True, exist_ok=True)

    cfg = compiler_config()
    pre = subprocess.run(["cpp", "-P", "-undef", "-D__GNUC__=2", "-D__GNUC_MINOR__=95", *cfg["compiler"]["cppflags"],
                          "-DPERMUTER", str(unit)],
                         capture_output=True, text=True, cwd=ROOT)
    if pre.returncode != 0:
        sys.exit(pre.stderr)
    text = pre.stdout
    cxx = not a.no_cxx and (a.cxx or looks_cxx(text))
    hints = []
    if cxx:
        try:
            text, hints = cxx_to_c(text, name)
        except CxxError as e:
            sys.exit(f"C++ -> C conversion refused: {e}\n"
                     f"(permute a hand-written C copy with an explicit self pointer: --src work/<copy>.cpp)")
        print("converted the C++ unit to C (--cxx)")
    (d / "base.c").write_text(to_c(text))

    flags = cfg["compiler"]["cflags"] + file_cflags(unit)
    py = sys.executable
    # base.c is C for the permuter's parser; compile.sh turns it back into the C++ the gate compiles
    # (tools/permute.py --to-cpp: drop the C-only prelude, restore 128-bit typedefs, wrap in extern "C")
    ti = " ".join(n for _, n in TI_TYPEDEF.findall(text))
    (d / "compile.sh").write_text(
        "#!/bin/sh\n# generated by tools/permute.py: same pipeline as tools/match.py\n"
        f"# usage: compile.sh input.c -o output.o\n"
        f"cd {shlex.quote(str(ROOT))} || exit 1\n"
        "src=\"$3.cpp\"\n"
        f"{shlex.quote(py)} tools/permute.py --to-cpp \"$1\" \"$src\" {ti} || exit 1\n"
        # the permuter deletes its own .c/.o temp files but not this .cpp: remove it here, or /tmp fills up
        f"{shlex.quote(py)} tools/cc.py cxx \"$src\" \"$3\" --func {name} --cflags {shlex.quote(' '.join(flags + ['-x', 'c++']))}\n"
        "rc=$?\nrm -f \"$src\"\nexit $rc\n")
    os.chmod(d / "compile.sh", 0o755)
    (d / "settings.toml").write_text(settings_text(name, a.all_passes))

    res = match.compare(name, unit)
    if res.error:
        sys.exit(f"unit does not compile: {res.error}")
    target = ROOT / "build" / "match" / "target" / f"{name}.o"
    (d / "target.o").write_bytes(target.read_bytes())

    # drift check 1: compile.sh(base.c) == match.py's object (for --cxx: the C conversion == the C++ unit)
    out = d / "drift.o"
    r = subprocess.run([str(d / "compile.sh"), str(d / "base.c"), "-o", str(out)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(("the C conversion does not compile" if cxx else "compile.sh failed on base.c")
                 + f" ({d.relative_to(ROOT)}/base.c):\n" + r.stderr
                 + ("\n(permute a hand-written C copy with --src, or try --no-cxx)" if cxx else ""))
    ours = ROOT / "build" / "match" / f"{name}.o"
    if text_bytes(out, name) != text_bytes(ours, name):
        if cxx:
            sys.exit(f"DRIFT: the C conversion ({d.relative_to(ROOT)}/base.c) compiles to different .text "
                     "than the C++ unit; not permuting (permute a hand-written C copy with --src)")
        sys.exit("DRIFT: compile.sh output differs from tools/match.py's compile; not permuting")

    print(f"permuter dir ready: {d.relative_to(ROOT)} "
          f"(match.py: {'MATCH' if res.ok else f'{len(res.diffs)} instruction(s) differ'}; "
          f"weights: {'permuter defaults' if a.all_passes else 'clean profile'})")
    if hints:
        (d / "port_back.txt").write_text("\n".join(hints) + "\n")
        print("port back (C -> C++):\n  " + "\n  ".join(hints))
    if res.ok:
        print("already matches; nothing to permute")
        return

    # drift check 2: the permuter's own base score must say "not matching" too
    proc = subprocess.Popen([py, "-u", str(PERMUTER / "permuter.py"), str(d), "-j1"],
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                            preexec_fn=lowered(a.nice), start_new_session=True)
    base = None
    for line in proc.stdout:
        if "Syntax error" in line or "pycparser" in line:
            os.killpg(proc.pid, signal.SIGKILL)
            sys.exit("decomp-permuter cannot parse base.c: " + line.strip() + "\n"
                     + ("(the --cxx output is outside what pycparser reads: permute a hand-written C copy "
                        "with --src)" if cxx else
                        "(it reads C, not C++): permute a C-style copy with an explicit self pointer under "
                        "work/, or try --cxx"))
        m = re.search(r"base score = (\d+)", line)
        if m:
            base = int(m.group(1))
            break
    try:
        os.killpg(proc.pid, signal.SIGKILL)
    except ProcessLookupError:
        pass
    proc.wait()
    if base is None or base == 0:
        sys.exit(f"DRIFT: permuter base score {base} but match.py sees {len(res.diffs)} difference(s)")
    print(f"permuter base score {base} (agrees: not yet matching)")
    cmd = [py, str(PERMUTER / "permuter.py"), str(d), "--stop-on-zero"] + (["--best-only"] if a.best_only else [])
    if a.run:
        print(f"running for {a.time or 'unlimited'} s at nice {a.nice}: {' '.join(cmd[2:] + rest)}")
        before = list(d.glob("output-*"))
        run_bounded(cmd + rest, a.time, a.nice)
        report_outputs(d, before)
        if hints:
            print(f"port the winner back with {d.relative_to(ROOT)}/port_back.txt")
    else:
        src_arg = f" --src {a.src}" if a.src else ""
        print(f"run: python tools/permute.py {name}{src_arg} --run -j2   (--time {a.time}, --nice {a.nice})")


if __name__ == "__main__":
    main()
