#!/usr/bin/env python3
"""Forbidden-construct gate for unit files. Text only: needs no disc or toolchain.

    python tools/scan.py                 # every src/funcs/* file
    python tools/scan.py FILE...         # just these

A matching function must be plain C++ that a 2003 compiler could have been fed.
Rejected (each prints "PROBLEM <file>: <why>" for Steward's report):
  - inline asm in any spelling, register pinning (register x asm("$s0")),
    .set noreorder, #pragma, INCLUDE_ASM/INCLUDE_RODATA/GLOBAL_ASM
  - __attribute__((section(...))) and other placement tricks
  - hard-coded addresses inside the game image (0x00100000..0x00468C30): use the symbol
    (a plain number in that range is allowed with `/* const: 0xVALUE */`; gate.py checks the asm)
  - string literals: the game's strings stay in its .rodata; use extern char D_XXXXXXXX[]
  - bare expression statements (`m_count;`): dead reads kept to steer the compiler
  - #include of anything that is not a header
  - a file name that is not func_XXXXXXXX.cpp for a function in the table
  - per-file cflags outside toolchain/compiler.toml [per_file].allowed_cflags

The one exception (config/inline_asm_allow.us.txt; policy in RULES.md and docs/ASM_ONLY.md): the unit of
a listed function (VU0 macro mode, interrupt or system-call code) may use inline asm, as small helpers
only. Every asm statement must
  - be a statement of its own, the only one in a `static inline` function (no file-scope asm, no asm
    labels on declarations; register pinning stays banned everywhere)
  - hold at most 3 instructions (the template split on `;` and newlines)
  - contain no assembler directive (`.word`, `.byte`, `.half`, `.set`, any `.xxx`), no label and no
    branch or jump (`b*`, `j*`, `eret`)
All the logic around the helpers (loops, branches, address arithmetic, loads, stores, calls) is C++.

Object-level rules (exactly one function, no data, rodata or literal sections of
its own) are checked by tools/gate.py.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import CFLAGS_RE, CONFIG, FUNCTIONS_CSV, SRC_FUNCS, SRC_NONMATCHING, UNIT_CONST_RE, compiler_config  # noqa: E402

UNIT_NAME = re.compile(r"^func_([0-9A-F]{8})\.cpp$")
ASM_RULE = (re.compile(r"\b__asm__\b|\b__asm\b|\basm\s*\(|\basm\s+volatile\b|\basm\s+__volatile__\b"),
            "inline asm is not allowed: write C++ (register pinning and asm blocks fake a match)")
RULES = [
    ASM_RULE,
    (re.compile(r"\bregister\b[^;]*\b(?:asm|__asm__)\b"), "register pinning is not allowed"),
    (re.compile(r"\.set\s+(?:no)?reorder|\.set\s+(?:no)?at\b"), "assembler directives are not allowed"),
    (re.compile(r"^\s*#\s*pragma\b", re.M), "#pragma is not allowed"),
    (re.compile(r"\b(?:INCLUDE_ASM|INCLUDE_RODATA|GLOBAL_ASM|NON_MATCHING)\b"),
     "asm include macros do not belong in a unit file: a unit is the finished function"),
    (re.compile(r"__attribute__\s*\(\(\s*(?:section|aligned|used|naked|noinline)\b"),
     "placement/linkage attributes are not allowed"),
    (re.compile(r"^\s*#\s*include\s*[<\"][^>\"]*\.(?:c|cpp|cc|s|S|inc|txt)[>\"]", re.M),
     "only headers may be included"),
]
BARE_STMT = re.compile(r"^\s*(?!(?:break|continue|return|default)\b)[A-Za-z_][\w.]*(?:->[\w.]+)*\s*;\s*$", re.M)
ADDR_LIT = re.compile(r"\b0x([0-9A-Fa-f]{6,8})\b")
IMAGE = (0x00100000, 0x00468C30)
STRING_LIT = re.compile(r'"(?:[^"\\]|\\.)*"')


INLINE_ASM_ALLOW = CONFIG / "inline_asm_allow.us.txt"
ASM_KW = re.compile(r"\b(?:__asm__|__asm|asm)\b")
ASM_QUAL = re.compile(r"\s*(?:__volatile__|__volatile|volatile)?\s*\(")
MAX_ASM_INSNS = 3
BRANCH_MNEMONIC = re.compile(r"^(?:b[a-z0-9]*|j[a-z]*|eret|deret)(?:\.[a-z0-9.]*)?$")
INLINE_WORDS = {"inline", "__inline__", "__inline"}


def inline_asm_allowlist(path=None):
    """Function names whose unit may hold inline-asm helpers (`func_XXXXXXXX  reason` lines)."""
    path = Path(path or INLINE_ASM_ALLOW)
    if not path.exists():
        return set()
    names = set()
    for line in path.read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            names.add(line.split()[0])
    return names


def _skip_string(code, i):
    q, j = code[i], i + 1
    while j < len(code) and code[j] != q:
        j += 2 if code[j] == "\\" else 1
    return j + 1


def _close_paren(code, i):
    """Index just past the parenthesis matching code[i] == '('."""
    depth, n = 0, len(code)
    while i < n:
        c = code[i]
        if c in "\"'":
            i = _skip_string(code, i)
            continue
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return n


def _top_level_blocks(code):
    """[(open brace index, close brace index, header text)] for every top-level brace block."""
    blocks, depth, start, hdr_from, i, n = [], 0, 0, 0, 0, len(code)
    while i < n:
        c = code[i]
        if c in "\"'":
            i = _skip_string(code, i)
            continue
        if c == "{":
            if depth == 0:
                start = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                blocks.append((start, i, code[hdr_from:start]))
                hdr_from = i + 1
        elif c == ";" and depth == 0:
            hdr_from = i + 1
        elif c == "#" and depth == 0:          # a preprocessor line is not part of the next header
            j = code.find("\n", i)
            hdr_from = i = n if j < 0 else j
            continue
        i += 1
    return blocks


def _asm_template(args):
    """The concatenated string literals at the start of an asm statement's parentheses."""
    out, i = [], 0
    while True:
        while i < len(args) and args[i].isspace():
            i += 1
        if i < len(args) and args[i] == '"':
            j = _skip_string(args, i)
            out.append(args[i + 1:j - 1])
            i = j
        else:
            return "".join(out)


def check_inline_asm(code):
    """Check the asm statements of an allowlisted unit (comments already stripped). Returns the problems and
    the code with those statements blanked out, so their template and constraint strings are not taken for
    string literals by the other rules."""
    problems, spans, seen = [], [], set()
    blocks = _top_level_blocks(code)
    for m in ASM_KW.finditer(code):
        q = ASM_QUAL.match(code, m.end())
        if not q:
            problems.append("`asm` may only start an asm statement: `__asm__ __volatile__(\"insn\" : out : in);`")
            continue
        end = _close_paren(code, q.end() - 1)
        spans.append((m.start(), end))
        if code[:m.start()].rstrip()[-1:] not in (";", "{", "}"):
            problems.append("an asm statement must be a statement of its own "
                            "(no asm labels on declarations, no register pinning)")
        if not code[end:].lstrip().startswith(";"):
            problems.append("an asm statement must end with `;`")
        block = next((b for b in blocks if b[0] < m.start() < b[1]), None)
        words = set(re.findall(r"[A-Za-z_]\w*", block[2].split("(", 1)[0])) if block else set()
        if not block or "static" not in words or not INLINE_WORDS & words \
                or words & {"struct", "class", "union", "namespace"}:
            problems.append("inline asm may only appear inside a `static inline` helper function")
        elif block[0] in seen:
            problems.append("only one asm statement per `static inline` helper")
        if block:
            seen.add(block[0])
        template = _asm_template(code[q.end():end - 1])
        insns = [t.strip() for t in re.split(r";|\\n|\n", template.replace("\\t", " "))]
        insns = [t for t in insns if t]
        if not insns:
            problems.append("an asm statement needs an instruction template (a plain string literal)")
        if len(insns) > MAX_ASM_INSNS:
            problems.append(f"an asm statement holds {len(insns)} instructions, at most {MAX_ASM_INSNS} are "
                            "allowed (one operation, or a short sequence the hardware requires together)")
        for t in insns:
            mnem = t.split(None, 1)[0].lower()
            if t.startswith("."):
                problems.append(f"assembler directive `{t}` in inline asm: no .word/.byte/.half/.set or other directives")
            elif ":" in t or "%=" in t:
                problems.append(f"label in inline asm (`{t}`): control flow belongs in C++")
            elif BRANCH_MNEMONIC.match(mnem):
                problems.append(f"branch or jump `{mnem}` in inline asm: control flow belongs in C++")
    blanked = list(code)
    for a, b in spans:
        for k in range(a, b):
            if blanked[k] != "\n":
                blanked[k] = " "
    return list(dict.fromkeys(problems)), "".join(blanked)


def strip_comments(src):
    """Remove comments but keep strings."""
    out, i, n = [], 0, len(src)
    while i < n:
        if src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("\n" * src.count("\n", i, j))
            i = j
        elif src.startswith("//", i):
            j = src.find("\n", i)
            i = n if j < 0 else j
        elif src[i] in "\"'":
            q, j = src[i], i + 1
            while j < n and src[j] != q:
                j += 2 if src[j] == "\\" else 1
            out.append(src[i:j + 1])
            i = j + 1
        else:
            out.append(src[i])
            i += 1
    return "".join(out)


def known_functions():
    if not FUNCTIONS_CSV.exists():
        return None
    return {line.split(",", 1)[0] for line in FUNCTIONS_CSV.read_text().splitlines()[1:]}


def looks_like_address(v):
    """Inside the image, word-aligned, and not a single-bit/round flag value."""
    return IMAGE[0] <= v < IMAGE[1] and v % 4 == 0 and (v & (v - 1)) != 0 and v % 0x10000 != 0


def scan_file(path, allowed, funcs, asm_allow=None):
    problems = []
    name = path.name
    if not UNIT_NAME.match(name):
        return [f"file name must be func_XXXXXXXX.cpp (uppercase hex address), got {name}"]
    if funcs is not None and path.stem not in funcs:
        problems.append(f"{path.stem} is not a function in config/functions.us.csv")
    text = path.read_text(errors="replace")
    first = text.split("\n", 1)[0]
    cm = CFLAGS_RE.match(first)
    if cm:
        for flag in cm.group(1).split():
            if flag not in allowed:
                problems.append(f"cflag {flag} is not in toolchain/compiler.toml allowed_cflags")
    elif "cflags:" in text:
        problems.append("a /* cflags: */ comment only works on the very first line")
    code = strip_comments(text)
    rules = RULES
    if asm_allow and path.stem in asm_allow:
        asm_problems, code = check_inline_asm(code)
        problems += asm_problems
        rules = [r for r in RULES if r is not ASM_RULE]
    for rx, why in rules:
        if rx.search(code):
            problems.append(why)
    no_extern_c = code.replace('extern "C"', "")
    no_includes = re.sub(r"^\s*#\s*include\s*\"[^\"]*\"", "", no_extern_c, flags=re.M)
    if STRING_LIT.search(no_includes):
        problems.append("string literals are not allowed: declare the game's string as extern char D_XXXXXXXX[]")
    m = BARE_STMT.search(code)
    if m:
        problems.append(f"bare expression statement `{m.group(0).strip()}` (a read that does nothing): "
                        "no dead statements, even on volatile members")
    declared = {int(m.group(1), 16) for m in UNIT_CONST_RE.finditer(text)}   # gate.py verifies these
    for lit in ADDR_LIT.findall(code):
        v = int(lit, 16)
        if looks_like_address(v) and v not in declared:
            problems.append(f"hard-coded address 0x{lit}: reference the symbol (D_{v:08X}/func_{v:08X}) instead")
    return problems


def main(argv):
    files = [Path(a) for a in argv] or (sorted(SRC_FUNCS.glob("*")) + sorted(SRC_NONMATCHING.glob("*")))
    allowed = set(compiler_config()["per_file"]["allowed_cflags"])
    funcs = known_functions()
    asm_allow = inline_asm_allowlist()
    nbad = n = 0
    for f in files:
        if f.is_dir() or f.name.startswith("."):
            continue
        n += 1
        if f.suffix != ".cpp":
            print(f"PROBLEM {f.name}: only func_XXXXXXXX.cpp files belong in src/funcs")
            nbad += 1
            continue
        for p in scan_file(f, allowed, funcs, asm_allow):
            print(f"PROBLEM {f.name}: {p}")
            nbad += 1
    print(f"scan: {n} files, {nbad} problems")
    return 1 if nbad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
