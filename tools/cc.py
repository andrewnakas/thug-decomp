#!/usr/bin/env python3
"""The one compile driver. Every C++/C unit and every asm file is built through here.

    python tools/cc.py cxx src/funcs/func_00112345.cpp build/x.o
    python tools/cc.py asm asm/nonmatchings/game/func_00112345.s build/y.o
    python tools/cc.py cxx in.cpp out.o --print-asm     # stop after cc1plus, print asm

C++ pipeline (toolchain/compiler.toml):  SN ee-gcc driver -> cpp, cc1plus, as (Windows .exe under wibo)
Asm pipeline:                            GNU as -march=r5900 (splat output)

Each stage is its own subprocess with its exit status checked; an empty or
missing object is an error (a shell pipe would hide a missing tool and leave an
empty .o that ninja happily links).

Experiments (compiler identification) may override --compiler and --cflags;
gates never pass these.
"""
import argparse
import os
import re
import shlex
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT, TOOLCHAIN, compiler_config, file_cflags, tool  # noqa: E402

UNIT_EXTS_SRC = (".cpp", ".c")
TIMEOUT = 120  # wibo can hang (RAC3 lesson): never wait forever


class StageError(Exception):
    pass


def run(stage, argv, data=b"", cwd=ROOT):
    try:
        p = subprocess.run(argv, input=data, capture_output=True, cwd=cwd, timeout=TIMEOUT)
    except FileNotFoundError:
        raise StageError(f"{stage}: tool not found: {argv[0]} (run python3 toolchain/setup.py)")
    except subprocess.TimeoutExpired:
        raise StageError(f"{stage}: timed out after {TIMEOUT}s")
    if p.returncode != 0:
        raise StageError(f"{stage} failed ({p.returncode}):\n{p.stderr.decode(errors='replace')}")
    return p.stdout


def compiler_dir(cfg, name=None):
    name = name or cfg["compiler"]["name"]
    spec = cfg["compilers"][name]
    return TOOLCHAIN / "compilers" / spec["dir"], spec


def wibo():
    return str(TOOLCHAIN / "bin" / "wibo")


def driver_cmd(src, cfg, compiler, cflags, extra_cpp, mode, out):
    """SN's own ee-gcc driver (under wibo): it supplies SN's exact cpp predefines and as flags."""
    c = cfg["compiler"]
    cdir, spec = compiler_dir(cfg, compiler)
    flags = list(cflags if cflags is not None else c["cflags"])
    if Path(src).suffix in UNIT_EXTS_SRC:
        flags += file_cflags(src)  # later flags win in gcc
    return [wibo(), str(cdir / spec["driver"]), mode, *flags, *c["cppflags"], *extra_cpp,
            os.path.relpath(src, ROOT), "-o", os.path.relpath(out, ROOT)]


def cxx_to_asm(src, cfg, compiler=None, cflags=None, extra_cpp=()):
    """Preprocess + compile one unit; returns the compiler's assembly text (bytes)."""
    (ROOT / "build").mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="thugcc", dir=ROOT / "build") as td:
        out = Path(td) / "u.s"
        run("ee-gcc -S", driver_cmd(src, cfg, compiler, cflags, extra_cpp, "-S", out))
        text = out.read_bytes()
    if not text.strip():
        raise StageError("compiler produced no output")
    return text


# Float literals. SN's compiler writes `li.s $fN,<value>` and SN's as turns every
# value it cannot build with lui/mtc1 into a fresh .lit4 constant (R_MIPS_LITERAL).
# The original's constants already sit in the global .lit4 blob, so the k-th such
# li.s is rewritten to load the k-th literal the original function loads, but
# only when the 4 bytes there are exactly the value the compiler asked for.
LIT4 = (0x387400, 0x388258)
LI_S = re.compile(r"^(\s*)li\.s\s+(\$f\d+)\s*,\s*(\S+)\s*$")
GPREL_REF = re.compile(r"%gp_rel\((D_([0-9A-F]{8}))\)")
UNIT_NAME = re.compile(r"^(func_[0-9A-F]{8})$")


def target_literals(func):
    """Addresses of the .lit4 constants the original function loads, in instruction order."""
    from common import FUNCTIONS_CSV
    import csv
    with open(FUNCTIONS_CSV) as f:
        row = next((r for r in csv.DictReader(f) if r["name"] == func), None)
    if row is None:
        return []
    out = []
    for line in (ROOT / row["asm"]).read_text().splitlines():
        for m in GPREL_REF.finditer(line):
            a = int(m.group(2), 16)
            if LIT4[0] <= a < LIT4[1] and ("lwc1" in line):
                out.append(m.group(1))
    return out


def retarget_literals(asm_text, func):
    from common import EXE, FILE_OFF, VRAM
    want = target_literals(func)
    if not want:
        return asm_text
    img = EXE.read_bytes()
    lines = asm_text.decode(errors="replace").splitlines()
    k = 0
    for i, line in enumerate(lines):
        m = LI_S.match(line)
        if not m:
            continue
        bits = struct.pack("<f", float(m.group(3)))
        if int.from_bytes(bits, "little") & 0xFFFF == 0:
            continue                     # as builds it inline (lui/mtc1): no literal
        if k >= len(want):
            break
        sym = want[k]
        a = int(sym[2:], 16)
        if img[a - VRAM + FILE_OFF:a - VRAM + FILE_OFF + 4] != bits:
            break                        # different value: leave it, the build will fail loudly
        # old SN as: a small .extern makes `l.s` gp-relative by itself (R_MIPS_GPREL16)
        lines[i] = f"{m.group(1)}.extern\t{sym},4\n{m.group(1)}l.s\t{m.group(2)},{sym}"
        k += 1
    return ("\n".join(lines) + "\n").encode()


def fix_symtab(path):
    """Make an SN object linkable by modern ld.

    Old SN gas writes .symtab sh_info as the number of section symbols, not the index of
    the first global; modern ld rejects that ("local symbol at index N (>= sh_info)").
    Set it to the first non-local symbol. Locals always precede globals in its output;
    anything else is an error, never a silent reorder."""
    b = bytearray(Path(path).read_bytes())
    if b[:4] != b"\x7fELF" or b[4] != 1 or b[5] != 1:
        raise StageError(f"{path}: not a 32-bit little-endian ELF")
    # e_flags ABI field: SN emits EABI64 (0x4000); splat's asm is assembled as O64 (0x2000)
    # because modern gas only accepts o32 register names that way. Metadata only.
    flags, = struct.unpack_from("<I", b, 0x24)
    struct.pack_into("<I", b, 0x24, (flags & ~0xF000) | 0x2000)
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", b, 0x2E)
    for k in range(shnum):
        h = shoff + k * shentsize
        sh_type, = struct.unpack_from("<I", b, h + 4)
        if sh_type != 2:  # SHT_SYMTAB
            continue
        off, size = struct.unpack_from("<II", b, h + 16)
        entsize, = struct.unpack_from("<I", b, h + 36)
        binds = [b[off + i * entsize + 12] >> 4 for i in range(size // entsize)]
        first_global = next((i for i, bd in enumerate(binds) if bd != 0), len(binds))
        if any(bd == 0 for bd in binds[first_global:]):
            raise StageError(f"{path}: local symbol after a global in .symtab")
        struct.pack_into("<I", b, h + 28, first_global)
    Path(path).write_bytes(bytes(b))


def compile_obj(src, out, cfg, compiler=None, cflags=None, extra_cpp=(), literals=True, func=None):
    """Compile a unit to an object. With literals=True, float literals are retargeted
    to the original function's constants (see above); func defaults to the file stem."""
    out = Path(out)
    out.parent.mkdir(parents=True, exist_ok=True)
    tmp = out.with_suffix(out.suffix + ".tmp")
    func = func or (Path(src).stem if UNIT_NAME.match(Path(src).stem) else None)
    text = cxx_to_asm(src, cfg, compiler, cflags, extra_cpp)
    if literals and func:
        text = retarget_literals(text, func)
    with tempfile.TemporaryDirectory(prefix="thugas", dir=ROOT / "build") as td:
        s = Path(td) / "u.s"
        s.write_bytes(text)
        run("ee-gcc -c", driver_cmd(s, cfg, compiler, cflags, (), "-c", tmp))
    if not tmp.exists() or tmp.stat().st_size == 0:
        raise StageError("compiler produced an empty object")
    fix_symtab(tmp)
    os.replace(tmp, out)


def assemble_gnu(asm_text, out, cfg):
    out = Path(out)
    out.parent.mkdir(parents=True, exist_ok=True)
    tmp = out.with_suffix(out.suffix + ".tmp")
    run("as", [tool("mipsel-linux-gnu-as"), *cfg["as"]["flags"], "-o", str(tmp), "--"], asm_text)
    if not tmp.exists() or tmp.stat().st_size == 0:
        raise StageError("as produced an empty object")
    os.replace(tmp, out)


def asm_wrapper(path):
    """splat's per-function .s files are made for INCLUDE_ASM; give them a preamble."""
    rel = os.path.relpath(path, ROOT)
    sect = ".text"
    head = Path(path).read_text(errors="replace")[:4096]
    for line in head.splitlines():
        s = line.strip()
        if s.startswith(".section"):
            sect = s.split()[1].rstrip(",")
            break
    return (f'.include "macro.inc"\n.set noat\n.set noreorder\n.section {sect}\n'
            f'.include "{rel}"\n').encode()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("kind", choices=["cxx", "asm", "bin"])
    ap.add_argument("src")
    ap.add_argument("out", nargs="?")
    ap.add_argument("--print-asm", action="store_true")
    ap.add_argument("--compiler")
    ap.add_argument("--cflags")
    ap.add_argument("-D", action="append", default=[])
    a = ap.parse_args()
    cfg = compiler_config()
    cflags = shlex.split(a.cflags) if a.cflags is not None else None
    defs = [f"-D{d}" for d in a.D]
    try:
        if a.kind == "cxx" and a.print_asm:
            sys.stdout.write(cxx_to_asm(a.src, cfg, a.compiler, cflags, defs).decode(errors="replace"))
            return
        if not a.out:
            sys.exit("output path required")
        if a.kind == "cxx":
            compile_obj(a.src, a.out, cfg, a.compiler, cflags, defs)
        elif a.kind == "bin":
            rel = os.path.relpath(a.src, ROOT)
            assemble_gnu(f'.section .data\n.incbin "{rel}"\n'.encode(), a.out, cfg)
        else:
            assemble_gnu(asm_wrapper(a.src), a.out, cfg)
    except StageError as e:
        sys.exit(f"{a.src}: {e}")


if __name__ == "__main__":
    main()
