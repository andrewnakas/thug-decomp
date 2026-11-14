# Status

## 2026-11-14: close-out

| | Functions | Share of game code |
|---|---|---|
| Exact match, plain C++ (`src/funcs/`) | 8,857 | **81.21%** |
| Exact under recorded compiler decisions (`src/concession/`) | 89 | +4.02% (**85.23%** together) |
| Equivalent C++, not byte-exact (`src/nonmatching/`) | 250 | fuzzy total **98.58%** |
| Left as assembly (docs/ASM_ONLY.md) | 7 | |

- The matching build is byte-identical (`SLUS_207.31: OK`); every gate passes on `main`.
- The functional build runs every concession and non-matching unit's C++ in place of the game's code. It boots and
  plays into New Jersey in PCSX2 with frames matching the original (checked 2026-11-13 and 2026-11-14 by booting the
  original and the functional build back to back).
- What is left, unit by unit, and why each one does not match: [docs/REMAINING.md](docs/REMAINING.md).

## History

| Date | Milestone |
|---|---|
| 2026-11-03 | Project started. Disc verified (ISO sha1 `b1c7b98412ce6921ea97af48627f0fd81ba0ec64`, ELF sha1 `ffefbe60…`); splat split 11,438 functions and 115 linker-fill fragments; the all-asm build is byte-identical; the compiler identified as SN ee-gcc 2.95.3 build 1.36 (docs/COMPILER_ID.md); first 4 C++ matches. By the end of the day: 203 PRs merged, 33.8% of code bytes. |
| 2026-11-05 | 53.7% after three Claude lanes and Steward merging around the clock. |
| 2026-11-06 | **Every game function has C++**: exact or `src/nonmatching/` (equivalent, scored, never linked), except the asm-only list. 73.96% exact, 92.93% fuzzy. |
| 2026-11-12 | Fuzzy push starts (75.44% exact, 94.48% fuzzy). Functional build and PCSX2 boot test added; ten real behaviour bugs in non-matching units were found by booting and fixed. |
| 2026-11-13 | Decision oracle (`tools/oracle.py`): SN's stripped `cc1plus.exe` driven under gdb at hook points recovered from the binary, able to force decisions. Every residue classified (A reachable tie, B code shape, C compiler-internal order). 80.82% exact, 98.44% fuzzy. |
| 2026-11-13 | **Concession tier** (owner ruling): units that match exactly under recorded forced decisions. Force kinds `ga`, `la`, `sched` (with replay and two-slot picks), `spill`, `fr`, `lfr`, `reorg`, `cprop`; directed search (`tools/oracle_directed.py`) sweeps every unit. 89 units. |
| 2026-11-14 | GameCube retail build measured as a shape reference: pairs reliably, but shows no structural error in the remaining drafts (docs/REMAINING.md). Close-out: fuzzy labels re-scored, docs updated, stale branches removed. |

## Tooling items resolved since the start

- Library identification: `config/lib_ranges.us.csv` tags the Sony SDK and GameSpy code (974 and 1,104
  functions), which leaves the denominator.
- Jump tables: `tools/cc.py` points a unit's switch table at the game's own `jtbl_` after checking every entry.
- `-G8` is pinned (`toolchain/compiler.toml`).
