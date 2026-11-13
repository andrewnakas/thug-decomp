#!/usr/bin/env python3
"""Map every word of a compiled unit back to the C++ source line that produced it.

Shared by diffmap.py and shapedb.py.

    srcmap.compile_lines(src, func=None, workdir=None) -> LineMap

How: cc1plus (SN ee-gcc 2.95.3 build 1.36) is run exactly as tools/cc.py runs it (pinned cflags + the unit's
own /* cflags: */) plus `-g`. With -g it emits stabs: before the instructions of each source line it writes

    $LM12:
        .stabn 68,0,<line>,$LM12          (N_SLINE)

and `.stabs "<file>",132,...` (N_SOL) when the line notes switch file (an inline from a header). We put a
plain label `__ln_K:` next to every `$LMn:` label, assemble with SN's own as (through the ee-gcc driver), and
read the label offsets back: every word from label K up to the next one belongs to line K.

-g does not change the code with this compiler (checked on every matched unit by shapedb.py build: the words
equal the game's, see `verified`); the line notes only add labels, which SN as already respects. If the
words ever differ from the plain compile, `LineMap.same` is False and the caller should say so.

Line numbers of inlined code are those of the inline function's body (gcc 2.95 records no call site). We
also give each word the last line seen inside the function's own body (`via`), so an inlined helper's code
can be attributed to the statement that called it.

Written from the documented stabs format and gcc's -g output; no code from any other project.
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
from common import ROOT, compiler_config, file_cflags  # noqa: E402

LM_LABEL = re.compile(r"^(\$LM\d+):\s*$")
SLINE = re.compile(r"^\s*\.stabn\s+68,\s*0,\s*(\d+),\s*(\$LM\d+)")
SOL = re.compile(r'^\s*\.stabs\s+"([^"]*)",\s*132,')
FUN = re.compile(r'^\s*\.stabs\s+"[^"]*:F[^"]*",\s*36,\s*0,\s*(\d+),')


@dataclass
class LineMap:
    src: Path
    words: list                     # our words (labelled object; equal to the plain compile when same=True)
    lines: list                     # per word: (file, line) or None (before the first line note)
    via: list                       # per word: the last line inside the function body seen so far (or None)
    fun_line: int = 0               # line of the function's definition
    body: tuple = (0, 0)            # (first, last) line of the function body in the unit file
    same: bool = True               # labelled object == plain compile
    unit_file: str = ""             # the name cc1plus used for the unit itself
    relocs: dict = field(default_factory=dict)   # word -> reloc type (from the labelled object)
    reloc_syms: dict = field(default_factory=dict)  # word -> symbol name
    asm: str = ""

    def line_of(self, i):
        """(file, line) of word i, or None."""
        return self.lines[i] if 0 <= i < len(self.lines) else None

    def is_unit(self, fl):
        return fl is not None and fl[0] == self.unit_file


def body_range(src_text, fun_line):
    """(first, last) line of the function that starts at fun_line (brace matching; units have no strings)."""
    lines = src_text.splitlines()
    depth, opened = 0, False
    i = max(fun_line - 1, 0)
    # the definition may start a few lines above the line gcc records (return type on its own line)
    while i < len(lines):
        s = re.sub(r"//.*$", "", lines[i])
        s = re.sub(r"/\*.*?\*/", "", s)
        for ch in s:
            if ch == "{":
                depth += 1
                opened = True
            elif ch == "}":
                depth -= 1
                if opened and depth == 0:
                    return fun_line, i + 1
        i += 1
    return fun_line, len(lines)


def _assemble(wd, body, stem, flags):
    from elftools.elf.elffile import ELFFile
    cfg = compiler_config()
    cdir, spec = cc.compiler_dir(cfg)
    (wd / f"{stem}.s").write_text(body)
    cc.run("ee-gcc -c (lines)", [cc.wibo(), str(cdir / spec["driver"]), "-c", *flags, f"{stem}.s", "-o",
                                 f"{stem}.o"], cwd=wd)
    with open(wd / f"{stem}.o", "rb") as fh:
        elf = ELFFile(fh)
        tidx = next(i for i, s in enumerate(elf.iter_sections()) if s.name == ".text")
        data = elf.get_section(tidx).data()
        labels, fstart, fsize = {}, None, None
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if s["st_shndx"] != tidx:
                continue
            if s.name.startswith("__ln_"):
                labels[int(s.name[5:])] = s["st_value"]
            elif s["st_info"]["type"] == "STT_FUNC":
                if fstart is not None:
                    raise ValueError("more than one function in .text")
                fstart, fsize = s["st_value"], s["st_size"]
        if fstart is None:
            raise ValueError("no function symbol in the object")
        fsize = fsize or len(data) - fstart
        words = [int.from_bytes(data[i:i + 4], "little") for i in range(fstart, fstart + fsize - 3, 4)]
        relocs, syms = {}, {}
        rel = elf.get_section_by_name(".rel.text")
        if rel is not None:
            symtab = elf.get_section_by_name(".symtab")
            for r in rel.iter_relocations():
                off = r["r_offset"] - fstart
                if 0 <= off < fsize:
                    relocs[off // 4] = r["r_info_type"]
                    sym = symtab.get_symbol(r["r_info_sym"])
                    nm = sym.name
                    if sym["st_info"]["type"] == "STT_SECTION":
                        nm = elf.get_section(sym["st_shndx"]).name
                    syms[off // 4] = nm
    return words, labels, fstart, relocs, syms


def compile_lines(src, func=None, workdir=None, cflags=None, check=True):
    """Compile `src` with -g and map each word of its one function to a source line.
    check=False skips the second assembly that proves the labels did not change the code."""
    cfg = compiler_config()
    src = Path(src).resolve()
    func = func or src.stem
    tmp = None
    if workdir:
        wd = Path(workdir).resolve()
        wd.mkdir(parents=True, exist_ok=True)
    else:
        (ROOT / "build").mkdir(exist_ok=True)
        tmp = tempfile.TemporaryDirectory(prefix="srcmap_", dir=ROOT / "build")
        wd = Path(tmp.name)
    try:
        unit = "u" + src.suffix
        shutil.copyfile(src, wd / unit)
        cdir, spec = cc.compiler_dir(cfg)
        cpp = []
        for f in cfg["compiler"]["cppflags"]:
            cpp.append("-I" + os.path.relpath(ROOT / f[2:], wd) if f.startswith("-I") else f)
        base = list(cflags if cflags is not None else cfg["compiler"]["cflags"]) + file_cflags(src)
        cc.run("ee-gcc -S -g", [cc.wibo(), str(cdir / spec["driver"]), "-S", *base, "-g", *cpp, unit, "-o",
                                "g.s"], cwd=wd)
        asm = (wd / "g.s").read_text(errors="replace")
        out, plain, marks = [], [], []
        cur_file = unit
        pending = {}                  # $LMn -> index into marks (the .stabn follows the label)
        fun_line = 0
        for line in asm.splitlines():
            m = SOL.match(line)
            if m:
                cur_file = m.group(1)
            m = FUN.match(line)
            if m and not fun_line:
                fun_line = int(m.group(1))
            m = LM_LABEL.match(line)
            if m:
                k = len(marks)
                marks.append([cur_file, None])
                pending[m.group(1)] = k
                out.append(line)
                out.append(f"__ln_{k}:")
                plain.append(line)
                continue
            m = SLINE.match(line)
            if m and m.group(2) in pending:
                marks[pending[m.group(2)]][1] = int(m.group(1))
            out.append(line)
            plain.append(line)
        lab = cc.retarget_literals(("\n".join(out) + "\n").encode(), func).decode(errors="replace")
        pl = cc.retarget_literals(("\n".join(plain) + "\n").encode(), func).decode(errors="replace")
        aflags = list(cflags if cflags is not None else cfg["compiler"]["cflags"]) + file_cflags(src)
        words, labels, fstart, relocs, syms = _assemble(wd, lab, "lab", aflags)
        same = True
        if check:
            pwords, _, _, _, _ = _assemble(wd, pl, "plain", aflags)
            same = pwords == words
        n = len(words)
        lines = [None] * n
        order = sorted(labels, key=lambda k: (labels[k], k))
        # several labels at one offset: the last one wins (the earlier line produced no code there)
        for idx, k in enumerate(order):
            s = (labels[k] - fstart) // 4
            e = n
            for k2 in order[idx + 1:]:
                s2 = (labels[k2] - fstart) // 4
                if s2 > s:
                    e = s2
                    break
            else:
                e = n
            if marks[k][1] is None:
                continue
            for w in range(max(s, 0), min(e, n)):
                lines[w] = (marks[k][0], marks[k][1])
        # words before the first line note (prologue) belong to the definition line
        for w in range(n):
            if lines[w] is not None:
                break
            lines[w] = (unit, fun_line)
        text = src.read_text(errors="replace")
        body = body_range(text, fun_line) if fun_line else (0, 0)
        via, last = [], None
        for fl in lines:
            if fl and fl[0] == unit and body[0] <= fl[1] <= body[1]:
                last = fl[1]
            via.append(last)
        return LineMap(src, words, lines, via, fun_line, body, same, unit, relocs, syms, asm)
    finally:
        if tmp is not None:
            tmp.cleanup()


def main():
    import argparse
    ap = argparse.ArgumentParser(description="print each word of a unit with its source line")
    ap.add_argument("src")
    ap.add_argument("--func")
    a = ap.parse_args()
    lm = compile_lines(a.src, a.func)
    from rabbitizer import Instruction, InstrCategory
    src_lines = Path(a.src).read_text(errors="replace").splitlines()
    for i, w in enumerate(lm.words):
        fl = lm.lines[i]
        txt = Instruction(w, vram=i * 4, category=InstrCategory.R5900).disassemble()
        where = f"{fl[1]:5d}" if fl else "    ?"
        s = src_lines[fl[1] - 1].strip() if fl and lm.is_unit(fl) and 0 < fl[1] <= len(src_lines) else ""
        print(f"{i * 4:05X} {txt:<40} {where}  {s[:60]}")
    if not lm.same:
        print("WARNING: the -g labelled object differs from the plain compile", file=sys.stderr)


if __name__ == "__main__":
    main()
