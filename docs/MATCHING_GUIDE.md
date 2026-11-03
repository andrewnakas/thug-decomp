# Matching guide (SN ee-gcc 2.95.3 / PS2 EE)

Idioms that turn the asm back into C++ for this compiler. Add to it (maintainer PR) whenever a merged unit
proves a new one.

## Reading the asm

| You see | It is |
|---|---|
| `daddu $v0, $a0, $zero` | a move (EE gcc moves with 64-bit `daddu`) |
| `sd $ra, 0x0($sp)` / `ld $ra` | normal non-leaf prologue/epilogue |
| `lw $x, %gp_rel(D_...)($gp)` | a global of 8 bytes or less: `extern int D_...;` |
| `lui`/`addiu %hi/%lo(D_...)` | a larger global or an array: `extern T D_...[N];` |
| `lwc1 $f0, %gp_rel(D_00387xxx)($gp)` | a float literal: just write the number (e.g. `5000.0f`) |
| `lui $at, 0x3F80; mtc1 $at, $f1` | the literal `1.0f` (no `.lit4` entry) |
| `mtc1 $zero, $f0` | `0.0f` |
| `c1 0x10044` in match output (`sqrt.s`) | `sqrtf(x)` with `extern "C" float sqrtf(float);` |
| `lq`/`sq` 16-byte moves | a 16-byte struct copy (`struct Vec4 { float x, y, z, w; }`, aligned 16) |
| `ldl`/`ldr` + `sdl`/`sdr` pairs | an unaligned 8-byte struct copy |
| constructor returning `$a0` in `$v0` | `Foo::Foo()` (g++ 2.95 ctors return `this`) |
| `syscall` after `li $v1, N` | Sony kernel call stubs: library code, not a target |

## C++ specifics

- Write members as members: `int Foo::Get() const { return m_count; }`. Mangled names don't matter to the gates.
- A class with virtual functions: declare the vtable pointer as the first member yourself only if the code reads it
  explicitly; prefer declaring `virtual` methods and let the compiler lay out the object. If a unit would emit the
  vtable (it defines the class's first non-inline virtual), the gate rejects it: declare that method in the class
  but don't define it in this unit.
- Calls to functions still in asm: `extern "C" T func_XXXXXXXX(Foo* self, ...);`.
- Static helpers must be `static inline` and fully inlined, or the gate rejects the extra function.
- `bool` returns come out as `sltu $v0, $zero, $v0` after an `andi`: `return (m_flags & 4) != 0;`.

## Reshaping

- Evaluation order shows in the instruction order. Split an expression into statements to move a computation
  earlier, or merge statements to delay it.
- A register differs but the instructions are the same: try the opposite operand order (`a + b` vs `b + a`),
  a local temporary, or `x = -x` in place vs a new variable.
- Size differs: the structure is wrong (a missing `if`, a wrong loop shape, a wrong type width). Fix that first.
