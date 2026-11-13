#!/usr/bin/env python3
"""Static equivalence audit: does a (non-matching) unit still DO what the game's function does?

    python tools/equiv_audit.py func_00188620                  # src/nonmatching unit, else src/funcs
    python tools/equiv_audit.py func_00188620 --src work/try.cpp
    python tools/equiv_audit.py --all                          # every src/nonmatching unit
    python tools/equiv_audit.py --all --lo 0x280000 --hi 0x3478CC --json work/equiv.json -j2
    python tools/equiv_audit.py --funcs func_A func_B          # force the src/funcs copies (calibration)
    python tools/equiv_audit.py func_X --cflags "-O2 -G8 ..."  # experiment: other flags for ours
    python tools/equiv_audit.py func_X -v                      # also print every extracted fact
    python tools/equiv_audit.py --all -j2 --report work/equiv_report.txt   # ranked text report
    python tools/equiv_audit.py --from-json work/equiv.json --report r.txt  # re-render without compiling

A non-matching unit may differ from the game in registers, scheduling and block layout; this tool ignores all
of that and compares what the code observably does. Both objects come from match.compare (the game's asm
assembled, ours compiled); each is run through a small symbolic evaluator over its control-flow graph (a
forward "must" dataflow to a fixpoint: a register keeps a value at a block entry only when every predecessor
agrees; spilled values are followed through stack slots; a register written once in the whole function keeps
that value everywhere; jump-table cases start from the dispatch state). The callee's own asm decides which
argument registers a call really passes (a leftover temp in $a3 is not an argument):

  calls      ordered call targets (jal / tail `j` relocations; `jalr` through `lw t, OFF(vptr)` is reported as
             vcall+OFF) with the argument registers a0-a3/f12-f15 as set before the call: const, global
             address, sp, arg-relative (a0 = incoming this), loads from those, float literal, or not set in the
             block. Compared per target as multisets: a target on one side only, a count difference, a
             definite argument that differs (const 3 vs 4), a definite argument ours never sets.
  globals    the symbols every lo/gprel/jal relocation points into (data labels, vtables, functions; jump
             tables and hardware/scratchpad addresses excluded).
  memory     (base, offset, width, load/store) with base = incoming arg a0..a3 (followed through moves),
             a global, one dereference of those (*(a0+0x10)), or a linear index form (D_X+a1*0xCB0+a0*0x28:
             catches swapped indices); sp is ignored (frames differ). One-sided
             stores/loads and width/sign differences (sb vs sw, lb vs lbu) are flagged; a one-sided store names
             the other side's nearby offsets (field shifted by 4?).
  constants  values stored, compared (slti/beq vs li), passed, returned, or used as masks/32-bit keys
             (lui/ori); float literals (.lit4 bytes, mtc1 of a constant). One-sided values are flagged.

Score = sum of severity weights (10 strong, 4 medium, 1 weak); 0 means nothing flagged. A flag is a lead, not
proof: read the game's asm at the given address (MATCHING_GUIDE "Equivalence fixes need instruction-level proof").
Count differences of a call whose extra copies carry the same arguments are ranked medium (likely cross-jumping
or a duplicated tail), not strong. One-sided field accesses where the other side walks a pointer into the same
object are ranked weak.

Calibration (2026-11-13): 50 matched units score 0; the same 50 sources compiled with other flags (-O1, or
-fno-gcse -fno-schedule-insns2 -fno-strength-reduce: equivalent code, different shape) raise weak flags only.
Seeded bugs all flagged STRONG: int->char member (sw vs sb), a dropped 4th call argument, a changed const
argument, a changed 32-bit hash key, a field shifted by 4, swapped 2D indices, changed GS register values.
"""
import argparse
import bisect
import json
import os
import shlex
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
from common import BUILD, SRC_FUNCS, SRC_NONMATCHING, load_functions  # noqa: E402

from rabbitizer import Instruction, InstrCategory  # noqa: E402

LIT_LO, LIT_HI = 0x387400, 0x388258        # .lit4 (and .lit8 nearby): game float literals
STRONG, MEDIUM, WEAK = 10, 4, 1
GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
SAVED_G = set(range(16, 24)) | {30}
SAVED_F = set(range(20, 32))
ARG_G = (4, 5, 6, 7)
ARG_F = (12, 13, 14, 15)
M64 = (1 << 64) - 1
LOADS = {"lb": (1, 1), "lbu": (1, 0), "lh": (2, 1), "lhu": (2, 0), "lw": (4, 1), "lwu": (4, 0), "ld": (8, 1),
         "lq": (16, 1), "lwl": (4, 1), "lwr": (4, 1), "ldl": (8, 1), "ldr": (8, 1), "lwc1": (4, 2),
         "ldc1": (8, 2), "lqc2": (16, 2)}
STORES = {"sb": 1, "sh": 2, "sw": 4, "sd": 8, "sq": 16, "swl": 4, "swr": 4, "sdl": 8, "sdr": 8, "swc1": 4,
          "sdc1": 8, "sqc2": 16}
WNAME = {1: "b", 2: "h", 4: "w", 8: "d", 16: "q"}

_funcs = None
_labels = None
_jtbls = None


def jtbls():
    """Addresses of the game's switch jump tables (a unit may use branches instead: not a behaviour fact)."""
    global _jtbls
    if _jtbls is None:
        _jtbls = {int(n[5:], 16) for n in match.real_labels() if n.startswith("jtbl_")}
    return _jtbls


def func_addrs():
    global _funcs
    if _funcs is None:
        _funcs = {r["addr"]: r for r in load_functions()}
    return _funcs


def label_addrs():
    """Sorted addresses of every named label (functions, data), to name the symbol an address falls in."""
    global _labels
    if _labels is None:
        s = set(func_addrs())
        for n in match.real_labels():
            m = match.NAMED_ADDR.match(n)
            if m and not n.startswith(".L"):
                s.add(int(m.group(1), 16))
        for a in match.symbols().values():
            s.add(a)
        _labels = sorted(s)
    return _labels


def aname(a):
    if a is None:
        return "?"
    if isinstance(a, str):
        return a
    return f"func_{a:08X}" if a in func_addrs() else f"D_{a:08X}"


def owner(a):
    """'D_00393E80+0x8' for an address inside a labelled object."""
    if isinstance(a, str) or a is None:
        return aname(a)
    labs = label_addrs()
    k = bisect.bisect_right(labs, a) - 1
    if k >= 0 and 0 <= a - labs[k] < 0x10000:
        base = labs[k]
        return aname(base) + (f"+0x{a - base:X}" if a != base else "")
    return aname(a)


def owner_base(a):
    return owner(a).split("+")[0]


def s32(v):
    v &= 0xFFFFFFFF
    return v - (1 << 32) if v & 0x80000000 else v


def s64(v):
    v &= M64
    return v - (1 << 64) if v >> 63 else v


def hx(v):
    if -0x100 < v < 0x100:
        return str(v) if -10 < v < 10 else (f"-0x{-v:X}" if v < 0 else f"0x{v:X}")
    if -(1 << 31) <= v < (1 << 32):
        return f"0x{v & 0xFFFFFFFF:X}"
    return f"0x{v & M64:X}"


def fbits(b):
    """Float value of 4 literal bytes, printed compactly."""
    try:
        f = struct.unpack("<f", bytes(b[:4]))[0]
    except struct.error:
        return "?"
    return f"{f:.9g}f"


def ftext_bits(t):
    """The 32-bit pattern of a float fact's text, or None."""
    try:
        return int.from_bytes(struct.pack("<f", float(t[:-1])), "little")
    except (ValueError, OverflowError, struct.error):
        return None


def hw_addr(v):
    """Hardware register / scratchpad address (outside the image: 0x10000000-0x7FFFFFFF)."""
    return isinstance(v, int) and 0x10000000 <= (v & 0xFFFFFFFF) < 0x80000000


# ---- symbolic values ------------------------------------------------------------------------------------------
# ('c', int)            constant (64-bit, signed)
# ('g', addr|name)      address of a global (exact address incl. offset)
# ('hi', addr|name)     upper half of a global address (lui %hi)
# ('a', n, off)         incoming argument register n (0..3) plus off (a0 = this)
# ('sp', off)           stack address
# ('ld', key, off, w)   a value loaded from memory at base-key + off
# ('gi', key)           global/arg base plus an unknown index (array element address)
# ('f', text)           float constant
# ('?',)                set in this block, value unknown
UNK = ("?",)


def add(v, k):
    if v is None:
        return UNK
    t = v[0]
    if t == "c":
        return ("c", s64(v[1] + k))
    if t == "a":
        return ("a", v[1], v[2] + k)
    if t == "sp":
        return ("sp", v[1] + k)
    if t == "g":
        return ("g", v[1] + k) if isinstance(v[1], int) else ("g", f"{v[1]}+{k}")
    if t == "lin":
        return ("lin", v[1], v[2] + k)
    return UNK


def tolin(v):
    """(coefficients {var: k}, offset) for values linear in the incoming arguments / global bases."""
    if v is None:
        return None
    t = v[0]
    if t == "c":
        return {}, v[1]
    if t == "a":
        return {f"a{v[1]}": 1}, v[2]
    if t == "g" and isinstance(v[1], int):
        ob = owner_base(v[1])
        m = match.NAMED_ADDR.match(ob)
        if not m:
            return None
        return {"g:" + ob: 1}, v[1] - int(m.group(1), 16)
    if t == "lin":
        return dict(v[1]), v[2]
    return None


def fromlin(d, off):
    d = {k: c for k, c in d.items() if c}
    if not d:
        return ("c", s64(off))
    if len(d) == 1:
        (k, c), = d.items()
        if c == 1 and k.startswith("a"):
            return ("a", int(k[1]), off)
        if c == 1 and k.startswith("g:"):
            return ("g", int(k[-8:], 16) + off)
    return ("lin", tuple(sorted(d.items())), off)


def lin_combine(a, b, sign=1, scale_a=1):
    la, lb = tolin(a), tolin(b)
    if la is None or lb is None or (la[1] is None) or (lb[1] is None):
        return None
    d = defaultdict(int)
    for k, c in la[0].items():
        d[k] += c * scale_a
    for k, c in lb[0].items():
        d[k] += sign * c
    if not any(k.startswith("a") or k.startswith("g:") for k in d):
        return None
    return fromlin(d, la[1] * scale_a + sign * lb[1])


def lin_name(items):
    parts = []
    for k, c in items:
        nm = k if k.startswith("a") else k[2:]
        parts.append(nm if c == 1 else f"{nm}*{hx(c)}")
    return "+".join(parts)


def basekey(v, depth=0):
    """Canonical memory base for a pointer value, or None when it is unknown."""
    if v is None:
        return None
    t = v[0]
    if t == "c" and hw_addr(v[1]):
        return ("g", v[1] & 0xFFFFFFFF)
    if t == "a":
        return (f"a{v[1]}", v[2])
    if t == "sp":
        return ("sp", v[1])
    if t == "g":
        return ("g", v[1])
    if t == "ld" and depth == 0 and v[1] is not None and v[1][0] in ("a0", "a1", "a2", "a3", "g", "a0[]"):
        b = v[1]
        inner = f"{b[0]}+0x{b[1] + v[2]:X}" if b[0] != "g" else owner(b[1] + v[2] if isinstance(b[1], int)
                                                                        else b[1])
        return (f"*({inner})", 0)
    if t == "ld":
        return ("*?", 0)           # a pointer loaded from somewhere we do not name (vptr of a member...)
    if t == "gi":
        return v[1]
    if t == "lin":
        return ("L:" + lin_name(v[1]), v[2])
    return None


def bdesc(key, off):
    """Human form of a memory access."""
    b, o = key
    if b == "g":
        return owner(key[1] + off) if not isinstance(key[1], str) else f"{key[1]}+0x{off:X}"
    if b.startswith("L:"):
        tot = o + off
        return f"{b[2:]}{'+' if tot >= 0 else '-'}0x{abs(tot):X}"
    if b.startswith("a"):
        base = "this" if b.startswith("a0") else b[:2]
        tot = o + off
        return f"{base}{'[]' if b.endswith('[]') else ''}{'+' if tot >= 0 else '-'}0x{abs(tot):X}"
    tot = o + off
    return f"{b}+0x{tot:X}"


def norm_key(key, off):
    """(base, total offset) used to compare accesses: globals by absolute address."""
    b, o = key
    if b == "g":
        if isinstance(o, int):
            return ("g", o + off)
        return ("g", f"{o}+{off}")
    return (b, o + off)


def adesc(v):
    """Short text for an argument value; None for 'not set in this block'."""
    if v is None:
        return None
    t = v[0]
    if t == "c":
        return "c:" + hx(v[1])
    if t == "g":
        return "&" + (owner(v[1]) if isinstance(v[1], int) else v[1])
    if t == "a":
        return ("this" if v[1] == 0 else f"a{v[1]}") + (f"+0x{v[2]:X}" if v[2] > 0 else
                                                         (f"-0x{-v[2]:X}" if v[2] < 0 else ""))
    if t == "sp":
        return "sp"
    if t == "ld":
        k = v[1]
        if k is None or k[0] == "?":
            return "ld(?)"
        if k[0] == "sp":
            return "ld(sp)"
        if k[0] == "*?":
            return "ld(*?)"
        return "ld(" + bdesc(k, v[2]) + ")"
    if t == "f":
        return "f:" + v[1]
    if t == "lin":
        return "&" + lin_name(v[1]) + (f"+0x{v[2]:X}" if v[2] > 0 else (f"-0x{-v[2]:X}" if v[2] < 0 else ""))
    return "?"


def definite(d):
    return d is not None and d != "?" and not d.startswith("ld(?") and not d.startswith("ld(*?") \
        and d != "ld(sp)" and d != "sp"


# ---- the walk -----------------------------------------------------------------------------------------------

class Facts:
    def __init__(self):
        self.calls = []        # (target, (a0..a3, f12..f15 descs), index)
        self.refs = {}         # owner symbol -> first index
        self.mem = defaultdict(list)   # (normkey, 'L'|'S') -> [(width, sign/float, index, desc)]
        self.consts = defaultdict(list)  # value -> [(context, index)]
        self.floats = defaultdict(list)  # float text -> [index]
        self.refsym = {}       # owner symbol -> the symbol the relocation names (D_X for %lo(D_X+0xC))
        self.addr_taken = set()  # (base, off): field/global addresses put in a register (pointer walks)
        self.fbits = set()     # constants moved into an FPR (lui + mtc1 floats)
        self.written = []      # per call: arg registers written since the previous call


def lit_sections(path):
    """{section name: bytes} of an object's literal sections (for SN's gp-relative LITERAL relocations that
    match.read_obj cannot place: their addend is section offset - 0x4000)."""
    from elftools.elf.elffile import ELFFile
    out = {}
    try:
        with open(path, "rb") as fh:
            for sec in ELFFile(fh).iter_sections():
                if sec.name in match.LITERAL_SECTIONS:
                    out[sec.name] = sec.data()
    except OSError:
        pass
    return out


def walk(obj, func_addr, lits=None, params=None):
    """params: the incoming argument registers (from the game's asm); default all of a0-a3."""
    words, relocs = obj.words, obj.relocs
    n = len(words)
    ins = [Instruction(w, vram=func_addr + i * 4, category=InstrCategory.R5900) for i, w in enumerate(words)]
    end = func_addr + n * 4

    def reloc_target(i):
        r = relocs.get(i)
        if not r:
            return None
        return r[1] if r[1] is not None else r[2]

    # pass 1: labels (branch targets), def counts, first def / first call per arg register
    labels = set()
    gdefs, fdefs = Counter(), Counter()
    last_op = {}
    saves = {}              # (fpr?, reg) -> prologue save slot
    last_lui, lui_merged, lui_pair = {}, set(), {}
    for i, x in enumerate(ins):
        name = x.getOpcodeName()
        if x.isBranch() or (name == "j" and i in relocs):
            if x.isBranch():
                t = x.getBranchVramGeneric()
            else:
                t = reloc_target(i) if isinstance(reloc_target(i), int) else None
            if t is not None and func_addr <= t < end:
                labels.add((t - func_addr) // 4)
        if name in ("jal", "jalr"):
            gdefs[2] += 1          # return values
            gdefs[3] += 1
            fdefs[0] += 1
            fdefs[1] += 1
        raw0 = x.getRaw()
        if name in ("sd", "sq", "sdc1", "swc1") and ((raw0 >> 21) & 31) == 29 and \
                ((raw0 >> 16) & 31) in (SAVED_G | SAVED_F | {31}):
            saves.setdefault((name in ("sdc1", "swc1"), (raw0 >> 16) & 31), raw0 & 0xFFFF)
        if name in ("ld", "lq", "ldc1", "lwc1") and ((raw0 >> 21) & 31) == 29 and \
                saves.get((name in ("ldc1", "lwc1"), (raw0 >> 16) & 31)) == raw0 & 0xFFFF:
            continue            # epilogue restore of a callee-saved register (from its prologue slot)
        raw = x.getRaw()
        if name in ("ori", "addiu", "daddiu") and ((raw >> 21) & 31) == ((raw >> 16) & 31) and \
                last_op.get((raw >> 16) & 31) == "lui":
            last_op[(raw >> 16) & 31] = name
            lui_merged.add(last_lui[(raw >> 16) & 31])
            lui_pair[i] = True
            continue            # lui + ori/addiu build one 32-bit value: one definition
        if name == "lui":
            last_lui[(raw >> 16) & 31] = i
        for r in dest_gprs(x, name):
            last_op[r] = name
            gdefs[r] += 1
        fd = dest_fpr(x, name)
        if fd is not None:
            fdefs[fd] += 1
    # jump tables: every label in the asm counts too (case targets are not branch targets)

    facts = Facts()
    g = {}           # gpr -> value (absent = not set in this block)
    f = {}           # fpr -> value
    stable_g = {0: ("c", 0), 29: ("sp", 0), 28: ("gp",)}
    stable_f = {}
    params = set(ARG_G) if params is None else params
    for k, r in enumerate(ARG_G):
        if r in params:
            g[r] = ("a", k, 0)

    def rg(r, i):
        if r in stable_g:
            return stable_g[r]
        return g.get(r)

    def setg(r, v):
        if r == 0:
            return
        if v is not None and v[0] in ("a", "g") and not (v[0] == "a" and v[2] == 0):
            facts.addr_taken.add((f"a{v[1]}" if v[0] == "a" else "g", v[2] if v[0] == "a" else v[1]))
        # a register written once in the whole function holds that value at every use (compiled code never
        # reads a caller-saved register across a call it has not rewritten)
        if gdefs[r] == 1 and r not in ARG_G and v not in (None, UNK):
            stable_g[r] = v
        g[r] = v if v is not None else UNK

    def rf(r):
        return stable_f.get(r, f.get(r))

    def setf(r, v):
        if fdefs[r] == 1 and r not in ARG_F and v not in (None, UNK):
            stable_f[r] = v
        f[r] = v if v is not None else UNK

    def clear_call():
        for r in list(g):
            if isinstance(r, int) and r not in SAVED_G and r not in (28, 29):
                del g[r]
        for r in list(f):
            if r not in SAVED_F:
                del f[r]

    def const(ctx, v, i):
        if ctx == "imm32" and hw_addr(v) and v & 0xFFFF == 0:
            return              # upper half of a hardware/scratchpad address: compared as memory accesses
        facts.consts[s64(v)].append((ctx, i))

    def mem(i, x, name, base_v, ls, width, sign, data_v=None):
        r = relocs.get(i)
        off = x.getProcessedImmediate() if r is None else 0
        if r and r[0] in (match.R_MIPS_LO16, match.R_MIPS_GPREL16, match.R_MIPS_LITERAL):
            tgt = r[1] if r[1] is not None else r[2]
            if r[3] is not None or (isinstance(tgt, int) and LIT_LO <= tgt < LIT_HI):
                return None       # literal load, recorded as a float/int literal by the caller
            key = ("g", tgt)
        else:
            key = basekey(base_v)
        if key is not None and key[0] == "g" and key[1] in jtbls():
            return None
        if key is None or key[0] in ("sp", "*?"):
            return key
        nk = norm_key(key, off)
        facts.mem[(nk, ls)].append((width, sign, i, bdesc(key, off)))
        return key

    def literal(i):
        r = relocs.get(i)
        if not r or r[0] not in (match.R_MIPS_LO16, match.R_MIPS_GPREL16, match.R_MIPS_LITERAL):
            return None
        if r[3]:
            return r[3]
        if r[3] is not None:              # empty: SN as LITERAL addend (offset - 0x4000)
            data = (lits or {}).get(r[2], b"")
            off = match.sext16(words[i] & 0xFFFF) + 0x4000
            return data[off:off + 4] if 0 <= off < len(data) else b"????"
        if isinstance(r[1], int) and LIT_LO <= r[1] < LIT_HI:
            return match.read_orig(r[1], 4)
        return None

    def ref(i):
        r = relocs.get(i)
        if not r or r[0] == match.R_MIPS_HI16 or r[0] == match.R_MIPS_PC16:
            return
        tgt = r[1] if r[1] is not None else r[2]
        if r[3] is not None or (isinstance(tgt, int) and LIT_LO <= tgt < LIT_HI):
            return
        if isinstance(tgt, int) and func_addr <= tgt < end:
            return
        if isinstance(tgt, str) and (tgt.startswith(".") or tgt.startswith("jtbl")):
            return
        if isinstance(tgt, int) and (tgt in jtbls() or hw_addr(tgt)):
            return
        key = owner_base(tgt) if isinstance(tgt, int) else tgt
        facts.refs.setdefault(key, i)
        sym = r[2]
        m = match.NAMED_ADDR.match(sym)
        sa = int(m.group(1), 16) if m else match.EXTRA_SYMS.get(sym, match.symbols().get(sym))
        facts.refsym.setdefault(key, aname(sa) if sa is not None else sym)

    def step(i):
        """Apply instruction i to the state. Returns ('call', target) / ('ret',) / ('jump',) / None."""
        x = ins[i]
        name = x.getOpcodeName()
        r = relocs.get(i)
        ref(i)
        w = words[i]
        rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = x.getProcessedImmediate() if x.isIType() else 0

        if name == "lui":
            if r and r[0] == match.R_MIPS_HI16:
                setg(rt, ("hi", r[1] if r[1] is not None else r[2]))
            else:
                setg(rt, ("c", s32(imm << 16)))
                if i not in lui_merged:
                    const("imm32", s32(imm << 16), i)
            return None
        if name in ("addiu", "daddiu", "addi", "daddi", "ori"):
            if r and r[0] in (match.R_MIPS_LO16, match.R_MIPS_GPREL16):
                setg(rt, ("g", r[1] if r[1] is not None else r[2]))
                return None
            v = rg(rs, i)
            if name == "ori":
                if v and v[0] == "c":
                    setg(rt, ("c", v[1] | imm))
                    if rs == 0 and imm > 1:
                        const("li", imm, i)
                    if lui_pair.get(i) or (rs == rt and v[1] & 0xFFFF == 0 and v[1] and imm):
                        const("imm32", v[1] | imm, i)
                elif v and v[0] in ("sp", "a", "g"):
                    setg(rt, add(v, imm))         # ori on an aligned pointer is an add
                else:
                    if v is not None and v != UNK:
                        const("mask", imm, i)
                    setg(rt, UNK)
                return None
            nv = add(v, imm)
            if name in ("addiu", "addi") and nv[0] == "c":
                nv = ("c", s32(nv[1]))
            if rs == 0 and not lui_pair.get(i) and not (-2 < imm < 2):
                const("li", imm, i)
            if nv[0] == "c" and (lui_pair.get(i) or (rs == rt and v and v[0] == "c" and v[1] & 0xFFFF == 0
                                                     and v[1] and imm)):
                const("imm32", nv[1], i)
            setg(rt, nv)
            return None
        if name in ("andi", "xori"):
            v = rg(rs, i)
            if v and v[0] == "c":
                setg(rt, ("c", (v[1] & imm) if name == "andi" else (v[1] ^ imm)))
            else:
                if not (name == "xori" and imm == 1):
                    const("mask", imm, i)
                setg(rt, UNK)
            return None
        if name in ("slti", "sltiu"):
            const("cmp", imm, i)
            setg(rt, UNK)
            return None
        if name in ("addu", "daddu", "or", "subu", "dsubu", "xor", "and", "slt", "sltu", "nor", "dadd", "add"):
            a, b = rg(rs, i), rg(rt, i)
            if name in ("addu", "daddu", "or", "add", "dadd") and rt == 0:
                setg(rd, a)
                return None
            if name in ("addu", "daddu", "or") and rs == 0:
                setg(rd, b)
                return None
            ca = a is not None and a[0] == "c"
            cb = b is not None and b[0] == "c"
            if ca and cb:
                va, vb = a[1], b[1]
                res = {"addu": va + vb, "daddu": va + vb, "add": va + vb, "dadd": va + vb, "or": va | vb,
                       "subu": va - vb, "dsubu": va - vb, "xor": va ^ vb, "and": va & vb,
                       "slt": int(va < vb), "sltu": int((va & M64) < (vb & M64)), "nor": ~(va | vb)}[name]
                if name in ("addu", "subu", "add"):
                    res = s32(res)
                setg(rd, ("c", s64(res)))
                return None
            for v, other in ((a, b), (b, a)):
                if v is not None and v[0] == "c" and other is not None and other[0] != "c" and v[1] != 0:
                    ctx = "cmp" if name in ("slt", "sltu") else "op"
                    if not (name in ("addu", "daddu", "subu") and -0x8000 <= v[1] < 0x8000):
                        const(ctx, v[1], i)
            if name in ("addu", "daddu", "subu", "dsubu"):
                lv = lin_combine(a, b, -1 if name in ("subu", "dsubu") else 1)
                if lv is not None and lv[0] != "c":
                    setg(rd, lv)
                    return None
            if name in ("addu", "daddu"):
                for v, other in ((a, b), (b, a)):
                    if other is not None and other[0] == "c" and v is not None and v[0] in ("a", "g", "sp"):
                        setg(rd, add(v, other[1]))
                        return None
                for v in (a, b):
                    if v is not None and v[0] in ("a", "g"):
                        k = basekey(v)
                        setg(rd, ("gi", (k[0] + "[]", k[1]) if k[0] != "g" else ("g", k[1])))
                        return None
            setg(rd, UNK)
            return None
        if name in ("mult", "multu", "dmult"):
            a, b = rg(rs, i), rg(rt, i)
            res = UNK
            for v, other in ((a, b), (b, a)):
                if other is not None and other[0] == "c" and v is not None and v[0] in ("a", "lin"):
                    res = lin_combine(v, ("c", 0), 1, other[1]) or UNK
            lo[0] = res
            if rd:
                setg(rd, res)
            return None
        if name == "mflo":
            setg(rd, lo[0])
            return None
        if name in ("sll", "srl", "sra", "dsll", "dsrl", "dsra", "dsll32", "dsrl32", "dsra32"):
            v = rg(rt, i)
            sa = (w >> 6) & 31
            if name in ("sll", "dsll") and v is not None and v[0] in ("a", "lin"):
                setg(rd, lin_combine(v, ("c", 0), 1, 1 << sa) or UNK)
                return None
            if v is not None and v[0] == "c":
                val = v[1]
                if name == "sll":
                    res = s32(val << sa)
                elif name == "srl":
                    res = s32((val & 0xFFFFFFFF) >> sa)
                elif name == "sra":
                    res = s32(val) >> sa
                elif name == "dsll":
                    res = s64(val << sa)
                elif name == "dsll32":
                    res = s64(val << (sa + 32))
                elif name == "dsrl":
                    res = s64((val & M64) >> sa)
                elif name == "dsrl32":
                    res = s64((val & M64) >> (sa + 32))
                elif name == "dsra":
                    res = s64(val) >> sa
                else:
                    res = s64(val) >> (sa + 32)
                setg(rd, ("c", res))
            else:
                setg(rd, UNK)
            return None
        if name in LOADS:
            width, sign = LOADS[name]
            base = rg(rs, i)
            if name in ("lwc1", "ldc1"):
                lit = literal(i)
                ft = ((words[i] >> 16) & 31)
                if lit is not None:
                    txt = fbits(lit) if name == "lwc1" else lit.hex()
                    facts.floats[txt].append(i)
                    setf(ft, ("f", txt))
                    return None
                key = mem(i, x, name, base, "L", width, sign)
                setf(ft, ("ld", key, 0 if r else imm, width) if key else UNK)
                return None
            if name == "lqc2":
                mem(i, x, name, base, "L", width, sign)
                return None
            lit = literal(i)
            if lit is not None:
                v = int.from_bytes(lit[:4], "little", signed=True)
                const("lit", v, i)
                setg(rt, ("c", v))
                return None
            key = mem(i, x, name, base, "L", width, sign)
            if key is not None and key[0] == "sp" and width in (4, 8):
                setg(rt, g.get(("sp", key[1] + imm), UNK))      # a spilled value reloaded
                return None
            setg(rt, ("ld", key or ("?", 0), 0 if r else imm, width))
            return None
        if name in STORES:
            width = STORES[name]
            base = rg(rs, i)
            key = mem(i, x, name, base, "S", width, 2 if name in ("swc1", "sdc1", "sqc2") else 0)
            if name in ("swc1", "sdc1"):
                v = rf(((words[i] >> 16) & 31))
                if v is not None and v[0] == "f" and (key is None or key[0] != "sp"):
                    b = ftext_bits(v[1])
                    if b is not None:          # a float constant stored: same fact as `sw` of its bits
                        const("store.w", b, i)
            elif name != "sqc2":
                v = rg(rt, i)
                if key is not None and key[0] == "sp":
                    slot = ("sp", key[1] + imm)
                    if width in (4, 8) and v is not None and v != UNK:
                        g[slot] = v
                    else:
                        g.pop(slot, None)
                if v is not None and v[0] == "c" and (key is None or key[0] != "sp"):
                    const(f"store.{WNAME.get(width, width)}", v[1] & ((1 << (8 * width)) - 1) if width < 8
                          else v[1], i)
            return None
        if name == "mtc1":
            v = rg(rt, i)
            fs = ((words[i] >> 11) & 31)
            if v is not None and v[0] == "c":
                facts.fbits.add(s64(s32(v[1])))
                txt = fbits((v[1] & 0xFFFFFFFF).to_bytes(4, "little"))
                if v[1] != 0:
                    facts.floats[txt].append(i)
                setf(fs, ("f", txt))
            else:
                setf(fs, UNK)
            return None
        if name == "mov.s":
            setf(((words[i] >> 6) & 31), rf(((words[i] >> 11) & 31)))
            return None
        if name in ("jal", "jalr"):
            if name == "jal":
                tgt = r[1] if r and r[1] is not None else (r[2] if r else f"0x{x.getInstrIndexAsVram():08X}")
                return ("call", aname(tgt) if isinstance(tgt, int) else tgt)
            v = rg(rs, i)
            if v is not None and v[0] == "ld" and v[1] is not None and v[1][0].startswith("*"):
                return ("call", f"vcall+0x{v[2]:X}")
            if v is not None and v[0] == "ld":
                return ("call", f"icall[{adesc(v)}]")
            return ("call", "icall[?]")
        if name == "j":
            tgt = r[1] if r and r[1] is not None else (r[2] if r else x.getInstrIndexAsVram())
            if isinstance(tgt, int) and func_addr <= tgt < end:
                return ("jump", (tgt - func_addr) // 4)
            return ("tail", aname(tgt) if isinstance(tgt, int) else tgt)
        if name == "jr":
            if rs == 31:
                return ("ret",)
            return ("jump", None)
        if x.isBranch():
            if name in ("beq", "bne", "beql", "bnel"):
                for q in (rs, rt):
                    v = rg(q, i)
                    if v is not None and v[0] == "c" and v[1] != 0 and q != 0:
                        const("cmp", v[1], i)
            t = x.getBranchVramGeneric()
            ti = (t - func_addr) // 4 if func_addr <= t < end else None
            return ("br", x.isUnconditionalBranch(), x.isBranchLikely(), ti)
        # anything else: clobber its destinations
        for d in dest_gprs(x, name):
            setg(d, UNK)
        fd = dest_fpr(x, name)
        if fd is not None:
            setf(fd, UNK)
        return None

    def snapshot_args():
        out = []
        for k, r in enumerate(ARG_G):
            out.append(adesc(rg(r, i_cur[0])))
        for r in ARG_F:
            out.append(adesc(rf(r)))
        return tuple(out)

    i_cur = [0]
    lo = [UNK]
    wsince = set()                  # registers written since the previous call (32+n for FPRs), linear order

    # basic blocks: leaders are the entry, branch targets and the instruction after each delay slot
    leaders = {0} | {t for t in labels if t < n}
    for i, x in enumerate(ins):
        nm = x.getOpcodeName()
        if x.isBranch() or nm in ("j", "jr"):
            leaders.add(i + 2)
    starts = sorted(t for t in leaders if t < n)
    ends = {st: (starts[k + 1] if k + 1 < len(starts) else n) for k, st in enumerate(starts)}

    def run_block(st, in_g, in_f, final):
        """Run one block from its in-state. Returns [(successor start or 'jt', g, f)]."""
        g.clear()
        g.update(in_g)
        f.clear()
        f.update(in_f)
        lo[0] = UNK
        out = []
        i = st
        end = ends[st]
        while i < end:
            i_cur[0] = i
            res = step(i)
            if final:
                wsince.update(dest_gprs(ins[i], ins[i].getOpcodeName()))
                fdst = dest_fpr(ins[i], ins[i].getOpcodeName())
                if fdst is not None:
                    wsince.add(32 + fdst)
            if res is None:
                i += 1
                continue
            kind = res[0]
            if kind in ("call", "tail"):
                if i + 1 < n:
                    i_cur[0] = i + 1
                    step(i + 1)
                i_cur[0] = i + 1
                if final:
                    for d in dest_gprs(ins[i + 1], ins[i + 1].getOpcodeName()) if i + 1 < n else ():
                        wsince.add(d)
                    facts.calls.append((res[1], snapshot_args(), i, frozenset(wsince)))
                    wsince.clear()
                clear_call()
                if kind == "tail":
                    return out
                i += 2
                continue
            if kind == "ret":
                if i + 1 < n:
                    step(i + 1)
                v = g.get(2)
                if v is not None and v[0] == "c":
                    const("ret", v[1], i)
                fv = f.get(0)
                if fv is not None and fv[0] == "f":
                    facts.floats[fv[1]].append(i)
                return out
            if kind == "jump":
                if i + 1 < n:
                    step(i + 1)
                out.append(("jt" if res[1] is None else res[1], dict(g), dict(f)))
                return out
            if kind == "br":
                uncond, likely, ti = res[1], res[2], res[3]
                if i + 1 < n:
                    if likely and not uncond:
                        sg, sf = dict(g), dict(f)
                        step(i + 1)
                        if ti is not None:
                            out.append((ti, dict(g), dict(f)))
                        g.clear(), g.update(sg), f.clear(), f.update(sf)
                    else:
                        step(i + 1)
                        if ti is not None:
                            out.append((ti, dict(g), dict(f)))
                if not uncond and i + 2 < n:
                    out.append((i + 2, dict(g), dict(f)))
                return out
            i += 1
        if end < n:
            out.append((end, dict(g), dict(f)))
        return out

    def meet(states):
        if not states:
            return {}, {}
        rg_, rf_ = {}, {}
        for d, k in ((rg_, 0), (rf_, 1)):
            first = states[0][k]
            for r, v in first.items():
                if all(p[k].get(r) == v for p in states[1:]):
                    d[r] = v
        return rg_, rf_

    entry_g = dict(g)
    final_facts = facts
    # optimistic iteration to a fixpoint: a block's in-state is what all its computed predecessors agree on
    outs = {}                         # block start -> [(succ, g, f)]
    for _ in range(40):
        facts = Facts()               # throwaway while iterating
        changed = False
        ins_state = defaultdict(list)
        jt = []
        for st in starts:
            for succ, sg, sf in outs.get(st, []):
                if succ == "jt":
                    jt.append((sg, sf))
                else:
                    ins_state[succ].append((sg, sf))
        for st in starts:
            if st == 0:
                preds = [(entry_g, {})] + ins_state.get(0, [])
            else:
                preds = ins_state.get(st, []) or jt     # no known predecessor: a jump-table case
                if not preds:
                    continue          # optimistic: wait until a predecessor has been computed
            ig, if_ = meet(preds)
            o = run_block(st, ig, if_, False)
            if o != outs.get(st):
                outs[st] = o
                changed = True
        if not changed:
            break
    facts = final_facts
    ins_state = defaultdict(list)
    jt = []
    for st in starts:
        for succ, sg, sf in outs.get(st, []):
            (jt if succ == "jt" else ins_state[succ]).append((sg, sf))
    for st in starts:
        preds = [(entry_g, {})] + ins_state.get(0, []) if st == 0 else (ins_state.get(st, []) or jt)
        ig, if_ = meet(preds)
        run_block(st, ig, if_, True)
    return facts


def dest_gprs(x, name):
    w = x.getRaw()
    out = []
    if x.modifiesRd():
        out.append((w >> 11) & 31)
    if x.modifiesRt() and name not in ("lwc1", "ldc1", "swc1", "sdc1", "lqc2", "sqc2", "mtc1", "ctc1",
                                       "mtc2", "ctc2", "qmtc2"):
        out.append((w >> 16) & 31)
    if name in ("jal", "jalr"):
        out.append(31)
    return [r for r in out if r]


def dest_fpr(x, name):
    w = x.getRaw()
    if name in ("lwc1", "ldc1"):
        return (w >> 16) & 31
    if name == "mtc1":
        return (w >> 11) & 31
    if x.isFloat() and x.modifiesFd():
        return (w >> 6) & 31
    return None


# ---- comparison -----------------------------------------------------------------------------------------------

def arg_score(a, b):
    return sum(1 for x, y in zip(a, b) if x == y)


ARGN = ["a0", "a1", "a2", "a3", "f12", "f13", "f14", "f15"]
ARGREG = [4, 5, 6, 7, 32 + 12, 32 + 13, 32 + 14, 32 + 15]
_reads = {}


def callee_reads(target, depth=0):
    """Argument registers (4..7, 32+12..32+15) the game's callee reads before writing them, from its asm;
    None when unknown (indirect call, no such function)."""
    if not target.startswith("func_"):
        return None
    try:
        addr = int(target[5:13], 16)
    except ValueError:
        return None
    if target in _reads:
        return _reads[target]
    row = func_addrs().get(addr)
    data = match.read_orig(addr, row["size"]) if row else None
    if not data:
        return None
    _reads[target] = None            # recursion guard
    written, reads, spilled = set(), set(), set()
    clobber = False
    for k in range(0, len(data) - 3, 4):
        w = int.from_bytes(data[k:k + 4], "little")
        x = Instruction(w, vram=addr + k, category=InstrCategory.R5900)
        name = x.getOpcodeName()
        used = []
        try:
            if x.readsRs():
                used.append((w >> 21) & 31)
            if x.readsRt():
                used.append((w >> 16) & 31)
            if x.readsFs():
                used.append(32 + ((w >> 11) & 31))
            if x.readsFt():
                used.append(32 + ((w >> 16) & 31))
        except Exception:      # noqa: BLE001
            pass
        if name in ("swc1", "sdc1"):
            used.append(32 + ((w >> 16) & 31))
        if name in ("sw", "sd", "sq", "swc1", "sdc1") and (w >> 21) & 31 == 29:
            r_ = ((w >> 16) & 31) + (32 if name in ("swc1", "sdc1") else 0)
            if r_ in ARGREG and r_ not in written:
                spilled.add(r_)        # a varargs prologue spills every argument register
                continue
        reads.update(r for r in used if r in ARGREG and r not in written)
        if clobber:
            written.update(ARGREG)
            clobber = False
        written.update(dest_gprs(x, name))
        fd = dest_fpr(x, name)
        if fd is not None:
            written.add(32 + fd)
        if name in ("jal", "jalr"):
            clobber = True           # after the delay slot
        elif name == "j" and depth < 3:
            t = x.getInstrIndexAsVram()
            if not (addr <= t < addr + row["size"]) and t in func_addrs():
                sub = callee_reads(f"func_{t:08X}", depth + 1)
                reads.update(ARGREG if sub is None else (sub - written))
    if not ({7, 6} <= spilled or {44, 46} <= spilled):
        reads |= spilled               # an ordinary spill of a real argument
    _reads[target] = frozenset(reads)
    return _reads[target]


def raw_hi(sym, other):
    """Does the other side build this symbol's %hi as a plain lui constant (an unsymbolised address)?"""
    m = match.NAMED_ADDR.match(sym)
    if not m:
        return False
    hi = ((int(m.group(1), 16) + 0x8000) >> 16) & 0xFFFF
    return any(v & 0xFFFF == 0 and ((v >> 16) & 0xFFFF) == hi and {c for c, _ in u} == {"imm32"}
               for v, u in other.consts.items())


def diff_facts(gf, of, base, our_base=None):
    """[(severity, text)] for game facts gf vs our facts of."""
    out = []

    def ga(i):
        return f"{base + i * 4:08X}"

    # calls
    gc, oc = defaultdict(list), defaultdict(list)
    for t, args, i, _ in gf.calls:
        gc[t].append((args, i))
    for t, args, i, wr in of.calls:
        oc[t].append((args, i, wr))
    for t in sorted(set(gc) | set(oc)):
        reads = callee_reads(t)

        def proj(c, reads=reads):
            if reads is None:
                return c
            return (tuple(a if ARGREG[k] in reads else None for k, a in enumerate(c[0])),) + tuple(c[1:])
        G = [proj(c) for c in gc.get(t, [])]
        O = [proj(c) for c in oc.get(t, [])]
        if not O:
            out.append((STRONG, f"call {t}: game {len(G)}x (first at {ga(G[0][1])}), ours never"))
            continue
        if not G:
            out.append((STRONG, f"call {t}: ours {len(O)}x, game never"))
            continue
        # remove identical signatures, then pair the rest by similarity
        Gr, Or = [], list(O)
        for g in G:
            k = next((j for j, o in enumerate(Or) if o[0] == g[0]), None)
            if k is None:
                Gr.append(g)
            else:
                Or.pop(k)
        pairs = []
        for g in Gr:
            if not Or:
                break
            k = max(range(len(Or)), key=lambda j: arg_score(g[0], Or[j][0]))
            pairs.append((g, Or.pop(k)))
        Gleft = Gr[len(pairs):]
        for g, o in pairs:
            for k, (x, y) in enumerate(zip(g[0], o[0])):
                if x == y:
                    continue
                if reads is not None and ARGREG[k] not in reads:
                    continue          # the callee never reads this register: a leftover temp
                if definite(x) and definite(y):
                    sev = STRONG if (x[:2] in ("c:", "f:") or x[0] == "&" or y[:2] in ("c:", "f:") or y[0] == "&") \
                        else MEDIUM
                    out.append((sev, f"call {t} at {ga(g[1])}: arg {ARGN[k]} game {x}, ours {y}"))
                elif definite(x) and y is None and (x[:2] in ("c:", "f:") or x[0] == "&"):
                    sev = STRONG if reads is not None and ARGREG[k] not in o[2] else MEDIUM
                    out.append((sev, f"call {t} at {ga(g[1])}: arg {ARGN[k]} game {x}, ours not set "
                                     "before the call" + (" (never written since the previous call: missing "
                                                          "argument?)" if sev == STRONG else "")))
                elif definite(y) and x is None and (y[:2] in ("c:", "f:") or y[0] == "&"):
                    out.append((WEAK, f"call {t} at {ga(g[1])}: arg {ARGN[k]} ours {y}, game not set in block"))
        if len(G) != len(O):
            extra = Gleft or Or
            same_args = all(any(e[0] == z[0] for z in (O if Gleft else G)) for e in extra)
            sev = MEDIUM if same_args or (len(G) and len(O)) else STRONG
            if not same_args:
                sev = STRONG
            out.append((sev, f"call {t}: game {len(G)}x, ours {len(O)}x"
                             + (" (extra copies have the same arguments: cross-jump/duplicated tail?)"
                                if same_args else "")))

    # globals
    gsyms, osyms = set(gf.refsym.values()) | set(gf.refs), set(of.refsym.values()) | set(of.refs)
    for s in sorted(set(gf.refs) - set(of.refs)):
        if s.startswith("func_") and s in {c[0] for c in gf.calls}:
            continue
        if gf.refsym.get(s) in osyms:
            continue          # same symbol, another label inside it (D_X+0xC vs D_X+0xC's own label)
        if raw_hi(s, of):
            continue
        out.append((STRONG, f"global {s}: game references it (at {ga(gf.refs[s])}), ours never"))
    for s in sorted(set(of.refs) - set(gf.refs)):
        if s.startswith("func_") and s in {c[0] for c in of.calls}:
            continue
        if of.refsym.get(s) in gsyms:
            continue
        if raw_hi(s, gf):
            continue
        out.append((STRONG, f"global {s}: ours references it, game never"))

    # memory
    keys = set(gf.mem) | set(of.mem)
    by_base = defaultdict(lambda: defaultdict(set))   # (side, base, ls) -> offsets
    for side, F in (("g", gf), ("o", of)):
        for (nk, ls) in F.mem:
            by_base[(side, nk[0], ls)][nk[1]] = True
    for key in sorted(keys, key=lambda k: (str(k[0][0]), str(k[0][1]), k[1])):
        (b, off), ls = key
        G, O = gf.mem.get(key, []), of.mem.get(key, [])
        argbase = b.startswith("a") or b == "g" or b.startswith("L:")
        deref = b.startswith("*(")
        what = "store" if ls == "S" else "load"
        if G and O:
            gw = {(w, s) for w, s, _, _ in G}
            ow = {(w, s) for w, s, _, _ in O}
            if gw != ow:
                def fw(ws, ls=ls):
                    return "/".join(sorted(("s" if ls == "S" else "l") + WNAME.get(w, str(w))
                                           + ("u" if s == 0 and ls == "L" and w < 8 else "")
                                           + ("c1" if s == 2 else "") for w, s in ws))
                gwid = {w for w, _ in gw}
                owid = {w for w, _ in ow}
                if gwid != owid:
                    sev = STRONG if ls == "S" else MEDIUM
                else:
                    sev = MEDIUM if ls == "L" else WEAK
                if deref and sev > WEAK:
                    sev = MEDIUM
                out.append((sev, f"{what} width at {G[0][3]} ({ga(G[0][2])}): game {fw(gw)}, ours {fw(ow)}"))
            continue
        if not (argbase or deref) or b.endswith("[]") or b == "sp":
            continue
        if b == "g" and isinstance(off, str):
            continue
        side, F, other = ("game", G, "o") if G else ("ours", O, "g")
        this_side = gf.mem if side == "game" else of.mem
        near = sorted(o for o in by_base.get((other, b, ls), {})
                      if isinstance(o, int) and isinstance(off, int) and 0 < abs(o - off) <= 8
                      and ((b, o), ls) not in this_side)
        hint = ""
        if near:
            near_txt = ", ".join(bdesc((b, 0), o) if b != "g" else owner(o) for o in near)
            hint = f" ({'game' if other == 'g' else 'ours'} {what}s {near_txt})"
        if deref:
            sev = MEDIUM if ls == "S" else WEAK
        else:
            sev = STRONG if ls == "S" else MEDIUM
        oth = of if side == "game" else gf
        walked = [o for bb, o in oth.addr_taken if bb == b and isinstance(o, int) and isinstance(off, int)
                  and o <= off < o + 0x400]
        if b == "g" and isinstance(off, int) and owner_base(off) in oth.refs:
            walked.append(off)
        if walked:
            sev = WEAK         # the other side takes the address and walks it with a pointer
            hint += f" ({'ours' if side == 'game' else 'game'} uses a pointer into it)"
        loc = f" ({ga(F[0][2])})" if side == "game" else ""
        out.append((sev, f"{what} {F[0][3]}{loc}: {side} only{hint}"))

    # constants
    gk, ok = set(gf.consts), set(of.consts)
    for v in sorted(gk ^ ok):
        side = "game" if v in gk else "ours"
        uses = (gf if v in gk else of).consts[v]
        ctxs = sorted({c for c, _ in uses})
        oth = of if v in gk else gf
        if ctxs == ["imm32"] and v & 0xFFFF == 0 and any((x >> 16) == (v >> 16) for x in oth.consts):
            continue                  # a lui whose low half is added in another block
        if ctxs == ["imm32"] and s64(s32(v)) in (gf if v in gk else of).fbits:
            continue                  # float bits (lui + mtc1): compared as floats
        if ctxs == ["imm32"] and v & 0xFFFF == 0 and any(
                ((int(m.group(1), 16) + 0x8000) >> 16) == ((v >> 16) & 0xFFFF)
                for m in (match.NAMED_ADDR.match(x) for x in oth.refs) if m):
            continue                  # a raw %hi the splitter left unsymbolised vs the other side's symbol
        big = not (-0x100 < v < 0x100)
        if ctxs and set(ctxs) <= {"cmp", "li"} and any(
                (v + d) in oth.consts and any(c in ("cmp", "li") for c, _ in oth.consts[v + d])
                for d in (-1, 1)):
            out.append((WEAK, f"const {hx(v)} ({','.join(ctxs)}): {side} only, the other side compares "
                              "against it +-1 (`x > K` vs `x >= K+1`?)"))
            continue
        strong_ctx = any(c.startswith("store") or c in ("ret", "lit") for c in ctxs)
        if big and (strong_ctx or any(c in ("cmp", "mask", "op") for c in ctxs)):
            sev = STRONG
        elif strong_ctx or big:
            sev = MEDIUM
        else:
            sev = WEAK
        loc = f" at {ga(uses[0][1])}" if side == "game" else ""
        out.append((sev, f"const {hx(v)} ({','.join(ctxs)}): {side} only{loc}"))
    gall = set(gf.consts) | {s64(s32(b)) for b in map(ftext_bits, gf.floats) if b is not None}
    oall = set(of.consts) | {s64(s32(b)) for b in map(ftext_bits, of.floats) if b is not None}
    for v in sorted(set(gf.floats) ^ set(of.floats)):
        side = "game" if v in gf.floats else "ours"
        b = ftext_bits(v)
        if b is not None and (b == 0 or s64(s32(b)) in (oall if side == "game" else gall)):
            continue              # the same bits appear as an integer constant on the other side
        loc = f" at {ga(gf.floats[v][0])}" if side == "game" else ""
        out.append((STRONG, f"float {v}: {side} only{loc}"))
    out.sort(key=lambda x: -x[0])
    return out


def unit_src(name, prefer_funcs=False):
    nm = SRC_NONMATCHING / f"{name}.cpp"
    fu = SRC_FUNCS / f"{name}.cpp"
    for p in ((fu, nm) if prefer_funcs else (nm, fu)):
        if p.exists():
            return p
    return None


def audit(name, src=None, cflags=None, outdir=None, prefer_funcs=False):
    src = Path(src) if src else unit_src(name, prefer_funcs)
    if src is None:
        return {"name": name, "error": "no unit source", "score": -1, "flags": []}
    outdir = outdir or BUILD / "equiv" / f"w{os.getpid()}"
    try:
        res = match.compare(name, str(src), None, cflags, outdir)
    except Exception as e:      # noqa: BLE001
        return {"name": name, "src": str(src), "error": f"{type(e).__name__}: {e}", "score": -1, "flags": []}
    if res.error:
        return {"name": name, "src": str(src), "error": res.error.strip().splitlines()[-1][:300] if res.error.strip()
                else "error", "score": -1, "flags": []}
    base = match.func_row(name)["addr"]
    od = Path(outdir)
    params = callee_reads(f"func_{base:08X}")
    params = {r for r in ARG_G if r in params} if params is not None else None
    gf = walk(res.target, base, lit_sections(od / "target" / f"{name}.o"), params)
    of = walk(res.ours, base, lit_sections(od / f"{name}.o"), params)
    flags = diff_facts(gf, of, base)
    return {"name": name, "src": str(src), "match": res.ok, "score": sum(s for s, _ in flags),
            "flags": [[s, t] for s, t in flags], "game": gf, "ours": of}


def dump_facts(F, base):
    for t, args, i, _ in F.calls:
        print(f"    call {t:<24} {base + i * 4:08X}  " + " ".join(f"{ARGN[k]}={a}" for k, a in enumerate(args)
                                                                 if a is not None))
    for (nk, ls), L in sorted(F.mem.items(), key=lambda kv: str(kv[0])):
        print(f"    {ls} {L[0][3]:<28} " + ",".join(sorted({WNAME.get(w, '?') + str(s) for w, s, _, _ in L})))
    print("    refs " + " ".join(sorted(F.refs)))
    print("    consts " + " ".join(f"{hx(v)}:{'/'.join(sorted({c for c, _ in u}))}" for v, u in
                                   sorted(F.consts.items())))
    print("    floats " + " ".join(sorted(F.floats)))


SEVN = {STRONG: "STRONG", MEDIUM: "medium", WEAK: "weak"}


def fmt(r, verbose=False):
    lines = []
    if r.get("error"):
        return [f"{r['name']}: ERROR {r['error']}"]
    tag = " (exact MATCH)" if r.get("match") else ""
    lines.append(f"{r['name']}: score {r['score']}{tag}" + ("" if r["flags"] else "  ok"))
    for s, t in r["flags"]:
        lines.append(f"    [{SEVN[s]:<6}] {t}")
    return lines


def _work(args):
    name, src, cflags, prefer = args
    r = audit(name, src, cflags, None, prefer)
    r.pop("game", None)
    r.pop("ours", None)
    return r


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("names", nargs="*")
    ap.add_argument("--all", action="store_true", help="every src/nonmatching unit")
    ap.add_argument("--lo", type=lambda s: int(s, 16), default=0)
    ap.add_argument("--hi", type=lambda s: int(s, 16), default=1 << 32)
    ap.add_argument("--src", help="a draft to audit instead of the unit (one NAME)")
    ap.add_argument("--funcs", action="store_true", help="prefer src/funcs over src/nonmatching")
    ap.add_argument("--cflags", help="experiment: replace the pinned cflags for ours")
    ap.add_argument("--json", help="write all results here")
    ap.add_argument("-j", type=int, default=1, help="parallel compiles (keep it at 1-2 on a shared machine)")
    ap.add_argument("-v", action="store_true", help="also print the extracted facts")
    ap.add_argument("--report", help="write a ranked text report (units by score, with their flags) here")
    ap.add_argument("--from-json", help="re-render --report from an earlier --json instead of compiling")
    a = ap.parse_args()
    if a.from_json:
        results = json.loads(Path(a.from_json).read_text())
        write_report(results, a.report)
        return

    names = list(a.names)
    if a.all:
        names += sorted(p.stem for p in SRC_NONMATCHING.glob("func_*.cpp"))
    names = [n for n in names if a.lo <= int(n[5:13], 16) < a.hi] if (a.all or a.lo or a.hi < 1 << 32) else names
    if not names:
        ap.error("no units")
    cflags = shlex.split(a.cflags) if a.cflags else None
    jobs = [(n, a.src if len(names) == 1 else None, cflags, a.funcs) for n in names]
    results = []
    if a.v and len(names) == 1:
        r = audit(names[0], a.src, cflags, None, a.funcs)
        if not r.get("error"):
            base = match.func_row(names[0])["addr"]
            print("  game:")
            dump_facts(r["game"], base)
            print("  ours:")
            dump_facts(r["ours"], base)
        r.pop("game", None)
        r.pop("ours", None)
        results = [r]
        print("\n".join(fmt(r)))
    elif a.j > 1 and len(names) > 1:
        from multiprocessing import Pool
        with Pool(a.j) as pool:
            for r in pool.imap_unordered(_work, jobs):
                results.append(r)
                print("\n".join(fmt(r)), flush=True)
    else:
        for j in jobs:
            r = _work(j)
            results.append(r)
            print("\n".join(fmt(r)), flush=True)
    if len(results) > 1:
        flagged = sum(1 for r in results if r.get("score", 0) > 0)
        err = sum(1 for r in results if r.get("error"))
        print(f"\n{flagged} flagged / {len(results)} units ({err} errors)")
    if a.json:
        Path(a.json).write_text(json.dumps(sorted(results, key=lambda r: -r.get("score", 0)), indent=1))
    if a.report:
        write_report(results, a.report)


def write_report(results, path):
    results = sorted(results, key=lambda r: (-r.get("score", 0), r["name"]))
    ok = [r for r in results if not r.get("error")]
    flagged = [r for r in ok if r["score"] > 0]
    strong = [r for r in ok if any(s == STRONG for s, _ in r["flags"])]
    medium = [r for r in ok if not any(s == STRONG for s, _ in r["flags"]) and any(s == MEDIUM for s, _ in r["flags"])]
    errs = [r for r in results if r.get("error")]
    lines = ["equiv_audit.py report: static behaviour facts of each unit vs the game's function",
             f"{len(flagged)} flagged / {len(ok)} audited ({len(strong)} with a STRONG flag, {len(medium)} with "
             f"medium at most, {len(flagged) - len(strong) - len(medium)} weak only; {len(errs)} errors)",
             "A flag is a lead to check against the game's asm, not proof of a bug.", ""]
    for r in results:
        if r.get("score", 0) > 0 or r.get("error"):
            lines += fmt(r)
    lines += ["", "clean (score 0): " + " ".join(r["name"] for r in ok if r["score"] == 0)]
    text = "\n".join(lines) + "\n"
    if path:
        Path(path).write_text(text)
    else:
        print(text)


if __name__ == "__main__":
    main()
