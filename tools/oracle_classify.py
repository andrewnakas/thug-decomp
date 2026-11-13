#!/usr/bin/env python3
"""Classify nonmatching units from oracle.py --json summaries (docs/techniques/ORACLE.md, "Classification").

    python tools/oracle.py NAME --force --chain 3 --json work/oracle/cls/NAME.json    (per unit)
    python tools/oracle_classify.py          -> work/oracle/classes.tsv and counts per class

A unit is A only if the forced flip that gained words is itself a reachable tie.

Classes:
  A  reachable tie: a sched luid tie decided at sched1 by luid (or a sched1 luid decision), or a global/local
     allocation tie on allocno/quantity number between pseudos that are not gcse PRE registers.
  B  code shape: the instruction multisets differ (or a word is not a reordering): needs a structural rewrite.
  C  unreachable: PRE-register order tie, priority gap, dependents/reg-weight/busy key, a sched2 order fixed in
     sched1 by reg weight or dependence, find_reg/reload choices, reorg fills.
  E  oracle error / no data.
"""
import csv
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def fuzzy_of(name):
    p = os.path.join(ROOT, "src/nonmatching", name + ".cpp")
    try:
        m = re.search(r"/\* fuzzy: ([0-9.]+) \*/", open(p).read(4000))
        return float(m.group(1)) if m else None
    except OSError:
        return None


def decision_class(w):
    k = w["kind"]
    if k in ("ga", "la"):
        if w.get("tie") and not w.get("pre"):
            return "A", f"{k} order tie {w['p']}/{w['q']}"
        if w.get("tie"):
            return "C", f"{k} PRE-reg tie {w['p']}/{w['q']}"
        return "C", f"{k} priority gap {w['p']}/{w['q']}"
    if k == "sched":
        key, s1, ps = w.get("key"), w.get("s1"), w.get("pass_")
        if ps == 1:
            if key == "luid?":
                return "A", f"sched1 luid tie {w['uid']}/{w['ug']}"
            return "C", f"sched1 {key} {w['uid']}/{w['ug']}"
        if key == "luid?" and s1 in ("luid?",):
            return "A", f"sched2 luid tie (sched1 luid) {w['uid']}/{w['ug']}"
        if key == "luid?" and s1 is None:
            return "C", f"sched2 luid tie, order fixed by sched1 dependence {w['uid']}/{w['ug']}"
        if key == "luid?":
            return "C", f"sched2 luid tie, sched1 {s1} {w['uid']}/{w['ug']}"
        return "C", f"sched2 {key} {w['uid']}/{w['ug']}"
    if k == "sched_dep":
        return "C", f"dependence order {w['uid']}/{w['ug']}"
    if k == "shape_word":
        return "B", "not a reordering"
    if k == "findreg":
        return "C", f"find_reg choice {w['p']}"
    if k == "reload":
        return "C", "reload/hard reg"
    if k == "reorg":
        return "C", "reorg fill"
    return "C", k


def force_record(f, words):
    """The decision record a force was generated from."""
    for w in words:
        if f.get("kind") == "sched" and w["kind"] == "sched" and w.get("ug") == f.get("first") \
                and w.get("pass_") == f.get("pass"):
            return w
        if f.get("kind") in ("ga", "la") and w["kind"] == f["kind"]:
            pair = f.get("before") or f.get("swap") or []
            if set(pair) == {w.get("p"), w.get("q")}:
                return w
    return None


def gaining_class(d, r0):
    """Class of the first-round flip that gained words: A only if that flip is itself a reachable tie."""
    gains = [x for x in r0.get("forces", []) if x.get("nd") is not None and x["nd"] < (r0.get("ndiff") or 0)]
    if not gains:
        return None
    best = min(gains, key=lambda x: x["nd"])
    w = force_record(best["force"], r0.get("words", []))
    if w is None:
        return "C", f"gaining flip without a named record: {best['desc']}"
    c, why = decision_class(w)
    if c == "A":
        return "A", why + f" (forcing it: {r0['ndiff']}->{best['nd']})"
    return "C", why + f" (the gaining flip, {r0['ndiff']}->{best['nd']})"


def main():
    rows = []
    for f in sorted(glob.glob(os.path.join(ROOT, "work/oracle/cls/*.json"))):
        name = os.path.basename(f)[:-5]
        try:
            d = json.load(open(f))
        except ValueError:
            continue
        r0 = d["rounds"][0] if d["rounds"] else {}
        nwords = r0.get("nwords") or 0
        nd0 = r0.get("ndiff")
        best = min([r["best"][0] for r in d["rounds"] if r.get("best")] + ([nd0] if nd0 is not None else []),
                   default=None)
        forced = "MATCH" if d.get("forced_match") else (f"{nd0}->{best}" if best is not None and best < (nd0 or 0)
                                                       else "no gain")
        if nd0 is None:
            cls, why = "E", "no data"
        elif nd0 == 0:
            cls, why = "M", "already matches"
        else:
            decs = [decision_class(w) for w in r0.get("words", [])]
            if r0.get("shape") and not d.get("forced_match"):
                cls, why = "B", "code shape (instruction multisets differ)"
                a = [x for x in decs if x[0] == "A"]
                if a:
                    why += "; also " + a[0][1]
            elif gaining_class(d, r0) is not None:
                cls, why = gaining_class(d, r0)
            elif any(c == "A" for c, _ in decs) and not d["rounds"][0].get("best"):
                cls, why = "C", "tie named but forcing it gains nothing: " + next(w for c, w in decs if c == "A")
            elif d.get("forced_match"):
                kinds = ",".join(sorted({f.get("kind") for f in d.get("final", [])}))
                cls, why = "C", f"forced MATCH via {kinds}; " + next((w for c, w in decs if c == "C"), "no named decision")
            elif any(c == "B" for c, _ in decs):
                cls, why = "B", next(w for c, w in decs if c == "B")
            elif decs:
                cls, why = "C", decs[0][1]
            else:
                cls, why = "C", "no named decision"
        rows.append(dict(unit=name, size=nwords * 4, fuzzy=fuzzy_of(name), cls=cls, decision=why, forced=forced,
                         ndiff=nd0))
    out = os.path.join(ROOT, "work/oracle/classes.tsv")
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()), delimiter="\t")
        w.writeheader()
        w.writerows(rows)
    from collections import defaultdict
    agg = defaultdict(lambda: [0, 0, 0.0, 0])
    for r in rows:
        a = agg[r["cls"]]
        a[0] += 1
        a[1] += r["size"]
        if r["fuzzy"] is not None:
            a[2] += r["size"] * (100 - r["fuzzy"]) / 100
        a[3] += r["forced"] == "MATCH"
    print("class units bytes gap_bytes(size*(100-fuzzy)) forced_MATCH")
    for c in sorted(agg):
        n, b, g, m = agg[c]
        print(f"{c}  {n:4d}  {b:8d}  {g:9.0f}  {m}")


if __name__ == "__main__":
    main()
