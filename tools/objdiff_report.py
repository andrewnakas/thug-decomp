#!/usr/bin/env python3
"""Write an objdiff report.json (report version 2) without the disc, for ByteMatch.

    python tools/objdiff_report.py [-o build/report/SLUS_207.31/report.json]

Inputs are only committed files: config/functions.us.csv and src/funcs/.
Every merged unit passed tools/gate.py and tools/build.py on the judge box, so
each counts as a 100% match. Each function is its own unit with a source_path,
so ByteMatch can link to the C++. Only game code is counted: Sony SDK, OpenSSL,
GameSpy and libgcc code stays asm. Adapted from thps64 and Thrasher.
"""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import FUZZY_RE, ROOT, SRC_CONCESSION, SRC_FUNCS, SRC_NONMATCHING, load_functions  # noqa: E402

REPORT_VERSION = 2
VERSION = "SLUS_207.31"


def pct(a, b):
    return 100.0 * a / b if b else 0.0


def measures(funcs, matched, units, complete_units=0, fuzzy=None):
    fuzzy = fuzzy or {}
    total = sum(f["size"] for f in funcs)
    done = sum(f["size"] for f in funcs if f["name"] in matched)
    mf = sum(1 for f in funcs if f["name"] in matched)
    near = sum(f["size"] * fuzzy.get(f["name"], 0.0) / 100.0 for f in funcs if f["name"] not in matched)
    return {
        "fuzzy_match_percent": pct(done + near, total), "total_code": str(total),
        "matched_code": str(done), "matched_code_percent": pct(done, total),
        "total_data": "0", "matched_data": "0", "matched_data_percent": 0.0,
        "total_functions": len(funcs), "matched_functions": mf,
        "matched_functions_percent": pct(mf, len(funcs)),
        "complete_code": str(done), "complete_code_percent": pct(done, total),
        "complete_data": "0", "complete_data_percent": 0.0,
        "total_units": units, "complete_units": complete_units,
    }


def report(funcs, matched, fuzzy=None, concession=frozenset()):
    fuzzy = fuzzy or {}
    units = []
    for f in funcs:
        ok = f["name"] in matched
        fz = 100.0 if ok else fuzzy.get(f["name"], 0.0)
        meta = {"complete": ok, "progress_categories": ["game"]}
        if ok:
            meta["source_path"] = f"src/funcs/{f['name']}.cpp"
        elif f["name"] in concession:
            meta["source_path"] = f"src/concession/{f['name']}.cpp"
        elif f["name"] in fuzzy:
            meta["source_path"] = f"src/nonmatching/{f['name']}.cpp"
        units.append({
            "name": f"funcs/{f['name']}",
            "measures": measures([f], matched, 1, int(ok), fuzzy),
            "sections": [{"name": ".text", "size": str(f["size"]),
                          "fuzzy_match_percent": fz,
                          "metadata": {"virtual_address": str(f["addr"])}}],
            "functions": [{"name": f["name"], "size": str(f["size"]),
                           "fuzzy_match_percent": fz,
                           "metadata": {"virtual_address": str(f["addr"])}, "address": "0"}],
            "metadata": meta,
        })
    m = measures(funcs, matched, len(units), sum(1 for f in funcs if f["name"] in matched), fuzzy)
    return {"measures": m, "units": units, "version": REPORT_VERSION,
            "categories": [{"id": "game", "name": "Game", "measures": m}]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", default=str(ROOT / "build" / "report" / VERSION / "report.json"))
    a = ap.parse_args()
    funcs = [f for f in load_functions() if f["source"] == "game" and f["kind"] == "func"]
    matched = {p.stem for p in SRC_FUNCS.glob("func_*.cpp")} & {f["name"] for f in funcs}
    # scores of src/nonmatching units: gate.py verified each stated value on the judge before it merged
    fuzzy = {}
    for p in SRC_NONMATCHING.glob("func_*.cpp"):
        m = FUZZY_RE.search(p.read_text(errors="replace"))
        if m and p.stem not in matched:
            fuzzy[p.stem] = min(float(m.group(1)), 99.9)
    # src/concession units match exactly under recorded forced compiler decisions (gate.py replays them). They
    # are not concession-free matches, so they count only toward fuzzy, at 99.9, never toward matched_code.
    names = {f["name"] for f in funcs}
    concession = {p.stem for p in SRC_CONCESSION.glob("func_*.cpp")} & names - matched
    for n in concession:
        fuzzy[n] = 99.9
    rep = report(funcs, matched, fuzzy, concession)
    sizes = {f["name"]: f["size"] for f in funcs}
    with_conc = sum(sizes[n] for n in matched | concession)
    rep["concession"] = {"functions": len(concession), "code": str(sum(sizes[n] for n in concession)),
                         "matched_with_concessions_percent": 100.0 * with_conc / sum(sizes.values())}
    out = Path(a.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(rep, separators=(",", ":")) + "\n")
    m = rep["measures"]
    print(f"{out.relative_to(ROOT) if out.is_relative_to(ROOT) else out}: "
          f"{m['matched_functions']}/{m['total_functions']} functions, "
          f"{m['matched_code']}/{m['total_code']} bytes ({m['matched_code_percent']:.3f}%), "
          f"with concessions {rep['concession']['matched_with_concessions_percent']:.3f}% "
          f"({len(concession)} units), "
          f"fuzzy {m['fuzzy_match_percent']:.3f}% ({len(fuzzy) - len(concession)} non-matching units)")


if __name__ == "__main__":
    main()
