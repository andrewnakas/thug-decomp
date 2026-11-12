#!/usr/bin/env python3
"""Explain the register allocation of one unit: which pseudo got which hard register, and why.

    python tools/regalloc_explain.py func_00271D80
    python tools/regalloc_explain.py func_00271D80 --src work/try.cpp --keep work/dumps/x
    python tools/regalloc_explain.py func_00271D80 --pseudo 167      # one pseudo in detail

The unit is compiled with the pinned cflags plus its own /* cflags: */ and -dl -dg -dp (dumps in a
private build/ directory, or --keep DIR), and three things are printed:

1. Global allocation (global.c), in the order find_reg tried the pseudos. gcc 2.95 sorts the
   allocnos by
        priority = floor_log2(refs) * refs / live_length * 10000 * size     (truncated to int)
   highest first, ties by pseudo number. refs is REG_N_REFS (each use counts loop_depth, so a
   reference inside a loop weighs more), live_length is REG_LIVE_LENGTH in insns, size the
   number of words (UNITS_PER_WORD = 8 on the EE: a TImode pseudo counts 2). A pseudo with a
   REG_EQUIV note (a constant, or a memory slot that never changes, e.g. a stack argument) had
   its live length doubled by local-alloc's update_equiv_regs, so it goes later; pseudos with
   1 reference get priority 0 (floor_log2(1) = 0). The computed order is checked against the
   ";; N regs to allocate:" line of the .greg dump.
   For each pseudo: refs, live length, priority, calls crossed, conflicts, preferred hard regs
   (copy/preference hints), the hard register it ended with (after reload), and the insn that
   sets it.
2. Local allocation (local-alloc.c): pseudos living in one basic block are given registers
   there first, block by block; their order inside a block uses the same formula on the
   quantity's life within the block (shown as an approximation from refs/live length).
3. At every differing word whose instruction is the same as the game's except for registers:
   which pseudo sits in the register that differs, what it got, what the game has, and why it
   could not have the game's register (a conflicting pseudo allocated earlier, a local pseudo or
   hard register live across it, a call it crosses) or, when the register was free, that the
   choice came from REG_ALLOC_ORDER / the already-used-registers pass / a preference.
"""
import argparse
import math
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rtl_dumps as R  # noqa: E402

UNITS_PER_WORD = 8

REG_LINE = re.compile(r"^Register (\d+) used (\d+) times? across (-?\d+) insns?(.*)$")
LOCAL_RE = re.compile(r"^;; Register (\d+) in (\d+)\.")
CONFL_RE = re.compile(r"^;; (\d+) conflicts:(.*)$")
PREF_RE = re.compile(r"^;; (\d+) preferences:(.*)$")
ORDER_RE = re.compile(r"^;; (\d+) regs to allocate:(.*)$")


@dataclass
class Pseudo:
    regno: int
    refs: int
    live: int
    block: int = None
    sets: int = 0
    calls: int = 0
    nbytes: int = UNITS_PER_WORD
    cls: str = ""
    user: bool = False
    local: int = None             # hard reg from local-alloc
    final: int = None             # hard reg after global + reload (None: memory)
    conflicts: list = field(default_factory=list)
    hard_conflicts: list = field(default_factory=list)
    prefs: list = field(default_factory=list)
    equiv: str = ""
    setter: str = ""
    setter_uid: int = None

    @property
    def size(self):
        return (self.nbytes + UNITS_PER_WORD - 1) // UNITS_PER_WORD

    @property
    def priority(self):
        if self.live <= 0 or self.refs <= 0:
            return 0
        fl = self.refs.bit_length() - 1          # floor_log2
        return int(((fl * self.refs) / self.live) * 10000 * self.size)


def parse_lreg(text):
    ps = {}
    locals_ = {}
    for line in text.splitlines():
        m = REG_LINE.match(line)
        if m:
            p = Pseudo(int(m.group(1)), int(m.group(2)), int(m.group(3)))
            rest = m.group(4)
            mm = re.search(r" in block (\d+)", rest)
            p.block = int(mm.group(1)) if mm else None
            mm = re.search(r"set (\d+) time", rest)
            p.sets = int(mm.group(1)) if mm else 0
            mm = re.search(r"crosses (\d+) call", rest)
            p.calls = int(mm.group(1)) if mm else 0
            mm = re.search(r"(\d+) bytes", rest)
            p.nbytes = int(mm.group(1)) if mm else UNITS_PER_WORD
            p.user = "user var" in rest
            mm = re.search(r";\s*((?:pref )?[A-Z_0-9]+(?: or none|, else [A-Z_0-9]+)?)", rest)
            p.cls = mm.group(1) if mm and "_REGS" in mm.group(1) else ""
            ps[p.regno] = p
            continue
        m = LOCAL_RE.match(line)
        if m:
            locals_[int(m.group(1))] = int(m.group(2))
    for r, h in locals_.items():
        if r in ps:
            ps[r].local = h
    return ps


def parse_greg(text):
    order, confl, prefs, disp = [], {}, {}, {}
    lines = text.splitlines()
    for i, line in enumerate(lines):
        m = ORDER_RE.match(line)
        if m:
            for tok in m.group(2).split():
                if tok.startswith("("):
                    continue
                order.append(int(tok.split("+")[0]))
            continue
        m = CONFL_RE.match(line)
        if m:
            confl[int(m.group(1))] = [int(x) for x in m.group(2).split()]
            continue
        m = PREF_RE.match(line)
        if m:
            prefs[int(m.group(1))] = [int(x) for x in m.group(2).split()]
            continue
        if line.startswith(";; Register dispositions:"):
            for l2 in lines[i + 1:]:
                if not l2.strip() or l2.startswith(";;"):
                    break
                for a, b in re.findall(r"(\d+) in (\d+)", l2):
                    disp[int(a)] = int(b)
    return order, confl, prefs, disp


def rtl_desc(insn):
    try:
        from sched_explain import rtl_short
        return rtl_short(insn.pattern)
    except Exception:
        return ""


def build(d):
    lreg = R.pick_function(d.files.get("lreg", ""))
    greg = R.pick_function(d.files.get("greg", ""))
    ps = parse_lreg(lreg)
    order, confl, prefs, disp = parse_greg(greg)
    allocnos = set(confl)
    for r, lst in confl.items():
        if r not in ps:
            continue
        ps[r].conflicts = [x for x in lst if x in allocnos and x != r]
        ps[r].hard_conflicts = [x for x in lst if x not in allocnos]
        ps[r].prefs = prefs.get(r, [])
    for r, p in ps.items():
        p.final = disp.get(r)
    insns = R.parse_insns(lreg)
    for ins in insns.values():
        pat = ins.pattern
        if R.head(pat) == "set":
            rr = R.reg_of(pat[1])
            if rr and not rr[1] and rr[0] in ps:
                p = ps[rr[0]]
                if not p.setter:
                    p.setter = f"insn {ins.uid}: {rtl_desc(ins)}"
                    p.setter_uid = ins.uid
                for kind, x in ins.notes:
                    if kind == "REG_EQUIV":
                        p.equiv = rtl_short_safe(x)
    return ps, order, insns, R.parse_insns(greg)


def rtl_short_safe(x):
    try:
        from sched_explain import rtl_short
        return rtl_short(x)
    except Exception:
        return "?"


def computed_order(ps, allocnos):
    gl = [ps[r] for r in allocnos if r in ps and ps[r].local is None]
    return [p.regno for p in sorted(gl, key=lambda p: (-p.priority, p.regno))]


def pri_s(p):
    return f"{p.priority / 10000:.4f}"


def show_global(ps, order):
    allocnos = [r for r in ps if ps[r].conflicts or ps[r].hard_conflicts or r in order]
    mine = computed_order(ps, allocnos)
    print(f"\nglobal allocation: {len(order)} pseudos, in the order find_reg took them "
          f"({'matches' if mine == order else '!! differs from'} the computed priority order)")
    if mine != order:
        print(f"   dump:     {' '.join(map(str, order))}")
        print(f"   computed: {' '.join(map(str, mine))}")
    print("     #  pseudo  refs  live sz priority calls conf  prefs        got     sets / defined by")
    for i, r in enumerate(order, 1):
        p = ps.get(r)
        if p is None:
            print(f"   {i:>3}  {r:<6} (not in the .lreg register table)")
            continue
        flags = (" uservar" if p.user else "") + (f" EQUIV {p.equiv[:24]}" if p.equiv else "")
        pref = ",".join(R.hard_name(h) for h in p.prefs) or "-"
        print(f"   {i:>3}  {r:<6} {p.refs:>4} {p.live:>5} {p.size:>2} {pri_s(p):>9} {p.calls:>5} "
              f"{len(p.conflicts):>4}  {pref:<12} {R.hard_name(p.final):<7} {p.sets}x {p.setter[:40]}{flags}")


def show_local(ps):
    by_block = {}
    for p in ps.values():
        if p.local is not None:
            by_block.setdefault(p.block, []).append(p)
    if not by_block:
        return
    print(f"\nlocal allocation (one block each; ~priority uses refs/live length, local-alloc measures "
          f"the life inside the block):")
    for b in sorted(by_block, key=lambda x: (x is None, x)):
        lst = sorted(by_block[b], key=lambda p: (-p.priority, p.regno))
        items = "  ".join(f"{p.regno}->{R.hard_name(p.local)}(~{pri_s(p)})" for p in lst)
        print(f"   block {b}: {items}")


def tied_to(p, ps, insns):
    """local-alloc's combine_regs: the destination of an insn takes the register of a source pseudo
    that dies in that insn (one quantity for both). Returns that source pseudo, if any."""
    ins = insns.get(p.setter_uid)
    if ins is None or R.head(ins.pattern) != "set":
        return None
    dead = {R.reg_of(x)[0] for k, x in ins.notes if k == "REG_DEAD" and R.reg_of(x)}
    for rn, hard in R.regs_in(ins.pattern[2]):
        q = ps.get(rn)
        if not hard and q is not None and rn in dead and rn != p.regno and q.local is not None \
                and q.local == p.local:
            return q
    return None


def why_not_local(p, want, ps, insns):
    txt = f"local-alloc gave it {R.hard_name(p.local)} in block {p.block}"
    t = tied_to(p, ps, insns)
    if t is not None:
        txt += (f"; it shares that register with pseudo {t.regno}, which dies in its defining insn "
                f"(combine_regs ties a destination to a dying source)")
    rivals = [q for q in ps.values() if q.regno in p.conflicts and q.regno != p.regno and
              (q.final if q.final is not None else q.local) == want]
    if rivals:
        txt += f"; {R.hard_name(want)} is held by " + ", ".join(
            f"pseudo {q.regno} ({'local ~' + pri_s(q) if q.local is not None else 'global'}, live at the same time)"
            for q in rivals[:3])
        txt += f" (this one ~{pri_s(p)})"
    elif want in p.hard_conflicts:
        txt += f"; {R.hard_name(want)} is live across it as a hard register"
    else:
        txt += (f"; {R.hard_name(want)} was free over its whole life: the choice came from local-alloc's "
                f"order (quantities by ~priority, registers in REG_ALLOC_ORDER) or a tie/copy suggestion")
    return txt


def why_not(p, want, ps, order, insns=None):
    """Why pseudo p did not end up in hard register `want`."""
    reasons = []
    if p.local is not None:
        return why_not_local(p, want, ps, insns)
    if p.final is None:
        return "it was spilled to the stack (reload)"
    if want in p.hard_conflicts:
        who = [q for q in ps.values() if q.local == want and q.regno in p.conflicts]
        if who:
            reasons.append(f"{R.hard_name(want)} is live across it: held by local pseudo"
                           f"{'s' if len(who) > 1 else ''} {', '.join(str(q.regno) for q in who[:4])}")
        else:
            reasons.append(f"{R.hard_name(want)} is live across it as a hard register (argument/return value, "
                           f"or an insn that needs it)")
    if p.calls and want not in R.CALL_SAVED and want < 64:
        reasons.append(f"it crosses {p.calls} call(s) and {R.hard_name(want)} is call-clobbered")
    pos = {r: i for i, r in enumerate(order)}
    earlier = [ps[q] for q in p.conflicts if q in ps and ps[q].final == want and ps[q].local is None
               and pos.get(q, 1e9) < pos.get(p.regno, -1)]
    for q in earlier[:3]:
        if q.priority == p.priority:
            how = (f"a priority tie ({pri_s(q)}) broken by pseudo number, {q.regno} < {p.regno}: "
                   f"the pseudo created first wins")
        else:
            how = f"priority {pri_s(q)} vs {pri_s(p)}"
        reasons.append(f"it lost {R.hard_name(want)} to pseudo {q.regno}, allocated earlier by {how} "
                       f"(refs {q.refs}/{p.refs}, live {q.live}/{p.live})")
    later = [ps[q] for q in p.conflicts if q in ps and ps[q].final == want and ps[q].local is None
             and pos.get(q, -1) > pos.get(p.regno, 1e9)]
    if not reasons:
        txt = f"{R.hard_name(want)} was free when it was allocated (#{pos.get(p.regno, -1) + 1}); " \
              f"{R.hard_name(p.final)} won by "
        txt += ("its preference list " + ",".join(R.hard_name(h) for h in p.prefs)) if p.final in p.prefs else \
            "REG_ALLOC_ORDER / the pass that prefers registers already used"
        if later:
            txt += f"; later pseudo{'s' if len(later) > 1 else ''} " + ", ".join(
                f"{q.regno} (priority {pri_s(q)})" for q in later[:3]) + f" then took {R.hard_name(want)}"
        reasons.append(txt)
    return "; ".join(reasons)


def scratches(pat):
    elts = pat[1] if R.head(pat) == "parallel" and len(pat) > 1 and isinstance(pat[1], list) else []
    return sum(1 for x in elts if R.head(x) == "clobber" and R.head(x[1]) == "scratch")


def role(word, pos):
    """Is register operand `pos` of this instruction written (dest) or read (src)?"""
    from rabbitizer import Instruction, InstrCategory
    ins = Instruction(word, category=InstrCategory.R5900)
    if pos == 0 and not (ins.doesStore() or ins.isBranch() or ins.isJump()) and \
            not ins.getOpcodeName().startswith(("mult", "div", "mt", "ctc")):
        return "dest"
    return "src"


def operand_regs(pat, which):
    """Registers in the destination(s) or the source(s) of an insn pattern."""
    sets = []
    if R.head(pat) == "set":
        sets = [pat]
    elif R.head(pat) == "parallel" and len(pat) > 1 and isinstance(pat[1], list):
        sets = [x for x in pat[1] if R.head(x) == "set"]
    out = []
    for x in sets:
        dest = x[1]
        if which == "dest":
            if R.head(dest) == "mem":
                continue
            out += R.regs_in(dest)
        else:
            out += R.regs_in(x[2])
            if R.head(dest) == "mem":
                out += R.regs_in(dest)
    return out or R.regs_in(pat)


def origin(uid, insns, greg_insns):
    """An insn missing from .lreg was made by reload (or a split it triggered): the first insn after it in
    the .greg chain that local-alloc knew is usually the one it came from."""
    g = greg_insns.get(uid)
    steps = 0
    while g is not None and steps < 6:
        if g.next in insns:
            return insns[g.next]
        g = greg_insns.get(g.next)
        steps += 1
    return None


def explain_diffs(d, res, ps, order, insns, addr, greg_insns=None):
    from match import disasm
    if not d.word_uid:
        print(f"\n(no word->insn map: {d.map_note or 'compile differs'})")
        return
    print("\nregister differences at the differing words:")
    seen, told = set(), set()
    shown = 0
    for i in res.diffs:
        if i >= len(res.target.words) or i >= len(res.ours.words) or i >= len(d.word_uid):
            continue
        g = disasm(res.target.words[i], addr + 4 * i, None)
        o = disasm(res.ours.words[i], addr + 4 * i, None)
        gm, om = g.split()[0], o.split()[0]
        gr, orr = re.findall(r"\$\w+", g), re.findall(r"\$\w+", o)
        uid = d.word_uid[i]
        if gm != om or len(gr) != len(orr):
            print(f"   {addr + 4 * i:08X} game `{g}` / ours `{o}` (insn {uid}): different instruction "
                  f"(scheduling or code shape, see sched_explain.py)")
            shown += 1
            continue
        pairs = [(R.NAME_TO_HARD.get(x), R.NAME_TO_HARD.get(y)) for x, y in zip(orr, gr) if x != y]
        if not pairs:
            continue
        ins = insns.get(uid)
        for ours_h, game_h in pairs:
            cands = []
            if ins is not None:
                pos = next(k for k, (x, y) in enumerate(zip(orr, gr)) if R.NAME_TO_HARD.get(x) == ours_h
                           and R.NAME_TO_HARD.get(y) == game_h)
                for rn, hard in operand_regs(ins.pattern, role(res.ours.words[i], pos)):
                    if hard:
                        continue
                    p = ps.get(rn)
                    if p is not None and (p.final if p.final is not None else p.local) == ours_h \
                            and p not in cands:
                        cands.append(p)
            key = (uid, ours_h, game_h)
            if key in seen:
                continue
            seen.add(key)
            shown += 1
            head = f"   {addr + 4 * i:08X} `{o}` (insn {uid}) game `{g}`:"
            if ins is None:
                src = origin(uid, insns, greg_insns or {})
                print(f"{head} {R.hard_name(ours_h)} vs {R.hard_name(game_h)}: insn {uid} did not exist at "
                      f"local-alloc (made by reload or the prologue/epilogue)")
                if src is not None:
                    scr = sum(1 for x in (src.pattern[1] if R.head(src.pattern) == "parallel" else [])
                              if R.head(x) == "clobber" and R.head(x[1]) == "scratch")
                    pseudos = sorted({rn for rn, hard in R.regs_in(src.pattern) if not hard})
                    print(f"      it comes from insn {src.uid}: {rtl_desc(src)[:70]}"
                          + (f"\n      that pattern has {scr} (clobber (scratch)): reload picks those registers "
                             f"after global allocation, so this is reload's choice, not a pseudo priority" if scr else ""))
                    print("      its pseudos: " + ", ".join(
                        f"{rn}->{R.hard_name(ps[rn].final if ps[rn].final is not None else ps[rn].local)}"
                        for rn in pseudos if rn in ps))
                continue
            if not cands:
                hard_used = [rn for rn, hard in R.regs_in(ins.pattern) if hard and rn == ours_h]
                scr = scratches(ins.pattern)
                if hard_used:
                    what = "a hard register named in the RTL itself (argument, return value, fixed operand)"
                elif scr:
                    what = (f"no pseudo of this insn is there: the insn has {scr} (clobber (scratch)), and "
                            f"reload picks that register after global allocation")
                else:
                    what = "no pseudo of this insn is there: a reload register (spilled or reloaded operand)"
                print(f"{head} {R.hard_name(ours_h)} vs {R.hard_name(game_h)}: {what}")
                continue
            for p in {c.regno: c for c in cands}.values():
                kind = "local" if p.local is not None else "global"
                if (p.regno, ours_h, game_h) in told:
                    print(f"{head} pseudo {p.regno} again ({R.hard_name(ours_h)} vs {R.hard_name(game_h)}, see above)")
                    continue
                told.add((p.regno, ours_h, game_h))
                print(f"{head}\n      pseudo {p.regno} ({kind}{', user var' if p.user else ''}, {p.setter[:50]}) "
                      f"got {R.hard_name(ours_h)}, game uses {R.hard_name(game_h)}:\n      "
                      f"{why_not(p, game_h, ps, order, insns)}")
                t = tied_to(p, ps, insns) if p.local is not None else None
                if t is not None and uid == p.setter_uid and pos == 0 and game_h not in \
                        [R.NAME_TO_HARD.get(x) for x in gr[1:]]:
                    print(f"      hint: the game's insn does not reuse a source register for the result, so in the "
                          f"original pseudo {t.regno} is probably still live after it (used again later), or the "
                          f"operands come in another order")
                holder = [q for q in ps.values() if q.regno in p.conflicts and
                          (q.final if q.final is not None else q.local) == game_h]
                if holder and p.local is None:
                    print("      holders of " + R.hard_name(game_h) + " that conflict with it: " + ", ".join(
                        f"{q.regno} ({'local' if q.local is not None else 'priority ' + pri_s(q)})" for q in holder[:5]))
    if not shown:
        print("   none: the differing words are not register-only differences")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--keep", help="keep the dumps in this directory (under work/ or build/)")
    ap.add_argument("--pseudo", type=int, action="append", help="show one pseudo in detail (repeatable)")
    ap.add_argument("--no-local", action="store_true", help="skip the per-block local-alloc listing")
    a = ap.parse_args()
    src = R.find_source(a.name, a.src)
    d = R.compile_with_dumps(a.name, src, ["-dl", "-dg"], keep=a.keep)
    if "lreg" not in d.files or "greg" not in d.files:
        sys.exit("no .lreg/.greg dumps produced")
    ps, order, insns, greg_insns = build(d)

    res, addr = None, None
    try:
        import match
        res = match.compare(a.name, str(src), outdir=str(d.workdir.parent / "explain_match"))
        addr = match.func_row(a.name)["addr"]
        if res.error:
            print(f"(match: {res.error.splitlines()[0]})")
            res = None
    except Exception as e:
        print(f"(no diff against the game: {e})")
    if res is not None:
        print(f"{a.name}: " + ("MATCH" if res.ok else f"{len(res.diffs)} of {len(res.target.words)} words differ"))
        if d.words and not R.same_code(d.words, res.ours.words):
            print("   !! the dump compile differs from match.py's object: word->insn map not trusted")
            d.word_uid = None

    if a.pseudo:
        for r in a.pseudo:
            p = ps.get(r)
            if p is None:
                print(f"pseudo {r}: not in the dumps")
                continue
            print(f"\npseudo {r}: refs {p.refs}, live {p.live}, size {p.size}, priority {pri_s(p)}, "
                  f"crosses {p.calls} calls, class {p.cls or '?'}{', user var' if p.user else ''}")
            print(f"   {'local-alloc in block ' + str(p.block) if p.local is not None else 'global'}; "
                  f"got {R.hard_name(p.final if p.final is not None else p.local)}")
            if p.equiv:
                print(f"   REG_EQUIV {p.equiv} (live length doubled by update_equiv_regs)")
            print(f"   defined by {p.setter}")
            if p.local is None:
                pos = order.index(r) + 1 if r in order else None
                print(f"   allocated #{pos} of {len(order)}")
                print(f"   conflicts: " + " ".join(
                    f"{q}({R.hard_name(ps[q].final if ps[q].final is not None else ps[q].local) if q in ps else '?'})"
                    for q in p.conflicts))
                print(f"   hard conflicts: {' '.join(R.hard_name(h) for h in p.hard_conflicts)}")
                print(f"   preferences: {' '.join(R.hard_name(h) for h in p.prefs) or '-'}")
        return

    show_global(ps, order)
    if not a.no_local:
        show_local(ps)
    if res is not None and not res.ok:
        explain_diffs(d, res, ps, order, insns, addr, greg_insns)


if __name__ == "__main__":
    main()
