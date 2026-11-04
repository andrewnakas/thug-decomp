"""Shared paths and config for every tool. Import, don't copy."""
import csv
import os
import re
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLCHAIN = ROOT / "toolchain"
BIN = TOOLCHAIN / "bin"
ASM = ROOT / "asm"
BUILD = Path(os.environ.get("THUG_BUILD", ROOT / "build"))
SRC_FUNCS = ROOT / "src" / "funcs"
CONFIG = ROOT / "config"
FUNCTIONS_CSV = CONFIG / "functions.us.csv"
EXE_NAME = "SLUS_207.31"
EXE = ROOT / "disc" / "files" / EXE_NAME
EXE_SHA1 = "ffefbe60ba0a1d7f27264bc1be6782f6bfc22985"
GP = 0x38F3F0
VRAM = 0x100000          # main LOAD segment vaddr
FILE_OFF = 0x1000        # its file offset (file offset = vram - 0xFF000)
SEG_END = 0x294E35       # end of the main segment's file bytes (.sdata end)

UNIT_EXTS = (".cpp", ".c")
UNIT_RE = re.compile(r"^func_([0-9A-F]{8})\.(cpp|c)$")
CFLAGS_RE = re.compile(r"^/\*\s*cflags:(.*?)\*/")


def tool(name):
    """A binutils tool: toolchain/bin first, then PATH."""
    p = BIN / name
    return str(p) if p.exists() else name


def compiler_config():
    return tomllib.loads((TOOLCHAIN / "compiler.toml").read_text())


def file_cflags(path):
    """Per-file flags from a first-line /* cflags: ... */ comment."""
    with open(path) as f:
        m = CFLAGS_RE.match(f.readline())
    return m.group(1).split() if m else []


def load_functions():
    """Rows of config/functions.us.csv with addr/size as ints."""
    rows = []
    with open(FUNCTIONS_CSV) as f:
        for r in csv.DictReader(f):
            r["addr"] = int(r["addr"], 16)
            r["size"] = int(r["size"], 16)
            rows.append(r)
    return rows


def unit_path(name):
    """The C++ (or C) source for a function, if one exists; else the .cpp path it would have."""
    for ext in UNIT_EXTS:
        p = SRC_FUNCS / f"{name}{ext}"
        if p.exists():
            return p
    return SRC_FUNCS / f"{name}.cpp"


UNIT_SYM_RE = re.compile(r"/\*\s*sym:\s*([^\s=*]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*\*/")


def unit_syms(path):
    """[(mangled name, address)] from `/* sym: NAME = 0xADDR */` directives in a unit file.

    A unit carries the C++-name mappings it needs itself, so a PR that only touches src/funcs
    (all Steward copies into the judge) is self-contained.
    """
    try:
        text = Path(path).read_text(errors="replace")
    except OSError:
        return []
    return [(m.group(1), int(m.group(2), 16)) for m in UNIT_SYM_RE.finditer(text)]


def all_unit_syms():
    out = []
    for p in sorted(SRC_FUNCS.glob("func_*.cpp")):
        out += [(n, a, p.name) for n, a in unit_syms(p)]
    return out
