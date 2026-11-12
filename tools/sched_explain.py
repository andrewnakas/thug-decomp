#!/usr/bin/env python3
"""Explain the instruction scheduler's choices for one unit, cycle by cycle.

    python tools/sched_explain.py func_002C0730                     # blocks around the first differences
    python tools/sched_explain.py func_002C0730 --pass 2 --block 5  # one block of sched2
    python tools/sched_explain.py func_002C0730 --why 96 125        # which key orders insn 96 before 125
    python tools/sched_explain.py func_002C0730 --all               # every block
    python tools/sched_explain.py NAME --src work/try.cpp --keep work/dumps/NAME

The unit is compiled with the pinned cflags plus its own /* cflags: */ and -dS -dR -dp
-fsched-verbose-5 (dump files in a private build/ directory, or --keep DIR). The haifa
scheduler's verbose trace gives, per basic block, the dependence table and the sorted ready list
of every cycle; this tool recomputes gcc 2.95's rank_for_schedule keys for every candidate:

    1. priority     INSN_PRIORITY, the critical path to the block end (higher first)
    2. reg weight   INSN_REG_WEIGHT, registers born minus REG_DEAD/REG_UNUSED notes (sched1 only;
                    lower first). The notes are the ones sched1 sees, read from the .regmove dump
                    (-dN); insns split inside sched1 fall back to the .sched dump.
    3. dep class    relation to the last scheduled insn: 3 independent, or dependent with
                    insn_cost 1; 1 a true dependence on a multi-cycle insn (a load, a mult...);
                    2 an anti/output dependence costing more than 1. insn_cost never returns
                    less than 1 and mips' ADJUST_COST makes anti/output links free, so on this
                    target they count as class 3 (checked against the dumps). Higher first.
    4. dependents   length of INSN_DEPEND, insns waiting on it (more first)
    5. luid         original order in the block (earlier first)

and checks its order against the order the compiler printed ("model check", "!! model
differs"). Within a cycle the R5900 issues up to two insns: the scheduler walks the sorted list
best first, skips an insn whose unit is busy this cycle (actual_hazard 1), queues one with a
longer hazard, and stops after a jump.

Accuracy, measured on 16 nonmatching units (~6800 adjacent ready-list pairs): sched2 agrees with
the dump everywhere; sched1 on ~99%. The rest are priority inversions in sched1 (a lower-priority
insn printed ahead, mostly float/TImode-heavy blocks) that the five keys do not explain; the tool
marks those cycles with "!!" and the dump order is what the compiler did.

Insn numbers are INSN_UIDs, as printed in the dumps and by `-dp` ("# 123 movsi..." in the .s).
Words are mapped to uids by assembling the compiler output with a label after every insn.

Interblock regions (several blocks per region) also compare "in-block before interblock",
speculativeness and probability; this build schedules one block per region at -O2, so those
keys are only reported, not modelled.
"""
import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rtl_dumps as R  # noqa: E402

KEYS = ["priority", "reg weight", "dep class", "dependents", "luid"]


@dataclass
class Row:
    uid: int
    code: int
    bb: int
    dep: int
    prio: int
    cost: int
    unit: str
    succ: list
    group: bool
    luid: int


@dataclass
class Cycle:
    t: int
    ready: list                   # best first (the dump prints worst first)
    last: int                     # last scheduled insn when the list was sorted
    issued: list = field(default_factory=list)
    queued: dict = field(default_factory=dict)


@dataclass
class Block:
    bb: int
    head: int
    end: int
    after_reload: bool
    rows: dict = field(default_factory=dict)
    cycles: list = field(default_factory=list)
    desc: dict = field(default_factory=dict)
    total: int = 0
    rgn_blocks: int = 1


TABLE_RE = re.compile(r"^;;\s+(\+)?\s*(\d+)\s+(-?\d+)\s+(\d+)\s+(\d+)\s+(-?\d+)\s+(-?\d+)\s+\d+\s*-\s*\d+\s+(.*?)\t?:\s*(.*)$")
BB_RE = re.compile(r"^;;\s+-- basic block (\d+) from (\d+) to (\d+) -- (before|after) reload")
READY_RE = re.compile(r"^;;\tReady list \(t =\s*(\d+)\):\s*(.*)$")
ISSUE_RE = re.compile(r"--> scheduling insn <<<(\d+)>>>")
QUEUE_RE = re.compile(r"Ready-->Q: insn (\d+): queued for (\d+) cycles")
RGN_RE = re.compile(r"^;;\trgn (\d+) nr_blocks (\d+):")
VIS_RE = re.compile(r"^;;\s+(\d+)\s{2,}(.*)$")
VIS_ITEM_RE = re.compile(r"(?:^|\s)(\d+)\s+((?:\S| (?=\S))+)")


def parse_sched(text):
    blocks, cur, in_vis, nblocks = [], None, False, {}
    rgn_size = []
    for line in text.splitlines():
        m = RGN_RE.match(line)
        if m:
            rgn_size.append(int(m.group(2)))
            continue
        m = BB_RE.match(line)
        if m:
            cur = Block(int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4) == "after")
            blocks.append(cur)
            in_vis = False
            continue
        if cur is None:
            continue
        if "scheduling visualization" in line:
            in_vis = True
            continue
        m = re.match(r"^;;\s+total time = (\d+)", line)
        if m:
            cur.total = int(m.group(1))
            in_vis = False
            continue
        if in_vis:
            m = VIS_RE.match(line)
            if m:
                for mm in VIS_ITEM_RE.finditer(m.group(2)):
                    cur.desc[int(mm.group(1))] = mm.group(2)
            continue
        m = TABLE_RE.match(line)
        if m and not cur.cycles:
            uid = int(m.group(2))
            cur.rows[uid] = Row(uid, int(m.group(3)), int(m.group(4)), int(m.group(5)), int(m.group(6)),
                                int(m.group(7)), m.group(8).strip(), [int(x) for x in m.group(9).split()],
                                bool(m.group(1)), len(cur.rows))
            continue
        m = READY_RE.match(line)
        if m:
            last = None
            for c in reversed(cur.cycles):
                if c.issued:
                    last = c.issued[-1]
                    break
            lst = [int(x) for x in m.group(2).split()]
            cur.cycles.append(Cycle(int(m.group(1)), list(reversed(lst)), last))
            continue
        m = ISSUE_RE.search(line)
        if m and cur.cycles:
            cur.cycles[-1].issued.append(int(m.group(1)))
            continue
        m = QUEUE_RE.search(line)
        if m and cur.cycles:
            uid = int(m.group(1))
            if uid in cur.cycles[-1].ready and uid not in cur.cycles[-1].issued:
                cur.cycles[-1].queued[uid] = int(m.group(2))
    if rgn_size and max(rgn_size) > 1:
        for b in blocks:
            b.rgn_blocks = max(rgn_size)
    return blocks


# ---------------------------------------------------------------- rank_for_schedule

def reg_weight(insn):
    """find_insn_reg_weight: +1 per register SET/CLOBBER destination, -1 per REG_DEAD/REG_UNUSED note."""
    if insn is None:
        return None
    w = 0
    pat = insn.pattern
    elts = pat[1:] if R.head(pat) == "parallel" else [pat]
    if R.head(pat) == "parallel" and len(elts) == 1 and isinstance(elts[0], list) and \
            elts[0] and isinstance(elts[0][0], list):
        elts = elts[0]           # parallel[ ... ] vector
    for x in elts:
        if R.head(x) in ("set", "clobber") and len(x) > 1:
            dest = x[1]
            while R.head(dest) == "subreg":
                dest = dest[1]
            if R.reg_of(dest) or R.head(dest) == "scratch":
                w += 1
    for kind, _ in insn.notes:
        if kind in ("REG_DEAD", "REG_UNUSED"):
            w -= 1
    return w


class Ranker:
    def __init__(self, block, insns, weights_from, pass_no):
        self.b = block
        self.insns = insns            # RTL of this pass's dump (LOG_LINKS with dependence kinds)
        self.wsrc = weights_from      # RTL the weights come from (sched1: the regmove dump)
        self.pass_no = pass_no

    def dep_class(self, uid, last):
        """rank_for_schedule's class relative to the last scheduled insn:
        3 independent, or dependent with insn_cost == 1; 2 anti/output dep costing more than 1;
        1 true dep costing more than 1. insn_cost never returns less than 1: a link that
        ADJUST_COST makes free (mips: every anti/output dep) or whose user is a USE/CLOBBER
        (INSN_CODE < 0) costs exactly 1, so on this target class 2 never occurs in practice."""
        if last is None or last not in self.b.rows or uid not in self.b.rows[last].succ:
            return 3, "indep"
        kind = ""
        ins = self.insns.get(uid)
        if ins is not None:
            for u, k in ins.links:
                if u == last:
                    kind = k
                    break
        cost = self.b.rows[last].cost
        if self.b.rows[uid].code < 0 or kind:
            cost = 1
        if cost == 1:
            return 3, ("1-cycle" if not kind else kind.lower())
        return (1, "true") if not kind else (2, kind.lower())

    def weight(self, uid):
        if self.pass_no != 1:
            return 0
        ins = self.wsrc.get(uid) or self.insns.get(uid)
        w = reg_weight(ins)
        return w if w is not None else 0

    def keys(self, uid, last):
        r = self.b.rows[uid]
        cls, why = self.dep_class(uid, last)
        return {"priority": r.prio, "reg weight": self.weight(uid), "dep class": cls, "dep why": why,
                "dependents": len(r.succ), "luid": r.luid}

    def sort_key(self, uid, last):
        k = self.keys(uid, last)
        return (-k["priority"], k["reg weight"], -k["dep class"], -k["dependents"], k["luid"])

    def first_diff(self, a, b, last):
        """The first key on which a and b differ: (key, a value, b value, winner)."""
        ka, kb = self.keys(a, last), self.keys(b, last)
        order = [("priority", 1), ("reg weight", -1), ("dep class", 1), ("dependents", 1), ("luid", -1)]
        for name, sign in order:
            if name == "reg weight" and self.pass_no != 1:
                continue
            if ka[name] != kb[name]:
                win = a if (ka[name] - kb[name]) * sign > 0 else b
                return name, ka[name], kb[name], win
        return None, None, None, None


# ---------------------------------------------------------------- output

def describe(block, insns, uid, width=34):
    s = block.desc.get(uid)
    if not s and uid in insns:
        s = rtl_short(insns[uid].pattern)
    return (s or "")[:width]


def rtl_short(e, depth=0):
    if isinstance(e, str):
        return e
    if not e:
        return ""
    r = R.reg_of(e)
    if r:
        return (R.hard_name(r[0]) if r[1] else f"r{r[0]}")
    h = R.head(e)
    if h == "set":
        return f"{rtl_short(e[1])}={rtl_short(e[2])}"
    if h == "const_int":
        return e[1]
    if h == "mem":
        return f"[{rtl_short(e[1])}]"
    if h == "plus":
        return f"{rtl_short(e[1])}+{rtl_short(e[2])}"
    if depth > 3:
        return h or "?"
    if h is None:                      # a vector: parallel[ ... ]
        return ";".join(rtl_short(x, depth + 1) for x in e)
    return f"{h}(" + ",".join(rtl_short(x, depth + 1) for x in e[1:] if isinstance(x, list)) + ")"


def show_block(block, ranker, insns, pass_no, words_note=None):
    rows = block.rows
    print(f"\n=== sched{pass_no} basic block {block.bb} (insns {block.head}..{block.end}, "
          f"{len(rows)} scheduled, {block.total} cycles) ===")
    if block.rgn_blocks > 1:
        print("   note: interblock region; in-block/speculative/probability keys are not modelled")
    print("   dependence table (luid = original order):")
    print("     luid  uid  prio cost dependents  unit     insn")
    for r in sorted(rows.values(), key=lambda r: r.luid):
        w = ranker.weight(r.uid)
        wt = f" w{w:+d}" if pass_no == 1 else ""
        print(f"     {r.luid:>4} {('+' if r.group else ' ')}{r.uid:<5} {r.prio:>3} {r.cost:>4}   "
              f"{len(r.succ):>2} {str(r.succ[:6])[1:-1]:<22} {r.unit:<7}{wt}  {describe(block, insns, r.uid)}")
    disagree = 0
    for c in block.cycles:
        model = sorted(c.ready, key=lambda u: ranker.sort_key(u, c.last)) if all(u in rows for u in c.ready) \
            else c.ready
        agree = model == c.ready
        disagree += not agree
        if len(c.ready) == 1 and agree:
            print(f"   t={c.t:<3} {c.ready[0]:<5} only candidate"
                  + (f"  -> issued" if c.ready[0] in c.issued else "")
                  + f"   {describe(block, insns, c.ready[0])}")
            continue
        print(f"   t={c.t:<3} last scheduled: {c.last if c.last is not None else '-'}   "
              f"ready list best first{'' if agree else '   !! model differs: dump ' + ' '.join(map(str, c.ready)) + ' / model ' + ' '.join(map(str, model))}")
        hdr = "        uid   prio" + (" wt" if pass_no == 1 else "") + " cls deps luid  status        why below the one above (this vs above)"
        print(hdr)
        prev = None
        last_issued_pos = max((c.ready.index(u) for u in c.issued if u in c.ready), default=-1)
        for i, u in enumerate(c.ready):
            if u not in rows:
                print(f"        {u:<5} (not in this block's table)")
                continue
            k = ranker.keys(u, c.last)
            if u in c.issued:
                st = "ISSUED"
            elif u in c.queued:
                st = f"queued {c.queued[u]}"
            elif i < last_issued_pos:
                st = "unit busy"
            else:
                st = "waits"
            why = ""
            if prev is not None:
                key, va, vb, win = ranker.first_diff(prev, u, c.last)
                if key:
                    why = f"{key} {vb} vs {va}" + (" (model disagrees)" if win != prev else "")
            wt = f" {k['reg weight']:>+3d}" if pass_no == 1 else ""
            cls = f"{k['dep class']}{'' if k['dep why'] in ('indep',) else ':' + k['dep why'][:4]}"
            print(f"        {u:<5} {k['priority']:>4}{wt} {cls:<6}{k['dependents']:>2} {k['luid']:>4}  {st:<13} "
                  f"{why:<26} {describe(block, insns, u, 30)}")
            prev = u
    print(f"   model check: {len(block.cycles) - disagree}/{len(block.cycles)} cycles ordered as the dump"
          + ("" if not disagree else "  (!! some keys are not modelled exactly; trust the dump order)"))


def explain_why(blocks, rankers, insns_by_pass, a, b):
    found = False
    for pass_no, blist in blocks.items():
        for blk in blist:
            if a not in blk.rows or b not in blk.rows:
                continue
            found = True
            rk = rankers[pass_no][blk.bb]
            print(f"\nsched{pass_no} block {blk.bb}:")
            both = [c for c in blk.cycles if a in c.ready and b in c.ready]
            when = {}
            for c in blk.cycles:
                for u in (a, b):
                    if u in c.ready and u not in when:
                        when[u] = c.t
            issued = {u: c.t for c in blk.cycles for u in c.issued}
            if not both:
                print(f"   never in the ready list together: {a} ready t={when.get(a)} issued t={issued.get(a)}, "
                      f"{b} ready t={when.get(b)} issued t={issued.get(b)}.")
                dep = "depends on" if a in deps_closure(blk, b) else ("is depended on by" if b in deps_closure(blk, a)
                                                                       else "is independent of")
                print(f"   {b} {dep} {a} (dependences/latency decide this order, not rank_for_schedule)")
                continue
            c = both[0]
            key, va, vb, win = rk.first_diff(a, b, c.last)
            ka, kb = rk.keys(a, c.last), rk.keys(b, c.last)
            print(f"   first together at t={c.t} (last scheduled {c.last}):")
            for k in KEYS:
                if k == "reg weight" and pass_no != 1:
                    continue
                extra = ""
                if k == "dep class":
                    extra = f"   ({ka['dep why']} / {kb['dep why']})"
                print(f"     {k:<11} {a}: {ka[k]:<6} {b}: {kb[k]:<6}{extra}{'   <-- decides' if k == key else ''}")
            if key:
                lose = b if win == a else a
                vw, vl = (va, vb) if win == a else (vb, va)
                print(f"   => {win} goes before {lose}: {key} ({win}: {vw} vs {lose}: {vl})"
                      + ("" if c.ready.index(win) < c.ready.index(lose) else "   !! but the dump has the other order"))
                if key == "luid":
                    print("      (a pure source-order tie: swap the two statements in the source to swap them here)")
            print(f"   issued: {a} at t={issued.get(a)}, {b} at t={issued.get(b)}")
    if not found:
        print(f"insns {a} and {b} are not in one scheduled block (see the tables; uids come from -dp/the dumps)")


def deps_closure(blk, uid):
    seen, todo = set(), [uid]
    pred = {}
    for r in blk.rows.values():
        for s in r.succ:
            pred.setdefault(s, []).append(r.uid)
    while todo:
        u = todo.pop()
        for p in pred.get(u, []):
            if p not in seen:
                seen.add(p)
                todo.append(p)
    return seen


def show_words(d, res, blocks_focus, addr):
    """Game vs ours around the focused blocks (word index -> insn uid via -dp labels)."""
    if not d.word_uid or res is None or res.target is None:
        return
    from match import disasm
    uids = set()
    for blk in blocks_focus:
        uids |= set(blk.rows)
    idx = [i for i, u in enumerate(d.word_uid) if u in uids]
    if not idx:
        return
    lo, hi = min(idx), max(idx)
    print(f"\n   words {lo}..{hi} (game | ours, our insn uid):")
    for i in range(lo, hi + 1):
        tw = res.target.words[i] if i < len(res.target.words) else None
        ow = res.ours.words[i] if i < len(res.ours.words) else None
        l = disasm(tw, addr + 4 * i, None) if tw is not None else ""
        r = disasm(ow, addr + 4 * i, None) if ow is not None else ""
        mark = "!!" if i in res.diffs else "  "
        print(f"   {mark} {addr + 4 * i:08X} {l:<34} | {r:<34} {d.word_uid[i] if d.word_uid[i] is not None else ''}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--pass", dest="pass_no", type=int, choices=[1, 2],
                    help="sched1 (before reload) or sched2 (after); default both")
    ap.add_argument("--block", type=int, action="append", help="basic block number (repeatable)")
    ap.add_argument("--why", nargs=2, type=int, metavar=("UID1", "UID2"))
    ap.add_argument("--all", action="store_true", help="every block, not only those around differences")
    ap.add_argument("--keep", help="keep the dumps in this directory (under work/ or build/)")
    ap.add_argument("--verbose", type=int, default=5, help=argparse.SUPPRESS)
    a = ap.parse_args()

    src = R.find_source(a.name, a.src)
    d = R.compile_with_dumps(a.name, src, ["-dN", "-dS", "-dR", f"-fsched-verbose-{a.verbose}"], keep=a.keep)
    passes = [a.pass_no] if a.pass_no else [1, 2]
    regmove = R.parse_insns(R.pick_function(d.files.get("regmove", "")))
    blocks, insns_by_pass, rankers = {}, {}, {}
    for p in passes:
        suf = "sched" if p == 1 else "sched2"
        if suf not in d.files:
            print(f"no .{suf} dump (is scheduling disabled by the unit's cflags?)")
            continue
        text = R.pick_function(d.files[suf])
        blocks[p] = parse_sched(text)
        insns_by_pass[p] = R.parse_insns(text)
        rankers[p] = {b.bb: Ranker(b, insns_by_pass[p], regmove, p) for b in blocks[p]}

    res, addr = None, None
    try:
        import match
        res = match.compare(a.name, str(src), outdir=str(d.workdir.parent / "explain_match"))
        addr = match.func_row(a.name)["addr"]
        if res.error:
            print(f"(match: {res.error.splitlines()[0]})")
            res = None
    except Exception as e:    # the explanation does not need the diff
        print(f"(no diff against the game: {e})")
        res = None
    if res is not None:
        state = "MATCH" if res.ok else f"{len(res.diffs)} of {len(res.target.words)} words differ"
        print(f"{a.name}: {state}" + ("" if not d.map_note else f"   ({d.map_note})"))
        if d.words and not R.same_code(d.words, res.ours.words):
            print("   !! the dump compile differs from match.py's object: word->insn map not trusted")
            d.word_uid = None

    if a.why:
        explain_why(blocks, rankers, insns_by_pass, *a.why)
        return

    focus_uids = set()
    if res is not None and not res.ok and d.word_uid:
        first = res.diffs[0]
        span = [i for i in res.diffs if i < first + 8]
        for i in span:
            if i < len(d.word_uid) and d.word_uid[i] is not None:
                focus_uids.add(d.word_uid[i])
        print(f"first difference at word {first} ({addr + 4 * first:08X}); our insns there: "
              f"{' '.join(map(str, sorted(focus_uids))) or '?'}")
    for p, blist in blocks.items():
        sel = []
        for b in blist:
            if a.block is not None:
                if b.bb in a.block:
                    sel.append(b)
            elif a.all or not focus_uids or (set(b.rows) & focus_uids):
                sel.append(b)
        for b in sel:
            show_block(b, rankers[p][b.bb], insns_by_pass[p], p)
        if p == passes[-1] and res is not None and sel:
            show_words(d, res, sel, addr)
    if not any(blocks.values()):
        print("no scheduled blocks found")


if __name__ == "__main__":
    main()
