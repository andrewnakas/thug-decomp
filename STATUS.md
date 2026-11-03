# Status

## 2026-11-03: project started

- Disc verified (ISO sha1 `b1c7b98412ce6921ea97af48627f0fd81ba0ec64`, ELF sha1 `ffefbe60…`).
- splat split: 11,553 entries in `.text`, of which 11,438 are functions and 115 are unreferenced SN linker fill.
  142 VU0 macro instructions are emitted as `.word`.
- The all-asm build is byte-identical (`SLUS_207.31: OK`).
- The compiler is pinned to SN ee-gcc 2.95.3 build 1.36, `-O2 -G8 -ffast-math -fno-exceptions`
  (docs/COMPILER_ID.md).
- First 4 C++ matches: func_001000D0, func_00100118, func_0015A138, func_00243A58. The whole ELF still rebuilds
  byte-identical, and objdiff scores each unit at 100%.

## Open tooling items

- Library identification (`config/lib_ranges.us.csv`): tag the Sony SDK 2.8 libs, OpenSSL, GameSpy and libgcc so
  they leave the denominator. Right now every function counts as game code.
- Jump tables and per-function `.rodata` (a `switch`, a vtable a unit owns): the gate rejects them for now.
- `-G4` vs `-G8` is still undecided (no discriminating function seen yet).
