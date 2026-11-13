#!/usr/bin/env python3
"""Is the residue a loop.c threshold decision? Sweep `-mvu0-use-vf0-vfN` and name the loop decision it moves.

    python tools/loopknob.py func_00230D88                 # src/funcs or src/nonmatching unit
    python tools/loopknob.py func_00230D88 --src work/try.cpp
    python tools/loopknob.py func_00230D88 --range 1-8 -j2
    python tools/loopknob.py func_00230D88 --at 2          # skip the sweep, explain N=2 only

Why this works (docs/techniques/LAST_MILE.md 1.1): Sony's `-mvu0-use-vf0-vfN` adds VU0 registers to
`n_non_fixed_regs`, and gcc 2.95.3 loop.c scales two thresholds by that number:
    scan_loop / move_movables:  hoist an invariant when  threshold * savings * lifetime >= insn_count,
                                threshold = (loop has a call ? 1 : 2) * (1 + n_non_fixed_regs)
    strength_reduce:            reduce a giv when its benefit, scaled by (call ? 1 : 2) * (3 + n_non_fixed_regs),
                                beats the loop's insn count ("giv of insn U not worth while, B vs K")
So the flag moves exactly these decisions and nothing else (it changes no code outside loops). When some N
gives a match or a big drop, the residue is one of these decisions: the C shape of the loop (its size, the
invariant's lifetime, how many times a variable is set) sits on the other side of the threshold.

What it prints:
 1. differing words (and fuzzy) for N = none, 1 .. 31 (default range 1-31; the knob is not monotonic);
 2. for the best N, the loop.c decisions that differ between no flag and N, read from the `.loop` dumps (-dL)
    of both compiles: hoisted invariants (movables), reduced or combined givs, eliminated bivs, and each loop's
    insn count, with the source line of each insn (taken from the -g line notes of the pre-loop `.gcse` dump);
 3. a one-line hint toward a C shape that crosses the same threshold without the flag.

It is a diagnostic. `-mvu0-use-vf0-vf2` is an allowed per-file flag, but ship it only when the unit's matched
neighbours all still match with it (MATCHING_GUIDE "Per-file flags need neighbour evidence"); any other N is not
allowed. A unit's own vu0 flag is stripped (in a copy under work/loopknob/) so "none" really means none.
"""
import argparse
import re
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import rtl_dumps  # noqa: E402
from common import ROOT, compiler_config, file_cflags  # noqa: E402

VU0 = re.compile(r"\s*-mvu0-use-vf0-vf\d+")
CFLAGS_LINE = re.compile(r"^/\*\s*cflags:(.*)\*/\s*$")


def stripped_copy(src, outdir):
    """A copy of the unit without its own -mvu0-use-vf0-vfN (same line numbers)."""
    text = Path(src).read_text()
    first, _, rest = text.partition("\n")
    m = CFLAGS_LINE.match(first)
    if not m or not VU0.search(m.group(1)):
        return Path(src), None
    flags = VU0.sub("", m.group(1)).strip()
    # keep a first line so that line numbers stay the same
    new_first = f"/* cflags: {flags} */" if flags else "/* (vu0 flag stripped by loopknob) */"
    outdir.mkdir(parents=True, exist_ok=True)
    cp = outdir / Path(src).name
    cp.write_text(new_first + "\n" + rest)
    own = VU0.search(m.group(1)).group(0).strip()
    return cp, own


def knob_flags(n):
    return [] if n == 0 else [f"-mvu0-use-vf0-vf{n}"]


def label(n):
    return "none" if n == 0 else str(n)


def score(name, src, n, outdir):
    cfg = compiler_config()
    cflags = list(cfg["compiler"]["cflags"]) + knob_flags(n)
    r = match.compare(name, str(src), None, cflags, str(outdir / f"n{n}"))
    if r.error:
        return n, None, None, r.error.splitlines()[0][:80]
    return n, (0 if r.ok else len(r.diffs)), match.fuzzy(r), ""


# ------------------------------------------------------------------ dumps

LOOP_RE = re.compile(r"^Loop from (\d+) to (\d+): (\d+) real insns\.")
MOV_RE = re.compile(r"^Insn (\d+): regno (\d+) \(life (\d+)\), (.*)$")
GIV_RE = re.compile(r"^Insn (\d+): (?:giv reg (\d+)|dest address) src reg (\d+) benefit (\d+) lifetime (\d+)")
NOTWORTH_RE = re.compile(r"^giv of insn (\d+) not worth while, (-?\d+) vs (\d+)\.")
REDUCED_RE = re.compile(r"^giv at (\d+) reduced to")
COMBINED_RE = re.compile(r"^giv at (\d+) combined with giv at (\d+)")
BIV_ELIM_RE = re.compile(r"^biv (\d+) can be eliminated")
BIV_NOELIM_RE = re.compile(r"^Cannot eliminate biv (\d+)")
RTL_HEAD = re.compile(r"^\((insn|jump_insn|call_insn|note|code_label|barrier)\s+(\d+)\s")
LINE_NOTE = re.compile(r"^\(note \d+ \d+ \d+ \(\"[^\"]*\"\) (\d+)\)")
REGNUM = re.compile(r"\((reg(?:/[a-z])*):([A-Z]+) (\d+)(?: [a-z0-9]+)?\)")


def rtl_insns(text, calls):
    """uid -> (source line, compact pattern) for every insn printed in a dump; call insn uids go to `calls`."""
    out, line, cur = {}, None, None

    def flush():
        if cur:
            kind, uid, body = cur
            out[uid] = (line, compact(body))

    for raw in text.splitlines():
        m = LINE_NOTE.match(raw)
        if m:
            flush()
            cur = None
            line = int(m.group(1))
            continue
        m = RTL_HEAD.match(raw)
        if m:
            flush()
            cur = (m.group(1), int(m.group(2)), [raw]) if m.group(1) in ("insn", "jump_insn", "call_insn") else None
            if m.group(1) == "call_insn":
                calls.add(int(m.group(2)))
            continue
        if cur and raw.startswith(" "):
            cur[2].append(raw)
    flush()
    return out


def compact(lines):
    s = " ".join(x.strip() for x in lines)
    m = re.search(r"\(set (.*)", s)
    if m:
        s = "(set " + m.group(1)
    s = re.sub(r"\s+\d+ \{[^}]*\}.*$", "", s)        # insn code, notes
    s = re.sub(r"\s+-1 \(nil\).*$", "", s)
    s = re.sub(r" \[0x[0-9a-f]+\]", "", s)
    s = REGNUM.sub(lambda m: f"r{m.group(3)}", s)
    s = re.sub(r"\(const_int (-?\d+)\)", r"\1", s)
    return s[:110]


def norm_rtx(s):
    """Pseudo numbers shift between the two compiles once a decision differs: drop them for keys."""
    return re.sub(r"r\d+", "r", s)


def parse_loop_dump(text):
    """[(pass, loop ordinal, loop dict)] with every decision; pass 2 is rerun-loop-opt."""
    loops, seen, npass, cur = [], set(), 1, None
    for raw in text.splitlines():
        m = LOOP_RE.match(raw)
        if m:
            start = int(m.group(1))
            if start in seen:
                npass += 1
                seen = set()
            seen.add(start)
            cur = dict(start=start, end=int(m.group(2)), count=int(m.group(3)), npass=npass,
                       ordinal=len(seen), mov={}, giv={}, givs_found={}, biv={})
            loops.append(cur)
            continue
        if cur is None:
            continue
        m = MOV_RE.match(raw)
        if m:
            uid, regno, life, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4)
            if "possible biv" in rest:
                continue
            sv = re.search(r"savings (\d+)", rest)
            if "moved to" in rest:
                verdict = "hoisted"
            elif "not desirable" in rest:
                verdict = "kept in loop (not desirable)"
            elif "matches" in rest:
                verdict = "merged with an equal movable"
            else:
                verdict = re.sub(r"\d+", "#", rest.strip())
            cur["mov"][uid] = dict(regno=regno, life=life, savings=int(sv.group(1)) if sv else None,
                                   verdict=verdict, raw=rest.strip())
            continue
        m = GIV_RE.match(raw)
        if m:
            cur["givs_found"][int(m.group(1))] = dict(benefit=int(m.group(4)), lifetime=int(m.group(5)))
            continue
        m = NOTWORTH_RE.match(raw)
        if m:
            cur["giv"][int(m.group(1))] = dict(verdict="not reduced (not worth while)",
                                               detail=f"{m.group(2)} vs {m.group(3)}")
            continue
        m = REDUCED_RE.match(raw)
        if m:
            cur["giv"].setdefault(int(m.group(1)), dict(verdict="reduced", detail=""))
            continue
        m = COMBINED_RE.match(raw)
        if m:
            cur["giv"][int(m.group(1))] = dict(verdict="combined", detail=f"into giv at {m.group(2)}",
                                               into=int(m.group(2)))
            continue
        m = BIV_ELIM_RE.match(raw)
        if m:
            cur["biv"][int(m.group(1))] = "eliminated"
            continue
        m = BIV_NOELIM_RE.match(raw)
        if m:
            cur["biv"][int(m.group(1))] = "kept"
    return loops


class Side:
    def __init__(self, name, src, n, keep):
        flags = ["-g", "-ds", "-dG", "-dL"] + knob_flags(n)
        d = rtl_dumps.compile_with_dumps(name, src, flags, keep=str(keep), map_words=False)
        self.loop_text = d.files.get("loop", "")
        self.calls = set()
        self.pre = rtl_insns(d.files.get("gcse") or d.files.get("cse", ""), self.calls)  # pre-loop RTL
        self.post = rtl_insns(self.loop_text, self.calls)            # after both loop passes
        self.loops = parse_loop_dump(self.loop_text)
        # the first uid loop.c created: anything >= it may be numbered differently in the other compile
        self.first_new = max(self.pre) + 1 if self.pre else 1 << 30

    def desc(self, uid):
        return self.pre.get(uid) or self.post.get(uid) or (None, f"insn {uid}")

    def key(self, uid):
        """A key for an insn that is the same in both compiles."""
        if uid < self.first_new:
            return ("uid", uid)
        line, rtx = self.desc(uid)
        return ("new", line, norm_rtx(rtx))

    def has_call(self, lp):
        return any(lp["start"] <= u <= lp["end"] for u in self.calls)

    def loop_lines(self, lp):
        ls = [ln for u, (ln, _) in self.pre.items() if lp["start"] <= u <= lp["end"] and ln]
        if not ls and lp["start"] >= self.first_new:
            ls = [ln for u, (ln, _) in self.post.items() if lp["start"] <= u <= lp["end"] and ln]
        return (min(ls), max(ls)) if ls else None


def loop_key(side, lp):
    return (lp["npass"], side.key(lp["start"]))


def decisions(side):
    """{(loop key, kind, insn key): (verdict, detail, uid, loop)}"""
    out = {}
    for lp in side.loops:
        lk = loop_key(side, lp)
        for uid, mv in lp["mov"].items():
            out[(lk, "mov", side.key(uid))] = (mv["verdict"], f"savings {mv['savings']} x life {mv['life']}",
                                               uid, lp, (mv["savings"] or 0) * mv["life"])
        for uid, gv in lp["giv"].items():
            out[(lk, "giv", side.key(uid))] = (gv["verdict"], gv["detail"], uid, lp)
        for reg, v in lp["biv"].items():
            out[(lk, "biv", ("reg", reg) if reg < 1000 else ("reg?",))] = (v, "", None, lp)
    return out


def explain(name, src, n, outdir, src_lines):
    base = Side(name, src, 0, outdir / "dump_none")
    knob = Side(name, src, n, outdir / f"dump_{n}")
    print(f"\nloop.c decisions that differ, no flag -> N={n} (pass 1 = loop, pass 2 = rerun-loop-opt;"
          " * = changes the end result):")
    # loop sizes
    bl = {loop_key(base, lp): lp for lp in base.loops}
    kl = {loop_key(knob, lp): lp for lp in knob.loops}
    for k in sorted(set(bl) | set(kl), key=lambda k: (k[0], str(k[1]))):
        a, b = bl.get(k), kl.get(k)
        lp = a or b
        rng = (base if a else knob).loop_lines(lp)
        where = f"lines {rng[0]}-{rng[1]}" if rng else f"uids {lp['start']}-{lp['end']}"
        ca, cb = (a["count"] if a else "-"), (b["count"] if b else "-")
        mark = "  " if ca == cb else "!!"
        print(f"  {mark} pass {lp['npass']} loop {where}: {ca} -> {cb} insns")
    da, db = decisions(base), decisions(knob)
    flips = []
    for k in sorted(set(da) | set(db), key=lambda k: (k[0][0], str(k[0][1]), k[1], str(k[2]))):
        a, b = da.get(k), db.get(k)
        va = a[0] if a else "(not considered)"
        vb = b[0] if b else "(not considered)"
        if va == vb:
            continue
        side, uid, lp = (base, a[2], a[3]) if a else (knob, b[2], b[3])
        if k[1] == "biv":
            line, rtx = None, f"biv reg {k[2][1] if len(k[2]) > 1 else '?'}"
        else:
            line, rtx = side.desc(uid)
        flips.append(dict(kind=k[1], before=va, after=vb, line=line, rtx=rtx, npass=lp["npass"], n=n, key=k,
                          call=side.has_call(lp), sl=(a or b)[4] if k[1] == "mov" else None,
                          detail_a=a[1] if a else "", detail_b=b[1] if b else "", loop=lp,
                          lines=side.loop_lines(lp)))
    # net effect over both passes: an invariant hoisted in pass 1 with the flag and in pass 2 without it ends
    # up hoisted either way (only the timing differs, which can still change the pass-2 loop's insn count)
    def net(dec, key):
        vs = [v[0] for k, v in dec.items() if k[1] == key[1] and k[2] == key[2] and k[0][1] == key[0][1]]
        if key[1] == "mov":
            return "hoisted" if "hoisted" in vs else "kept"
        return vs[-1] if vs else "(not considered)"

    for f in flips:
        f["net"] = net(da, f["key"]) != net(db, f["key"])
    if not flips:
        print("  (no movable/giv/biv decision differs: the knob moved something else, e.g. only an insn count)")
    for f in flips:
        src_txt = src_lines[f["line"] - 1].strip() if f["line"] and f["line"] <= len(src_lines) else ""
        kind = {"mov": "invariant", "giv": "giv", "biv": "biv"}[f["kind"]]
        det = f["detail_a"] or f["detail_b"]
        if f["detail_a"] and f["detail_b"] and f["detail_a"] != f["detail_b"]:
            det = f"{f['detail_a']} -> {f['detail_b']}"
        same = "" if f["net"] else "   (same in the end: only the pass differs)"
        print(f"  {'*' if f['net'] else ' '} pass {f['npass']} {kind:9} line {f['line'] or '?':>4}: "
              f"{f['before']} -> {f['after']}   [{det}]{same}")
        print(f"       {f['rtx']}")
        if src_txt:
            print(f"       | {src_txt}")
    return flips


def hint(flips, lines_of_loop=None):
    """One short hint toward a C shape that crosses the same threshold without the flag."""
    if not flips:
        return ("no loop.c decision moved: compare the loops' insn counts above, or this N changes something "
                "outside loop.c (rare); try diffmap --knob")
    # the first flip that changes the end result (marked *) is the one to reproduce in C
    f = sorted(flips, key=lambda f: (not f.get("net", True), f["npass"], f["kind"] != "mov"))[0]
    rng = f["lines"]
    where = f"the loop at lines {rng[0]}-{rng[1]}" if rng else "its loop"
    at = f"line {f['line']}" if f["line"] else "?"
    later = " (second loop pass: the first pass shrank the loop; -fno-rerun-loop-opt is also an allowed flag)" \
        if f["npass"] > 1 else ""
    if f["kind"] == "mov" and f["after"] == "hoisted":
        # the threshold grows by (call ? 1 : 2) per step of N (vf1 already differs from no flag); the bound is rough,
        # because move_movables also weighs what it already moved in the same loop
        steps = (1 if f["call"] else 2) * f["n"]
        cnt = f["loop"]["count"]
        margin = "a few insns" if steps * max(f["sl"] or 1, 1) <= 4 else "many insns"
        return (f"the game hoists the invariant of {at} out of {where}{later}. Without the flag it misses the "
                f"threshold ({f['detail_a']}, loop {'with' if f['call'] else 'without'} a call, {cnt} insns; "
                f"N={f['n']} raises the threshold by {steps} step(s), so the loop is about {margin} too big). "
                "Make the loop smaller (move work out of "
                "the body; write a late exit as `return` instead of `break` so its code leaves the loop), or "
                "compute the value before the loop yourself (declare the variable with the other locals and "
                "assign it before the `for`).")
    if f["kind"] == "mov" and f["before"] == "hoisted":
        return (f"the game keeps the invariant of {at} inside {where}{later}. Make it fail the threshold "
                "without the flag: a bigger loop body (a late exit as `break` keeps its code in the loop), "
                "assign the variable at the top of the body instead of before the loop (a second set marks "
                "it may_not_optimize), or a union-typed local initialiser where the type really is a union.")
    if f["kind"] == "giv":
        if "reduced" == f["after"] or f["after"] == "combined":
            what = "strength-reduces (pointer increment)"
        else:
            what = "does not strength-reduce"
        return (f"the game {what} the address/index computation of {at} in {where}{later}. Change the giv's "
                "benefit or order: a `T *p = &arr[i];` local at the top of the body instead of `arr[i]` at each "
                "use (or the reverse), or repeat the full index expression at each use.")
    return (f"bivs differ in {where}: the loop counter is {f['after']} with the flag. Try a count-down loop "
            "(`while (k--)`) or a pointer-compare loop end.")


def parse_range(s):
    out = []
    for part in s.split(","):
        a, _, b = part.partition("-")
        out += list(range(int(a), int(b or a) + 1))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--range", default="1-31", help="values of N to sweep (default 1-31; 'none' is always run)")
    ap.add_argument("--at", type=int, help="skip the sweep and explain this N")
    ap.add_argument("-j", type=int, default=2, help="parallel compiles (default 2)")
    ap.add_argument("--outdir", default=None, help="work directory (default work/loopknob/NAME)")
    a = ap.parse_args()

    src = rtl_dumps.find_source(a.name, a.src)
    outdir = Path(a.outdir) if a.outdir else ROOT / "work" / "loopknob" / a.name
    outdir.mkdir(parents=True, exist_ok=True)
    src2, own = stripped_copy(src, outdir / "src")
    print(f"{a.name}: {src}" + (f"  (own flag {own} stripped for the sweep)" if own else ""))
    others = [f for f in file_cflags(src2)]
    if others:
        print(f"  unit flags kept: {' '.join(others)}")

    if a.at is not None:
        best = a.at
        res = {0: score(a.name, src2, 0, outdir), best: score(a.name, src2, best, outdir)}
    else:
        ns = [0] + [n for n in parse_range(a.range) if n > 0]
        with ProcessPoolExecutor(max(1, a.j)) as ex:   # processes: match.compare is not thread-safe
            res = {r[0]: r for r in ex.map(score, [a.name] * len(ns), [src2] * len(ns), ns, [outdir] * len(ns))}
    print("differing words per -mvu0-use-vf0-vfN:")
    row = []
    for n in sorted(res):
        _, d, fz, err = res[n]
        row.append(f"{label(n)}:{'ERR' if d is None else ('MATCH' if d == 0 else d)}")
    for k in range(0, len(row), 11):
        print("  " + "  ".join(row[k:k + 11]))
    ok = {n: r for n, r in res.items() if r[1] is not None}
    if 0 not in ok:
        sys.exit(f"{a.name}: the unit does not compile: {res[0][3]}")
    base_d, base_f = ok[0][1], ok[0][2]
    if a.at is None:
        best = min(ok, key=lambda n: (ok[n][1], -ok[n][2], n))
    bd, bf = ok[best][1], ok[best][2]
    if best == 0 or bd >= base_d:
        print(f"best: none ({base_d} words, fuzzy {base_f:.1f}). The loop.c thresholds do not own this residue.")
        return
    same = sorted(n for n in ok if ok[n][1] == bd)
    print(f"best: N={best} ({'MATCH' if bd == 0 else f'{bd} words'}, fuzzy {bf:.1f}), no flag {base_d} words "
          f"(fuzzy {base_f:.1f}); same result at N in {{{','.join(map(str, same))}}}")
    if best == 2 or 2 in same:
        print("  N=2 is an allowed per-file flag: ship it only if the matched neighbours all still match with it.")
    src_lines = Path(src2).read_text(errors="replace").splitlines()
    flips = explain(a.name, src2, best, outdir, src_lines)
    print("\nhint: " + hint(flips))


if __name__ == "__main__":
    main()
