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
HOOKS = set(CFG.get("hooks", ["ga", "la", "sched", "reorg", "gcse"]))
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
    find_reg_rets=(0x4EBC74, 0x4EBCB9, 0x4ED0E8, 0x4ED514, 0x4ED53E),
    # local-alloc.c
    block_alloc=0x537D50, la_sorted=0x5384EF, la_done=0x5386C7, next_qty=0x611050, qty_phys_reg=0x611084,
    qty_birth=0x611068, qty_death=0x611060, qty_n_refs=0x61104C, qty_size=0x6110C4,
    qty_first_reg=0x61106C, reg_next_in_qty=0x611054,
    # haifa-sched.c
    schedule_block=0x4F4830, sched_sorted=0x4F4D4F, sched_reordered=0x4F4D64, sched_pick=0x4F4F27,
    reload_completed=0x620508, clock_var=0x610C58, current_blocks=0x610CC8, rgn_bb_table=0x610FA4,
    insn_priority=0x610CD0, insn_reg_weight=0x610B94, insn_depend=0x610BA0, insn_luid=0x610FD4,
    last_scheduled_insn=0x610CEC, insn_cost_fn=0x4EF510, insn_cost_rets=(0x4F63B7, 0x4F6401),
    rank_for_schedule=0x4F62C0, rank_ret=0x4F646A,
    # reorg.c
    emit_delay_sequence=0x57B100,
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
    STACK.append(dict(ev="find_reg", ga=state["ga"], allocno=allocno, regno=regno, alt=alt,
                      acc_clob=acc, retrying=retrying, losers=bool(losers)))


def find_reg_ret():
    ev = STACK.pop()
    ev["hard"] = s16(u32(A["reg_renumber"]) + 2 * ev["regno"])
    emit(**ev)


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


def la_done():
    n = s32(A["next_qty"])
    if n <= 0:
        return
    phys = arr16(u32(A["qty_phys_reg"]), n)
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


def install():
    if "gcse" in HOOKS:
        Hook(A["cprop_copy_call"], cprop_call("copy", A["cprop_copy_call"] + 5))
        Hook(A["cprop_const_call"], cprop_call("const", A["cprop_const_call"] + 5))
    if "ga" in HOOKS:
        Hook(A["ga_after_qsort"], ga_after_qsort)
        Hook(A["find_reg"], find_reg_entry)
        for r in A["find_reg_rets"]:
            Hook(r, find_reg_ret)
    if "la" in HOOKS:
        Hook(A["block_alloc"], la_entry)
        Hook(A["la_sorted"], la_sorted)
        Hook(A["la_done"], la_done)
    if "sched" in HOOKS:
        Hook(A["schedule_block"], sb_entry)
        Hook(A["sched_sorted"], sched_sorted)
        Hook(A["sched_reordered"], sched_reordered)
        Hook(A["sched_pick"], sched_pick)
    if "reorg" in HOOKS:
        Hook(A["emit_delay_sequence"], delay_seq)


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
emit(ev="end", forces=FORCES)
OUT.close()
