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
| `lq`/`sq` 16-byte moves | a 16-byte struct copy: `typedef int qword __attribute__((mode(TI)));` in a union with `struct { float x, y, z, w; }` (gives 16-byte alignment; `aligned()` is rejected by scan) |
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

## Findings from the first batches (lanes 1-3, PRs #2-#4)

- **`-fopt-stack` is global** (now pinned): without it a non-leaf saving `$s0` gets a 0x20 frame with `sq`;
  the game uses a 0x10 frame with `sd $s0, 0($sp)` / `sd $ra, 8($sp)`.
- **Store order:** several stores through one base come out with the *last* source store first (often in a
  delay slot). Write them in field order first; if the game's order is A,B,C,D try D,A,B,C.
- **Float register choice follows local declaration order** (`float nx = -x; float nz = -z;`).
- **`0xFFFFFFFF` (lui/ori) is an unsigned constant; `addiu -1` is `int -1`.** Same for masks: `&= ~1` on an
  `int` gives `addiu -2`, on an `unsigned` gives `lui/ori 0xFFFE`.
- **`m = g; g = g + 1;`** keeps the increment in its own register; `m = g++` does not match.
- **Small extern arrays go gp-relative only with a size:** `extern unsigned int D_00391D68[1];`.
- **g++ 2.95 vtables:** the vptr follows the fields of the class that first declares a virtual; each slot is
  8 bytes (`lh` delta at off, `lw` function at off+4), the first virtual is at vtable+8.
- **Constructors/destructors of derived classes:** write the real class hierarchy; map the mangled base-ctor and
  vtable names the compiler references (`__1B`, `_vt$1C`) to their addresses in `include/game/cxx_symbols.txt`
  (`match.py --show` prints the names). The gate checks every entry.
- **A trailing `move $v1, $v0` before a store** means the function also returns the stored value.
- **An `$a1` that survives into a call** is a forwarded argument.
- **Fill:** `addiu $sp, $sp, +N; nop` pieces between functions are SN linker leftovers (kind `fill` in the
  table, not targets). `tools/find_fill.py` splits real functions out from behind them.
