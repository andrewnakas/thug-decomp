# Tony Hawk's Underground (PS2) decompilation

![Code](https://bytematch.dev/andrewnakas/thug-decomp.svg?label=Code&measure=matched_code_percent)
![Functions](https://bytematch.dev/andrewnakas/thug-decomp.svg?label=Functions&measure=matched_functions)

A matching decompilation of **Tony Hawk's Underground** (Neversoft / Activision, 2003, PlayStation 2, NTSC-U
`SLUS-20731`). The game's C++ is being written back function by function until it compiles to the original
boot ELF byte for byte.

**Bring your own disc.** This repository contains no game code or data. You need your own legally owned copy of
the game, dumped yourself, to build or check anything. **The leaked THUG source code is off limits**: see
[PROVENANCE.md](PROVENANCE.md).

## Status

| | |
|---|---|
| Target | `SLUS_207.31` (sha1 `ffefbe60ba0a1d7f27264bc1be6782f6bfc22985`), main segment at `0x00100000`, `$gp = 0x0038F3F0` |
| Compiler | SN Systems ProDG **ee-gcc 2.95.3, SN BUILD 1.36** (`cc1plus`), `-O2 -G8 -ffast-math -fno-exceptions`, run under [wibo](https://github.com/decompals/wibo) (pinned in `toolchain/compiler.toml`; how it was identified: [docs/COMPILER_ID.md](docs/COMPILER_ID.md)) |
| Split | 11,438 functions (2.37 MB of `.text`) via [splat](https://github.com/ethteck/splat) + [spimdisasm](https://github.com/Decompollaborate/spimdisasm) (R5900) |
| Build | The full ELF rebuilds byte-identical from C++ + asm (`SLUS_207.31: OK`) |

Progress is tracked on [bytematch.dev](https://bytematch.dev/andrewnakas/thug-decomp).

**Joining (human or AI agent)? Read [START_HERE.md](START_HERE.md).**

## Quick start (Linux, no root needed)

```sh
git clone https://github.com/andrewnakas/thug-decomp && cd thug-decomp
ln -s "/path/to/Tony Hawk's Underground (USA).iso" disc/     # your own dump, git-ignored
python3 toolchain/setup.py                  # SN compiler, wibo, binutils, objdiff, m2c, permuter, .venv
.venv/bin/python tools/extract_disc.py      # verifies the disc, extracts SLUS_207.31 (OK: 31 files match)
.venv/bin/python tools/split.py             # splat: asm/ and the function table
.venv/bin/python configure.py && .venv/bin/ninja   # -> SLUS_207.31: OK
```

## Working on a function

```sh
.venv/bin/python tools/new_func.py --next            # small functions nobody has done yet
.venv/bin/python tools/new_func.py func_00112345     # m2c draft -> src/funcs/func_00112345.cpp
.venv/bin/python tools/match.py func_00112345 --show # side by side, !! marks differences
.venv/bin/python tools/permute.py func_00112345 --run -j4   # near misses: decomp-permuter
.venv/bin/python tools/scan.py && .venv/bin/python tools/gate.py && .venv/bin/python tools/build.py
```

Then open a pull request using the template. Claim first: comment `/claim 0x00112345` on the pinned
**Active claims** issue. See [AGENTS.md](AGENTS.md), [RULES.md](RULES.md), [PROVENANCE.md](PROVENANCE.md) and
[docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md).

## How merges work

[Decompathon Steward](https://github.com/andrewnakas/decompathon-steward) runs on the maintainer's machine,
which has the disc. **No AI is involved in merging.** For every PR, Steward checks out `main`, copies in only
the PR's `src/funcs/` files, and runs five deterministic gates:

| Gate | Tool | Checks |
|---|---|---|
| toolcheck | `tools/toolcheck.py` | the toolchain is the pinned one (sha256 + canary compile) |
| scan | `tools/scan.py` | plain C++ only: no inline asm, register pinning, `#pragma`, string literals, hard-coded addresses |
| split | `tools/check_split.py` | the split tiles `.text`, every function ends properly, splitting is deterministic |
| match | `tools/gate.py` | every unit matches instruction for instruction, defines one function, owns no data |
| build | `tools/build.py` | the whole ELF is byte-identical (sha1), and objdiff independently agrees |

Public CI (GitHub Actions) runs the checks that need no disc: lint, scan, tests, a compile of every unit, and
the progress report that ByteMatch reads.

## How the PS2 pipeline works

- `tools/cc.py` runs SN's own `ee-gcc.exe` driver under wibo, so cpp, `cc1plus` and SN's `as` (GNU as
  2.9-ee-991111b) get exactly SN's flags. Float literals (`li.s`) are pointed at the game's own `.lit4`
  constants when the bytes agree, and SN objects get their symtab/ABI header fixed so modern ld can link them.
- splat's asm is assembled by GNU as with `-march=r5900 -mabi=o64`. The 142 VU0 macro-mode instructions GNU as
  cannot encode are emitted as `.word` by `tools/split.py` (the mnemonic is kept in a comment).
- `configure.py` pins every function object at its original address; `tools/link.py` splices the ELF header,
  the linked main segment and the ELF tail (DNAS blob, section headers; both from your disc) and checks the sha1.

## Layout

```
config/       splat yaml, symbol files, function table, checksums, split exceptions
src/funcs/    one matched function per file: func_XXXXXXXX.cpp
include/      common.h; include/game/ for shared class and struct headers
tools/        the build and every gate
toolchain/    compiler.toml (the pinned pipeline), checksums.sha256, setup.py
configure.py  writes build.ninja + the link script (every object pinned to its address)
```

## Credits

Built on [splat](https://github.com/ethteck/splat), [spimdisasm](https://github.com/Decompollaborate/spimdisasm),
[rabbitizer](https://github.com/Decompollaborate/rabbitizer), the [decomp.me compilers](https://github.com/decompme/compilers),
[wibo](https://github.com/decompals/wibo), [m2c](https://github.com/matt-kempster/m2c),
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) and [objdiff](https://github.com/encounter/objdiff).
The project structure follows the [THPS N64 decomp](https://github.com/andrewnakas/thps64) and the
[Thrasher PS1 decomp](https://github.com/andrewnakas/thrasher-skate-decomp).

The code in this repository is released under CC0 (see [LICENSE](LICENSE)). Tony Hawk's Underground is © its
respective owners; this project is not affiliated with or endorsed by them.
