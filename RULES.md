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
