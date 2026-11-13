#!/usr/bin/env python3
"""Where in the source is the mismatch? Annotate a unit's C++ lines with how well their code matches the game.

    python tools/diffmap.py func_001780F0                    # src/funcs or src/nonmatching unit
    python tools/diffmap.py func_001780F0 --src work/try.cpp
    python tools/diffmap.py func_001780F0 --html work/diffmap.html   # side-by-side heat view
    python tools/diffmap.py func_001780F0 --callsite         # charge inlined code to the calling statement
    python tools/diffmap.py func_001780F0 --regions 20 --asm # more regions, with the game's asm for each
    python tools/diffmap.py func_001780F0 --json out.json    # machine-readable (shapedb.py query reads it)
    python tools/diffmap.py func_001780F0 --knob             # DIAGNOSTIC: which pass-isolating flag
                                                             # (-fno-gcse, -fforce-addr, ...) removes which region

1. The unit is compiled as match.py does (match.compare: our object and the game's), and once more with -g
   (tools/srcmap.py): the stabs line notes map every word of ours to the C++ line that produced it. The two
   compiles are checked to give the same code.
2. Our words are aligned with the game's the way match.fuzzy aligns them (difflib over instruction shapes,
   registers ignored), and every non-aligned stretch is aligned again on the opcode alone. Each word is then
   one of
        ok     the same instruction (relocations resolve to the same place)
        reg    the same instruction with other registers (fuzzy gives it half credit)
        diff   paired with a game instruction of the same opcode but another immediate/target
        extra  ours only (the game has nothing there)
        miss   the game's only: charged to the source line of the nearest word of ours before it
3. Output: the source with per-line counts and a heat mark, then the worst regions (runs of non-ok words,
   with game address range and the source lines involved), worst first.

Inlined code carries the line numbers of the inline function's body (gcc 2.95 records no call site); with
--callsite it is charged to the last line of the function body seen before it in our code instead.
"""
import argparse
import difflib
import html
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import srcmap  # noqa: E402
from rtl_dumps import find_source, same_code  # noqa: E402

KINDS = ("ok", "reg", "diff", "extra", "miss")
WEIGHT = {"ok": 0.0, "reg": 0.5, "diff": 1.0, "extra": 1.0, "miss": 1.0}


def opkey(w):
    """The opcode alone (no registers, no immediate)."""
    op = w >> 26
    if op == 0:
        return w & 0xFC00003F
    if op == 1:                       # REGIMM: rt selects the branch
        return w & 0xFC1F0000
    if op in (0x10, 0x11, 0x12):
        return w & 0xFFE0003F
    if op == 0x1C:                    # MMI
        return w & 0xFC0007FF
    return w & 0xFC000000


def align(res):
    """[(kind, our index or None, game index or None)] in order."""
    a, b = match._norm(res.ours), match._norm(res.target)
    sa, sb = [match._shape(w) for w in a], [match._shape(w) for w in b]
    base = match.func_row(res.name)["addr"] if res.name else 0
    out = []

    def same(i, j):
        tr, orr = res.target.relocs.get(j), res.ours.relocs.get(i)
        tw, ow = res.target.words[j], res.ours.words[i]
        if tr or orr:
            return match.reloc_equal(tr, orr, base + j * 4, tw, ow)
        return tw == ow

    def fill(i0, i1, j0, j1):
        """Non-aligned stretch: align again on opcodes alone."""
        ka, kb = [opkey(w) for w in a[i0:i1]], [opkey(w) for w in b[j0:j1]]
        sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
        pi, pj = 0, 0
        for blk in sm.get_matching_blocks():
            for k in range(pi, blk.a):
                out.append(("extra", i0 + k, None))
            for k in range(pj, blk.b):
                out.append(("miss", None, j0 + k))
            for k in range(blk.size):
                out.append(("diff", i0 + blk.a + k, j0 + blk.b + k))
            pi, pj = blk.a + blk.size, blk.b + blk.size

    sm = difflib.SequenceMatcher(None, sa, sb, autojunk=False)
    pi, pj = 0, 0
    for blk in sm.get_matching_blocks():
        if blk.a > pi or blk.b > pj:
            fill(pi, blk.a, pj, blk.b)
        for k in range(blk.size):
            i, j = blk.a + k, blk.b + k
            if a[i] == b[j]:
                out.append(("ok" if same(i, j) else "diff", i, j))
            else:
                out.append(("reg", i, j))
        pi, pj = blk.a + blk.size, blk.b + blk.size
    return out


def attribute(ops, lm, callsite=False):
    """Give every op a source position (file, line): ours from the line map, misses from the word of ours
    before them (or the first word). Returns (positions, call sites): the call site is the last line of the
    function body seen at that point (equal to the position for code that is not inlined)."""
    def where(i):
        return lm.lines[i] if i < len(lm.lines) else None

    def site(i):
        fl = where(i)
        if fl and lm.is_unit(fl) and lm.body[0] <= fl[1] <= lm.body[1]:
            return fl
        v = lm.via[i] if i < len(lm.via) else None
        return (lm.unit_file, v) if v else fl

    pos, sites = [], []
    last, last_s = None, None
    for kind, i, j in ops:
        if i is not None:
            last, last_s = where(i), site(i)
        pos.append(last)
        sites.append(last_s)
    for k in range(len(pos)):          # leading misses (before any word of ours): the first word's line
        if pos[k] is not None:
            break
        if lm.lines:
            pos[k], sites[k] = where(0), site(0)
    if callsite:
        return sites, sites
    return pos, sites


def moved(ops, res, min_len=6, min_ratio=0.7):
    """Code the monotonic alignment could not pair because it sits elsewhere: a run of our extra words whose
    shapes match a run of the game's missing words at another place (block order, cross-jumping keeping
    another copy, a loop rotated differently). [(ratio, our (i0, i1), game (j0, j1))], best first."""
    def runs(kind, idx):
        out, cur = [], None
        for k, op in enumerate(ops):
            if op[0] == kind:
                v = op[idx]
                if cur and v == cur[1] + 1:
                    cur[1] = v
                else:
                    cur = [v, v]
                    out.append(cur)
            elif op[0] not in ("reg", "diff"):      # short reg/diff interruptions do not end a run
                cur = None if op[0] == "ok" else cur
        return [r for r in out if r[1] - r[0] + 1 >= min_len]
    ex, mi = runs("extra", 1), runs("miss", 2)
    sa = [match._shape(w) for w in match._norm(res.ours)]
    sb = [match._shape(w) for w in match._norm(res.target)]
    cand = []
    for e in ex:
        for m in mi:
            x, y = sa[e[0]:e[1] + 1], sb[m[0]:m[1] + 1]
            sm = difflib.SequenceMatcher(None, x, y, autojunk=False)
            if sm.real_quick_ratio() < min_ratio or sm.quick_ratio() < min_ratio:
                continue
            r = sm.ratio()
            if r >= min_ratio:
                cand.append((r * min(len(x), len(y)), r, tuple(e), tuple(m)))
    cand.sort(reverse=True)
    used_e, used_m, out = set(), set(), []
    for _, r, e, m in cand:
        if e in used_e or m in used_m:
            continue
        used_e.add(e)
        used_m.add(m)
        out.append((r, e, m))
    return out


def compare_tree(words, base):
    """{constant: target word index} for `beq x, reg` where reg holds a constant built by lui/ori/addiu/li
    (gcc's compare tree for a sparse switch); the first compare of each constant wins."""
    from rabbitizer import Instruction, InstrCategory
    vals, out = {}, {}
    for k, w in enumerate(words):
        ins = Instruction(w, vram=base + 4 * k, category=InstrCategory.R5900)
        op = ins.getOpcodeName()
        if op in ("beq", "beql", "bne", "bnel"):
            a, b = ins.rs.value, ins.rt.value
            c = vals.get(b, vals.get(a)) if b != 0 else None
            if c is not None and op.startswith("beq"):
                t = (ins.getBranchVramGeneric() - base) // 4 - (1 if op == "beql" else 0)
                if 0 <= t < len(words):
                    out.setdefault(c & 0xFFFFFFFF, t)
            continue
        d = ins.getDestinationGpr()
        if d is None:
            continue
        d = d.value
        imm = ins.getProcessedImmediate() if ins.isIType() else None
        if op == "lui":
            vals[d] = (imm & 0xFFFF) << 16
        elif op == "ori" and ins.rs.value in vals:
            vals[d] = vals[ins.rs.value] | (imm & 0xFFFF)
        elif op in ("ori", "addiu") and ins.rs.value == 0:
            vals[d] = imm
        else:
            vals.pop(d, None)
    return out


def switch_order(res, lm):
    """Case bodies laid out in another order than the game's: [(constant, game target, our target, line)] in the
    game's body order, or [] when the orders agree. gcc lays out case bodies in source order."""
    base = match.func_row(res.name)["addr"]
    g, o = compare_tree(res.target.words, base), compare_tree(res.ours.words, base)
    common = [c for c in g if c in o]
    if len(common) < 3:
        return []
    by_game = sorted(common, key=lambda c: g[c])
    by_ours = sorted(common, key=lambda c: o[c])
    if by_game == by_ours:
        return []
    out = []
    for c in by_game:
        fl = lm.lines[o[c]] if o[c] < len(lm.lines) else None
        out.append((c, g[c], o[c], fl[1] if fl else None))
    return out


def regions(ops, pos, sites=None, gap=2):
    """Runs of non-ok ops, merged across short ok stretches; worst (by weight) first."""
    runs, cur, oks = [], None, 0
    for k, (kind, i, j) in enumerate(ops):
        if kind == "ok":
            if cur is not None:
                oks += 1
                if oks > gap:
                    runs.append(cur)
                    cur, oks = None, 0
            continue
        if cur is None:
            cur = [k, k]
        cur[1] = k
        oks = 0
    if cur is not None:
        runs.append(cur)
    out = []
    for s, e in runs:
        seg = ops[s:e + 1]
        cnt = defaultdict(int)
        for kind, _, _ in seg:
            cnt[kind] += 1
        w = sum(WEIGHT[kd] * n for kd, n in cnt.items())
        js = [j for _, _, j in seg if j is not None]
        iss = [i for _, i, _ in seg if i is not None]
        lines = sorted({p for p in pos[s:e + 1] if p})
        stmts = sorted({p for p in (sites or pos)[s:e + 1] if p})
        out.append(dict(start=s, end=e, weight=w, counts=dict(cnt), game=(min(js), max(js)) if js else None,
                        ours=(min(iss), max(iss)) if iss else None, lines=lines, stmts=stmts))
    out.sort(key=lambda r: -r["weight"])
    return out


def compress(nums):
    nums = sorted(set(nums))
    out, s, p = [], None, None
    for n in nums:
        if s is None:
            s = p = n
        elif n == p + 1:
            p = n
        else:
            out.append((s, p))
            s = p = n
    if s is not None:
        out.append((s, p))
    return ", ".join(f"{a}" if a == b else f"{a}-{b}" for a, b in out)


def heat(st):
    n = sum(st.values())
    if not n:
        return " "
    bad = sum(WEIGHT[k] * v for k, v in st.items()) / n
    return " " if bad == 0 else "." if bad < 0.25 else "+" if bad < 0.5 else "*" if bad < 0.75 else "#"


def back_branches(words, lo, hi):
    """Backward branches (loops) among words lo..hi."""
    n = 0
    for k in range(lo, hi + 1):
        w = words[k]
        op = w >> 26
        if op in (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 0x11 and (w >> 21) & 0x1F == 8):
            if match.sext16(w & 0xFFFF) < 0:
                n += 1
    return n


def dis(w, addr, reloc=None):
    return match.disasm(w, addr, reloc)


def analyse(name, src=None, callsite=False):
    src = find_source(name, src)
    res = match.compare(name, str(src))
    if res.error:
        raise SystemExit(f"{name}: {res.error}")
    lm = srcmap.compile_lines(src, name)
    note = ""
    if not same_code(lm.words, res.ours.words):
        note = ("WARNING: the -g compile differs from match.py's object; line numbers are approximate "
                f"({len(lm.words)} vs {len(res.ours.words)} words)")
    ops = align(res)
    pos, sites = attribute(ops, lm, callsite)
    return src, res, lm, ops, pos, sites, note


def per_line(ops, pos):
    st = defaultdict(lambda: defaultdict(int))
    for (kind, _, _), p in zip(ops, pos):
        if p:
            st[p][kind] += 1
    return st


def report(name, src, res, lm, ops, pos, sites, note, nreg=10, show_asm=False, all_lines=False):
    addr = match.func_row(name)["addr"]
    total = defaultdict(int)
    for kind, _, _ in ops:
        total[kind] += 1
    print(f"{name}: {src}  fuzzy {match.fuzzy(res):.1f}  ours {len(res.ours.words)} words, game "
          f"{len(res.target.words)}")
    print("  " + "  ".join(f"{k} {total[k]}" for k in KINDS))
    if note:
        print("  " + note)
    st = per_line(ops, pos)
    inl = defaultdict(lambda: defaultdict(int))     # inlined code charged to the calling statement
    for (kind, _, _), p, c in zip(ops, pos, sites):
        if p and c and p != c:
            inl[c][kind] += 1
    text = src.read_text(errors="replace").splitlines()
    unit_lines = sorted(l for (f, l) in st if f == lm.unit_file)
    if not unit_lines:
        print("no line information")
        return
    lo = min(unit_lines)
    hi = max(max(unit_lines), lm.body[1] or 0)
    print()
    print("  line |   ok  reg diff extr miss | source        (heat: ' ' all ok  . + * #  worst)")
    for ln in range(lo, hi + 1):
        s = st.get((lm.unit_file, ln))
        t = text[ln - 1] if ln - 1 < len(text) else ""
        c = inl.get((lm.unit_file, ln))
        tail = ""
        if c:
            nbad = sum(WEIGHT[k] * v for k, v in c.items())
            tail = f"      << inlined here: {sum(c.values())} words, {nbad:g} bad"
        if not s:
            if c:
                print(f"{heat(c)}{ln:5d} | {'':24} |   {t}{tail}")
            elif all_lines or (lm.body[0] <= ln <= lm.body[1]):
                print(f" {ln:5d} | {'':24} |   {t}")
            continue
        cols = " ".join(f"{s[k]:4d}" if s[k] else "   ." for k in KINDS)
        print(f"{heat(s)}{ln:5d} | {cols} |   {t}{tail}")
    others = sorted(p for p in st if p[0] != lm.unit_file)
    if others:
        print("\n  code from other files (inlined headers):")
        for p in others:
            s = st[p]
            print(f"{heat(s)} {p[0]}:{p[1]} " + " ".join(f"{k} {s[k]}" for k in KINDS if s[k]))
    regs = regions(ops, pos, sites)
    bad = sum(r["weight"] for r in regs) or 1
    print(f"\nworst regions ({len(regs)} in all; weight = diff+extra+miss + 0.5*reg):")
    for r in regs[:nreg]:
        g = r["game"]
        o = r["ours"]
        gtxt = f"game {addr + g[0] * 4:08X}-{addr + g[1] * 4 + 3:08X}" if g else "game -"
        otxt = f"ours +{o[0] * 4:04X}-+{o[1] * 4 + 3:04X}" if o else "ours -"
        c = r["counts"]
        cnt = " ".join(f"{k} {c[k]}" for k in KINDS[1:] if c.get(k))
        body = lambda fl: fl[0] == lm.unit_file and lm.body[0] <= fl[1] <= lm.body[1]  # noqa: E731
        st_ = [l for f, l in r["stmts"] if f == lm.unit_file]
        inl = [l for f, l in r["lines"] if f == lm.unit_file and not body((f, l))]
        ol = [f"{f}:{l}" for f, l in r["lines"] if f != lm.unit_file]
        print(f"  {r['weight']:6.1f} ({100 * r['weight'] / bad:4.1f}%)  {gtxt}  {otxt}  [{cnt}]")
        print(f"         statements {compress(st_) or '-'}" + (f"   inlined lines {compress(inl)}" if inl else "")
              + (f" + {', '.join(ol)}" if ol else ""))
        for l in sorted(set(st_))[:5]:
            if 0 < l <= len(text):
                print(f"           {l:5d}: {text[l - 1].strip()[:90]}")
        bo = back_branches(res.ours.words, *o) if o else 0
        bg = back_branches(res.target.words, *g) if g else 0
        if bo != bg:
            hint = ("ours loops where the game's code is straight-line: write the loop out (-O2 does not "
                    "unroll loops)" if bg == 0 else "ours has more loops here" if bo > bg
                    else "the game has more loops here")
            print(f"         loops: ours {bo}, game {bg} backward branches -> {hint}")
        if show_asm:
            for kind, i, j in ops[r["start"]:r["end"] + 1][:40]:
                gl = dis(res.target.words[j], addr + j * 4, res.target.relocs.get(j)) if j is not None else ""
                ol_ = dis(res.ours.words[i], addr + i * 4, res.ours.relocs.get(i)) if i is not None else ""
                print(f"           {kind:5} {gl[:52]:<52} | {ol_[:52]}")
    sw = switch_order(res, lm)
    if sw:
        print(f"\nswitch case bodies are in another order than the game's ({len(sw)} compared constants; gcc "
              "lays bodies out in source order; constants of a nested switch show up too). Game order, with the "
              "line our body starts on (!! = out of order: move this case):")
        seq = [ot for _, _, ot, _ in sw]
        best = [1] * len(seq)                   # longest increasing run of our offsets = the cases in order
        back = [-1] * len(seq)
        for i in range(len(seq)):
            for j in range(i):
                if seq[j] <= seq[i] and best[j] + 1 > best[i]:
                    best[i], back[i] = best[j] + 1, j
        keep, i = set(), max(range(len(seq)), key=lambda k: best[k])
        while i >= 0:
            keep.add(i)
            i = back[i]
        for k, (c, gt, ot, ln) in enumerate(sw):
            t = text[ln - 1].strip()[:70] if ln and 0 < ln <= len(text) else ""
            mark = "  " if k in keep else "!!"
            print(f"  {mark}case 0x{c:08X}  game +{gt * 4:04X}  ours +{ot * 4:04X}  line {ln}: {t}")
    mv = moved(ops, res)
    if mv:
        where_i = {i: p for (k, i, j), p in zip(ops, sites) if i is not None}
        where_j = {j: p for (k, i, j), p in zip(ops, sites) if j is not None}
        print(f"\nmoved code ({len(mv)}): our extra words that match the game's missing words elsewhere "
              "(block order / which copy survived cross-jumping / loop rotation):")
        for r, (i0, i1), (j0, j1) in mv[:nreg]:
            li = sorted({where_i[i][1] for i in range(i0, i1 + 1) if where_i.get(i)})
            lj = sorted({where_j[j][1] for j in range(j0, j1 + 1) if where_j.get(j)})
            print(f"  {100 * r:4.0f}%  ours +{i0 * 4:04X}-+{i1 * 4 + 3:04X} ({i1 - i0 + 1} words, statements "
                  f"{compress(li)})  =  game {addr + j0 * 4:08X}-{addr + j1 * 4 + 3:08X} ({j1 - j0 + 1} words, "
                  f"placed after statements {compress(lj)})")


def to_json(name, src, res, lm, ops, pos, sites):
    addr = match.func_row(name)["addr"]
    return dict(
        name=name, src=str(src), fuzzy=match.fuzzy(res), addr=addr,
        ops=[[k, i, j, list(p) if p else None] for (k, i, j), p in zip(ops, pos)],
        regions=[dict(r, lines=[list(x) for x in r["lines"]], stmts=[list(x) for x in r["stmts"]])
                 for r in regions(ops, pos, sites)],
    )


HTML_HEAD = """<!doctype html><html><head><meta charset="utf-8"><title>diffmap {name}</title>
<style>
:root{{--bg:#fff;--fg:#222;--ok:#e8f5e9;--reg:#fff8d6;--diff:#ffe0b2;--extra:#ffcdd2;--miss:#e1d5f5;--mut:#888}}
@media (prefers-color-scheme: dark){{:root{{--bg:#1b1b1b;--fg:#ddd;--ok:#1f3322;--reg:#3a3418;--diff:#47331a;
--extra:#4a2226;--miss:#33284a;--mut:#999}}}}
body{{background:var(--bg);color:var(--fg);font:12px/1.35 ui-monospace,monospace;margin:16px}}
.wrap{{display:flex;gap:16px;align-items:flex-start}} .col{{flex:1;min-width:0;overflow-x:auto}}
table{{border-collapse:collapse;width:100%}} td{{padding:0 6px;white-space:pre;vertical-align:top}}
tr.ok{{background:var(--ok)}} tr.reg{{background:var(--reg)}} tr.diff{{background:var(--diff)}}
tr.extra{{background:var(--extra)}} tr.miss{{background:var(--miss)}} .n{{color:var(--mut);text-align:right}}
.src{{position:sticky;top:0;max-height:95vh;overflow:auto}} a{{color:inherit}}
.legend span{{padding:0 6px;margin-right:4px}}
</style></head><body>
<h3>{name} &mdash; fuzzy {fuzzy:.1f}</h3>
<div class="legend"><span style="background:var(--ok)">ok</span><span style="background:var(--reg)">reg</span>
<span style="background:var(--diff)">diff</span><span style="background:var(--extra)">extra (ours only)</span>
<span style="background:var(--miss)">miss (game only)</span></div>
"""


def write_html(path, name, src, res, lm, ops, pos):
    addr = match.func_row(name)["addr"]
    text = src.read_text(errors="replace").splitlines()
    st = per_line(ops, pos)
    out = [HTML_HEAD.format(name=html.escape(name), fuzzy=match.fuzzy(res)), '<div class="wrap">']
    out.append('<div class="col src"><table>')
    lines = sorted(l for f, l in st if f == lm.unit_file)
    lo, hi = (min(lines), max(max(lines), lm.body[1])) if lines else (1, len(text))
    for ln in range(lo, hi + 1):
        s = st.get((lm.unit_file, ln))
        t = text[ln - 1] if ln - 1 < len(text) else ""
        if s:
            n = sum(s.values())
            bad = sum(WEIGHT[k] * v for k, v in s.items()) / n
            cls = "ok" if bad == 0 else "reg" if bad < 0.34 else "diff" if bad < 0.67 else "extra"
            cnt = " ".join(f"{k[0]}{s[k]}" for k in KINDS if s[k])
            out.append(f'<tr class="{cls}" id="L{ln}"><td class="n"><a href="#A{ln}">{ln}</a></td>'
                       f'<td>{html.escape(t)}</td><td class="n">{cnt}</td></tr>')
        else:
            out.append(f'<tr id="L{ln}"><td class="n">{ln}</td><td>{html.escape(t)}</td><td></td></tr>')
    out.append("</table></div><div class='col'><table>")
    out.append("<tr><td>kind</td><td>game</td><td>ours</td><td class='n'>line</td></tr>")
    seen = set()
    for (kind, i, j), p in zip(ops, pos):
        g = dis(res.target.words[j], addr + j * 4, res.target.relocs.get(j)) if j is not None else ""
        o = dis(res.ours.words[i], addr + i * 4, res.ours.relocs.get(i)) if i is not None else ""
        ln = p[1] if p and p[0] == lm.unit_file else None
        anchor = ""
        if ln and ln not in seen:
            seen.add(ln)
            anchor = f' id="A{ln}"'
        lref = f'<a href="#L{ln}">{ln}</a>' if ln else (f"{p[0]}:{p[1]}" if p else "")
        out.append(f'<tr class="{kind}"{anchor}><td>{kind}</td><td>{html.escape(g)}</td><td>{html.escape(o)}</td>'
                   f'<td class="n">{lref}</td></tr>')
    out.append("</table></div></div></body></html>")
    Path(path).parent.mkdir(parents=True, exist_ok=True)
    Path(path).write_text("\n".join(out))


# --knob: pass-isolating flags. Each one switches off (or shifts) one pass's decision; when a flag removes a
# region, that pass owns the mismatch. A DIAGNOSTIC only: most of these flags are not allowed per file, and
# an allowed one still needs neighbour evidence (MATCHING_GUIDE "Per-file flags need neighbour evidence").
KNOBS = [
    ("-fno-gcse", "gcse (global cse / PRE: expressions moved across blocks)"),
    ("-fno-cse-follow-jumps", "cse following jumps (values carried along branch paths)"),
    ("-fno-expensive-optimizations", "the 'expensive' parts of cse/regmove/combine"),
    ("-fforce-addr", "address forming (memory addresses copied into registers before use)"),
    ("-fno-schedule-insns", "sched1 (scheduling before register allocation)"),
    ("-fno-schedule-insns2", "sched2 (scheduling after reload)"),
    ("-fno-rerun-loop-opt", "loop.c's second pass"),
    ("-fno-strength-reduce", "loop.c strength reduction (givs)"),
    ("-mvu0-use-vf0-vf2", "loop.c hoisting / giv thresholds (tools/loopknob.py sweeps N)"),
]
SHORT = ["no-gcse", "no-cse-fj", "no-expens", "force-addr", "no-sched1", "no-sched2", "no-rerun", "no-sreduce",
         "vu0-vf2"]


def game_badness(ops, g0, g1):
    """Weight of the non-ok ops that fall in game words g0..g1 (extras charged to the game word before)."""
    w, last = 0.0, -1
    for kind, i, j in ops:
        if j is not None:
            last = j
        if g0 <= last <= g1 and kind != "ok" and (j is None or g0 <= j <= g1):
            w += WEIGHT[kind]
    return w


def _knob_run(name, src, k):
    from common import ROOT, compiler_config
    pinned = list(compiler_config()["compiler"]["cflags"])
    r = match.compare(name, str(src), None, pinned + [KNOBS[k][0]],
                      str(ROOT / "work" / "diffmap_knob" / name / f"k{k}"))
    if r.error:
        return k, None, None
    return k, r, align(r)


def knob_report(name, src, res, ops, pos, sites, nreg=8, j=2):
    # processes, not threads: match.compare keeps module-level state and is not thread-safe
    from concurrent.futures import ProcessPoolExecutor
    addr = match.func_row(name)["addr"]
    n = len(KNOBS)
    with ProcessPoolExecutor(max(1, j)) as ex:
        results = list(ex.map(_knob_run, [name] * n, [str(src)] * n, range(n)))
    regs = [r for r in regions(ops, pos, sites) if r["game"]][:nreg]
    print("\n--knob: which pass owns each region? (DIAGNOSTIC ONLY: these flags name the pass that decides "
          "differently;\n  they are not fixes. Most are not allowed per file; -mvu0-use-vf0-vf2 is, with "
          "neighbour evidence.)")
    print(f"  {'flag':30} {'words':>6} {'fuzzy':>6}   pass")
    print(f"  {'(pinned flags)':30} {len(res.diffs):6d} {match.fuzzy(res):6.1f}")
    for k, r, _ in results:
        flag, what = KNOBS[k]
        if r is None:
            print(f"  {flag:30} {'ERR':>6}")
            continue
        tag = "MATCH" if r.ok else f"{len(r.diffs)}"
        print(f"  {flag:30} {tag:>6} {match.fuzzy(r):6.1f}   {what}")
    if not regs:
        return
    print("\n  worst regions (weight with pinned flags -> with each flag; '-' = no change, clean = region removed):")
    hdr = "  " + f"{'region':28}" + "".join(f"{SHORT[k]:>11}" for k in range(len(KNOBS)))
    print(hdr)
    for rg in regs:
        g0, g1 = rg["game"]
        b = game_badness(ops, g0, g1)
        st = [l for f, l in rg["stmts"]] if rg["stmts"] and isinstance(rg["stmts"][0], tuple) else []
        lab = f"{addr + g0 * 4:08X}-{addr + g1 * 4 + 3:08X} {b:g}"
        cells, owners = [], []
        for k, r, kops in results:
            if r is None:
                cells.append("ERR")
                continue
            w = game_badness(kops, g0, g1)
            if w == b:
                cells.append("-")
            else:
                cells.append("clean" if w == 0 else f"{w:g}")
                if w < b:
                    owners.append((w, k))
        print("  " + f"{lab:28}" + "".join(f"{c:>11}" for c in cells))
        lines = compress(st) if st else ""
        if owners:
            owners.sort()
            best_w = owners[0][0]
            names = [KNOBS[k][1].split(" (")[0] for w, k in owners if w == best_w]
            verdict = "removed" if best_w == 0 else f"reduced to {best_w:g}"
            print(f"      lines {lines}: {verdict} by {', '.join(KNOBS[k][0] for w, k in owners if w == best_w)}"
                  f" -> the residue lives in {' / '.join(names)}")
        else:
            print(f"      lines {lines}: no flag improves it (allocation or source shape; try regalloc_explain)")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--html")
    ap.add_argument("--json")
    ap.add_argument("--regions", type=int, default=10)
    ap.add_argument("--asm", action="store_true", help="print the aligned asm of each listed region")
    ap.add_argument("--callsite", action="store_true", help="charge inlined code to the calling statement")
    ap.add_argument("--all-lines", action="store_true", help="also print lines without code outside the body")
    ap.add_argument("--knob", action="store_true",
                    help="diagnostic: recompile with pass-isolating flags and say which flag removes which region")
    ap.add_argument("-j", type=int, default=2, help="parallel compiles for --knob (default 2)")
    a = ap.parse_args()
    src, res, lm, ops, pos, sites, note = analyse(a.name, a.src, a.callsite)
    if res.ok:
        print(f"{a.name}: MATCH")
    report(a.name, src, res, lm, ops, pos, sites, note, a.regions, a.asm, a.all_lines)
    if a.knob and not res.ok:
        knob_report(a.name, src, res, ops, pos, sites, min(a.regions, 8), a.j)
    if a.html:
        write_html(a.html, a.name, src, res, lm, ops, pos)
        print(f"\nwrote {a.html}")
    if a.json:
        Path(a.json).write_text(json.dumps(to_json(a.name, src, res, lm, ops, pos, sites)))


if __name__ == "__main__":
    main()
