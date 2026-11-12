#!/usr/bin/env python3
"""Build a second, NON-matching "functional" executable: every function we have C++ for runs our C++.

    python tools/build_functional.py                       # build/functional/SLUS_207.31 + report
    python tools/build_functional.py --only func_00101D60,0x00103000
    python tools/build_functional.py --exclude @work/bad.txt
    python tools/build_functional.py --no-ninja            # trust the current matching build

Why: src/funcs units are already linked byte-for-byte into the matching build, but the 450-odd
src/nonmatching units ("equivalent, does not match yet") are never linked. This build runs them, so
booting it in an emulator tests that they really are equivalent. The matching build is not touched.

How (all derived from the matching build, which must be OK):
  1. The matching ELF (build/SLUS_207.31) is the base: every address stays the same.
  2. Each src/nonmatching unit is compiled with the pinned compiler. Float literals the compiler would put
     in its own gp-relative .lit4 are pointed at an identical constant in the game's .lit4 (else built
     inline with lui/ori/mtc1); switch jump tables stay the unit's own (.rodata, absolute %hi/%lo).
  3. References resolve against the matching build's symbols (build/main.elf), the units' /* sym: */
     lines and the func_/D_/jtbl_ naming convention. A unit's own global symbols are made local, so the
     rest of the game keeps calling the original address.
  4. Placement (class Plan): a replaced function's original bytes are dead, so they are the free RAM.
     A unit whose code fits in its own slot goes there (no trampoline). Otherwise the slot's first two
     words become `j <C++ copy>; nop` (so jal callers, vtables and function pointers in data all reach
     the C++) and the rest of the slot is a hole; the other units' code and jump tables are packed into
     those holes best-fit.
  5. Whatever still does not fit goes to an overflow segment at SEG_ADDR (0x00479000), a third PT_LOAD
     appended to the file. Free RAM for it: the game's memory manager (func_0010A420, the Mem manager
     constructor) builds its one big region from (0x00478C3F & ~0xF) = 0x00478C30 (end of .bss 0x00468C30
     + the 64 KB libc heap crt0 passes to SetupHeap) up to 0x01FEFFF0 (the 64 KB main-thread stack crt0
     sets up at 0x01FF0000). Every other byte of the 32 MB is the ELF, that libc heap or the stack, so
     the region start is moved up past the overflow by patching that one lui/addiu pair (0x0010A478 /
     0x0010A484). The game needs nearly all of that heap: with every unit in the overflow segment (heap
     -450 KB, `--no-holes`) loading the first level runs out of memory and crashes, even when the
     segment holds the original asm (`--use-asm`), so the holes come first.

Code elsewhere that branches into the MIDDLE of a replaced function would land in foreign code: such
entries are found by scanning the asm; a unit entered at +4 is skipped, and one entered further in keeps
its original bytes (no hole is made of it). Both are listed in the report.

Debug aids for bisecting a crash: --only / --exclude (lists or @file), --use-asm (relocate the game's own
asm instead of the C++: separates "the C++ is wrong" from "the mechanism is wrong"), --no-holes,
--no-trampolines. tools/pcsx2_boot.py boots the result.
"""
import argparse
import concurrent.futures
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
from common import (ASM, BUILD, EXE_NAME, EXE_SHA1, FILE_OFF, GP, ROOT, SRC_NONMATCHING, VRAM,  # noqa: E402
                    compiler_config, load_functions, tool, unit_path, unit_syms)

OUT = BUILD / "functional"
OBJ = OUT / "obj"
SEG_ADDR = 0x00479000         # start of the new segment (just above the old memory-manager region start)
LIT4 = cc.LIT4                # the game's .lit4 (gp-relative float constants)
# Mem manager region start: lui $a1,%hi(0x478C3F); addiu $a1,$a1,%lo(0x478C3F); & 0xFFFFFFF0
HEAP_LUI = (0x0010A478, 0x3C050048)
HEAP_ADDIU = (0x0010A484, 0x24A58C3F)
HEAP_START_ORIG = 0x00478C3F
SEG_END_VADDR = 0x00393E35   # end of the main LOAD segment's file bytes (.sdata end)
STACK_BOTTOM = 0x01FF0000     # crt0 SetupThread stack base; memory manager region ends at 0x01FEFFF0
GP_DATA = (".sdata", ".sbss", ".lit4", ".lit8", ".scommon")
OK_SECTIONS = (".text", ".rodata", ".rdata", ".data", ".bss")
META = (".reginfo", ".MIPS.abiflags", ".pdr", ".gnu.attributes")   # discarded by the link script
NAMED_ADDR = re.compile(r"^(?:func|D|jtbl)_([0-9A-F]{6,8})$")
TOOL_STAMP = hashlib.sha1(Path(__file__).read_bytes() + Path(cc.__file__).read_bytes()
                          + (ROOT / "toolchain/compiler.toml").read_bytes()).hexdigest()[:12]


def vaddr_to_off(a):
    return a - VRAM + FILE_OFF


# ---------------------------------------------------------------- selection
def parse_list(spec):
    """Comma/space separated names or addresses; @file reads them from a file (one per line, # comments)."""
    out = set()
    if not spec:
        return out
    items = []
    for part in spec.split(","):
        part = part.strip()
        if part.startswith("@"):
            for line in Path(part[1:]).read_text().splitlines():
                line = line.split("#")[0].strip()
                items += line.replace(",", " ").split()
        elif part:
            items.append(part)
    for it in items:
        it = it.strip()
        m = re.match(r"^(?:func_)?(?:0x)?([0-9A-Fa-f]{1,8})(?:\.cpp)?$", Path(it).name)
        if not m:
            sys.exit(f"--only/--exclude: cannot read {it!r}")
        out.add(f"func_{int(m.group(1), 16):08X}")
    return out


# ---------------------------------------------------------------- compile
LI_S = re.compile(r"^(\s*)li\.s\s+(\$f\d+)\s*,\s*(\S+)\s*$")
LI_D = re.compile(r"^(\s*)li\.d\s+(\$\d+)\s*,\s*(\S+)\s*$")


def lit4_index():
    img = (ROOT / "disc" / "files" / EXE_NAME).read_bytes()
    idx = {}
    for a in range(LIT4[0], LIT4[1], 4):
        o = vaddr_to_off(a)
        idx.setdefault(img[o:o + 4], a)
    return idx


def rewrite_literals(text, lit4):
    """li.s that needs a literal: load an identical constant from the game's .lit4 (gp-relative, like
    the original), or build it inline. Never leaves the unit with a .lit4 of its own."""
    lines = text.splitlines()
    n_game = n_inline = 0
    noreorder = False
    for i, line in enumerate(lines):
        s = line.strip()
        if s == ".set\tnoreorder" or s == ".set noreorder":
            noreorder = True
        elif s == ".set\treorder" or s == ".set reorder":
            noreorder = False
        m = LI_D.match(line)
        if m:                             # a double in a 64-bit GPR (soft-float): build it inline
            if noreorder:
                raise cc.StageError("li.d inside a .set noreorder block")
            ind, r = m.group(1), m.group(2)
            v = int.from_bytes(struct.pack("<d", float(m.group(3))), "little")
            hi, lo = v >> 32, v & 0xFFFFFFFF
            seq = [f"lui\t{r},0x{hi >> 16:X}", f"ori\t{r},{r},0x{hi & 0xFFFF:X}", f"dsll32\t{r},{r},0"]
            if lo:
                seq += [".set\tnoat", f"lui\t$1,0x{lo >> 16:X}", f"ori\t$1,$1,0x{lo & 0xFFFF:X}",
                        "dsll32\t$1,$1,0", "dsrl32\t$1,$1,0", f"or\t{r},{r},$1", ".set\tat"]
            lines[i] = "\n".join(ind + x for x in seq)
            n_inline += 1
            continue
        if re.match(r"^\s*li\.d\s", line):
            raise cc.StageError("li.d into a floating-point register: not handled")
        m = LI_S.match(line)
        if not m:
            continue
        bits = struct.pack("<f", float(m.group(3)))
        v = int.from_bytes(bits, "little")
        if v & 0xFFFF == 0:
            continue                      # as builds it inline (lui/mtc1): no literal
        if noreorder:
            raise cc.StageError("li.s inside a .set noreorder block")
        a = lit4.get(bits)
        if a is not None:
            lines[i] = f"{m.group(1)}.extern\tD_{a:08X},4\n{m.group(1)}l.s\t{m.group(2)},D_{a:08X}"
            n_game += 1
        else:
            ind = m.group(1)
            lines[i] = (f"{ind}.set\tnoat\n{ind}lui\t$1,0x{v >> 16:X}\n{ind}ori\t$1,$1,0x{v & 0xFFFF:X}\n"
                        f"{ind}mtc1\t$1,{m.group(2)}\n{ind}.set\tat")
            n_inline += 1
    return "\n".join(lines) + "\n", n_game, n_inline


def compile_unit(src, lit4, cfg):
    """-> (obj path, info dict). Cached on source + tool hash."""
    name = src.stem
    out = OBJ / f"{name}.o"
    stamp = OBJ / f"{name}.stamp"
    key = hashlib.sha1(src.read_bytes()).hexdigest() + TOOL_STAMP
    if out.exists() and stamp.exists():
        st = json.loads(stamp.read_text())
        if st.get("key") == key:
            return out, st["info"]
    text = cc.cxx_to_asm(src, cfg).decode(errors="replace")
    text, n_game, n_inline = rewrite_literals(text, lit4)
    s = OBJ / f"{name}.s"
    s.write_text(text)
    tmp = OBJ / f"{name}.o.tmp"
    cc.run("ee-gcc -c", cc.driver_cmd(s, cfg, None, None, (), "-c", tmp))
    if not tmp.exists() or tmp.stat().st_size == 0:
        raise cc.StageError("assembler produced an empty object")
    cc.fix_symtab(tmp)
    tmp.replace(out)
    info = {"lit_game": n_game, "lit_inline": n_inline}
    stamp.write_text(json.dumps({"key": key, "info": info}))
    return out, info


def assemble_original(name, funcs_by_name, cfg):
    """Control for bisecting: the game's own asm of the function, relocated into the segment the same way.
    If a unit misbehaves but its original asm run from the segment does not, the unit's C++ is at fault."""
    src = ROOT / funcs_by_name[name]["asm"]
    out = OBJ / f"{name}.orig.o"
    cc.assemble_gnu(cc.asm_wrapper(src), out, cfg)
    return out, {"lit_game": 0, "lit_inline": 0}


def obj_facts(path):
    """Sections with bytes, defined globals, undefined globals, STT_FUNC symbols, gp-relative targets."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        gprel = set()
        for s in elf.iter_sections():
            if isinstance(s, RelocationSection):
                for r in s.iter_relocations():
                    if r["r_info_type"] in (7, 8):       # R_MIPS_GPREL16, R_MIPS_LITERAL
                        nm = symtab.get_symbol(r["r_info_sym"]).name
                        if nm:
                            gprel.add(nm)
        sects, aligns = {}, {}
        for s in elf.iter_sections():
            if s["sh_flags"] & 2 and s["sh_size"]:      # SHF_ALLOC
                sects[s.name] = s["sh_size"]
                aligns[s.name] = max(1, s["sh_addralign"])
        defined, undef, funcs = [], [], []
        for sym in symtab.iter_symbols():
            if not sym.name:
                continue
            bind = sym["st_info"]["bind"]
            if sym["st_shndx"] == "SHN_UNDEF":
                if bind != "STB_LOCAL":
                    undef.append(sym.name)
                continue
            if bind != "STB_LOCAL":
                defined.append(sym.name)
                if sym["st_info"]["type"] == "STT_FUNC":
                    funcs.append((sym.name, sym["st_value"]))
    return sects, defined, undef, funcs, gprel, aligns


# ---------------------------------------------------------------- symbols of the matching build
def main_symbols():
    from elftools.elf.elffile import ELFFile
    out = {}
    with open(BUILD / "main.elf", "rb") as fh:
        elf = ELFFile(fh)
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            if sym.name and sym["st_shndx"] != "SHN_UNDEF" and sym["st_info"]["type"] != "STT_SECTION":
                out.setdefault(sym.name, sym["st_value"])
    return out


# ---------------------------------------------------------------- tail sharing
ADDR_TOKEN = re.compile(r"(?:\.L|func_|D_|jtbl_)([0-9A-F]{8})\b")


def outside_refs(funcs_by_name, chosen):
    """{name: [(file, addr)]} references from outside a replaced function into its body (past the start)."""
    spans = sorted((f["addr"], f["addr"] + f["size"], f["name"]) for n, f in funcs_by_name.items() if n in chosen)
    starts = [s[0] for s in spans]
    import bisect
    hits = {}
    own_text = {}

    def own_table(name, label):    # a jump table the replaced function itself loads: not an outside entry
        if name not in own_text:
            own_text[name] = (ROOT / funcs_by_name[name]["asm"]).read_text(errors="replace")
        return label.startswith("jtbl_") and label in own_text[name]

    for p in list((ASM / "nonmatchings").rglob("*.s")) + list((ASM / "data").rglob("*.s")):
        is_data = p.parent.name == "data"
        cur = p.stem
        for line in p.read_text(errors="replace").splitlines():
            if is_data:
                d = re.match(r"^\s*dlabel\s+(\S+)", line)
                if d:
                    cur = d.group(1)
                    continue
            for m in ADDR_TOKEN.finditer(line):
                a = int(m.group(1), 16)
                k = bisect.bisect_right(starts, a) - 1
                if k < 0:
                    continue
                lo, hi, name = spans[k]
                if not lo < a < hi or (not is_data and p.stem == name) or (is_data and own_table(name, cur)):
                    continue
                hits.setdefault(name, set()).add((f"{p.name}:{cur}" if is_data else p.name, a))
    return {k: sorted(v) for k, v in hits.items()}


# ---------------------------------------------------------------- link
def link(units, symtab, extra_syms, plan):
    """units: [(name, obj)]. Returns (elf path, {name: entry}, segment bytes) or raises with unresolved."""
    LOC = OUT / "loc"
    LOC.mkdir(parents=True, exist_ok=True)
    need = {}
    objs = []
    gp_users = {name: facts[4] for name, _, facts in units}
    for name, obj, facts in units:
        sects, defined, undef, funcs, _, _ = facts
        entry_sym = f"__functional_{name}"
        args = [tool("mipsel-linux-gnu-objcopy")]
        own = [f for f, v in funcs if v == 0 and f in defined]
        if not own:
            raise RuntimeError(f"{name}: no global function at .text offset 0")
        args += [f"--redefine-sym={own[0]}={entry_sym}"]
        for d in defined:
            if d != own[0]:
                args += [f"--localize-symbol={d}"]
        lo = LOC / f"{name}.o"
        r = subprocess.run(args + [str(obj), str(lo)], capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError(f"{name}: objcopy: {r.stderr.strip()}")
        objs.append((name, lo))
        for u in undef:
            need.setdefault(u, set()).add(name)
    assigns, unresolved = [], {}
    for u in sorted(need):
        if u == "_gp":
            continue
        a = symtab.get(u)
        if a is None:
            a = extra_syms.get(u)
        if a is None:
            m = NAMED_ADDR.match(u)
            a = int(m.group(1), 16) if m else None
        if a is None:
            for n in need[u]:
                unresolved.setdefault(n, []).append(u)
            continue
        far = [n for n in need[u] if u in gp_users.get(n, ()) and not GP - 0x8000 <= a < GP + 0x8000]
        for n in far:
            unresolved.setdefault(n, []).append(f"{u} (0x{a:08X}) is accessed $gp-relative but lies outside "
                                                f"the $gp range: the unit declares it 8 bytes or smaller")
        assigns.append(f'"{u}" = 0x{a:08X};\n')
    if unresolved:
        return None, unresolved, None
    rel = lambda p: str(p.relative_to(ROOT))   # noqa: E731
    ld = ["/* generated by tools/build_functional.py */\n", "OUTPUT_ARCH(mips:5900)\n",
          f"_gp = 0x{GP:08X};\n", *assigns, "SECTIONS\n{\n"]
    objs_by = dict(objs)
    for name, kind, addr in sorted(plan.placed, key=lambda x: x[2]):
        o = rel(objs_by[name])
        ld.append(f"    .{kind}_{name} 0x{addr:08X} : {{ {o}({RO_SECTIONS if kind == 'r' else '.text'}) }}\n")
    ld.append(f"    .functional 0x{SEG_ADDR:08X} :\n    {{\n")
    for name, kind in plan.overflow:
        ld.append(f"        . = ALIGN(16);\n        {rel(objs_by[name])}({RO_SECTIONS if kind == 'r' else '.text'})\n")
    for name, _, _ in units:
        ld.append(f"        {rel(objs_by[name])}(.bss COMMON)\n")
    ld.append("        . = ALIGN(16);\n    }\n")
    ld.append("    /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.pdr) *(.comment) *(.gnu.attributes) "
              "*(.mdebug*) *(.gptab*) *(.note*) }\n}\n")
    script = OUT / "functional.ld"
    script.write_text("".join(ld))
    elf = OUT / "functional.elf"
    r = subprocess.run([tool("mipsel-linux-gnu-ld"), "-nostdlib", "-EL", "--no-check-sections", "-T", str(script),
                        "-Map", str(OUT / "functional.map"), "-o", str(elf)],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError("ld failed:\n" + r.stderr[-4000:])
    from elftools.elf.elffile import ELFFile
    entries, pieces, seg = {}, [], b""
    with open(elf, "rb") as fh:
        e = ELFFile(fh)
        for sym in e.get_section_by_name(".symtab").iter_symbols():
            if sym.name.startswith("__functional_func_"):
                entries[sym.name[len("__functional_"):]] = sym["st_value"]
        for sec in e.iter_sections():
            if not sec["sh_flags"] & 2 or not sec["sh_size"]:
                continue
            if sec.name == ".functional":
                if sec["sh_type"] != "SHT_PROGBITS":
                    seg = bytes(sec["sh_size"])
                else:
                    seg = sec.data()
                continue
            want = plan.sizes[sec.name]
            if sec["sh_size"] != want[0]:
                raise RuntimeError(f"{sec.name}: linked size 0x{sec['sh_size']:X}, planned 0x{want[0]:X}")
            pieces.append((sec["sh_addr"], sec.data()))
    return elf, entries, (pieces, seg)


# ---------------------------------------------------------------- placement
RO_SECTIONS = ".rodata .rodata.* .rdata .data"


class Plan:
    """Where each unit's code and read-only data go.

    Free RAM is scarce (see the module docstring), but every replaced original function leaves its own
    bytes unused: the C++ copy goes into its own slot when it fits (no trampoline at all), and otherwise
    the slot minus its 8-byte trampoline is a hole for other units' code and jump tables. Only what does
    not fit anywhere goes to the overflow segment above .bss, whose size the heap gives up."""

    def __init__(self, units, funcs_by_name, no_reuse, use_holes=True):
        self.placed, self.overflow, self.sizes = [], [], {}
        self.own = set()
        holes = []
        pieces = []
        for name, _, facts in units:
            sects, aligns = facts[0], facts[5]
            f = funcs_by_name[name]
            a0, size = f["addr"], f["size"]
            tsize, talign = sects.get(".text", 0), aligns.get(".text", 8)
            rsize = sum(v for k, v in sects.items() if k in (".rodata", ".rdata", ".data") or k.startswith(".rodata."))
            ralign = max([aligns[k] for k in sects if k in (".rodata", ".rdata", ".data") or k.startswith(".rodata.")]
                         or [1])
            reuse = use_holes and name not in no_reuse
            if reuse and tsize <= size and a0 % talign == 0:
                self._put(name, "t", a0, tsize)
                self.own.add(name)
                holes.append([a0 + tsize, a0 + size])
            else:
                if reuse:
                    holes.append([a0 + 8, a0 + size])
                pieces.append((tsize, talign, name, "t"))
            if rsize:
                pieces.append((rsize, ralign, name, "r"))
        for size, align, name, kind in sorted(pieces, key=lambda p: (-p[0], p[2])):
            best = None
            for h in holes:                       # best fit: the smallest hole it fits in
                start = (h[0] + align - 1) // align * align
                if start + size <= h[1] and (best is None or h[1] - h[0] < best[1] - best[0]):
                    best = h
            if best is None:
                self.overflow.append((name, kind))
                continue
            start = (best[0] + align - 1) // align * align
            self._put(name, kind, start, size)
            best[0] = start + size
        self.holes_left = sum(h[1] - h[0] for h in holes)

    def _put(self, name, kind, addr, size):
        self.placed.append((name, kind, addr))
        self.sizes[f".{kind}_{name}"] = (size, addr)


# ---------------------------------------------------------------- ELF
def make_elf(base, placed, entries, funcs_by_name, trampolines=True):
    pieces, seg = placed
    b = bytearray(base)
    assert b[:4] == b"\x7fELF"
    phoff, = struct.unpack_from("<I", b, 0x1C)
    phentsize, phnum = struct.unpack_from("<HH", b, 0x2A)
    if phnum != 2:
        raise SystemExit(f"expected 2 program headers in the matching ELF, found {phnum}")
    new_ph = phoff + phnum * phentsize
    first_data = min(struct.unpack_from("<I", b, phoff + k * phentsize + 4)[0] for k in range(phnum))
    if new_ph + phentsize > first_data or any(b[new_ph:new_ph + phentsize]):
        raise SystemExit("no room for a third program header")
    # code and tables placed in the replaced functions' own bytes
    for addr, data in pieces:
        if not (VRAM <= addr and addr + len(data) <= SEG_END_VADDR):
            raise SystemExit(f"piece at 0x{addr:08X} is outside the main segment's file bytes")
        o = vaddr_to_off(addr)
        b[o:o + len(data)] = data
    # trampolines (a unit placed in its own slot needs none)
    for name, entry in (entries.items() if trampolines else ()):
        f = funcs_by_name[name]
        if entry == f["addr"]:
            continue
        o = vaddr_to_off(f["addr"])
        struct.pack_into("<II", b, o, 0x08000000 | ((entry >> 2) & 0x03FFFFFF), 0)
    if not seg:
        return bytes(b), HEAP_START_ORIG & ~0xF
    # memory-manager region start, moved past the segment
    seg_end = SEG_ADDR + len(seg)
    new_start = (seg_end + 0xFFF) & ~0xFFF
    for (a, want) in (HEAP_LUI, HEAP_ADDIU):
        got, = struct.unpack_from("<I", b, vaddr_to_off(a))
        if got != want:
            raise SystemExit(f"heap-start instruction at 0x{a:08X} is 0x{got:08X}, expected 0x{want:08X}")
    v = new_start + 0xF                               # the game masks with 0xFFFFFFF0
    hi, lo = (v + 0x8000) >> 16, v & 0xFFFF
    struct.pack_into("<I", b, vaddr_to_off(HEAP_LUI[0]), 0x3C050000 | hi)
    struct.pack_into("<I", b, vaddr_to_off(HEAP_ADDIU[0]), 0x24A50000 | lo)
    # segment bytes, page-congruent with the vaddr
    off = (len(b) + 0xFFF) & ~0xFFF
    off += SEG_ADDR & 0xFFF
    b += bytes(off - len(b)) + seg
    struct.pack_into("<IIIIIIII", b, new_ph, 1, off, SEG_ADDR, SEG_ADDR, len(seg), len(seg), 7, 0x1000)
    struct.pack_into("<H", b, 0x2C, phnum + 1)
    return bytes(b), new_start


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--only", help="build with just these units (names/addresses, comma separated, or @file)")
    ap.add_argument("--exclude", help="leave these units out (same syntax)")
    ap.add_argument("--no-ninja", action="store_true", help="do not (re)build the matching ELF first")
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("-o", "--output", default=str(OUT / EXE_NAME))
    ap.add_argument("--use-asm", help="debug control: for these units, relocate the game's own asm into the "
                                      "segment instead of compiling the C++ (same syntax as --only)")
    ap.add_argument("--no-holes", action="store_true",
                    help="put every unit in the overflow segment instead of the replaced functions' own bytes")
    ap.add_argument("--no-trampolines", action="store_true",
                    help="debug: load the segment and move the heap, but keep running the original code")
    a = ap.parse_args()
    jobs = max(1, min(a.jobs, 4))

    if not a.no_ninja:
        r = subprocess.run([str(ROOT / ".venv/bin/ninja"), f"-j{jobs}"], cwd=ROOT)
        if r.returncode:
            sys.exit("the matching build failed: fix it first (it is the base of the functional build)")
    base_path = BUILD / EXE_NAME
    base = base_path.read_bytes()
    if hashlib.sha1(base).hexdigest() != EXE_SHA1:
        sys.exit(f"{base_path} is not the matching build (sha1 differs): run ninja first")

    funcs_by_name = {f["name"]: f for f in load_functions()}
    only, excl, use_asm = parse_list(a.only), parse_list(a.exclude), parse_list(a.use_asm)
    skipped = {}     # name -> reason
    cand = []
    for src in sorted(SRC_NONMATCHING.glob("func_*.cpp")):
        n = src.stem
        if only and n not in only:
            continue
        if n in excl:
            skipped[n] = "excluded (--exclude)"
            continue
        f = funcs_by_name.get(n)
        if f is None:
            skipped[n] = "not in config/functions.us.csv"
        elif unit_path(n).exists():
            skipped[n] = "already matched in src/funcs (the build has its exact bytes)"
        elif f["size"] < 8:
            skipped[n] = f"original is only {f['size']} bytes: no room for a j+nop trampoline"
        else:
            cand.append(src)
    for n in sorted(only - {p.stem for p in SRC_NONMATCHING.glob('func_*.cpp')}):
        skipped[n] = "--only names a function with no src/nonmatching unit"

    # mid-function entries: a branch/pointer from outside to +4 would land on the trampoline's nop
    refs = outside_refs(funcs_by_name, {p.stem for p in cand})
    mid_entries = {}
    for n, lst in refs.items():
        a0 = funcs_by_name[n]["addr"]
        bad = [(fl, x) for fl, x in lst if x < a0 + 8]
        if bad:
            skipped[n] = "something outside enters it at +4: " + ", ".join(f"0x{x:08X} from {fl}" for fl, x in bad)
        else:
            mid_entries[n] = lst
    cand = [p for p in cand if p.stem not in skipped]

    OBJ.mkdir(parents=True, exist_ok=True)
    cfg = compiler_config()
    lit4 = lit4_index()
    built = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        futs = {(ex.submit(assemble_original, p.stem, funcs_by_name, cfg) if p.stem in use_asm
                 else ex.submit(compile_unit, p, lit4, cfg)): p for p in cand}
        for fu in concurrent.futures.as_completed(futs):
            p = futs[fu]
            try:
                built[p.stem] = fu.result()
            except cc.StageError as e:
                skipped[p.stem] = "compile: " + str(e).strip().splitlines()[-1][:200]

    units = []
    lit_game = lit_inline = 0
    for n in sorted(built):
        obj, info = built[n]
        facts = obj_facts(obj)
        sects = facts[0]
        bad = [s for s in sects if s in GP_DATA or not (s in OK_SECTIONS or s.startswith(".rodata") or s in META)]
        if bad:
            skipped[n] = "sections this build cannot place: " + ", ".join(f"{s} ({sects[s]} bytes)" for s in bad)
            continue
        units.append((n, obj, facts))
        lit_game += info["lit_game"]
        lit_inline += info["lit_inline"]

    symtab = main_symbols()
    extra = {}
    for p in sorted(SRC_NONMATCHING.glob("func_*.cpp")):
        for nm, ad in unit_syms(p):
            if nm in symtab and symtab[nm] != ad:
                print(f"warning: {p.name} maps {nm} to 0x{ad:08X}, the matching build has 0x{symtab[nm]:08X}")
            extra.setdefault(nm, ad)
    no_reuse = set(mid_entries)       # their bodies are still entered from outside: keep the original bytes
    while True:
        plan = Plan(units, funcs_by_name, no_reuse, use_holes=not a.no_trampolines and not a.no_holes)
        elf, res, seg = link(units, symtab, extra, plan)
        if elf is not None:
            break
        for n, syms in res.items():
            gpf = [x for x in syms if " " in x]
            skipped[n] = ("; ".join(sorted(set(gpf))) if gpf else
                          "unresolved symbols: " + ", ".join(sorted(syms)))
        units = [u for u in units if u[0] not in res]
    entries = res

    out_bytes, heap_start = make_elf(base, seg, entries, funcs_by_name, not a.no_trampolines)
    if heap_start >= STACK_BOTTOM - 0x01000000:
        sys.exit("segment too large")
    outp = Path(a.output)
    outp.parent.mkdir(parents=True, exist_ok=True)
    outp.write_bytes(out_bytes)

    orig_bytes = sum(funcs_by_name[n]["size"] for n in entries)
    pieces, seg = seg
    tramp = [n for n in entries if entries[n] != funcs_by_name[n]["addr"]]
    lines = [
        f"functional build: {outp.relative_to(ROOT) if outp.is_relative_to(ROOT) else outp}",
        f"  sha1 {hashlib.sha1(out_bytes).hexdigest()}",
        f"  units replaced: {len(entries)} (src/nonmatching), running C++ instead of 0x{orig_bytes:X} bytes "
        f"of original code; src/funcs units already run C++ in the matching layout",
        f"  placement: {len(plan.own)} in their own original bytes (no trampoline), "
        f"{len(tramp)} behind a j+nop trampoline; {len(pieces)} code/table pieces in replaced functions' bytes, "
        f"0x{plan.holes_left:X} bytes of those left unused",
        (f"  overflow segment: 0x{SEG_ADDR:08X}-0x{SEG_ADDR + len(seg):08X} (0x{len(seg):X} bytes, "
         f"{len(plan.overflow)} pieces), third PT_LOAD; memory-manager region start moved "
         f"0x{HEAP_START_ORIG & ~0xF:08X} -> 0x{heap_start:08X} (heap {(0x01FEFFF0 - heap_start) / 1048576:.2f} MB, "
         f"was {(0x01FEFFF0 - 0x00478C30) / 1048576:.2f} MB)") if seg else
        "  overflow segment: none (everything fits in the original layout; heap and program headers untouched)",
        f"  float literals: {lit_game} pointed at the game's .lit4, {lit_inline} built inline",
        f"  units skipped: {len(skipped)}",
    ]
    for n in sorted(skipped):
        lines.append(f"    {n}: {skipped[n]}")
    lines.append(f"  units entered mid-body from outside (they still run the original code there): {len(mid_entries)}")
    for n in sorted(mid_entries):
        if n in entries:
            lines.append(f"    {n}: " + ", ".join(f"0x{x:08X} ({fl})" for fl, x in mid_entries[n][:6])
                         + (" ..." if len(mid_entries[n]) > 6 else ""))
    report = "\n".join(lines) + "\n"
    (OUT / "report.txt").write_text(report)
    (OUT / "entries.json").write_text(json.dumps({n: f"0x{v:08X}" for n, v in sorted(entries.items())}, indent=1))
    print(report, end="")


if __name__ == "__main__":
    main()
