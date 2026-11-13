#!/usr/bin/env python3
"""Target-directed force search: steer SN's cc1plus toward the game's code instead of flipping one tie at a time.

    python tools/oracle_directed.py func_00201488                 # search, print the forces if it matches
    python tools/oracle_directed.py NAME --src work/try.cpp --json out.json --rounds 6 --beam 2

oracle.py's greedy search keeps a single flip only if the differing-word count drops. Many near misses need
several decisions changed together (a schedule where three insns move, or two pseudos that must both go
earlier), and every single flip on the way makes the count worse or no better. This search reads the
answer off the game's code instead:

  * word alignment: every game word is paired with one of our words, exactly (same word, same relocation
    target) where possible, else by shape (same instruction, other registers); our word -> INSN_UID map
    (rtl_dumps) then names, for every game word, the insn of ours that produced it.
  * sched replay (pass 2, and pass 1): per basic block, the game's order of those insns becomes a target order
    {"kind":"sched","pass":P,"block":B,"order":[uids]}. tools/oracle_gdb.py then ranks every cycle's ready
    list of that block by the target order. It only permutes the ready list the compiler built (a hazard
    still queues an insn), so the result is a schedule the compiler could have chosen.
  * directed global alloc: for every pseudo sitting in a register the game does not use there, the
    conflicting pseudo that holds the game's register and was allocated first gives a constraint
    {"kind":"ga","before":[p,q]}; all of them are applied together.
  * beam search over those candidate sets (replace a block's order when it is re-derived, keep the k best
    states by differing words, then by force count), up to N rounds.

A forced match is then minimised: forces whose removal keeps the match are dropped, and every replay order is
rewritten, if possible, as the single-cycle {"clock","first"} picks it overrode (same output, verified).
"""
import argparse
import json
import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
import oracle  # noqa: E402
import rtl_dumps as R  # noqa: E402
from common import ROOT  # noqa: E402


# ------------------------------------------------------------------ words
def _ins(w):
    from rabbitizer import Instruction, InstrCategory
    return Instruction(w, category=InstrCategory.R5900)


def has_slot(w):
    return _ins(w).hasDelaySlot()


def _masked(obj, i):
    w = obj.words[i]
    r = obj.relocs.get(i)
    op = w >> 26
    if op in (2, 3):
        return w & 0xFC000000
    if r is not None or has_slot(w):
        return w & 0xFFFF0000
    return w


def shape(obj, i):
    """Instruction text with registers and relocated fields masked."""
    import match
    t = match.disasm(_masked(obj, i), 0, None)
    return re.sub(r"\$\w+", "R", t)


def same_word(res, i, j, addr):
    import match
    t, o = res.target, res.ours
    tw, ow = t.words[i], o.words[j]
    if (tw >> 26) in (2, 3) or has_slot(tw):
        if (tw >> 26) != (ow >> 26):
            return False
        if (tw >> 26) in (2, 3):
            tr, orr = t.relocs.get(i), o.relocs.get(j)
            return match.reloc_equal(tr, orr, addr + 4 * j, tw, ow) if (tr or orr) else tw == ow
        return (tw >> 16) == (ow >> 16) if not _ins(tw).isJump() else tw == ow
    tr, orr = t.relocs.get(i), o.relocs.get(j)
    if tr or orr:
        return match.reloc_equal(tr, orr, addr + 4 * j, tw, ow)
    return tw == ow


def align(res, addr, how="near"):
    """game word index -> (our word index, 'exact'|'shape'), or None.

    how="near": identical words close by first (a local reorder), then same-shape words (other registers).
    how="seq": a shape-level sequence alignment first (keeps register-only differences in place), then the
    same fallbacks. Neither is right everywhere (two same-shape words swapped vs an identical word elsewhere),
    so the search derives candidates from both."""
    import difflib
    nt, no = len(res.target.words), len(res.ours.words)
    ts = [shape(res.target, i) for i in range(nt)]
    os_ = [shape(res.ours, j) for j in range(no)]
    used, out = set(), [None] * nt

    def kind(i, j):
        return "exact" if same_word(res, i, j, addr) else "shape"

    def fill(test, w):
        for i in range(nt):
            if out[i] is not None:
                continue
            cands = [j for j in range(max(0, i - w), min(no, i + w + 1)) if j not in used and test(i, j)]
            if cands:
                j = min(cands, key=lambda j: (abs(i - j), j))
                used.add(j)
                out[i] = (j, kind(i, j))
    exact = lambda i, j: same_word(res, i, j, addr)      # noqa: E731
    same_shape = lambda i, j: ts[i] == os_[j]           # noqa: E731
    if how == "seq":
        for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ts, os_, autojunk=False).get_opcodes():
            if op == "equal":
                for i, j in zip(range(i1, i2), range(j1, j2)):
                    out[i] = (j, kind(i, j))
                    used.add(j)
    else:
        fill(exact, 8)
    fill(same_shape, 24)
    fill(exact, 96)
    fill(same_shape, 96)
    return out


# ------------------------------------------------------------------ sched replay targets
def natural_orders(ev, pass_):
    """block -> uids in issue order, uid -> block (the last schedule_block of that pass wins)."""
    orders, where = {}, {}
    for e in ev:
        if e["ev"] == "pick" and e["pass_"] == pass_:
            orders.setdefault(e["block"], []).append(e["uid"])
            where[e["uid"]] = e["block"]
    return orders, where


def sched_targets(ev, res, d, al, pass_):
    """block -> target order (uids) for every block whose game order differs from ours."""
    orders, where = natural_orders(ev, pass_)
    wu = d.word_uid or []
    tw = res.target.words
    gseq, seen = [], set()
    for i in range(len(tw)):
        if al[i] is None:
            continue
        j = al[i][0]
        u = wu[j] if j < len(wu) else None
        if u is None or u in seen or u not in where:
            continue
        seen.add(u)
        gseq.append(u)
    # delay slots: a slot insn filled from before its branch (or call) was scheduled before it
    for i in range(len(tw) - 1):
        if not has_slot(tw[i]) or al[i] is None or al[i + 1] is None:
            continue
        b = wu[al[i][0]] if al[i][0] < len(wu) else None
        s = wu[al[i + 1][0]] if al[i + 1][0] < len(wu) else None
        if b is None or s is None or b == s or b not in where or s not in where or where[b] != where[s]:
            continue
        nat = orders[where[b]]
        if nat.index(s) < nat.index(b) and gseq.index(s) > gseq.index(b):
            gseq.remove(s)
            gseq.insert(gseq.index(b), s)
    out = {}
    for blk, nat in orders.items():
        seq = [u for u in gseq if where.get(u) == blk]
        if len(nat) < 2 or len(seq) < 2:
            continue
        res_ = list(seq)
        for k, m in enumerate(nat):
            if m in res_:
                continue
            prev = next((nat[x] for x in range(k - 1, -1, -1) if nat[x] in res_), None)
            res_.insert(res_.index(prev) + 1 if prev is not None else 0, m)
        if res_ != nat:
            out[blk] = res_
    return out


# ------------------------------------------------------------------ directed global alloc
def ga_constraints(ev, res, d, al, ps, insns):
    """[(p, q)]: pseudo p must be allocated before conflicting pseudo q, which holds p's game register."""
    import regalloc_explain as RA
    ga = [e for e in ev if e["ev"] == "ga_order"]
    if not ga:
        return [], {}
    order = ga[-1]["order"]
    pos = {r: k for k, r in enumerate(order)}
    wu = d.word_uid or []
    want = {}
    for i, a in enumerate(al):
        if a is None or a[1] != "shape":
            continue
        j = a[0]
        u = wu[j] if j < len(wu) else None
        ins = insns.get(u)
        if ins is None:
            continue
        import match
        gt, ot = match.disasm(res.target.words[i], 0, None), match.disasm(res.ours.words[j], 0, None)
        gr, orr = re.findall(r"\$\w+", gt), re.findall(r"\$\w+", ot)
        for k, (x, y) in enumerate(zip(orr, gr)):
            if x == y:
                continue
            oh, gh = R.NAME_TO_HARD.get(x), R.NAME_TO_HARD.get(y)
            for rn, hard in RA.operand_regs(ins.pattern, RA.role(res.ours.words[j], k)):
                p = ps.get(rn)
                if hard or p is None:
                    continue
                got = p.final if p.final is not None else p.local
                if got == oh:
                    want.setdefault(rn, Counter())[gh] += 1
    cons = []
    wants = {p: c.most_common(1)[0][0] for p, c in want.items()}
    for p, gh in wants.items():
        if p not in pos:
            continue
        for q in ps[p].conflicts:
            if q in pos and q in ps and ps[q].final == gh and pos[q] < pos[p]:
                cons.append((p, q))
    return cons, wants


# ------------------------------------------------------------------ search
class Search:
    def __init__(self, name, src, wd, log=print, flips=True):
        self.unit = oracle.Unit(name, src, wd)
        import match
        self.addr = match.func_row(name)["addr"]
        self.n = 0
        self.log = log
        self.cache = {}
        self.flips = flips
        traced = self.unit.traced

        def traced_fresh(*a, **k):             # every traced compile rewrites the dumps: keep unit.files current
            out = traced(*a, **k)
            self.refresh_dumps()
            return out
        self.unit.traced = traced_fresh

    def refresh_dumps(self):
        u = self.unit
        for f in u.wd.iterdir():
            m = re.match(r"^u\.(?:cc|c|cpp|ii|i)\.(\w+)$", f.name)
            if m:
                u.files[m.group(1)] = f.read_text(errors="replace")

    def run(self, forces):
        key = json.dumps(forces, sort_keys=True)
        if key in self.cache:
            return self.cache[key]
        self.n += 1
        tag = f"d{self.n}"
        try:
            asm, ev = self.unit.traced(tag, force=forces)
        except (cc.StageError, OSError):
            self.cache[key] = None
            return None
        r = oracle.compare_asm(self.unit, asm, tag)
        out = None if r.error else dict(nd=len(r.diffs), res=r, asm=asm, ev=ev, forces=forces,
                                         errs=sum(1 for e in ev if e.get("ev") == "error"))
        self.cache[key] = out
        return out

    def analyse(self, st, how):
        import regalloc_explain as RA
        d = oracle.word_map(self.unit, st["asm"])
        al = align(st["res"], self.addr, how)
        s2 = sched_targets(st["ev"], st["res"], d, al, 2) if d.word_uid else {}
        s1 = sched_targets(st["ev"], st["res"], d, al, 1) if d.word_uid else {}
        try:
            ps, _, insns, _ = RA.build(d)
            cons, wants = ga_constraints(st["ev"], st["res"], d, al, ps, insns)
        except Exception:  # dumps missing or unparsable: no ga candidates
            cons, wants = [], {}
        return s1, s2, cons

    @staticmethod
    def with_orders(forces, pass_, targets):
        keep = [f for f in forces if not (f.get("kind") == "sched" and f.get("pass") == pass_ and "order" in f
                                          and f["block"] in targets)]
        return keep + [{"kind": "sched", "pass": pass_, "block": b, "order": o} for b, o in sorted(targets.items())]

    @staticmethod
    def with_ga(forces, cons):
        have = {tuple(f["before"]) for f in forces if f.get("kind") == "ga" and "before" in f}
        new = [{"kind": "ga", "before": [p, q]} for p, q in cons if (p, q) not in have]
        # ga forces go first: they act before sched2, and keeping them together keeps the file readable
        return [f for f in forces if f.get("kind") == "ga"] + new + [f for f in forces if f.get("kind") != "ga"]

    def candidates(self, st):
        out = []
        for how in ("near", "seq"):
            for c in self.directed_candidates(st, how):
                if c not in out:
                    out.append(c)
        if self.flips:
            out += [st["forces"] + [f] for f in self.single_flips(st["forces"])]
        return out

    def directed_candidates(self, st, how):
        s1, s2, cons = self.analyse(st, how)
        F = st["forces"]
        out = []
        if s2:
            out.append(self.with_orders(F, 2, s2))
        if s1:
            out.append(self.with_orders(F, 1, s1))
        if s1 and s2:
            out.append(self.with_orders(self.with_orders(F, 1, s1), 2, s2))
        if cons:
            g = self.with_ga(F, cons)
            out.append(g)
            if s2:
                out.append(self.with_orders(g, 2, s2))
            for p, q in cons[:6]:              # and each constraint alone (a set can contradict itself)
                out.append(self.with_ga(F, [(p, q)]))
        return out

    def single_flips(self, F):
        """oracle.py's own candidate flips for this state (each tie or ordering decision it names)."""
        import contextlib
        import io
        a = argparse.Namespace(force=False, trace=False, pass_=None, max_words=60, max_force=0)
        oracle.REC.update(words=[], forces=[], shape=None, ndiff=None, cands=[])
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                oracle.explain(self.unit, a, list(F))
        except (cc.StageError, OSError, SystemExit, ValueError, KeyError):
            return []
        out = []
        for f in oracle.REC.get("cands", []):
            if f not in F and f not in out:
                out.append(f)
        return out[:10]

    def search(self, rounds=5, beam=2, budget=80):
        st = self.run([])
        if st is None:
            return None, None
        self.log(f"   start: {st['nd']} words differ")
        best = st
        frontier = [st]
        seen = {json.dumps([], sort_keys=True)}
        for rnd in range(rounds):
            nxt = []
            for s in frontier:
                for c in self.candidates(s):
                    k = json.dumps(c, sort_keys=True)
                    if k in seen or self.n >= budget:
                        continue
                    seen.add(k)
                    r = self.run(c)
                    if r is None or r["errs"]:
                        continue
                    nxt.append(r)
                    if (r["nd"], len(r["forces"])) < (best["nd"], len(best["forces"])):
                        best = r
                    if r["nd"] == 0:
                        self.log(f"   round {rnd + 1}: MATCH with {len(c)} force(s) ({self.n} compiles)")
                        return r, best
            if not nxt:
                break
            nxt.sort(key=lambda r: (r["nd"], len(r["forces"])))
            frontier = nxt[:beam]
            self.log(f"   round {rnd + 1}: best {frontier[0]['nd']} words ({self.n} compiles)")
        return None, best

    # ---- minimise a match
    def decisions(self, st):
        """Cycles where a replay order changed what the compiler would have issued."""
        out = []
        for e in st["ev"]:
            f = e.get("forced") if e.get("ev") == "ready" else None
            if f and "order_block" in f and f["top"] != f["was"]:
                out.append((e["pass_"], e["block"], e["clock"], f["top"], f["was"]))
        return out

    def drop(self, st):
        """Drop every force whose removal keeps the match."""
        forces = list(st["forces"])
        k = 0
        while k < len(forces) and len(forces) > 1:
            trial = forces[:k] + forces[k + 1:]
            r = self.run(trial)
            if r is not None and r["nd"] == 0 and not r["errs"]:
                forces, st = trial, r
            else:
                k += 1
        return st

    def minimise(self, st):
        st = self.drop(st)
        forces = list(st["forces"])
        # rewrite each replay order as the per-cycle picks it overrode, when that reproduces the match
        for f in [f for f in forces if "order" in f]:
            picks = [x for x in self.decisions(st) if x[0] == f["pass"] and x[1] == f["block"]]
            cyc = []
            for _, _, c, top, was in picks:
                first = top[-1] if len(top) < 2 or top[-2:-1] == was[-2:-1] else [top[-1], top[-2]]
                cyc.append({"kind": "sched", "pass": f["pass"], "block": f["block"], "clock": c, "first": first})
            alt = [g for g in forces if g is not f] + cyc
            r = self.run(alt)
            if r is not None and r["nd"] == 0 and not r["errs"]:
                forces, st = alt, r
        return self.drop(st)


def count_decisions(forces):
    """How tools/concession.py counts a force list against MAX_FORCES: a replay order counts as the number of
    cycles whose pick it overrode (stored in the force as "picks"), every other force as one."""
    return sum(max(1, int(f.get("picks", 1))) if "order" in f else 1 for f in forces)


def directed(name, src, wd, rounds=5, beam=2, budget=80, log=print):
    s = Search(name, src, wd, log=log)
    m, best = s.search(rounds, beam, budget)
    if m is None:
        return None, (best["nd"] if best else None), s.n
    m = s.minimise(m)
    forces = []
    for f in m["forces"]:
        if "order" in f:
            n = sum(1 for x in s.decisions(m) if x[0] == f["pass"] and x[1] == f["block"])
            f = dict(kind="sched", **{"pass": f["pass"]}, block=f["block"], picks=n, order=f["order"])
        forces.append(f)
    return forces, 0, s.n


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--keep")
    ap.add_argument("--rounds", type=int, default=5)
    ap.add_argument("--beam", type=int, default=2)
    ap.add_argument("--budget", type=int, default=80, help="at most this many traced compiles")
    ap.add_argument("--json")
    a = ap.parse_args()
    src = R.find_source(a.name, a.src)
    wd = Path(a.keep) if a.keep else ROOT / "build" / "oracle_directed" / a.name
    forces, nd, n = directed(a.name, src, wd, a.rounds, a.beam, a.budget)
    if forces is not None:
        print(f"{a.name}: forced MATCH with {len(forces)} force line(s), {count_decisions(forces)} decision(s)")
        for f in forces:
            print("   " + json.dumps(f))
    else:
        print(f"{a.name}: no forced match (best {nd} words, {n} compiles)")
    if a.json:
        Path(a.json).write_text(json.dumps(dict(name=a.name, forced_match=forces is not None, final=forces,
                                                best=nd, compiles=n)))


if __name__ == "__main__":
    main()
