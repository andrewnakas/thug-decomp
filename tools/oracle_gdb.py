# Decision tracer for SN ee-gcc 2.95.3 build 1.36 cc1plus.exe, run inside gdb under wibo.
#   ORACLE_CFG=cfg.json gdb -q -batch -x orc_gdb.py --args wibo cc1plus.exe ...
# cfg.json: {"out": "trace.jsonl", "hooks": ["ga","la","sched","reorg"], "force": [...]}
# Every event is one JSON line. Forces rewrite the compiler's own sort results in place.
import gdb
import json
import os
import struct

CFG = json.load(open(os.environ["ORACLE_CFG"]))
OUT = open(CFG["out"], "w")
HOOKS = set(CFG.get("hooks", ["ga", "la", "sched", "reorg", "gcse", "spill"]))
FORCES = CFG.get("force", [])
INF = None


def inf():
    global INF
    if INF is None:
        INF = gdb.selected_inferior()
    return INF


def rd(addr, n):
    return bytes(inf().read_memory(addr, n))


def u32(a):
    return struct.unpack("<I", rd(a, 4))[0]


def s32(a):
    return struct.unpack("<i", rd(a, 4))[0]


def s16(a):
    return struct.unpack("<h", rd(a, 2))[0]


def arr32(a, n, signed=True):
    if n <= 0:
        return []
    return list(struct.unpack("<%d%s" % (n, "i" if signed else "I"), rd(a, 4 * n)))


def arr16(a, n):
    if n <= 0:
        return []
    return list(struct.unpack("<%dh" % n, rd(a, 2 * n)))


def wr32(a, vals, signed=True):
    inf().write_memory(a, struct.pack("<%d%s" % (len(vals), "i" if signed else "I"), *vals))


def reg(name):
    return int(gdb.parse_and_eval("$" + name)) & 0xFFFFFFFF


def emit(**kw):
    OUT.write(json.dumps(kw) + "\n")


def uid(rtx):
    return s32(rtx + 8)          # rtx header is 8 bytes; fld[] are 8 wide (64-bit HOST_WIDE_INT)


def xexp(rtx, i):
    return u32(rtx + 8 + 8 * i)


def insn_list(lst):
    out = []
    while lst:
        out.append(uid(xexp(lst, 0)))
        lst = xexp(lst, 1)
    return out


class Hook(gdb.Breakpoint):
    def __init__(self, addr, fn):
        super().__init__("*0x%x" % addr, internal=True)
        self.fn = fn
        self.addr = addr
        self.silent = True

    def stop(self):
        try:
            self.fn()
        except Exception as e:  # never kill the compile
            emit(ev="error", at=hex(self.addr), msg=repr(e))
        return False


def forces(kind):
    return [f for f in FORCES if f.get("kind") == kind]


# ------------------------------------------------------------------ SN 1.36 cc1plus.exe addresses
A = dict(
    current_function_name=None,
    # global.c
    max_allocno=0x6107D0, allocno_order=0x6107D4, allocno_size=0x6109C8, allocno_live_length=0x610B8C,
    allocno_n_refs=0x6109BC, allocno_reg=0x6109CC, reg_renumber=0x628F8C,
    ga_after_qsort=0x4EBC13, find_reg=0x4EC790,
    scratch_regset=0x62CFE0,   # 16 bytes past .data's VirtualSize (0x62CFC4), inside its last mapped page: unused
    find_reg_rets=(0x4EBC74, 0x4EBCB9, 0x4ED0E8, 0x4ED514, 0x4ED53E),
    # local-alloc.c
    block_alloc=0x537D50, la_sorted=0x5384EF, la_done=0x5386C7, next_qty=0x611050, qty_phys_reg=0x611084,
    qty_birth=0x611068, qty_death=0x611060, qty_n_refs=0x61104C, qty_size=0x6110C4,
    qty_first_reg=0x61106C, reg_next_in_qty=0x611054,
    find_free_reg=0x539480, qty_phys_copy_sugg=0x611064, qty_phys_num_copy_sugg=0x611074, qty_phys_num_sugg=0x61105C,
    find_free_reg_rets=(0x53843D, 0x5385AD, 0x5385FB, 0x53865A, 0x53869C, 0x5398C3),
    # haifa-sched.c
    schedule_block=0x4F4830, sched_sorted=0x4F4D4F, sched_reordered=0x4F4D64, sched_pick=0x4F4F27,
    reload_completed=0x620508, clock_var=0x610C58, current_blocks=0x610CC8, rgn_bb_table=0x610FA4,
    insn_priority=0x610CD0, insn_reg_weight=0x610B94, insn_depend=0x610BA0, insn_luid=0x610FD4,
    last_scheduled_insn=0x610CEC, insn_cost_fn=0x4EF510, insn_cost_rets=(0x4F63B7, 0x4F6401),
    rank_for_schedule=0x4F62C0, rank_ret=0x4F646A,
    # reorg.c
    emit_delay_sequence=0x57B100,
    # reload1.c: alter_reg (gives a spilled pseudo its stack slot) and its call sites in reload() / finish_spills
    alter_reg=0x56CF60, alter_reg_init_call=0x56A86D, alter_reg_finish_call=0x56F66A, finish_spills=0x56EFA0,
    assign_stack_local=0x4DE3D0, frame_offset=0x629128, reg_old_renumber=0x6151B8, max_regno=0x62914C,
    # gcse.c cprop_insn (0x4E95B0): the try_replace_reg calls (copy-prop, const-prop)
    cprop_copy_call=0x4E96C2, cprop_const_call=0x4E971C,
)

state = {"fn": 0, "ga": 0, "pass": None, "bb": None, "block": None, "sb": 0}


# ------------------------------------------------------------------ global allocation
def ga_after_qsort():
    n = u32(A["max_allocno"])
    order_p = u32(A["allocno_order"])
    order = arr32(order_p, n)
    regs = arr32(u32(A["allocno_reg"]), n)
    refs = arr32(u32(A["allocno_n_refs"]), n)
    ll = arr32(u32(A["allocno_live_length"]), n)
    size = arr32(u32(A["allocno_size"]), n)
    state["ga"] += 1
    forced = None
    by_reg = {regs[a]: a for a in range(n)}
    for f in forces("ga"):
        if f.get("fn", 1) != state["ga"]:
            continue
        new = list(order)
        if "swap" in f:
            ra, rb = f["swap"]
            ia, ib = new.index(by_reg[ra]), new.index(by_reg[rb])
            new[ia], new[ib] = new[ib], new[ia]
        if "before" in f:          # [a, b]: move pseudo a to just before pseudo b
            ra, rb = f["before"]
            new.remove(by_reg[ra])
            new.insert(new.index(by_reg[rb]), by_reg[ra])
        if "order" in f:
            new = [by_reg[r] for r in f["order"]] + [a for a in new if regs[a] not in f["order"]]
        wr32(order_p, new)
        order = new
        forced = f
    emit(ev="ga_order", ga=state["ga"], order=[regs[a] for a in order],
         alloc={regs[a]: [a, refs[a], ll[a], size[a]] for a in range(n)}, forced=forced)


STACK = []


def find_reg_entry():
    esp = reg("esp")
    allocno, losers, alt, acc, retrying = arr32(esp + 4, 5)
    regno = s32(u32(A["allocno_reg"]) + 4 * allocno)
    ev = dict(ev="find_reg", ga=state["ga"], allocno=allocno, regno=regno, alt=alt,
              acc_clob=acc, retrying=retrying, losers=bool(losers))
    for f in forces("fr"):
        # {"kind":"fr","reg":P,"hard":H}: find_reg is entered for pseudo P with every hard reg except H added to
        # its own `losers` input (the set retry_global_alloc and the caller-save retry use). find_reg then runs
        # all of its usual checks (class, conflicts, call-clobbered, fixed, mode) on H alone, records the
        # conflicts itself, and the return hook checks that it really chose H (else: a hook error, no match).
        if f.get("reg") != regno or f.get("retrying", 0) != retrying or f.get("fn", 1) != state["ga"]:
            continue
        old = list(struct.unpack("<4I", rd(losers, 16))) if losers else [0, 0, 0, 0]
        h = int(f["hard"])
        mask = [0xFFFFFFFF] * 4
        mask[h // 32] &= ~(1 << (h % 32)) & 0xFFFFFFFF
        inf().write_memory(A["scratch_regset"], struct.pack("<4I", *[o | m for o, m in zip(old, mask)]))
        wr32(esp + 8, [A["scratch_regset"]], signed=False)
        ev["forced"] = f
    STACK.append(ev)


def find_reg_ret():
    ev = STACK.pop()
    ev["hard"] = s16(u32(A["reg_renumber"]) + 2 * ev["regno"])
    emit(**ev)
    f = ev.get("forced")
    if f is None:
        return
    if ev["hard"] == int(f["hard"]):
        f["ok"] = f.get("ok", 0) + 1
    elif ev["hard"] >= 0:
        emit(ev="error", at="find_reg", msg=f"fr force: find_reg chose {ev['hard']} for pseudo {ev['regno']}, "
                                           f"not {f['hard']}")


# ------------------------------------------------------------------ local allocation
def qty_regs(q):
    out = []
    r = s32(u32(A["qty_first_reg"]) + 4 * q)
    nxt = u32(A["reg_next_in_qty"])
    while r >= 0 and len(out) < 64:
        out.append(r)
        r = s32(nxt + 4 * r)
    return out


def la_entry():
    state["la_b"] = s32(reg("esp") + 4)


def la_sorted():
    n = s32(A["next_qty"])
    if n <= 0:
        return
    base = reg("ebx")
    order = arr32(base, n)
    phys = arr16(u32(A["qty_phys_reg"]), n)
    birth = arr32(u32(A["qty_birth"]), n)
    death = arr32(u32(A["qty_death"]), n)
    refs = arr32(u32(A["qty_n_refs"]), n)
    size = arr32(u32(A["qty_size"]), n)
    regs = [qty_regs(q) for q in range(n)]
    forced = None
    for f in forces("la"):
        if f.get("block") is not None and f["block"] != state["la_b"]:
            continue
        r2q = {r: q for q in range(n) for r in regs[q]}
        if not all(r in r2q for r in f.get("swap", []) + f.get("before", [])):
            continue
        new = list(order)
        if "swap" in f:
            a, b = r2q[f["swap"][0]], r2q[f["swap"][1]]
            ia, ib = new.index(a), new.index(b)
            new[ia], new[ib] = new[ib], new[ia]
        if "before" in f:
            a, b = r2q[f["before"][0]], r2q[f["before"][1]]
            new.remove(a)
            new.insert(new.index(b), a)
        wr32(base, new)
        order = new
        forced = f
    emit(ev="la_order", block=state["la_b"], order=order,
         qty={q: dict(regs=regs[q], phys=phys[q], birth=birth[q], death=death[q], refs=refs[q], size=size[q])
              for q in range(n)}, forced=forced)


FFR = []


def ffr_entry():
    """local-alloc's find_free_reg(class, mode, qty, accept_call_clobbered, just_try_suggested, born, dead).
    An lfr force {"kind":"lfr","block":B,"reg":P,"hard":H} makes every call for P's quantity a
    just_try_suggested call whose only copy-suggested register is H (the arithmetic suggestions are hidden
    for the call, so the fallback to them is not taken). find_free_reg then applies all of its own checks
    (class, fixed and call-clobbered regs, every insn of the lifetime in regs_live_at, mode) to H and, if H
    passes, marks it live itself (post_mark_life). The quantity's suggestion state is restored on return."""
    esp = reg("esp")
    cls, mode, q, acc, just, born, dead = arr32(esp + 4, 7)
    rec = None
    for f in forces("lfr"):
        if f.get("block") is not None and f["block"] != state["la_b"]:
            continue
        if f["reg"] not in qty_regs(q):
            continue
        cs, ncs, ns = u32(A["qty_phys_copy_sugg"]) + 16 * q, u32(A["qty_phys_num_copy_sugg"]) + 2 * q, \
            u32(A["qty_phys_num_sugg"]) + 2 * q
        rec = dict(f=f, q=q, save=(rd(cs, 16), rd(ncs, 2), rd(ns, 2)), at=(cs, ncs, ns))
        h = int(f["hard"])
        bits = [0, 0, 0, 0]
        bits[h // 32] = 1 << (h % 32)
        inf().write_memory(cs, struct.pack("<4I", *bits))
        inf().write_memory(ncs, struct.pack("<h", 1))
        inf().write_memory(ns, struct.pack("<h", 0))
        wr32(esp + 0x14, [1])
    FFR.append(rec)


def ffr_ret():
    rec = FFR.pop() if FFR else None
    if rec is None:
        return
    for a, b in zip(rec["at"], rec["save"]):
        inf().write_memory(a, b)
    got = s32_reg("eax")
    emit(ev="lfr", block=state["la_b"], qty=rec["q"], forced=rec["f"], got=got)
    if got == int(rec["f"]["hard"]):
        rec["f"]["ok"] = rec["f"].get("ok", 0) + 1


def s32_reg(name):
    v = reg(name)
    return v - (1 << 32) if v & 0x80000000 else v


def la_done():
    n = s32(A["next_qty"])
    if n <= 0:
        return
    phys = arr16(u32(A["qty_phys_reg"]), n)
    for f in forces("lfr"):
        if f.get("block") is not None and f["block"] != state["la_b"]:
            continue
        for q in range(n):
            if f["reg"] in qty_regs(q) and phys[q] != int(f["hard"]):
                emit(ev="error", at="find_free_reg", msg=f"lfr force {f}: quantity {q} got {phys[q]}")
    emit(ev="la_result", block=state["la_b"], phys={q: phys[q] for q in range(n)},
         regs={q: qty_regs(q) for q in range(n)})


# ------------------------------------------------------------------ scheduler
def sb_entry():
    bb = s32(reg("esp") + 4)
    block = s32(u32(A["rgn_bb_table"]) + 4 * (s32(A["current_blocks"]) + bb))
    p = 2 if s32(A["reload_completed"]) else 1
    if p != state["pass"]:
        state["sb"] = 0
    state.update({"pass": p, "bb": bb, "block": block})
    state["sb"] += 1
    emit(ev="sched_block", pass_=p, block=block, bb=bb)


def keys(insn):
    u = uid(insn)
    dep = u32(u32(A["insn_depend"]) + 4 * u)
    n = 0
    while dep and n < 10000:
        n += 1
        dep = xexp(dep, 1)
    return dict(uid=u, prio=s32(u32(A["insn_priority"]) + 4 * u),
                weight=s32(u32(A["insn_reg_weight"]) + 4 * u), ndep=n,
                luid=s32(u32(A["insn_luid"]) + 4 * u))


def ready_list():
    base, n = reg("esi"), reg("ebx")
    return base, n, arr32(base, n, signed=False)


def sched_sorted():
    base, n, ptrs = ready_list()
    state["pre"] = [uid(p) for p in ptrs]


def sched_reordered():
    base, n, ptrs = ready_list()
    clock = s32(A["clock_var"])
    last = u32(A["last_scheduled_insn"])
    forced = None
    for f in forces("sched"):
        if f.get("pass") != state["pass"] or f.get("block") != state["block"]:
            continue
        if "order" in f:
            # replay: in every cycle of the block, rank the ready insns by their place in the target order (the
            # earliest at the end, i.e. issued first); insns the order does not name keep their relative order in
            # front. It only permutes this cycle's ready list: a hazard still queues an insn as usual.
            pos = {u: k for k, u in enumerate(f["order"])}
            uids = [uid(p) for p in ptrs]
            free = [p for p, u in zip(ptrs, uids) if u not in pos]
            named = sorted([p for p, u in zip(ptrs, uids) if u in pos], key=lambda p: -pos[uid(p)])
            new = free + named
            if new != ptrs:
                wr32(base, new, signed=False)
                nu = [uid(p) for p in new]
                forced = dict(kind="sched", order_block=f["block"], top=nu[-2:], was=uids[-2:])
                ptrs = new
            continue
        if f.get("clock") is not None and f["clock"] != clock:
            continue
        uids = [uid(p) for p in ptrs]
        first = f["first"] if isinstance(f["first"], list) else [f["first"]]   # [u1, u2]: u1 first, then u2
        if first and all(u in uids for u in first) and (f.get("over") is None or f["over"] in uids):
            for u in first[::-1]:
                k = [uid(p) for p in ptrs].index(u)
                ptrs.append(ptrs.pop(k))            # the end of the array is issued first
            wr32(base, ptrs, signed=False)
            forced = f
            f["done"] = f.get("done", 0) + 1
            if f.get("once", True):
                f["pass"] = -1
    emit(ev="ready", pass_=state["pass"], block=state["block"], clock=clock,
         last=uid(last) if last else None, sorted=state.get("pre"),
         ready=[keys(p) for p in ptrs], forced=forced)


def sched_pick():
    insn = reg("esi")
    emit(ev="pick", pass_=state["pass"], block=state["block"], clock=s32(A["clock_var"]), uid=uid(insn))


COSTS = []


def insn_cost_ret():
    # rank_for_schedule's class test: (last_scheduled_insn, link, insn) -> cost
    pass


# ------------------------------------------------------------------ reorg
def delay_seq():
    esp = reg("esp")
    ret, insn, lst, length = arr32(esp, 4, signed=False)
    emit(ev="delay", caller=ret, branch=uid(insn), slots=insn_list(lst), length=length)


# ------------------------------------------------------------------ gcse constant/copy propagation
def cprop_call(kind, ret_addr):
    def fn():
        regno = reg("esi")
        insn = reg("edi")
        src = reg("ebx")
        u = uid(insn)
        to = s32(src + 8) if kind == "copy" else None
        skip = None
        for f in forces("cprop"):
            if f.get("uid") in (None, u) and f.get("reg") in (None, regno) and f.get("what", kind) == kind:
                skip = f
        emit(ev="cprop", what=kind, reg=regno, uid=u, to=to, forced=skip)
        if skip is not None:                     # make try_replace_reg "fail": skip the call, return 0
            gdb.execute("set $rax = 0")
            gdb.execute("set $rip = 0x%x" % ret_addr)
    return fn


# ------------------------------------------------------------------ reload: spill-slot order
SPILL = {"site": {}, "perm": None}


def spill_site(site):
    """A call `alter_reg (i, from)` in a loop over pseudos (reload's initial loop, or finish_spills).
    A spill force {"kind":"spill","site":"init"|"finish","order":[regnos]} makes the loop visit the named pseudos
    in that order: at the k-th iteration that would call alter_reg for one of them, it calls it for order[k]
    instead (with that pseudo's own from_reg). Each named pseudo is still visited exactly once, by the
    compiler's own alter_reg, so only the order of the stack-slot assignments changes."""
    def fn():
        esp = reg("esp")
        i, frm = arr32(esp, 2)
        st = SPILL["site"].setdefault(site, {"n": 0, "k": 0})
        if st.get("new", True):
            st.update(new=False, n=st["n"] + 1, k=0, old={})
        sub = None
        for f in forces("spill"):
            if f.get("site", "init") != site or f.get("n", 1) != st["n"]:
                continue
            order = f["order"]
            if i not in order:
                continue
            if site == "finish" and not st["old"]:
                base = u32(A["reg_old_renumber"])
                st["old"] = {r: s16(base + 2 * r) for r in order}
            sub = order[sorted(order).index(i)] if f.get("by", "rank") == "rank" else order[st["k"]]
            st["k"] += 1
            nf = st["old"].get(sub, frm) if site == "finish" else frm
            wr32(esp, [sub, nf])
            f["done"] = f.get("done", 0) + 1
        emit(ev="alter_reg", site=site, n=st["n"], regno=i, frm=frm, sub=sub,
             frame=s32(A["frame_offset"]))
    return fn


def finish_spills_entry():
    st = SPILL["site"].get("finish")
    if st:
        st["new"] = True


def stack_local():
    esp = reg("esp")
    ret, mode, size = arr32(esp, 3, signed=False)
    emit(ev="stack_local", caller=ret, mode=mode, size=size, frame=s32(A["frame_offset"]))


def slot_ret():
    x = reg("eax")
    a = xexp(x, 0)
    off = s32(xexp(a, 1) + 8) if (s16(a) & 0xFFFF) != 0x36 else 0
    emit(ev="slot", off=off)


def install():
    if "gcse" in HOOKS:
        Hook(A["cprop_copy_call"], cprop_call("copy", A["cprop_copy_call"] + 5))
        Hook(A["cprop_const_call"], cprop_call("const", A["cprop_const_call"] + 5))
    if "ga" in HOOKS or forces("fr"):
        Hook(A["ga_after_qsort"], ga_after_qsort)
        Hook(A["find_reg"], find_reg_entry)
        for r in A["find_reg_rets"]:
            Hook(r, find_reg_ret)
    if "la" in HOOKS or forces("lfr"):
        Hook(A["block_alloc"], la_entry)
        if forces("lfr"):
            Hook(A["find_free_reg"], ffr_entry)
            for r in A["find_free_reg_rets"]:
                Hook(r, ffr_ret)
        Hook(A["la_sorted"], la_sorted)
        Hook(A["la_done"], la_done)
    if "sched" in HOOKS:
        Hook(A["schedule_block"], sb_entry)
        Hook(A["sched_sorted"], sched_sorted)
        Hook(A["sched_reordered"], sched_reordered)
        Hook(A["sched_pick"], sched_pick)
    if "reorg" in HOOKS:
        Hook(A["emit_delay_sequence"], delay_seq)
    if "spill" in HOOKS or forces("spill"):
        Hook(A["alter_reg_init_call"], spill_site("init"))
        Hook(A["alter_reg_finish_call"], spill_site("finish"))
        Hook(A["finish_spills"], finish_spills_entry)
        Hook(A["assign_stack_local"], stack_local)
        Hook(0x56D02D, slot_ret)
        Hook(0x56D0D8, slot_ret)


gdb.execute("set pagination off")
gdb.execute("set confirm off")
gdb.execute("set debuginfod enabled off")
gdb.execute("set displaced-stepping off")      # gdb would decode the 32-bit guest code as x86-64
for sig in ("SIGSEGV", "SIGILL", "SIGUSR1", "SIGUSR2", "SIGPIPE"):
    gdb.execute("handle %s nostop noprint pass" % sig)
gdb.execute("break thunk_kernel32_GetCommandLineA")   # guest image is mapped by now
gdb.execute("run")
gdb.execute("delete")
install()
gdb.execute("continue")
for f in forces("spill"):
    if f.get("done", 0) != len(f["order"]):
        emit(ev="error", at="alter_reg", msg=f"spill force {f} replayed {f.get('done', 0)} of {len(f['order'])}")
for f in forces("fr") + forces("lfr"):
    if not f.get("ok"):           # never accepted: find_reg's own checks rejected H (or the call never came)
        emit(ev="error", at=f["kind"], msg=f"{f['kind']} force {f} was never accepted by the allocator")
emit(ev="end", forces=FORCES)
OUT.close()
