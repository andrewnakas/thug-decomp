#!/usr/bin/env python3
"""Concession tier: C++ that matches the game exactly once a few recorded compiler decisions are forced.

    python tools/concession.py func_00213DF8                 # verify src/concession/func_00213DF8.cpp
    python tools/concession.py --find func_00213DF8          # search forces for the src/nonmatching unit
    python tools/concession.py --find func_00213DF8 --write  # ... and move it to src/concession/ on a match
    python tools/concession.py --find --directed func_X      # target-directed search (tools/oracle_directed.py)
    python tools/concession.py --all                         # verify every src/concession unit

A src/concession/func_X.cpp unit follows every src/funcs rule (scan.py applies), plus one header line per
forced decision, in the JSON form tools/oracle.py --with takes:

    /* force: {"kind": "sched", "pass": 2, "block": 21, "clock": 1, "first": 137} */

Each force is a tie-break or ordering decision inside SN's own cc1plus.exe (global-alloc order, a ready-list
pick, a local-alloc quantity order, reload's spill-slot order, the register find_reg / find_free_reg picks among
those its own checks accept, the thread fill_eager_delay_slots tries first, a gcse copy/constant propagation or
PRE deletion declined through the failure path the pass already handles) that the source has not been found to
reach. tools/oracle.py proves the
unit's residue is only that decision: compiled under gdb with exactly these forces, the output is the game's
code, byte for byte (relocations resolved). Without them it is not (else the unit belongs in src/funcs/).

Concession units are never linked (the build keeps the game's asm, as for src/nonmatching), so the normal
build never needs gdb. Progress reports count them separately from concession-free matches; the headline
number stays concession-free. See docs/techniques/ORACLE.md, "Concession tier".
"""
import argparse
import json
import os
import re
import shutil
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BUILD, FUZZY_RE, ROOT, SRC_CONCESSION, SRC_FUNCS, SRC_NONMATCHING  # noqa: E402

FORCE_RE = re.compile(r"/\*\s*force:\s*(\{.*?\})\s*\*/")
MAX_FORCES = 8
FORCE_KINDS = {"ga", "la", "sched", "spill", "fr", "lfr", "reorg", "cprop"}   # "pre" is an oracle diagnostic only: no identity check yet


def unit_forces(path):
    """[(force dict)] from the unit's `/* force: {...} */` lines, in order. Raises ValueError on bad JSON."""
    out = []
    for m in FORCE_RE.finditer(Path(path).read_text(errors="replace")):
        out.append(json.loads(m.group(1)))
    return out


def count_decisions(forces):
    """What MAX_FORCES limits: every force line is one decision, except
      * a sched replay order ({"kind":"sched","order":[...],"picks":N}): the N ready-list picks it overrides;
      * a spill-slot order ({"kind":"spill","order":[p1..pN]}): N - 1 (the choices that fix an order of N).
    reorg ({"kind":"reorg","uid":B,"pred":P}), cprop ({"kind":"cprop","reg":R,"uid":U,...}) and pre
    ({"kind":"pre","uid":U} or {"kind":"pre","expr":E,"pass":K}) lines are one decision each: one branch's
    thread order, one propagation into one insn, one PRE deletion (or PRE leaving one expression alone)."""
    def one(f):
        if f.get("kind") == "spill":
            return max(1, len(f.get("order", [])) - 1)
        if "order" in f:
            return max(1, int(f.get("picks", 1)))
        return 1
    return sum(one(f) for f in forces)


def replay_picks(events):
    """(pass, block) -> number of cycles in which a replay order changed the top of the ready list."""
    out = {}
    for e in events:
        f = e.get("forced") if e.get("ev") == "ready" else None
        if f and "order_block" in f and f["top"] != f["was"]:
            k = (e["pass_"], e["block"])
            out[k] = out.get(k, 0) + 1
    return out


def force_line(f):
    return "/* force: " + json.dumps(f, separators=(", ", ": ")) + " */"


def verify(name, path, wd=None):
    """Return (problems, info). info has 'forced' (differing words with the forces) and 'plain' (without)."""
    import cc
    import match
    import oracle
    path = Path(path)
    problems, info = [], {}
    if shutil.which("gdb") is None:
        return ["gdb is not on PATH: the concession gate replays forces under gdb"], info
    try:
        forces = unit_forces(path)
    except ValueError as e:
        return [f"a /* force: */ line is not valid JSON: {e}"], info
    if not forces:
        problems.append("no /* force: {...} */ lines: a unit that needs none belongs in src/funcs/")
    if count_decisions(forces) > MAX_FORCES:
        problems.append(f"{count_decisions(forces)} forced decisions, more than the {MAX_FORCES} allowed")
    if any("order" in f and f.get("kind") != "spill" and (f.get("kind") != "sched"
                                                          or not isinstance(f.get("picks"), int)) for f in forces):
        problems.append('a replay order must be {"kind": "sched", "pass": P, "block": B, "picks": N, "order": [...]}')
    bad = [f for f in forces if f.get("kind") not in FORCE_KINDS]
    if bad:
        problems.append(f"force kind(s) {sorted({str(f.get('kind')) for f in bad})} not allowed "
                        f"(allowed: {', '.join(sorted(FORCE_KINDS))})")
    if FUZZY_RE.search(path.read_text(errors="replace")):
        problems.append("a concession unit has no /* fuzzy: */ line (it matches under its forces)")
    if (SRC_FUNCS / path.name).exists():
        problems.append("this function is matched in src/funcs: delete the src/concession copy")
    if problems:
        return problems, info
    wd = Path(wd or BUILD / "concession" / str(os.getpid()) / name)
    try:
        plain = match.compare(name, str(path), outdir=str(wd / "plain"))
        if plain.error:
            return [plain.error.strip().splitlines()[-1][:300]], info
        info["plain"] = len(plain.diffs)
        if plain.ok:
            return ["it matches exactly without its forces: move it to src/funcs/ and drop the force lines"], info
        unit = oracle.Unit(name, path, wd / "oracle")
        text, ev = unit.traced("gate", force=forces)
        errs = [e for e in ev if e.get("ev") == "error"]
        res = oracle.compare_asm(unit, text, "gate")
    except (cc.StageError, OSError, KeyError) as e:
        return [f"forced compile failed: {str(e).strip().splitlines()[-1][:300]}"], info
    if res.error:
        return [res.error.strip().splitlines()[-1][:300]], info
    info["forced"] = len(res.diffs)
    if errs:
        problems.append(f"the oracle reported {len(errs)} hook error(s) (first: {errs[0]})")
    measured = replay_picks(ev)
    for f in forces:
        if f.get("kind") == "sched" and "order" in f and measured.get((f["pass"], f["block"]), 0) != f["picks"]:
            problems.append(f"replay order for pass {f['pass']} block {f['block']} declares {f['picks']} pick(s), "
                            f"the compile overrode {measured.get((f['pass'], f['block']), 0)}")
    if not res.ok:
        problems.append(f"does not match under its {len(forces)} forced decision(s): {len(res.diffs)} "
                        f"instruction(s) still differ ({len(plain.diffs)} without them)")
    return problems, info


def find(name, src, chain, max_force, out_json):
    """Run the oracle's greedy force search; return the force list if it reaches a byte-exact match."""
    import subprocess
    cmd = [sys.executable, str(ROOT / "tools" / "oracle.py"), name, "--src", str(src), "--force",
           "--chain", str(chain), "--max-force", str(max_force), "--json", str(out_json),
           "--keep", str(BUILD / "oracle" / name)]
    p = subprocess.run(cmd, capture_output=True, text=True)
    if not Path(out_json).exists():
        print(p.stdout[-2000:] + p.stderr[-2000:])
        return None
    d = json.loads(Path(out_json).read_text())
    return d["final"] if d.get("forced_match") else None


def find_directed(name, src, out_json):
    """tools/oracle_directed.py's target-directed beam search; the force list on a match, else None."""
    import oracle_directed
    wd = BUILD / "oracle_directed" / name
    forces, best, n = oracle_directed.directed(name, src, wd, log=lambda *_: None)
    Path(out_json).write_text(json.dumps(dict(name=name, forced_match=forces is not None, final=forces,
                                              best=best, compiles=n)))
    shutil.rmtree(wd, ignore_errors=True)
    return forces


def write_unit(name, src, forces):
    """src/nonmatching/func_X.cpp -> src/concession/func_X.cpp with force lines, fuzzy line dropped."""
    lines = Path(src).read_text().splitlines(keepends=True)
    keep = [l for l in lines if not FUZZY_RE.fullmatch(l.strip())]
    keep = [FUZZY_RE.sub("", l) if FUZZY_RE.search(l) else l for l in keep]
    head = 1 if keep and keep[0].startswith("/* cflags:") else 0
    block = [force_line(f) + "\n" for f in forces]
    out = keep[:head] + block + keep[head:]
    dst = SRC_CONCESSION / f"{name}.cpp"
    dst.parent.mkdir(parents=True, exist_ok=True)
    dst.write_text("".join(out))
    return dst


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*")
    ap.add_argument("--all", action="store_true", help="verify every src/concession unit")
    ap.add_argument("--find", action="store_true", help="search forces for the src/nonmatching unit")
    ap.add_argument("--write", action="store_true", help="with --find: move a matching unit to src/concession/")
    ap.add_argument("--directed", action="store_true",
                    help="with --find: target-directed beam search (sched replay, directed global alloc)")
    ap.add_argument("--chain", type=int, default=4)
    ap.add_argument("--max-force", type=int, default=10)
    a = ap.parse_args()
    names = [n.removesuffix(".cpp").split("/")[-1] for n in a.names]
    if a.all:
        names += sorted(p.stem for p in SRC_CONCESSION.glob("func_*.cpp"))
    if not names:
        ap.error("name a unit, or --all")
    bad = 0
    for name in names:
        if a.find:
            src = SRC_NONMATCHING / f"{name}.cpp"
            if not src.exists():
                print(f"{name}: no src/nonmatching unit")
                bad += 1
                continue
            out = BUILD / "concession" / f"{name}.json"
            out.parent.mkdir(parents=True, exist_ok=True)
            forces = find_directed(name, src, out) if a.directed else find(name, src, a.chain, a.max_force, out)
            if not forces:
                print(f"{name}: no forced match" + ("" if a.directed else f" within {a.chain} round(s)"))
                bad += 1
                continue
            if count_decisions(forces) > MAX_FORCES:
                print(f"{name}: forced match needs {count_decisions(forces)} decisions (> {MAX_FORCES})")
                bad += 1
                continue
            print(f"{name}: forced MATCH with {count_decisions(forces)} decision(s): {json.dumps(forces)}")
            if not a.write:
                continue
            dst = write_unit(name, src, forces)
            problems, info = verify(name, dst)
            if problems:
                dst.unlink()
                print(f"{name}: written unit failed verification: {'; '.join(problems)}")
                bad += 1
                continue
            src.unlink()
            print(f"{name}: moved to {dst.relative_to(ROOT)} (plain {info['plain']} words differ, forced 0)")
        else:
            path = SRC_CONCESSION / f"{name}.cpp"
            if not path.exists():
                print(f"{name}: no src/concession unit")
                bad += 1
                continue
            problems, info = verify(name, path)
            if problems:
                bad += 1
                for p in problems:
                    print(f"PROBLEM concession/{path.name}: {p}")
            else:
                print(f"{name}: MATCH under {count_decisions(unit_forces(path))} forced decision(s) "
                      f"({info['plain']} words differ without them)")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
