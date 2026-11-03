#!/usr/bin/env python3
"""Compile every unit with the pinned toolchain, no disc needed (public CI).

    python tools/compile_units.py

Each src/funcs/*.cpp must compile, define exactly one function, and emit no data,
rodata, literal or linkonce sections of its own. Whether it MATCHES needs the
disc, so that is judged by Steward on the maintainer's machine (tools/gate.py).
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
import gate  # noqa: E402
import match  # noqa: E402
from common import BUILD, SRC_FUNCS, compiler_config  # noqa: E402


def main():
    cfg = compiler_config()
    bad = 0
    files = sorted(SRC_FUNCS.glob("*.cpp"))
    for f in files:
        out = BUILD / "ci" / (f.stem + ".o")
        try:
            cc.compile_obj(f, out, cfg, literals=False)   # literal retargeting reads the disc
            o = match.read_obj(out, 0)
        except (cc.StageError, ValueError) as e:
            print(f"PROBLEM {f.name}: {str(e).strip().splitlines()[-1][:300]}")
            bad += 1
            continue
        for s in gate.DATA_SECTIONS:
            if s in (".lit4", ".lit8"):
                continue   # without the disc, literals are not retargeted yet
            if o.sections.get(s, 0):
                print(f"PROBLEM {f.name}: has its own {s} ({o.sections[s]} bytes)")
                bad += 1
    print(f"compile: {len(files)} units, {bad} problems")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
