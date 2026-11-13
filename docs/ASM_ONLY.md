# Game functions that use instructions C++ cannot spell

Every other game function in `config/functions.us.csv` has C++, either an exact match in `src/funcs/` or
equivalent code in `src/nonmatching/`. The functions below were written in asm, or with VU0 macro-mode inline
asm, in the original: interrupt control (`ei`/`di`/`sync`), system calls, VU0 vector instructions, or
hand-written stubs.

## The inline-asm exception (narrow, enforced by `tools/scan.py`)

We publish our own C++, never transcriptions of the game's compiled code or its bytes. So inline asm stays
banned everywhere, with one narrow exception for the 23 functions listed in `config/inline_asm_allow.us.txt`
(the table below, "helpers allowed"). In the unit of a listed function, and nowhere else:

- an `__asm__` / `__asm__ __volatile__` statement may appear **only inside a `static inline` helper
  function**, one statement per helper, as a statement of its own;
- each statement holds **one instruction**, or a short fixed sequence of **at most 3** that the hardware
  requires together (`sync.l` + `ei`); the template is split on `;` and newlines to count them;
- operands go through constraints (`"r"(ptr)`, `"=r"(value)`); VU0 registers are named in the template;
- no `.word` / `.byte` / `.half` / `.set` or any other directive, no label, no branch or jump
  (`b*`, `j*`, `eret`), and no register pinning (`register int x asm("$16")`) anywhere in the unit;
- all of the function's logic (loops, branches, address arithmetic, loads, stores, calls) is ordinary C++
  around those helpers.

Examples of allowed helpers:

```cpp
static inline void ExitHandler() { __asm__ __volatile__("sync.l\n\tei"); }   // leave an interrupt handler
static inline void DisableIntr() { __asm__ __volatile__("di"); }
static inline void LoadVF4(const void* p) { __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p)); }
static inline void MulVF6() { __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5"); }
static inline void StoreVF6(void* p) { __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory"); }
```

A function whose logic cannot be expressed as C++ around such helpers (for example a hand-scheduled block that
sets `$gp`/`$sp` itself) stays asm, and its row says why.

**Assembler.** Compiler output goes through SN's own `as.exe` (`tools/cc.py`), which encodes the VU0
macro-mode and COP2 mnemonics with the game's exact words. Its spellings: `vdiv Q, $vf1x, $vf2y`,
`vsqrt Q, $vf1x`, `vmulq.xyz $vf1, $vf2, Q`, `vmulax.xyzw ACC, $vf1, $vf2x`, `vmadday.xyzw ACC, $vf3, $vf2y`,
`qmfc2`, `qmtc2.ni`, `cfc2.ni`, `vcallms 0x458`, `vnop`, `vwaitq`, `lqc2`, `sqc2` (`$Q` / `$ACC` and `.x`
field suffixes are rejected). GNU `as` (used only for splat's asm) cannot encode them, which is why
`tools/split.py` writes them as `.word` in `asm/`; units never do.

## The functions

| Function | Size | Kind | Status |
|---|---|---|---|
| func_0010ED38 | 0x108 | hand-written stub / nop padding | permanently asm: no logic to decompile |
| func_0010F8B8 | 0x28 | interrupt control (ei/di), sync | helpers allowed |
| func_00112048 | 0xe0 | interrupt control (ei/di), sync | helpers allowed |
| func_001154D0 | 0x174 | VU0 macro mode | helpers allowed |
| func_0011E278 | 0x20c | VU0 macro mode | helpers allowed |
| func_0011E4A8 | 0x310 | VU0 macro mode | helpers allowed |
| func_00121200 | 0x338 | VU0 macro mode | helpers allowed |
| func_0012A138 | 0xa14 | VU0 macro mode | helpers allowed |
| func_00164920 | 0x1a8 | interrupt control (ei/di), sync | helpers allowed |
| func_00164AC8 | 0x250 | interrupt control (ei/di), sync | helpers allowed |
| func_0016B8B8 | 0x9b4 | interrupt control (ei/di), sync | helpers allowed |
| func_0016C940 | 0xca4 | VU0 macro mode | helpers allowed |
| func_0016F050 | 0xb80 | VU0 macro mode | helpers allowed |
| func_0016FBD0 | 0x124 | VU0 macro mode | helpers allowed |
| func_0016FCF8 | 0x2f0 | VU0 macro mode | helpers allowed |
| func_00172340 | 0x20 | hand-written stub / nop padding | permanently asm: no logic to decompile |
| func_00172360 | 0x1c | hand-written stub / nop padding | permanently asm: no logic to decompile |
| func_0017CD90 | 0x6a8 | VU0 macro mode | helpers allowed |
| func_001E26E8 | 0x12c | interrupt control (ei/di), sync | helpers allowed |
| func_001E2840 | 0x3c | interrupt control (ei/di), sync | helpers allowed |
| func_001E2880 | 0x28 | interrupt control (ei/di), sync | helpers allowed |
| func_001F77B0 | 0x1bc | interrupt control (ei/di), sync | helpers allowed |
| func_001F7970 | 0x40 | interrupt control (ei/di), sync | helpers allowed |
| func_00267538 | 0x1a0 | VU0 macro mode | helpers allowed |
| func_002CE628 | 0x148 | interrupt control (ei/di), syscall | helpers allowed |
| func_002CE770 | 0x8 | hand-written stub / nop padding | permanently asm: no logic to decompile |
| func_002CE778 | 0x34 | syscall | helpers allowed |

27 functions, 0x4d64 bytes: 23 may be written as C++ with helpers, 4 stay asm for good.
