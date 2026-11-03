#!/usr/bin/env python3
"""Find unmatched functions whose code is identical to an already-matched unit.

    python tools/clones.py                 # every clone group with at least one match
    python tools/clones.py --lane 0x100000 0x1C0000   # only unmatched clones in this range
    python tools/clones.py --unmatched-groups 5       # groups of >= 5 identical unmatched functions

Instructions are normalised: symbol names, branch targets, %hi/%lo/%gp_rel
operands and absolute addresses become placeholders, so two functions that differ
only in which globals, callees or vtables they use compare equal. A clone of a
matched unit usually matches from the same source with the class, callee and
global names changed (lanes found 63 hash-table copies this way). It is a hint,
not a match: always run tools/match.py on the adapted file.
"""
import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT, SRC_FUNCS, load_functions  # noqa: E402

INSN = re.compile(r"/\*\s*[0-9A-F]+\s+[0-9A-F]{8}\s+[0-9A-F]{8}\s*\*/\s+(.*)$")
SYM = re.compile(r"\b(?:func|D|jtbl|\.L|L)_?[0-9A-F]{8}\b|\.L[0-9A-F]{8}")
REL = re.compile(r"%(hi|lo|gp_rel)\([^)]*\)")


def signature(path):
    out = []
    for line in path.read_text().splitlines():
        if line.lstrip().startswith("endlabel"):
            break
        m = INSN.search(line)
        if not m:
            continue
        s = m.group(1).split("/*")[0].strip()
        s = REL.sub(lambda r: f"%{r.group(1)}(S)", s)
        s = SYM.sub("S", s)
        s = re.sub(r"\s+", " ", s)
        out.append(s)
    return tuple(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lane", nargs=2, metavar=("LO", "HI"))
    ap.add_argument("--unmatched-groups", type=int, metavar="N",
                    help="also list groups of >= N identical unmatched functions (one source would do all)")
    ap.add_argument("--min-insns", type=int, default=4)
    ap.add_argument("--with", dest="extra", action="append", default=[], metavar="DIR",
                    help="also count units in DIR (e.g. another clone's src/funcs) as matched")
    a = ap.parse_args()
    lo, hi = (int(a.lane[0], 16), int(a.lane[1], 16)) if a.lane else (0, 1 << 32)
    done = {p.stem for p in SRC_FUNCS.glob("func_*.cpp")}
    where = {n: "src/funcs" for n in done}
    for d in a.extra:
        for p in Path(d).expanduser().glob("func_*.cpp"):
            if p.stem not in done:
                done.add(p.stem)
                where[p.stem] = d
    groups = defaultdict(list)
    for f in load_functions():
        if f["kind"] != "func" or f["source"] != "game":
            continue
        sig = signature(ROOT / f["asm"])
        if len(sig) >= a.min_insns:
            groups[sig].append(f)
    n = 0
    for sig, fs in sorted(groups.items(), key=lambda kv: kv[1][0]["addr"]):
        matched = [f for f in fs if f["name"] in done]
        todo = [f for f in fs if f["name"] not in done and lo <= f["addr"] < hi]
        if matched and todo:
            n += len(todo)
            src = matched[0]["name"]
            print(f"{src} [{where[src]}] ({len(sig)} insns) -> " + " ".join(f["name"] for f in todo))
    print(f"clones: {n} unmatched functions are identical to a matched unit")
    if a.unmatched_groups:
        for sig, fs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
            todo = [f for f in fs if f["name"] not in done and lo <= f["addr"] < hi]
            if len(todo) >= a.unmatched_groups and not any(f["name"] in done for f in fs):
                print(f"group of {len(todo)} ({len(sig)} insns): " + " ".join(f["name"] for f in todo[:12])
                      + (" ..." if len(todo) > 12 else ""))


if __name__ == "__main__":
    main()
