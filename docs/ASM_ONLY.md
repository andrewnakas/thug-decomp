# Game functions kept as asm (no C++ equivalent)

Every other game function in `config/functions.us.csv` has C++, either an exact match in `src/funcs/` or
equivalent code in `src/nonmatching/`. These stay as the game's asm because they were written in asm (or
VU0 macro-mode inline asm) in the original, which plain C++ cannot express: interrupt control (`ei`/`di`/`sync`),
system calls, VU0 vector instructions, or hand-scheduled nop padding.

| Function | Size | Why |
|---|---|---|
| func_0010ED38 | 0x108 | hand-written stub / nop padding |
| func_0010F8B8 | 0x28 | interrupt control (ei/di), sync |
| func_00112048 | 0xe0 | interrupt control (ei/di), sync |
| func_001154D0 | 0x174 | VU0 macro mode |
| func_0011E278 | 0x20c | VU0 macro mode |
| func_0011E4A8 | 0x310 | VU0 macro mode |
| func_00121200 | 0x338 | VU0 macro mode |
| func_0012A138 | 0xa14 | VU0 macro mode |
| func_00164920 | 0x1a8 | interrupt control (ei/di), sync |
| func_00164AC8 | 0x250 | interrupt control (ei/di), sync |
| func_0016B8B8 | 0x9b4 | interrupt control (ei/di), sync |
| func_0016C940 | 0xca4 | VU0 macro mode |
| func_0016F050 | 0xb80 | VU0 macro mode |
| func_0016FBD0 | 0x124 | VU0 macro mode |
| func_0016FCF8 | 0x2f0 | VU0 macro mode |
| func_00172340 | 0x20 | hand-written stub / nop padding |
| func_00172360 | 0x1c | hand-written stub / nop padding |
| func_0017CD90 | 0x6a8 | VU0 macro mode |
| func_001E26E8 | 0x12c | interrupt control (ei/di), sync |
| func_001E2840 | 0x3c | interrupt control (ei/di), sync |
| func_001E2880 | 0x28 | interrupt control (ei/di), sync |
| func_001F77B0 | 0x1bc | interrupt control (ei/di), sync |
| func_001F7970 | 0x40 | interrupt control (ei/di), sync |
| func_00267538 | 0x1a0 | VU0 macro mode |
| func_002CE628 | 0x148 | interrupt control (ei/di), syscall |
| func_002CE770 | 0x8 | hand-written stub / nop padding |
| func_002CE778 | 0x34 | syscall |

27 functions, 0x4d64 bytes.
