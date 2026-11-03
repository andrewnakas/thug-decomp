#!/usr/bin/env python3
"""Find functions that start with SN linker fill and record where the real code starts.

    python tools/find_fill.py          # writes config/fill_starts.us.txt, then run tools/split.py

SN's linker leaves dead `addiu $sp, $sp, +N; nop` pairs (the tails of stripped
functions) between functions. When one sits right before an unreferenced-by-call
function, spimdisasm folds it into that function's start, so the "function" begins
with an epilogue. This finds every function whose first instructions are such
pairs followed by real code and records the real start as a function symbol, so
the next split separates them (the fill then becomes kind=fill on its own).
Run it until it finds nothing new (a re-split can expose another layer).
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import CONFIG, ROOT, load_functions  # noqa: E402

OUT = CONFIG / "fill_starts.us.txt"
INSN = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+(\S+)\s*(.*)")
SP_POP = re.compile(r"^\$sp,\s*\$sp,\s*0x[0-9A-F]+$")


def real_start(path):
    insns = []
    for line in path.read_text().splitlines():
        m = INSN.search(line)
        if m:
            insns.append((int(m.group(1), 16), m.group(2), m.group(3).strip()))
    i = 0
    while i + 1 < len(insns) and insns[i][1] == "addiu" and SP_POP.match(insns[i][2]) and insns[i + 1][1] == "nop":
        i += 2
    if i == 0 or i >= len(insns):
        return None
    return insns[i][0] if len(insns) - i >= 2 else None   # real code follows the fill


def main():
    old = {}
    if OUT.exists():
        for line in OUT.read_text().splitlines():
            m = re.match(r"^(func_[0-9A-F]{8}) = (0x[0-9A-F]{8});", line)
            if m:
                old[m.group(1)] = int(m.group(2), 16)
    found = dict(old)
    for f in load_functions():
        if f["kind"] != "func":
            continue
        a = real_start(ROOT / f["asm"])
        if a is not None:
            found[f"func_{a:08X}"] = a
    lines = ["// Real function starts hidden behind SN linker fill (tools/find_fill.py). Generated."]
    lines += [f"{n} = 0x{a:08X}; // type:func" for n, a in sorted(found.items(), key=lambda t: t[1])]
    OUT.write_text("\n".join(lines) + "\n")
    print(f"find_fill: {len(found)} real starts ({len(found) - len(old)} new) -> {OUT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
