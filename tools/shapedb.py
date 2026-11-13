#!/usr/bin/env python3
"""Which C++ produces this asm? An index of instruction shapes over every matched unit.

    python tools/shapedb.py build [-j3] [--limit N] [--units a,b]   # index src/funcs (incremental)
    python tools/shapedb.py query func_001780F0                      # the game regions we don't reproduce
    python tools/shapedb.py query func_001780F0 --block 0x00178428   # one game basic block (any function)
    python tools/shapedb.py query func_001780F0 --top 8 --regions 3 --exclude func_00177A58
    python tools/shapedb.py loo --recent 10                          # leave-one-out retrieval test
    python tools/shapedb.py stats

build: for every src/funcs unit
  1. compile it with -g (tools/srcmap.py) to map each word to the C++ line (and the calling statement, for
     inlined code); the words are checked against the game's (a matched unit is byte-identical);
  2. read the game's asm for the function (asm/nonmatchings/..., splat output: symbolic relocations), cut it
     into basic blocks (leaders: labels, the word after a branch's delay slot), and turn every instruction
     into an abstract shape token:
        mnemonic + operand classes: register class (0 zero, v ret, a arg $a0-$a3/$t0-$t3, t temp, s saved,
        p sp, r ra, g gp; fv/fa/ft/fs float ret/arg/temp/saved), immediate class (0, 1, -1, k <16, m <256,
        K larger, n negative; shift amounts exact), memory operand (base class + offset 0/small/large,
        stack), relocation kind (H %hi, L %lo, G %gp_rel, GF a .lit4 float, F call/jump target, Bb/Bf a
        backward/forward branch). Register numbers and addresses are dropped;
  3. store every block (3+ tokens) and every window of 2 and 3 consecutive blocks as an entry: its token
     sequence, a 32-value MinHash of its token 2-/3-gram set, 16 LSH bands of 2 values, and the unit's
     word -> line map.
  The index is build/shapedb/shapes.sqlite (git-ignored). Units whose source and asm did not change are
  reused on the next build.

query NAME: compiles NAME (src/nonmatching or --src) as match.py does, aligns it with the game as diffmap.py
  does, and takes the game's words of the worst --regions regions (or the block at --block ADDR, which needs no
  unit). Their blocks and 2-block windows are looked up through the LSH bands, candidates are re-ranked by an
  order-aware similarity of the token sequences (difflib ratio), and the --top hits are printed with the
  matched unit's asm and the exact C++ lines that produced it.

Written from scratch (MinHash/LSH as in the textbook formulation); no code from any other project.
"""
import argparse
import difflib
import hashlib
import json
import os
import re
import sqlite3
import struct
import sys
import time
import zlib
from collections import defaultdict
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BUILD, ROOT, SRC_FUNCS, load_functions  # noqa: E402

DB = BUILD / "shapedb" / "shapes.sqlite"
TMP = BUILD / "shapedb" / "tmp"
NPERM, BANDS, ROWS = 32, 16, 2
P61 = (1 << 61) - 1
MAX_WIN_WORDS = 96
SCHEMA = 2

# ---------------------------------------------------------------- shapes

LINE_RE = re.compile(r"^\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+([0-9A-F]{8})\s*\*/\s*(\S+)\s*(.*?)\s*$")
LABEL_RE = re.compile(r"^\s*(?:[a-z]label\s+)?\.L([0-9A-F]{8}):?\s*$")
GPR = {"zero": "0", "at": "t", "v0": "v", "v1": "v", "gp": "g", "sp": "p", "fp": "s", "s8": "s", "ra": "r",
       "k0": "k", "k1": "k"}
for _n in ("a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"):
    GPR[_n] = "a"                       # EABI: eight argument registers
for _n in ("t4", "t5", "t6", "t7", "t8", "t9"):
    GPR[_n] = "t"
for _k in range(8):
    GPR[f"s{_k}"] = "s"
SHIFTS = {"sll", "srl", "sra", "dsll", "dsrl", "dsra", "dsll32", "dsrl32", "dsra32", "psllh", "psrlh", "psrah",
          "psllw", "psrlw", "psraw"}
LIT4 = (0x387400, 0x388258)
BRANCH_END = {"j", "jr", "b", "beq", "bne", "beqz", "bnez", "bgez", "bgtz", "blez", "bltz", "bgezal", "bltzal",
              "beql", "bnel", "beqzl", "bnezl", "bgezl", "bgtzl", "blezl", "bltzl", "bc1t", "bc1f", "bc1tl",
              "bc1fl", "bc0t", "bc0f", "bc2t", "bc2f", "bal", "jalr"}
BRANCH_END.discard("jalr")              # a call does not end a block


def reg_class(r):
    r = r.lstrip("$")
    if r in GPR:
        return GPR[r]
    m = re.match(r"^f(\d+)$", r)
    if m:
        n = int(m.group(1))
        return "fv" if n < 4 else "ft" if n < 12 else "fa" if n < 20 else "fs"
    return "x"


def imm_class(v):
    if v == 0:
        return "0"
    if v == 1:
        return "1"
    if v == -1:
        return "-1"
    if v < 0:
        return "n"
    return "k" if v < 16 else "m" if v < 256 else "K"


def _num(s):
    try:
        return int(s, 0)
    except ValueError:
        return None


def split_ops(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


SYM_ADDR = re.compile(r"_([0-9A-F]{8})")


def op_class(op, mnem, vram):
    if op.startswith("$"):
        return reg_class(op)
    m = re.match(r"^%(hi|lo|gp_rel)\(([^)]*)\)(?:\((\$\w+)\))?$", op)
    if m:
        kind, sym, base = m.groups()
        a = SYM_ADDR.search(sym)
        lit = a and LIT4[0] <= int(a.group(1), 16) < LIT4[1]
        k = {"hi": "H", "lo": "L", "gp_rel": "G"}[kind] + ("F" if lit else "")
        return k + (f"[{reg_class(base)}]" if base and kind != "gp_rel" else "")
    m = re.match(r"^(-?(?:0x[0-9A-Fa-f]+|\d+))\((\$\w+)\)$", op)
    if m:
        v, base = _num(m.group(1)), reg_class(m.group(2))
        if base == "p":
            return "[sp]"
        return f"[{base}{'0' if v == 0 else 'o' if v < 0x40 else 'O'}]"
    m = re.match(r"^\.L([0-9A-F]{8})$", op)
    if m:
        return "Bb" if int(m.group(1), 16) <= vram else "Bf"
    if op.startswith("(") and ("0x" in op):
        return "K"                      # splat's (0xVALUE >> 16) / (0xVALUE & 0xFFFF) halves of a constant
    v = _num(op)
    if v is not None:
        if mnem in SHIFTS:
            return str(v)
        return imm_class(v)
    return "F"                          # a symbol: call/jump target


def tokenize(mnem, ops, vram):
    if mnem.startswith("."):
        return "word"
    return mnem + " " + ",".join(op_class(o, mnem, vram) for o in split_ops(ops))


def read_asm(path):
    """[(vram, word, mnemonic, operands)], label vrams."""
    ins, labels = [], set()
    for line in Path(path).read_text(errors="replace").splitlines():
        m = LINE_RE.match(line)
        if m:
            ins.append((int(m.group(1), 16), m.group(2), m.group(3), m.group(4)))
            continue
        m = LABEL_RE.match(line)
        if m:
            labels.add(int(m.group(1), 16))
    return ins, labels


def blocks_of(ins, labels):
    """[(start, end)] word ranges (end exclusive)."""
    if not ins:
        return []
    leaders = {0}
    for k, (v, _, mn, _) in enumerate(ins):
        if v in labels:
            leaders.add(k)
        if mn in BRANCH_END and k + 2 <= len(ins):
            leaders.add(k + 2)
    ls = sorted(x for x in leaders if x < len(ins))
    return [(s, ls[i + 1] if i + 1 < len(ls) else len(ins)) for i, s in enumerate(ls)]


def shingles(toks):
    out = set()
    for n in (2, 3):
        for i in range(len(toks) - n + 1):
            out.add(zlib.crc32("\x1f".join(toks[i:i + n]).encode()))
    if not out:
        out.add(zlib.crc32("\x1f".join(toks).encode()))
    return out


def _perms():
    out = []
    for k in range(NPERM):
        h = hashlib.blake2b(f"shapedb{k}".encode(), digest_size=16).digest()
        a = int.from_bytes(h[:8], "little") % (P61 - 1) + 1
        b = int.from_bytes(h[8:], "little") % P61
        out.append((a, b))
    return out


PERMS = _perms()


def minhash(sh):
    return [min(((a * x + b) % P61) & 0xFFFFFFFF for x in sh) for a, b in PERMS]


def band_keys(sig):
    keys = []
    for band in range(BANDS):
        part = sig[band * ROWS:(band + 1) * ROWS]
        h = zlib.crc32(struct.pack("<B" + "I" * ROWS, band, *part))
        keys.append((band << 32) | h)
    return keys


def entries_of(toks, blks, min_tok=3):
    """[(w0, w1, nblocks)] for blocks and windows of 2-3 consecutive blocks."""
    out = []
    for i, (s, e) in enumerate(blks):
        if e - s >= min_tok:
            out.append((s, e, 1))
        for w in (2, 3):
            if i + w <= len(blks):
                s2, e2 = blks[i][0], blks[i + w - 1][1]
                if e2 - s2 <= MAX_WIN_WORDS and e2 - s2 >= max(min_tok, 4):
                    out.append((s2, e2, w))
    return out


def func_shapes(asm_path):
    ins, labels = read_asm(asm_path)
    toks = [tokenize(mn, ops, v) for v, _, mn, ops in ins]
    return ins, toks, blocks_of(ins, labels)


# ---------------------------------------------------------------- build

def _sha(*paths):
    h = hashlib.sha1()
    for p in paths:
        h.update(Path(p).read_bytes())
    h.update(str(SCHEMA).encode())
    return h.hexdigest()


def _index_unit(job):
    """Worker: compile one unit with line info and cut the game's asm into shape entries."""
    name, src, asm, addr = job
    import srcmap
    from rtl_dumps import same_code
    import match
    out = dict(name=name, src=src, asm=asm, addr=addr, sha=_sha(src, ROOT / asm), err="")
    try:
        ins, toks, blks = func_shapes(ROOT / asm)
        if not ins:
            raise ValueError("no instructions in the asm")
        game = [int.from_bytes(bytes.fromhex(w), "little") for _, w, _, _ in ins]
        wd = TMP / f"w{os.getpid()}"
        lm = srcmap.compile_lines(ROOT / src, name, workdir=wd, check=False)
        orig = match.read_orig(addr, 4 * len(game))
        if orig is not None:
            game = [int.from_bytes(orig[i:i + 4], "little") for i in range(0, len(orig), 4)]
        n0 = len(lm.words)          # the game's function may end in alignment nops
        out["verified"] = int(n0 <= len(game) and same_code(lm.words, game[:n0]) and not any(game[n0:]))
        n = len(toks)
        files = []
        lines = []
        for i in range(n):
            fl = lm.lines[i] if i < len(lm.lines) else None
            site = lm.via[i] if i < len(lm.via) else None
            if fl is None:
                lines.append([0, 0, site or 0])
                continue
            if fl[0] not in files:
                files.append(fl[0])
            lines.append([files.index(fl[0]), fl[1], site or 0])
        out["files"] = files
        out["unit_file"] = lm.unit_file
        out["lines"] = lines
        out["body"] = list(lm.body)
        ents = []
        for s, e, nb in entries_of(toks, blks):
            t = toks[s:e]
            ents.append((s, e, nb, t, minhash(shingles(t))))
        out["entries"] = ents
        out["nwords"] = n
    except Exception as ex:  # noqa: BLE001 - a broken unit must not stop the build
        out["err"] = f"{type(ex).__name__}: {str(ex).strip().splitlines()[-1] if str(ex).strip() else ''}"
    return out


def connect(create=False):
    if not DB.exists() and not create:
        sys.exit(f"{DB} missing: run `tools/shapedb.py build` first")
    DB.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(DB)
    db.executescript("""
        CREATE TABLE IF NOT EXISTS meta(k TEXT PRIMARY KEY, v TEXT);
        CREATE TABLE IF NOT EXISTS tok(id INTEGER PRIMARY KEY, text TEXT UNIQUE);
        CREATE TABLE IF NOT EXISTS unit(id INTEGER PRIMARY KEY, name TEXT UNIQUE, addr INTEGER, nwords INTEGER,
            src TEXT, asm TEXT, sha TEXT, verified INTEGER, files TEXT, unit_file TEXT, lines TEXT, body TEXT,
            err TEXT);
        CREATE TABLE IF NOT EXISTS entry(id INTEGER PRIMARY KEY, unit INTEGER, w0 INTEGER, w1 INTEGER,
            nblk INTEGER, toks BLOB);
        CREATE TABLE IF NOT EXISTS band(key INTEGER, entry INTEGER);
        CREATE INDEX IF NOT EXISTS entry_unit ON entry(unit);
    """)
    return db


def tok_ids(db, toks, cache):
    out = []
    for t in toks:
        i = cache.get(t)
        if i is None:
            cur = db.execute("INSERT OR IGNORE INTO tok(text) VALUES (?)", (t,))
            i = cur.lastrowid if cur.rowcount else db.execute("SELECT id FROM tok WHERE text=?", (t,)).fetchone()[0]
            cache[t] = i
        out.append(i)
    return out


def pack(ids):
    return struct.pack(f"<{len(ids)}I", *ids)


def unpack(b):
    return list(struct.unpack(f"<{len(b) // 4}I", b))


def cmd_build(a):
    t0 = time.time()
    rows = {r["name"]: r for r in load_functions()}
    units = sorted(SRC_FUNCS.glob("func_*.cpp")) + sorted(SRC_FUNCS.glob("func_*.c"))
    if a.units:
        want = set(a.units.split(","))
        units = [u for u in units if u.stem in want]
    if a.limit:
        units = units[:a.limit]
    db = connect(create=True)
    have = {n: (i, s) for i, n, s in db.execute("SELECT id, name, sha FROM unit")}
    jobs, keep = [], set()
    for u in units:
        r = rows.get(u.stem)
        if not r:
            continue
        keep.add(u.stem)
        sha = _sha(u, ROOT / r["asm"])
        if u.stem in have and have[u.stem][1] == sha and not a.force:
            continue
        jobs.append((u.stem, os.path.relpath(u, ROOT), r["asm"], r["addr"]))
    if not a.units and not a.limit:      # units that left src/funcs
        for n, (i, _) in have.items():
            if n not in keep:
                _drop(db, i)
    print(f"shapedb: {len(units)} units, {len(jobs)} to (re)index with -j{a.jobs}", flush=True)
    cache = {t: i for i, t in db.execute("SELECT id, text FROM tok")}
    done = errs = unver = 0
    TMP.mkdir(parents=True, exist_ok=True)
    with ProcessPoolExecutor(max_workers=a.jobs) as ex:
        for out in ex.map(_index_unit, jobs, chunksize=4):
            done += 1
            old = db.execute("SELECT id FROM unit WHERE name=?", (out["name"],)).fetchone()
            if old:
                _drop(db, old[0])
            if out["err"]:
                errs += 1
                db.execute("INSERT INTO unit(name, addr, src, asm, sha, err) VALUES (?,?,?,?,?,?)",
                           (out["name"], out["addr"], out["src"], out["asm"], out["sha"], out["err"]))
                continue
            unver += 0 if out["verified"] else 1
            cur = db.execute("INSERT INTO unit(name, addr, nwords, src, asm, sha, verified, files, unit_file, lines,"
                             " body, err) VALUES (?,?,?,?,?,?,?,?,?,?,?,'')",
                             (out["name"], out["addr"], out["nwords"], out["src"], out["asm"], out["sha"],
                              out["verified"], json.dumps(out["files"]), out["unit_file"],
                              json.dumps(out["lines"]), json.dumps(out["body"])))
            uid = cur.lastrowid
            for s, e, nb, t, sig in out["entries"]:
                c = db.execute("INSERT INTO entry(unit, w0, w1, nblk, toks) VALUES (?,?,?,?,?)",
                               (uid, s, e, nb, pack(tok_ids(db, t, cache))))
                eid = c.lastrowid
                db.executemany("INSERT INTO band(key, entry) VALUES (?,?)", [(k, eid) for k in band_keys(sig)])
            if done % 200 == 0:
                db.commit()
                print(f"  {done}/{len(jobs)}  {time.time() - t0:.0f}s  errors {errs}", flush=True)
    db.execute("CREATE INDEX IF NOT EXISTS band_key ON band(key)")
    db.execute("INSERT OR REPLACE INTO meta VALUES ('built', ?)", (time.strftime("%Y-%m-%d %H:%M:%S"),))
    db.commit()
    n_u, n_e = db.execute("SELECT COUNT(*) FROM unit WHERE err=''").fetchone()[0], \
        db.execute("SELECT COUNT(*) FROM entry").fetchone()[0]
    dt = time.time() - t0
    print(f"shapedb: indexed {done} units in {dt:.0f}s ({errs} errors, {unver} whose -g words differ from the "
          f"game); index holds {n_u} units, {n_e} entries -> {DB}")
    db.execute("INSERT OR REPLACE INTO meta VALUES ('last_build_seconds', ?)", (f"{dt:.0f}",))
    db.commit()


def _drop(db, uid):
    db.execute("DELETE FROM band WHERE entry IN (SELECT id FROM entry WHERE unit=?)", (uid,))
    db.execute("DELETE FROM entry WHERE unit=?", (uid,))
    db.execute("DELETE FROM unit WHERE id=?", (uid,))


# ---------------------------------------------------------------- query

class Index:
    def __init__(self):
        self.db = connect()
        self.tok = {t: i for i, t in self.db.execute("SELECT id, text FROM tok")}
        self.units = {}

    def ids(self, toks):
        return [self.tok.get(t, -1 - k) for k, t in enumerate(toks)]   # unknown tokens never match

    def unit(self, uid):
        if uid not in self.units:
            r = self.db.execute("SELECT name, addr, src, asm, files, unit_file, lines, body FROM unit WHERE id=?",
                                (uid,)).fetchone()
            self.units[uid] = dict(name=r[0], addr=r[1], src=r[2], asm=r[3], files=json.loads(r[4]),
                                   unit_file=r[5], lines=json.loads(r[6]), body=json.loads(r[7]))
        return self.units[uid]

    def search(self, toks, exclude=(), per_band=400, rerank=150, top=20):
        """[(score, entry id, unit id, w0, w1)] best first."""
        sig = minhash(shingles(toks))
        votes = defaultdict(int)
        for k in band_keys(sig):
            for (e,) in self.db.execute("SELECT entry FROM band WHERE key=? LIMIT ?", (k, per_band)):
                votes[e] += 1
        if not votes:
            return []
        cand = sorted(votes, key=lambda e: -votes[e])[:rerank]
        q = self.ids(toks)
        sm = difflib.SequenceMatcher(None, autojunk=False)
        sm.set_seq2(q)
        out = []
        marks = ",".join("?" * len(cand))
        for e, uid, w0, w1, blob in self.db.execute(
                f"SELECT id, unit, w0, w1, toks FROM entry WHERE id IN ({marks})", cand):
            if uid in exclude:
                continue
            sm.set_seq1(unpack(blob))
            if sm.real_quick_ratio() < 0.3:
                continue
            out.append((sm.ratio(), e, uid, w0, w1))
        out.sort(key=lambda x: (-x[0], -(x[4] - x[3])))
        return out[:top]

    def unit_ids(self, names):
        out = set()
        for n in names:
            r = self.db.execute("SELECT id FROM unit WHERE name=?", (n,)).fetchone()
            if r:
                out.add(r[0])
        return out


def asm_lines(asm_path, w0, w1):
    ins = []
    for line in (ROOT / asm_path).read_text(errors="replace").splitlines():
        m = LINE_RE.match(line)
        if m:
            ins.append(f"{m.group(1)}  {m.group(3):<10} {m.group(4)}")
    return ins[w0:w1]


def cxx_lines(u, w0, w1):
    """[(line, text, role)] for the words w0..w1 of an indexed unit: the lines that produced them and, for
    inlined code, the statement that called it."""
    src = (ROOT / u["src"]).read_text(errors="replace").splitlines()
    fi_unit = u["files"].index(u["unit_file"]) if u["unit_file"] in u["files"] else -1
    own, sites = set(), set()
    for fi, ln, site in u["lines"][w0:w1]:
        if fi == fi_unit and ln:
            own.add(ln)
        if site and site not in own:
            sites.add(site)
    body = u["body"]
    out = []
    for ln in sorted(own | sites):
        role = "inline" if not (body[0] <= ln <= body[1]) else ("call" if ln in sites and ln not in own else "")
        if ln in own and not (body[0] <= ln <= body[1]):
            role = "inline"
        out.append((ln, src[ln - 1].rstrip() if 0 < ln <= len(src) else "", role))
    return out


def query_entries(toks, blks, lo, hi):
    """Blocks and 2-block windows of the game's function that overlap words lo..hi."""
    out = []
    sel = [k for k, (s, e) in enumerate(blks) if e > lo and s <= hi]
    for k in sel:
        s, e = blks[k]
        if e - s >= 3:
            out.append((s, e))
        if k + 1 < len(blks) and (k + 1) in sel:
            s2, e2 = blks[k][0], blks[k + 1][1]
            if 4 <= e2 - s2 <= MAX_WIN_WORDS:
                out.append((s2, e2))
    return out


def print_hit(ix, rank, score, uid, w0, w1, qlabel, max_asm=20):
    u = ix.unit(uid)
    a0 = u["addr"] + 4 * w0
    print(f"  #{rank} {100 * score:5.1f}%  {u['name']}  {a0:08X}-{u['addr'] + 4 * w1 - 1:08X} ({w1 - w0} words)"
          f"   ~ {qlabel}")
    for l in asm_lines(u["asm"], w0, w1)[:max_asm]:
        print(f"        {l}")
    if w1 - w0 > max_asm:
        print(f"        ... {w1 - w0 - max_asm} more")
    print(f"      C++ ({u['src']}):")
    for ln, t, role in cxx_lines(u, w0, w1):
        tag = {"inline": " [inlined]", "call": " [calls inline]"}.get(role, "")
        print(f"        {ln:5d}: {t.strip()[:110]}{tag}")


def cmd_query(a):
    t0 = time.time()
    rows = {r["name"]: r for r in load_functions()}
    row = rows.get(a.name)
    if not row:
        sys.exit(f"{a.name} is not in config/functions.us.csv")
    ins, toks, blks = func_shapes(ROOT / row["asm"])
    addr = row["addr"]
    ix = Index()
    exclude = ix.unit_ids([a.name] + (a.exclude.split(",") if a.exclude else []))
    targets = []                    # (label, lo, hi) in game words
    if a.block:
        w = (int(a.block, 16) - addr) // 4
        k = next((k for k, (s, e) in enumerate(blks) if s <= w < e), None)
        if k is None:
            sys.exit(f"{a.block} is not inside {a.name}")
        targets.append((f"block {addr + 4 * blks[k][0]:08X}", blks[k][0], blks[k][1] - 1))
    else:
        import match
        import diffmap
        from rtl_dumps import find_source
        src = find_source(a.name, a.src)
        res = match.compare(a.name, str(src))
        if res.error:
            sys.exit(f"{a.name}: {res.error}")
        ops = diffmap.align(res)
        regs = [r for r in diffmap.regions(ops, [None] * len(ops)) if r["game"]]
        for r in regs[:a.regions]:
            g0, g1 = r["game"]
            targets.append((f"region game {addr + 4 * g0:08X}-{addr + 4 * g1 + 3:08X} (weight {r['weight']:.0f})",
                            g0, g1))
    for label, lo, hi in targets:
        print(f"\n== {a.name} {label}")
        if a.show_query:
            for l in asm_lines(row["asm"], lo, hi + 1)[:40]:
                print(f"   | {l}")
        hits = {}
        for s, e in query_entries(toks, blks, lo, hi):
            for score, eid, uid, w0, w1 in ix.search(toks[s:e], exclude):
                key = (uid, w0, w1)
                q = f"game {addr + 4 * s:08X}-{addr + 4 * e - 1:08X}"
                # prefer long query windows when scores tie
                val = (score, e - s)
                if key not in hits or val > hits[key][0]:
                    hits[key] = (val, q, s, e)
        best = sorted(hits.items(), key=lambda kv: (-kv[1][0][0], -kv[1][0][1]))
        seen_units, shown = defaultdict(int), 0
        for (uid, w0, w1), ((score, _), q, s, e) in best:
            if seen_units[uid] >= a.per_unit:
                continue
            seen_units[uid] += 1
            shown += 1
            print_hit(ix, shown, score, uid, w0, w1, q)
            if shown >= a.top:
                break
        if not shown:
            print("  no similar block in the index")
    print(f"\n({time.time() - t0:.1f}s)")


# ---------------------------------------------------------------- leave-one-out

CXX_KW = {"if", "else", "for", "while", "do", "switch", "case", "default", "return", "break", "continue", "goto",
          "new", "delete", "sizeof", "this", "float", "int", "unsigned", "char", "short", "long", "bool", "void",
          "true", "false", "static", "inline", "const", "struct", "volatile"}
CXX_TOK = re.compile(r"[A-Za-z_]\w*|0x[0-9A-Fa-f]+|\d+\.\d*f?|\d+|->|<<=|>>=|<<|>>|==|!=|<=|>=|&&|\|\||\+\+|--|"
                     r"[-+*/%&|^]=|\S")


def cxx_shape(text):
    toks = CXX_TOK.findall(re.sub(r"//.*|/\*.*?\*/", "", text))
    out = []
    for i, t in enumerate(toks):
        if t in CXX_KW:
            out.append(t)
        elif re.match(r"[A-Za-z_]", t):
            out.append("CALL" if i + 1 < len(toks) and toks[i + 1] == "(" else "ID")
        elif re.match(r"\d+\.", t):
            out.append("F")
        elif re.match(r"\d|0x", t):
            out.append(t if t in ("0", "1") else "N")
        else:
            out.append(t)
    return out


def src_shape(u, w0, w1):
    return [t for _, txt, _ in cxx_lines(u, w0, w1) for t in cxx_shape(txt) + [";"]]


def recent_units(n, min_words=32):
    import subprocess
    out = subprocess.run(["git", "log", "--diff-filter=A", "--format=", "--name-only", "-n", "200", "--",
                          "src/funcs"], capture_output=True, text=True, cwd=ROOT).stdout.split()
    rows = {r["name"]: r for r in load_functions()}
    names = []
    for p in out:
        st = Path(p).stem
        if st in rows and st not in names and rows[st]["size"] // 4 >= min_words and (ROOT / p).exists():
            names.append(st)
        if len(names) >= n:
            break
    return names


def cmd_loo(a):
    import random
    t0 = time.time()
    ix = Index()
    names = a.units.split(",") if a.units else recent_units(a.recent)
    rng = random.Random(1)
    all_entries = [r for r in ix.db.execute("SELECT id, unit, w0, w1 FROM entry WHERE w1 - w0 >= ?",
                                            (a.min_words,))]
    tot = defaultdict(float)
    nq = 0
    per_unit = []
    examples = []
    for name in names:
        r = ix.db.execute("SELECT id FROM unit WHERE name=?", (name,)).fetchone()
        if not r:
            print(f"{name}: not in the index")
            continue
        uid = r[0]
        u = ix.unit(uid)
        rows = {x["name"]: x for x in load_functions()}
        _, toks, _ = func_shapes(ROOT / rows[name]["asm"])
        ents = list(ix.db.execute("SELECT w0, w1, nblk FROM entry WHERE unit=? AND w1 - w0 >= ? AND nblk <= 2",
                                  (uid, a.min_words)))
        ustat = defaultdict(float)
        for w0, w1, nb in ents:
            q = toks[w0:w1]
            qs = src_shape(u, w0, w1)
            hits = ix.search(q, exclude={uid}, top=a.top)
            nq += 1
            ustat["n"] += 1
            if not hits:
                continue
            ssims = []
            for score, eid, huid, h0, h1 in hits:
                hs = src_shape(ix.unit(huid), h0, h1)
                ssims.append(difflib.SequenceMatcher(None, qs, hs, autojunk=False).ratio())
            # baseline: random indexed entries of similar size from other units
            pool = [x for x in rng.sample(all_entries, min(len(all_entries), 400))
                    if x[1] != uid and 0.5 <= (x[3] - x[2]) / (w1 - w0) <= 2][:a.top]
            bs = [difflib.SequenceMatcher(None, qs, src_shape(ix.unit(x[1]), x[2], x[3]), autojunk=False).ratio()
                  for x in pool]
            nonclone = [s for (sc, *_), s in zip(hits, ssims) if sc < 0.999]
            vals = dict(asm1=hits[0][0], src1=ssims[0], srcbest=max(ssims), base=max(bs) if bs else 0,
                        idiom1=float(ssims[0] >= a.idiom), idiomk=float(max(ssims) >= a.idiom),
                        baseidiom=float(bool(bs) and max(bs) >= a.idiom), clone1=float(hits[0][0] >= 0.999),
                        nc_idiomk=float(bool(nonclone) and max(nonclone) >= a.idiom), has_nc=float(bool(nonclone)))
            for k, v in vals.items():
                tot[k] += v
                ustat[k] += v
            if len(examples) < a.examples and rng.random() < 0.08:
                examples.append((name, w0, w1, hits[0], ssims[0]))
        per_unit.append((name, ustat))
    print(f"leave-one-out over {len(per_unit)} units, {nq} query blocks/windows (>= {a.min_words} words), "
          f"top {a.top}, 'same idiom' = C++ shape similarity >= {a.idiom}")
    print(f"{'unit':<14} {'q':>4} {'asm@1':>6} {'src@1':>6} {'idiom@1':>8} {'idiom@k':>8} {'baseline':>8} "
          f"{'clone@1':>8}")
    for name, s in per_unit:
        n = s["n"] or 1
        print(f"{name:<14} {int(s['n']):4d} {s['asm1'] / n:6.2f} {s['src1'] / n:6.2f} {s['idiom1'] / n:8.0%} "
              f"{s['idiomk'] / n:8.0%} {s['baseidiom'] / n:8.0%} {s['clone1'] / n:8.0%}")
    n = nq or 1
    print(f"{'ALL':<14} {nq:4d} {tot['asm1'] / n:6.2f} {tot['src1'] / n:6.2f} {tot['idiom1'] / n:8.0%} "
          f"{tot['idiomk'] / n:8.0%} {tot['baseidiom'] / n:8.0%} {tot['clone1'] / n:8.0%}")
    hn = tot["has_nc"] or 1
    print(f"excluding identical-asm hits (clones): idiom@k {tot['nc_idiomk'] / hn:.0%} of {int(tot['has_nc'])} "
          "queries that had a non-identical hit")
    print(f"mean best C++ similarity in top {a.top}: {tot['srcbest'] / n:.2f} vs random same-size entries "
          f"{tot['base'] / n:.2f}")
    for name, w0, w1, (score, eid, huid, h0, h1), ss in examples:
        u = ix.unit(huid)
        print(f"\nexample: {name} words {w0}-{w1}  ->  {u['name']} {h0}-{h1}  asm {score:.2f}  C++ {ss:.2f}")
        q = ix.unit(ix.unit_ids([name]).pop())
        for ln, t, role in cxx_lines(q, w0, w1)[:6]:
            print(f"   query {ln:5d}: {t.strip()[:100]}")
        for ln, t, role in cxx_lines(u, h0, h1)[:6]:
            print(f"   hit   {ln:5d}: {t.strip()[:100]}")
    print(f"\n({time.time() - t0:.0f}s)")


def cmd_stats(a):
    db = connect()
    for k, v in db.execute("SELECT k, v FROM meta"):
        print(f"{k}: {v}")
    print("units:", db.execute("SELECT COUNT(*), SUM(verified), SUM(err != '') FROM unit").fetchone(),
          "(all, -g words equal the game's, errors)")
    print("entries:", db.execute("SELECT COUNT(*) FROM entry").fetchone()[0])
    print("tokens:", db.execute("SELECT COUNT(*) FROM tok").fetchone()[0])
    for n, e in db.execute("SELECT name, err FROM unit WHERE err != '' LIMIT 20"):
        print(f"  {n}: {e}")
    print(f"size: {DB.stat().st_size / 1e6:.0f} MB")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("build")
    b.add_argument("-j", "--jobs", type=int, default=3)
    b.add_argument("--limit", type=int)
    b.add_argument("--units")
    b.add_argument("--force", action="store_true")
    q = sub.add_parser("query")
    q.add_argument("name")
    q.add_argument("--src")
    q.add_argument("--block", help="a game address inside NAME: query that basic block")
    q.add_argument("--top", type=int, default=5)
    q.add_argument("--regions", type=int, default=3)
    q.add_argument("--per-unit", type=int, default=1, help="hits shown per matched unit (default 1)")
    q.add_argument("--exclude", help="comma-separated units to leave out")
    q.add_argument("--show-query", action="store_true", help="print the game's asm of each queried region")
    lo = sub.add_parser("loo")
    lo.add_argument("--recent", type=int, default=10)
    lo.add_argument("--units")
    lo.add_argument("--top", type=int, default=5)
    lo.add_argument("--min-words", type=int, default=6)
    lo.add_argument("--idiom", type=float, default=0.6)
    lo.add_argument("--examples", type=int, default=6)
    sub.add_parser("stats")
    a = ap.parse_args()
    if a.cmd == "build":
        a.jobs = max(1, min(a.jobs, 4))
    {"build": cmd_build, "query": cmd_query, "loo": cmd_loo, "stats": cmd_stats}[a.cmd](a)


if __name__ == "__main__":
    main()
