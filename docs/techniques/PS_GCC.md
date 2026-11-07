# Fixing regalloc, scheduler and hoist ties under gcc 2.x: what other decomp projects do

Research catalogue, 2026-11-06. Scope: public decompilation projects on gcc 2.x-family compilers (PS2 ee-gcc
2.95/2.96, PS1 PsyQ gcc 2.6-2.8.1, GBA agbcc = gcc 2.95) and general tooling. No leaked source was opened.
Raw downloads used for this file are in `work/research/dl/` (git-ignored).

How much each source counts for us (our compiler is SN ee-gcc 2.95.3 build 1.36, C++ front end, -O2 -G8):

| Weight | Project | Compiler | Status |
|---|---|---|---|
| ★★★ | Ratchet & Clank 3 (rac3-uya-decomp) | **SN ee-gcc 2.95.3 v1.36** (same as ours), C | in progress, large wiki |
| ★★★ | Gran Turismo 4 (gt4-decomp) | Sony ee-gcc 2.96 (001003-1), **C++** | 97.9% of functions |
| ★★☆ | Shadow of the Colossus (sotc-decomp) | ee-gcc 2.96, C | 77% |
| ★★★ | Boktai 3 (boktai3-decomp) + its Yu-Gi-Oh! EDS catalogue | agbcc = **gcc 2.95** (ARM/Thumb) | in progress; read agbcc's source |
| ★★☆ | Parasite Eve 2 (parasite-eve-2-decomp) | PSX gcc 2.8.1 + maspsx | **complete** |
| ★★☆ | Legend of Mana (lom-decomp) | PSX gcc 2.7.2 (4 builds, 7 pipelines) | **complete** (NA + JP) |
| ★☆☆ | SotN (sotn-decomp) | gcc 2.6.3-psx + maspsx | many overlays complete |
| ★☆☆ | Paper Mario | KMC gcc 2.7.2/"2.8.1" | **100% (US)** |
| ★☆☆ | pokeemerald / pokefirered / pokeruby, tmc, fireemblem7u/8u, pmd-red | agbcc | 100% or near |
| ☆ | BFM-decomp | gcc 2.7.2 | in progress (wiki on the compiler source) |

Rule check for our repo: each entry has a **Here?** tag. **OK** = plain C++ allowed by RULES/scan.
**Careful** = allowed, but it must read as real code (no dead or steering statements). **No** = asm, pins or dead code,
which our gates reject. Several projects matched their last functions only with **No**-class tricks. Those are
listed so we know which wall they hit, not to copy them.

---

## 0. First, find the decision that differs (the process the best projects converged on)

The top gcc-2.x projects (Boktai 3, PE2, UYA, EDS) all made the same shift. Guessing at C spellings came to a
halt, so they started reading the compiler's dumps, finding the pass that made the different choice, and then
looking for the C that changes that choice. Their tools differ; the method is the same.

**P1. Dump `-dl -dg` (and `-da` for every pass) and grep the differing insn through the passes.**
Use `.lreg` for "Register N used X times across Y insns" and `.greg` for the global allocno order. A diff in an
insn that `.lreg` does not list (its number is above every `.lreg` insn) is a reload choice. The first pass where
your RTL differs from the shape you expect names the real problem: cse, gcse, loop, combine, lreg, greg, sched or dbr.
- Boktai 3 `passdiff.py` sorted 930 pinned functions by the first pass that differs. Only **21%** were pure
  allocation. The rest were cse/expand constant handling (27%), branch or jump threading (11%), order (10%),
  expression shape (10%), combine (6%), extension (4%), spill (4%), load reuse (3%) and hoist (1%).
  **So most "register swaps" are decided before the register allocator runs.**
- PE2 "Diagnostic ladder": a register diff → local quantities and suggestions → global conflicts and preferences
  → reload. An order diff → sched1/sched2 dependencies and priorities → dbr. A load present in `.greg` but
  replaced in `.sched2` → post-reload CSE (`reload_cse_regs`), not scheduling.
- Sources: https://github.com/moozilla/boktai3-decomp/blob/HEAD/docs/REGALLOC.md ,
  https://github.com/GabeRealB/parasite-eve-2-decomp/blob/HEAD/CODEGEN_MODEL.md (§10.5, ladder)

**P2. Compute the priorities by hand before editing.**
Global priority is `floor_log2(refs) * refs / live_length` (×10000 and truncated to an integer in 2.95; PE2 says
the 2.8.1 host build divides in floating point). An equal priority goes to the **lower pseudo number**, the value
created first. Local-alloc uses the same formula per quantity over half-insn positions. A quantity that has a
*suggested* hard register (a copy to or from `$aN`/`$v0`) is placed first, in that register.
- UYA ships `tools/regalloc.py`. Boktai 3 has `regdiag.py` and `regsolve.py`, which replays global-alloc in Python
  (95.7% of registers reproduced) and says "pseudo X must outrank Y by N uses". PE2 has `trace_gcc.py`, a GDB
  observer on cc1. tingle_tuner has a ranking printer.
- PE2 §10.7 worked one example to the number. Four swaps, each with a margin of 16 to 300 priority units, and
  each margin tells you which lever (one extra mention, operand order) closes it.

**P3. Instrument the compiler and solve in "compiler space" first, then search for C.**
Boktai 3 PR #214 notes that blind permuting stalls on register problems because the score is flat: a candidate
either swaps two registers or it does not. So they patched agbcc with knobs that change no output on their own
(`AGBCC_PRI`, `AGBCC_FORCE=N:R`, `AGBCC_PREF`, `AGBCC_SPILL`, `AGBCC_GCSE_T`). `rasolve.py` turns these knobs
until the bytes match and prints the answer in C terms ("`table` must outrank the two short temporaries", "one
more reload before line 90"). `translate.py` then enumerates source edits on those lines and ranks them by the
remaining gap, which gives a score with a slope.
- Our toolchain is a closed Windows SN build, so we cannot patch it. The same inverse solve can be done from
  `.lreg`/`.greg` numbers in Python, as their `regsolve.py` does.
- Source: https://github.com/moozilla/boktai3-decomp/pull/214

**P4. Fix the first differing block first.**
Reload hands out spill registers round-robin through the whole function, and local and global choices cascade.
A wrong block near the top shifts registers in every block below it. Fix the top, re-diff, and only then judge
what is still different lower down. (EDS "work top-down"; Boktai 3 `scope` fact 8.)

**P5. Check structure before registers.** God Hand, the BotW guidance and GT4 all say the same: a register-only
diff is usually a wrong *C structure* (wrong callee arity or return type, a missing parameter, an extra parameter
copy, a missing early return). Boktai 3's depin worker turned 28 of 60 pinned functions into clean C. Most pins
"only made up for an earlier mistake: a parameter copy (`T *x = input`), or a missing `return 0;` or early return".

**P6. Rewrite instead of tuning.** UYA's `func_003A3FB0` went from 46 differences to 0 with a clean rewrite after
long tuning of the old draft. GT4 notes that m2c's own temporaries and statement order are a frequent hidden
cause (GT4 "What m2c's drafts get wrong, counted").

---

## 1. Global-alloc ties (two callee-saved registers swapped)

**R1. Change the reference count: add or remove a real mention.** *Fixes: `$sN` swap.* *Here? OK*
Priority grows with refs. Several early `return ret;` statements in one branch each add a reference to `ret`. In
one PE2 case, rewriting a branch as nested `if`s dropped `ret` from 20 refs to 17 and flipped a pair with
identical instructions. EDS used `goto end;` to one `return flags;` to remove a use.
```c
/* before: ret has 20 refs */  if (a && b) return ret; ...
/* after: 17 refs, swap flips */ if (a) { if (b) return ret; } ...
```
https://github.com/GabeRealB/parasite-eve-2-decomp/blob/HEAD/CODEGEN_MODEL.md (§1, §10.6)

**R2. Change the live length: move the first set later or the last use earlier.** *Fixes: `$sN` swap.* *Here? OK*
GT4 (ee-gcc 2.96 C++): "To push a value to a higher `$s` register, end its live range later or give it fewer uses;
to pull it lower, assign it later (after the early-return checks) or use it more often." Saved-register order
follows priority, **not declaration order**.
```cpp
/* before */ Foo* f = m_foo; if (!x) return; if (!y) return; use(f);
/* after: f born later, shorter, higher priority */ if (!x) return; if (!y) return; Foo* f = m_foo; use(f);
```
https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/knowledge/ee-gcc-2.96.md ("Register allocation")

**R3. Refs inside loops count more: flow.c adds the loop depth to every reference.** *Fixes: `$sN` swap.*
*Here? OK if the loop is real; a bare `do{}while(0)` wrap is Careful/No*
A mention inside a loop weighs ×2, and one in a nested loop ×3 (PE2 table). Moving one use into or out of a loop
moves priority a long way. Boktai 3 and UYA reached this lever with empty `do { } while (0)` wraps: four nested
wraps around `table = gUnk;` raised a table pointer above two constants. Boktai rewrites each such wrap as the
statement macro it probably was (`DEBUG_NOP()`). Under our "no steering code" rule, only a wrap that is plausibly a
real macro body would pass. Treat this as a diagnostic: it tells you which value needs more weight, and then you
look for real code that adds it.
https://github.com/moozilla/boktai3-decomp/blob/HEAD/docs/REGALLOC.md ("Loop depth weights uses")

**R4. Split one variable into two, or merge two into one.** *Fixes: `$sN` swap, and a value moving between local and
global allocation.* *Here? OK*
One C variable reused for two roles is one pseudo. A global allocno sums the refs and takes the longest member
length. UYA: one shared `i` used by two loops swapped `$s0`/`$s1`, and separate counters fixed it. Block-local
temporaries instead of one function-level `s32 t` took a diff from 544 to 278. GT4 found the reverse: reusing one
`int value` for two unrelated values broke an exact priority tie (`func_004F2308`).
```c
/* before */ int i; for (i=0;i<n;i++) a(); for (i=0;i<m;i++) b();
/* after  */ for (int i=0;i<n;i++) a(); for (int j=0;j<m;j++) b();
```
UYA wiki "Register allocation"; GT4 "Floats" (reuse case)

**R5. Declaration order only breaks exact ties (pseudo number).** *Fixes: an exact tie.* *Here? OK*
Every source agrees on the limits. UYA says declaration order "only breaks ties between equal priorities". PE2
tested swapping `int a, b;` and got identical code, while swapping the two statements that *load* them flipped
the registers, because that changed the live lengths. EDS: equal truncated priorities go to the lower pseudo, so
declaring `zoneOfs` before `z` won a tie. In C++ (GT4) the order of first use or assignment matters more than the
textual declaration. Try declaration order only when `.greg` shows equal priorities.
https://github.com/GabeRealB/parasite-eve-2-decomp/blob/HEAD/CODEGEN_MODEL.md (§10.6 "Folklore, tested")

**R6. Constants and address constants enter allocation at half priority (REG_EQUIV doubling).** *Fixes: a table
pointer or mask losing its `$s` register.* *Here? OK*
`update_equiv_regs` (local-alloc.c) doubles `REG_LIVE_LENGTH` for a register whose single set is a constant (a
number or a symbol address): once per constant set, so a pseudo set twice to the constant gets 4×. The doubling also
applies when the *first* set is a constant even if later sets are not. Levers:
- Make the first set a load instead (reuse a variable) (EDS `SendBattleDestroyedCardToGraveyard`).
- Copy a parameter into a local to drop the doubling (PE2 `_actor105100Death`).
- A constant born at function entry has the longest life and the lowest priority. It may get no register and be
  rematerialised at each use, which can be exactly what the original did.
https://github.com/moozilla/boktai3-decomp/blob/HEAD/tools/scope/README.md (fact 10), EDS catalogue (§ allocation)

**R7. Where the value dies decides local vs global allocation.** *Fixes: a value in `$v1` vs `$sN`, or a temporary
taking a pool it should not.* *Here? OK*
A pseudo used in only one basic block goes to local-alloc. Give it a use in a second block and it becomes global,
which frees local registers for others, and the reverse also holds. EDS and Boktai: a function-scope pointer
shared by two `if` arms (instead of one per arm) moved it to global allocation and freed the register the original
used. PE2: "a local shared by two copies of a duplicated tail becomes a global pseudo, and that is what frees a
call-saved register". UYA `func_003D2878`: declare the temporary block-local in each arm so it inherits the
register of the input that dies into it.
https://github.com/GabeRealB/parasite-eve-2-decomp/blob/HEAD/DECOMPILATION_LEARNINGS.md

**R8. Calls crossed, and the refs vs 4×calls threshold.** *Fixes: callee-saved count off by one, or a spill vs `$s`
choice.* *Here? OK*
In 2.8.1/2.95 a value crossing calls is spilled rather than caller-saved when `refs <= 4 * calls_crossed` (PE2
§10.7). One more reference can turn a spilled value into a register value. GT4 (2.96 C++):
- **Callee-saved count too high**: you cache a pointer or field across a call that the original reloaded. Write the
  member access again after the call.
- **Count too low**: the original computed the value before the call and kept it live across.
- Two virtual calls through `this->p` reload `this->p` after the first call. m2c's hoisted temporary is wrong there.

**R9. Pass a value straight through a hard register (copy preferences).** *Fixes: a parameter leaving `$aN`, or a result
leaving `$v0`.* *Here? OK*
A value returned unchanged or passed as an argument unchanged keeps `$v0`/`$aN` if the register is free over its
range (PE2 §10.6). UYA: reuse the parameter itself as the working pointer (`a0 = ...; a0[0] = ...`) so it stays in
`$a0`; a fresh local lands in `$v1`. Boktai 3: `x = Helper(x, z)` (the inline result written back into its argument
variable) makes x, the parameter and the result one pseudo. The reverse also holds: a needless `T *x = input;` copy
is the most common hidden cause (Boktai depin note 1; pokeemerald `MoveItemSlotInList` removed "dumb assignments
needed to match" `itemSlots = itemSlots_`).

**R10. Preferences spread along value chains: the operand order of the last op decides who inherits.** *Fixes: `$s`/`$t`
swap at a multiply or add.* *Here? OK*
`expand_preferences` (global.c) merges preferences along each "dies here / set here" insn. The REG_DEAD note order
decides who receives a preference, and flow writes the notes in operand order. `radius * table` instead of
`table * radius` changed which value got `$r3`. This only works when neither operand is a constant, because
`expand_binop` puts a constant second.
https://github.com/moozilla/boktai3-decomp/blob/HEAD/tools/scope/README.md (fact 11)

**R11. Tied operands: `k = C; k *= t;` vs `k = C * t`.** *Fixes: local swaps around two-operand ops.* *Here? OK*
`combine_regs` (local-alloc) ties an output to operand 1 when the input dies there. Writing the result as a
compound update of one variable ties it. UYA `func_003A73A0`. Same idea for a division: assign the constant to the
result variable first (`k = 0.026f; k = D.f48 / k;`) and the quotient is computed in its register. Boktai fact 12:
`x = t % 512;` computes the quotient in `x` (`expand_divmod` reuses the destination), while the same `%` inside an
expression gets a fresh register.

**R12. When the swap is two loads in one block, the first operand of the op that kills both owns the chain.**
*Fixes: `$v0`/`$v1` between two loads.* *Here? OK*
PE2 §10.7: `lbu` result as operand 1 tied the 7-insn chain to it. Write the `lw` value as the first operand
instead (`w + b`, not `b + w`).

---

## 2. Local-alloc and `$v0`/`$v1`/`$aN` ties

**V1. Give every callee its real return type, even when the result is ignored.** *Fixes: `$v0`→`$v1` shift right
after a call, `$a0`/`$a1` order in a `jal` delay slot.* *Here? OK (already in our MATCHING_GUIDE)*
Confirmed independently by UYA, GT4 and SotC. A `void` vs `int` callee changes whether `$v0` is live after the call,
so local-alloc skips `$v0` for the next temporary. GT4 matched `func_00335248` (624 B) with this after a 4-minute
permuter run had failed. tmc removed a fakematch by giving the callee its true 64-bit return
(`union SplitDWord`; `GetFuserIdAndFuserTextId`).

**V2. Check callee arity and pass-through arguments.** *Fixes: "dead" argument registers and unexplained copies.*
*Here? OK*
GT4: m2c drops a passed-through `this` or leading arguments (`func_002638E0(0)` is really `(arg0, arg1, 0)`).
EDS: a hidden live real parameter in r1 shifted every later reload. Boktai: "an argument register kept alive
across a call ... usually means the callee takes more parameters". Also K&R zero-argument declarations leave `$a0`
untouched (UYA).

**V3. Argument order and float position in prototypes.** *Fixes: the order of the last arg moves before `jal`.*
*Here? OK*
Integer and float argument registers are assigned separately under EABI, so a float's place in the list changes only
the *move order*. GT4: "original `mov.s $f12` before `daddu $t2` = the float comes before that integer argument".
UYA swept 35 interleavings for `func_003A0EB0`, and one matched. Arguments expand right to left in g++, so a nested call
in a later argument runs after the earlier arguments' addresses are built. Compute it into a local first to reorder.

**V4. A constant in the wrong one of `$v0`/`$v1` against a load: route the constant through an inline parameter.**
*Fixes: local swap, constant vs load.* *Here? OK (static inline helper)*
GT4 `0055C398`: sched1 hoisted the constant so it outlived the load. A `static inline set_(2, mask, ...)` taking the
constant as a parameter changed the pseudo lengths, and the function went from 8 differences to a match. It did not
work on a sibling where both values were loads.

**V5. Value-first temporaries / load-before-constant.** *Fixes: `li` and `lw` order and their registers.* *Here? OK*
Boktai `sub_08172AF4`: `f(s, *p <= 7 ? 0 : 1)` emitted the load after the constant. With `u8 v = *p; u32 r = 1; if (v <=
7) r = 0; f(s, r);` it matched. GT4 says the same for compare flags: `int first = p->n == 0; p->n++;` keeps the
`sltiu` before the store.

**V6. Copies that CSE deletes: a needed `move` exists only if there is a join or a later use of the old value.**
*Fixes: missing `daddu x, y, $zero`.* *Here? OK*
GT4: "A copy `t = param;` never survives inside one straight block (CSE merges the two). A retail `move` ... needs a
join in between or a later use of the older value." PE2: naming one `memCalloc` result twice is how the target keeps
it in both `$v0` and `$a0`.

**V7. Fewer than four local quantities: agbcc's sort compares quantity numbers.** *Fixes: exotic local ties.* *Here?
OK (diagnosis only)*
EDS found that with exactly three local quantities the sort compares qty numbers instead of qty_order. This is a
2.95 local-alloc quirk worth knowing when a three-temporary leaf will not follow the priority formula.

**V8. `bool`/narrow types change which register a test uses.** *Here? OK*
GT4: byte tests in `$v1` across a whole draft while the original tests in `$v0` meant the draft was compiled as C and
the game as C++. Same body in a `.cpp` file: 31 → 25 differences, all byte tests fixed. For us everything is already
C++, but **the permuter's C copy** of a unit can show this artifact, so recheck permuter wins in the real unit.

---

## 3. Scheduling (instruction order inside a block, store order)

**S1. Know the sched1 tie-breakers.** *Fixes: order of independent loads and stores.* *Here? OK*
`rank_for_schedule`: priority (critical path, weighted by latency), then the relationship to the last scheduled
insn, then **original RTL order**. Scheduling runs backward. UYA: sched1 prefers the insn that **ends a register's
life**, then the one with **more dependents**. PE2 adds `schedule_select`'s `potential_hazard` weighting, which can pick
a lower-ranked insn. Moving a load or store in the C changes the order only when it changes the dependence graph, a
lifetime or the tie order.
https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns (Scheduling) ; PE2 CODEGEN_MODEL §2

**S2. Rotated store runs: the original's first store is your last.** *Fixes: store order.* *Here? OK (in our guide)*
UYA: "For retail's order A, B, C, D, write B, C, D, A". GT4 says the same for zero-store runs. GT4: constructor
bodies match when written vtable first, then fields by ascending offset. If not, permute the run
(`perm.py` tries every order).

**S3. Loads cannot pass a store through a different pointer: statement order is fixed there.** *Fixes: a load at the
wrong end of a store run.* *Here? OK*
PE2: `sched_analyze_1` makes each store depend on every pending load (and the reverse) unless `base_alias_check` can
prove the bases distinct, which it cannot for two plain pseudos. So "a load written after a run of stores cannot be
scheduled before them". Two stores off **one** base are independent of each other (constant-offset check), so their
emitted order says nothing about source order. Read the load's side.

**S4. Types decide aliasing, and aliasing decides which accesses may swap.** *Fixes: adjacent load/store swapped, a
global reload present or missing.* *Here? OK*
GT4: "A load can move above a store only if their types cannot alias (int vs float vs pointer vs struct). Use the
data's real type." Declare read-only tables `const` to remove false dependences. A global reloaded after a store
through a pointer means the store's type may alias it, so try a typed struct field. UYA: a load through a cast
`s32 *` keeps stores to plain globals after it, while struct-member loads do not conflict with fixed scalar globals.
SotC matched several functions only with **`-fno-strict-aliasing`** per file. That flag is **not in our allowed
cflags list**; if several of our near misses look like this, it is worth a `tooling` issue.

**S5. Variables that cross calls are hoisted by sched1, new variables after the call are not.** *Fixes: a computation
before vs after a `jal`.* *Here? OK*
UYA `func_003869E8`: a variable that doesn't cross a call keeps its computation after the call. GT4: sched1 moves
pseudo copies across calls freely. PE2: a named loop-invariant hoists before a preceding `jal`, while a literal
rematerialises in the delay slot.

**S6. Separate variables for identical constants.** *Fixes: an `li` outranking other insns.* *Here? Careful*
UYA `func_003D1D40`: `k1 = 0x98; k2 = 0x98;` stays two pseudos, so each `li` has one dependent and no longer outranks
the rest. This is justified where the original code plausibly had two named constants (two `#define`s or arguments).

**S7. A `do { ... } while (0)` block (a statement macro) is a sched1 barrier.** *Fixes: constants or copies hoisted
across stores or calls.* *Here? Careful (only as a plausible macro body)*
GT4: "Constants built only after earlier stores, never hoisted above them = the later statements sit in a
`do { ... } while (0)` block, a packet macro's body. Its loop notes make the block's first insn a sched1 barrier"
(5 functions 12-26 off → match). It also keeps a copy below a call. It also limits CSE (UYA), so a shared `%hi` may be
recomputed. Side effect: it raises reference weights (R3) and can add `.p2align` padding. PE2 measured both effects.
Ask "is this a SDK or engine macro?" before using it.

**S8. Chained and staged assignments fix order.** *Here? OK*
- `a = b = f();` vs `b = v; a = b;` gives opposite store order (UYA, GT4).
- `size = a + b; size += c;` keeps each add in order, where one long sum gets reassociated (GT4, UYA
  `t = off + 1; off = (key & 1) + t;`).
- `(w + 8) * 16` folds to `w*16 + 128`; keep `t = w + 8` as its own local if the original adds first (GT4).
- `tbp = t->w0; tbp = (g->x34 + tbp * 4) >> 8;` (a variable set twice) differs from the one-expression form and
  took UYA `func_00394368` from 176 to 30 differences.

**S9. Store first, then test.** *Fixes: a store in or out of a branch delay slot.* *Here? OK*
UYA: `p->f74 = t; if (...) ...` puts the store in the delay slot where an if/else form does not. GT4: "reading a field
into a local before an unrelated store lets that store fill a later `jal` slot". "A load in the first branch slot after
a call = a local read written right after the call".

**S10. A store fed by a `lui/ori` constant issues early whatever its position.** *Here? OK (saves time)*
GT4: reorder only the cheap stores. The store in the `jr $ra` slot is the scheduler's leftover, not necessarily the
last C line.

**S11. FPR numbers in a call-free block come from latency, not names.** *Here? OK (saves time)*
GT4: only a change in expression shape changes them. Our guide's "float register choice follows declaration order"
holds where floats are user locals that live across blocks.

**S12. `-fno-schedule-insns` is a diagnostic, rarely a fix.** UYA: 0 of 44 near misses matched with it, most got worse.
We already use it only as a diagnostic.

**S13. Scheduling-only residues that no source order reaches.** PE2: `potential_hazard` and `unit_n_insns` are
whole-block properties. One extra memory insn far away (for example, a duplicated tail kept until cross-jumping)
changes the selection. They solved one case by duplicating coordinate updates in both arms, which is real code.

---

## 4. Delay slots and branch-likely

**D1. Invert the condition / swap the `if` arms.** *Fixes: `beq`↔`bne`, plain vs likely, which arm falls through.*
*Here? OK*
Paper Mario: "If you encounter likely instructions ... try inverting the condition". GT4: the tested polarity follows
the first-written arm. `if (x < 0) { d = -1; x = -x; } else d = 1;` gives `bgezl; li`, while testing `x >= 0` first
gives plain `bgez`. A ternary or `if` whose arm *reads memory* never becomes `movn`; it stays branch-likely with the arm
in the slot.
https://github.com/pmret/papermario/wiki/GCC-2.8.1-Tips-and-Tricks

**D2. `throw()` on callees changes branch-likely (C++ only).** *Fixes: a likely bit differing next to a call.*
*Here? OK (C++ exception spec, no asm)*
GT4 (ee-gcc 2.96 **C++**): "A branch-likely where the original has a plain branch with the same slot ... declare the
callees `throw()` (a destructor too). Without it reorg sees the register live on the fall-through path and annuls the
slot. One `throw()` on the call right after the branch was enough." It works the other way as well: `00559808` needed
`throw()` to *get* retail's `bnel`. Whenever the only difference is a branch's likely bit, try `throw()` on each nearby
callee. g++ 2.95 has the same EH/reorg interaction, so **this is directly worth testing on our C++ units.** It needs
`-fexceptions`-style EH regions to matter; check whether our build has them.

**D3. Early return vs result variable vs separate `return 1;` per site.** *Fixes: `daddu $v0,$zero,$zero` in a slot,
duplicated `li $v0,1`.* *Here? OK*
GT4: `daddu $v0,$zero,$zero` in a branch slot = an early `return 0;` at that site, while a `result = 0;` local at the top
gives a hoisted zero. Separate `return 1;` exits keep one `li` per site, and one merged return removes them. Boktai and
UYA: a single `return r` sometimes matches, and early returns sometimes let gcc fold `r` to a constant and free its
register.

**D4. Write a shared call in each arm, or once.** *Fixes: argument in a slot, cross-jump layout.* *Here? OK*
GT4: one shared `jal` whose argument is set in a branch slot = both arms written out in full (`if (c) { f(1); return 1; }
f(0); return 1;`). An instruction duplicated at the end of both arms is reorg filling a slot from the join, so write it
once after the if/else (UYA). A store duplicated in both arms (`jr; sh` twice) is written in each arm (GT4).

**D5. The loop-init expression order fills the guard slot.** *Here? OK*
GT4: `for (j = 0, p = base; ...)` vs `for (p = base, j = 0; ...)`: reorg fills the slot with the insn right before
the test. A separate `pos = c->pos;` before the loop puts `i = 0` in the slot instead.

**D6. A `volatile` access is never moved into a slot.** *Here? Careful (only real hardware or shared state)*
UYA, GT4 and SotC agree. GT4 has the converse: to *allow* a single store into a `beql` slot inside a volatile struct,
write that one store through a non-volatile cast.

**D7. A `nop` in a `jal` slot is the tell for a cross-jump head or a local data symbol.** PE2: a `nop` in a `jal` delay
slot marks the call block as a cross-jump head. Paper Mario: `lui/addiu` before `jal` and `nop` in the slot (instead of
`addiu` in the slot) usually means the symbol is `.data`/`.rodata` *of this file* rather than extern. Our units cannot
own data, so park these.

**D8. Selector type sets the branch layout.** UYA `func_003B8440`: an `s32` selector gives `beq` with the
then-assignment in the slot, while a `u8` selector gives `bne`/`b`. GT4: `bne` vs `bnel` before a call can depend on
whether the callee is defined earlier in the same file. With one function per file, park such residues.

---

## 5. GCSE / loop-hoist order and loop-invariant registers

**H1. Order of hoisted addresses = expression first-appearance / PRE hash-bucket order.** *Fixes: two hoisted `lui/addiu`
in swapped `$s` registers, spill-slot order of hoisted pseudos.* *Here? OK (diagnosis); levers below*
UYA and Boktai: PRE insertion order is expression index order, and PRE reaching registers are numbered in hash-bucket
order `(13259 + C) mod N` (for `(plus fp C)`), where `N = (insns after cse1 / 2) | 1`, read from the `-dG` dump.
**N depends on the size of the whole function**, so a change anywhere can reorder the hoists. Each extra loop with a
variable bound adds about 2 to N. UYA `func_003B3558` needed N = 215. Our guide already notes "hash of the symbol name
for ties". This formula turns it into a computable target.
https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns ("Hoisting")

**H2. A local pointer vs a member access in the loop.** *Fixes: hoisted copies, extra `daddu` copy of a base.* *Here? OK*
UYA: `o->an[o->idx][i]` hoists `o + 0x38C`, and a local pointer (`an = o->an`) removes the copy. GT4: a base copied to a
second register before a loop = loop.c hoisted an address the source computes *inside* the loop, so index the member
directly instead of a pointer made before the loop. SotC: `char *g = gcGlobalVar;` declared **inside** the loop body
keeps the full address in an `$s` register.

**H3. Indexed `for` vs walking pointer, and where the increment sits.** *Fixes: induction-register assignment, init
order before the loop.* *Here? OK*
Boktai rule: loop.c inserts hoisted invariants first, then strength-reduction inits (pointer, count-down). A
hand-written pointer loop puts its inits before the loop start, so the hoisted constant comes *after* them. If the ROM
materialises the constant first, write an indexed `for` and let loop.c make the pointer. UYA: `for (i...; i++, list++)`
(two increments) matched where a single induction variable did not. Paper Mario: negative struct offsets in a loop
come from `for (i = 1; i < n; i++, p++)`. GT4: index (`p[i]`) vs cursor (`*p++`) swaps the saved registers of cursor and
index.

**H4. Loop constants as named locals, in the original's order.** *Fixes: the `li` order before a loop, which constant gets
`$sN`.* *Here? OK*
UYA: gcc hoists loop-invariant constants between the inits, so put them in locals assigned in retail's order
(`i = 0; three = 3;`). `s32 one = 1;` before the loop keeps 1 in a saved register (`func_003947B0`). PE2: "Literal
`1` hoists into `$s1` among `%hi` `lui`s; a named `one` does not."

**H5. A second set of a variable keeps it in the loop (loop.c will not hoist a multiply-set pseudo).** *Fixes: an `li` the
original re-executes in the loop, a count-down vs count-up loop.* *Here? Careful (the second set must be real)*
GT4 `003D25B0`: to get a register-bound count-down (`li N; addiu k,-1; bnez`) the bound must be a register with two
sets (`c = N` before the loop and again in the body). gcse CONST-PROP otherwise folds N into the `slt`. Boktai depin 10
replaced an asm barrier this way. UYA `func_003B23F8`. Under our rules a redundant `c = N;` is a steering statement,
so this is legal only when the value genuinely changes or is re-read.

**H6. A variable loop bound stops PRE hoisting.** UYA `func_003B3558`: `s32 nF = 5; ... i < nF` stops PRE moving an
array address above the loop. cprop folds the bound later, so the loop code is unchanged. *Here? Careful*

**H7. gcse propagates float constants across blocks but not within a block.** UYA `func_003AF2C0`: assign the constant
inside the loop, in the same basic block as its use, and loop.c hoists it to the preheader once instead of gcse
copying it into each call's arguments. *Here? OK*

**H8. Hide an address from gcse by building it in two statements.** Boktai `sub_08000430`:
`off = (u8 *)&sym + k; base = (s16 *)(off - k);`. gcse hashes `SET_SRC` and never sees `sym`; combine folds it back.
*Here? Careful (looks contrived; last resort)*

**H9. Read the global again instead of caching it, or the reverse.** *Fixes: an `%hi` held in `$sN` vs rematerialised.*
*Here? OK*
GT4: `T *w = &D_X;` once = an `lui/addiu` pair held in `$s`, while direct `D_X.field` at each site rematerialises it.
PE2: "Read the global back instead of caching it, so its `%hi` hoists"; "Hoist `&Global` into a saved register with a
local pointer". A `lui` shared but `%lo` recomputed after a join = a second use through a pointer local.

**H10. `-fno-rerun-loop-opt`, `-fno-gcse` per file.** UYA kept an up-counting loop with `-fno-rerun-loop-opt` on one
function. GT4 has an `ee-gcc2.96-nogcse` profile for a few library-like functions with no loop optimisation. Our
allowed list has `-fno-strength-reduce` but neither of these. If a cluster of near misses needs one, that is a
`tooling` issue with evidence, not a unit change.

---

## 6. Spill-slot and stack-slot order

**K1. A scalar gets its slot when `&x` is first seen, an array at its declaration.** *Fixes: stack offsets of locals.*
*Here? OK*
UYA `func_003C0188`: one `u8 cc[2]` array declared first put the bytes at retail's offsets. Block-local arrays get
separate slots; retail shares slots between cases or loops, so declare such buffers once at the top
(`func_003DCD08`). BFM (gcc 2.7.2): "spill-slot order follows declaration order, not first-assignment order". PE2:
"declaration order picks the spill slot".

**K2. Spill-slot order of PRE pseudos follows gcse buckets (see H1).** UYA changed the bucket count with loop-bound form
without changing instructions. Float arguments written as integer bit patterns changed N (`func_003A8230` needed 589).

**K3. Reload rotation: one reload more or fewer earlier shifts every later reload register.** *Fixes: a reload or
temporary register one off.* *Here? OK (diagnosis)*
`allocate_reload_reg` hands out spill registers round-robin from `last_spill_reg`, reset per function. On MIPS this
matters less than on Thumb (more registers, fewer reloads), but large constant offsets, `$at` expansions and stack
accesses still go through reload. The EDS and Boktai levers (literal address vs symbol, hidden parameter) carry over as
diagnosis.

---

## 7. Types, casts, literals

**T1. Width and signedness of locals and parameters.** *Here? OK*
- An `s8`/`u8`/`s16` parameter is masked or sign-extended on entry: declare it `s32` if retail has no mask (UYA, GT4,
  Boktai).
- `s32 v = (u8)field;` before `v == 1 || v == 2` drops an `andi` (GT4).
- `u32 info` instead of `u16` drops a zero extension and shortens a live length enough to flip a tie (EDS).
- Refs and live lengths are counted **before combine**, so insns combine deletes later (extensions of narrow locals)
  still count. Changing a `u8` local to `int` can flip a tie with no instruction change.

**T2. `long` working variables keep `movz` chains** where `int` folds into `xor`/`sltu` (UYA). `long` is 64-bit on EE.

**T3. Comparison constants: `>` vs `>=`.** SotN: devs wrote `foo > 0x28`. Writing `>= 0x29` gives the same semantics
but a different register (`$at` vs `$v1`). Try both spellings of the boundary. *Here? OK*
https://github.com/Xeeynamo/sotn-decomp/wiki/Register-Mismatch-Decompilation-Tricks

**T4. `%`/`/` instead of hand-written masks and shifts.** SotN: an `andi`+sign-check+subtract is `foo % 0x80`.
pokeemerald "Fix fakematchings regarding modulo" did the same. UYA:
`(x > -1 ? x : x + 0xFF) >> 8 << 8` is `(x / 256) * 256`. *Here? OK*

**T5. Boolean returns: `if (r < 0) return 0; return 1;` vs `return r >= 0;`** give different code (UYA, GT4, our guide).

**T6. Pointer arithmetic form controls `addu` operand order.** `p->arr[i]` (base first) vs byte arithmetic `p + i*4`
(index first); a separate `E *e = p->arr + i;` statement lands the sum in the base's register (GT4: 11 functions).
Already in our guide; GT4 adds the "separate element-pointer statement" variant.

**T7. Float literals: spell enough digits.** cc1 2.9x truncates decimal literals. Use the digits that hit the bits
(SotC, GT4). Already in our guide.

---

## 8. Inline wrappers (the main legal tool for "impossible" shapes)

**I1. An inline helper's parameter order sets the copy schedule and register.** UYA `func_003EB728`: integrate.c
copies each formal in order. Boktai depin 7: `Wrap(size, p) { Fn(p, size); }` changed which temporary gets the low
register and replaced r0 pins. *Here? OK (static inline, used consistently)*

**I2. Inline getters and accessors materialise a base or stop folding.** SotC `st_defaultAI`: a static inline getter
returning `&gcGlobalVar` keeps a materialised base. Direct access folds the address, 22 vs 24 words. PE2: a constant
address folds into the memory operand **only** inside an inlined body. Our guide's `GetSize()` and `Elapsed()` are the
same family. *Here? OK*

**I3. Inline helpers cut CSE.** EDS: routing one lookup through an inline helper ends CSE's block at the helper's folded
branches, so two lookups no longer share a constant. *Here? OK*

**I4. Pass-through reference helpers create stack homes.** GT4: `static inline const int &ref(const int &x)` around uses
gives the `sw $a1, 0($sp)` slots of the original (our guide notes the `const T&` effect). *Here? OK*

---

## 9. The `register` keyword, `volatile` and other folklore

**F1. Plain `register` (no asm) does nothing at -O2 in gcc 2.x.** PE2 tested it on gcc 2.8.1: "**`register`** does not
steer allocation at `-O` (`obey_regdecls` is cleared)". In 2.95 the flag is set only at -O0, so the keyword has no
priority effect at -O2. The other effect is that `&x` on a register variable is an error. UYA shows a `register u128_t z
= 0;` compiling to ordinary `por`/`sq`. Not worth trying. (Any effect seen is through a side change, not the keyword.)
https://github.com/GabeRealB/parasite-eve-2-decomp/blob/HEAD/CODEGEN_MODEL.md (§10.6)

**F2. Renaming and unused locals do nothing.** flow deletes an unused local before either allocator runs (PE2).

**F3. Explicit `register T x asm("$s1")` pins** move diffs but often hide a structural error. Boktai's `unpin.py` found
173 of 237 UYA pins and dozens of its own redundant once the source was right. God Hand hard-fails any pin.
*Here? No*

**F4. `volatile`** keeps an access in place and out of delay slots. Use it only on a reload the original really does
(UYA). SotC and GT4 found the ee-as reorder interaction (`.set volatile` comments). *Here? Careful*

**F5. Empty-asm barriers count as instructions** for branch shortening (Boktai: an empty `asm("")` is estimated as one
insn, which can turn a short branch long). PE2: input-only empty asm is implicitly volatile. *Here? No (but it explains
why other projects' asm-based matches are not portable to us)*

**F6. Permuter dummy statements** (`x++; x--;`, `s->q = s->q;`, `+0`, `(x+1)-1`) are rejected even by projects that allow
pins (Boktai depin 13). SotN's `(Random() & 3) + 1 - 1` is the same class. *Here? No*

---

## 10. Using the permuter well

**M1. Use it late, on register-only diffs, then extract the *plausible* edit.** decomp-permuter README: the permuter is
"best towards the end, when mostly regalloc changes remain". Randomisations "often produce meaningless changes that
happen to improve regalloc"; pick the plausible ones, and if none are plausible the runs still show which lines matter.
https://github.com/simonlindholm/decomp-permuter

**M2. Know what its gcc weights favour.** `default_weights.toml` for gcc turns *down* (0.5) `perm_add_mask`, `xor_zero`,
`refer_to_var`, `float_literal`, `sameline`, `empty_stmt`, `condition`, `mult_zero`, `dummy_comma_expr`,
`add_self_assignment`, `duplicate_assignment` and `pad_var_decl`, and turns *up* `perm_alias_array` (3). The heavy hitters
at base weight are `perm_temp_for_expr` (100), `expand_expr` (20), `reorder_stmts`/`reorder_decls`/`cast_simple`/
`randomize_internal_type`/`split_assignment`/`ins_block`/`struct_ref`/`inline` (10). These are the shapes that matter for
gcc: temporaries, statement order, types, inline and struct refs.
https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml

**M3. Restrict and steer: `PERM_LINESWAP`, `PERM_GENERAL`, focus lines.** Use `PERM_LINESWAP` over a store run,
`PERM_GENERAL(a, b)` for the two operand orders, and `PERM_RANDOMIZE` only around the differing lines. Boktai's fork adds
`--focus auto|LINES` and meaning-preserving agbcc passes (move-to-use, split variable, typed constants, loop form,
call-argument order through an inline wrapper, safe statement swap).

**M4. Give it a better score.** UYA: the default score tracked `try_func` differences poorly, and with a custom
`check.py` metric it improved 9 of 11 near misses. Boktai: "a permuter score of 0 is not a match: it ignores branch
offsets". Always recheck in the real unit (for us: the C++ unit, since the permuter works on a C copy, see V8).

**M5. Enumerate instead of sample.** Boktai's `translate.py` enumerates every edit the passes can make on the involved
lines and ranks by remaining gap; their `natfarm.py` ran 26 natural passes deterministically over all pinned functions.
UYA brute-forced statement orders of the first statements and store lines, and wrap positions (`dwrap.py`).

---

## 11. How projects decide something is truly unmatchable

- **PE2** marks a proof attempt incomplete until a reproducer exists. BFM's wiki (gcc 2.7.2) is blunt: six rounds of
  "unsteerable" verdicts (hoist vs rematerialise across calls, store vs load order, delay-slot filler choice, spill-slot
  order) were all explained once someone read the pass source. "Two proofs of unmatchability were each one producer
  short"; "twelve compiler walls were actually the vendor's controller library". **A wall verdict must name the pass and
  the condition**, or it is not a verdict.
  https://github.com/Druthulu/BFM-decomp/wiki/How-to-AI-decomp-07-compiler-source
- **Boktai 3 `flagprobe.py`**: before blaming the compiler build or flags, compile the 150 smallest stubborn functions
  under 12 variants (other compiler builds, -O1/-O3, -fno-gcse, -fno-regmove and others). Only six scattered single
  matches appeared and every variant was further away overall, so "pins are a C-spelling problem". Worth running once
  on our residue with ee-gcc 2.95.3-114/-107/2.95.2 (all in `toolchain/compiler.toml`).
- **Wrong compiler per TU really happens.** UYA picks the assembler per function. GT4 uses ee-gcc 2.9-991111 for some
  files and a `nogcse` profile. Legend of Mana uses 7 pipelines over 4 compiler builds. Crash XS (agbcc) chose
  `old_agbcc` per object. SotC tested every PS2 gcc and found 2.95.x cannot make 2.96's sibling calls. For library-like
  code in our image, a different SN build is a real candidate. That is a tooling question.
- **Assembler, not compiler.** SotC found ee-as filling delay slots the original assembler left empty (volatile accesses,
  indexed `la`), and an ee-as encoding bug that makes a few functions unmatchable unless the build pre-expands macros.
  GT4: `ldl/ldr` half order depends on the assembler year. A residue made only of slot fills or encoding is a build
  issue.
- **PE2 "What does not generalise"**: handwritten stubs falling through on an incoming register, dead `lui/ori` in an
  entry block and similar; grep the corpus, don't build a rule.
- **GT4**: "When the code depends on unrelated declarations ... the compiler hashed symbol addresses during CSE; try the
  other natural form or park it." "bne vs bnel may depend on whether the callee is defined in the same file ... we compile
  one function per file: park such residuals." These are the honest "park" categories for a one-function-per-file
  project like ours.

---

## 12. How 100% projects finished (the last 10-20%)

| Project | Compiler | How the last functions were closed |
|---|---|---|
| **Parasite Eve 2** (complete) | PSX gcc 2.8.1 + patched maspsx | A compiler model (CODEGEN_MODEL.md), a GDB tracer on cc1 (`trace_gcc.py`), and a 7.5 MB per-function learnings corpus of about 4,500 entries recording each decisive edit. The last ones were accepted with **3 register pins, 4 inline-asm statements, 8 handwritten-asm routines**, all listed in the README as open "matching hacks". Assembler and linker behaviour (PSYLINK bss placement by name hash) were patched in maspsx. |
| **Legend of Mana** (complete, NA+JP) | 4 PSX gcc builds (2.7.2 family), 7 pipelines | Routing each source file to the right historical compiler and assembler pipeline; decomp-permuter. |
| **Paper Mario US** (100%) | KMC gcc | Community decomp.me plus the permuter over 3+ years. Their wiki tips are the condition inversion, loop and switch shapes cited above. |
| **Fire Emblem 7U** (all functions in C) | agbcc | "Some of the last ones are fake matches (register pins, empty asm barriers); each is marked `FAKEMATCH` with a comment", and each has a plain `#if NONMATCHING` twin that is checked for the same behaviour. |
| **Fire Emblem 8U** | agbcc | 99.78% in C; the rest is ARM that agbcc can't emit. History shows "add NONMATCHING for asm hacks" (2023) and later removals of NONMATCHING as plain C was found. |
| **pokeemerald / pokefirered** | agbcc | 100% matching years ago with many fakematches. Most were removed in 2021 by commits tagged **[LEAK-INFORMED]**, which we cannot do. Since 2023 non-leak cleanups fixed fakematches by: true types (e.g. a merged `*(s32*)&task->x` load replaced by two field compares), `%` instead of masks, early `return` instead of an `if` wrapper, dropping parameter copies, casting loop bounds (`i < (s16)to`). Current pokeemerald `src/` has **no register pins or empty asm at all** (checked in a local copy). |
| **The Minish Cap (tmc)** | agbcc | Late fakematch removals: the callee's true 64-bit return through a union (`GetFuserIdAndFuserTextId`), replacing goto/pointer walks with indexed `for` loops (`RespawnPlayer`), removing `FORCE_REGISTER` by restructuring (`SyncPlayerToPlatform`). |
| **Boktai 3** (in progress, about 9,900 exact) | agbcc | Compiler instrumentation, inverse allocation solver, deterministic natural-edit search (P3, M5). Depin workers turned 28 of 60, 19 of 60 and 14 of 50 pinned functions into clean C using R1-R11 and I1. |
| **GT4** (97.9%) | ee-gcc 2.96 C++ | Rule catalogue (ee-gcc-2.96.md) plus automated fixers: `near_fix.py` rules (`void_returns`, float-argument position, pass-through `this`), `perm.py` store-order enumeration, `regsearch.py` wrap search, `fragments.py` counting what m2c gets wrong. Per-file compiler profiles. |
| **SotN** (overlays complete) | gcc 2.6.3 + maspsx | Duplicate-function tracking (copy matched C to identical overlays), the decomp.me preset, the permuter, and the register-trick page (T3, T4). |
| **Digimon (dtbe_decomp)** | agbcc | One commit "Decompile all remaining nonmatching functions in Agumon (100% byte match)". No write-up. |

What this means for us:
1. **No gcc-2.x project reached a strict 100% with zero asm and zero pins on the first pass.** Every finished project
   (PE2, FE7U, pokeemerald and pokefirered originally, tmc, FE8U) closed the last few percent with FAKEMATCH, pins or
   asm, then spent years replacing them. Under our "no asm, no dead code" rules, the realistic end state is our
   `src/nonmatching/` lane for the residue, plus the plain-C replacements the cleanup phases found.
2. The cleanup phases that did *not* use leaks found the real fixes in a few families: the callee's true signature or
   return type, early returns vs `if` wrappers, dropped parameter copies, indexed loops instead of pointer walks,
   `%`/`/` instead of masks, struct types instead of casts, inline helpers in place of macros, and an operand-order
   flip. All of them are allowed here.
3. The biggest jump in yield came from **tooling that reads the compiler's decision** (PE2 tracer, Boktai
   `rasolve`/`regdiag`/`passdiff`, UYA `regalloc.py`, `sched_explain.py`), not from more random permutation.
4. **Clone and family propagation** (SotN duplicates, Boktai `clones.py`/`relatives.py`, GT4 family fixes) turned one
   solved residue into many matches. Our `tools/clones.py` is the same idea.
5. Before calling a residue unmatchable, rule out other compiler builds and assembler differences (§11).

---

## Sources

- Ratchet & Clank 3 wiki, Matching Patterns: https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns
- GT4 ee-gcc 2.96 notes: https://github.com/gustavocanepa/gt4-decomp/blob/HEAD/knowledge/ee-gcc-2.96.md
- SotC compiler findings: https://github.com/TheRealestNwah/sotc-decomp/blob/HEAD/docs/findings.md
- Parasite Eve 2: https://github.com/GabeRealB/parasite-eve-2-decomp (README, CODEGEN_MODEL.md, COMPILER_ANALYSIS.md, DECOMPILATION_LEARNINGS.md)
- Boktai 3: https://github.com/moozilla/boktai3-decomp/blob/HEAD/docs/REGALLOC.md , docs/AGBCC_RULES.md, docs/AGBCC_TIPS.md,
  tools/scope/README.md, docs/external/eds/matching-tricks.md, PR https://github.com/moozilla/boktai3-decomp/pull/214
- SotN register tricks: https://github.com/Xeeynamo/sotn-decomp/wiki/Register-Mismatch-Decompilation-Tricks ; https://github.com/Xeeynamo/sotn-decomp/wiki/Decompilation
- Paper Mario GCC tips: https://github.com/pmret/papermario/wiki/GCC-2.8.1-Tips-and-Tricks
- BFM-decomp compiler-source page: https://github.com/Druthulu/BFM-decomp/wiki/How-to-AI-decomp-07-compiler-source
- decomp-permuter: https://github.com/simonlindholm/decomp-permuter ; weights https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml
- God Hand CONTRIBUTING (no-pin policy): https://github.com/LucasPicoli/god-hand-decomp/blob/main/CONTRIBUTING.md
- Fire Emblem 7U README/CONTRIBUTING: https://github.com/6elphegor/fireemblem7u ; FE8U PR #744 https://github.com/FireEmblemUniverse/fireemblem8u/pull/744
- pokeemerald history (fakematch fixes, e.g. #2259, #2260, #2336, "Fix fakematchings regarding modulo"): https://github.com/pret/pokeemerald/commits
- tmc history (#666, #667, #694): https://github.com/zeldaret/tmc/commits
- Legend of Mana: https://github.com/celophi/lom-decomp ; maspsx: https://github.com/mkst/maspsx
- Crash Bandicoot XS (per-object old_agbcc): https://github.com/Almamu/CrashBandicootXS-decomp/pull/737
- dtbe_decomp commit: https://github.com/ReGame-Labs/dtbe_decomp/commit/0969d92d94fec79766a8b666048ab21b6fd87f3b
