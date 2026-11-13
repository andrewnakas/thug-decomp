#!/usr/bin/env python3
"""Decision oracle: run SN's own cc1plus.exe under gdb and report, for every differing word, the internal
decision that produced it (register allocation order, ready-list pick, delay-slot fill), and with
--force, what the output would be if the other candidate had won.

    python tools/oracle.py func_00271D80                         # explain every differing word
    python tools/oracle.py func_00271D80 --pass ra               # only allocation decisions
    python tools/oracle.py func_00271D80 --force                 # also flip each decision and recompile
    python tools/oracle.py NAME --src work/try.cpp --keep work/oracle/NAME
    python tools/oracle.py NAME --trace                          # dump the raw decision trace (JSON lines)

How it works (docs/techniques/ORACLE.md): the unit is preprocessed and compiled by SN's driver once
(with -dl -dg -dp, which do not change the code), then cc1plus.exe is run again directly under gdb
inside wibo. tools/oracle_gdb.py sets breakpoints at addresses recovered from the stripped binary
(global_alloc after its qsort, find_reg, local-alloc's block_alloc after its qty sort, haifa
schedule_block after SCHED_SORT and after the EE backend's MD_SCHED_REORDER hook, the issue point,
reorg's emit_delay_sequence) and logs the inputs and outcomes. A force rewrites the sorted array in
the compiler's memory at that point and lets compilation continue, so the effect of flipping one
decision is exact, not modelled.

Passes:
    ra      global.c allocno order (priority = floor_log2(refs)*refs/live*10000*size, ties by allocno
            number), find_reg results; local-alloc.c quantity order per block (same formula on the
            quantity's life inside the block, ties by quantity number).
    sched1/sched2  haifa ready list per cycle: rank keys (priority, reg weight, dependence on the last
            insn, dependents, luid), the order before and after SN's MD_SCHED_REORDER, the issued insn.
    reorg   which reorg function filled each delay slot (fill_simple_delay_slots, fill_slots_from_thread
            for eager/simple threading, steal_delay_list_*), the branch and the slot insns.
Needs: gdb on PATH (tested with GNU gdb 15 on x86-64 Linux), wibo 1.2 from toolchain/bin.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from contextlib import contextmanager
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
import rtl_dumps as R  # noqa: E402
from common import ROOT, compiler_config, file_cflags  # noqa: E402

GDB_SCRIPT = Path(__file__).resolve().parent / "oracle_gdb.py"
GDB_TIMEOUT = 600

# reorg.c functions in SN 1.36 cc1plus.exe (start address -> name), for naming emit_delay_sequence's caller
REORG_FUNCS = [
    (0x579C00, "dbr_schedule"), (0x57A590, "fill_simple_delay_slots"), (0x57B100, "emit_delay_sequence"),
    (0x57B2E0, "add_to_delay_list"), (0x57B320, "note_delay_statistics"), (0x57B360, "optimize_skip"),
    (0x57B4E0, "own_thread_p"), (0x57B560, "update_block"), (0x57B630, "fill_slots_from_thread"),
    (0x57C040, "steal_delay_list_from_target"), (0x57C400, "steal_delay_list_from_fallthrough"),
    (0x57CBD0, "fill_eager_delay_slots"), (0x57CE00, "relax_delay_slots"), (0x57D4B0, "delete_scheduled_jump"),
    (0x57D560, "try_merge_delay_insns"), (0x57DAD0, "make_return_insns"),
    (0x57E000, None),
]


def reorg_name(addr):
    best = None
    for a, n in REORG_FUNCS:
        if a <= addr:
            best = n
    return best or f"0x{addr:06X}"


# ------------------------------------------------------------------ compiling
class Unit:
    """One unit prepared for traced compiles: preprocessed source, cc1plus argv, dumps, target."""

    def __init__(self, name, src, wd):
        self.name, self.src, self.wd = name, Path(src).resolve(), Path(wd).resolve()
        self.cfg = compiler_config()
        self.wd.mkdir(parents=True, exist_ok=True)
        for old in self.wd.glob("u.*"):
            old.unlink()
        shutil.copyfile(self.src, self.wd / ("u" + self.src.suffix))
        cdir, spec = cc.compiler_dir(self.cfg)
        cpp = []
        for f in self.cfg["compiler"]["cppflags"]:
            cpp.append("-I" + os.path.relpath(ROOT / f[2:], self.wd) if f.startswith("-I") else f)
        flags = list(self.cfg["compiler"]["cflags"]) + file_cflags(self.src) + ["-dG", "-dl", "-dg", "-dp"]
        argv = [cc.wibo(), str(cdir / spec["driver"]), "-v", "-save-temps", "-S", *flags, *cpp,
                "u" + self.src.suffix, "-o", "u.s"]
        p = subprocess.run(argv, cwd=self.wd, capture_output=True, timeout=300)
        if p.returncode != 0:
            raise cc.StageError("ee-gcc -S failed:\n" + p.stderr.decode(errors="replace")[-2000:])
        line = next((l for l in p.stderr.decode(errors="replace").splitlines() if "cc1plus.exe" in l
                     or "cc1.exe" in l), None)
        if line is None:
            raise cc.StageError("no cc1 command line in the driver's -v output")
        toks = line.split()
        exe = toks[0]
        if exe[1:2] == ":":
            exe = exe[2:]
        self.cc1 = os.path.normpath(exe.replace("\\", "/"))
        self.cc1_args = [t for t in toks[1:] if t != "-version"]
        self.base_asm = (self.wd / "u.s").read_text(errors="replace")
        self.files = {}
        for f in self.wd.iterdir():
            m = re.match(r"^u\.(?:cc|c|cpp|ii|i)\.(\w+)$", f.name)
            if m:
                self.files[m.group(1)] = f.read_text(errors="replace")

    def traced(self, tag, hooks=("ga", "la", "sched", "reorg", "gcse"), force=()):
        """Run cc1plus under gdb; returns (asm text, list of events)."""
        out_s, trace = f"o_{tag}.s", self.wd / f"trace_{tag}.jsonl"
        args = list(self.cc1_args)
        k = args.index("-o")
        args[k + 1] = out_s
        cfgp = self.wd / f"cfg_{tag}.json"
        cfgp.write_text(json.dumps({"out": str(trace), "hooks": list(hooks), "force": list(force)}))
        env = dict(os.environ, ORACLE_CFG=str(cfgp))
        argv = ["gdb", "-q", "-batch", "-nx", "-x", str(GDB_SCRIPT), "--args", cc.wibo(), self.cc1, *args]
        p = subprocess.run(argv, cwd=self.wd, env=env, capture_output=True, timeout=GDB_TIMEOUT)
        if not (self.wd / out_s).exists():
            raise cc.StageError("traced compile produced no output:\n" + p.stdout.decode(errors="replace")[-1500:]
                                + p.stderr.decode(errors="replace")[-1500:])
        ev = [json.loads(l) for l in trace.read_text().splitlines() if l.strip()]
        errs = [e for e in ev if e["ev"] == "error"]
        if errs:
            print(f"   (tracer: {len(errs)} hook errors, first: {errs[0]})", file=sys.stderr)
        return (self.wd / out_s).read_text(errors="replace"), ev


@contextmanager
def asm_override(text):
    """Make match.compare assemble this compiler output instead of compiling the source."""
    plain = "\n".join(R.DP_STRIP.sub("", l) for l in text.splitlines()) + "\n"
    old = cc.cxx_to_asm
    cc.cxx_to_asm = lambda *a, **k: plain.encode()
    try:
        yield
    finally:
        cc.cxx_to_asm = old


def compare_asm(unit, text, tag):
    import match
    with asm_override(text):
        return match.compare(unit.name, str(unit.src), outdir=str(unit.wd / f"m_{tag}"))


def word_map(unit, text):
    d = R.Dumps(unit.name, unit.src, unit.wd, text, unit.files)
    try:
        R._map_words(d, unit.cfg)
    except (cc.StageError, ValueError, OSError) as e:
        d.map_note = str(e)
    return d


# ------------------------------------------------------------------ trace model
def floor_log2(n):
    return n.bit_length() - 1 if n > 0 else -1


def ga_priority(refs, live, size):
    # allocno_compare: (double)(floor_log2(refs) * refs) / live * 10000 * size, truncated (__ftol)
    if live == 0:
        return 0
    return int((floor_log2(refs) * refs) / live * size * 10000.0)


def qty_priority(q):
    life = q["death"] - q["birth"]
    if life == 0:
        return 0
    return int((floor_log2(q["refs"]) * q["refs"] * q["size"]) / life * 10000.0)


class Trace:
    def __init__(self, events):
        self.ev = events
        self.ga = [e for e in events if e["ev"] == "ga_order"]
        self.find_reg = [e for e in events if e["ev"] == "find_reg"]
        self.la = [e for e in events if e["ev"] == "la_order"]
        self.ready = [e for e in events if e["ev"] == "ready"]
        self.picks = [e for e in events if e["ev"] == "pick"]
        self.delay = [e for e in events if e["ev"] == "delay"]

    # ---- global allocation
    def ga_info(self, regno):
        for g in self.ga:
            a = g["alloc"].get(str(regno))
            if a is None:
                continue
            allocno, refs, live, size = a
            pr = ga_priority(refs, live, size)
            order = g["order"]
            pos = order.index(regno)
            ties = [int(r) for r, (an, rf, lv, sz) in g["alloc"].items()
                    if int(r) != regno and ga_priority(rf, lv, sz) == pr]
            return dict(ga=g["ga"], allocno=allocno, refs=refs, live=live, size=size, pri=pr, pos=pos,
                        n=len(order), ties=sorted(ties), order=order, alloc=g["alloc"])
        return None

    def ga_key(self, info, regno):
        an, rf, lv, sz = info["alloc"][str(regno)]
        return ga_priority(rf, lv, sz), an

    # ---- local allocation
    def la_info(self, regno):
        for e in self.la:
            for q, d in e["qty"].items():
                if regno in d["regs"]:
                    q = int(q)
                    pri = qty_priority(d)
                    ties = [int(k) for k, x in e["qty"].items() if int(k) != q and qty_priority(x) == pri]
                    return dict(block=e["block"], qty=q, d=d, pri=pri, pos=e["order"].index(q), order=e["order"],
                                qtys=e["qty"], ties=ties)
        return None

    # ---- scheduler
    def pick_of(self, uid, pass_):
        for i, p in enumerate(self.picks):
            if p["uid"] == uid and p["pass_"] == pass_:
                return i, p
        return None, None

    def ready_at(self, pass_, block, clock, uid):
        for e in self.ready:
            if e["pass_"] == pass_ and e["block"] == block and e["clock"] == clock and \
                    any(k["uid"] == uid for k in e["ready"]):
                return e
        return None


def sched1_key(tr, uid, ug):
    """How sched1 ordered the same two insns: its separating key, or None if never ready together."""
    _, pk = tr.pick_of(uid, 1)
    _, pg = tr.pick_of(ug, 1)
    for first, other in ((pk, ug), (pg, uid)):
        if first is None:
            continue
        e = tr.ready_at(1, first["block"], first["clock"], first["uid"])
        if e is None:
            continue
        ks = {k["uid"]: k for k in e["ready"]}
        if other in ks:
            return rank_explain(ks[first["uid"]], ks[other], 1)[0]
    return None


def rank_explain(a, b, pass_):
    """Which rank_for_schedule key puts a ahead of b (a, b: key dicts). Returns (key, detail)."""
    if a["prio"] != b["prio"]:
        return "priority", f"priority {a['prio']} vs {b['prio']}"
    if pass_ == 1 and a["weight"] != b["weight"]:
        return "reg weight", f"reg weight {a['weight']} vs {b['weight']} (lower first)"
    if a["ndep"] != b["ndep"]:
        return "dependents?", (f"dependents {a['ndep']} vs {b['ndep']} (unless the dependence class on the last "
                               f"insn already separated them)")
    return "luid?", f"luid {a['luid']} vs {b['luid']} (unless the dependence class separated them)"


# ------------------------------------------------------------------ explaining one unit
def words_text(res, addr):
    import match
    t = [match.disasm(w, addr + 4 * i, None) for i, w in enumerate(res.target.words)]
    o = [match.disasm(w, addr + 4 * i, None) for i, w in enumerate(res.ours.words)]
    return t, o


def is_branch(text):
    m = text.split()[0] if text else ""
    return m.startswith(("b", "j")) and m not in ("break",)


def ra_candidates(d, ps, insns, res, i, otext, gtext):
    """Pseudos sitting in the differing register operand(s) of word i."""
    import regalloc_explain as RA
    uid = d.word_uid[i] if d.word_uid and i < len(d.word_uid) else None
    gr, orr = re.findall(r"\$\w+", gtext), re.findall(r"\$\w+", otext)
    out = []
    ins = insns.get(uid)
    for pos, (x, y) in enumerate(zip(orr, gr)):
        if x == y:
            continue
        oh, gh = R.NAME_TO_HARD.get(x), R.NAME_TO_HARD.get(y)
        if ins is None:
            out.append((None, oh, gh, uid))
            continue
        found = False
        for rn, hard in RA.operand_regs(ins.pattern, RA.role(res.ours.words[i], pos)):
            p = ps.get(rn)
            if hard or p is None:
                continue
            got = p.final if p.final is not None else p.local
            if got == oh:
                out.append((p, oh, gh, uid))
                found = True
        if not found:
            out.append((None, oh, gh, uid))
    return out


def code_shape(tt, ot, d):
    """Align the two instruction streams by mnemonic; report instructions only one side has."""
    import difflib
    gm = [t.split()[0] for t in tt]
    om = [t.split()[0] for t in ot]
    if sorted(gm) == sorted(om):
        return False
    sm = difflib.SequenceMatcher(None, gm, om, autojunk=False)
    extra, missing = [], []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op in ("delete", "replace"):
            missing += [tt[i] for i in range(i1, i2)]
        if op in ("insert", "replace"):
            extra += [(ot[j], d.word_uid[j] if d.word_uid and j < len(d.word_uid) else None) for j in range(j1, j2)]
    from collections import Counter
    cm, co = Counter(gm), Counter(om)
    net_m = sum((cm - co).values())
    net_e = sum((co - cm).values())
    print(f"\ncode shape: the instruction multisets differ ({net_m} game-only, {net_e} ours-only by mnemonic) -- "
          f"not a tie; a cse/gcse/loop/combine/jump decision or the source shape")
    if missing:
        print("   game-only (aligned): " + "; ".join(f"`{x}`" for x in missing[:8]) + (" ..." if len(missing) > 8 else ""))
    if extra:
        print("   ours-only (aligned): " + "; ".join(f"`{x}` (insn {u})" for x, u in extra[:8]) +
              (" ..." if len(extra) > 8 else ""))
    return True


GCSE_LINE = re.compile(r"^(CONST-PROP|COPY-PROP|PRE|PRE/HOIST|GCSE|HOIST)\b.*$")


PRE_REGS = set()


def gcse_report(unit, involved):
    """gcse.c's decisions from its own -dG log, marking the ones that touch a differing insn or its pseudos."""
    text = unit.files.get("gcse", "")
    lines = [l for l in text.splitlines() if GCSE_LINE.match(l)]
    for l in lines:
        m = re.search(r"(?:reaching reg is|to reg) (\d+)", l)
        if m:
            PRE_REGS.add(int(m.group(1)))
    if not lines:
        return
    print("\ngcse decisions (from the -dG log; * = touches a differing insn or one of its pseudos):")
    for l in lines:
        nums = {int(x) for x in re.findall(r"insn (\d+)", l)}
        regs = {("r", int(x)) for x in re.findall(r"reg(?: is)? (\d+)", l)}
        mark = "*" if (nums | regs) & involved else " "
        print(f"   {mark} {l}")
    print("   (expression numbers are hash-table order; PRE's reaching regs are new pseudos numbered in that order, "
          "and allocno_compare breaks priority ties by pseudo number)")


REC = {"words": [], "forces": []}


def rec(kind, **kw):
    REC["words"].append(dict(kind=kind, **kw))


def explain(unit, a, base=()):
    import match
    import regalloc_explain as RA
    addr = match.func_row(unit.name)["addr"]
    asm, ev = unit.traced("base", force=base)
    tr = Trace(ev)
    if a.trace:
        for e in ev:
            print(json.dumps(e))
        return
    same = R.same_code
    res = compare_asm(unit, asm, "base")
    if res.error:
        sys.exit(f"{unit.name}: {res.error.splitlines()[0]}")
    base_res = compare_asm(unit, unit.base_asm, "plain")
    if not base and not same(res.ours.words, base_res.ours.words):
        print("!! the traced compile differs from the plain one: tracer changed the code")
    ndiff = len(res.diffs)
    print(f"{unit.name}: " + ("MATCH" if res.ok else f"{ndiff} of {len(res.target.words)} words differ") +
          f"   (trace: {len(tr.ga)} global sort, {len(tr.find_reg)} find_reg, {len(tr.la)} local sorts, "
          f"{len(tr.ready)} ready lists, {len(tr.picks)} issues, {len(tr.delay)} delay fills)")
    REC.update(ndiff=ndiff, nwords=len(res.target.words), traced=True)
    if res.ok:
        return
    d = word_map(unit, asm)
    if not d.word_uid:
        print(f"(no word->insn map: {d.map_note})")
    ps, order, insns, greg_insns = RA.build(d)
    # sanity: our model of allocno_compare must reproduce the compiler's order
    for g in [g for g in tr.ga if not g.get("forced")]:
        model = sorted(g["order"], key=lambda r: (-ga_priority(*g["alloc"][str(r)][1:]), g["alloc"][str(r)][0]))
        if model != g["order"]:
            print("   !! allocno_compare model differs from the compiler's sort (x87 rounding?)")
    tt, ot = words_text(res, addr)
    pass_filter = a.pass_
    forces = []          # (description, force spec)
    seen = set()
    shape = code_shape(tt, ot, d)
    REC["shape"] = shape
    involved = set()
    for i in res.diffs:
        if d.word_uid and i < len(d.word_uid) and d.word_uid[i] is not None:
            involved.add(d.word_uid[i])
            ins = insns.get(d.word_uid[i])
            if ins is not None:
                involved |= {("r", rn) for rn, hard in R.regs_in(ins.pattern) if not hard}
    if pass_filter in (None, "gcse"):
        gcse_report(unit, involved)
    if pass_filter == "gcse":
        return None
    print()
    shown = 0
    for i in res.diffs:
        if i >= len(tt) or i >= len(ot):
            print(f"   {addr + 4 * i:08X}  length differs (code shape: an insn more or fewer; gcse/cse/loop/jump, "
                  f"not a tie)")
            break
        if shown >= a.max_words:
            print(f"   ... {len(res.diffs)} differing words; showing the first {a.max_words} (--max-words)")
            break
        shown += 1
        g, o = tt[i], ot[i]
        uid = d.word_uid[i] if d.word_uid and i < len(d.word_uid) else None
        head = f"   {addr + 4 * i:08X}  game `{g}` / ours `{o}` (insn {uid})"
        gm, om = g.split()[0], o.split()[0]
        if gm == om and is_branch(g) and re.sub(r"\. \+ 4 \+ \(.*\)", "", g) == re.sub(r"\. \+ 4 \+ \(.*\)", "", o):
            if pass_filter not in (None, "reorg"):
                continue
            fills = [e for e in tr.delay if e["branch"] == uid]
            print(head)
            if shape:
                print("      branch target shifted by the code-shape difference above (not a decision of its own)")
                continue
            what = (f"its delay slot was filled with insn(s) {fills[-1]['slots']} by {reorg_name(fills[-1]['caller'])}"
                    if fills else "no delay-slot fill was recorded for it")
            print(f"      deciding pass: reorg (branch target differs, same branch). Our branch insn {uid}: {what}. "
                  f"A game target one word further means the game's slot holds a copy of the target's first insn "
                  f"(filled from the taken thread, branching to target+4); one word shorter, the reverse")
            rec("reorg", uid=uid, shifted=False)
            continue
        in_slot = i > 0 and is_branch(ot[i - 1]) and is_branch(tt[i - 1])
        greg_only = gm == om and len(re.findall(r"\$\w+", g)) == len(re.findall(r"\$\w+", o)) and \
            re.sub(r"\$\w+", "R", g) == re.sub(r"\$\w+", "R", o)
        if in_slot and pass_filter in (None, "reorg", "ra"):
            fills = [e for e in tr.delay if uid in e["slots"]]
            fill = (f"delay slot of branch insn {fills[-1]['branch']}, filled with insn(s) {fills[-1]['slots']} by "
                    f"{reorg_name(fills[-1]['caller'])}") if fills else \
                "delay slot; no fill recorded for this insn (a nop, or a copy made by relax_delay_slots)"
            if not greg_only:
                if pass_filter == "ra":
                    continue
                print(head)
                print(f"      deciding pass: reorg. {fill[0].upper() + fill[1:]}")
                rec("reorg", uid=uid)
                continue
            print(head)
            print(f"      ({fill}; the slot insn is right, its register is an allocation decision:)")
        if greg_only:
            if pass_filter not in (None, "ra"):
                continue
            for p, oh, gh, u in ra_candidates(d, ps, insns, res, i, o, g):
                key = (p.regno if p else None, oh, gh)
                if key in seen:
                    continue
                seen.add(key)
                print(head)
                if p is None:
                    print(f"      deciding pass: reload / hard register ({R.hard_name(oh)} vs {R.hard_name(gh)}): "
                          f"no pseudo of insn {u} holds it")
                    rec("reload", uid=u)
                    continue
                gi = tr.ga_info(p.regno)
                li = tr.la_info(p.regno)
                if gi is not None:
                    print(f"      deciding pass: global-alloc. pseudo {p.regno} got {R.hard_name(oh)}, game has "
                          f"{R.hard_name(gh)}; allocated #{gi['pos'] + 1} of {gi['n']}: refs {gi['refs']} live "
                          f"{gi['live']} size {gi['size']} -> priority {gi['pri']}, allocno {gi['allocno']}")
                    holders = [q for q in p.conflicts if q in ps and
                               (ps[q].final if ps[q].final is not None else ps[q].local) == gh]
                    for q in holders[:4]:
                        qi = tr.ga_info(q)
                        if qi is None:
                            print(f"      {R.hard_name(gh)} is held by conflicting pseudo {q} (local-alloc, block "
                                  f"{ps[q].block}): not an ordering tie with this pseudo")
                            continue
                        kp, kq = tr.ga_key(gi, p.regno), tr.ga_key(gi, q)
                        first = "priority" if kp[0] != kq[0] else "allocno number (tie on priority)"
                        who = q if qi["pos"] < gi["pos"] else p.regno
                        print(f"      competitor: pseudo {q} (priority {kq[0]}, allocno {kq[1]}) holds "
                              f"{R.hard_name(gh)} and conflicts; pseudo {who} went first, decided by {first}")
                        rec("ga", p=p.regno, q=q, tie=kp[0] == kq[0], pre=bool({p.regno, q} & PRE_REGS), user=bool(p.user))
                        if qi["pos"] < gi["pos"]:
                            forces.append((f"global: pseudo {p.regno} before {q}",
                                           {"kind": "ga", "before": [p.regno, q]}))
                    if gi["ties"]:
                        print(f"      priority ties: {gi['ties'][:12]}")
                        for q in gi["ties"][:6]:
                            if q in p.conflicts:
                                forces.append((f"global: swap tied pseudos {p.regno} and {q}",
                                               {"kind": "ga", "swap": [p.regno, q]}))
                    if not holders:
                        print(f"      {R.hard_name(gh)} was free of conflicting global pseudos: find_reg's choice "
                              f"(REG_ALLOC_ORDER, preferences, call-clobbered avoidance)")
                        rec("findreg", p=p.regno, pre=p.regno in PRE_REGS)
                elif li is not None:
                    dq = li["d"]
                    print(f"      deciding pass: local-alloc, block {li['block']}. pseudo {p.regno} = quantity "
                          f"{li['qty']} got {R.hard_name(oh)}, game has {R.hard_name(gh)}; quantity #{li['pos'] + 1} "
                          f"of {len(li['order'])}: refs {dq['refs']} life {dq['birth']}..{dq['death']} size "
                          f"{dq['size']} -> priority {li['pri']}")
                    for q in li["order"]:
                        x = li["qtys"][str(q)]
                        if q == li["qty"] or x["phys"] != gh:
                            continue
                        if x["death"] <= dq["birth"] or dq["death"] <= x["birth"]:
                            continue
                        qp = qty_priority(x)
                        first = "priority" if qp != li["pri"] else "quantity number (tie on priority)"
                        before = li["order"].index(q) < li["pos"]
                        print(f"      competitor: quantity {q} (pseudos {x['regs']}, priority {qp}, life "
                              f"{x['birth']}..{x['death']}) holds {R.hard_name(gh)} and overlaps; "
                              f"{'it' if before else 'this one'} went first, decided by {first}")
                        rec("la", p=p.regno, q=x["regs"][0], tie=qp == li["pri"], pre=bool(({p.regno} | set(x["regs"])) & PRE_REGS))
                        if before:
                            forces.append((f"local block {li['block']}: pseudo {p.regno} before {x['regs'][0]}",
                                           {"kind": "la", "block": li["block"], "before": [p.regno, x["regs"][0]]}))
                    if li["ties"]:
                        print(f"      priority ties in the block: quantities {li['ties'][:10]}")
                else:
                    print(f"      pseudo {p.regno}: allocated by neither sort (reload or a fixed register)")
                    rec("reload", p=p.regno)
            continue
        # a different instruction at this position: scheduling (same insns, other order) or code shape
        if pass_filter not in (None, "sched", "sched1", "sched2"):
            continue
        cand = [j for j in range(max(0, i - 24), min(len(ot), i + 25)) if ot[j] == g and j != i
                and not (d.word_uid and j < len(d.word_uid) and d.word_uid[j] == uid)]
        print(head)
        if not cand or uid is None:
            print("      deciding pass: not a reordering (the game's instruction is not nearby in ours): code shape")
            rec("shape_word", uid=uid)
            continue
        j = min(cand, key=lambda x: abs(x - i))
        ug = d.word_uid[j]
        done = False
        for ps_ in ((2, 1) if pass_filter in (None, "sched", "sched2") else (1,)):
            if pass_filter == "sched1" and ps_ == 2:
                continue
            _, pk = tr.pick_of(uid, ps_)
            if pk is None:
                continue
            e = tr.ready_at(ps_, pk["block"], pk["clock"], uid)
            if e is None:
                continue
            ks = {k["uid"]: k for k in e["ready"]}
            if ug not in ks:
                continue
            uo_k, ug_k = ks[uid], ks[ug]
            rpos = [k["uid"] for k in e["ready"]]
            spos = e.get("sorted") or rpos
            note = ""
            if (spos.index(uid) > spos.index(ug)) != (rpos.index(uid) > rpos.index(ug)):
                note = " (the order was changed by SN's MD_SCHED_REORDER hook, cc1plus 0x40D320)"
            if rpos.index(ug) > rpos.index(uid):
                key = "busy"
                why = (f"insn {ug} ranked higher but was not issued first: its function unit was busy or it was "
                       f"queued (actual_hazard)")
            else:
                key, det = rank_explain(uo_k, ug_k, ps_)
                why = f"first separating key: {det}"
            print(f"      deciding pass: sched{ps_}, block {e['block']}, cycle {e['clock']}: ready "
                  f"{rpos[::-1]} (best first); issued {uid}, game's insn is {ug}{note}")
            print(f"      {uid}: prio {uo_k['prio']} weight {uo_k['weight']} deps {uo_k['ndep']} luid {uo_k['luid']}"
                  f"  |  {ug}: prio {ug_k['prio']} weight {ug_k['weight']} deps {ug_k['ndep']} luid {ug_k['luid']}")
            print(f"      {why}")
            rec("sched", pass_=ps_, uid=uid, ug=ug, key=("busy" if rpos.index(ug) > rpos.index(uid) else key), s1=sched1_key(tr, uid, ug))
            forces.append((f"sched{ps_} block {e['block']} cycle {e['clock']}: issue {ug} before {uid}",
                           {"kind": "sched", "pass": ps_, "block": e["block"], "clock": e["clock"], "first": ug}))
            done = True
            break
        if not done:
            print(f"      insn {ug} (the game's) was never in a ready list together with {uid}: a dependence or an "
                  f"earlier decision, not a ready-list tie")
            rec("sched_dep", uid=uid, ug=ug)
    REC["cands"] = [f for _, f in forces]
    # forcing
    if a.force and forces:
        print("\nforcing (recompiled with one decision flipped in the compiler's memory):")
        uniq = []
        for desc, f in forces:
            norm = lambda x: json.dumps(dict(x, swap=sorted(x["swap"])) if "swap" in x else x, sort_keys=True)
            if norm(f) not in [norm(x[1]) for x in uniq]:
                uniq.append((desc, f))
        best = None
        for k, (desc, f) in enumerate(uniq[:a.max_force]):
            asm_f, ev_f = unit.traced(f"f{k}", force=list(base) + [f])
            applied = [e for e in ev_f if e.get("forced")]
            if not applied:
                print(f"   {desc}: force point not reached")
                continue
            r = compare_asm(unit, asm_f, f"f{k}")
            nd = len(r.diffs) if not r.error else None
            tag = "MATCH" if r.ok else (f"{nd} words differ (was {ndiff})" if nd is not None else r.error[:60])
            print(f"   {desc}: {tag}")
            REC["forces"].append(dict(desc=desc, force=f, nd=nd))
            if nd is not None and (best is None or nd < best[0]):
                best = (nd, desc, f)
        if best:
            print(f"   best single flip: {best[1]} -> {best[0]} differing words")
        return best if best and best[0] < ndiff else None
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--keep", help="working directory to keep (default build/oracle/NAME)")
    ap.add_argument("--pass", dest="pass_", choices=["ra", "sched", "sched1", "sched2", "reorg", "gcse"])
    ap.add_argument("--force", action="store_true", help="recompile with each candidate decision flipped")
    ap.add_argument("--max-force", type=int, default=12)
    ap.add_argument("--max-words", type=int, default=25, help="explain at most this many differing words")
    ap.add_argument("--chain", type=int, default=0, metavar="N",
                    help="with --force: keep the best flip and search again, up to N rounds (greedy)")
    ap.add_argument("--with", dest="with_", action="append", default=[], metavar="JSON",
                    help='apply this force before explaining, e.g. \'{"kind":"ga","before":[337,332]}\'')
    ap.add_argument("--json", help="write a machine-readable summary (decisions, forces) to this file")
    ap.add_argument("--trace", action="store_true", help="print the raw decision trace and stop")
    a = ap.parse_args()
    if shutil.which("gdb") is None:
        sys.exit("oracle.py needs gdb on PATH")
    src = R.find_source(a.name, a.src)
    wd = Path(a.keep) if a.keep else ROOT / "build" / "oracle" / a.name
    unit = Unit(a.name, src, wd)
    base = [json.loads(x) for x in a.with_]
    rounds = []
    for rnd in range(a.chain + 1):
        if base:
            print(f"\n=== with forced decisions: {json.dumps(base)}")
        REC.update(words=[], forces=[], shape=None, ndiff=None)
        best = explain(unit, a, base)
        rounds.append(dict(base=list(base), ndiff=REC.get("ndiff"), nwords=REC.get("nwords"), shape=REC.get("shape"),
                           words=REC["words"], forces=REC["forces"], best=best[:2] if best else None))
        if not (a.force and best) or best[0] == 0:
            if best and best[0] == 0:
                base = base + [best[2]]
            break
        base = base + [best[2]]
    if a.json:
        Path(a.json).write_text(json.dumps(dict(name=a.name, rounds=rounds, final=base,
                                                forced_match=any(r["best"] and r["best"][0] == 0 for r in rounds),
                                                pre_regs=sorted(PRE_REGS))))


if __name__ == "__main__":
    main()
