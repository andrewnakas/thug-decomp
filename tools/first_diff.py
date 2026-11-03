#!/usr/bin/env python3
"""Where does build/SLUS_207.31 first differ from the original, and in which function?

    python tools/first_diff.py [--all] [build/SLUS_207.31]
"""
import argparse
import bisect
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BUILD, EXE, EXE_NAME, FILE_OFF, FUNCTIONS_CSV, SEG_END, VRAM, load_functions  # noqa: E402


def where(off, funcs, starts):
    if FILE_OFF <= off < SEG_END:
        va = off - FILE_OFF + VRAM
        i = bisect.bisect_right(starts, va) - 1
        if i >= 0 and va < funcs[i]["addr"] + funcs[i]["size"]:
            f = funcs[i]
            return f"vram 0x{va:08X}, {f['name']} +0x{va - f['addr']:X}"
        return f"vram 0x{va:08X} (data)"
    return "outside the main segment (ELF header or tail)"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("built", nargs="?", default=str(BUILD / EXE_NAME))
    ap.add_argument("--all", action="store_true", help="list every differing function, not just the first")
    a = ap.parse_args()
    want = EXE.read_bytes()
    got = Path(a.built).read_bytes()
    funcs = load_functions() if FUNCTIONS_CSV.exists() else []
    starts = [f["addr"] for f in funcs]
    if len(got) != len(want):
        print(f"size: built 0x{len(got):X}, original 0x{len(want):X}")
    n = min(len(got), len(want))
    seen = set()
    for off in range(n):
        if got[off] != want[off]:
            w = where(off, funcs, starts)
            key = w.split(" +")[0]
            if key in seen:
                continue
            seen.add(key)
            print(f"file 0x{off:X}: built {got[off]:02X}, original {want[off]:02X}  ({w})")
            if not a.all:
                return 1
    if len(got) == len(want) and not seen:
        print("identical")
        return 0
    return 1


if __name__ == "__main__":
    sys.exit(main())
