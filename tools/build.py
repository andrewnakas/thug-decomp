#!/usr/bin/env python3
"""The build gate: link everything and require a byte-identical SLUS_207.31.

    python tools/build.py

Runs fresh (re-split if stale), configure.py, then ninja. On a mismatch it
runs first_diff.py so the report names the function that broke the image.
"""
import json
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fresh  # noqa: E402
from common import ROOT, tool  # noqa: E402


def main():
    if len(sys.argv) > 1:   # it takes no options: never start a full build on a mistyped flag
        sys.exit(__doc__.strip() if sys.argv[1] in ("-h", "--help") else f"build.py takes no arguments, got {sys.argv[1:]}")
    fresh.ensure()
    py = sys.executable
    subprocess.run([py, "configure.py"], cwd=ROOT, check=True)
    r = subprocess.run([py, "-m", "ninja", "-k", "0"], cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    if r.returncode != 0:
        tail = "\n".join(l for l in out.splitlines() if not l.startswith("[")) or out
        print(tail[-3000:], flush=True)
        grown = []
        lines = (ROOT / "build" / "link.ld").read_text().splitlines()
        for n in re.findall(r"link\.ld:(\d+) cannot move location counter backwards", out):
            prev = lines[int(n) - 2] if int(n) >= 2 else ""
            m = re.search(r"(func_[0-9A-F]{8})\.(?:cpp|s)\.o", prev)
            grown.append(m.group(1) if m else prev.strip())
        if grown:
            for g in grown:
                print(f"PROBLEM {g}.cpp: compiles larger than the original and runs into the next object")
        elif "MISMATCH" in out:
            subprocess.run([py, "tools/first_diff.py"], cwd=ROOT)
            print("PROBLEM SLUS_207.31: linked image differs from the original (see first_diff above)")
        else:
            print("PROBLEM SLUS_207.31: build failed before the sha1 check (compile or link error above)")
        print("BUILD FAIL")
        sys.exit(1)
    print(next((l for l in out.splitlines() if "SLUS_207.31:" in l), "SLUS_207.31: OK"))
    if not objdiff_agrees():
        print("BUILD FAIL")
        sys.exit(1)
    print("BUILD PASS")


def map_symbols():
    """A C++ unit defines a mangled name; tell objdiff it pairs with the target's func_X."""
    import match
    cfg_path = ROOT / "objdiff.json"
    cfg = json.loads(cfg_path.read_text())
    for u in cfg["units"]:
        if u.get("base_path"):
            o = match.read_obj(ROOT / u["base_path"], 0)
            u["symbol_mappings"] = {u["name"]: o.func}
    cfg_path.write_text(json.dumps(cfg, indent=1) + "\n")


def objdiff_agrees():
    """Second opinion: objdiff must also see every unit file as a 100% match."""
    py = sys.executable
    r = subprocess.run([py, "-m", "ninja", "objdiff"], cwd=ROOT, capture_output=True, text=True)
    map_symbols()
    out = ROOT / "build" / "report" / "objdiff_check.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    r2 = subprocess.run([tool("objdiff-cli"), "report", "generate", "-o", str(out)], cwd=ROOT,
                        capture_output=True, text=True)
    if r.returncode or r2.returncode:
        print("PROBLEM objdiff: could not build or run the objdiff check:\n" + (r.stdout + r2.stderr)[-1500:])
        return False
    ok = True
    for u in json.loads(out.read_text())["units"]:
        if u.get("metadata", {}).get("complete"):
            for f in u.get("functions", []):
                if f.get("fuzzy_match_percent", 0) < 100.0:
                    print(f"PROBLEM {f['name']}.cpp: objdiff scores it {f.get('fuzzy_match_percent', 0):.2f}%")
                    ok = False
    if ok:
        print("objdiff: every unit file is a 100% match")
    return ok


if __name__ == "__main__":
    main()
