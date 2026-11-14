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
     address seen at `emit_delay_sequence`, and each fill_eager branch's `prediction` (`eager` events). Force:
     `{"kind":"reorg","uid":B,"pred":P}`.
   - **gcse**: gcse's own `-dG` log (CONST-PROP / COPY-PROP / PRE), with `*` on actions that touch a differing insn
     or one of its pseudos. Force: `{"kind":"cprop","reg":R[,"uid":U][,"what":"copy|const"]}` makes
     `try_replace_reg` fail at that propagation (the call is skipped and returns 0); `{"kind":"pre","uid":U}`
     makes pre_delete's `validate_change` fail for that occurrence.
   - **code shape**: the instruction multisets differ. An alignment lists the game-only and ours-only instructions.
     No tie explains it.

Force specs (`--with` or the trace's `forced` field): `{"kind":"ga","before":[A,B]}` / `{"kind":"ga","swap":[A,B]}`
(pseudo numbers), `{"kind":"la","block":N,"before":[A,B]}`, `{"kind":"sched","pass":1|2,"block":N,"clock":C,"first":UID}`,
`{"kind":"sched",...,"clock":C,"first":[U1,U2]}` (U1 issued first, U2 second in that cycle: the EE issues up to
two insns a cycle), `{"kind":"sched","pass":P,"block":N,"picks":K,"order":[UIDs]}` (replay a whole block; see
"Target-directed search"), `{"kind":"cprop","reg":R}`, and the register-allocation kinds of "Register choice and
spill-slot forces" below: `{"kind":"spill","order":[P1,...]}`, `{"kind":"fr","reg":P,"hard":H}`,
`{"kind":"lfr","block":B,"reg":P,"hard":H}` (H is gcc's hard register number: 2 = `$v0`, 4 = `$a0`, 32 + n = `$fn`),
and the reorg/gcse kinds of "Delay-slot thread and gcse forces" below: `{"kind":"reorg","uid":B,"pred":P}`,
`{"kind":"cprop","reg":R,"uid":U,"what":"copy|const","pass":K}`, `{"kind":"pre","uid":U}` /
`{"kind":"pre","expr":E,"pass":K}`.

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
| `one_cprop_pass` / `one_pre_gcse_pass` entries (pass counters) | 0x4E8C10 / 0x4E9B50 | both zero their own counters first (`const_prop_count` 0x61073C, `gcse_subst_count` 0x610638) |
| `pre_delete`: its `validate_change (insn, &SET_SRC (set), expr->reaching_reg, 0)` call | 0x4EA922 (returns to 0x4EA927) | insn edi, bb ebp, expression index [esp+0x38]; force skips the call (eax=0) |
| `fill_eager_delay_slots`: after `prediction = mostly_true_jump (insn, condition)` (call 0x57CCBF), before `if (prediction > 0)` | 0x57CCC7 | insn esi, prediction eax (also feeds `likely = prediction == 2`); force rewrites eax |
| reload1.c `alter_reg(i, from_reg)` 0x56CF60: the call in reload()'s `for (i = LAST_VIRTUAL_REGISTER + 1; ...)` loop / in `finish_spills`' loop; `finish_spills` entry | 0x56A86D / 0x56F66A; 0x56EFA0 | args at [esp], [esp+4] at the `call`; `reg_old_renumber` (short*) 0x6151B8, `max_regno` 0x62914C; force rewrites the two pushed args |
| `assign_stack_local` entry; its two calls in `alter_reg` (returned MEM at the next insn) | 0x4DE3D0; 0x56D028 / 0x56D0D3 | `frame_offset` (64-bit) 0x629128; slot offset = INTVAL of the MEM's PLUS |
| global.c `find_reg` arg 2 `losers` (a HARD_REG_SET *, 16 bytes: FIRST_PSEUDO_REGISTER is 111) | [esp+8] at 0x4EC790 | force points it at 0x62CFE0, 16 unused bytes past .data's VirtualSize (0x62CFC4) in its last mapped page |
| local-alloc.c `find_free_reg(class, mode, qty, acc, just_try_suggested, born, dead)` / the insns after its 6 calls | 0x539480 / 0x53843D 0x5385AD 0x5385FB 0x53865A 0x53869C 0x5398C3 | `qty_phys_copy_sugg` (HARD_REG_SET*) 0x611064, `qty_phys_num_copy_sugg` (short*) 0x611074, `qty_phys_num_sugg` 0x61105C, `qty_phys_sugg` 0x6110AC |

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
| func_00145DC0 | reorg delay slot | reorg: same branch (insn 219), target one word off; our slot was filled by `fill_eager_delay_slots` with insn 224; the game filled it from the taken thread (target's first insn copied, branch to target+4) | `{"kind":"reorg","uid":219,"pred":1}`: **MATCH** (1 -> 0 words) |
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

## Concession tier (2026-11-13)

`src/concession/func_X.cpp` units carry their forces as `/* force: {...} */` lines, in the JSON `--with` takes.
`tools/concession.py` verifies a unit: a plain compile must NOT match, and a traced compile with exactly those
forces must match byte for byte (relocations resolved); hook errors fail it. `gate.py` calls the same check, so
the judge needs gdb and wibo, as the oracle does. A verification costs about 3 seconds. `--find --write` runs
the greedy search (`--force --chain 4 --max-force 10`) on a src/nonmatching unit and moves it on a match.

Forces are keyed by pseudo-register numbers, block numbers and clocks, so they are tied to the exact source
text: any edit to a concession unit needs a fresh `--find`. Allowed kinds: `ga`, `la`, `sched` (at most 8 decisions
per unit, counted as in "Target-directed search" below), since 2026-11-13 `spill`, `fr` and `lfr` (see
"Register choice and spill-slot forces"; a spill order of N pseudos counts N - 1 decisions), and `reorg`, `cprop`
and `pre` (see "Delay-slot thread and gcse forces"; one decision per line). New kinds (reload register choice)
are added to `FORCE_KINDS` in tools/concession.py as the oracle learns to force them, and listed here.

## Target-directed search (2026-11-13)

`tools/oracle_directed.py NAME` (and `tools/concession.py --find --directed [--write]`) reads the decisions off
the game's code instead of flipping one tie at a time:

1. **Word alignment.** Every game word is paired with one of our words: the same word nearby (a reorder), else
   the same instruction with other registers. Two variants (identical words first, or a shape-level sequence
   alignment first) because each fails somewhere: two same-shape insns swapped, against an identical word that
   lives elsewhere. The word -> INSN_UID map then names, for every game word, our insn that produced it.
2. **sched replay.** Per basic block, the game's order of those insns becomes a target. The new force
   `{"kind":"sched","pass":P,"block":B,"order":[uids]}` ranks every ready list of that block by the target
   (earliest issued first; insns it does not name stay in front in their own order). It only permutes the
   ready list the compiler built: a busy unit still skips or queues an insn. Delay-slot insns filled from
   before their branch are put back before it. Done for sched2 and for sched1 (the target there is the game's
   final order, an approximation).
3. **Directed global alloc.** For every pseudo whose register differs from the game's, the conflicting pseudo
   that holds the game's register and was allocated first gives `{"kind":"ga","before":[p,q]}`; the whole set is
   tried at once, and each constraint alone.
4. **Beam search** (width 2, 5 rounds, 60 traced compiles by default) over those candidates plus oracle.py's
   own single flips, so a flip that does not lower the count can still be kept if a later one does.
5. **Minimise.** Forces whose removal keeps the match are dropped. Each replay order is rewritten as the
   cycles it actually overrode, `{"kind":"sched",...,"clock":C,"first":[U1,U2]}`: the EE issues two insns a
   cycle, and the greedy search could only name the first. The drop pass runs again on the result.

**Result on the 97 class C units the greedy search could not force** (`work/concession/batch2c.txt`):
**17 reach a forced match** (16 written to src/concession; func_00292630 needs 13 decisions, over the cap).
By the classifier's deciding decision: ga priority gap 4 of 22, sched2 dependents 5 of 7, luid tie 3 of 8,
sched2 luid / sched1 reg weight 2 of 3, dependence order 1 of 2, find_reg 1 of 11, reload 1 of 5; sched
priority 0 of 22, ga order tie 0 of 15. Decisions per written unit: 1 (6 units), 2 (6), 3 (3), 8 (1). A rerun
of the 22 units left at 1-4 differing words with beam 3, 8 rounds and 200 compiles found nothing more. About
1-2 minutes per unit at 2 jobs (each traced compile is light: under 100 MB).

Why the greedy search missed them: 30 of the 35 force lines in these units set **both** issue slots of a cycle
(`"first":[U1,U2]`). Forcing only the first slot moves the second insn to another cycle, so the count does
not drop and the greedy search discards the flip. Classification by `oracle_classify.py` was often wrong about
the deciding pass: func_001154D0 and func_0011B148 were labelled "ga priority gap" and need one sched2 cycle.

Counting: `MAX_FORCES` (8) now counts decisions, not lines (`concession.count_decisions`). A
`"first":[U1,U2]` line is one decision (one cycle's ready list). A replay `order` line counts as its `"picks"`,
the number of cycles whose top of the ready list it changed; `verify` recounts that from the trace and fails a
unit whose declared `picks` differs. The minimiser turns every order into per-cycle lines when that reproduces
the match, so no unit written in this batch carries an `order` line.

What still fails (measured, not assumed):
- **Hazard timing.** In func_00201488 the game issues `sd $s4` before `daddu $s5,$v0`; under the replayed
  order the store unit is busy in that cycle and the scheduler issues the `daddu` in the free slot. The game's
  cycle structure differed earlier (a dependence or latency we do not reproduce), not its ready-list order.
- **find_reg and local alloc.** func_00133170: the game gives the higher-priority pseudo `$v0` while ours takes
  `$v1` with `$v0` free; no allocno order produces that. These need live ranges from a different sched1.
- **Dependences.** func_0012F420: the game hoists a load above stores ours keeps it behind (memory
  dependence), so it is never in the same ready list.

## Register choice and spill-slot forces (2026-11-13)

Three force kinds reach allocation decisions the earlier kinds could not. Each one acts on an **input** of the
compiler's own routine (a loop order, a `losers` set, a suggestion set) and leaves the choice, its legality
checks and its bookkeeping to that routine; the hook only verifies afterwards that the routine took the asked-for
option, and reports a hook error (which fails `concession.py`) if it did not.

| Kind | Spec | What it changes | Why the result is a choice the compiler could make |
|---|---|---|---|
| `spill` | `{"kind":"spill","order":[P1,P2,...]}` (optional `"site":"finish"`, `"n":K` for the K-th `finish_spills`) | the order in which reload's loop `for (i = ...; i < max_regno; i++) alter_reg (i, -1);` visits the named pseudos: the k-th iteration that would call `alter_reg` for one of them calls it for `order[k]` instead | every pseudo still gets exactly one `alter_reg` call, and `alter_reg`/`assign_stack_local` assign the slots; only the order of the slot assignments (hence which spilled pseudo gets which offset) is permuted. The hook fails unless all N named pseudos were replayed |
| `fr` | `{"kind":"fr","reg":P,"hard":H}` (optional `"retrying":1` for reload's `retry_global_alloc`) | global.c `find_reg` for P is entered with every hard register except H in its `losers` argument (ORed into any `losers` it already had) | `find_reg` applies all its own tests to H (class, `hard_reg_conflicts`, fixed and call-used sets, mode, the pass-0/pass-1 rule) and, when H passes, records `reg_renumber`, `regs_used_so_far` and the conflicts of the other allocnos itself. If H fails a test, `find_reg` returns no register: hook error. `losers` is the input global.c itself uses to exclude registers (caller-save retry, reload's retry) |
| `lfr` | `{"kind":"lfr","block":B,"reg":P,"hard":H}` | local-alloc.c `find_free_reg` calls for P's quantity in block B become `just_try_suggested` calls whose only copy-suggested register is H; the quantity's suggestion sets are restored when the call returns | `find_free_reg` checks H against the class, fixed/call-clobbered sets and `regs_live_at` over the quantity's whole lifetime, and marks it live itself (`post_mark_life`). block_alloc's own fallbacks (the real lifetime after the widened one, the alternate class) run as usual; the hook fails unless the quantity ends with H |

Spot check (forcing the compiler's own choices must change nothing): on 11 matched src/funcs units (the 6
largest, including func_001AC030 with 222 find_reg choices, 629 local quantities and 28 spill slots, and 5
mid-sized ones), every `fr` and `lfr` set to the register the plain compile chose, plus a `spill` order equal to
the natural one, gives byte-identical assembly with no hook error. Negative check: `fr` asking for `$zero` is
refused by find_reg (hook error, no match).

Finding the forces (`tools/oracle_directed.py`, also behind `concession.py --find --directed`):
- **spill.** Our and the game's words are paired by position (a slot permutation moves no instruction; the
  word alignment is used only when the sizes differ). Every pair of `$sp`-based loads/stores with different
  offsets votes "our offset -> game offset". The trace gives each slot's frame offset (`slot` events); the
  constant between frame offsets and `$sp` offsets is the one that puts the most votes inside the slot range at
  both ends. The spilled pseudos are then sorted by the offset the game gives them, and the pseudos the
  permutation leaves in place are dropped from the order.
- **fr / lfr.** For each pseudo whose register differs from the game's (the same alignment as directed global
  alloc), an `fr` force if find_reg placed it in this compile, else an `lfr` force for its block. All of them
  are tried together, and each one alone.

**Result** (`concession.py --find --directed --write`, the units of the earlier batch blocked on stack slots,
find_reg or reload): **10 of 18 reach a forced match** and were written as concession units.
- spill: func_002C9FA8 (one order of 5 pseudos), func_0024C590 (3), func_00206F68 (3), func_00273DB0 (4, plus
  one `fr`).
- fr: func_00273A60, func_001C6218 (one decision each).
- lfr: func_001DA8F0, func_001CEA68 (1), func_00209B80 (3), func_00215388 (6: one inline body expanded six
  times, the same choice in each).
- No match: func_001EB180, func_001EC7A0, func_001FEC38, func_00231FE8 (find_free_reg refuses the game's
  register under our lifetimes, or a schedule difference remains), and all four "reload" units:
  func_001FDFA8 is a code-shape difference (the game's `lui $at` is an assembler macro expansion of another
  insn pattern); in func_00294AB0 the game keeps pseudo 119 apart from 134, which combine_regs ties into one
  quantity in ours; func_002448C0 and the first differences of func_002C0BE0 are two argument moves (hard
  registers) issued in the other order, and the shape-only alignment reads that as a register swap. No reload
  register choice is involved in any of them, so no reload kind was added.
- The classifier's "find_reg choice" label covers both allocators: 4 of the 6 such units that matched needed
  `lfr` (local-alloc placed the pseudo), not `fr`.

Not yet exercised: the `"site":"finish"` form of `spill` (pseudos spilled during reload, whose slots
`alter_reg` shares per hard register). It is implemented on the same pattern but no unit needed it.

All four stack-slot units in this batch had their spilled pseudos in a rotated order: the game assigns the slots
of the higher-numbered pseudos first (for example 287, 288 before 278, 279, 281). That suggests the pseudos were
created in another order in the original (an inline body expanded earlier, say); the source lever is not known.

## Delay-slot thread and gcse forces (2026-11-13)

Three more kinds reach the two residues the blocked notes kept naming: which thread reorg fills a branch's delay
slot from, and a gcse propagation or PRE deletion the game did not make. Like the register kinds, each acts on an
**input or a failure path the pass already has**: the pass still runs every one of its own legality tests, and
the hook only reports an error (failing `concession.py`) if the decision point never came.

| Kind | Spec | Hook | What it changes | Why the result is a choice the compiler could make |
|---|---|---|---|---|
| `reorg` | `{"kind":"reorg","uid":B,"pred":P}` (optional `"n":K`: only the K-th time fill_eager_delay_slots reaches B; it runs twice, MAX_REORG_PASSES) | 0x57CCC7 | the value `prediction = mostly_true_jump (insn, condition)` has in fill_eager_delay_slots for conditional branch B; P is one of the values mostly_true_jump returns (-1, 0, 1, 2) | prediction is a branch-probability estimate. It only picks which thread `fill_slots_from_thread` tries first (the target when > 0, else the fall-through when the branch owns it) and its `likely` argument (P == 2). Both orders are code the pass runs for some branch; inside, every candidate still passes the resource, opposite-thread liveness, `may_trap_p`, annul (`eligible_for_annul_*`), thread-ownership and `redundant_insn` tests, and the jump is redirected by the pass itself. Unconditional branches (prediction fixed at 2) are not hooked |
| `cprop` | `{"kind":"cprop","reg":R,"uid":U,"what":"copy"\|"const","pass":K}` | 0x4E96C2 / 0x4E971C | cprop_insn's `try_replace_reg (R, src, U)` fails (the call is skipped, returns 0) in cprop pass K (1 = the first pass, 2 = the final alter_jumps pass) | try_replace_reg is `validate_replace_src`, which fails whenever the replaced insn is not recognised; cprop_insn then just moves on to the next register. Not propagating is always correct (the register still holds the value) |
| `pre` | `{"kind":"pre","uid":U}` or `{"kind":"pre","expr":E,"pass":K}` (every redundant occurrence of expression E) | 0x4EA922 | pre_delete's `validate_change (insn, &SET_SRC (set), reaching_reg, 0)` fails for occurrence U (or all of E's) | gcse.c handles that failure ("on the x86 some of the movXX patterns ... may cause validate_change to fail"): the occurrence keeps its own computation and is not marked `deleted_p`, so pre_insert and pre_insert_copies make no insertion or copy for it. With all of E's occurrences declined, PRE leaves E alone (the reaching-reg pseudo is still created, as on that path) |

Each line counts as one decision. Reverse forces (a propagation or a PRE deletion the compiler did *not* make, a
thread the pass's tests reject) are not offered: they would need the pass to skip a legality test.

Identity check (forcing the compiler's own choices must change nothing): on 11 matched src/funcs units (the 6
largest, func_001AC030 with 251 fill_eager visits, and 5 mid-sized), every fill_eager branch forced to its own
prediction (with `n`) plus a `cprop` decline of every try_replace_reg call that failed by itself (110 calls)
gives byte-identical assembly and no hook error.

Finding the forces (`tools/oracle_directed.py`): the differing words, their neighbours (delay slots) and the
pseudos of their insns form an "involved" set. `reorg` candidates are the other predictions (<= 0 -> 1 and 2;
1 -> 0 and 2; 2 -> 0 and 1) for every fill_eager branch in that set or whose slot insn is. `cprop` candidates are
the successful propagations (the `-dG` log's COPY-PROP / CONST-PROP lines, matched to the trace's calls for the
pass number) into an involved insn or of an involved pseudo; `pre` candidates are the redundant occurrences that
are involved, and every expression whose reaching reg or inserted insn is. Each is tried alone on top of the
current state, before the schedule and allocation candidates, in every round of the beam search.

**Result** (`concession.py --find --directed --write` on the 182 src/nonmatching units whose diff touched a
fill_eager branch or a gcse action, all but the 20 lane-claimed units; about 30 s per unit at 2 jobs, each traced
compile under 100 MB): **3 new concession units**, all through `reorg`.
- func_00145DC0 (`reorg` 219 pred 1) and func_001BA1F8 (`reorg` 225 pred 1; the game's slot is an annulled
  `bc1fl` filled from the target): one decision each. Both are the LAST_MILE "delay slot filled from the branch
  target" residue. With the target thread tried first, the pass itself also produces the rest of the game's code
  around the branch (the note expected a fall-through copy to linger; it does not).
- func_0018C0A8: two `reorg` decisions plus one `fr` and two sched2 cycles (5).
- Over the cap: func_00148990 (11 sched cycles), func_00159060 (a spill order of 10 pseudos, 9 decisions); no new
  kind involved.
- `cprop` and `pre`: **no unit converted, and no single decline lowered the differing-word count** in the gcse
  units the blocked notes name (func_001ADDC8, func_001B9E30, func_00168F58, func_00265038, func_00107050,
  func_001FE5D8). Declining the PRE deletions of func_001ADDC8 (insns 114, 145) stops the latch copies but the
  game's loop is still strength-reduced differently (18 -> 37 words); in func_001B9E30 the kept copy of m16C is
  not a gcse COPY-PROP (only reg 123 -> 119 props exist, and declining them changes nothing near 0x1B9E4C). So
  these residues come from cse/loop.c, or from propagations the game *did* make that ours did not (a reverse
  force, which would skip legality tests and is not offered).

## Limits and next steps

- Reorg forces reach fill_eager_delay_slots' thread order only; a slot fill_simple_delay_slots filled from before
  the branch (so fill_eager never saw it) is not forced.
- cse.c has no hooks. The func_0022F500 diagnosis above was made from `-dr`/`-ds` dumps by hand.
- PRE hash order is shown through the `-dG` log (expression numbers = hash-table order; reaching regs are new pseudos
  numbered in that order, which feeds allocno_compare's tie-break). It is not forced (a `pre` force declines a
  deletion; it does not reorder the table).
- Ready-list forces are keyed by (pass, block, clock). A force that changes an earlier cycle shifts later clocks.
  `--chain` re-explains after each kept flip, so later forces are found against the new schedule.
- The addresses are specific to `ee-gcc2.95.3-136/lib/gcc-lib/ee/2.95.3/cc1plus.exe` (sha256 in
  `toolchain/checksums.sha256`). Another build needs its own map.
