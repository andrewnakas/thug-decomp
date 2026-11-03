# AGENTS.md: how to contribute (AI agents and humans alike)

This is the single source of truth for working in this repo. New here? Start with [START_HERE.md](START_HERE.md).
Read [RULES.md](RULES.md) and [PROVENANCE.md](PROVENANCE.md) once, and [docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md)
before your first function.

## What you are doing

You turn one function of `SLUS_207.31` (Tony Hawk's Underground, PS2, NTSC-U) from asm back into C++ that compiles to
**exactly** the same instructions under the pinned toolchain (SN ee-gcc 2.95.3 build 1.36, `toolchain/compiler.toml`).
One function per file: `src/funcs/func_XXXXXXXX.cpp` (uppercase hex address). Nothing else is a contribution: the
gates judge only `src/funcs/` files (plus shared headers in `include/game/`).

**Never look at the leaked THUG source** (thug1src and its forks/mirrors), not even to check a name. See PROVENANCE.md.

## Lanes (so agents do not collide)

| Agent | Address range | Branch prefix |
|---|---|---|
| Claude lane 1 | `0x00100000`–`0x001BFFFF` | `claude-lane1/` |
| Claude lane 2 | `0x001C0000`–`0x0027FFFF` | `claude-lane2/` |
| Claude lane 3 | `0x00280000`–`0x003478CB` | `claude-lane3/` |
| Any other agent or human | an unclaimed range from the Active claims issue (#1) | `<name>/` |

Sony SDK, OpenSSL, GameSpy and libgcc code is linked in among the game code. It is not a target: if a function is
clearly library code (a known SDK routine, OpenSSL `BN_*`, GameSpy, `__divdi3`...), skip it and note it in your PR
so it can be tagged in `config/lib_ranges.us.csv`.

Use **one clone per agent**, and keep every temporary file inside your own clone (under `work/`, git-ignored): never in a shared temp or scratchpad directory, where another agent can pick it up. Never run `split.py`, `gate.py` and `build.py` at the same time in one clone: they share
`asm/`, `build/` and `build.ninja`. Keep parallel compiles low (`-j2` to `-j4`) when several agents share a machine.

## Setup (once per workspace)

```sh
git clone https://github.com/andrewnakas/thug-decomp && cd thug-decomp
ln -s /path/to/your/THUG.iso disc/            # your own dump, git-ignored
python3 toolchain/setup.py
.venv/bin/python tools/extract_disc.py
.venv/bin/python tools/split.py
.venv/bin/python configure.py && .venv/bin/ninja        # must print SLUS_207.31: OK
```

## The loop, per function

1. **Pick and claim.** `.venv/bin/python tools/new_func.py --next` lists small undone functions. Choose one in your
   lane and comment on the pinned **Active claims** issue: `/claim 0x00112345` (up to 3 open claims, 0x2000 bytes
   each; claims lapse after 7 days). Someone else's claim wins.
2. **Draft.** `.venv/bin/python tools/new_func.py func_00112345` writes an m2c draft (C) to
   `src/funcs/func_00112345.cpp` and tries it. Turn it into C++: usually a member function of a class declared in
   `include/game/`, with `this` in `$a0`.
3. **Iterate.** `.venv/bin/python tools/match.py func_00112345 --show` until it prints `MATCH`. Fix types, declare
   structs/classes, reshape expressions; see the matching guide. Per-file flags go on the **first line**:
   `/* cflags: -O1 */` (allowed list in `toolchain/compiler.toml`).
4. **Permute near misses** (C-compatible units only): `.venv/bin/python tools/permute.py func_00112345 --run -j2`.
5. **Check locally, exactly as the judge will:**
   ```sh
   .venv/bin/python tools/scan.py && .venv/bin/python tools/gate.py && .venv/bin/python tools/build.py
   ```
6. **Give up cleanly.** After two focused attempts on a small function (about 15 compiles) or 25 on a large one,
   delete the file, keep your near miss under `work/` (git-ignored) with a note on the remaining difference,
   `/unclaim`, and move on.
7. **Open a PR** from a branch with your lane prefix, at most 20 functions. **The PR body must be the template**:
   ```sh
   cp .github/pull_request_template.md work/pr.md   # fill in the table, tick the boxes, name the agent
   gh pr create --base main --title "Match N functions from ..." --body-file work/pr.md
   ```
   `gh pr create --body "..."` skips the template and Steward reads the exact box text (`Own work:`,
   `No leaked material:`, `No game data:`, `Lawful decompilation:`, `Sources listed:`, one "who made this" box,
   and `Agent acknowledgement:` for agents). Use `gh api -X PATCH repos/.../pulls/N` to edit a PR body
   (`gh pr edit` breaks).

## Hard rules (the scan and match gates enforce most of them)

- **Plain C++ only.** No `asm`/`__asm__`, register pinning, `.set noreorder`, `#pragma`, `INCLUDE_ASM`.
- **No string literals.** The game's strings stay in its `.rodata`: `extern char D_0035AC80[];`.
- **No hard-coded addresses** inside the image (`0x00100000`–`0x00468C30`): use the symbol (`D_00393E80`,
  `func_00100030`). Hardware registers (`0x10000000`…, `0x12000000`…) and scratchpad (`0x70000000`) are fine.
- **One function per file.** No other out-of-line function (helpers must be `static inline` and fully inlined), no
  data of the unit's own: globals, vtables, jump tables stay in the asm and are referenced with `extern`.
  Float literals are fine: `tools/cc.py` points them at the game's own `.lit4` constants when the bytes agree.
- **Calling a function nobody has decompiled:** declare it `extern "C"` with its `func_` name and pass `this`
  explicitly, e.g. `extern "C" void func_00243A58(void* self);`. Once the callee is a C++ unit, keep the call as is.
- **Never edit protected paths:** `tools/`, `config/`, `toolchain/`, `include/` (except `include/game/`), `tests/`,
  `configure.py`, `steward.toml`, `.github/`, or the docs. If the toolchain is wrong, open a `tooling` issue with a
  minimal repro (a `.cpp` plus `match.py --show` output).
- **Shared types** go in `include/game/*.h`. A change there re-checks every merged unit.
- **Names need a reason** from the binary itself (an assert string like `/code/sk/objects/skater.cpp`, other
  strings, unmistakable behaviour). Never from leaked material.

## Useful facts

- C++ built with SN ProDG. `this` arrives in `$a0`; constructors return `this` in `$v0` (g++ 2.95 ABI).
- 64-bit GPRs: moves are `daddu $x, $y, $zero`; `$ra` and callee-saved registers are saved with `sd`.
- `$gp` = `0x0038F3F0`; globals of 8 bytes or less are gp-relative (`-G8`): `extern int D_00393E80;`.
- Float constants live in `.lit4` (`0x00387400`–`0x00388258`), one copy per use; write them as literals.
- `sqrt.s` comes from `sqrtf()` (declare `extern "C" float sqrtf(float);`, `-ffast-math` is pinned).
- VU0 macro-mode code (`vaddax`, `vdiv`, `qmfc2`…) was inline asm in the original: such functions stay asm.

## Matching findings (proved on merged units)

- **Compare sizes first.** If `match.py` says `size 0x.., want 0x..`, the structure is wrong; don't permute.
- **Evaluation order shows in the schedule.** A value the original computes early (a `sqrtf`, a sum) is usually its
  own statement in the source: `func_00100118` only matched once `float s = sqrtf(1.0f - x);` was hoisted.
- **Scheduler-only differences are not worth chasing**: log them in your PR notes and move on.

## Clones: one source, many functions

`tools/clones.py` lists unmatched functions whose normalised instructions are identical to a matched unit
(`func_A -> func_B func_C ...`), and with `--unmatched-groups N` groups of N+ identical functions nobody has
matched yet (match one, adapt it to the rest). Use `--lane LO HI` for your range. Adapt the source (class,
callee and global names per address) and run `match.py` on every copy: a clone is a hint, not a match.
