# Post-mortem: the THUG PS2 decomp (2026-11-03 to 2026-11-14)

This is the post-mortem for the first phase of the project, which matched the PS2 game. It is in three parts:

1. **Post-mortem.** What happened, what worked, what did not, and where the ceiling is.
2. **Rust rewrite.** How hard it would be to turn this decomp into a native PC rewrite in Rust.
3. **"Reskate".** How hard it would be to bring THUG into *reskate*, a de-live-serviced, mod-open build of EA's
   *skate.* (2025, "Skate 4").

Parts 2 and 3 only assess difficulty. Neither is planned work.

Figures come from [STATUS.md](../STATUS.md), [REMAINING.md](REMAINING.md), the repo itself (file counts, `config/`,
`asm/`) and the maintainer's project notes. "Game code" excludes the Sony SDK, GameSpy, OpenSSL and libgcc, as in
the progress report.

---

# Part 1: Post-mortem

## 1.1 Summary

| Tier | Folder | Functions | Bytes | Share of game code |
|---|---|---|---|---|
| Exact, plain C++ | `src/funcs/` | 8,857 | 1,566,180 | **81.21%** |
| Exact under recorded compiler decisions | `src/concession/` | 89 | 77,456 | +4.02% (**85.23%** together) |
| Equivalent C++, not byte-exact | `src/nonmatching/` | 250 | 281,164 | fuzzy total **98.58%** |
| Left as assembly | [ASM_ONLY.md](ASM_ONLY.md) | 7 | 3,668 | 0.19% |
| **Total** | | **9,203** | **1,928,468** | |

- **Pace:** 717 PRs merged in 12 days, from repo creation on 2026-11-03 to close-out PR #722 on 2026-11-14.
- **Who did the work:** three Claude Code lanes split by address range. No AI was involved in merging:
  [Decompathon Steward](https://github.com/andrewnakas/decompathon-steward) ran five deterministic gates on the
  maintainer's machine.
- **Coverage:** every game function has C++ except the 7 hand-written or hardware-only ones.
- **Matching build:** always byte-identical (`SLUS_207.31: OK`).
- **Functional build:** runs all 339 concession and non-matching units in place of the game's code. It boots and
  plays into New Jersey in PCSX2, with frames within 0.2–2.6% of the original when the two are booted back to back.

## 1.2 Timeline

| Date | Exact | Fuzzy | What happened |
|---|---|---|---|
| 11-03 | 33.8% | | The disc was verified and splat split it into 11,438 functions. The all-asm build was byte-identical on the first day. The compiler was identified as SN ee-gcc 2.95.3 build 1.36 from one discriminating function (`sd` vs `sq` for the `$ra` save). 203 PRs merged on day 1. |
| 11-05 | 53.7% | | Three lanes plus Steward ran around the clock. **Steward**, at one PR per 4–8 minutes, was the bottleneck, not matching. |
| 11-06 | 73.96% | 92.93% | **Coverage complete**: every function had C++, either exact or in `src/nonmatching/`. This followed the owner ruling "we need all the C++". |
| 11-12 | 75.44% | 94.48% | The fuzzy push began. A functional build and a PCSX2 boot test were added, and booting found **10 real behaviour bugs**. The same day, parallel builds across sessions exhausted RAM and took down the desktop (see 1.6). |
| 11-13 | 80.82% | 98.44% | The **decision oracle** arrived: SN's stripped `cc1plus.exe` driven under gdb. Every residue was classified A/B/C. The owner ruled to create a **concession tier**, and new force kinds each added a batch of units. |
| 11-14 | 81.21% | 98.58% | The GameCube build was measured as a shape reference and turned out not to be a lever. Close-out followed: full re-verification, docs and branch clean-up. 85.23% counting concessions. |

The curve is the familiar one: about 34 points on day 1, 20 more over the next two days, 8 more to coverage, then
roughly 7 points over the last eight days. That last stretch cost the most tooling per byte.

## 1.3 What worked

1. **Fixing the toolchain before matching anything.** The exact SN build was pinned from a discriminating
   instruction before the first function was attempted (lesson carried over from thps64,
   [LESSONS.md](LESSONS.md)). No later match had to be redone because of a compiler change.
2. **Deterministic gates and strict provenance.**
   - The gates: toolcheck, scan, split, match and build. They are deterministic and involve no AI.
   - Provenance: no leaked source, no prototypes, the owner's own disc only.
   - Result: no merge was ever disputed, and the rules could be enforced mechanically, not by review. Steward
     copies only unit files into the judge, so a PR cannot change the rules it is judged by.
3. **Lanes and isolation.** Each agent had its own address range, its own clone and its own `work/` folder. There
   were no collisions across 717 PRs.
4. **The non-matching tier.** Accepting equivalent but not-exact C++ (scored, never linked) gave the project
   complete C++ coverage by day 4. It also turned "fuzzy" into a measurable target.
5. **Booting as the equivalence test.**
   - What the static audit found: `tools/equiv_audit.py` flagged 30 units, and none of them were real bugs.
   - What booting found: the functional build plus `tools/pcsx2_boot.py` found 10 real behaviour bugs that static
     review missed (00189750, 0017A400, 0014F538, 001E0F20, 001CD048, 00121200, 001BF5A0, 001BC938, 00188620,
     001AC030).
   - Lesson: the first end-to-end runtime check found more than any amount of reading.
6. **The decision oracle** ([techniques/ORACLE.md](techniques/ORACLE.md)).
   - What it is: gdb drives SN's own stripped compiler at hook addresses recovered from the binary, using a
     3,511-function symbol map.
   - What it did: it explained each near miss by compiler pass and candidate key, which replaced guesswork with
     diagnosis.
7. **The concession tier with directed search.** Some differences come from compiler-internal decisions that the
   source cannot reach. Recording those forces converted 89 units (+4.02%). Each new force kind bought a batch of
   units: `ga`, `la`, `sched`, `spill`, `fr`, `lfr`, `reorg`, `cprop`. Directed search (`tools/oracle_directed.py`)
   beat hand-hunting for forces.
8. **Verification as one chained script.** The close-out re-score, concession re-verify, scan, gate, build,
   functional build and boot all ran in one script, in one memory slot, with each step's exit code checked. This
   made the final numbers trustworthy.

## 1.4 What did not work, or stopped paying

| Approach | Result |
|---|---|
| Class-B "code shape" rewrites, done by hand or by agent | The first sweep converted about 11% of units. The second converted about 1 in 10, at about 230k tokens per 8-unit batch, so it was paused. 116 units (177 KB) remain undiagnosed. |
| Swapping the two tied statements in a class-C tie | 0 of 18 converted. Moving a third statement sometimes worked. |
| GameCube retail build as a shape reference | Pairing was reliable: 183 units at 99.7% precision. But in a sample of the 10 largest units it showed no structural error, because the residue is register allocation and scheduling. Measuring it took about a day, for a negative result that was still worth having. |
| Other SN compiler builds (2.95.3-114/-107, 2.95.2-274/-273a) | None matched. Every apparent gain was an alignment artefact. |
| Per-file `-fno-gcse` | Usually wrong. Dropping the flag gave exact matches. |
| Declaration-context padding | 0 of 1,296 compiles changed a word. |
| Wider force searches (beam 3, 200 compiles) | Nothing beyond the directed search. |
| Early dead-code or "steering" tricks | Ruled out. 6 units were returned to asm on 11-03. |

## 1.5 Bottlenecks and cost

- **Days 1–3: merge throughput.** Steward handled one PR per 4–8 minutes. Matching was faster than merging.
- **Days 4–12: per-unit difficulty.** Each remaining point needed new tooling (oracle, force kinds, directed search)
  rather than more agents.
- **Cost accounting is the biggest gap in this post-mortem.** Token spend was not tracked per phase. The only firm
  figure is about 230k tokens per 8-unit rewrite batch in the last phase. Next time, log tokens and compiles per
  merged byte from day 1.

## 1.6 Incidents

| Incident | Effect | Fix |
|---|---|---|
| Parallel builds across sessions exhausted RAM (11-12) | The desktop and every session were killed | `memgate` (at most 2 heavy jobs machine-wide, waits for free RAM) and a capped `claude.slice` |
| An old PR going DIRTY stalled Steward, and newest-first ordering starved old PRs | The merge queue stopped | Merge oldest first, in Steward |
| `wibo` hangs under load | Compiles timed out; Steward's gate crashed on a `TimeoutExpired` | `cc.py` retries, and concession verify retries 3x (PR #720) |
| `memgate` gave up after 3600 s during the close-out re-score (rc 75) | The verification chain aborted | `MEMGATE_WAIT`, and the whole chain in one slot |
| The timed PCSX2 route missed under host load 13 | A boot came out inconclusive | Boot the original and the functional build back to back under the same load |
| Agents past about 350k context hit errors | Lost work | Fresh agents with short briefs |
| Gate output piped through `tail` | Hid a failing exit code once | Never pipe a gate; check `rc` |
| The game reads its own ELF filename | A longer filename crashes it (TLB miss at 0x114318) | `pcsx2_boot.py` always boots the build as `SLUS_207.31` |

## 1.7 Decisions and refusals

- **Owner rulings:**
  - no AI in merges;
  - "we need all the C++" (11-06), which created the non-matching tier;
  - a tooling change for PR #700;
  - the concession tier (11-13, [RULES.md](../RULES.md) rule 10), which reversed the earlier "a forced compile is
    never shippable";
  - a steady budget of 2–3 agents.
- **Matching rulings** (all in [MATCHING_GUIDE.md](MATCHING_GUIDE.md)):
  - no dead or steering code (the instruction test);
  - empty case values must be pinned uniquely;
  - per-file flags need evidence from matched neighbours in the same file;
  - `volatile` only for data shared with interrupts or threads;
  - truthful signatures over score;
  - inline asm only on the allow-list.
- **Provenance refusals.** A prototype build was declined because PROVENANCE.md excludes internal builds. An
  unofficial online copy of the disc was declined. The GameCube image was used only as a measuring stick, and
  nothing from it is in the repo beyond summary statistics.
- **"Could a concession be wrong code?"** No more than a non-matching unit could. It is ordinary equivalent C++,
  boot-tested. The forces only replay tie-breaks inside SN's own compiler.

## 1.8 The ceiling

[REMAINING.md](REMAINING.md) accounts for every unit. The biggest bucket is code shape, undiagnosed: 116 units,
177,496 bytes. Then come internal order the forces do not reach (40), within 4 words under forcing (32), and
gcse/PRE/cse/loop decisions (28).

Only two levers are left:

- **More rewrite batches.** About 85 queued units, at an estimated 2M tokens for 8–10 conversions.
- **A `cse`-pass force kind.** This would serve part of the gcse/cse bucket.

**Judgment:** about 85% exact, counting concessions, is the practical clean-room ceiling for this toolchain without
a breakthrough in shape diagnosis. The 98.58% fuzzy, boot-verified C++ matters more for anything built on this
work than the last exact points do.

## 1.9 Lessons for the next decomp

1. **Pin the compiler from a discriminating function first.** (Again.)
2. **Build the functional build and boot test in week one, not day 10.** It finds real bugs that static review
   cannot.
3. **Make a non-matching tier part of the plan.** Full coverage early beats a long tail of untouched asm.
4. **Classify residues with a compiler oracle as soon as the easy matches dry up.** It tells you which units are
   worth a human, which need a force, and which to leave.
5. **Gate memory and parallelism from the start** on a shared machine.
6. **Merge oldest first.** Expect the merge queue, not matching, to be the early bottleneck.
7. **Track tokens and compiles per merged byte per phase.**
8. **Name things as you go.** Matching rewards address names, so nothing forced recovery of meaning. Part 2 shows
   what that costs later.

---

# Part 2: Porting to a Rust rewrite

## 2.1 The core problem

The decomp is **behaviourally complete**: 98.58% fuzzy, booting and playing in the functional build. But it is
**semantically anonymous**, and it is still **welded to the PS2 image**. Matching asks for the right instructions,
not the right names or a standalone program, so neither was recovered. A Rust rewrite needs both.

## 2.2 Naming and structure: almost none recovered

| Measure | Count |
|---|---|
| Units named by address (`func_XXXXXXXX`) | 9,196 of 9,196 |
| Units that are member functions of a recovered class | 5,568 |
| Distinct type names declared inside units | 14,970 |
| ...of which carry an address (`Obj_001F53D0`, `Base13F8B0`) | ~14,907 |
| Shared headers with a real layout (`include/game/`) | 2 (`idstring.h`, `vector.h`) |
| `extern "C" func_` callee declarations | 27,468 (6,950 distinct callees) |

- **No shared layouts.** Each unit re-declares the partial struct it needs, with `pad[]` fields. Nothing reconciles
  `Obj_A` in one unit with `Obj_B` in another, even when they are the same class.
- **Hints exist but are unused.** Assert paths name the source files:
  - `gel/components/*Component.cpp`
  - `sk/components/SkaterCorePhysicsComponent.cpp`
  - `sk/objects/skater.cpp`
  - `gfx/NGPS/p_gfxman.cpp`

  Script-function names in `.rodata` name hundreds of engine entry points. A naming pass would start from these.

## 2.3 Data is still assembly

| Section | Labels | Size |
|---|---|---|
| `.rodata` | 10,880 | ~183 KB |
| `.data` | 710 | ~55 KB |
| `.sdata` (gp-relative) | 3,908 | ~48 KB |
| `.lit4` | 1,768 | ~3.6 KB |
| `.bss` | 681 | ~872 KB |

- **Function pointers:** 4,384 in data (vtables and script/CFunc tables). Units reference 421 vtables.
- **Jump tables:** 152, which stay in the game's rodata.
- **Globals:** units reference 4,484 distinct `D_XXXXXXXX` symbols.
- **Fixed memory map:** the build pins every object to its original address. It also depends on `$gp = 0x0038F3F0`
  and a hard-coded heap region.
- **What a standalone program must lift:** every table, string, float literal and the BSS layout, as real typed
  declarations. Today none of that exists outside the asm.

## 2.4 The platform layer

| Layer | Size of the problem |
|---|---|
| Sony SDK 2.8 + newlib + SN runtime | 906 functions / 192 KB; **945 game units** call 228 distinct SDK entry points |
| GameSpy (online) | 1,036 functions / 237 KB; 73 game units call it. The servers are gone, so online play needs a replacement (or is dropped). |
| Direct hardware | 29 units touch EE registers (DMA, VIF, GS, INTC/timers); 9 use the scratchpad; about 79 use uncached or accelerated address aliases |
| VU0 | 23 inline-asm units (13 macro-mode vector math), plus 7 asm-only functions (one is a ~95-op hand-scheduled VU0 block) |
| VU1 microcode | 22.9 KB (`vutext.bin`). This **is** the renderer's transform and lighting stage, and it must be rewritten for the GPU. |
| IOP | 28 opaque IRX modules: SNDRV audio, EZPCM, streaming (CDVDSTM), pad, memory card, network, USB keyboard, multitap. None is decompiled. |

## 2.5 The engine runtime is not yet understood

Matching never required understanding these systems:

- the QB script VM and its CFunc tables;
- the component system (`gel/components`);
- the goal manager, park editor and create-a-skater;
- the asset formats: `.qb .pre .scn .geom .col .tex .skin .img.ps2 .vag .pss` and the ~900 MB `SKATE5.WAD`.

**No parser for any of these formats exists in the repo.** `tools/extract_disc.py` only copies files.

## 2.6 Parity hazards

- **The PS2 FPU is not IEEE 754.** It has no denormals, infinities or NaNs, and it clamps on overflow. Native
  `f32` physics will drift unless the rules are emulated where they matter (skater physics, collision).
- **Wide registers and qwords.** 64-bit GPR and 128-bit qword idioms (`Vector` has a TI-mode union) need explicit
  equivalents.
- **Limited verification of the non-exact code.** The 14.58% that is not exact was verified by a boot-to-first-level
  route, not by full coverage.

## 2.7 Recommended path: staged, each stage useful on its own

| Stage | Work | Biggest risk | Relative size |
|---|---|---|---|
| 0. Name and type recovery | Merge per-unit structs into shared class layouts, starting from vtables, asserts and script-function names; give classes and methods real names | Sheer volume: ~15k types, ~9k functions | Large |
| 1. Asset readers (Rust) | Parsers for `.pre/.qb/.scn/.geom/.col/.tex/.skin`, reading the user's own disc at setup time. Nothing is shipped (the same installer model as skate-3-rust-engine). | Undocumented formats; byte-exact readers need the stage-0 names | Medium |
| 2. Host PC build of the existing C++ | Lift the data image from the user's ELF at setup time. HLE the SDK, IOP (audio, streaming, pad) and GS/VU1. This is a recomp-style PC port and serves as the parity oracle. | VU1 renderer and IOP audio; memory-map assumptions | Large |
| 3. Rust, subsystem by subsystem | Port in this order: math, script VM, skater physics, goals/gaps/scoring, rendering (Bevy). Diff each against stage 2 with tick captures, citing original addresses as skate-3-rust-engine does. | Physics parity (FPU), script VM semantics | Very large |

- **Skipping stage 2** means porting with no reference to diff against.
- **Skipping stage 0** means porting 9,196 anonymous functions.

The owner's
[skate-3-rust-engine](https://github.com/SK8-ENGINE/skate-3-rust-engine) is proof that the stage-3 method works:
Bevy 0.18, about 232k lines of Rust ported routine by routine from disassembly, with tuning taken from the game's
own data and a user-disc installer. It also shows the cost: parity is still listed as work in progress.

**Provenance carries over unchanged:**

- no leaked source, even for names;
- assets only from the user's disc;
- no game bytes in the repo.

---

# Part 3: THUG into "reskate" (a de-live-serviced, mod-open *skate.*)

## 3.1 The gating dependency: the host game

- **What *skate.* is:** EA's 2025 Frostbite game. It is closed-source, live-service and online-only, and it ships
  the EA Javelin anticheat.
- **What "reskate" would require:**
  - a build that runs without EA's servers (server emulation or removal of the online layer);
  - a build that tolerates modified content.
- **Why this report goes no further:** both mean defeating or removing the anticheat and the online layer. That
  carries legal and terms-of-service risk, and this project's provenance rules would not cover it.
- **What the owner's existing work does:** it reads *skate.* files offline from a read-only mount. It never hooks
  or injects into the executable.

So everything below assumes a reskate exists with a documented way to load content.

## 3.2 Getting content into Frostbite

- **No public authoring path.** Frostbite has no official modding tools. The existing pipeline only *reads* the
  formats: TOC/CAS superbundles, EBX (RIFF with its own type info), MeshSet, `.physics` collision and BC3/BC7
  textures. Writing them back is a separate, larger problem.
- **Compression.** Oodle Kraken has no open-source codec. Encoding means running the game's own DLL.
- **Version churn.** Content indices (GUIDs to CAS locations) are tied to one game build. A live-service title
  changes them every update.
- **Rendering.** Shaders are not recreated. Materials are tinted master textures with parameters in shader blocks,
  so THUG's textures need a material mapping, not a straight copy.

## 3.3 Getting content out of THUG

- **Same gap as Part 2, stage 1.** No THUG asset readers exist yet.
- **Level data:**
  - PS2 geometry with vertex-colour lighting;
  - separate collision (`.col`);
  - rails and gaps defined in script node arrays (`.qb`), not in geometry.
- **Conversion.** Scale and axis conversion are needed. Grind detection in skate games relies on authored splines
  and material names, so THUG's rail nodes would need to be turned into splines.

## 3.4 Gameplay mismatch

THUG and *skate.* are different games:

- **THUG** is arcade: combos, manuals, reverts, special meter, goal and gap scripts in QB.
- ***skate.*** is physics-driven flick-it.

Porting THUG **levels** is feasible once both sides have readers and writers. Porting THUG **gameplay** would mean
reimplementing it as reskate mods, which needs a scripting API that reskate may not have.

## 3.5 Legal

- **Two publishers' IP** are involved: Activision for THUG, EA for *skate.*
- **Only conversion is acceptable:** of the user's own discs and installs, on the user's machine. Nothing converted
  may be redistributed.

## 3.6 Recommendation

The realistic way to get THUG levels into a modern skate game is the owner's own skate-3-rust-engine, not reskate:

- its `.skate` map format (v15) already carries visual mesh, collision, surfaces, spawns and rails;
- it has a Lua ZIP mod system with hot reload and a setup-from-your-own-disc installer;
- what is missing is a THUG level reader, and that reader is Part 2, stage 1, so the work serves both goals.

Revisit reskate only if it ships with a documented content format and mod loader that do not require touching the
anticheat or EA's servers.
