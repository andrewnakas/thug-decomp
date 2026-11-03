#!/usr/bin/env python3
"""Clean re-split of SLUS_207.31, then derive the function table.

    python tools/split.py

1. Wipes asm/ and build/splat_src (splat leaves stale files behind; never split
   over an old tree).
2. Runs splat on config/splat.us.yaml.
3. Writes config/functions.us.csv: the Steward unit table and the progress
   denominator. The `source` column (game | sdk | libc | openssl | gamespy | ...)
   comes from config/lib_ranges.us.csv (tools/lib_identify.py); only `game`
   functions are decomp targets.
"""
import csv
import hashlib
import re
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ASM, BUILD, CONFIG, FUNCTIONS_CSV, ROOT  # noqa: E402

YAML = CONFIG / "splat.us.yaml"
LIB_RANGES = CONFIG / "lib_ranges.us.csv"
STAMP = BUILD / "split.stamp"

ADDR = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s")
NONMATCH = re.compile(r"^nonmatching\s+(\w+)(?:,\s*(0x[0-9A-Fa-f]+))?")
GLABEL = re.compile(r"^\s*glabel\s+(\w+)")


def split_inputs():
    """Files whose change requires a re-split (tools/fresh.py stamps these)."""
    files = [YAML, CONFIG / "symbol_addrs.us.txt", CONFIG / "fill_starts.us.txt", CONFIG / "reloc_addrs.us.txt", LIB_RANGES,
             ROOT / "requirements.txt", Path(__file__)]
    return [f for f in files if f.exists()]


def inputs_hash():
    h = hashlib.sha256()
    for f in split_inputs():
        h.update(f.name.encode() + b"\0" + f.read_bytes())
    return h.hexdigest()


def load_lib_ranges():
    if not LIB_RANGES.exists():
        return []
    with open(LIB_RANGES) as f:
        return [(int(r["start"], 16), int(r["end"], 16), r["source"]) for r in csv.DictReader(f)]


def source_of(addr, ranges):
    for lo, hi, src in ranges:
        if lo <= addr < hi:
            return src
    return "game"


def parse(path):
    info = {"name": None, "func": None, "size": 0, "addr": None}
    for line in path.read_text().splitlines():
        m = NONMATCH.match(line)
        if m and info["name"] is None:
            info["name"] = m.group(1)
            if m.group(2):
                info["size"] = int(m.group(2), 16)
        m = GLABEL.match(line)
        if m and info["func"] is None:
            info["func"] = m.group(1)
        if info["addr"] is None:
            m = ADDR.search(line)
            if m:
                info["addr"] = int(m.group(1), 16)
    return info


VU_LINE = re.compile(r"^(\s*/\*\s*[0-9A-F]+\s+[0-9A-F]{8}\s+([0-9A-F]{8})\s*\*/\s*)(v[a-z0-9]+(?:\.[xyzw]+)?\s.*)$")


def wordify_vu(path):
    """GNU as cannot encode VU0 macro-mode ops (vaddax ACC, vdiv Q, ...): emit them as .word.

    The comment keeps the original mnemonic. Bytes in splat's comment are in file
    (little-endian) order. Returns the number of rewritten lines.
    """
    text = path.read_text()
    if "$vf" not in text:
        return 0
    n = 0
    out = []
    for line in text.splitlines():
        m = VU_LINE.match(line)
        if m:
            raw = bytes.fromhex(m.group(2))
            word = int.from_bytes(raw, "little")
            out.append(f"{m.group(1)}.word 0x{word:08X} /* {m.group(3).strip()} */")
            n += 1
        else:
            out.append(line)
    path.write_text("\n".join(out) + "\n")
    return n


INSN = re.compile(r"/\*\s*[0-9A-F]+\s+[0-9A-F]{8}\s+[0-9A-F]{8}\s*\*/\s+(\S+)")
FUNC_REF = re.compile(r"\bfunc_[0-9A-F]{8}\b")
ENDERS = ("jr", "j", "jalr", "b", "eret")


def ends_in_jump(path):
    """True/False for code; None for something too short to tell (data in .text)."""
    insns = []
    for line in path.read_text().splitlines():
        if line.lstrip().startswith("endlabel"):
            break
        m = INSN.search(line)
        if m:
            insns.append(m.group(1))
    while len(insns) > 2 and insns[-1] == "nop" and insns[-2] == "nop":
        insns.pop()  # alignment padding
    if len(insns) < 2:
        return None
    return insns[-2] in ENDERS or insns[-1] in ENDERS


FILL_INSN = re.compile(r"/\*\s*[0-9A-F]+\s+[0-9A-F]{8}\s+[0-9A-F]{8}\s*\*/\s+(addiu\s+\$sp, \$sp, 0x[0-9A-F]+|nop)\s*$")


def only_fill(path):
    """Nothing but `addiu $sp, $sp, +N` / `nop` (SN linker leftovers)."""
    lines = [l for l in path.read_text().splitlines() if INSN.search(l)]
    return bool(lines) and all(FILL_INSN.search(l) for l in lines)


def reference_counts():
    """func_X -> number of mentions in other asm files (calls, jumps, pointers in data)."""
    counts = {}
    for p in ASM.rglob("*.s"):
        own = p.stem
        for m in FUNC_REF.findall(p.read_text()):
            if m != own:
                counts[m] = counts.get(m, 0) + 1
    return counts


def main():
    for d in (ASM, BUILD / "splat_src"):
        shutil.rmtree(d, ignore_errors=True)
    r = subprocess.run([sys.executable, "-m", "splat", "split", str(YAML)], cwd=ROOT,
                       capture_output=True, text=True)
    if r.returncode != 0:
        sys.stdout.write(r.stdout[-4000:] + r.stderr[-4000:])
        sys.exit("splat failed")

    ranges = load_lib_ranges()
    funcs = []
    vu = 0
    for p in sorted((ASM / "nonmatchings" / "game").glob("*.s")):
        vu += wordify_vu(p)
        info = parse(p)
        rel = p.relative_to(ROOT).as_posix()
        if info["addr"] is None:
            sys.exit(f"{rel}: no instructions")
        funcs.append({"name": info["func"] or info["name"], "addr": info["addr"], "size": info["size"],
                      "kind": "func" if info["func"] else "data", "asm": rel})
    # Unreferenced fragments that never end (addiu $sp/nop pairs between functions, left
    # by SN's linker) are not functions: kind "fill", never a decomp target, kept as asm.
    refs = reference_counts()
    for f in funcs:
        p = ROOT / f["asm"]
        if f["kind"] == "func" and not refs.get(f["name"]) and (ends_in_jump(p) is False or only_fill(p)):
            f["kind"] = "fill"
    funcs.sort(key=lambda f: f["addr"])
    for a, b in zip(funcs, funcs[1:]):
        if not a["size"]:
            a["size"] = b["addr"] - a["addr"]
        if a["addr"] + a["size"] > b["addr"]:
            sys.exit(f"overlap: {a['name']} runs into {b['name']}")

    with open(FUNCTIONS_CSV, "w", newline="") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(["name", "addr", "size", "source", "kind", "asm"])
        for f in funcs:
            w.writerow([f["name"], f"{f['addr']:08X}", f"0x{f['size']:X}", source_of(f["addr"], ranges),
                        f["kind"], f["asm"]])

    BUILD.mkdir(exist_ok=True)
    STAMP.write_text(inputs_hash() + "\n")
    by = {}
    for f in funcs:
        if f["kind"] != "func":
            continue
        s = source_of(f["addr"], ranges)
        n, b = by.get(s, (0, 0))
        by[s] = (n + 1, b + f["size"])
    print(f"split: {vu} VU0 macro instructions emitted as .word, "
          f"{sum(1 for f in funcs if f['kind'] == 'fill')} unreferenced fill fragments")
    print("split: " + ", ".join(f"{s} {n} functions ({b:,} bytes)" for s, (n, b) in sorted(by.items())))


if __name__ == "__main__":
    main()
