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
    def __init__(self, unsafe=True):
        self.unsafe = unsafe
        self.ops = [self.m_swap, self.m_swap, self.m_split, self.m_merge, self.m_temp, self.m_inline,
                    self.m_commute, self.m_commute, self.m_invert, self.m_rettype, self.m_inttype, self.m_for2while]
        if unsafe:
            self.ops.append(self.m_countdown)

    def mutate(self, src, rng):
        for _ in range(20):
            op = rng.choice(self.ops)
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

    def m_rettype(self, src, rng):
        cands = list(re.finditer(r'extern\s+"C"\s+(void\s*\*|void|int|bool|unsigned\s+int|char\s*\*)\s+(func_[0-9A-F]{8})\s*\(',
                                 src))
        if not cands:
            return None
        m = rng.choice(cands)
        cur = re.sub(r"\s+", " ", m.group(1)).replace(" *", "*")
        new = rng.choice([t for t in self.RETTYPES if t != cur])
        return src[:m.start(1)] + new + src[m.end(1):]

    INTTYPES = ["int", "unsigned int", "short", "unsigned short"]

    def m_inttype(self, src, rng):
        code, blocks = self._stmts(src)
        cands = []
        for st in blocks:
            for (s, e) in st:
                m = re.match(r"^(\s*)(unsigned\s+int|unsigned\s+short|int|short)(\s+[A-Za-z_]\w*\s*[=;])", code[s:e])
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


# ---------------------------------------------------------------- checking and scoring

EXTRA_BANNED = [
    (re.compile(r"\bdo\s*\{[^{}]*\}\s*while\s*\(\s*0\s*\)"), "do {} while (0)"),
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
        self.stats = {"illegal": 0, "error": 0, "compiled": 0}

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
        return (1 if res.ok else 0, round(self.match.fuzzy(res), 3), -len(res.diffs))


def fmt(sc):
    return "MATCH" if sc[0] else f"fuzzy {sc[1]:.1f}, {-sc[2]} words differ"


# ---------------------------------------------------------------- the search

def worker(args):
    name, base, wid, seed, deadline, unsafe, keep, stop, outq = args
    try:
        os.nice(10)
    except OSError:
        pass
    rng = random.Random(seed)
    sc = Scorer(name, wid)
    sc.base_funcs = out_of_line_functions(mask_comments(base))
    mut = Mutator(unsafe)
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
    jobs = [(a.name, base, w, seed + w, deadline, not a.no_unsafe, a.keep, stop, q) for w in range(a.jobs)]
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

    best = []                                 # (score, src, how)
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
    shutil.rmtree(BUILD / "cxxperm" / a.name, ignore_errors=True)


if __name__ == "__main__":
    main()
