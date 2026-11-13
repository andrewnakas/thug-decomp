# Decision oracle: SN cc1plus.exe under gdb (`tools/oracle.py`)

`tools/oracle.py NAME` compiles a unit with the real SN ee-gcc 2.95.3 build 1.36 `cc1plus.exe`, stopped by gdb at
the points where gcc makes the decisions our near misses hinge on. For every differing word it prints the pass that
decided it, the competing candidates with their keys, and which key separated them. With `--force` it flips each
candidate decision **inside the running compiler** (rewriting the sorted array at the breakpoint) and recompiles,
so "would a tie flip alone match?" is answered by the compiler itself, not by a model.

```sh
.venv/bin/python tools/oracle.py func_00271D80                       # explain every differing word
.venv/bin/python tools/oracle.py func_00271D80 --force               # + flip each decision, recompile, count words
.venv/bin/python tools/oracle.py func_002BC710 --force --chain 3     # greedy: keep the best flip, search again
.venv/bin/python tools/oracle.py NAME --pass ra|sched|sched1|sched2|reorg|gcse
.venv/bin/python tools/oracle.py NAME --with '{"kind":"ga","before":[337,332]}'   # explain under a forced decision
.venv/bin/python tools/oracle.py NAME --trace                        # raw decision trace (JSON lines)
.venv/bin/python tools/oracle.py NAME --src work/try.cpp --keep work/oracle/NAME
```

Needs `gdb` on PATH (tested: GNU gdb 15, x86-64 Linux) and `toolchain/bin/wibo` 1.2. A traced compile takes about
as long as a normal one plus gdb start-up (0.5-3 s for most units). The traced output is checked against the plain
compile (`!! tracer changed the code` if not; never seen).

A forced result is a **diagnosis, not a contribution**: the build never uses the oracle. What it buys is knowing
which decision to steer with the source (an operand order, a statement order, a temporary), and that steering it is
enough. Example: `func_00271D80` matches if pseudo 337 is allocated before pseudo 332. They tie at priority 9350
and allocno number decides, which is pseudo creation order. So the lever is to create the `0x100($sp)` address
before the `0x128($sp)` one in the source.

## How it works

1. `Unit` runs SN's driver once with `-v -save-temps -dG -dl -dg -dp`. The dump flags do not change the code. This
   keeps the preprocessed `u.ii`, the dumps the explainers parse, and the exact cc1plus command line.
2. `tools/oracle_gdb.py` (gdb's Python) runs `wibo cc1plus.exe ...` and stops at `thunk_kernel32_GetCommandLineA`, a
   wibo symbol. By then the PE image is mapped at 0x400000. It then sets internal breakpoints at the guest addresses
   below. Their `stop()` methods read the compiler's globals, log one JSON event each and return False, so the
   compile never pauses for a user. **`set displaced-stepping off` is required.** gdb debugs wibo as an x86-64
   process, and displaced stepping would re-decode the 32-bit guest code as 64-bit and crash the compile (SIGSEGV).
   With it off, int3 breakpoints, single-stepping, memory and register reads and writes all work in wibo's 32-bit
   code segment.
3. `oracle.py` assembles our output and compares it with the game's (`match.compare`, with the compiler output
   swapped in). It maps each word to its INSN_UID (`rtl_dumps._map_words`) and pseudos to insns (`.lreg`/`.greg`
   via `regalloc_explain.build`). Then it classifies each differing word:
   - **ra**: same instruction, other registers. It names the pseudo in that operand, whether global or local
     allocation placed it, its priority, and the conflicting pseudo that holds the game's register. It says which
     one went first and why: priority, or the allocno/quantity number on a priority tie. Forces: `before`, `swap`.
   - **sched1/sched2**: the game's instruction sits nearby in ours. It finds the ready list of the cycle where we
     issued our insn and, if the game's insn was in it, prints both insns' keys and the first key that separates
     them. If our insn won despite a lower rank, it says so: the function unit was busy or the insn was queued
     (`actual_hazard`). If SN's `MD_SCHED_REORDER` hook changed the order, it says that too. Force: issue the game's
     insn first in that cycle.
   - **reorg**: a delay-slot word, or the same branch with another target. It names the filler that put the insn in
     the slot (`fill_simple_delay_slots`, `fill_eager_delay_slots`, `fill_slots_from_thread`...), using the return
     address seen at `emit_delay_sequence`.
   - **gcse**: gcse's own `-dG` log (CONST-PROP / COPY-PROP / PRE), with `*` on actions that touch a differing insn
     or one of its pseudos. Force: `{"kind":"cprop","reg":R[,"uid":U][,"what":"copy|const"]}` makes
     `try_replace_reg` fail at that propagation (the call is skipped and returns 0).
   - **code shape**: the instruction multisets differ. An alignment lists the game-only and ours-only instructions.
     No tie explains it.

Force specs (`--with` or the trace's `forced` field): `{"kind":"ga","before":[A,B]}` / `{"kind":"ga","swap":[A,B]}`
(pseudo numbers), `{"kind":"la","block":N,"before":[A,B]}`, `{"kind":"sched","pass":1|2,"block":N,"clock":C,"first":UID}`,
`{"kind":"cprop","reg":R}`.

## Hook points in SN 1.36 `cc1plus.exe` (all verified by disassembly against gcc 2.95.3's source)

| What | Address | Reads / forces |
|---|---|---|
| `global_alloc`, after `qsort(allocno_order, max_allocno, 4, allocno_compare)` | 0x4EBC13 | `allocno_order` 0x6107D4, `max_allocno` 0x6107D0, `allocno_reg` 0x6109CC, `allocno_n_refs` 0x6109BC, `allocno_live_length` 0x610B8C, `allocno_size` 0x6109C8; force rewrites `allocno_order` |
| `find_reg` entry / its 5 return sites | 0x4EC790 / 0x4EBC74 0x4EBCB9 0x4ED0E8 0x4ED514 0x4ED53E | args (allocno, losers, alt_regs_p, accept_call_clobbered, retrying); result `reg_renumber` (short*) 0x628F8C |
| `block_alloc` entry; after its qty sort (EXCHANGE/qsort paths join); before the reg_renumber loop | 0x537D50; 0x5384EF (`qty_order` in ebx); 0x5386C7 | `next_qty` 0x611050, `qty_phys_reg` 0x611084, `qty_birth` 0x611068, `qty_death` 0x611060, `qty_n_refs` 0x61104C, `qty_size` 0x6110C4, `qty_first_reg` 0x61106C, `reg_next_in_qty` 0x611054 |
| `schedule_block` entry | 0x4F4830 | bb; block = `rgn_bb_table`[`current_blocks`+bb] (0x610FA4, 0x610CC8); pass from `reload_completed` 0x620508 |
| after SCHED_SORT / after `MD_SCHED_REORDER` (0x40D320) | 0x4F4D4F / 0x4F4D64 | ready array in esi, n_ready in ebx (best insn last); `clock_var` 0x610C58; per uid: `insn_priority` 0x610CD0, `insn_reg_weight` 0x610B94, `insn_depend` 0x610BA0, `insn_luid` 0x610FD4; force moves an insn to the end |
| issue (`last_scheduled_insn = insn`) | 0x4F4F27 | insn in esi; `last_scheduled_insn` 0x610CEC |
| `emit_delay_sequence(insn, list, length)` | 0x57B100 | caller from the return address |
| `cprop_insn` copy-prop / const-prop `try_replace_reg` calls | 0x4E96C2 / 0x4E971C | regno esi, insn edi, src ebx; force skips the call (eax=0) |

Layout facts the tracer depends on: rtx header 8 bytes, every rtx field 8 bytes wide (HOST_WIDE_INT is 64-bit on
this 32-bit host), so INSN_UID is at +8 and XEXP(x,i) at +8+8i. The binary was built by a gcc for Windows (cdecl,
16-byte aligned functions, nop padding). `rank_for_schedule` (0x4F62C0) and `allocno_compare` (0x4EBD10) are
instruction for instruction the 2.95.3 source. allocno_compare computes in x87: `fild; fidiv; fimul; fmul 10000.0;
__ftol`. The tool re-sorts with that formula and warns if its order differs from the compiler's.

**SN-only scheduler hook.** SN's EE backend defines `MD_SCHED_REORDER` (0x40D320, called after every SCHED_SORT).
Stock 2.95.3's mips port does not. It acts only in sched1 (`!reload_completed`), with 3 or more ready insns, and
under a target flag (0x200000) and a cpu-name compare. The tracer records the ready order before and after it. Under
the pinned flags it **never changed an order**: 0 of 3,698 ready lists over 7 units. So it does not explain
`sched_explain.py`'s ~1% of sched1 "priority inversions". The trace itself gives the compiler's real order in those
cycles.

## Phase 1: symbol recovery for the stripped `cc1plus.exe`

The binary has no symbols. Names come from three sources:
- the unstripped Sony `ee-gcc2.9-991111` cc1plus (ELF), matched function by function on string references, call
  graph and link order;
- the public gcc 2.95.3 source, for in-file order, string references and code shape;
- hand verification by disassembly for every hook point above.

Working files live in `work/oracle/` (git-ignored): `mapper.py`, `symmap*.tsv`. See the symbol map section below for
coverage and precision.

**Result:** [`oracle_symmap.tsv`](oracle_symmap.tsv) names **3,511 of 4,302** SN functions. Columns: address,
name, confidence, source file.

| Confidence | Count | Precision |
|---|---|---|
| verified | 40 | hand-checked against the disassembly |
| high | 1,798 | 18 of 20 spot-checked correct, 1 wrong, 1 uncheckable |
| med | 1,389 | 16 of 20 correct, 0 wrong, 4 uncheckable |
| low | 284 | not sampled; treat as a hint (about 50/50) |

Blind self-check: run without the anchors, the automatic pass gets 35 of the 40 verified anchors right, 0 wrong.
The other 5 are left unnamed: `allocno_compare`, `rank_for_schedule` and `swap_sort` are reached only through
qsort, and qsort and `__ftol` are libc. Names from insn-emit, insn-output and insn-recog (`gen_*`, `output_N`) are
unreliable at every level, because SN's EE machine description differs from Sony's.

Coverage of the files the oracle cares about:
- reorg.c: complete except `rare_destination`, which is inlined.
- gcse.c: 87 of 89. `hash_scan_clobber` and `hash_scan_call` are empty functions.
- haifa-sched.c: 104 of 108.
- global.c: 21 of 21.
- local-alloc.c: 25 of 27.
- flow 59/70, regmove 15/18, jump 43/50, final 25/38, combine 53/58, reload1 65/81.

Most of the missing names are small statics that were inlined.

Method notes:
1. **Function starts.** They come from call targets, tail jumps, code-pointer immediates (qsort comparators) and
   padding boundaries. 513 inline switch tables in .text are stripped first, so they are not decoded as code, and
   padding targets that are only jump labels are dropped.
2. **First matching pass.** Names are matched on unique shared strings. The callee and caller sequences of matched
   pairs are then aligned, which propagates names. Each candidate is scored against the identifiers and strings of
   the gcc 2.95.3 function bodies, including callees of inlined statics. A negative score demotes or drops it.
3. **Function order.** SN does not keep source order within a file. Functions come caller-first, a depth-first walk
   from each file's top function: `dbr_schedule` leads reorg.c, and `schedule_region` comes before
   `schedule_block`. So order is only a weak check, and source-order gap filling was dropped.

**Surprises:**
- SN has one big `global_alloc`, where Sony's 2.9 has a big `global_init` instead.
- `qty_compare_1` exists only in SN.
- SN's EE backend has `mips_sched_reorder` at 0x40D320. The name comes from the 2.9-ee reference.

The mapper scripts (`mapper.py`, `mapper2.py`, `srcorder.py`) stay in the git-ignored `work/oracle/`. They need the
GPL gcc-core-2.95.3 tarball (from ftp.gnu.org) and the two binaries, none of which are committed.

## Validation (2026-11-13)

| Unit | Class | Oracle says | Forced result |
|---|---|---|---|
| func_00271D80 | regalloc tie (0.9350) | global-alloc: pseudos 332 and 337 tie at priority 9350, allocno number (86 < 91) puts 332 first, so 332 takes `$s1` | `ga before [337,332]`: **MATCH** (7 -> 0 words) |
| func_002BC710 | `this` priority vs key counter | global: pseudo 116 (`this`, priority 9666) beats 121/143/186 to `$s0` on priority (not a tie); then a sched2 cycle (block 7, t=7) where insns 340 and 352 tie on every key but luid | `ga before [121,116]`: 42 -> 2 words; + sched2 issue order 352/633 at block 7 t=7: **MATCH** (3 forced decisions, found by `--chain`) |
| func_0015D8A0 | | code shape: 201 words; game-only/ours-only instructions listed; no single flip helps (best 200) | none |
| func_002A0840 | gcse const-prop | code shape (10 game-only insns: the `nor`/`movn` sequence); gcse log marks CONST-PROP of reg 123 in insn 396 and COPY-PROPs of 124/131 into insn 81 as touching the differing insns | not a tie |
| func_00145DC0 | reorg delay slot | reorg: same branch (insn 219), target one word off; our slot was filled by `fill_eager_delay_slots` with insn 224; the game filled it from the taken thread (target's first insn copied, branch to target+4) | report only (no reorg force yet) |
| func_0022F500 (lane 1) | second copy of a `new` result | see below | `cprop` force: not the cause |

**func_0022F500: where `daddu $s4, $s3` comes from.** The copy is insn 219, `(set (reg/v 146) (reg 149))`: the
user variable that receives the `new` result (149 is the call's value via the inlined constructor's `this`, pseudo
150). At expand time the later field stores (insns 227, 231, 237, 269: offsets 0x38, 0x4C, 0x44, +0x18) address
through the variable 146. **cse.c (first pass) folds them to 149** inside the extended basic block, so 219 dies and
one register remains. The game still has them on the variable: `s3` = 149 (constructor stores 0x4-0x14), `s4` = 146.
So in the original, cse did not see 146 == 149 at those stores. gcse's COPY-PROP of 146 -> 149 (insns 348-406, later
blocks) is not the cause. Forcing it off (`--with '{"kind":"cprop","reg":146}'`) keeps insn 219 alive, but 149
then dies early and sits in `$v0`, while the game keeps 149 live across those blocks in `$s3`. So the copy-prop did
fire in the original; the fold that is missing is cse's, in this block. The lever to try in source is a
basic-block boundary or an opaque assignment between the variable's assignment and those stores, e.g. the
assignment made where cse cannot see the `new` value: through a conditional, or after a call.

## Batch result

This run covered the 60 nonmatching units with the highest fuzzy scores (97-99.x). The settings were
`--force --chain 3 --max-force 10`; each unit took about 1-5 minutes. Results:

- **14 of 60 reach a byte-exact MATCH by forcing compiler decisions alone.**
  - 12 need one flip:
    - global-alloc order: func_00271D80, func_0025E0A8, func_001E04D8, func_001DF490;
    - sched2 ready-list pick: func_002284B0, func_001B1340, func_001BB720, func_001CFB18, func_001C2870,
      func_00120C28, func_002B3718, func_00106098.
  - 2 need a chain of 2-3 flips: func_00290A80, func_00116170.
  - For these 14 the residue is proven to be ties or orderings. A source change that moves those decisions (creation
    order of a pseudo, statement order for the luid key) is enough.
- 16 more improve under forcing without matching. Examples: func_001C1808 8->2, func_001D6800 7->4,
  func_002C0730 9->7, func_001855A8 26->18.
- 9 are flagged code shape (instruction multisets differ). No tie can fix these.
- The rest (about 20) have differences that no single recorded decision moves. These include reload's own register
  choices (scratch or spill registers), find_reg's choice when the game's register was free, and dependence-limited
  orderings.

Takeaway: for these near misses, **sched2 ready-list ties outnumber register-allocation ties**: 10 of the 14 MATCH
cases are sched2. In those cases the competing insns tie on priority. They are separated by a late key:
- luid (source order): 5 units;
- the number of dependents: 3 units;
- or the winner was issued over a better-ranked insn whose unit was busy.

So the levers are statement order and which value gets used more.

Correction: the "luid 21 vs 21" line in `func_00106098` was a bug. When an insn spans two words, the oracle compared
it with itself. That is fixed.

Because the chain is greedy, it keeps a flip only if the word count drops. An earlier version kept a worse one:
`func_0023A778` went 7 -> 17. That is fixed.

## From forced flip to source fix (2026-11-13)

We took the 14 units that matched under forcing, plus 6 that improved, and looked for a natural source change that
flips the same decision. Every result was checked with `match.py` on a real compile. **2 became exact matches**
(PR #682). The rest stayed as they were.

| Unit | Decision the oracle named | Outcome |
|---|---|---|
| func_001CFB18 | sched2 luid tie: `out++` against the strength-reduced `pts[j-2]` pointer | **MATCH**: index `&out[j]` instead of `out++`, so loop.c makes both induction variables in the game's order |
| func_00121200 | sched1 reg-weight key: the `v.y` store against `s->w = 1.0f` | **MATCH**: one `v.Set(s, s, s, 1.0f)` replaces the split stores |
| func_00271D80, func_0025E0A8 | global-alloc tie broken by allocno number, but both pseudos are **gcse PRE reaching regs** | none (see below) |
| func_001E04D8, func_001DF490, func_00290A80, func_00116170 | global-alloc priority **difference** (not a tie), from live lengths set by sched1's argument-move order | none |
| func_001B1340, func_001BB720, func_00106098 | sched2 luid order inherited from **sched1's reg-weight key**: a store or block copy against a hard-register argument setter | none |
| func_002B3718 | sched2 luid order inherited from sched1, where one insn is a PRE copy placed at the end of its block | none |
| func_001C2870, func_002284B0, func_00120C28, func_002A8270 | "dependents" key; counts fixed by call-clobber output dependences or argument setup | none |
| func_001C1808 | global-alloc exact tie between two pseudos made inside one dot-product expression | none |
| func_001D6800, func_0019FD58, func_001C0F20 | alias/dependence or argument-move order | none |

What converted, and what cannot convert:

- **Converted:** both ties sat between two insns from neighbouring statements or one statement, and the original
  shape was a different but equally natural way to write those statements: indexing instead of bumping, one
  setter instead of member stores. Swapping two statements alone fixed nothing here.
- **Check sched1 before trusting a sched2 luid tie.** luid is the insn order after sched1. When sched1 ordered the
  pair by reg weight (a store or block copy frees or births no register; a hard-register argument setter births
  one), no statement order flips it. Run `sched_explain.py --pass 1 --why A B` or the oracle's sched1 lines first.
  This was the case in 4 units: func_001B1340, func_001BB720, func_00106098 and func_002B3718.
- **Allocno-number ties between PRE reaching regs are not source order.** gcse creates the reaching regs in hash
  bucket order, bucket = (hash + K) mod S, with S = max_cuid/2 | 1 (the gcse hash-table size). It was measured on
  two units; for a SYMBOL_REF the hash is h += (h << 7) + c over the name, K = 7933. Flipping the order means
  changing the insn count at gcse time by a computable amount, for example -16 or +27 insns in func_00271D80. In
  both units every edit that did this also changed the final code. The `-dG` log line "reaching reg is N" identifies
  this class.
- **Global-alloc priority is not a tie** when live lengths differ by one or two insns because sched1 placed the
  argument loads. The argument order fixes those, not the source.
- **"Dependents" decisions** need a real extra use of a value. The game showed none in all 4 units.

Rule of thumb for agents: use the oracle to **classify** a near miss first. Only luid ties whose sched1 order was
itself a luid tie, and global-alloc ties between user pseudos (not PRE regs), are worth source edits. Everything
else above is an internal ordering that the source does not reach.

## Classification of every nonmatching unit (2026-11-13)

All 368 `src/nonmatching` units were run through `oracle.py --force --chain 3 --max-force 8 --json` and classified
by `tools/oracle_classify.py`. The result is `work/oracle/classes.tsv`, also shared as
`~/Documents/thpsundergroundDecompProject/work/oracle_classes.tsv`. Its columns are unit, size, fuzzy, class,
deciding decision, forced result and differing words. The run took about 2 hours at 2 jobs through memgate.

| Class | Units | Bytes | Gap bytes (size x (100 - fuzzy)) | Forced MATCH |
|---|---|---|---|---|
| A: reachable tie | 11 | 5,316 | 208 | 1 |
| B: code shape | 230 | 252,016 | ~22,700 | 0 |
| C: unreachable internal order | 127 | 118,652 | ~4,900 | 30 |

**Rules.** A unit is **A** only if the forced flip that gained the most words is itself a reachable tie, meaning one of:
- a ready-list luid tie that sched1 also tied on luid;
- a global or local allocation tie on allocno or quantity number between pseudos that are not gcse PRE reaching regs.

The first version labelled a unit A whenever any such tie appeared among its differing words. That gave 54 A units.
Of the 11 worked by hand, 10 were misclassified:
- the flip that gained was a priority decision or a PRE register;
- or the "tie" was only a word shifted by code elsewhere, already in the game's order.

**B** means the instruction multisets differ and no forced flip reaches a match. **C** covers everything else:
- PRE-register ties, priority gaps, dependents and reg-weight keys;
- sched2 orders fixed by sched1;
- find_reg, reload and reorg choices.

30 units in C reach a byte-exact match when the compiler's decisions are forced. They are 100% proven to be
compiler-internal ties or orders; only a shape the oracle cannot see (cse, loop.c or PRE side effects) would fix them.

**Converting A by hand, 18 units.**
- 0 exact matches.
- 4 fuzzy gains: func_001BA5D0 85.2->98.1, func_001A07E0 81.7->93.6, func_001A7108 80.7->83.3,
  func_00209608 76.9->77.1 (PR #689).
- Plain swaps of the two tied statements helped in 0 of 18 cases.
- The gains came from:
  - moving a *third* statement relative to the tied pair;
  - an equally natural different shape: a `Trim()` that returns its list, a ternary instead of assign-then-if.

**Reachable ties that the source still cannot reach:**
- a store just before a call against that call's argument move (expand_call emits the move right before the jal);
- luid ties between loop.c-generated preheader insns;
- ties inside an inline helper that is used twice, where every reorder hits both uses.

**Known classifier gaps:**
1. The sched1 key in the JSON (`s1`) is read from the trace's ready list at the first cycle the pair met. In
   func_00292630 the hand analysis found reg weight where the record said luid.
2. A word that is only shifted is not told apart from a real reorder.
3. Insns created by loop.c and call-argument moves are not flagged as unreachable.

## Limits and next steps

- Reorg has no force yet: the trace shows the filler, not the thread decision inside `fill_slots_from_thread`.
- cse.c has no hooks. The func_0022F500 diagnosis above was made from `-dr`/`-ds` dumps by hand.
- PRE hash order is shown through the `-dG` log (expression numbers = hash-table order; reaching regs are new pseudos
  numbered in that order, which feeds allocno_compare's tie-break). It is not forced.
- Ready-list forces are keyed by (pass, block, clock). A force that changes an earlier cycle shifts later clocks.
  `--chain` re-explains after each kept flip, so later forces are found against the new schedule.
- The addresses are specific to `ee-gcc2.95.3-136/lib/gcc-lib/ee/2.95.3/cc1plus.exe` (sha256 in
  `toolchain/checksums.sha256`). Another build needs its own map.
