#!/usr/bin/env python3
"""A permuter for C++ units: mutates the unit text directly (no C parser), scores every candidate with the
same pipeline as match.py, and hill-climbs towards an exact match.

    python tools/cxxperm.py func_00112345                       # src/nonmatching/ or src/funcs/ unit
    python tools/cxxperm.py func_00112345 --src work/draft.cpp -j4 --time 600
    python tools/cxxperm.py func_00112345 --seed 1 --keep 8 --no-unsafe

Every candidate is written to a scratch file, checked with tools/scan.py's rules (no asm, no string literals, no
bare statements, no in-image addresses) plus a few of our own (no do{}while(0), no new out-of-line functions), then
compiled and compared with match.compare() into a per-worker build directory. Candidates are ranked by
(exact match, fuzzy v2 score, fewer differing words). Each worker runs its own hill climb with restarts; the best
candidates are written to work/cxxperm/<func>/best_<rank>.cpp with their score in a header comment, and the run
stops at the first exact MATCH or at --time.

The mutations are text- and brace-aware and stay inside one block of statements:
  swap        swap two adjacent statements that do not touch the same variables (never two calls)
  split/merge `T x = e;`  <->  `T x; x = e;`
  temp        hoist a call into `__typeof__(call) t = call;` before its statement; inline a one-use temp
  commute     swap operands of == != + * (and && || when neither side has a call); flip < > <= >=
  invert      `if (c) A else B`  ->  `if (!(c)) B else A`
  rettype     an extern "C" callee's return type among void / int / void* / bool / unsigned int
  inttype     a local's type among int / unsigned int / short / unsigned short
  for2while   `for (i; c; s) body` -> `i; while (c) { body s; }` (only without `continue`)
  countdown   `for (int i = 0; i < N; i++)` -> `for (int i = N - 1; i >= 0; i--)`   [unsafe: order changes]
Candidates are not proven equivalent: read any winner before keeping it (the unsafe mutations can change order;
--no-unsafe turns them off).
"""
import argparse
import multiprocessing as mp
import os
import random
import re
import shutil
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT, BUILD, compiler_config, unit_path  # noqa: E402

IDENT = re.compile(r"[A-Za-z_]\w*")
KEYWORDS = {"if", "else", "for", "while", "do", "return", "break", "continue", "switch", "case", "default",
            "goto", "sizeof", "new", "delete", "this", "true", "false", "const", "volatile", "unsigned", "signed",
            "int", "short", "long", "char", "float", "double", "void", "bool", "struct", "class", "union",
            "static", "inline", "extern", "operator", "__typeof__"}
TYPE_WORDS = {"int", "short", "long", "char", "float", "double", "bool", "void", "unsigned", "signed", "const"}
CONTROL = re.compile(r"^\s*(if|for|while|do|switch|return|break|continue|goto|case|default)\b|^\s*\w+\s*:(?!:)")
TYPE_START = re.compile(r"^\s*(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|class\s+)*"
                        r"(?:int|short|long|char|float|double|bool|void|[A-Z_]\w*|[a-z_]\w*_[0-9A-F]{6,8}\w*)"
                        r"(?:\s*[*&])*\s+[*&]*\s*([A-Za-z_]\w*)\s*(=|;|\[)")


# ---------------------------------------------------------------- parsing (brace-aware, no full C++ parser)

def match_close(s, i):
    """Index of the bracket closing the one at s[i] (one of ( [ {)."""
    pair = {"(": ")", "[": "]", "{": "}"}[s[i]]
    depth = 0
    for j in range(i, len(s)):
        c = s[j]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth == 0:
                return j if c == pair else -1
    return -1


def mask_comments(src):
    """Same length as src, comments replaced by spaces, so offsets stay valid."""
    out = list(src)
    i = 0
    while i < len(src):
        if src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = len(src) if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
        elif src.startswith("//", i):
            j = src.find("\n", i)
            j = len(src) if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        else:
            i += 1
    return "".join(out)


def code_blocks(code):
    """(start, end) of every statement block: a { } that follows `)`, `else`, `do` or another statement block
    start, i.e. function bodies and control-flow bodies, not class bodies or initialisers."""
    blocks = []
    for i, c in enumerate(code):
        if c != "{":
            continue
        k = i - 1
        while k >= 0 and code[k].isspace():
            k -= 1
        prev = code[max(0, k - 3):k + 1]
        if k >= 0 and (code[k] in ")" or prev.endswith("else") or prev.endswith("do") or code[k] in "{;}"):
            # a `) {` after `operator` or a member function head is a function body too; class bodies follow
            # a name, initialisers follow `=`: both excluded by the test above
            if code[k] in "{;}":
                # a nested bare block inside a function only counts if we are already inside one
                if not any(s < i < e for s, e in blocks):
                    continue
            j = match_close(code, i)
            if j > 0:
                blocks.append((i, j))
    return blocks


def split_statements(code, start, end):
    """Top-level statements inside the block code[start] == '{' .. code[end] == '}' as (s, e) spans (e exclusive)."""
    out = []
    i = start + 1
    while i < end:
        while i < end and code[i].isspace():
            i += 1
        if i >= end:
            break
        s = i
        depth = 0
        while i < end:
            c = code[i]
            if c in "([":
                depth += 1
            elif c in ")]":
                depth -= 1
            elif c == "{" and depth == 0:
                j = match_close(code, i)
                if j < 0:
                    return out
                i = j + 1
                # `if (...) {..} else ...` and `do {..} while (...);` continue the same statement
                k = i
                while k < end and code[k].isspace():
                    k += 1
                if code.startswith("else", k) and not (code[k + 4:k + 5].isalnum() or code[k + 4:k + 5] == "_"):
                    i = k + 4
                    continue
                if re.match(r"\s*do\b", code[s:i]) and code.startswith("while", k):
                    continue
                if re.match(r"\s*(struct|class|union|enum)\b", code[s:i]) or code[k:k + 1] == ";":
                    continue
                break
            elif c == ";" and depth == 0:
                i += 1
                break
            i += 1
        out.append((s, i))
    return out


def idents(text):
    return {m.group(0) for m in IDENT.finditer(text)} - KEYWORDS


def writes(text):
    w = set()
    m = TYPE_START.match(text)
    if m:
        w.add(m.group(1))
    for m in re.finditer(r"([A-Za-z_][\w.\->\[\]]*)\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)", text):
        root = IDENT.match(m.group(1))
        if root:
            w.add(root.group(0))
    for m in re.finditer(r"(?:\+\+|--)\s*([A-Za-z_]\w*)|([A-Za-z_]\w*)\s*(?:\+\+|--)", text):
        w.add(m.group(1) or m.group(2))
    return w


def has_call(text):
    return re.search(r"[A-Za-z_]\w*\s*\(", re.sub(r"\b(if|for|while|switch|return|sizeof)\s*\(", "", text)) \
        is not None


# ---------------------------------------------------------------- mutations

class Mutator:
    # pass weights: the upstream permuter's [gcc] weights where a pass has an equivalent, Boktai's for its
    # gcc-specific passes, 5 for our C++-specific ones (docs/techniques/N64_AND_PERMUTER.md, appendix)
    WEIGHTS = {"temp": 100, "inline": 20, "swap": 10, "reorder_decls": 10, "split": 10, "merge": 5,
               "commute": 5, "compound": 5, "chain": 5, "ineq": 5, "invert": 1, "inttype": 20, "rettype": 5,
               "merge_var": 5, "split_var": 10, "move_to_use": 10, "for2while": 5, "call_order": 5,
               "nest_and": 5, "early_return": 5, "param": 5, "flags": 3, "countdown": 1}
    REGALLOC = {"move_to_use", "reorder_decls", "split_var", "merge_var", "split", "merge", "param", "temp",
                "inline", "inttype"}

    def __init__(self, unsafe=True, focus=None, allowed=(), weights=None):
        self.unsafe = unsafe
        self.allowed = sorted(allowed)
        w = dict(self.WEIGHTS)
        w.update(weights or {})
        if not unsafe:
            w.pop("countdown", None)
        if focus == "regalloc":
            for k in self.REGALLOC:
                w[k] = w.get(k, 0) * 4
        self.names = [k for k in w if w[k] > 0 and hasattr(self, "m_" + k)]
        self.weights = [w[k] for k in self.names]
        self.ops = [getattr(self, "m_" + k) for k in self.names]
        self._returns = {}

    def mutate(self, src, rng):
        for _ in range(20):
            op = rng.choices(self.ops, weights=self.weights)[0]
            try:
                out = op(src, rng)
            except Exception:
                out = None
            if out and out != src:
                return out, op.__name__[2:]
        return None, None

    # helpers
    def _stmts(self, src):
        code = mask_comments(src)
        res = []
        for (s, e) in code_blocks(code):
            st = split_statements(code, s, e)
            if st:
                res.append(st)
        return code, res

    def m_swap(self, src, rng):
        code, blocks = self._stmts(src)
        pairs = []
        for st in blocks:
            for k in range(len(st) - 1):
                a, b = code[st[k][0]:st[k][1]], code[st[k + 1][0]:st[k + 1][1]]
                if CONTROL.match(a) or CONTROL.match(b) or "{" in a or "{" in b:
                    continue
                if writes(a) & idents(b) or writes(b) & idents(a):
                    continue
                if has_call(a) and has_call(b):
                    continue
                pairs.append((st[k], st[k + 1]))
        if not pairs:
            return None
        (s1, e1), (s2, e2) = rng.choice(pairs)
        return src[:s1] + src[s2:e2] + src[e1:s2] + src[s1:e1] + src[e2:]

    def m_split(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks[1:] if len(blocks) > 1 else blocks:
            for (s, e) in st:
                t = code[s:e]
                m = re.match(r"^(\s*(?:const\s+|unsigned\s+)*[A-Za-z_][\w:]*(?:\s*\*)*\s+)([A-Za-z_]\w*)\s*=\s*(.+);\s*$",
                             t, re.S)
                if m and TYPE_START.match(t) and "const" not in m.group(1) and "&" not in m.group(1) \
                        and "{" not in m.group(3):
                    cands.append((s, e, m))
        if not cands:
            return None
        s, e, m = rng.choice(cands)
        return src[:s] + f"{m.group(1)}{m.group(2)};\n    {m.group(2)} = {m.group(3)};" + src[e:]

    def m_merge(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for k in range(len(st) - 1):
                a, b = code[st[k][0]:st[k][1]], code[st[k + 1][0]:st[k + 1][1]]
                m = re.match(r"^(\s*(?:unsigned\s+)*[A-Za-z_][\w:]*(?:\s*\*)*\s+)([A-Za-z_]\w*)\s*;\s*$", a)
                if not m or not TYPE_START.match(a):
                    continue
                n = re.match(r"^\s*" + re.escape(m.group(2)) + r"\s*=(?!=)\s*(.+);\s*$", b, re.S)
                if n and m.group(2) not in idents(n.group(1)):
                    cands.append((st[k][0], st[k + 1][1], f"{m.group(1)}{m.group(2)} = {n.group(1)};"))
        if not cands:
            return None
        s, e, rep = rng.choice(cands)
        return src[:s] + rep + src[e:]

    def m_temp(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                t = code[s:e]
                if re.match(r"^\s*(for|while|do|case|default|else)\b", t):
                    continue
                for m in re.finditer(r"\b(func_[0-9A-F]{8}|[A-Za-z_]\w*)\s*\(", t):
                    if m.group(1) in KEYWORDS or m.start() == 0 and TYPE_START.match(t):
                        continue
                    if t[:m.start()].rstrip().endswith((".", "->", "::")):
                        continue                     # a member call: its object would be left behind
                    o = s + m.end() - 1
                    c = match_close(code, o)
                    if c < 0 or c >= e:
                        continue
                    # never out of a conditional or repeated context, never an unevaluated __typeof__ operand
                    if self._in_typeof(code, s + m.start()) or self._cond_context(code, s, s + m.start()):
                        continue
                    call = src[s + m.start():c + 1]
                    if "=" in call and "==" not in call:
                        continue
                    # skip a call that is itself the whole statement or a declaration's callee name
                    if code[s:s + m.start()].strip() == "" and code[c + 1:e].strip() == ";":
                        continue
                    cands.append((s, s + m.start(), c + 1, call))
        if not cands:
            return None
        s, cs, ce, call = rng.choice(cands)
        name = f"tmp{rng.randrange(1000)}"
        if re.search(r"\b" + name + r"\b", src):
            return None
        indent = re.match(r"[ \t]*", src[src.rfind("\n", 0, s) + 1:s]).group(0)
        return src[:s] + f"__typeof__({call}) {name} = {call};\n{indent}" + src[s:cs] + name + src[ce:]

    def m_inline(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for k, (s, e) in enumerate(st):
                t = code[s:e]
                m = re.match(r"^\s*(?:__typeof__\(.*\)|(?:unsigned\s+)*[A-Za-z_][\w:]*(?:\s*\*)*)\s+([A-Za-z_]\w*)\s*=\s*(.+);\s*$",
                             t, re.S)
                if not m or not (TYPE_START.match(t) or t.lstrip().startswith("__typeof__")):
                    continue
                v, expr = m.group(1), m.group(2)
                uses = [j for j in range(k + 1, len(st)) if re.search(r"\b" + v + r"\b", code[st[j][0]:st[j][1]])]
                rest_after_block = code[st[-1][1]:]
                if len(uses) != 1 or uses[0] != k + 1:
                    continue
                u0, u1 = st[k + 1]
                body = src[u0:u1]
                if len(re.findall(r"\b" + v + r"\b", body)) != 1 or v in writes(body):
                    continue
                if re.search(r"\b" + v + r"\b", rest_after_block[:0]):
                    continue
                cands.append((s, e, u0, u1, v, expr))
        if not cands:
            return None
        s, e, u0, u1, v, expr = rng.choice(cands)
        body = re.sub(r"\b" + v + r"\b", lambda _: f"({expr})", src[u0:u1], count=1)
        return src[:s] + body + src[u1:]

    ATOM = r"(?:[A-Za-z_][\w]*(?:(?:\.|->)[A-Za-z_]\w*|\[[^\[\]]*\])*(?:\([^()]*\))?|0x[0-9A-Fa-f]+|\d+(?:\.\d+)?f?)"

    def m_commute(self, src, rng):
        code = mask_comments(src)
        blocks = code_blocks(code)
        if not blocks:
            return None
        lo = min(s for s, _ in blocks)
        pat = re.compile(r"(?<![\w.>\])])(" + self.ATOM + r")\s*(==|!=|\+(?![+=])|(?<=\s)\*(?=\s)|&&|\|\||<=|>=|<(?![<=])|(?<!-)>(?![>=]))\s*(" + self.ATOM +
                         r")(?![\w(\[.])(?!\s*(?:->|\.|\[|\())")
        cands = []
        for m in pat.finditer(code, lo):
            a, op, b = m.group(1), m.group(2), m.group(3)
            if op in ("&&", "||") and ("(" in a or "(" in b):
                continue
            if "(" in a and "(" in b:              # two calls: their order would change
                continue
            if not self._safe_operands(code, m.start(), m.end(), op):
                continue
            if op in ("<", ">") and (re.match(r"[A-Za-z_]", b) and "(" not in b and code[m.end():m.end() + 1] == "("):
                continue
            pre = code[max(0, m.start() - 2):m.start()]
            post = code[m.end():m.end() + 2].lstrip()
            # stay away from precedence traps: only operands that are alone between lower-precedence tokens
            if op in ("+", "*") and (pre.rstrip().endswith(("*", "/", "-", "%")) or post[:1] in ("*", "/", "%")):
                continue
            if op == "+" and (pre.rstrip().endswith("-") or post[:1] == "-"):
                continue
            cands.append(m)
        if not cands:
            return None
        m = rng.choice(cands)
        a, op, b = m.group(1), m.group(2), m.group(3)
        flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}.get(op, op)
        return src[:m.start()] + f"{b} {flip} {a}" + src[m.end():]

    def m_invert(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                t = code[s:e]
                if not t.lstrip().startswith("if"):
                    continue
                o = code.find("(", s)
                c = match_close(code, o)
                if c < 0:
                    continue
                k = c + 1
                while code[k].isspace():
                    k += 1
                if code[k] != "{":
                    continue
                c2 = match_close(code, k)
                j = c2 + 1
                while j < e and code[j].isspace():
                    j += 1
                if not code.startswith("else", j):
                    continue
                j += 4
                while code[j].isspace():
                    j += 1
                if code[j] != "{":
                    continue
                c3 = match_close(code, j)
                if c3 + 1 != e and code[c3 + 1:e].strip():
                    continue
                cands.append((s, o, c, k, c2, j, c3))
        if not cands:
            return None
        s, o, c, k, c2, j, c3 = rng.choice(cands)
        cond = src[o + 1:c]
        m = re.match(r"^\s*!\s*\((.*)\)\s*$", cond, re.S)
        ncond = m.group(1) if m and match_close("(" + m.group(1) + ")", 0) == len(m.group(1)) + 1 else f"!({cond})"
        return src[:o] + f"({ncond}) " + src[j:c3 + 1] + " else " + src[k:c2 + 1] + src[c3 + 1:]

    RETTYPES = ["void", "int", "void*", "bool", "unsigned int"]

    def callee_returns(self, name):
        """True if the callee's asm leaves a value in $v0 (written after its last call), False if it does not,
        None when unknown (no asm, or it ends in a tail jump)."""
        if name in self._returns:
            return self._returns[name]
        r = None
        fs = list((ROOT / "asm").glob(f"nonmatchings/*/{name}.s"))
        if fs:
            ins = re.findall(r"^\s*/\*[^*]*\*/\s+(\w+)\s+([^\n]*)$", fs[0].read_text(), re.M)
            last = max([i for i, (op, _) in enumerate(ins) if op in ("jal", "jalr")], default=-1)
            tail = [i for i, (op, a) in enumerate(ins) if op == "j" or op == "jr" and "$ra" not in a]
            if not tail:
                r = any(a.startswith("$v0,") and not op.startswith(("s", "b")) or op in ("sll", "slt", "sltu",
                        "slti", "sltiu", "sra", "srl") and a.startswith("$v0,")
                        for op, a in ins[last + 1:])
        self._returns[name] = r
        return r

    def m_rettype(self, src, rng):
        cands = list(re.finditer(r'extern\s+"C"\s+(void\s*\*|void|int|bool|unsigned\s+int|char\s*\*)\s+(func_[0-9A-F]{8})\s*\(',
                                 src))
        if not cands:
            return None
        m = rng.choice(cands)
        cur = re.sub(r"\s+", " ", m.group(1)).replace(" *", "*")
        ret = self.callee_returns(m.group(2))
        types = ["void"] if ret is False else [t for t in self.RETTYPES if t != "void"] if ret else self.RETTYPES
        types = [t for t in types if t != cur]
        if not types:
            return None
        return src[:m.start(1)] + rng.choice(types) + src[m.end(1):]

    INTTYPES = ["int", "unsigned int", "short", "unsigned short", "signed char", "unsigned char"]

    def m_inttype(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                m = re.match(r"^(\s*)(unsigned\s+int|unsigned\s+short|unsigned\s+char|signed\s+char|int|short)"
                             r"(\s+[A-Za-z_]\w*\s*[=;])", code[s:e])
                if m:
                    cands.append((s + len(m.group(1)), s + m.end(2), re.sub(r"\s+", " ", m.group(2))))
        if not cands:
            return None
        a, b, cur = rng.choice(cands)
        return src[:a] + rng.choice([t for t in self.INTTYPES if t != cur]) + src[b:]

    def m_for2while(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                if not code[s:e].lstrip().startswith("for"):
                    continue
                o = code.find("(", s)
                c = match_close(code, o)
                parts = src[o + 1:c].split(";")
                if len(parts) != 3:
                    continue
                k = c + 1
                while code[k].isspace():
                    k += 1
                if code[k] != "{":
                    continue
                c2 = match_close(code, k)
                body = src[k + 1:c2]
                if re.search(r"\bcontinue\b", body):
                    continue
                cands.append((s, e, parts, body, c2))
        if not cands:
            return None
        s, e, (init, cond, step), body, c2 = rng.choice(cands)
        init, cond, step = init.strip(), cond.strip() or "1", step.strip()
        out = (f"{init}; " if init else "") + f"while ({cond}) {{{body}"
        out += (f"    {step};\n    }}" if step else "}")
        if re.match(r"(?:unsigned\s+)?\w+\s+\w+", init):
            out = "{ " + out + " }"
        return src[:s] + out + src[c2 + 1:]

    def m_countdown(self, src, rng):
        pat = re.compile(r"for\s*\(\s*(int|unsigned int|short)\s+([A-Za-z_]\w*)\s*=\s*0\s*;\s*\2\s*<\s*([^;]+?)\s*;"
                         r"\s*(?:\2\s*\+\+|\+\+\s*\2)\s*\)")
        cands = list(pat.finditer(src))
        if not cands:
            return None
        m = rng.choice(cands)
        t, v, n = m.group(1), m.group(2), m.group(3)
        t = "int" if t.startswith("unsigned") else t
        return src[:m.start()] + f"for ({t} {v} = ({n}) - 1; {v} >= 0; {v}--)" + src[m.end():]

    # ------------------------------------------------------------ v2: precedence, context and new passes

    PREC = {"*": 13, "/": 13, "%": 13, "+": 12, "-": 12, "<<": 11, ">>": 11, "<": 10, ">": 10, "<=": 10,
            ">=": 10, "==": 9, "!=": 9, "&": 8, "^": 7, "|": 6, "&&": 5, "||": 4, "?": 3, ":": 3}
    TOK_BEFORE = re.compile(r"(<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%<>&^|!~?:)])\s*$")
    TOK_AFTER = re.compile(r"^\s*(<<|>>|<=|>=|==|!=|&&|\|\||->|\+\+|--|[-+*/%<>&^|?:.\[(])")

    def _safe_operands(self, code, start, end, op):
        """True when the operands around `op` at code[start:end] can be swapped without regrouping: the token
        before binds less tightly than op and so does the token after (same level is fine for + and *)."""
        p = self.PREC[op]
        m = self.TOK_BEFORE.search(code[max(0, start - 4):start])
        if m:
            t = m.group(1)
            if t in "!~)" or t not in self.PREC or self.PREC[t] >= p:
                return False
        m = self.TOK_AFTER.match(code[end:end + 4])
        if m:
            t = m.group(1)
            if t in ("->", "++", "--", ".", "[", "("):
                return False
            if t not in self.PREC:
                return False
            if self.PREC[t] > p or self.PREC[t] == p and op not in ("+", "*"):
                return False
        return True

    @staticmethod
    def _cond_context(code, s, pos):
        """True when code[pos] (inside the statement starting at s) is evaluated conditionally or repeatedly:
        after && || ? at any level of the statement head, or inside a loop head or a body."""
        head = code[s:pos]
        if re.match(r"\s*(for|while|do|switch|case|default|else)\b", head):
            return True
        if re.search(r"&&|\|\||\?", head):
            return True
        if "{" in head:
            return True
        m = re.match(r"\s*if\s*\(", head)
        if m:                                  # only the condition of an if, never its (unbraced) body
            c = match_close(code, s + m.end() - 1)
            if c < 0 or pos > c:
                return True
        return False

    @staticmethod
    def _in_typeof(code, pos):
        for m in re.finditer(r"__typeof__\s*\(", code[:pos]):
            c = match_close(code, m.end() - 1)
            if c < 0 or c > pos:
                return True
        return False

    def _func_body(self, code):
        """(head_start, open_brace, close_brace) of the unit's one out-of-line function definition."""
        depth = 0
        for i, c in enumerate(code):
            if c == "{":
                if depth == 0:
                    hs = max(code.rfind(";", 0, i), code.rfind("}", 0, i)) + 1
                    head = code[hs:i]
                    if re.search(r"\)\s*(const\s*)?$", head.strip()) and not re.search(r"\binline\b", head) \
                            and not re.match(r"\s*(struct|class|union|enum)\b", head.strip()):
                        j = match_close(code, i)
                        if j > 0:
                            return hs, i, j
                depth += 1
            elif c == "}":
                depth -= 1
        return None

    def _decl_type(self, code, v):
        m = re.search(r"(?:^|[;{(,]\s*)((?:const\s+|unsigned\s+|signed\s+)*(?:int|short|long|char|float|bool|"
                      r"[A-Za-z_]\w*)(?:\s*\*)*)\s+" + re.escape(v) + r"\s*[=;,)\[]", code, re.M)
        return re.sub(r"\s+", " ", m.group(1)).strip() if m else None

    INT_DECL = re.compile(r"^(?:(?:unsigned|signed)\s+)?(?:int|short|char|long)$|^unsigned$")

    @staticmethod
    def _reads_memory(expr):
        return bool(re.search(r"->|\.|\[|\*|\bD_[0-9A-F]{8}\b|\bthis\b", expr)) or has_call(expr)

    @staticmethod
    def _barrier(stmt):
        """A statement that may change memory: a call, or a store through anything but a plain local name."""
        if has_call(stmt):
            return True
        for m in re.finditer(r"([A-Za-z_][\w.\->\[\]*]*)\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)", stmt):
            if not re.fullmatch(r"[A-Za-z_]\w*", m.group(1)) or re.match(r"D_[0-9A-F]{8}$", m.group(1)):
                return True
        return bool(re.search(r"\+\+|--", stmt) and re.search(r"(->|\.|\[|\*)\s*\w*\s*(\+\+|--)", stmt))

    def m_move_to_use(self, src, rng):
        """Move `T x = e;` down to just before the first statement that uses x, or up past statements that
        neither use x nor change what e reads (memory reads never cross a call or a store)."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for k, (s, e) in enumerate(st):
                t = code[s:e]
                m = re.match(r"^\s*(?:const\s+|unsigned\s+|signed\s+)*[A-Za-z_][\w:]*(?:\s*\*)*\s+([A-Za-z_]\w*)"
                             r"\s*(?:=\s*(.+))?;\s*$", t, re.S)
                if not m or not TYPE_START.match(t):
                    continue
                v, init = m.group(1), m.group(2) or ""
                deps = idents(init)
                mem = self._reads_memory(init)
                call = has_call(init)

                def blocked(u):
                    if re.search(r"\b" + v + r"\b", u) or writes(u) & deps:
                        return True
                    if re.search(r"\bgoto\b|^\s*\w+\s*:(?!:)|\b(case|default)\b", u, re.M):
                        return True
                    if (mem or call) and self._barrier(u):
                        return True
                    if call and self._reads_memory(u):
                        return True
                    return False
                j = k + 1
                while j < len(st) and not blocked(code[st[j][0]:st[j][1]]):
                    j += 1
                if j < len(st) and j > k + 1 and re.search(r"\b" + v + r"\b", code[st[j][0]:st[j][1]]):
                    cands.append(("down", k, j, st))
                j = k - 1
                while j >= 0 and not blocked(code[st[j][0]:st[j][1]]):
                    j -= 1
                if j + 1 < k:
                    cands.append(("up", k, rng.randrange(j + 1, k), st))
        if not cands:
            return None
        d, k, j, st = rng.choice(cands)
        s, e = st[k]
        stmt = src[s:e]
        ts = st[j][0]
        ind = "\n" + re.match(r"[ \t]*", src[src.rfind("\n", 0, ts) + 1:ts]).group(0)
        if d == "down":
            return src[:s] + src[st[k + 1][0]:ts] + stmt + ind + src[ts:]
        return src[:ts] + stmt + ind + src[ts:s] + src[e:]

    def m_reorder_decls(self, src, rng):
        """Move an uninitialised local declaration within its run of declarations (pseudo-number order)."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            runs, cur = [], []
            for k, (s, e) in enumerate(st):
                t = code[s:e]
                if TYPE_START.match(t) and re.match(r"^[^=(]*;\s*$", t):
                    cur.append(k)
                else:
                    if len(cur) > 1:
                        runs.append(cur)
                    cur = []
            if len(cur) > 1:
                runs.append(cur)
            for r in runs:
                cands.append((st, r))
        if not cands:
            return None
        st, r = rng.choice(cands)
        a, b = rng.sample(r, 2)
        order = list(r)
        order.remove(a)
        order.insert(order.index(b) if b in order else len(order), a)
        texts = [src[st[k][0]:st[k][1]] for k in order]
        s0, e0 = st[r[0]][0], st[r[-1]][1]
        return src[:s0] + "\n    ".join(texts) + src[e0:]

    def _var_ok(self, body, v):
        return not re.search(r"&\s*" + v + r"\b(?!\s*[\[.])", re.sub(r"&&", "  ", body)) \
            and not re.search(r"\b(goto)\b|^\s*\w+\s*:(?!:)", body, re.M)

    def m_split_var(self, src, rng):
        """A reused local: from one plain assignment `v = e;` on, use a fresh variable for the rest of its block."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            bs, be = st[0][0], st[-1][1]
            for k, (s, e) in enumerate(st):
                m = re.match(r"^\s*([A-Za-z_]\w*)\s*=(?!=)\s*(.+);\s*$", code[s:e], re.S)
                if not m:
                    continue
                v = m.group(1)
                if v in idents(m.group(2)) or v in KEYWORDS:
                    continue
                decl = None
                for j in range(k):
                    t = code[st[j][0]:st[j][1]]
                    if TYPE_START.match(t) and TYPE_START.match(t).group(1) == v:
                        decl = t
                if not decl or not self._var_ok(code[bs:be], v):
                    continue
                ty = re.match(r"^\s*(.*?)\b" + v + r"\b", decl, re.S).group(1).strip()
                if not ty or "[" in decl.split(v, 1)[1][:3]:
                    continue
                cands.append((s, e, be, v, ty, m.group(2)))
        if not cands:
            return None
        s, e, be, v, ty, rhs = rng.choice(cands)
        n = f"{v}_{rng.randrange(2, 99)}"
        if re.search(r"\b" + n + r"\b", src):
            return None
        rest = re.sub(r"\b" + v + r"\b", n, src[e:be])
        return src[:s] + f"{ty} {n} = {rhs};" + rest + src[be:]

    def m_merge_var(self, src, rng):
        """Two same-type locals of one block with disjoint lifetimes become one (b's uses go to a); this also
        writes a call result back into its argument variable (`T b = f(a);` -> `a = f(a);`)."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            bs, be = st[0][0], st[-1][1]
            decls = {}
            for k, (s, e) in enumerate(st):
                t = code[s:e]
                m = TYPE_START.match(t)
                if m and not re.search(r"\[", t.split("=")[0]):
                    ty = re.match(r"^\s*(.*?)\b" + m.group(1) + r"\b", t, re.S).group(1).strip()
                    decls[m.group(1)] = (k, ty)
            names = list(decls)
            for a in names:
                for b in names:
                    if a == b or decls[a][1] != decls[b][1] or decls[a][0] >= decls[b][0]:
                        continue
                    if not self._var_ok(code[bs:be], a) or not self._var_ok(code[bs:be], b):
                        continue
                    kb = decls[b][0]
                    later_a = [j for j in range(kb + 1, len(st)) if re.search(r"\b" + a + r"\b", code[st[j][0]:st[j][1]])]
                    if later_a:
                        continue
                    tb = code[st[kb][0]:st[kb][1]]
                    if "=" not in tb:                  # b must start with a value at its declaration
                        continue
                    # b must not be used before its declaration's statement in this block's loops: same block
                    cands.append((st, kb, a, b, be))
        if not cands:
            return None
        st, kb, a, b, be = rng.choice(cands)
        s, e = st[kb]
        t = src[s:e]
        m = re.match(r"^(\s*).*?\b" + b + r"\b\s*=\s*(.+);\s*$", t, re.S)
        if not m:
            return None
        rest = re.sub(r"\b" + b + r"\b", a, src[e:be])
        return src[:s] + f"{m.group(1)}{a} = {m.group(2)};" + rest + src[be:]

    def m_param(self, src, rng):
        """Use a parameter directly instead of a local copy `T x = p;`, or add such a copy."""
        code = mask_comments(src)
        fb = self._func_body(code)
        if not fb:
            return None
        hs, ob, cb = fb
        head = code[hs:ob]
        po = head.find("(")
        pc = match_close(head, po)
        params = []
        for p in head[po + 1:pc].split(","):
            m = re.match(r"^\s*(.*?[\s*&])([A-Za-z_]\w*)\s*$", p)
            if m and "&" not in m.group(1) and "..." not in p:
                params.append((re.sub(r"\s+", " ", m.group(1)).strip(), m.group(2)))
        if not params:
            return None
        body = src[ob + 1:cb]
        copies = []
        for ty, p in params:
            for m in re.finditer(r"(?m)^(\s*)(" + re.escape(ty).replace(r"\ ", r"\s+") + r")\s*([A-Za-z_]\w*)\s*=\s*"
                                 + p + r"\s*;[ \t]*\n", body):
                x = m.group(3)
                after = body[m.end():]
                if x in writes(after) or p in writes(after) or not self._var_ok(body, x) or not self._var_ok(body, p):
                    continue
                copies.append((m, x, p))
        if copies and rng.random() < 0.6:
            m, x, p = rng.choice(copies)
            nb = body[:m.start()] + "\n" + re.sub(r"\b" + x + r"\b", p, body[m.end():])
            return src[:ob + 1] + nb + src[cb:]
        ty, p = rng.choice(params)
        if not self._var_ok(body, p) or re.search(r"\b" + p + r"\b", body) is None:
            return None
        n = f"{p}_{rng.randrange(2, 99)}"
        if re.search(r"\b" + n + r"\b", src):
            return None
        nb = re.sub(r"\b" + p + r"\b", n, body)
        return src[:ob + 1] + f"\n    {ty} {n} = {p};" + nb + src[cb:]

    def m_nest_and(self, src, rng):
        """`if (a && b) S` (no else)  <->  `if (a) { if (b) S }`."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                t = code[s:e]
                m = re.match(r"^\s*if\s*\(", t)
                if not m:
                    continue
                o = s + m.end() - 1
                c = match_close(code, o)
                if c < 0:
                    continue
                if re.search(r"\belse\b", code[c:e]):
                    continue
                cond = code[o + 1:c]
                # split at a top-level &&
                depth, cuts = 0, []
                i = 0
                while i < len(cond):
                    ch = cond[i]
                    if ch in "([":
                        depth += 1
                    elif ch in ")]":
                        depth -= 1
                    elif depth == 0 and cond.startswith("&&", i):
                        cuts.append(i)
                        i += 1
                    elif depth == 0 and (cond.startswith("||", i) or ch == "?"):
                        cuts = None
                        break
                    i += 1
                if cuts:
                    cands.append(("split", s, o, c, e, rng.choice(cuts)))
                k = c + 1
                while k < e and code[k].isspace():
                    k += 1
                inner = code[k:e]
                if inner.startswith("{"):
                    c2 = match_close(code, k)
                    inner_st = code[k + 1:c2].strip()
                    if c2 == e - 1 and re.match(r"^if\s*\(", inner_st) and not re.search(r"\belse\b", inner_st):
                        sp = split_statements(code, k, c2)
                        if len(sp) == 1:
                            cands.append(("join", s, o, c, e, (k, c2, sp[0])))
        if not cands:
            return None
        kind, s, o, c, e, x = rng.choice(cands)
        if kind == "split":
            a, b = src[o + 1:o + 1 + x].strip(), src[o + 3 + x:c].strip()
            body = src[c + 1:e].strip()
            ind = re.match(r"[ \t]*", src[src.rfind("\n", 0, s) + 1:s]).group(0)
            return src[:s] + f"if ({a}) {{\n{ind}    if ({b}) {body}\n{ind}}}" + src[e:]
        k, c2, (is_, ie) = x
        it = src[is_:ie]
        m = re.match(r"^\s*if\s*\(", it)
        io = is_ + m.end() - 1
        ic = match_close(code, io)
        return src[:o + 1] + f"({src[o + 1:c].strip()}) && ({src[io + 1:ic].strip()})" + ") " + \
            src[ic + 1:ie].strip() + src[e:]

    def m_early_return(self, src, rng):
        """In a void function body: `if (c) return; R` (R to the end)  <->  `if (!(c)) { R }`."""
        code = mask_comments(src)
        fb = self._func_body(code)
        if not fb:
            return None
        hs, ob, cb = fb
        if not re.search(r"(?:^|\s)void\s+[\w:]+\s*\(", code[hs:ob]):
            return None
        st = split_statements(code, ob, cb)
        cands = []
        for k, (s, e) in enumerate(st[:-1]):
            m = re.match(r"^\s*if\s*\(", code[s:e])
            if m:
                o = s + m.end() - 1
                c = match_close(code, o)
                if re.match(r"^\s*return\s*;\s*$", code[c + 1:e]):
                    rest = code[st[k + 1][0]:st[-1][1]]
                    if not re.search(r"^\s*\w+\s*:(?!:)|\bgoto\b", rest, re.M):
                        cands.append(("wrap", s, o, c, st[k + 1][0], st[-1][1]))
        s, e = st[-1]
        m = re.match(r"^\s*if\s*\(", code[s:e])
        if m:
            o = s + m.end() - 1
            c = match_close(code, o)
            k = c + 1
            while code[k].isspace():
                k += 1
            if code[k] == "{" and match_close(code, k) == e - 1:
                cands.append(("unwrap", s, o, c, k, e))
        if not cands:
            return None
        kind, s, o, c, a, b = rng.choice(cands)
        cond = src[o + 1:c]
        m = re.match(r"^\s*!\s*\((.*)\)\s*$", cond, re.S)
        ncond = m.group(1) if m and match_close("(" + m.group(1) + ")", 0) == len(m.group(1)) + 1 else f"!({cond})"
        if kind == "wrap":
            return src[:s] + f"if ({ncond}) {{\n    " + src[a:b] + "\n    }" + src[b:]
        return src[:s] + f"if ({ncond})\n        return;\n    " + src[a + 1:b - 1].strip() + "\n" + src[b:]

    LV = r"[A-Za-z_]\w*(?:(?:\.|->)[A-Za-z_]\w*|\[[A-Za-z_0-9]+\])*"

    def m_compound(self, src, rng):
        """`x = x op y;`  <->  `x op= y;` (whole statements only)."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                t = code[s:e]
                if TYPE_START.match(t) or re.match(r"^\s*(return|operator)\b", t):
                    continue
                m = re.match(r"^(\s*)(" + self.LV + r")\s*=\s*(" + self.LV + r")\s*(<<|>>|[-+*/%&|^])\s*(.+?);\s*$",
                             t, re.S)
                if m and m.group(2) == m.group(3):
                    rhs = m.group(5).strip()
                    if re.fullmatch(self.ATOM, rhs) or rhs.startswith("(") and match_close(rhs, 0) == len(rhs) - 1:
                        cands.append((s + len(m.group(1)), e, f"{m.group(2)} {m.group(4)}= {rhs};"))
                m = re.match(r"^(\s*)(" + self.LV + r")\s*(<<|>>|[-+*/%&|^])=\s*(.+?);\s*$", t, re.S)
                if m and m.group(2) not in KEYWORDS:
                    y = m.group(4).strip()
                    y = y if re.fullmatch(self.ATOM, y) else f"({y})"
                    cands.append((s + len(m.group(1)), e, f"{m.group(2)} = {m.group(2)} {m.group(3)} {y};"))
        if not cands:
            return None
        s, e, rep = rng.choice(cands)
        return src[:s] + rep + src[e:]

    def m_chain(self, src, rng):
        """`a = e; b = a;`  <->  `b = a = e;`."""
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for k in range(len(st)):
                t = code[st[k][0]:st[k][1]]
                m = re.match(r"^\s*(" + self.LV + r")\s*=\s*(" + self.LV + r")\s*=(?!=)\s*(.+);\s*$", t, re.S)
                if m:
                    cands.append(("split", st[k][0], st[k][1], m))
                if k + 1 < len(st):
                    m1 = re.match(r"^\s*(" + self.LV + r")\s*=(?!=)\s*(.+);\s*$", t, re.S)
                    t2 = code[st[k + 1][0]:st[k + 1][1]]
                    m2 = re.match(r"^\s*(" + self.LV + r")\s*=\s*(" + self.LV + r")\s*;\s*$", t2)
                    if m1 and m2 and m2.group(2) == m1.group(1) and not TYPE_START.match(t):
                        cands.append(("join", st[k][0], st[k + 1][1], (m1, m2)))
        if not cands:
            return None
        kind, s, e, m = rng.choice(cands)
        if kind == "split":
            return src[:s] + f"{m.group(2)} = {m.group(3)};\n    {m.group(1)} = {m.group(2)};" + src[e:]
        m1, m2 = m
        return src[:s] + f"{m2.group(1)} = {m1.group(1)} = {m1.group(2)};" + src[e:]

    def m_call_order(self, src, rng):
        """Call an extern "C" callee through a `static inline` wrapper whose parameter order differs, so the
        arguments are evaluated (and loaded) in another order. Only for side-effect-free arguments."""
        decls = list(re.finditer(r'extern\s+"C"\s+([\w\s*]+?)\s*\b(func_[0-9A-F]{8})\s*\(([^()]*)\)\s*;', src))
        cands = []
        for d in decls:
            ps = [p.strip() for p in d.group(3).split(",")]
            if len(ps) < 2 or any(p in ("", "void", "...") for p in ps):
                continue
            types = []
            for p in ps:
                m = re.match(r"^(.*?[\s*&])([A-Za-z_]\w*)$", p)
                types.append(m.group(1).strip() if m and m.group(2) not in TYPE_WORDS else p)
            for c in re.finditer(r"\b" + d.group(2) + r"\s*\(", src[d.end():]):
                o = d.end() + c.end() - 1
                cl = match_close(src, o)
                if cl < 0:
                    continue
                args, depth, cur = [], 0, ""
                for ch in src[o + 1:cl]:
                    if ch in "([":
                        depth += 1
                    elif ch in ")]":
                        depth -= 1
                    if ch == "," and depth == 0:
                        args.append(cur)
                        cur = ""
                    else:
                        cur += ch
                args.append(cur)
                if len(args) != len(types) or any(has_call(a) or re.search(r"\+\+|--|[^=!<>]=[^=]", a) for a in args):
                    continue
                cands.append((d, types, o, cl, args, d.end() + c.start()))
        if not cands:
            return None
        d, types, o, cl, args, cs = rng.choice(cands)
        n = len(types)
        perm = list(range(n))
        while perm == list(range(n)):
            rng.shuffle(perm)
        ret = re.sub(r"\s+", " ", d.group(1)).strip()
        name = f"Call_{d.group(2)[5:]}_{''.join(map(str, perm))}"
        helper = f"static inline {ret} {name}(" + ", ".join(f"{types[i]} a{i}" for i in perm) + ") { " + \
            ("" if ret == "void" else "return ") + f"{d.group(2)}(" + ", ".join(f"a{i}" for i in range(n)) + "); }\n"
        out = src[:cs] + f"{name}(" + ", ".join(args[i].strip() for i in perm) + ")" + src[cl + 1:]
        if name not in src:
            out = out[:d.end()] + "\n" + helper + out[d.end():]
        return out

    def m_ineq(self, src, rng):
        """On integer locals: `x < N` <-> `x <= N - 1`, `x > N` <-> `x >= N + 1` (N an integer literal); and
        `a - b` <-> `a + -b`."""
        code = mask_comments(src)
        lo = min((s for s, _ in code_blocks(code)), default=len(code))
        cands = []
        for m in re.finditer(r"\b([A-Za-z_]\w*)\s*(<=|>=|<|>)\s*(-?\d+)\b(?![.\w])", code[lo:]):
            ty = self._decl_type(code, m.group(1))
            if not ty or not self.INT_DECL.match(ty):
                continue
            if not self._safe_operands(code, lo + m.start(), lo + m.end(), m.group(2)):
                continue
            n = int(m.group(3))
            new = {"<": ("<=", n - 1), "<=": ("<", n + 1), ">": (">=", n + 1), ">=": (">", n - 1)}[m.group(2)]
            if ty.startswith("unsigned") and new[1] < 0:
                continue
            cands.append((lo + m.start(), lo + m.end(), f"{m.group(1)} {new[0]} {new[1]}"))
        for m in re.finditer(r"(?<=[\w)\]])\s*-\s*(" + self.ATOM + r")(?![\w(\[.])", code[lo:]):
            cands.append((lo + m.start(), lo + m.end(), f" + -{m.group(1)}"))
        for m in re.finditer(r"(?<=[\w)\]])\s*\+\s*-\s*(" + self.ATOM + r")(?![\w(\[.])", code[lo:]):
            cands.append((lo + m.start(), lo + m.end(), f" - {m.group(1)}"))
        if not cands:
            return None
        s, e, rep = rng.choice(cands)
        return src[:s] + rep + src[e:]

    def m_flags(self, src, rng):
        """Add or drop one allowed per-file flag on the first line."""
        flags = [f for f in self.allowed if not f.startswith("-O") and not f.startswith("-G")] + ["-O1", "-O2"]
        if not flags:
            return None
        first, rest = (src.split("\n", 1) + [""])[:2]
        m = re.match(r"^/\*\s*cflags:(.*?)\*/\s*$", first)
        cur = m.group(1).split() if m else []
        f = rng.choice(flags)
        if f in cur:
            cur.remove(f)
        else:
            if f.startswith("-O"):
                cur = [c for c in cur if not c.startswith("-O")]
            cur.append(f)
        line = f"/* cflags: {' '.join(cur)} */" if cur else None
        body = rest if m else src
        return (line + "\n" + body) if line else body


# ---------------------------------------------------------------- checking and scoring

EXTRA_BANNED = [
    (re.compile(r"\bdo\s*\{[^{}]*\}\s*while\s*\(\s*0\s*\)"), "do {} while (0)"),
    (re.compile(r"(?m)^\s*([A-Za-z_][\w.\->\[\]]*)\s*=\s*\1\s*;"), "self-assignment"),
]


def out_of_line_functions(code):
    """Names of non-inline function definitions at file scope (a unit may define exactly one)."""
    n = 0
    depth = 0
    i = 0
    while i < len(code):
        c = code[i]
        if c == "{":
            if depth == 0:
                head = code[max(0, code.rfind(";", 0, i), code.rfind("}", 0, i)) + 1:i]
                if re.search(r"\)\s*(const\s*)?$", head.strip()) and not re.search(r"\binline\b", head) \
                        and not re.match(r"\s*(struct|class|union|enum|extern)\b", head.strip()):
                    n += 1
            depth += 1
        elif c == "}":
            depth -= 1
        i += 1
    return n


LOADSTORE = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x27: "lwu", 0x37: "ld",
             0x28: "sb", 0x29: "sh", 0x2B: "sw", 0x3F: "sd"}


def width_sig(words):
    """Counts of memory-access widths and of zero/sign extensions: a candidate that moves these away from
    the game's (an `lh` where the game has `lw`, an extra `andi 0xFFFF`) narrowed or widened a value."""
    from collections import Counter
    c = Counter()
    for w in words:
        op = w >> 26
        if op in LOADSTORE:
            c[LOADSTORE[op]] += 1
        elif op == 0x0C and (w & 0xFFFF) in (0xFF, 0xFFFF):
            c[f"andi{w & 0xFFFF:x}"] += 1
        elif op == 0 and (w & 0x3F) in (0, 2, 3) and ((w >> 6) & 31) in (16, 24) and w:
            c[f"shift{w & 0x3F}_{(w >> 6) & 31}"] += 1
    return c


def sig_dist(a, b):
    return sum(abs(a[k] - b[k]) for k in set(a) | set(b))


class Scorer:
    def __init__(self, name, wid):
        import match
        import scan
        self.match = match
        self.scan = scan
        self.name = name
        self.dir = BUILD / "cxxperm" / name / f"w{wid}"
        self.dir.mkdir(parents=True, exist_ok=True)
        self.path = self.dir / f"{name}.cpp"
        self.allowed = set(compiler_config().get("per_file", {}).get("allowed_cflags", []))
        self.base_funcs = None
        self.width_limit = None               # set from the base: candidates may not drift further
        self.stats = {"illegal": 0, "error": 0, "compiled": 0, "width": 0}

    def legal(self, src):
        self.path.write_text(src)
        probs = self.scan.scan_file(self.path, self.allowed, None)
        if probs:
            return False
        code = self.scan.strip_comments(src)
        for rx, _ in EXTRA_BANNED:
            if rx.search(code):
                return False
        if self.base_funcs is not None and out_of_line_functions(code) > self.base_funcs:
            return False
        return True

    def score(self, src):
        if not self.legal(src):
            self.stats["illegal"] += 1
            return None
        res = self.match.compare(self.name, self.path, outdir=self.dir / "o")
        if res.error:
            self.stats["error"] += 1
            return None
        self.stats["compiled"] += 1
        if not res.ok:
            d = sig_dist(width_sig(res.ours.words), width_sig(res.target.words))
            if self.width_limit is None:
                self.width_limit = d
            elif d > self.width_limit:
                self.stats["width"] += 1
                return None
        return (1 if res.ok else 0, round(self.match.fuzzy(res), 3), -len(res.diffs))


def flag_variants(src, allowed):
    """The unit with each allowed per-file flag set, and with each pair of non -O/-G flags."""
    first, rest = (src.split("\n", 1) + [""])[:2]
    m = re.match(r"^/\*\s*cflags:(.*?)\*/\s*$", first)
    cur = m.group(1).split() if m else []
    body = rest if m else src
    plain = [f for f in allowed if not f.startswith(("-O", "-G"))]
    sets = [[f] for f in allowed] + [[f, g] for i, f in enumerate(plain) for g in plain[i + 1:]]
    seen = set()
    for add in sets:
        fl = [c for c in cur if not (c.startswith("-O") and any(x.startswith("-O") for x in add))
              and not (c.startswith("-G") and any(x.startswith("-G") for x in add))]
        for f in add:
            fl = [c for c in fl if c != f] if f in fl else fl + [f]
        key = tuple(sorted(fl))
        if key in seen or key == tuple(sorted(cur)):
            continue
        seen.add(key)
        yield (f"/* cflags: {' '.join(fl)} */\n" + body if fl else body), fl


def fmt(sc):
    return "MATCH" if sc[0] else f"fuzzy {sc[1]:.1f}, {-sc[2]} words differ"


# ---------------------------------------------------------------- the search

def worker(args):
    name, base, wid, seed, deadline, unsafe, keep, stop, outq, focus, guard = args
    try:
        os.nice(10)
    except OSError:
        pass
    rng = random.Random(seed)
    sc = Scorer(name, wid)
    sc.base_funcs = out_of_line_functions(mask_comments(base))
    mut = Mutator(unsafe, focus, sc.allowed)
    if not guard:
        sc.width_limit = 10 ** 9
    base_score = sc.score(base)
    if base_score is None:
        outq.put(("error", wid, "base does not compile or fails scan"))
        return
    pool = [(base_score, base)]
    seen = {base}
    tries = 0
    stale = 0
    while time.time() < deadline and not stop.is_set():
        parent_score, parent = rng.choice(pool[:max(1, keep)])
        cand = parent
        how = []
        for _ in range(rng.choice((1, 1, 1, 2, 2, 3))):
            nxt, op = mut.mutate(cand, rng)
            if nxt is None:
                break
            cand = nxt
            how.append(op)
        if cand == parent or cand in seen:
            stale += 1
            if stale > 200:
                pool = pool[:1]
                stale = 0
            continue
        seen.add(cand)
        tries += 1
        s = sc.score(cand)
        outq.put(("tick", wid, None))
        if s is None:
            continue
        if s >= pool[-1][0] or len(pool) < keep:
            pool.append((s, cand))
            pool.sort(key=lambda p: p[0], reverse=True)
            del pool[keep:]
        if s > pool[0][0] or s >= parent_score and s > base_score:
            outq.put(("cand", wid, (s, cand, "+".join(how))))
            stale = 0
        else:
            stale += 1
        if s[0]:
            stop.set()
            break
        if stale > 400:                      # restart from the original or a random keeper
            pool = [(base_score, base)] if rng.random() < 0.5 else [rng.choice(pool)]
            stale = 0
    outq.put(("done", wid, sc.stats))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src", help="unit to permute (default src/nonmatching/<name>.cpp, else src/funcs/)")
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("--time", type=int, default=600, help="seconds (default 600)")
    ap.add_argument("--keep", type=int, default=6, help="candidates kept per worker (default 6)")
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument("--no-unsafe", action="store_true", help="skip mutations that can change evaluation order")
    ap.add_argument("--out", help="output dir (default work/cxxperm/<name>)")
    ap.add_argument("--sweep-flags", action="store_true",
                    help="first try every allowed per-file flag and every pair of them on the starting unit")
    ap.add_argument("--focus", choices=["regalloc"], help="bias towards the declaration and live-range passes")
    ap.add_argument("--no-width-guard", action="store_true",
                    help="keep candidates whose load/store widths or extensions drift from the game's")
    a = ap.parse_args()

    if a.src:
        src = Path(a.src)
    else:
        src = ROOT / "src" / "nonmatching" / f"{a.name}.cpp"
        if not src.exists():
            src = unit_path(a.name)
    base = src.read_text()
    out = Path(a.out) if a.out else ROOT / "work" / "cxxperm" / a.name
    out.mkdir(parents=True, exist_ok=True)

    seed = a.seed if a.seed is not None else int(time.time())
    deadline = time.time() + a.time
    mgr = mp.Manager()
    stop = mgr.Event()
    q = mgr.Queue()
    jobs = [(a.name, base, w, seed + w, deadline, not a.no_unsafe, a.keep, stop, q, a.focus, not a.no_width_guard)
            for w in range(a.jobs)]
    procs = [mp.Process(target=worker, args=(j,)) for j in jobs]
    for p in procs:
        p.start()

    sc0 = Scorer(a.name, "base")
    base_score = sc0.score(base)
    if base_score is None:
        stop.set()
        for p in procs:
            p.join()
        sys.exit(f"{a.name}: the starting unit does not compile or fails scan.py's checks")
    print(f"{a.name}: base {fmt(base_score)}; {a.jobs} workers for {a.time}s", flush=True)
    if a.sweep_flags:
        tried = better = 0
        for fsrc, fl in flag_variants(base, sorted(sc0.allowed)):
            fs = sc0.score(fsrc)
            tried += 1
            if fs and fs > base_score:
                better += 1
                print(f"  flags {' '.join(fl) or '(none)'}: {fmt(fs)}", flush=True)
                (out / f"flags_{'_'.join(f.strip('-') for f in fl)}.cpp").write_text(
                    f"/* cxxperm: {fmt(fs)} via flags */\n" + fsrc)
        print(f"  flag sweep: {tried} flag sets, {better} better than base", flush=True)

    best = []                                 # (score, src, how)
    wins = {}
    stats = {}
    done = 0
    ticks = 0
    t0 = time.time()
    last = t0
    while done < len(procs):
        try:
            kind, wid, data = q.get(timeout=5)
        except Exception:
            if time.time() > deadline + 60:
                break
            continue
        if kind == "tick":
            ticks += 1
        elif kind == "done":
            done += 1
            for k, v in (data or {}).items():
                stats[k] = stats.get(k, 0) + v
        elif kind == "error":
            print(f"worker {wid}: {data}", flush=True)
            done += 1
        elif kind == "cand":
            s, csrc, how = data
            if any(b[1] == csrc for b in best):
                continue
            best.append((s, csrc, how))
            for op in how.split("+"):
                wins[op] = wins.get(op, 0) + 1
            best.sort(key=lambda b: b[0], reverse=True)
            del best[8:]
            if best[0][1] == csrc:
                print(f"  [{time.time() - t0:6.0f}s] new best: {fmt(s)}  ({how})", flush=True)
            for k, (bs, bsrc, bhow) in enumerate(best):
                (out / f"best_{k}.cpp").write_text(f"/* cxxperm: {fmt(bs)} via {bhow} */\n" + bsrc)
        if time.time() - last > 60:
            last = time.time()
            print(f"  [{last - t0:6.0f}s] {ticks} candidates, {ticks / (last - t0):.2f}/s", flush=True)
    stop.set()
    for p in procs:
        p.join(timeout=30)
    el = time.time() - t0
    print(f"{a.name}: {ticks} candidates in {el:.0f}s ({ticks / max(el, 1):.2f}/s); "
          f"best {fmt(best[0][0]) if best else 'none better than base'}; results in {out}")
    if stats:
        print("  " + ", ".join(f"{k} {v}" for k, v in sorted(stats.items())))
    if wins:
        print("  improving passes: " + ", ".join(f"{k} {v}" for k, v in sorted(wins.items(), key=lambda x: -x[1])))
    shutil.rmtree(BUILD / "cxxperm" / a.name, ignore_errors=True)


if __name__ == "__main__":
    main()
