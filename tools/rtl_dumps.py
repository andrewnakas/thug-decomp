#!/usr/bin/env python3
"""Shared helpers for the explainers (sched_explain.py, regalloc_explain.py).

Compiles one unit with cc1plus's RTL dumps, parses those dumps, and maps every word of the
compiled function back to the RTL insn (INSN_UID) it came from.

    rtl_dumps.compile_with_dumps(name, src, dump_flags, keep=None) -> Dumps

Written from the published behaviour of gcc 2.95 (haifa-sched.c, local-alloc.c, global.c,
print-rtl.c, final.c -dp output); no code from any other project.

Dump flags this cc1plus (SN ee-gcc 2.95.3 build 1.36) accepts, checked by hand:
  -dN (.regmove)  -dS (.sched)  -dl (.lreg)  -dg (.greg)  -dR (.sched2)  -dp (asm comments with
  "# UID pattern [length = N]")  -fsched-verbose-N (N=0..5; `-fsched-verbose=N` is rejected).
None of them changes the generated code (the explainers check this against match.py's object).
"""
import os
import re
import shutil
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
from common import ROOT, SRC_NONMATCHING, compiler_config, file_cflags, unit_path  # noqa: E402

GPR_NAMES = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
             "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
NAME_TO_HARD = {f"${n}": i for i, n in enumerate(GPR_NAMES)}
NAME_TO_HARD.update({f"$f{i}": 32 + i for i in range(32)})
NAME_TO_HARD["$s8"] = 30
# MIPS EABI as SN's EE port uses it: callee-saved GPRs $s0-$s7, $fp; callee-saved FPRs $f20-$f31
# (the game's prologues save $f20+). Everything else allocatable is clobbered by a call.
CALL_SAVED = set(range(16, 24)) | {30} | set(range(32 + 20, 32 + 32))
FIXED = {0, 26, 27, 28, 29}


def hard_name(r):
    if r is None:
        return "mem"
    if 0 <= r < 32:
        return "$" + GPR_NAMES[r]
    if 32 <= r < 64:
        return f"$f{r - 32}"
    return f"hard{r}"


def find_source(name, src=None):
    if src:
        return Path(src)
    p = unit_path(name)
    if p.exists():
        return p
    for ext in (".cpp", ".c"):
        q = SRC_NONMATCHING / f"{name}{ext}"
        if q.exists():
            return q
    sys.exit(f"{name}: no unit in src/funcs or src/nonmatching (use --src)")


# ---------------------------------------------------------------- compiling

@dataclass
class Dumps:
    name: str
    src: Path
    workdir: Path
    asm: str                       # compiler output with -dp comments
    files: dict                    # suffix ("sched", "sched2", "lreg", ...) -> text
    word_uid: list = None          # word index of the function -> INSN_UID (or None)
    words: list = None             # our words (from the labelled object)
    map_note: str = ""             # why word_uid is missing/partial


def _rel(p, base):
    return os.path.relpath(p, base)


def compile_with_dumps(name, src, dump_flags, keep=None, map_words=True):
    """Compile `src` exactly as cc.py does (pinned cflags + the unit's own) plus dump flags.

    Runs in a private directory under build/ (or `keep`), because cc1plus writes its dumps
    next to the working directory."""
    cfg = compiler_config()
    src = Path(src).resolve()
    if keep:
        wd = Path(keep).resolve()
        wd.mkdir(parents=True, exist_ok=True)
        tmp = None
    else:
        (ROOT / "build").mkdir(exist_ok=True)
        tmp = tempfile.TemporaryDirectory(prefix="explain_", dir=ROOT / "build")
        wd = Path(tmp.name)
    try:
        for old in wd.glob("u.*"):
            old.unlink()
        shutil.copyfile(src, wd / ("u" + src.suffix))
        cdir, spec = cc.compiler_dir(cfg)
        cpp = []
        for f in cfg["compiler"]["cppflags"]:
            cpp.append("-I" + _rel(ROOT / f[2:], wd) if f.startswith("-I") else f)
        flags = list(cfg["compiler"]["cflags"]) + file_cflags(src) + list(dump_flags) + ["-dp"]
        argv = [cc.wibo(), str(cdir / spec["driver"]), "-S", *flags, *cpp, "u" + src.suffix, "-o", "u.s"]
        cc.run("ee-gcc -S (dumps)", argv, cwd=wd)
        asm = (wd / "u.s").read_text(errors="replace")
        files = {}
        for f in wd.iterdir():
            m = re.match(r"^u\.(?:cc|c|cpp|ii|i)\.(\w+)$", f.name) or re.match(r"^u\.(\w+)$", f.name)
            if m and m.group(1) not in ("s", "cpp", "c", "o", "ls"):
                files[m.group(1)] = f.read_text(errors="replace")
        d = Dumps(name, src, wd, asm, files)
        if map_words:
            try:
                _map_words(d, cfg)
            except (cc.StageError, ValueError, OSError) as e:
                d.map_note = f"word->insn map unavailable: {e}"
        return d
    finally:
        if tmp is not None and not keep:
            tmp.cleanup()


DP_RE = re.compile(r"#\s+(\d+)\s+(\S+)\s+\[length = \d+\]\s*$")
DP_STRIP = re.compile(r"\s+#\s+\d+\s+\S+\s+\[length = \d+\]\s*$")


def same_code(a, b):
    """Two word lists equal up to relocated immediates (literal/jump-table retargeting only moves those)."""
    if len(a) != len(b):
        return False
    for x, y in zip(a, b):
        if x == y:
            continue
        op = x >> 26
        if op != y >> 26 or op == 0:
            return False
        if op in (2, 3):                       # j/jal: target field relocated
            continue
        if (x & 0xFFFF0000) != (y & 0xFFFF0000):
            return False
    return True


def _map_words(d, cfg):
    """Word index -> INSN_UID: put a label after every -dp-annotated line, assemble with SN's own as,
    and read the label offsets back. The labelled object must have the same words as the plain one."""
    from elftools.elf.elffile import ELFFile
    out, plain, uids = [], [], []
    for line in d.asm.splitlines():
        m = DP_RE.search(line)
        bare = DP_STRIP.sub("", line) if m else line
        out.append(bare)
        plain.append(bare)
        if m:
            k = len(uids)
            uids.append(int(m.group(1)))
            out.append(f"__xu_{k}:")
    # float literals exactly as cc.py does it (the -dp comments are gone, so its li.s pattern matches)
    labelled = cc.retarget_literals(("\n".join(out) + "\n").encode(), d.name).decode(errors="replace")
    text = cc.retarget_literals(("\n".join(plain) + "\n").encode(), d.name).decode(errors="replace")
    wd = d.workdir

    def assemble(body, stem):
        (wd / f"{stem}.s").write_text(body)
        cdir, spec = cc.compiler_dir(cfg)
        flags = [f for f in cfg["compiler"]["cflags"]] + file_cflags(d.src)
        cc.run("ee-gcc -c (map)", [cc.wibo(), str(cdir / spec["driver"]), "-c", *flags, f"{stem}.s",
                                   "-o", f"{stem}.o"], cwd=wd)
        with open(wd / f"{stem}.o", "rb") as fh:
            elf = ELFFile(fh)
            textsec = elf.get_section_by_name(".text")
            data = textsec.data()
            sym = elf.get_section_by_name(".symtab")
            labels, fstart, fsize = {}, None, None
            tidx = next(i for i, s in enumerate(elf.iter_sections()) if s.name == ".text")
            for s in sym.iter_symbols():
                if s["st_shndx"] != tidx:
                    continue
                if s.name.startswith("__xu_"):
                    labels[int(s.name[5:])] = s["st_value"]
                elif s["st_info"]["type"] == "STT_FUNC":
                    fstart, fsize = s["st_value"], s["st_size"]
            if fstart is None:
                raise ValueError("no function symbol in the object")
            fsize = fsize or len(data) - fstart
            words = [int.from_bytes(data[i:i + 4], "little") for i in range(fstart, fstart + fsize - 3, 4)]
            return words, labels, fstart

    plain, _, _ = assemble(text if text.endswith("\n") else text + "\n", "plain")
    words, labels, fstart = assemble(labelled, "lab")
    if words != plain:
        raise ValueError("labels changed the code (as reordered across them)")
    word_uid = [None] * len(words)
    prev = 0
    for k, uid in enumerate(uids):
        end = labels.get(k)
        if end is None:
            continue
        end = (end - fstart) // 4
        for w in range(max(prev, 0), min(end, len(words))):
            word_uid[w] = uid
        prev = max(prev, end)
    d.word_uid, d.words = word_uid, words


# ---------------------------------------------------------------- RTL parsing

TOK_RE = re.compile(r'"(?:[^"\\]|\\.)*"|[()\[\]]|[^\s()\[\]"]+')


def parse_sexprs(text):
    """All top-level RTL expressions in a dump (lines starting with ';;' are skipped)."""
    body = "\n".join(l for l in text.splitlines() if not l.lstrip().startswith(";;"))
    stack, out = [[]], []
    for t in TOK_RE.findall(body):
        if t in "([":
            stack.append([])
        elif t in ")]":
            if len(stack) == 1:
                continue
            e = stack.pop()
            stack[-1].append(e)
            if len(stack) == 1:
                out.append(stack[0].pop())
        else:
            stack[-1].append(t)
    return out


@dataclass
class Insn:
    kind: str
    uid: int
    pattern: list
    code: int
    links: list = field(default_factory=list)   # [(uid, kind)] kind '' = data, 'ANTI', 'OUTPUT'
    notes: list = field(default_factory=list)   # [(kind, expr)]
    prev: int = None
    next: int = None


def _int(s):
    try:
        return int(s)
    except (TypeError, ValueError):
        return None


def _chain(e, head):
    """Flatten an (insn_list / expr_list ...) chain into [(note kind, item)]."""
    out = []
    while isinstance(e, list) and e and isinstance(e[0], str) and e[0].startswith(head):
        kind = e[0].split(":", 1)[1] if ":" in e[0] else ""
        out.append((kind, e[1] if len(e) > 1 else None))
        e = e[2] if len(e) > 2 else None
    return out


def parse_insns(text):
    """{uid: Insn} for every insn/jump_insn/call_insn in a dump (the last function only)."""
    insns = {}
    for e in parse_sexprs(text):
        if not e or head(e) not in ("insn", "jump_insn", "call_insn"):
            continue
        uid = _int(e[1])
        if uid is None or len(e) < 5:
            continue
        pat = e[4]
        rest = e[5:]
        code = _int(rest[0]) if rest and isinstance(rest[0], str) else None
        rest = [x for x in rest[1:] if not (isinstance(x, str) and x.startswith("{"))]
        links = [(_int(u), k.replace("REG_DEP_", "")) for k, u in _chain(rest[0], "insn_list")] if rest else []
        notes = []
        if len(rest) > 1:
            notes = _chain(rest[1], ("expr_list", "insn_list"))
        insns[uid] = Insn(e[0], uid, pat, code if code is not None else -1, links, notes,
                          _int(e[2]), _int(e[3]))
    return insns


def reg_of(e):
    """(regno, is_hard) if e is (reg ...) else None."""
    if isinstance(e, list) and e and isinstance(e[0], str) and (e[0] == "reg" or e[0].startswith("reg:")
                                                                  or e[0].startswith("reg/")):
        n = _int(e[1]) if len(e) > 1 else None
        if n is None:
            return None
        return n, len(e) > 2
    return None


def regs_in(e, out=None):
    """All (regno, is_hard) mentioned anywhere in an expression."""
    if out is None:
        out = []
    r = reg_of(e)
    if r:
        out.append(r)
        return out
    if isinstance(e, list):
        for x in e:
            regs_in(x, out)
    return out


def head(e):
    if isinstance(e, list) and e and isinstance(e[0], str):
        return e[0].split(":")[0].split("/")[0]
    return None


def split_functions(text):
    """A dump holds one section per function (';; Function NAME'); return [(name, text)]."""
    parts = re.split(r"^;; Function (.*)$", text, flags=re.M)
    if len(parts) == 1:
        return [("", text)]
    return [(parts[i].strip(), parts[i + 1]) for i in range(1, len(parts), 2)]


def pick_function(text, want=None):
    """The section of a dump for the compared function (the last one when only one is defined)."""
    fs = split_functions(text)
    if want:
        for n, t in fs:
            if want in n:
                return t
    return fs[-1][1]
