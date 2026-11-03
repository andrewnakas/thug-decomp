#!/usr/bin/env python3
"""Compile one function and compare it with the original, instruction by instruction.

    python tools/match.py func_00112345            # MATCH / N words differ
    python tools/match.py func_00112345 --show     # side-by-side diff, !! on differences
    python tools/match.py func_00112345 --src draft.cpp   # try a file outside src/funcs
    python tools/match.py func_00112345 --compiler ee-gcc2.95.2-274 --cflags "-O2 -G8"

A unit defines exactly one function in .text, under any (mangled C++) name: that
function is the one compared. Relocations are not masked away: every relocated
field is resolved to the original address it points at and those addresses must
be equal. A jump to the wrong label or a load from the wrong global is a
mismatch (thps64 once masked local jumps and merged a non-match; never again).

The one exception is a compiler-emitted float literal (.lit4/.rodata local
constant): it matches when the 4 bytes it points at equal the bytes the original
instruction loaded. tools/cc.py then retargets it to that original constant
(see LITERALS in cc.py), so the linked image is still byte-identical.

Library use: compare(name, src=None, compiler=None, cflags=None) -> Result
"""
import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
from common import (ASM, BUILD, CONFIG, EXE, FILE_OFF, ROOT, SEG_END, VRAM,  # noqa: E402
                    compiler_config, load_functions, unit_path)

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16, R_MIPS_PC16 = 2, 4, 5, 6, 7, 10
R_MIPS_LITERAL = 8
RTYPE = {2: "32", 4: "26", 5: "hi", 6: "lo", 7: "gprel", 8: "literal", 10: "pc16"}
GP_TYPES = (R_MIPS_GPREL16, R_MIPS_LITERAL)  # SN as uses LITERAL for .lit4 loads
NAMED_ADDR = re.compile(r"^(?:\.L|[A-Za-z]+_)([0-9A-F]{8})$")
LABEL_DEF = re.compile(r"^\s*(?:glabel|dlabel|jlabel|alabel|ehlabel)\s+(\S+)")
OFF_ADDR = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s")
SYMFILE = re.compile(r"^\s*\"?([^\s\"]+)\"?\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
LITERAL_SECTIONS = (".lit4", ".lit8", ".rodata", ".rdata", ".sdata")

_symbols = None
_image = None


def image():
    """The original main segment bytes (from your disc's ELF)."""
    global _image
    if _image is None:
        _image = EXE.read_bytes()[FILE_OFF:SEG_END]
    return _image


def read_orig(addr, n):
    off = addr - VRAM
    if 0 <= off and off + n <= len(image()):
        return image()[off:off + n]
    return None


def symbols():
    """name -> original address, from config symbol files and every asm label."""
    global _symbols
    if _symbols is not None:
        return _symbols
    syms = {}
    for f in CONFIG.glob("*.txt"):
        for line in f.read_text().splitlines():
            m = SYMFILE.match(line)
            if m:
                syms[m.group(1)] = int(m.group(2), 16)
    for alias in sorted((ROOT / "include" / "game").glob("cxx_symbols*.txt")):  # contributors' C++ names
        for line in alias.read_text().splitlines():
            m = SYMFILE.match(line)
            if m:
                syms.setdefault(m.group(1), int(m.group(2), 16))
    _symbols = syms
    return syms


_labels = None


def real_labels():
    """Every label the asm actually defines (the linker only knows these)."""
    global _labels
    if _labels is None:
        _labels = set()
        for f in ASM.rglob("*.s"):
            _labels.update(re.findall(r"^\s*(?:glabel|dlabel|jlabel|alabel)\s+(\S+)", f.read_text(), re.M))
    return _labels


EXTRA_SYMS = {}   # from a .sym file next to --src (contributor experiments; the gate never uses it)


def sym_addr(name):
    a = EXTRA_SYMS.get(name, symbols().get(name))
    if a is None:
        m = NAMED_ADDR.match(name)
        if m and name in real_labels():
            a = int(m.group(1), 16)
        elif m and not name.startswith(".L"):
            UNKNOWN.add(name)   # e.g. D_00393FA2 inside an object: the linker has no such symbol
    return a


UNKNOWN = set()


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


@dataclass
class Obj:
    words: list
    relocs: dict          # word index -> (type, resolved target or None, symbol, literal bytes or None)
    size: int
    func: str = ""
    defined: list = field(default_factory=list)   # global function symbols in .text
    sections: dict = field(default_factory=dict)  # name -> size


def read_obj(path, func_addr, func_name=None):
    """Read the one function in `path` (or `func_name` if given)."""
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        text = elf.get_section_by_name(".text")
        symtab = elf.get_section_by_name(".symtab")
        sections = {s.name: s.data_size for s in elf.iter_sections() if s.name.startswith(".")}
        funcs = []
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS"):
                if elf.get_section(s["st_shndx"]).name == ".text":
                    funcs.append(s)
        if func_name:
            pick = [s for s in funcs if s.name == func_name]
        else:
            pick = funcs
        if len(pick) != 1:
            names = ", ".join(s.name for s in funcs) or "none"
            raise ValueError(f"{path}: a unit must define exactly one function in .text (found: {names})")
        sym0 = pick[0]
        start, size = sym0["st_value"], sym0["st_size"]
        if not size:
            size = text.data_size - start
        data = text.data()[start:start + size]
        words = [int.from_bytes(data[i:i + 4], "little") for i in range(0, len(data) - 3, 4)]

        relocs = {}
        rel = elf.get_section_by_name(".rel.text")
        last_hi = {}
        if isinstance(rel, RelocationSection):
            entries = sorted(rel.iter_relocations(), key=lambda r: r["r_offset"])
            for r in entries:
                off = r["r_offset"] - start
                if off < 0 or off >= size:
                    continue
                i = off // 4
                t = r["r_info_type"]
                sym = symtab.get_symbol(r["r_info_sym"])
                literal_sec = None
                if sym["st_info"]["type"] == "STT_SECTION":
                    sec = elf.get_section(sym["st_shndx"])
                    name = sec.name
                    base = func_addr - start if name == ".text" else None
                    if name in LITERAL_SECTIONS:
                        literal_sec = sec
                else:
                    name = sym.name
                    if sym["st_shndx"] == "SHN_UNDEF":
                        base = sym_addr(name)
                    else:
                        sec = elf.get_section(sym["st_shndx"])
                        if sec.name == ".text":
                            base = func_addr - start + sym["st_value"]
                        elif sec.name in LITERAL_SECTIONS and name.startswith("$"):
                            literal_sec, base = sec, None
                        else:
                            base = sym_addr(name)
                w = words[i]
                if t == R_MIPS_26:
                    addend = (w & 0x3FFFFFF) << 2
                    if sym["st_info"]["type"] != "STT_SECTION" and sym["st_shndx"] == "SHN_UNDEF":
                        addend = 0 if (w & 0x3FFFFFF) == 0 else addend
                elif t == R_MIPS_HI16:
                    lo = next((x for x in entries if x["r_offset"] > r["r_offset"]
                               and x["r_info_type"] == R_MIPS_LO16
                               and x["r_info_sym"] == r["r_info_sym"]), None)
                    lo_v = sext16(int.from_bytes(text.data()[lo["r_offset"]:lo["r_offset"] + 2], "little")) if lo else 0
                    addend = ((w & 0xFFFF) << 16) + lo_v
                    last_hi[r["r_info_sym"]] = w & 0xFFFF
                elif t == R_MIPS_LO16:
                    addend = (last_hi.get(r["r_info_sym"], 0) << 16) + sext16(w & 0xFFFF)
                elif t == R_MIPS_PC16:
                    addend = 0
                else:
                    addend = sext16(w & 0xFFFF)
                lit = None
                if literal_sec is not None:
                    off_in = addend + (0 if sym["st_info"]["type"] == "STT_SECTION" else sym["st_value"])
                    lit = literal_sec.data()[off_in:off_in + 4]
                    target = None
                else:
                    target = base + addend if base is not None else None
                relocs[i] = (t, target, name, lit)
        return Obj(words, relocs, size, sym0.name, [s.name for s in funcs], sections)


def mask(t, w):
    return w & {R_MIPS_26: 0xFC000000}.get(t, 0xFFFF0000)


def branch_target(w, addr):
    return addr + 4 + sext16(w & 0xFFFF) * 4


@dataclass
class Result:
    name: str
    ok: bool
    diffs: list
    target: Obj = None
    ours: Obj = None
    error: str = ""


def func_row(name):
    for f in load_functions():
        if f["name"] == name:
            return f
    raise KeyError(f"{name} is not in config/functions.us.csv")


def reloc_equal(tr, orr, here, tw, ow):
    """Do two relocated fields point at the same original thing?"""
    mt = mask(tr[0], tw) if tr else tw & 0xFFFF0000
    mo = mask(orr[0], ow) if orr else ow & 0xFFFF0000
    if mt != mo:
        return False
    tt = R_MIPS_GPREL16 if tr and tr[0] in GP_TYPES else (tr[0] if tr else None)
    ot = R_MIPS_GPREL16 if orr and orr[0] in GP_TYPES else (orr[0] if orr else None)
    if tr and orr and tt == ot:
        if tr[1] is not None and tr[1] == orr[1]:
            return True
        if orr[3] is not None and tr[1] is not None:   # our literal vs the original constant
            return read_orig(tr[1], len(orr[3])) == orr[3]
        return False
    if tr and not orr and tr[0] == R_MIPS_PC16:
        return tr[1] is not None and tr[1] == branch_target(ow, here)
    if orr and not tr and orr[0] == R_MIPS_PC16:
        return orr[1] is not None and orr[1] == branch_target(tw, here)
    return False


def compare(name, src=None, compiler=None, cflags=None, outdir=None):
    row = func_row(name)
    if src:
        side = Path(src).with_suffix(".sym")
        if side.exists():
            for line in side.read_text().splitlines():
                m = SYMFILE.match(line)
                if m:
                    EXTRA_SYMS[m.group(1)] = int(m.group(2), 16)
    addr = row["addr"]
    src = Path(src) if src else unit_path(name)
    outdir = Path(outdir) if outdir else BUILD / "match"
    cfg = compiler_config()
    ours_o = outdir / f"{name}.o"
    target_o = outdir / "target" / f"{name}.o"
    try:
        cc.assemble_gnu(cc.asm_wrapper(ROOT / row["asm"]), target_o, cfg)
        cc.compile_obj(src, ours_o, cfg, compiler, cflags, func=name)
    except cc.StageError as e:
        return Result(name, False, [], error=str(e))
    try:
        t = read_obj(target_o, addr, name)
        o = read_obj(ours_o, addr)
    except ValueError as e:
        return Result(name, False, [], error=str(e))
    diffs = []
    for i in range(max(len(t.words), len(o.words))):
        tw = t.words[i] if i < len(t.words) else None
        ow = o.words[i] if i < len(o.words) else None
        tr, orr = t.relocs.get(i), o.relocs.get(i)
        if tw is None or ow is None:
            diffs.append(i)
        elif tr or orr:
            if not reloc_equal(tr, orr, addr + i * 4, tw, ow):
                diffs.append(i)
        elif tw != ow:
            diffs.append(i)
    return Result(name, not diffs, diffs, t, o)


def disasm(word, addr, reloc):
    from rabbitizer import Instruction, InstrCategory
    s = Instruction(word, vram=addr, category=InstrCategory.R5900).disassemble()
    if reloc:
        t, target, sym, lit = reloc
        tgt = f"0x{target:08X}" if target is not None else (f"lit {lit.hex()}" if lit else "?")
        s = f"{s:<34} [{RTYPE.get(t, t)} {sym if not sym.startswith('.') else ''} -> {tgt}]"
    return s


def show(res, addr):
    t, o = res.target, res.ours
    print(f"{'game':<62} | yours ({o.func})")
    for i in range(max(len(t.words), len(o.words))):
        a = addr + i * 4
        l = disasm(t.words[i], a, t.relocs.get(i)) if i < len(t.words) else ""
        r = disasm(o.words[i], a, o.relocs.get(i)) if i < len(o.words) else ""
        mark = "!!" if i in res.diffs else "  "
        print(f"{mark} {a:08X} {l:<50} | {r}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--show", action="store_true")
    ap.add_argument("--compiler", help="experiment: another compilers.* entry")
    ap.add_argument("--cflags", help="experiment: replace the pinned cflags")
    ap.add_argument("--outdir", help="where to write objects (default build/match); use one per parallel run")
    a = ap.parse_args()
    import shlex
    res = compare(a.name, a.src, a.compiler, shlex.split(a.cflags) if a.cflags else None, a.outdir)
    if res.error:
        print(f"{a.name}: ERROR {res.error}")
        sys.exit(2)
    if UNKNOWN:
        print(f"{a.name}: unknown symbol(s) {', '.join(sorted(UNKNOWN))}: not a label in the asm (a name inside a "
              "data object?). Index from the object's real label instead; the link would fail.")
    if a.show:
        show(res, func_row(a.name)["addr"])
    extra = [f"{k} ({v} bytes)" for k, v in res.ours.sections.items()
             if v and (k in (".data", ".sdata", ".bss", ".sbss", ".rodata", ".rdata", ".lit4", ".lit8")
                       or k.startswith(".gnu.linkonce"))]
    if extra:
        print(f"{a.name}: WARNING the unit emits {', '.join(extra)}: gate.py will reject it "
              "(keep vtables/strings/tables in the asm; see MATCHING_GUIDE key-function notes)")
    if res.ok:
        print(f"{a.name}: MATCH")
    else:
        print(f"{a.name}: {len(res.diffs)} of {len(res.target.words)} words differ"
              + ("" if len(res.target.words) == len(res.ours.words)
                 else f" (size {len(res.ours.words) * 4:#x}, want {len(res.target.words) * 4:#x})"))
        sys.exit(1)


if __name__ == "__main__":
    main()
