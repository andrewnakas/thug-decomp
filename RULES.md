# Rules (Tony Hawk's Underground PS2 decomp)

1. One function per file: `src/funcs/func_XXXXXXXX.cpp` (uppercase hex address), defining exactly that one
   function in C++ (a member function, constructor or free function).
2. It must compile with the pinned toolchain (SN Systems ee-gcc 2.95.3 build 1.36, `toolchain/compiler.toml`)
   to the game's exact instructions, relocations included: the `match` gate. A file may ask for extra flags in a
   first-line `/* cflags: ... */` comment, but only from `[per_file].allowed_cflags`.
3. Zero loss: nothing that already matches may break, and the whole ELF must still rebuild byte-identical
   (`build` gate). Gates run on the judge box with the maintainer's disc, never on GitHub.
4. No inline asm, register pinning, `#pragma`, asm include macros or hard-coded RAM addresses (`scan` gate).
   No data of the unit's own: globals, vtables and strings stay in the asm and are referenced with `extern`.
   Float literals are fine (the toolchain points them at the game's own constants).
   **One narrow exception:** the functions listed in `config/inline_asm_allow.us.txt` (VU0 macro-mode code and
   interrupt / system-call code, see `docs/ASM_ONLY.md`) may use small inline-asm helpers. Each `__asm__`
   statement sits alone in a `static inline` helper and holds one instruction, or a fixed sequence of at most 3
   that the hardware requires together (`sync.l` + `ei`); no `.word`/`.byte`/`.half`/`.set` or other directive,
   no label, no branch or jump, no register pinning. All the logic (loops, branches, address arithmetic, loads,
   stores, calls) is ordinary C++ around the helpers. The reason: we publish our own C++, never transcriptions of
   the game's compiled code or its bytes; a helper names one hardware operation C++ has no spelling for.
   New entries (maintainer-reviewed, ruling of 2026-11-13): a function may be added to the allowlist only when
   its asm contains a hardware-only instruction with no C++ spelling (sync, ei/di, syscall, cache, COP0/COP2/VU0
   ops); the same helper rules apply, and the entry names the instruction and its address.
5. Provenance (PROVENANCE.md): every PR ticks every box. **Never use the leaked THUG source.**
6. Claim before you work (`/claim 0xADDR` on the Active claims issue). Someone else's claim wins. Claims lapse
   after 7 days without activity (reminder after 5). Touching someone's merged function: Steward asks them;
   7 days of silence means go ahead, credit kept.
7. Up to 20 functions per PR. `tools/`, `config/`, `toolchain/`, `include/` (except `include/game/`),
   `tests/`, `steward.toml`, `.github/` and these docs are maintainer-only.
8. Tick who made the PR. AI agents may contribute, but must tick every box themselves on every PR, after
   checking each against the PR's actual changes, plus the agent acknowledgement.
9. Merges are decided by deterministic gates and rules only. No AI takes part in reviewing or merging.
   Appeals: open an issue labelled `appeal`.
10. **Concession tier** (ruling of 2026-11-13). A function whose C++ matches the game exactly once a few
    compiler-internal decisions are forced (a global-alloc order, a scheduler ready-list pick, a local-alloc
    quantity order) may live in `src/concession/func_XXXXXXXX.cpp`. Each forced decision is a
    `/* force: {...} */` line in the unit; the `match` gate replays them in SN's own cc1plus under gdb
    (`tools/concession.py`) and requires a byte-exact match, and rejects a unit that matches without them.
    Every other rule applies unchanged. Concession units are never linked and are reported separately: the
    headline progress number counts only concession-free matches.
