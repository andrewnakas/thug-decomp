# Compiler identification (2026-11-03)

**Result:** SN Systems ProDG ee-gcc 2.95.3, "GNU C++ version 2.95.3 SN BUILD 1.36 for Playstation2 (ee)",
assembler GNU as 2.9-ee-991111b, flags `-O2 -G8 -ffast-math -fno-exceptions`. decomp.me id `ee-gcc2.95.3-136`.

## Evidence

| Observation | Where | Conclusion |
|---|---|---|
| `.DVP.overlay..*` sections, `.mdebug.eabi64`, e_flags `noreorder, 5900, eabi64, mips3` | ELF headers | SN ProDG toolchain (dvp-as), EABI64 |
| `daddu $x, $y, $zero` moves, functions aligned to 8 (`.align 3`) | everywhere | EE gcc 2.9x |
| float constants loaded `lwc1 %gp_rel(...)` from `.lit4`, not merged even within one function | func_00100118 | gcc 2.95 `li.s` + SN as, `-G` ≥ 4 |
| no `.eh_frame`/EH CIE records anywhere in the file | whole ELF | `-fno-exceptions` |
| `sqrt.s` emitted inline for `sqrtf` | func_00100118 | `-ffast-math` |
| **`sd $ra` / `ld $ra`** in a non-leaf with a 0x20 frame | func_001000D0 | **only SN 1.36** does this; 2.95.3-114, 2.95.3-107, 2.95.2-274 and 2.95.2-273a all save `$ra` with `sq`/`lq` |

All five SN candidates produce identical code for the other seed functions (func_00100118, func_0015A138,
func_00243A58), so func_001000D0 is the one that decides. `-G4` and `-G8` are indistinguishable so far
(no 5..8-byte global has been seen accessed gp-relative yet); `-G8` is SN's usual default. Revisit if a function
disagrees.

## Reproduce

```sh
for c in ee-gcc2.95.3-136 ee-gcc2.95.3-114 ee-gcc2.95.3-107 ee-gcc2.95.2-274 ee-gcc2.95.2-273a; do
  .venv/bin/python tools/match.py func_001000D0 --compiler $c   # only 136 prints MATCH
done
```

(The other candidates are listed in `toolchain/compiler.toml`; install them by extracting their archives into
`toolchain/compilers/` the same way `toolchain/setup.py` installs the pinned one.)
