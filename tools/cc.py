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
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT, TOOLCHAIN, compiler_config, file_cflags, tool  # noqa: E402

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
    flags += file_cflags(src)  # later flags win in gcc
    return [wibo(), str(cdir / spec["driver"]), mode, *flags, *c["cppflags"], *extra_cpp,
            os.path.relpath(src, ROOT), "-o", os.path.relpath(out, ROOT)]


def cxx_to_asm(src, cfg, compiler=None, cflags=None, extra_cpp=()):
    """Preprocess + compile one unit; returns the compiler's assembly text (bytes)."""
    with tempfile.TemporaryDirectory(prefix="thugcc", dir=ROOT / "build") as td:
        out = Path(td) / "u.s"
        run("ee-gcc -S", driver_cmd(src, cfg, compiler, cflags, extra_cpp, "-S", out))
        text = out.read_bytes()
    if not text.strip():
        raise StageError("compiler produced no output")
    return text


def compile_obj(src, out, cfg, compiler=None, cflags=None, extra_cpp=()):
    out = Path(out)
    out.parent.mkdir(parents=True, exist_ok=True)
    tmp = out.with_suffix(out.suffix + ".tmp")
    run("ee-gcc -c", driver_cmd(src, cfg, compiler, cflags, extra_cpp, "-c", tmp))
    if not tmp.exists() or tmp.stat().st_size == 0:
        raise StageError("compiler produced an empty object")
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
