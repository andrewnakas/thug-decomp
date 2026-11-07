# Fixing register-allocation and scheduler ties under gcc 2.x: what N64, GBA and other non-PS projects do

Scope: documented techniques from public decompilations of other games (N64, GBA, plus general tooling) for the
differences our near misses have: callee-saved swaps, `$v0`/`$v1` choices, instruction order within a block,
delay-slot fill, store order, and GCSE/loop-hoist order. No leaked game source was opened. Compiler facts cite the
public GNU gcc 2.95.3 source (`gcc-mirror/gcc`, tag `releases/gcc-2.95.3`). Our SN ee-gcc 2.95.3 is built on that
release, so the same allocator and scheduler apply. Each fact below was read from the source, not remembered.

**Relevance weighting.** Paper Mario uses **gcc 2.8.1**. Mario Party 1-3 and Dr. Mario 64 use **KMC gcc 2.7.2**
(Dr. Mario CN: egcs 1.1.2). GBA pret projects and Boktai 3 use **agbcc**, which Boktai's docs describe as gcc 2.95
(pret's page calls it "derived from GCC 2.7"). These are the closest to us, and agbcc shares our
`local-alloc.c`/`global.c`/`flow.c`. SM64, OoT, MM, Banjo-Kazooie, Perfect Dark, Mario Kart 64, Snowboard Kids and
Animal Forest use **IDO** (a different allocator). Their tips are included only when the mechanism is
compiler-independent, and are marked *(IDO)*. MWCC (GameCube/Wii) tips are skipped.

**Legality column (this repo).** Our gates and guide ban asm and pinning, bare reads, no-op assignments, dead
stores and comma tricks that only steer the compiler (docs/MATCHING_GUIDE.md "No dead statements").
- **OK**: ordinary C++ that a person could have written.
- **GREY**: real code, but suspicious unless it plausibly comes from a macro or inline helper. Get a maintainer ruling.
- **BANNED**: rejected here. Listed only so nobody spends time on it.

---

## 0. The gcc 2.x rules that decide these ties (read once)

These are verified in the gcc 2.95.3 source. They explain why most of the techniques below work.

| Pass | Rule | Source |
|---|---|---|
| Pseudo numbering | A named local gets its pseudo when its declaration is expanded (`expand_decl`, `gen_reg_rtx`). In C++ that happens at the declaration statement, in order. Parameters come first (`assign_parms`). Compiler temporaries are numbered when the expression is expanded, so in first-use order. At **-O2**, `register` changes nothing: the in-register test is `(DECL_REGISTER (decl) \|\| ! obey_regdecls)`, and `obey_regdecls` is set only when not optimizing. | stmt.c `expand_decl` |
| Use counts | flow.c adds `loop_depth` to `REG_N_REFS` for every reference: `REG_N_REFS (regno) += loop_depth;`. Depth starts at 1 and goes up at each `NOTE_INSN_LOOP_BEG`. **An empty `do {} while (0)` emits loop notes**, so references inside it count double. | flow.c `calculate_loop_depth`, mark_used_regs |
| local-alloc (pseudo lives in one basic block) | Priority is `floor_log2(refs) * refs * size / (death - birth)`. A value used once gets priority 0. Quantities with a suggested hard register (copied to or from `$a0`, `$v0`...) are sorted first. **Ties go to the lower quantity number**, which is birth order in the block. | local-alloc.c `QTY_CMP_PRI`, `qty_compare_1`, `qty_sugg_compare_1` |
| global-alloc (pseudo lives across blocks) | Priority is `floor_log2(refs) * refs / live_length * size`. **Ties go to the lower allocno, which is the pseudo number**, which is declaration or first-use order. Each pseudo takes the first free register in allocation order, honouring copy preferences. So the order in which `$s0`, `$s1`... are handed out is the priority order. | global.c `allocno_compare` |
| Scheduler (haifa, sched1 and sched2) | Ready insns are ranked by: critical-path priority; then register-pressure weight (sched1 only); then relation to the last scheduled insn (data-dependent vs independent); then the number of dependents; and **finally `INSN_LUID`, the original order**. **Loop notes are scheduling barriers** (`schedule_barrier_found`). | haifa-sched.c `rank_for_schedule`, `sched_analyze_insn` |
| CSE | A `SYMBOL_REF` is hashed by the **address of its name string** (`hash += ((unsigned) SYMBOL_REF << 7) + (unsigned long) XSTR (x, 0)`). Bucket order, and so tie order between globals, can depend on identifier allocation order and name length. | cse.c `canon_hash` |
| Delay slots | reorg.c first fills from insns before the branch or call (`fill_simple_delay_slots`), then from the target or fall-through (`fill_eager_delay_slots`, which gives branch-likely). | reorg.c |

Source: https://github.com/gcc-mirror/gcc/tree/releases/gcc-2.95.3/gcc (stmt.c, flow.c, local-alloc.c, global.c,
haifa-sched.c, cse.c, reorg.c).

---

## A. Diagnose before editing (process techniques)

**A1. Read the allocator's own dumps, then pick the lever.** Compile once with `-dl -dg` (also `-dp` for insn numbers
in the `.s`, `-da` for every pass). In `.lreg`, read "Register N used X times across Y insns". In `.greg`, read the
sorted allocno list. For the swapped pair, compute both priorities. If they are equal, the tie goes to the lower pseudo
number, so fix declaration or first-use order (B1). If they differ, change the use count or the live length (B3-B6).
- **Fixes:** callee-saved swaps and `$v0`/`$v1` swaps. **Legality:** OK (diagnostic only).
- **Why it works on gcc 2.x:** see section 0.
- **Source:** Boktai 3 docs/REGALLOC.md (agbcc), https://github.com/moozilla/boktai3-decomp/blob/main/docs/REGALLOC.md;
  EDS catalog, the same repo's docs/external/eds/matching-tricks.md ("Most were resolved by reading agbcc's RTL dumps
  instead of guessing"); BFM wiki ("Read the allocation ORDER before any register lever"),
  https://github.com/Druthulu/BFM-decomp/wiki/How-to-AI-decomp-07-compiler-source.
- **Here:** already in our MATCHING_GUIDE ("Diagnosing a register swap").

**A2. Find the pass that owns the difference.** Compile the near miss and a variant with `-da`. Compare the RTL pass
by pass (`.rtl .jump .cse .addressof .gcse .loop .cse2 .flow .combine .regmove .lreg .greg .sched2`). The first pass
that differs names the family.

Boktai's classification of 930 pinned functions shows that most "register" problems are decided earlier than
allocation:

| Family | Count | Natural lever |
|---|---:|---|
| const-in-reg (cse) | 249 | constant handling (D1-D3) |
| alloc (pure allocation) | 197 | sections B and C |
| branch | 105 | section F |
| order | 95 | section E |
| expr-shape | 91 | expression form |
| combine | 55 | add or remove a temporary |
| extend | 35 | variable types |
| spill | 34 | live ranges |
| load-reuse | 28 | re-read vs keep a copy |
| hoist | 11 | loop invariants |

Only the **alloc** family is pure allocation. **Source:** Boktai REGALLOC.md, "Which compiler pass a pin acts on"
(`passdiff.py`).

**A3. Switch the scheduler off to test whether it is the cause.** Use `-fno-schedule-insns` or `-fno-schedule-insns2`.
If the order difference disappears, it is a sched1 or sched2 tie (section E), not allocation. If the original unit
really was built that way, the flag can be kept: it is in our `allowed_cflags`. **Source:** our MATCHING_GUIDE; boktai
`flagprobe.py` (12 flag variants over 150 functions found no systematic flag difference, which shows "pins are a
C-spelling problem").

**A4. Solve in compiler space, then search C. This is the biggest documented gain.** An instrumented copy of the
compiler exposes knobs for priority (`AGBCC_PRI`), forcing a register (`AGBCC_FORCE`) and shifting the spill
rotation (`AGBCC_SPILL`). A solver finds the smallest compiler-internal change that gives a byte match, for example
"`table` (pseudo 28) needs priority 0.182 → 1.273, above pseudo 70". A C search (`translate.py`) then enumerates
permuter edits on only those lines. It scores each edit by the residual still left once the instrumented compiler
closes the remaining gap, which gives the search a slope.

Why: the upstream permuter's score is flat for a register swap. Blind runs on 7 near misses improved one; the solver
matched two that had stalled. Forcing the ROM's register directly "is rarely enough: it breaks the conflicts the other
pseudos rely on". Searching priorities keeps the allocator's own rules.
- **Source:** Boktai PR #214, https://github.com/moozilla/boktai3-decomp/pull/214, and docs/PERMUTER.md.
- **Here:** gcc 2.95.3 is public, so a vanilla build with these knobs could approximate SN 1.36. Check first that it
  reproduces our matched units.

**A5. Treat the permuter as a hypothesis generator, and re-check its winners.** Rebuild every winner through the real
pipeline. A score of 0 is not a match: the score ignores branch offsets and relocations. Watch for "stale captures",
where a local caches a value before a later write. Never import permuter output as a batch. Remove scaffolding one
piece at a time and compare object hashes; many `if (1) {}` fakes turn out to be inert.
- **Source:** Snowboard Kids DECOMPILATION_LEARNINGS.md *(IDO, process applies)*,
  https://github.com/cdlewis/snowboardkids-decomp/blob/main/DECOMPILATION_LEARNINGS.md; Boktai PERMUTER.md; N64
  Decomp Workbench, https://github.com/akratch/n64-decomp-workbench.

**A6. Check signatures and arity before chasing registers.** A missing argument, a bogus `this`, or a void callee
that really returns a value shifts every live range. A "hidden live value" (a real second parameter held in a register
and passed on) moved every later reload register in an EDS function.
- **Source:** Snowboard Kids learnings; EDS catalog "A hidden live value occupies a spill register"; our
  MATCHING_GUIDE ("Check callee arity first").

**A7. Port the C of a matched sibling, then permute.** Paper Mario matched `dispatch_damage_event_actor` by copying
the start of `dispatch_damage_event_partner`, running the permuter, and deleting one statement that does not exist in
this version. Boktai's `relatives.py` ports every matched function that explains 90% or more of an unmatched one. On
21 such ports, every remaining difference was "not allocation" (wrong constants, callees or a missing guard).
- **Source:** https://github.com/pmret/papermario/pull/994; Boktai AGBCC_TIPS.md ("Near relatives",
  `tools/repair.py`).
- **Here:** `tools/clones.py`.

**A8. Fix the first differing block first.** One wrong block shifts every later reload register (round-robin
`last_spill_reg`) and every later pseudo number. Fix top-down and re-diff before judging the code below it.
- **Source:** EDS catalog, "Work top-down".

---

## B. Callee-saved swaps and other allocation-order ties

**B1. Reorder local declarations (pseudo number breaks equal priorities).**
```c
/* before: angle -> $s1, scale -> $s0 */   u16 scale, angle; ...
/* after:  angle wins the tie          */   u16 angle, scale; ...
```
- **Fixes:** two callee-saved registers swapped when their priorities are equal after integer truncation.
- **Why:** `allocno_compare` and `qty_compare_1` fall back to the lower number. Pseudos for named locals are created at
  their declaration (`expand_decl`).
- **Source:** EDS catalog (agbcc: "Equal priorities ... go to the lower pseudo number"; `AddZoneLink` matched by
  declaring `zoneOfs`/`playerOfs` before `z`); Boktai REGALLOC "Declaration order (pseudo numbers break ties)"; our
  MATCHING_GUIDE ("Float register choice follows local declaration order").
- **Caveat:** *(IDO, Snowboard Kids)* "declaration order of register-only locals is inert" there. That is IDO; on gcc
  it is a real lever.
- **Legality:** OK.

**B2. Move the declaration or initialisation to first use (C++ only).** In C++ a declaration is a statement, so
`int x = f();` placed at its use gives `x` a later pseudo number than a declaration at the top of the function. It
also shortens the live range.
```cpp
int a; int b; ... a = f(); b = g();     // a, b numbered at top
...  int b = g(); ... int a = f();      // numbered in use order
```
- **Fixes:** the same as B1, plus local-to-global transitions.
- **Why:** pseudo numbering is at expansion; the live length is the priority divisor.
- **Source:** Boktai `perm_move_to_use` ("lifetime is the divisor in both allocators' priority"). The permuter
  upstream has `perm_reorder_decls`.
- **Legality:** OK.

**B3. Shorten or lengthen one value's live range.** Pass an expression straight into the call instead of naming it,
or compute it right before use.
```c
float h = x * 0.5f; ...lots...; f(h);   →   ...lots...; f(x * 0.5f);
```
- **Fixes:** a callee-saved order swap, or a value that should not be callee-saved at all.
- **Why:** `live_length` is the divisor of the global priority.
- **Source:** our MATCHING_GUIDE (proved here); EDS "Levers that change live length" (a separate early return
  instead of an `&&` term; added sign extensions).
- **Legality:** OK.

**B4. Change a value's use count.** Re-read a field instead of keeping a copy, or keep a copy instead of re-reading.
Or turn two `return x;` into a `goto end;` with one `return`. One fewer reference can drop a value below its rival.
- **Source:** EDS ("one fewer use (`goto end;` to a single `return flags;`)"); Paper Mario
  `src/pause/pause_badges.c:1064` ("Need to re-read button state here for strange regalloc reasons");
  https://github.com/pmret/papermario.
- **Legality:** OK when the re-read is real code. BANNED if it is a bare read.

**B5. Split a reused variable, or merge two variables into one.**
```c
s32 t; t = a->x; use(t); t = b->y; use2(t);         // one pseudo, live across both
s32 t1 = a->x; use(t1); s32 t2 = b->y; use2(t2);    // two short-lived pseudos (often local-alloc)
```
Either direction can be the fix:
- Splitting gives separate pseudos, often moved from global-alloc into local-alloc.
- Merging gives "multiple lifetimes", which moves a value into global-alloc. In
  `StackedActor_InitRisingParticle`, reusing one scratch for three constants made it pick r7 naturally.
- **Source:** Boktai `perm_split_var` and `remove_var`; REGALLOC "Natural r7 allocation". Paper Mario has several
  "reuse of the pct variable is not ideal, but required to match", e.g. `src/world/area_kgr/kgr_01/wiggle.c:35` and
  `src/audio/bgm_player.c:1358` ("variable is nargs, but reusing temp is required to match"). Mario Party 3 has
  `s16 temp = sp10[k] != 0; // TODO: regalloc hack`.
- **Legality:** OK (reuse is ugly but real).

**B6. Make one value used in two blocks into a function-scope variable, or the reverse.** A value used in two blocks
becomes a global pseudo, which can free local registers.
- **Source:** EDS ("one function-scope `u16 *c` shared by two arms").
- **Legality:** OK.

**B7. Write a call's result back into the variable it came from.** `x = Chase_CellIndex(x, z);` makes the parameter,
`x` and the result one pseudo. That reproduced the original's single callee-saved register.
- **Source:** Boktai REGALLOC ("Inline result into its argument's variable", `sp_result_into_arg`).
- **Legality:** OK.

**B8. Use parameters directly instead of copying them (or add the copy).** `T *p = arg;` creates a new pseudo with
a copy preference. Many pins existed only because of a needless parameter copy or a missing early `return 0;`.
- **Source:** Boktai "Replacing pins with plain C" (item 1); Snowboard Kids *(IDO)* "local alias of an argument" pulls
  it into an `s` register.
- **Legality:** OK.

**B9. Wrap references in `do { } while (0)` to raise their weight.** References inside the loop notes count
`loop_depth` = 2 instead of 1 (section 0). That raises the value's priority without changing behaviour. Boktai
`sub_08010514` needed the table pointer to outrank two constants, and four nested empty loops around
`table = gUnk_0203B400;` matched it. Paper Mario (gcc 2.8.1) has about 28 bare `do {} while (0);` and about 100
`do { stmt; } while (0); // required to match` in matched code, for example `src/world/action/hammer.c:304`,
`src/evt/evt.c:1246` and `src/entity/Block.c:138`.
- **Fixes:** priority ties and losses between pseudos; ordering (it is also a scheduler barrier, E4).
- **Project positions:**
  - Boktai: "`do/while(0)` is a macro: write the macro" (e.g. `DEBUG_NOP()`).
  - Paper Mario: accepted with a "required to match" comment.
  - Upstream permuter: `perm_ins_block`.
- **Legality:** GREY. Acceptable only as a plausible statement macro or inline helper body, never as a bare
  `do {} while (0);`. Get a ruling.

**B10. Change a local's integer type (width or signedness).** Narrow types add extension insns, which flow counts
before combine deletes them. That changes refs and live length.
- In `EffectMoveAllEquipsResolve`, `u8` locals changed which of two pseudos won (priorities 0.3704 vs 0.3689).
- `u32 scale` instead of `u16` broke a tie in `AddAffineSprite`.
- **Source:** EDS catalog ("refs and live_length come from the flow pass, before combine"); the permuter's
  `perm_randomize_internal_type`; Boktai `extend` family.
- **Legality:** OK if the type is plausible for the data.

**B11. A constant as the first set of a pseudo doubles its live length.** `update_equiv_regs` doubles a pseudo's live
length once per constant set when it has a `REG_EQUAL`/`REG_EQUIV` constant. Making the first set a load instead (by
reusing a variable) fixed one function. A constant pointer born at function entry gets the longest live range, so the
lowest priority and no register; reload then rematerialises it at each use.
- **Source:** EDS catalog (`DiscardPrompt_DrawRemaining`, `FindMonsterLinkedToCard`).
- **Legality:** OK.

**B12. Change the order of an inline wrapper's arguments.** `static inline void Wrap(int size, T *p) { Fn(p, size); }`
evaluates the arguments in the wrapper's order. That changes which temporary gets the lower register and replaced pins.
- **Source:** Boktai depin batch 2, item 7; `perm_call_order`.
- **Legality:** OK if the helper is plausible. Our rules require it to be `static inline` and fully inlined.

**B13. Return early instead of wrapping the body in an `if`.** `if (x) { loop }` became `if (!x) return 0;` before the
loop. Splitting a compound final condition into two early returns works the same way. Both change block structure and
live ranges.
- **Source:** Boktai depin batch 2, item 6.
- **Legality:** OK.

**B14. Declare a pointer temporary inside the loop body.** This removed "+r" barriers on loop-carried pointers.
- **Source:** Boktai depin batch 1, item 8.
- **Legality:** OK.

**B15. `register` keyword: no effect at -O2 on gcc 2.x, a real effect at -O0.** At -O2 the in-register test ignores
`DECL_REGISTER` because `obey_regdecls` is 0 (stmt.c). At -O0, only `register` locals get pseudos; all others live on
the stack. It is useful only for a unit that needs `/* cflags: -O0 */`. *(IDO)* is the same at -O2: "`register int a;`
simply becomes `int a;`".
- **Evidence:** Paper Mario uses `register` only in libultra (`src/os/*.c`), never in game code.
- **Source:** gcc stmt.c `expand_decl`; https://hackmd.io/vPmcgdaFSlq4R2mfkq4bJg *(IDO)*.
- **Legality:** OK (the plain keyword). `register ... asm("$s0")` is BANNED.

**B16. Registers pinned to hard registers: every project that finished removed them.** Pins were often the cause of
the mismatch. Boktai `sub_0802D44C` matched exactly once its pin and barrier were removed. BFM says pins "moved the
diff" but were symptoms. pret cleaned up fakematches after 100%; see "Fix Mugshot_ShowBanner fakematch relying on
merged stores" (pokeemerald #2336).
- **Legality:** BANNED here. Listed as negative evidence.

---

## C. `$v0`/`$v1` and argument-register choices

**C1. Declare the callee's real return type.** A void-declared callee that really returns a value, or the reverse,
changes copy preferences to `$v0` and the delay-slot order.
- **Source:** our MATCHING_GUIDE; Snowboard Kids ("Match prototypes per call site": a function can return a value in
  one unit and be `void` in another).
- **Legality:** OK.

**C2. Name a constant argument (`int id = 0xB; f(id, ...)`), or write `(*(&off))` on its first use.** Either changes
which register the constant gets, and whether CSE shares it with another use.
- **Source:** Boktai depin batch 3, item 12; `perm_const_var`.
- **Legality:** OK for a named constant. `*(&x)` is GREY: it comes from macros, but alone it looks steered.

**C3. Coalescing of a result register is often not source-steerable.** BFM: "Result-register coalescing (v0/v1) ... was
not reliably source-steerable. A variable at the top made it worse, an early return broke branch polarity. Treat it as
a permuter target." Snowboard Kids *(IDO)*: `if (1) { ... }` moved a value between v0 and v1.
- **Source:** BFM wiki; Snowboard Kids.
- **Legality:** OK when the edit is real code.

**C4. Capture a compound assignment's result: `temp = (field += n);`.** This keeps the result in the register the
target uses; `temp = field + n; field = temp;` may not.
- **Source:** Snowboard Kids *(IDO)*. The same shape is in our MATCHING_GUIDE: `m = g; g = g + 1;` vs `m = g++`.
- **Legality:** OK.

**C5. Fall off the end of a non-void function.** The incoming `$v0`/r0 then stays as the result, which removed a
pinned result in agbcc code. This is undefined behaviour, so use it only where the binary proves it.
- **Source:** Boktai depin batch 1, item 4.
- **Legality:** GREY.

---

## D. Constants, CSE and loop hoisting (gcse, loop.c, cse2)

**D1. Assign a loop constant again inside the loop.** With two sets, loop.c no longer hoists it.
```c
u32 one = 1; for (...) { one = 1; ... }
```
- **Source:** Boktai depin batch 3, item 10 (`reset_const`, which replaced an `asm volatile("" : "+r"(c))`).
- **Legality:** GREY. It is a no-op assignment by our rules unless it plausibly comes from a macro.

**D2. Use one named constant for two uses, or two separate literals.** This decides whether CSE keeps one long-lived
pseudo (which may land in a callee-saved register) or rematerialises the constant per use.
- **Source:** Boktai const-in-reg family; EDS ("An inline helper can stop two lookups sharing a constant across a
  call": routing one lookup through an inline helper ends CSE's block there).
- **Legality:** OK.

**D3. Re-read through the lvalue just stored.** Write `D_x = ptr + 2; v = D_x + ...;` rather than re-deriving the
expression. Or the reverse: "don't cache what the target reloads".
- **Source:** Snowboard Kids *(IDO, but CSE-generic)*; Paper Mario `src/evt/player_api.c:281` ("temp needed and used
  specifically only once").
- **Legality:** OK.

**D4. Hide an address from gcse/PRE with two-step address arithmetic.** `off = (u8*)&sym + k; base = (s16*)(off - k);`
works because gcse hashes `SET_SRC`, not the `REG_EQUAL` note, so it never sees `sym`.
- **Source:** Boktai REGALLOC, "Hiding a symbol address from gcse".
- **Legality:** GREY, close to banned. It is steering arithmetic.

**D5. Hoisted global addresses get registers in the order the expressions first appear.** Name hashing breaks ties,
via the `SYMBOL_REF` string address (section 0). Reorder the first uses, not the `extern` lines. Dr. Mario 64
recorded "renaming D_80099290_cn to D_8008E540 produces different codegen".
- **Source:** our MATCHING_GUIDE; `src/main_segment/debug_menu.c:1143` in https://github.com/AngheloAlf/drmario64;
  gcc cse.c.
- **Legality:** OK (we cannot choose names freely, but we can choose the first-use order).

**D6. Index the array vs walk a pointer; place the increment.** `arr[i]` keeps `i` live. A pointer walk lets the loop
optimiser fold and hoist the address. Where `e++` sits (body vs `for` header) moves the add. Paper Mario's "negative
struct offsets in loops" pattern is matched by incrementing a struct pointer alongside the index:
`for (i = 1; i < n; i++, p++)`.
- **Source:** Paper Mario wiki, GCC 2.8.1 Tips and Tricks,
  https://github.com/pmret/papermario/wiki/GCC-2.8.1-Tips-and-Tricks; Boktai AGBCC_TIPS ("Loops"); Paper Mario
  `States_PatrolAI.inc.c:27` (`i[array]`: "index and array are backwards!").
- **Legality:** OK.

**D7. Loop form: `for`, `while`, or `if (c) do {} while (c)`.** This decides biv reversal, the exit-test place and the
counter copy.
- **Source:** Boktai `perm_loop_form`; our MATCHING_GUIDE ("Loop direction").
- **Legality:** OK.

**D8. Put a ternary or `&&` value inside a loop into a named local in the preheader.** The value is otherwise
recomputed each iteration.
- **Source:** Snowboard Kids *(IDO)*. It is plausible for gcc loop.c too, but verify.
- **Legality:** OK.

---

## E. Scheduler ties: order within a block, store order, delay slots

**E1. Reorder independent statements, including stores.** The scheduler's last tie-breaker is `INSN_LUID`, the
original order. Equal-priority insns therefore come out in source order. Snowboard Kids measured that permuting four
independent statements "24 ways" gave between 271 and 397 positional mismatches out of 422. Boktai matched
`sub_081DC470` by moving `half = s + 0xC4` below the stores the original emits first.
- **Source:** gcc haifa-sched.c `rank_for_schedule`; Snowboard Kids; Boktai REGALLOC "Statement order";
  `perm_reorder_stmts`, `perm_swap_stmts`; Paper Mario `src/battle/btl_states_menus.c:2122` ("x = StratsMenuPosX; //!
  required to match").
- **Legality:** OK.

**E2. Hoist a computation the original does early into its own statement.** A value computed early in the original
(`sqrtf`, a sum, a load before a constant) usually was its own statement in the source.
- **Examples:**
  - Boktai: `u8 v = *p; u32 r = 1; if (v <= 7) r = 0; f(s, r);` instead of `f(s, *p <= 7 ? 0 : 1)`, to get the load
    before the constant.
  - Paper Mario: `tempPlayerDist = distToPlayer; // needed to match` (FireBarAI.inc.c:99);
    `one = POPUP_MENU_SWITCH_PARTNER; // required to match (why is 1 loaded so early?)` (8a860_len_3f30.c:430).
- **Source:** our AGENTS.md (`func_00100118`); Boktai "Load before constant"; Paper Mario.
- **Legality:** OK.

**E3. Load first, store later.** Load all source fields into named locals before the stores
(`a = s->x; b = s->y; d->x = f(a); d->y = g(b);`). This reproduces "batch loads, then stores" and changes which of
two loads gets the earlier delay slot.
- **Source:** Snowboard Kids *(IDO)*; Paper Mario `src/npc_collision.c:348` (`sx2 = sx = *x; // needed to match`).
- **Legality:** OK.

**E4. Add a scheduling barrier with a statement macro (loop notes).** `NOTE_INSN_LOOP_BEG`/`END` are
`schedule_barrier_found` in haifa-sched, so nothing is scheduled across a `do { ... } while (0)`. It works in both
sched1 and sched2, and keeps an instruction above or below the boundary. Every Paper Mario example (`stat_change.c:222`,
`enemy_ai.c:230`, `item_entity.c:903`) is a barrier between two groups of statements.
- **Source:** gcc haifa-sched.c; Paper Mario; Boktai.
- **Legality:** GREY (as B9).

**E5. Inline helpers move CSE and scheduling boundaries.** An inlined `static inline` body brings its own parameter
copies (new pseudos, numbered at the call) and sometimes its own block ends after folded branches. Boktai: "A helper's
types often decide the allocation" (`helperswap.py` tries the matched corpus's spellings of each helper).
- Materialised booleans (`movs 1; b; movs 0; cmp`) come from a `static inline u8` test helper; an `int` result gets
  jump-threaded away.
- A mask constant loaded before the `ldr` comes from `static inline u32 tst(u32 *a, u32 m) { return *a & m; }`.
- **Source:** Boktai AGBCC_TIPS; EDS; our MATCHING_GUIDE ("Timeouts keep the constant in a register only through an
  inline helper").
- **Legality:** OK (`static inline`, fully inlined).

**E6. Delay-slot fill depends on what is movable before the branch.** gcc fills from the instructions before the
branch first. If the target has `nop` in a call's delay slot where you get the argument setup, Paper Mario says the
symbol was defined in the same file (`.data`/`.rodata` local) rather than `extern`. `volatile` globals cannot be moved
into the slot, so a load kept out of the delay slot means a volatile global.
- **Source:** Paper Mario wiki; our MATCHING_GUIDE ("`volatile` globals").
- **Legality:** OK for a `volatile` extern. Local data definitions are BANNED by our one-unit/no-data rule, so that
  case is unmatchable here. Record it in the nonmatching note.

**E7. Branch-likely appears or disappears when the condition is inverted.** `beql`/`bnel` come from
`fill_eager_delay_slots`, which steals from the target. Inverting the `if` (and swapping its arms) toggles it.
- **Source:** Paper Mario wiki ("Likely instructions"); `perm_reverse_cond`.
- **Legality:** OK.

**E8. Keep or split a macro's statements.** "separate lines required to match, cant combine macro"
(`documents.c:402`). A macro body, or its splitting into statements, decides evaluation order.
- **Source:** Paper Mario.
- **Note:** *(IDO)* `PERM_FORCE_SAMELINE` matters for IDO only. gcc 2.x does not care about line placement, and
  Snowboard Kids proved blank lines and line layout inert at `-g0`.
- **Legality:** OK.

---

## F. Branch layout and condition forms

**F1. Arm order: `if (x) A else B` vs `if (!x) B else A`.** gcc lays out the then-arm as fall-through. Swap the arms
to swap the layout.
- **Source:** Boktai AGBCC_TIPS ("Branch layout ... Try testing the branch-taken condition first"); `perm_reverse_cond`.
- **Legality:** OK.

**F2. `!x` vs `x == 0`, `x` vs `x != 0`, `> 0 || == 0` vs `>= 0`.** Usually inert on gcc. Paper Mario has
`if (hitID > 0 || hitID == 0) // required to match` (7BB60.c:772).
- **Note:** the upstream permuter's `[gcc]` weights lower `perm_condition` to 0.5 ("not beneficial for GCC").
  *(IDO)* says `x == 0` vs `!x` changes regalloc on `u16`.
- **Legality:** OK.

**F3. Write an explicit `goto` to a shared tail.** Paper Mario uses `goto block_17; // TODO required to match`
(menus.c:355, item_entity.c:2172) where structured code would duplicate or reorder the tail.
- **Source:** Paper Mario.
- **Legality:** OK. A `goto` is real C.

**F4. Nested `if`s instead of `&&`; sequential early returns in the original's order; one `return r`.** These change
block structure and therefore both the allocator's local/global split and live lengths.
- **Source:** Boktai AGBCC_TIPS; EDS ("a separate early return instead of an `&&` term").
- **Legality:** OK.

**F5. Switches.** Order case bodies by their order in the asm, not by value. List an explicit case identical to
`default` when an unused compare (`slti`) proves it.
- **Source:** Paper Mario wiki ("Irregular switch irregularities"); Boktai AGBCC_TIPS; our MATCHING_GUIDE.
- **Legality:** OK.

---

## G. Expression shape (combine/regmove-level ties)

**G1. Commutative operand order: `a + b` vs `b + a`, `(i << 2) + tbl` vs `tbl[i]`, permuted OR chains.** CSE's
`fold_rtx` moves an operand with a known constant to the second position. regmove ties an AND result to a dying
operand pseudo.
- **Source:** Boktai AGBCC_TIPS; EDS ("regmove's replacement quality"); `perm_commutative`; our MATCHING_GUIDE
  ("addu operand order").
- **Legality:** OK.

**G2. `a - b` vs `a + (-b)`; `x = -x` in place vs a new variable.**
- **Source:** `perm_add_sub`; our MATCHING_GUIDE.
- **Legality:** OK.

**G3. Split a constant shift into two shifts.** `(c->height >> 2) >> 2` for `>> 4` was found by the permuter.
- **Source:** Boktai REGALLOC; `perm_factor_shift`.
- **Legality:** GREY (plausible from macros).

**G4. Compound assignment vs explicit form: `x += y` vs `x = x + y`.**
- **Source:** `perm_compound_assignment`.
- **Legality:** OK.

**G5. Struct access forms: `p->f`, `(*p).f`, `p[0].f`, `(p + i)->f`, `i[p]`.** These change address CSE and which
base register is kept. Boktai found real struct types beat `*(u16*)(p + 0x20)` casts for register choice.
- **Source:** `perm_struct_ref`; Boktai AGBCC_TIPS ("Use real struct types"); Paper Mario PatrolAI (`i[points]`).
- **Legality:** OK.

**G6. Add or remove a temporary for a subexpression.** This is the permuter's highest-weight pass
(`perm_temp_for_expr`, weight 100). It changes the pseudo count and numbering, and gives combine a different chance
to fuse. Paper Mario's last function, `update_camera_mode_1` (PR #1019, "100%"), is a cloud of shuffled temporaries
such as `new_var2` and `tmp1`.
- **Source:** https://github.com/pmret/papermario/pull/1019; `perm_temp_for_expr`, `perm_expand_expr`.
- **Legality:** OK. Clean up the names afterwards (Conker PR #86).

**G7. Chain or split an assignment: `a = b = e;` vs two statements.**
- **Source:** `perm_chain_assignment`, `perm_split_assignment`; Paper Mario `npc_collision.c:349`.
- **Legality:** OK.

**G8. Casts and width in expressions: `(u16)`, `(s32)`, `& 0xFFFF`.** These change extension insns, and with them
refs and live length (B10).
- **Source:** `perm_cast_simple`, `perm_add_mask` (lowered for gcc).
- **Legality:** OK when the cast is meaningful. A redundant mask is GREY.

---

## H. Tricks other projects call "fake" (mostly BANNED here)

| Trick | Effect | Project position | Here |
|---|---|---|---|
| `x = x;`, `x += 0;`, `x++; x--;`, `s->q = s->q;` | adds refs | Boktai: "not acceptable depins; leave the pin instead". Paper Mario has `npc->pos = npc->pos; // TODO required to match` | BANNED |
| `if (0) {...}`, `(0, x)`, `x ^ 0`, `x * 0`, `if (v) {}` | keeps a value alive or adds a ref | permuter `[gcc]` weights 0.5; "originally written with IDO in mind and not beneficial for GCC" | BANNED |
| unused `PERM_PAD` decl (`perm_pad_var_decl`) | stack layout | IDO-era | BANNED (dead code) |
| `volatile` local | forces memory | Snowboard Kids: `volatile u8 padding[N]` "only after confirming the frame is the only mismatch"; Mario Party 3 AGENTS.md forbids volatile tricks | BANNED unless the binary shows volatile semantics |
| `register x asm("r")`, `asm("" : "+r"(x))`, `asm("":::"memory")` | pins, barriers | used by agbcc projects as `FAKEMATCH`, all being removed | BANNED |
| one-element alias array `s32 v[1]` | forces a local to memory | `perm_alias_array` (weight 3 for gcc) | GREY (only with a real array) |
| "multiply by 16 then divide" (Paper Mario `audio/core/engine.c:899`) | — | marked "TODO fake match" | BANNED |

**How projects decide a function is "permuter-only" or "unmatchable".**
1. **Score is flat.** If many runs and thousands of mutations score the same, the search cannot converge, and the
   difference is not in its space. Snowboard Kids: "stop when inert". Boktai: "Why blind search stalled".
2. **The residual is outside C control.** Silent Hill issue #482 (PS1, mentioned for the reasoning): the permuter
   found nothing because the target needs a value in a hard register that the call-free C cannot control. BFM: "A
   residual on a call to an external callee is outside the permuter's search space."
3. **Compiler-space solving says no priority change helps.** Then "the ROM's register comes from a conflict: the
   original had another value live there" (a missing variable or argument), or the difference is instruction
   selection or CSE (Boktai `rasolve.py`).
4. **"Every small edit moves 20+ instructions"** (pressure lock): hand it to the permuter (BFM).
5. **Keep it as an equivalent nonmatching unit.** Perfect Dark shipped "fully decompiled" with "a small handful of
   functions not byte-matching even though functionally the same". THPS64 keeps 62 such functions in
   `src/nonmatching/` with a `NON_MATCHING:` note each, verified by screenshot bisection. This is our
   `src/nonmatching/` model.

---

## How 100% projects finished

| Project | Compiler | End state | How the last 10-20% closed (documented) |
|---|---|---|---|
| **Paper Mario** (pmret) | gcc 2.8.1 (KMC lineage) | 100% US code, April 2023 (PR #1019 "100%", "byebye") | The final functions were matched by brute variable shuffling plus the permuter. The last function, `update_camera_mode_1`, is full of `new_var2`, reused deltas and duplicated stores. Siblings were copied and permuted (PR #994). About 128 `do {} while (0)` barriers and dozens of "required to match" temporaries, gotos and re-reads were accepted with comments and cleaned later. They also ported the permuter to their build (PRs #203/#204: wrapping `__asm__` macros in a dummy function so pycparser accepts them). |
| **Mario Party 3** (mariopartyrd) | KMC gcc 2.7.2, `-O1` | ongoing, high | `permuter_settings.toml` checked in with `compiler_type = "gcc"` and the exact compiler command, plus a decomp.me mapping (`gcc2.7.2`). AGENTS.md forbids register-syntax and `volatile`/`__asm__` tricks; "regalloc hack" temporaries are tolerated with TODO comments. |
| **Dr. Mario 64** (AngheloAlf) | KMC gcc 2.7.2; egcs 1.1.2 for CN | far along (completion not verified here) | Remaining oddities are marked `//! FAKE` (labels, temporaries, renamed symbols). One version needed a different compiler, found by compiler bisection per version. |
| **Pokémon Emerald/FireRed/Ruby** (pret) | agbcc (gcc 2.x) | 100% | After 100% they spent PRs replacing fakematches with natural C (e.g. #2336, "relying on merged stores ... must be fixed"). `BLOCK_CROSS_JUMP` (`asm("")`) is kept as one named macro. |
| **Boktai 3** (moozilla) | agbcc ≈ gcc 2.95 | about 31%, active | The most systematic late-stage tooling: the instrumented compiler (`AGBCC_PRI/FORCE/SPILL`), `rasolve` then `translate` (beam search with a residual score), a permuter fork with crash fixes and 8 gcc passes, a "pin farm" that removed pins from about 930 functions, a pass-family classifier, `relatives`/`repair` ports, and `flagprobe` flag bisection. They found that **66% of near misses differ in more than 3 instructions of shape**; only about 10% are pure registers. |
| **Yu-Gi-Oh! EDS** (cited in Boktai) | old_agbcc | — | Around 60 register-only functions were resolved by reading `.lreg`/`.greg` dumps. A patched compiler (`regoracle`) replays global-alloc in Python and inverse-solves the priority order. |
| **Banjo-Kazooie** | IDO 5.3 | 100%, August 2024 | The final commit was "func_803411B0 match", followed by symbol cleanup. Years of collective decomp.me and permuter work; no write-up of the final technique was found. |
| **Perfect Dark** | IDO | "fully decompiled", a handful non-matching | Accepted functionally equivalent nonmatching C as done. The status page counts matching only, so it shows less than 100%. |
| **OoT / MM / SM64** (zeldaret, n64decomp) | IDO 7.1 / 5.3 | 100% | decomp-permuter grew up in this IDO community. Their fakes are marked `//! FAKE` / `// FAKE:`, and the last functions went through decomp.me and permuter@home, but no write-up of the final pushes was found (not verified in this pass). Little carries over to gcc beyond the process. |
| **Conker's BFD** (DevOldSchool) | not stated in the PR | active | Process: after a permuter match, clean up the leftover temporaries (copy temps, pass-through aliases, `tmp1` names) in a follow-up PR. Verify that every object is byte-identical, then check the ROM SHA-1 (PR #86). |
| **Snowboard Kids** | IDO 5.3 | active | A learnings file with an instrumented `uopt`, a stale-capture check for permuter winners, "prove insensitivity before chasing a lever", and "verify in the original translation unit". |
| **THPS64** (andrewnakas) | gcc 2.8.1 `-O1 -msplit-addresses` (found after KMC 2.7.2 failed on global stores) | done, with 62 nonmatching | Compiler identification by bisection on a specific shape (stores to globals). Nonmatching equivalents with screenshot bisection (`nm_bisect.py`). |

**Process patterns common to the finishers**
1. **Identify the exact compiler and flags early, by bisection on a distinguishing shape.**
   - THPS64: 2.7.2 vs 2.8.1, on global stores.
   - Dr. Mario: a per-version compiler.
   - BFM: the circulating "2.7.2" tree is really 2.8.1.
   - Boktai flagprobe: once identified, flag sweeps rarely help.
2. **Work from the compiler's view.** Use RTL dumps, `-dp` insn numbers, and instrumented compilers (Boktai, EDS,
   Snowboard Kids, Workbench).
3. **Port from relatives and clones before writing from scratch**, then repair constants and callees (Paper Mario
   #994, Boktai `relatives`/`repair`).
4. **The permuter, at the end only.** Paper Mario's last functions; the permuter README ("best towards the end, when
   mostly regalloc changes remain").
5. **Accept documented fakes as a debt, then pay it off** (Paper Mario comments, pret fakematch cleanup, Conker
   temporary cleanup).
6. **Count equivalent nonmatching functions as decompiled** but not matched (Perfect Dark, THPS64; our
   `src/nonmatching/`).
7. **Always verify through the real full build** (ROM hash), never the permuter's own score (Snowboard Kids, Conker).

**Finding the right source and context**
- **Library code:** projects match SDK and libc functions by identifying the exact library version and its build
  flags. Per-file flags differ (Boktai: library code "built without interworking"; Paper Mario `src/os/` uses
  `register`). We skip SDK code, so it is only relevant for spotting it.
- **The rest of the unit matters.** Same-file static data changes delay-slot fill (Paper Mario wiki). A function-address
  table in the same unit changed scheduling (Snowboard Kids, "verify in the original translation unit"). Under our
  one-function-per-file rule, any difference caused by a neighbour is unmatchable here. Record it as such.

---

## Tool notes

- **decomp-permuter.** It has 37 randomization passes. The score is weighted from objdump diffs: `PENALTY_REGALLOC=5`,
  `REORDERING=60`, `INSERTION=100`, `DELETION=100`, `STACKDIFF=1`, `BRANCHDIFF=1`, with a difflib or levenshtein
  aligner. Its `[gcc]` weight profile lowers IDO-era tricks to 0.5 and raises `perm_alias_array` to 3. The PERM
  macros are:
  - `PERM_GENERAL(a, b, ...)`: one of the alternatives.
  - `PERM_LINESWAP(lines)`: a permutation of the lines.
  - `PERM_VAR`, `PERM_INT(lo, hi)`, `PERM_ONCE`, `PERM_RANDOMIZE(code)`.
  - `PERM_IGNORE`/`PERM_PRETEND`: for C++ and non-C text.
  - `PERM_FORCE_SAMELINE`: IDO only.

  Options include `-j`, `-J` (permuter@home, a shared compile farm via Docker workers), `--best-only`,
  `--better-only`, `--stop-on-zero` and `--stack-diffs`.
  https://github.com/simonlindholm/decomp-permuter (README, src/randomizer.py, default_weights.toml, src/scorer.py).
- **Boktai permuter fork.**
  - Each pass is rolled back if it fails.
  - It handles anonymous structs, shared type nodes and shadowed locals.
  - `--focus auto|LINES` restricts mutation to the differing lines.
  - It adds 8 gcc passes (below).
- **decomp.me.** Hosts scratches on our exact compiler builds (the `decompme/compilers` release assets
  `ee-gcc2.95.3-136` etc. that `toolchain/compiler.toml` pins). Its asm-differ diff, m2c "decompile", fork and family
  views are how most finishers crowd-sourced their last functions.
- **m2c.** Helps to start drafts that mirror the original variables (e.g. one variable per saved register) and to
  pick a gcc target over an IDO one. Check `m2c --help` for the exact option names.
- **asm-differ.** Three-way diff against the previous build (`-3`), watch mode, and difflib or levenshtein alignment.
  Useful for spotting which single edit moved what.
- **N64 Decomp Workbench.** Relocation-aware compare; verdicts such as `allocation-mismatch`, `schedule-mismatch` and
  `commutative-order`; campaigns. It is IDO-only for traces, but its verdict taxonomy is reusable.

---

## Appendix: permuter passes worth re-implementing as C++ text transforms

**Meaning-preserving upstream passes** (gcc weight in parentheses). These are the core:

| Pass | Edit |
|---|---|
| `perm_temp_for_expr` (100) | move an expression into a new or reused temporary |
| `perm_expand_expr` (20) | replace a variable read with its last-assigned expression |
| `perm_reorder_stmts` (10) | move a statement to a nearby position (needs a dependence check) |
| `perm_reorder_decls` (10) | move a declaration |
| `perm_struct_ref` (10) | switch member access form |
| `perm_commutative` (5) | swap operands of a commutative operator |
| `perm_add_sub` (5) | `a - b` ↔ `a + (-b)` |
| `perm_compound_assignment` (5) | `x = x op y` ↔ `x op= y` |
| `perm_split_assignment` (10) | split `a = b op c` with a preceding assignment |
| `perm_chain_assignment` (5) | merge two assignments into a chain |
| `perm_long_chain_assignment` (3) | merge three or more |
| `perm_inequalities` (5) | shift a bound by ±1, strict ↔ non-strict |
| `perm_reverse_cond` (1) | negate an `if` and swap its arms |
| `perm_cast_simple` (10) | cast to a simple type |
| `perm_randomize_internal_type` (10) | change a local's integer type |
| `perm_randomize_function_type` (5) | change a return or parameter type |
| `perm_remove_var` (5) | delete one of two same-type variables, reuse the other |
| `perm_inline` (10) | move an expression into a `static inline` helper |
| `perm_factor_shift` (5) | split a constant shift |
| `perm_factor_mult` (5) | split a constant multiplier |

**Fake or IDO-era passes we should not port** (our gates ban them):
`perm_xor_zero`, `perm_mult_zero`, `perm_dummy_comma_expr`, `perm_add_self_assignment`, `perm_refer_to_var`,
`perm_empty_stmt` (except labels), `perm_pad_var_decl`, `perm_duplicate_assignment`, `perm_sameline`,
`perm_float_literal`. Also `perm_var_cond_block` (duplicating code under `if (var)`) and `perm_add_mask` and
`perm_remove_ast`, which can change meaning: use them only with an equivalence check.

**Grey upstream passes:** `perm_ins_block` (`do {} while (0)`/`if (1)`: only if emitted as a named macro),
`perm_alias_array`, `perm_randomize_external_type`.

**Boktai additions (gcc-specific), all re-implementable:**

| Pass | Edit |
|---|---|
| `perm_move_to_use` | move `x = e;` down to its first use, or up to just after what it reads |
| `perm_split_var` | give a reused variable a fresh name from one assignment to the next |
| `perm_const_var` | turn a constant into a typed local, or name it inline |
| `perm_loop_form` | `for` ↔ `while` ↔ `if (c) do {} while (c)` |
| `perm_addr_deref` | `x` → `*&x` (grey) |
| `perm_call_order` | reorder arguments through a `static inline` wrapper |
| `perm_swap_stmts` | swap two adjacent independent statements |
| `perm_literal_address` | a global → its literal RAM address. **BANNED here** (hard-coded addresses). |

**C++-specific passes we would add** (no upstream equivalent, because the permuter parses C only):
- move a C++ declaration-with-initialiser to its first use or to the top (pseudo numbering, B2);
- member access `m_x` ↔ `this->m_x` ↔ a local copy of `this`;
- an inline member accessor vs a direct field access (E5);
- argument order through an inline member wrapper (B12);
- result written back into its argument (B7);
- an early return ↔ a wrapped body (B13);
- nested `if` ↔ `&&` (F4);
- arm swap with negation (F1).

Score them against the real `match.py` output, not a custom objdump diff (A5).
