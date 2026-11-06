#!/usr/bin/env python3
"""Score an equivalent-but-not-matching unit and keep its `/* fuzzy: */` line current.

    python tools/nonmatch.py func_00112345            # print the score of src/nonmatching/func_00112345.cpp
    python tools/nonmatch.py func_00112345 --write    # also write/update its /* fuzzy: NN.N */ line
    python tools/nonmatch.py --all --write            # every src/nonmatching unit

src/nonmatching/ is for readable C++ that is functionally equivalent to a function nobody has matched yet.
It follows every unit rule (tools/scan.py), is never linked (the build keeps the game's asm), and counts
toward ByteMatch's fuzzy progress only. gate.py recomputes the score and rejects a stale line. When a unit
matches exactly, move it to src/funcs/.
"""
import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
from common import FUZZY_RE, SRC_NONMATCHING  # noqa: E402


def score(path):
    res = match.compare(path.stem, path)
    if res.error:
        raise SystemExit(f"{path.name}: {res.error.strip().splitlines()[-1]}")
    return res, match.fuzzy(res)


def write(path, value):
    text = path.read_text()
    line = f"/* fuzzy: {value:.1f} */"
    if FUZZY_RE.search(text):
        text = FUZZY_RE.sub(line, text, count=1)
    elif text.startswith("/* cflags:"):
        first, _, rest = text.partition("\n")
        text = f"{first}\n{line}\n{rest}"
    else:
        text = f"{line}\n{text}"
    path.write_text(text)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("names", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    paths = sorted(SRC_NONMATCHING.glob("func_*.cpp")) if a.all else [SRC_NONMATCHING / f"{n}.cpp" for n in a.names]
    for p in paths:
        if not p.exists():
            print(f"{p} missing")
            continue
        res, v = score(p)
        if res.ok:
            print(f"{p.stem}: MATCH, move it to src/funcs/")
            continue
        print(f"{p.stem}: fuzzy {v:.1f} ({len(res.diffs)} of {len(res.target.words)} words differ)")
        if a.write:
            write(p, v)


if __name__ == "__main__":
    main()
