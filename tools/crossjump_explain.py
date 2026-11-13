#!/usr/bin/env python3
"""Which tails did jump2 cross-jump, and which copy survived?

    python tools/crossjump_explain.py func_00230D88            # src/funcs or src/nonmatching unit
    python tools/crossjump_explain.py func_00230D88 --src work/try.cpp
    python tools/crossjump_explain.py func_00230D88 --rtl      # also print the merged insns' RTL

gcc 2.95's second jump pass (jump2, after reload and sched2, before reorg) cross-jumps: when the insns just
before a jump equal the insns just before its target label (or the code falling into it), it deletes the
jumping copy and retargets the jump into the other copy, at a new label placed in front of the kept insns
(docs/techniques/LAST_MILE.md 4.2). Nothing in the asm says which copy was kept: this tool reads it off the
RTL dumps. It compiles the unit as match.py does plus `-g -dR -dJ` (this cc1plus writes `.sched2` and `.jump2`;
the dumps do not change the code) and compares the insn chain before and after jump2:

    merged tail   insns deleted in front of a jump whose target changed (or of a new jump): the deleted copy
                  is at the jump's source lines, the surviving copy follows the new label
    new label     a label jump2 made for a merge. Later tails never merge into it (fact 101), while a jump to
                  an existing (user) label can merge again: `goto done` vs a duplicated tail
    deleted jump  a jump jump2 removed outright (jump to the next insn, threaded, or now unreachable)

Read it next to the game's asm: if the game keeps the other copy, reorder the duplicated tails, write them as
`return f(...)` in each branch, or jump to an existing label (MATCHING_GUIDE "Cross-jumping"). Also
cxxperm.py's `tail_into_branches`, `goto_existing_label` and `return_for_break` passes try those shapes.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rtl_dumps  # noqa: E402

HEAD = re.compile(r"^\((insn|jump_insn|call_insn|note|code_label|barrier)(?::\w+)?\s+(\d+)\s")
LINE_NOTE = re.compile(r"^\(note \d+ \d+ \d+ \(\"[^\"]*\"\) (\d+)\)")
LABEL_REF = re.compile(r"\(label_ref (\d+)\)")
REG = re.compile(r"\(reg(?:/[a-z])*:[A-Z]+ \d+ (\w+)\)")


def compact(lines):
    s = " ".join(x.strip() for x in lines)
    m = re.search(r"\((set|call|parallel|return|use|clobber) ", s)
    s = s[m.start():] if m else s
    s = re.sub(r"\s+\d+ \{[^}]*\}.*$", "", s)
    s = re.sub(r" \[0x[0-9a-f]+\]", "", s)
    s = REG.sub(lambda m: "$" + m.group(1), s)
    s = re.sub(r"\(const_int (-?\d+)\)", r"\1", s)
    return s


def parse(text):
    """Ordered [dict(kind, uid, line, pat, labels)] of the insn chain printed in a dump."""
    items, line, cur = [], None, None
    for raw in text.splitlines():
        m = LINE_NOTE.match(raw)
        if m:
            line = int(m.group(1))
            cur = None
            continue
        m = HEAD.match(raw)
        if m:
            cur = dict(kind=m.group(1), uid=int(m.group(2)), line=line, body=[raw])
            if cur["kind"] in ("insn", "jump_insn", "call_insn", "code_label", "barrier"):
                items.append(cur)
            else:
                cur = None
            continue
        if cur is not None and raw.startswith(" "):
            cur["body"].append(raw)
    for it in items:
        it["pat"] = compact(it["body"]) if it["kind"] != "code_label" else ""
        it["labels"] = tuple(int(x) for x in LABEL_REF.findall(" ".join(it["body"])))
        if it["kind"] == "code_label":
            it["user"] = '"' in it["body"][0] and not re.search(r'\s""\s', it["body"][0])
    return items


def explain(before, after, src_lines, show_rtl=False):
    b_by = {it["uid"]: it for it in before}
    a_by = {it["uid"]: it for it in after}
    real = ("insn", "jump_insn", "call_insn")
    deleted = {u for u, it in b_by.items() if it["kind"] in real and u not in a_by}
    new_labels = [it for it in after if it["kind"] == "code_label" and it["uid"] not in b_by]
    a_index = {it["uid"]: k for k, it in enumerate(after)}
    b_index = {it["uid"]: k for k, it in enumerate(before)}

    def src(ln):
        return src_lines[ln - 1].strip() if ln and 0 < ln <= len(src_lines) else ""

    def run_before(uid):
        """Deleted real insns directly in front of `uid` in the old chain."""
        k = b_index.get(uid)
        out = []
        if k is None:
            return out
        k -= 1
        while k >= 0 and before[k]["uid"] in deleted:
            out.append(before[k])
            k -= 1
        return out[::-1]

    def kept_after(label_uid, n):
        k = a_index[label_uid] + 1
        out = []
        while k < len(after) and len(out) < n:
            if after[k]["kind"] in real:
                out.append(after[k])
            k += 1
        return out

    merges, used = [], set()
    for it in after:
        if it["kind"] != "jump_insn":
            continue
        old = b_by.get(it["uid"])
        retarget = old is not None and old["labels"] != it["labels"]
        newjump = old is None
        if not (retarget or newjump):
            continue
        tgt = [l for l in it["labels"] if l in a_index]
        if newjump:
            # the copy it replaced sat right after its predecessor in the old chain
            k = a_index[it["uid"]] - 1
            while k >= 0 and after[k]["kind"] not in real:
                k -= 1
            prev = after[k]["uid"] if k >= 0 else None
            run = []
            if prev in b_index:
                j = b_index[prev] + 1
                while j < len(before) and before[j]["uid"] in deleted:
                    run.append(before[j])
                    j += 1
        else:
            run = run_before(it["uid"])
        used.update(r["uid"] for r in run)
        lab = tgt[0] if tgt else None
        kept = kept_after(lab, len(run)) if lab is not None and run else []
        merges.append(dict(jump=it, old=old, run=run, label=lab, kept=kept, newjump=newjump,
                           new_label=lab is not None and lab not in b_by))
    print(f"jump2: {len(deleted)} insns deleted, {len(new_labels)} new labels, "
          f"{sum(1 for m in merges if m['run'])} merged tails")
    n = 0
    for m in merges:
        if not m["run"]:
            continue
        n += 1
        j = m["jump"]
        lines = sorted({r["line"] for r in m["run"] if r["line"]})
        klines = sorted({r["line"] for r in m["kept"] if r["line"]})
        how = "new jump" if m["newjump"] else f"jump {j['uid']} retargeted"
        lab = f"new label {m['label']}" if m["new_label"] else f"existing label {m['label']}"
        print(f"\n  merge {n}: {len(m['run'])} insns deleted at line(s) {', '.join(map(str, lines)) or '?'}; "
              f"{how} to {lab}")
        print(f"    deleted copy: " + " | ".join(src(l) for l in lines[:3]))
        print(f"    kept copy at line(s) {', '.join(map(str, klines)) or '?'}: "
              + " | ".join(src(l) for l in klines[:3]))
        if show_rtl:
            for r in m["run"]:
                print(f"      - {r['uid']:5d} {r['pat'][:100]}")
            for r in m["kept"]:
                print(f"      + {r['uid']:5d} {r['pat'][:100]}")
        if m["new_label"]:
            print("    (a new label is a dead end: later tails do not merge into it; a jump to an existing label "
                  "can merge again)")
    lone = sorted(deleted - used)
    jumps = [b_by[u] for u in lone if b_by[u]["kind"] == "jump_insn"]
    others = [b_by[u] for u in lone if b_by[u]["kind"] != "jump_insn"]
    if jumps:
        print(f"\n  deleted jumps (to the next insn, threaded or unreachable): "
              + ", ".join(f"{u['uid']} (line {u['line']})" for u in jumps))
    if others:
        print(f"  other deleted insns (dead code or no-op moves): "
              + ", ".join(f"{u['uid']} (line {u['line']})" for u in others))
    if not n:
        print("  no tail was cross-jumped in this function")
    return merges


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    ap.add_argument("--src")
    ap.add_argument("--rtl", action="store_true", help="print the RTL of each deleted and kept insn")
    a = ap.parse_args()
    src = rtl_dumps.find_source(a.name, a.src)
    d = rtl_dumps.compile_with_dumps(a.name, src, ["-g", "-dR", "-dJ"], map_words=False)
    if "sched2" not in d.files or "jump2" not in d.files:
        sys.exit(f"{a.name}: no .sched2/.jump2 dump (got {sorted(d.files)})")
    print(f"{a.name}: {src}")
    explain(parse(d.files["sched2"]), parse(d.files["jump2"]),
            Path(src).read_text(errors="replace").splitlines(), a.rtl)


if __name__ == "__main__":
    main()
