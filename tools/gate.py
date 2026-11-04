#!/usr/bin/env python3
"""The match gate: every unit file must match, alone, with no side effects.

    python tools/gate.py              # all of src/funcs (cached per input hash)
    python tools/gate.py --cold       # ignore the cache
    python tools/gate.py FILE...      # just these (still a full check of each)

For each src/funcs/func_X.cpp:
  - it compiles through the pinned pipeline and MATCHes the original
    instruction for instruction, relocations resolved (tools/match.py)
  - its object defines exactly one function in .text (any C++ name) and nothing else
  - it has no data, rodata, literal or linkonce sections with content: globals,
    vtables, strings and jump tables stay in the asm (float literals are pointed
    at the game's own .lit4 constants by tools/cc.py)

Because every merged unit is re-checked whenever a shared input changes
(tools/, include/, config/, toolchain/), a change that breaks an earlier match
fails here: zero regressions by construction.

Output for Steward: "PROBLEM <file>: <why>" and "DIFFLINE <file>: yours | game".
Exit 0 only if everything passes.
"""
import argparse
import hashlib
import json
import os
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
from common import BUILD, ROOT, SRC_FUNCS, UNIT_RE  # noqa: E402

UNIT_FILE = __import__("re").compile(r"^func_[0-9A-F]{8}\.cpp$")

SHARED = ["tools", "include", "config", "toolchain/compiler.toml", "toolchain/checksums.sha256",
          "requirements.txt"]
CACHE = BUILD / "gate_cache.json"
DATA_SECTIONS = (".data", ".sdata", ".bss", ".sbss", ".rodata", ".rdata", ".lit4", ".lit8")
MAX_DIFFLINES = 6


def shared_hash():
    h = hashlib.sha256()
    for s in SHARED:
        p = ROOT / s
        files = sorted(p.rglob("*")) if p.is_dir() else [p]
        for f in files:
            if f.is_file() and "__pycache__" not in f.parts:
                h.update(str(f.relative_to(ROOT)).encode() + b"\0" + f.read_bytes())
    return h.hexdigest()


def check(path):
    """Return (file name, list of problems, list of difflines)."""
    path = Path(path)
    name = path.stem
    if not UNIT_FILE.match(path.name):
        return path.name, ["not a unit file name (func_XXXXXXXX.cpp)"], []
    try:
        row = match.func_row(name)
    except KeyError as e:
        return path.name, [str(e)], []
    res = match.compare(name, path, outdir=BUILD / "gate" / str(os.getpid()))
    if res.error:
        return path.name, [res.error.strip().splitlines()[-1][:300]], []
    problems, lines = [], []
    o = res.ours
    extra = [d for d in o.defined if d != o.func]
    if extra:
        problems.append(f"defines other functions too ({', '.join(extra)}): one function per file")
    for s in DATA_SECTIONS:
        if o.sections.get(s, 0):
            problems.append(f"has its own {s} ({o.sections[s]} bytes): reference data, strings and tables by extern D_ symbol")
    for s, n in o.sections.items():
        if s.startswith(".gnu.linkonce") and n:
            problems.append(f"emits {s} ({n} bytes): an out-of-line inline/template copy; "
                            "make the helper static inline or declare it extern")
    if not res.ok:
        n = len(res.target.words)
        problems.append(f"does not match: {len(res.diffs)} instruction(s) differ ({n} in the original)"
                        + ("" if n == len(o.words) else f" (size {len(o.words) * 4:#x}, game {n * 4:#x})"))
        for i in res.diffs[:MAX_DIFFLINES]:
            a = row["addr"] + i * 4
            yours = match.disasm(o.words[i], a, o.relocs.get(i)) if i < len(o.words) else "-"
            game = match.disasm(res.target.words[i], a, res.target.relocs.get(i)) if i < n else "-"
            lines.append(f"{a:08X} {yours} | {game}")
    return path.name, problems, lines


def check_cxx_symbols():
    """Every include/game/cxx_symbols.txt entry names a real function start or data label, once."""
    import re
    files = sorted((ROOT / "include" / "game").glob("cxx_symbols*.txt"))
    funcs = {r["addr"] for r in match.load_functions()}
    labels = set(match.symbols().values())
    for d in (ROOT / "asm" / "data").glob("*.s"):
        labels.update(int(x, 16) for x in re.findall(r"dlabel D_([0-9A-F]{8})", d.read_text()))
    seen, bad = {}, 0
    lines = [(f.name, n, l) for f in files for n, l in enumerate(f.read_text().splitlines(), 1)]
    from common import all_unit_syms
    lines += [(unit, 0, f"{n} = 0x{a:08X};") for n, a, unit in all_unit_syms()]
    for fname, n, line in lines:
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        m = re.match(r"^([^\s#=]+)\s*=\s*0x([0-9A-Fa-f]{1,8})\s*;\s*(?:#.*)?$", s)
        if not m:
            print(f"PROBLEM {fname}: line {n}: expected '<mangled> = 0xADDR;'")
            bad += 1
            continue
        name, addr = m.group(1), int(m.group(2), 16)
        if name in seen and seen[name] != addr:
            print(f"PROBLEM {fname}: line {n}: {name} is mapped to 0x{seen[name]:08X} elsewhere, 0x{addr:08X} here")
            bad += 1
        seen.setdefault(name, addr)
        if name.startswith(("func_", "D_")):
            print(f"PROBLEM {fname}: line {n}: {name} is not a C++ name")
            bad += 1
        if addr not in funcs and addr not in labels:
            print(f"PROBLEM {fname}: line {n}: 0x{addr:08X} is neither a function start nor a data label")
            bad += 1
    return bad


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("files", nargs="*")
    ap.add_argument("--cold", action="store_true")
    ap.add_argument("-j", type=int, default=os.cpu_count())
    a = ap.parse_args()

    import fresh
    fresh.ensure()

    files = [Path(f) for f in a.files] or sorted(SRC_FUNCS.glob("*.cpp"))
    stray = [f for f in SRC_FUNCS.glob("*") if f.suffix != ".cpp" and f.is_file()]
    sh = shared_hash()
    cache = {}
    if CACHE.exists() and not a.cold:
        c = json.loads(CACHE.read_text())
        if c.get("shared") == sh:
            cache = c.get("ok", {})
    todo, passed = [], []
    for f in files:
        key = hashlib.sha256(f.read_bytes()).hexdigest() if f.exists() else None
        if key and cache.get(f.name) == key:
            passed.append(f.name)
        else:
            todo.append(f)

    bad = check_cxx_symbols()
    for f in stray:
        print(f"PROBLEM {f.name}: only func_XXXXXXXX.cpp files belong in src/funcs")
        bad += 1
    with ProcessPoolExecutor(max_workers=max(1, a.j)) as ex:
        for f, (fname, problems, lines) in zip(todo, ex.map(check, todo)):
            if problems:
                bad += 1
                for p in problems:
                    print(f"PROBLEM {fname}: {p}")
                for l in lines:
                    print(f"DIFFLINE {fname}: {l}")
            else:
                passed.append(fname)
                if f.resolve().parent == SRC_FUNCS.resolve():
                    cache[fname] = hashlib.sha256(f.read_bytes()).hexdigest()

    CACHE.parent.mkdir(parents=True, exist_ok=True)
    CACHE.write_text(json.dumps({"shared": sh, "ok": {k: v for k, v in cache.items() if v}}, indent=0))
    total = len(files)
    print(f"gate: {len(passed)}/{total} unit files match ({len(todo)} checked, "
          f"{total - len(todo)} cached)" + (f", {bad} failing" if bad else ""))
    if bad:
        print("GATE FAIL")
        sys.exit(1)
    print("GATE PASS")


if __name__ == "__main__":
    main()
