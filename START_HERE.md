# Start here: joining the THUG decomp (agents and humans)

One page to go from a fresh machine to your first merged function. The details live in [AGENTS.md](AGENTS.md);
read it before your first PR.

## What you need

1. **Linux x86_64** (or WSL2), Python 3.11+ with `venv` (Ubuntu: `sudo apt install python3-venv`, or have `uv` installed), git, `gh` logged in, and about 3 GB of free disk. `setup.py` was verified from a fresh clone on 2026-11-03.
2. **Your own dump of the game**: Tony Hawk's Underground (USA), `SLUS-20731`, as a `.iso` DVD image. The repo
   contains no game data and nobody will send you any. The tools verify the dump by checksum.
3. **Your own GitHub account.** Claims belong to accounts.

## Setup (about 10 minutes)

```sh
git clone https://github.com/andrewnakas/thug-decomp && cd thug-decomp
ln -s "/path/to/Tony Hawk's Underground (USA).iso" disc/   # git-ignored, never committed
python3 toolchain/setup.py                  # SN compiler + wibo, binutils, objdiff, m2c, permuter (no root)
.venv/bin/python tools/extract_disc.py      # must end with: OK: 31 files match
.venv/bin/python tools/split.py
.venv/bin/python configure.py && .venv/bin/ninja   # must end with: SLUS_207.31: OK
```

If any step fails, open an issue with the "Build or setup problem" template. Never attach game files.

## Your first function

1. Look at the pinned **Active claims** issue and pick an address range nobody holds.
   `.venv/bin/python tools/new_func.py --next` lists small undone functions. Claim with `/claim 0x00112345`.
2. Follow the loop in [AGENTS.md](AGENTS.md#the-loop-per-function): `new_func.py` → `match.py --show` → fix the
   C++ → `scan.py`, `gate.py`, `build.py` all pass.
3. Open a PR from a branch, with the template as the body (`--body-file`), at most 20 functions.

**Your first PR waits for the maintainer** (the `judge-ok` label). After one merged PR, Steward judges and merges
automatically.

## Paste this to your agent

> You are contributing to a matching decompilation of Tony Hawk's Underground (PS2) at
> https://github.com/andrewnakas/thug-decomp. Read START_HERE.md, then AGENTS.md, then docs/MATCHING_GUIDE.md,
> and follow them exactly. Never open or search the leaked THUG source code. Set up the repo as START_HERE.md
> says (my disc image is at `<PATH TO .iso>`) and confirm the build prints `SLUS_207.31: OK`. Then work
> continuously: claim an unclaimed address range on the Active claims issue, match functions one at a time with
> tools/new_func.py and tools/match.py, check each with tools/scan.py, tools/gate.py and tools/build.py, and
> open PRs of up to 20 matched functions using the PR template. Plain C++ only: no inline asm, no register
> pinning, no string literals, no hard-coded addresses, no edits outside src/funcs/ (plus include/game/ for
> shared types). If a function doesn't match after two focused attempts, drop it, note why in work/, and move on.
