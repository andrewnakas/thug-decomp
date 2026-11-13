# The last 1-5%: how other matching decomps closed their hardest functions

Research catalogue, 2026-11-13. It covers **only what is not already in** [PS_GCC.md](PS_GCC.md),
[N64_AND_PERMUTER.md](N64_AND_PERMUTER.md) and [../MATCHING_GUIDE.md](../MATCHING_GUIDE.md). Read those first: they cover the gcc 2.x
allocation and scheduling rules, the permuter, `do {} while (0)`, declaration order, inline wrappers and the
"how 100% projects finished" tables. No leaked source was opened. Other projects' code was read for ideas only;
nothing was copied. Raw downloads are in `work/research/` (git-ignored).

Section 1 has **measurements taken in this repo** while researching (they turn two leads into data). Sections 2-6
are techniques from other projects. Section 7 ranks what to try next.

**Here?** tags: **OK** = plain C++ our gates accept. **Careful** = allowed only if it reads as real code.
**Tool** = a tooling or flag change (maintainer/`tooling` issue). **N/A** = does not apply to SN ee-gcc 2.95.3 C++.

---

## 1. Measured here (2026-11-13)

All runs used `match.py`'s `compare()` with the pinned flags plus the variant, on the 434 units in
`src/nonmatching/` (and, for regressions, the 1,701 matched units in `src/funcs/` that contain a loop).
The scripts and TSVs are in `work/vu0sweep/` and `work/cc29/`.

### 1.1 `-mvu0-use-vf0-vfN` is a free knob on loop.c's hoisting threshold, and it matches one unit outright

**Where it comes from.** Ratchet & Clank 3 (same SN 1.36 compiler) found that every one of its frontbin and boot_elf
source ranges was built with `-mvu0-use-vf0-vf2`. This is a Sony patch-set option ("Specify the range of vu0
registers to use"). Besides making `$vf1..$vfN` allocatable for the `j` asm constraint, it adds N to
`n_non_fixed_regs`. In gcc 2.95.3 `loop.c` that number sets two thresholds:
- `scan_loop` hoists invariants when `threshold * savings * lifetime >= insn_count`, with
  `threshold = (call ? 1 : 2) * (1 + n_non_fixed_regs)` (loop.c:702, 1839).
- `strength_reduce` uses `(call ? 1 : 2) * (3 + n_non_fixed_regs)` (loop.c:3746, 4737).

So the option changes loop-invariant hoisting and giv reduction in functions with **no VU0 code at all**. RAC3
reports `func_003BAE98` at 122 differences without it and a match with vf2.
Sources: [RAC3 Toolchain and Build](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Toolchain-and-Build),
[Matching Patterns, "-mvu0-use-vf0-vfN"](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns),
docs/compiler_matrix_findings.md in that repo.

**Our compiler accepts it** (`ee-gcc2.95.3-136` cc1plus; `-mvu0-use-vf0-vf1` behaves like no flag).

**On our 434 nonmatching units:**

| N | exact matches | better fuzzy | worse | unchanged |
|---|---|---|---|---|
| 2 | **1** (`func_00165CB0`, 16 diffs → MATCH) | 3 | 5 | 426 |
| 8 | 0 | 6 | 24 | 404 |
| 31 | 0 | 5 | 54 | 375 |

Units whose result moves with N, with the number of differing words:

| Unit | none/1 | 2 | 3 | 4 | 6-16 | 20-31 |
|---|---|---|---|---|---|---|
| func_00165CB0 | 16 | **MATCH** | 16 | 16 | 22 | 22 |
| func_00230D88 | 218 | **21** | **21** | 54 | 214 | 214 |
| func_001A6CA0 | 80 | 80 | 80 | 80 | 80 | **2** |
| func_001F8C10 | 59 | 53 | 53 | 53 | 53 | 53 |

**Regressions on matched units** (all 1,701 matched units that contain a loop; all match at the pinned flags):
**18 stop matching at N=2**, spread across the image (0x10B768 ... 0x2B6368), and **80 at N=31**. Every matched loop
unit between 0x160000 and 0x16C000 (38 units, the neighbourhood of `func_00165CB0`) still matches at N=2.

**Interpretation.**
1. The flag is **not** a global setting for THUG: it breaks matched units that need "none" (for example,
   `func_0010B768` and `func_00152690` match with no flag or N=1 and break from N=2). If the original used it at all,
   it was per source file, as `-mno-split-addresses` was in RAC3. `func_00165CB0` is the test case, and its
   neighbours all tolerate vf2, so a per-file setting there is plausible but not proven. Neighbours without loops
   can't tell either way, because the option only reaches loop.c.
2. Whatever the original flags were, **the knob is a diagnostic oracle for loop.c**: when some N gives a match or a big
   drop, the residue is a hoist/strength-reduction threshold decision (`threshold × savings × lifetime` vs the
   loop's `insn_count`), not allocation. The C fix is then to change the loop's insn count, the invariant's lifetime
   or how many times it is set. This is the free equivalent of Boktai 3's patched-compiler `AGBCC_*` knobs for one
   pass, with no patched compiler. Levers that move this decision without a flag: §4.1.
3. The knob is non-monotonic (func_00230D88 is good at N=2-3, bad at 4, bad again from 6), so sweep N = 1..31, not
   just 2 and 31.

### 1.2 Single-flag sweep over the 434 nonmatching units

Flags gcc 2.95.3 accepts that are **not** in our `allowed_cflags`, each added alone to the pinned flags.

| Flag | exact matches | better | worse | biggest gains (differing words) |
|---|---|---|---|---|
| `-fforce-addr` | **3** | 22 | 158 | **001B4A08 78→MATCH, 001B9E98 65→MATCH, 001BD428 35→MATCH**; 002A12C0 149→35 |
| `-fno-cse-follow-jumps` | 0 | 6 | 78 | **00148D60 136→4**; 002957A0 39→12; 00258528 28→11 |
| `-fno-expensive-optimizations` | 0 | 13 | 169 | **00128BF0 98→7** |
| `-fno-force-mem` | 0 | 8 | 158 | 00230D88 218→21 (same unit as the VU0 knob) |
| `-fno-rerun-cse-after-loop` | 0 | 10 | 227 | small |
| `-fno-thread-jumps` | 0 | 3 | 18 | 00271560 13→11 |
| `-fno-regmove` | 0 | 1 | 25 | none |
| `-fno-caller-saves` | 0 | 0 | 7 | none |
| `-fno-delayed-branch` | 0 | 3 | 429 | none (confirms reorg is on) |
| `-fno-strict-aliasing`, `-fno-peephole`, `-fno-defer-pop` | 0 | 0 | 0 | **no effect at all**: strict aliasing is evidently off in this build, so SotC's per-file `-fno-strict-aliasing` (PS_GCC.md S4) cannot help us |

**The three `-fforce-addr` matches all sit in 0x1B4A08-0x1BD428.** A neighbour check (all 246 matched units in
0x1B0000-0x1C2000, compiled with `-fforce-addr`) found 21 that break, interleaved with the three: 1B4650, 1B47F8
and 1B4828 just before 1B4A08; 1B5150 after it; 1B99A0 and 1BA498 around 1B9E98; 1BDD78 after 1BD428. So it is
not one file-wide flag over that range. It is either three small source files, or (more likely) three functions
whose C still has a different address-forming shape that `-fforce-addr` happens to imitate (it copies each memory
address into a register before use). Read each of the three diffs with and without the flag: the instructions the
flag adds or moves are the shape the C must produce.

How to read it: a flag that turns a unit from 100+ differences into a handful (func_00148D60 with
`-fno-cse-follow-jumps`, func_00128BF0 with `-fno-expensive-optimizations`) names **the pass** that makes the
different decision, whether or not the original used the flag. RAC3 used the same reasoning: `-fno-force-mem` shows
up as commutative operand order (`addu rd, x, mem` instead of `addu rd, mem, x`) because `expand_binop` swaps
operands while the first is still a memory reference. It turned out to be a per-file flag on one RAC3 source
file, with five functions in that file needing a single-function override.

RAC3's rule for accepting a flag: it must leave every other function of the same source file matching. Check the
matched neighbours by address before believing a per-function flag
([Matching Patterns, flags section](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns)).

### 1.3 Negative result: identifier-allocation history does not change our code

gcc 2.95.3 `cse.c` hashes a `SYMBOL_REF` by the **address** of its name string (`canon_hash`, line 2189). In
principle the declarations seen earlier in the unit could therefore change cse's tie order (GT4 suspected this).
`gcse.c` hashes the name's **characters** instead (`hash_expr_1`, line 1375: "Don't hash on the symbol's address
to avoid bootstrap differences"), so gcse/PRE order depends on the symbol's spelling, not its address.
Test: 432 nonmatching units, each compiled with an unused forward declaration (1, 37 and 300-character names)
added at the top. **0 of 1,296 compiles changed a single word.** Don't spend time on declaration context or padding.
(The spelling dependence in gcse is real, but our symbol names are fixed `D_`/`func_` names and must have a
binary-backed reason, so it is not a lever.)

### 1.4 Negative result: Sony's unstripped ee-gcc 2.9-ee-991111 is not a usable proxy oracle

GT4's strongest late tool is a GDB "decision oracle" on Sony's **unstripped** Linux cc1plus (§3.1). Our SN
`cc1plus.exe` (and every 2.95.x PE build in `toolchain/compilers`) has **no symbol table**. The only unstripped
cc1plus near our version is `ee-gcc2.9-991111` (6,720 symbols, ELF). Compared on 144 random matched units (both
assembled with SN's as; prologue saves and nops ignored), its code equals SN 1.36's in **65 (45%)**, and in **83
(58%)** with `-fno-schedule-insns -fno-schedule-insns2` on both. It decides differently too often for its
decisions to transfer. A GDB oracle for us would need symbols recovered for SN's `cc1plus.exe` (§7, item 5).

---

## 2. Policy: what "done" meant for the projects that finished

**Boktai 3 (agbcc, 100% matched on 2026-11-02, then 93.4% "concession-free").** The project runs in four agreed
phases per subsystem: every function drafted, drafts matched (concessions such as pins allowed), concessions
removed, cleanup. A single detector tags every concession (pin, empty asm, raw-offset field access). The headline on
decomp.dev **counts only concession-free code**; a `concession-ok` escape hatch marks the accepted ones. PR #970
"the last 13 functions match; code matched 100%" was followed by weeks of PRs titled "concession removal".
[Boktai PR list](https://github.com/moozilla/boktai3-decomp/pulls?q=is%3Apr+is%3Aclosed),
[tools/scope/README.md "the brief"](https://github.com/moozilla/boktai3-decomp/blob/HEAD/tools/scope/README.md).
*Here?* Our `src/nonmatching/` + fuzzy score is the same two-number model (exact vs equivalent).
Boktai's "tag every concession with one detector" is worth copying if we ever allow a concession class.

**GT4 (ee-gcc 2.96 C++, 93.8% of functions).**
- `knowledge/deferred-to-last.md`: hand-written-looking functions and fragments that borrow the caller's registers are
  worked **last**, when their callers are known. For each, record what the compiler cannot emit (trapping `daddi`,
  hand-scheduled `movz` chains, `t5`-`t9` allocation).
- `knowledge/debt.md`: byte-exact matches that rely on something they would rather replace.
- A residue proven unreachable is written up as **"a decision for the maintainer"** with the pass and the condition.
  Example: a `REG_BR_PROB` note that no arm swap, negation, cast, `throw()` or profile moves.
- [deferred-to-last.md](https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/knowledge/deferred-to-last.md),
  [debt.md](https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/knowledge/debt.md).

**RAC3 (SN 1.36, like us).** "A function that only matches in localdecomp is not done until `make` matches too."
A **workaround audit** removed every pin, fence and `do {} while (0)` wrap one at a time, kept each removal that
still matched, then retried in groups. 216 of 398 workarounds turned out to be unnecessary, and 173 of 237 pins
pinned the register the allocator picks anyway.
[Matching Patterns, "Matching workarounds audit"](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns).
*Here?* We have no pins, but the same audit applies to our matched units' "required" temporaries,
statement-macro wraps and duplicated tails. It is cheap, and it improves the shapedb corpus (§6).

**RAC3 false-match lesson.** Their single-function checker masked every relocated field, so two `$gp` stores in the
wrong order looked identical. The fix: fill in relocations with the symbols' real addresses before comparing.
Rechecked on 617 matched blocks with no false failures. Our `match.py` already compares relocations
(`reloc_equal`), so this is only a reminder to keep that property in any new scorer.

---

## 3. Compiler-decision tooling that went beyond ours

### 3.1 GT4's GDB oracle on the vendor compiler (`tools/oracle.py`, `tools/oracle/orc_*.py`)
GDB stops Sony's unstripped cc1plus at each allocation, scheduling and delay-slot decision, records its inputs,
and can **force** decisions. It works by symbol name, so the same script runs on gcc 2.9 and 2.96.
- `trace`: local-alloc quantities in placement order, global's `find_reg` results.
- `slots`: every delay-slot fill with the reorg phase, thread and annul flag.
- `early`: a per-pass ledger from `-da` dumps: which pass made or deleted each extra insn, and its source line.
- `force` / `report`: the smallest set of allocation, scheduler and reorg decisions that turns the draft into the
  original.
- `climb`: a beam search over source rewrites, scored by named decisions moved instead of differing rows.

**Measured result (honest):** at an equal number of compiles, the decision score found **the same number of matches
as plain row-count climbing** (15 vs 15 on 137 drafts; then 2 vs 3, then 1). What it added was the per-decision
verdict: on 61 of 137 drafts some edit moved a named decision, and that list of "movers" is what a retry (agent or
human) starts from.
Source: [orc_climb.py docstring](https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/tools/oracle/orc_climb.py).
*Here?* Tool. Our `regalloc_explain`/`sched_explain` already give the "why" from dumps. Forcing needs symbols (§1.4).
**Takeaway: don't expect a smarter score to beat word count for finding matches; use it to tell the agent which edit
moved which decision.**

### 3.2 GT4's finishing pipeline order (`tools/finish_near.py`)
After every agent session a CPU-only pass runs over every kept near miss, in this order:
1. `sweep`: re-judge the closest draft under **every compiler profile**.
2. `context`: search subsets of callee prototypes declared `throw()`.
3. `rewrite`: one round of decl order, operand swaps, block wraps and adjacent swaps.
4. `permute`.

The per-region profile sweep (`profile_sweep.py`) is credited with **most October closures**: "Most closures
found by hand ... were a change of profile, not of code."
*Here?* The `throw()` context step is **N/A** while we build with `-fno-exceptions` (no EH regions for reorg to stop
at). The sweep step is §1.1/§1.2 above. Run it after each round of reworks, since a reworked draft can sit at a
different threshold.

### 3.3 RAC3 `asm_profile.py`: read the per-file mode off the retail bytes
It scores evidence for split vs no-split addresses and for the assembler per function (`lui` feeding two accesses
→ split; `lui $at` macro expansions → no-split). Its guess agrees with the flags of 97-98% of matched functions.
`try_func.py` builds with the guessed profile first. *Here?* Tool, if any per-file flag (`-mno-split-addresses`, a VU0
range) turns out to be real for THUG. With 8,762 matched units, the per-file runs can be drawn directly: for each
candidate flag, mark which matched units still match with it. A residue may take the flag only inside a run of
neighbours that tolerate it.

### 3.4 Boktai 3 `scope`: what-if knobs plus "why"
Principles worth copying for our explainers:
- Every knob that flips a decision must also print the C lines that feed it.
- Output follows progressive disclosure.
- "Every match leaves the toolkit better".

Two of its recorded ideas are directly buildable here:
- **Shape vs allocation split:** force the original's register assignment onto the draft's pre-allocation RTL. A
  match means only allocation is wrong; anything else means shape. Needs a forcing compiler, which we lack. The
  `-dl -dg` replay in `regalloc_explain.py` can approximate it.
- **Refactoring as an IDE operation:** extract a repeated shape into a header inline, rewrite all call sites,
  recompile every affected unit.

---

## 4. Source levers for the residue classes we have left (all gcc 2.95 pass behaviour, mostly from Boktai 3's
`scope` facts 39-113, which are newer than the copy PS_GCC.md cites)

Boktai's agbcc is gcc 2.95-derived. `jump.c`, `loop.c`, `cse.c`, `flow.c` and `stmt.c` are machine-independent, so these
carry over. Thumb-only details (r0-r7, STACK_REG) are left out. Source:
[tools/scope/README.md](https://github.com/moozilla/boktai3-decomp/blob/HEAD/tools/scope/README.md), "agbcc facts".

### 4.1 Loop hoisting / strength reduction (pairs with §1.1)
- **A union local's initializer keeps a load inside the loop** (fact 93). `union U u = {x};` expands to a `clobber`
  and then a set, so loop.c counts two sets and marks the pseudo `may_not_optimize`. It is never hoisted. A plain local
  with the same uses is hoisted when `threshold × savings × lifetime >= insns`. *OK only where the union type is real.*
- **Declare early, assign at the top of the loop body** (fact 82). A pointer declared inside the body is numbered after
  every function-scope local and loses priority ties. Declared with the other locals and assigned in the body, it is
  hoisted the same way and keeps the low pseudo number. *OK*
- **giv order follows insn order, reversed** (fact 112). `record_giv` prepends, and `combine_givs` breaks benefit ties
  toward the latest insn. A `T *p = &arr[i]` local at the loop top vs `arr[i]` at each use swaps the order of the
  reduced increments. *OK*
- **A loop at the start of an `else` arm keeps a separate else block through gcse** (fact 113). `mark_jump_label`
  stops at `NOTE_INSN_LOOP_BEG`, so LCM inserts into that empty block and loop.c hoists into it. A `goto` loop has no
  loop notes and gets PRE copies before the compare. *OK (both forms are real C).*
- **gcse moves a computation that follows an inner loop to before that loop** (fact 50); read the PRE dump before
  blaming loop.c.
- **`p++` at each `continue` adds refs to a hoisted stride constant** (fact 70). *OK*
- **Rotation: `expand_end_loop` moves everything up to the LAST `break` it finds (within 30 insns) to the bottom
  test; a `return` is not an exit** (fact 102). Writing late exits as `return` instead of `break` keeps the original's
  split. Only `break` loops can be reversed into count-down; a `goto` exit cannot (fact 40). *OK*

### 4.2 Cross-jumping and block placement (jump2)
- **Search order** (facts 39, 79): jump2 tries each jump against the code falling into its label first (one shared
  insn is enough), then the other jumps to that label, **last one first**. Two shared insns are needed, and a label in
  the jumping tail lowers the minimum by one. Plan the `return`s to place each merge. *OK*
- **Walls** (fact 39): a `return`, and a call that falls into a label, because flow puts a `(use (const_int 0))`
  after it, so its tail cannot share the call. *OK*
- **New labels are dead ends** (fact 101): a tail merged into code before a label gets a new label with no jump
  chain, so later tails never merge with it. A jump to an **existing user label** (`goto done`) does let them merge.
  One function went from 21 to 3 differences this way. *OK*
- **Merging happens after reload and flow** (facts 27, 59, 91): a tail written in every branch counts its refs,
  live length and reload choices in **each** copy before jump2 merges them. That makes "write the tail in each
  branch" a priority lever and a reload-rotation lever, with no trace in the output. Our guide has the allocation
  side. The reload-rotation side is new: when the first reload choice is missing, write the shared tail (as a
  `return f(...)` or a static inline call) at the end of each branch. *OK*
- **A cross-jump strips the kept copy's `REG_EQUAL` notes** unless the deleted copy has the identical rtx (fact
  111). Only small `const_int`s (-64..64) are shared, so later merges that relied on a constant note fail. *Diagnosis*
- **A test whose result is never used** in the original is an `if` whose two arms were identical after expansion
  and were merged (fact 57). Write the `if` with arms that differ only in type. *OK under our instruction test (the
  test's insns exist in the game).*
- **A copy that repeats a value survives only after a label** (fact 81): `delete_noop_moves` runs at the start of
  jump2 and stops at labels. Calling the function in both arms creates the label, then cross-jumping merges the calls.
  *OK*
- **Delay-slot annul via reorg's approximate liveness** (GT4 codegen map §8c): `mark_target_live_regs` starts at the
  previous BARRIER, and a `REG_DEAD` note only takes effect at the next CODE_LABEL. Separate early returns
  (`if (a) return 0; if (f()) return 0;`) put a jump+barrier before the next test and give plain branches. One
  `a || f()` gives the annulled `beql`. *OK.* [gcc296-codegen-map.md](https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/knowledge/gcc296-codegen-map.md)

### 4.3 CSE and constants
- **A multi-set variable whose first set is a constant has its live length doubled for good** (fact 80), even after
  the next set drops the equivalence. A count set to 1/2/3 in a `switch` before a down-counting loop is the typical
  case. Copying into a fresh loop counter (`i = count;`) removes it. *OK*
- **A constant kept in a callee-saved register for one use in a merged tail was written in every case** (fact 65):
  cse follows the switch's compare jumps into each case and reuses the test's constant pseudo. *OK*
- **cse puts an operand known to equal a constant second** in a commutative op (fact 87). *Diagnosis*
- **A dead constant load in the original can come from a use combine folded after flow** (fact 94). For us this
  usually passes the instruction test: the load is in the game.
- **A non-void function with no `return` keeps the return register live to the end** (fact 95). On MIPS that is
  `$v0`: flow sees it live from entry, so the body never allocates `$v0`. If a game function returns a value its
  callers ignore and never touches `$v0`, the original may have fallen off the end. *Careful: it is UB. Use it only
  when the binary shows exactly this.*

### 4.4 `-g` changes code in exactly one pattern (Boktai fact 40)
Under `-g`, a `break;` on its own line puts a line note between the exit test and `NOTE_INSN_LOOP_END`, which blocks
loop reversal. `if (c) break;` on one line does not. Among 10,094 matched agbcc units, `-g` changed no other code.
Our `diffmap.py` compiles with `-g` and asserts equal code for matched units. **For a nonmatching unit, a `-g`
build that differs (or matches!) tells you the loop's exit form is the residue.** *Diagnosis, free.*

### 4.5 Scheduler: interblock regions (N/A for us)
GT4 (2.96) found sched1 hoisting argument setup above a branch only while the function has ≤ 10 blocks / 100 insns
(`MAX_RGN_BLOCKS`), so an extra block changes the schedule. gcc 2.95's haifa has the same limits, but our
`sched_explain.py` notes that **this SN build schedules one block per region at -O2**, so the lever does not exist
here. Listed so nobody chases it.

---

## 5. Jump tables that land on the wrong address

Nothing in other projects is a direct fix: in every project a table that "lands wrong" turned out to be case
**layout**, a table **index base**, or a **wrong function boundary**.
- **Index base:** if the game's table starts at a lower case value than ours, the original listed those values
  explicitly as default-equivalent cases (`case 0: case 1: default:`, RAC3 `func_003B0FC8`). A `beq 1; slti 2` tree
  appears only when the switch also has `case 0:` (RAC3 batch notes). *OK*
- **Wrong function boundary:** GT4's `debt.md` lists three functions that "cannot link from source" because the
  inventory cut the function at the wrong place around its jump table. When the table's entries point outside our
  function, or into the next one, check `config/` boundaries before touching the C (tooling issue).
- **Layout:** body order = source order (in our guide). Boktai facts 39/79/101 (§4.2) explain which case tails merge,
  which moves every later case body and so every later table entry.
- RAC3 moved every jump table out of its data blob into per-function `INCLUDE_RODATA` lines
  (`tools/migrate_jtbls.py`), so a converted C switch emits its table in place. Our `cc.py` instead re-points to the
  game's table when the offsets agree, which is equivalent.

---

## 6. Automation that made a measurable difference

| Project | What | Measured |
|---|---|---|
| Snowboard Kids 2 (IDO, Claude) | Prioritise unmatched functions by **similarity to matched ones** (embeddings, then Coddog's bounded Levenshtein over opcodes) | "Highly effective"; match rate 25% → 58% → 75%, then a plateau. 85th percentile of successful attempts: 28; one took 87. **Permuter removed**: the agent treated permuter artefacts as signal and looped. `--repeat 3` helped only the extreme tail. [The long tail](https://blog.chrislewis.au/the-long-tail-of-llm-assisted-decompilation/), [Using coding agents](https://blog.chrislewis.au/using-coding-agents-to-decompile-nintendo-64-games/) |
| Mizuchi benchmark (agbcc + IDO, Claude Sonnet) | m2c → compile → objdiff → permuter → agent loop, 12 attempts | 74% average on 60 functions. Half the matches came on the first attempt; **after 3 failed attempts the chance of a match drops to about a quarter**. The agent could not run the diff itself and wrongly claimed matches. [Article](https://gambiconf.substack.com/p/can-llms-really-do-matching-decompilation), [mizuchi](https://github.com/macabeus/mizuchi) |
| GT4 | `swarm.py` workers + `attempt_store`/`retry_brief` (every draft kept, retries start from the closest) + `finish_near` CPU pass + oracle `climb` | 29,040/30,962 functions. The profile sweep closed most hand-found residues. Decision-scored climb = row-count climb in matches (§3.1) |
| Boktai 3 | Depin workers with `scope` facts; GPT/Opus rounds on "concession removal" | 100% matched with concessions; 93.4% concession-free after a week of removal rounds |
| RAC3 | Brute-force **statement order of a function's first few statements** and random-swap store order | Matched 2 + 2 functions that hand work had left; "Statement-order search pays off early" |

What this means for us:
1. Cap agent retries per function at about 3 before switching strategy (Mizuchi), and **always** let the agent run the
   real judge (they lost runs to false "matched" claims).
2. Feed agents the nearest matched units as context. Our shapedb is the same idea as Coddog, at block level. Keep
   matched units clean (Lewis): every cleanup improves retrieval.
3. Don't give an LLM loop raw permuter output as a goal. Give it the explainer's "which decision differs".

---

## 7. Ranked: the five most promising things to try

1. **Run the loop.c knob on every residue and act on it (1 day, Tool + OK edits).** Build `tools/loopknob.py`:
   compile a unit at `-mvu0-use-vf0-vfN` for N = 1..31 and report the best N and the loop the difference sits in
   (from the `.loop` dump: which movables or givs change). Results so far: `func_00165CB0` matches at N=2,
   `func_00230D88` drops from 218 to 21, `func_001A6CA0` from 80 to 2. For each hit, either find the C that moves the
   same threshold without the flag (§4.1: loop insn count, union initializer, two sets, `break` vs `return`, declare
   early), or, if the hit's matched neighbours all tolerate the flag, open a `tooling` issue to allow
   `-mvu0-use-vf0-vf2` per file with the neighbour evidence (RAC3's acceptance rule, §1.2).
2. **Pass-isolating flags as diagnostics, plus the three `-fforce-addr` matches (1 day, Tool + OK edits).** The
   §1.2 sweep matched 3 units outright with `-fforce-addr` (001B4A08, 001B9E98, 001BD428). It also collapsed
   residues with `-fno-cse-follow-jumps` (func_00148D60 136 → 4) and `-fno-expensive-optimizations` (func_00128BF0
   98 → 7). First, diff the three with and without the flag and find the C address shape it imitates. Propose the
   flag for `allowed_cflags` only if no plain C form exists, using RAC3's neighbour rule (21 of 246 neighbours break,
   so it is not file-wide). Second, give `diffmap`/`regalloc_explain` a `--knob` mode that runs these flags and the
   VU0 range and prints "the residue lives in pass X".
3. **A jump2/cross-jump explainer plus three cxxperm passes (2-3 days, Tool).** `-dJ` dumps the jump2 RTL (checked: our cc1plus writes `.jump`, `.jump2`, `.loop` and `.gcse` for `-dj -dJ -dL -dG`). List which
   tails merged into which and which label blocked a merge (Boktai's `AGBCC_CROSS_TRACE`, rebuilt from dumps). Add the
   passes: *tail into each branch* (facts 59/65/91), *`goto` an existing label instead of a duplicated assignment*
   (fact 101), and *`return` instead of a late `break`* (fact 102). Block placement and cross-jump choice is one of our
   five residue classes, and none of our current tools reads jump2.
4. **Keep the search score as is, but record "movers" (1 day, Tool).** GT4 measured that a decision-based score finds no
   more matches than word count. So keep `match.py`'s count for ranking, and have `cxxperm` log, per variant, which
   explainer-named decision it moved and what it broke. A rerun or an agent starts from that list. Pair it with a
   3-attempt cap per strategy for agent loops (Mizuchi) and nearest-matched-unit context from shapedb (Lewis).
5. **A real decision oracle for SN 1.36 (1-2 weeks, research).** Recover function symbols for SN's stripped
   `cc1plus.exe`. Match its functions against the unstripped `ee-gcc2.9-991111` cc1plus (same Cygnus/Sony lineage)
   and the public gcc 2.95.3 source (call graph + string references: `rank_for_schedule` and `find_reg` are easy
   anchors via their dump strings). Then drive it under wibo with GDB, as GT4's `orc_gdb.py` does by symbol name. That
   turns every residue into "which decisions differ, forced to the original's, does it match?", the one capability
   GT4 and Boktai had that we lack. An alternative path is Sony's GPL EE gcc patch set from the PS2 Linux Kit source
   RPMs (gcc 2.95.2 based), rebuilt with instrumentation. Its output would first have to be checked against SN on the
   8,762 matched units (§1.4 shows that even a close Sony build agrees on under 60%).

## Sources
- RAC3 wiki: [Toolchain and Build](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Toolchain-and-Build), [Tools](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Tools), [Matching Patterns](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns); repo `docs/compiler_matrix_findings.md`, `docs/permuter_todo.md`
- GT4: [knowledge/](https://github.com/gustavocanepa/gt4-decomp/tree/HEAD/knowledge) (`deferred-to-last.md`, `debt.md`, `gcc296-codegen-map.md`, `round-2-results.md`), [tools/oracle.py](https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/tools/oracle.py), `tools/oracle/orc_*.py`, `tools/finish_near.py`, `tools/profile_sweep.py`, `tools/tu_context.py`
- Boktai 3: [tools/scope/README.md](https://github.com/moozilla/boktai3-decomp/blob/HEAD/tools/scope/README.md) (facts 39-113, brief), PR #970-#1009
- SotC: [docs/findings.md](https://github.com/TheRealestNwah/sotc-decomp/blob/HEAD/docs/findings.md)
- Chris Lewis: [The Long Tail of LLM-Assisted Decompilation](https://blog.chrislewis.au/the-long-tail-of-llm-assisted-decompilation/), [Using Coding Agents to Decompile N64 Games](https://blog.chrislewis.au/using-coding-agents-to-decompile-nintendo-64-games/)
- Mizuchi: [Can LLMs Really Do Matching Decompilation?](https://gambiconf.substack.com/p/can-llms-really-do-matching-decompilation), [github.com/macabeus/mizuchi](https://github.com/macabeus/mizuchi)
- gcc 2.95.3 source (`gcc-mirror/gcc`, tag `releases/gcc-2.95.3`): loop.c (thresholds), cse.c `canon_hash`, gcse.c `hash_expr_1`, stmt.c `preserve_subexpressions_p`, haifa-sched.c `too_large`
- PS2 Linux Kit gcc sources (lead only): [tensioncore HOWTO](https://ps2-linux.tensioncore.com/docs/howto/display_docff02.html?docid=78)

## Measured: per-function compiler build (2026-11-13) — dead end

All 434 src/nonmatching units were compiled with every other EE build we have (2.95.3-114, 2.95.3-107,
2.95.2-274, 2.95.2-273a; without SN-only `-fopt-stack`). None matched. 11 had fewer differing words on another
build, but every one checked scored lower by fuzzy (func_00103000 95.6 -> 84.6, func_0020FD98 97.4 -> 75.7,
func_001D6800 98.9 -> 97.7 on 2.95.3-107): alignment artefacts. The game was built with SN 2.95.3 v1.36
throughout; the remaining differences are source shape and per-file flags, not the compiler build.
Script: work/csweep/one.sh (git-ignored).

## Measured residues (lane 1, 2026-11-13): diagnoses, no source lever yet

**Delay slot filled from the branch target instead of the fall-through** (func_00145DC0, func_00125418). The slot of
a predicted-not-taken equal-to-zero branch (REG_BR_PRED 0x11 in the `-dd` .dbr dump) is filled by reorg's
fill_eager_delay_slots: it tries the fall-through first unless a CODE_LABEL sits between the branch and the first
fall-through insn; then it copies the target's first insn into the slot and branches to target+4, as the game does.
Liveness at the target cannot block this when the target's first insn sets the register. An unused label is
deleted (no effect); a used label reproduces the target+4 branch but keeps the fall-through copy that the game
removed (likely redundant_insn), so the game's missing fall-through insn has to be matched too.

**gcse PRE merging a reload the game keeps** (func_00168F58). The `-dG` log line "PRE/HOIST: end of bb N ...
copying expression" names the hoist: `n+1`, used after an inlined padding while-loop, is hoisted into that loop's
preheader. Statement placement, `noreturn` and int/unsigned did not change it. Store aliasing (stores through
`qword*`/pointers the compiler cannot prove disjoint) is the general lever for keeping such reloads; it matched
func_0015EC60 and func_00148D60.
