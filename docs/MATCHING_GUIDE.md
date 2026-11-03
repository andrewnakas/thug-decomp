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

## Findings from batch 2 (PRs #5, #6)

- **Destructor mangling:** this compiler mangles `~Foo` as `_$_3Foo` (not `_._3Foo`); ctors are `__3Foo`,
  vtables `_vt$3Foo`. Use those spellings in `cxx_symbols*.txt`.
- **Derived destructors are empty:** `Derived::~Derived() {}` reproduces the game's dtor (vptr reset, `in_chrg`
  in `$a1` forwarded to the base dtor, which does the `& 1` delete). Member sub-objects are destroyed in reverse
  order with `in_chrg = 2` automatically.
- **Keep the vtable out of the unit:** if the dtor is the class's only/first non-inline virtual, the unit emits
  `.gnu.linkonce.d._vt$...` + `__tf...` and the gate rejects it. Declare another virtual *before* the destructor
  (`virtual void Update();`, never defined) so the key function lives elsewhere.
- **Components:** the shared base at 0x00184DC0 (ctor) / 0x00184DD8 (deleting dtor) has fields 0x0-0x17 and its
  vptr at 0x18. Factories call `func_001046B0(size)` (the global allocator, zeroing) and then the ctor.
- **Sub-object init order:** an inline `Identity()` call in the ctor body keeps the game's order; an inline
  sub-object ctor schedules its stores earlier.
- **Copy through a destination pointer** (`addiu $a2, $a0, 0x40` then `sq` off `$a2`) needs an inline
  `operator=` copying row by row; plain struct assignment uses direct offsets.
- **Identical functions need distinct names** (a different class/method per file), or the link sees duplicates.
- **A 1-element array loop** `for (i = 0; i < 1; i++) a[i] = 0;` reproduces a run-once count-down loop.

## Findings from batch 3 (PRs #7-#11)

- **Single-bit bool tests:** `return (m_flags & 8) != 0;` compiles to `sra` + `andi 1`. The game's
  `andi 8; sltu $v0, $zero, $v0` comes from `if (m_flags & 8) return true; return false;` (or `> 0`). For bit 0
  a plain `andi 1` is right; multi-bit masks (`& 0xC`) take `!= 0`.
- **Defining a destructor without emitting the vtable:** declare it pure with a body (`virtual ~Foo() = 0;` and
  `Foo::~Foo() {...}`) plus another virtual after it; or keep it undefined in units that only `new` the class.
- **Class `operator delete`:** an in-class `static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }`
  inlines into deleting dtors as the `& 1` pool-free branch. `delete p` on a virtual-dtor class is a slot-1 call
  with `$a1 = 3`.
- **CRC loops:** index (`data[i]`) rather than `*data++`; take a local copy of a string pointer after the null check.
- **Singleton getters** `if (!inst && create) inst = ...; refcount++; return inst;` match as written.
- **An extra `daddu $v0, $a0` before a conditional store** is an inline helper returning a pointer.
- **List append** stores `node->prev` before `node->next`.
