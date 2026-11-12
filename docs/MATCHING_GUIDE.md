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

## Findings from batches 4-6 (PRs #12-#17)

- **Variable-bit tests:** `int mask = 1 << n; return (m & mask) != 0;` gives the game's `sllv; and; sltu`;
  writing `(m & (1 << n)) != 0` directly gives `srav; andi 1`.
- **`bool` is 4 bytes.** `lw; xori 1; sltu; sw` is `b ^= true;` (`b = !b` gives only the `xori`).
- **`volatile` globals:** an `ld` left out of the delay slot, or `lw` + `dsll32/dsrl32` zero-extension, is a
  `volatile` global.
- **Indexing order:** `T* p = m_items; p += i; return p->m;` when `p[i].m` puts the `addu` operands the other way.
- **`char buf[1024]` locals** explain 0x410 frames (format-then-print helpers).
- **Script commands:** `bool Cmd_X(void* params, void* script) { ...; return true; }` free functions; identical
  bodies need distinct names.
- **Uninitialised out-params:** no `sw $zero` before a getter call means `int v; get(params, 0, &v, 1);`.
- **A `sw $a1, 0($sp)` in a leaf then the same value stored to a field** is a temporary bound to a `const T&`
  parameter of a `static inline` helper.
- **Code after a `beqz` landing point runs on both paths**: only what precedes it belongs inside the `if`.
- **`1.0f / 60.0f`** folds to the .lit4 constant 0x3C888889.

## Switch statements (jump tables)

Write the `switch` normally. `tools/cc.py` compiles the unit once, reads where each entry of the compiler's local
jump table lands in the function, and compares that with the game's `jtbl_XXXXXXXX` table (in the same order the
original function references its tables). Only if every entry lands on the same offset does it point the
`%hi/%lo` at the game's table and drop the local one; otherwise the unit keeps its own `.rodata` and the gate
rejects it (`has its own .rodata`). So a rejected switch means the case layout differs: check the case order
against `asm/data/rodata.rodata.s` (`dlabel jtbl_...`) and spell out every case, including empty ones.
Example: `src/funcs/func_002BA688.cpp`.

## Findings from lane 3 batches 11-12 (medium functions, switches)

- **A callee's declared return type changes codegen even when the result is ignored**: declaring it `int`/`void*`
  instead of `void` fixes `$v0`/`$v1` choices and the `$a0`/`$a1` order in a call's delay slot.
- **Timeouts** keep the constant in a register only through an inline helper:
  `static inline bool Elapsed(int ms, int now, int start) { return now - start > ms; }`.
- **Cross-jumped calls:** write the same call in every `case`; gcc merges them into the game's single shared call.
- **Block order:** a `goto` into another case's block, or falling through from a case's `if`, reproduces layouts
  that structured code cannot.
- **Several switches in one function** are supported (each table is checked separately).

## Types and tables (lanes' large-function rounds)

- **`long` is the 64-bit type** (`ld`/`sd`); `long long` is 128-bit on this compiler (`lq`/`sq`, or
  "unsupported wide integer operation"). Bit fields over 64-bit registers: `unsigned long` members.
- **A jump table starting at index 0 needs an explicit empty `case 0:`**; every index the table covers must be a
  `case` (empty ones fall to the shared exit), or gcc emits a compare chain.
- **Declare callees with their real return type** (`int`, `void*`, `bool`) even if the result is ignored: it
  decides `$v0`/`$v1` and delay-slot order.
- **No dead statements.** A bare `m_count;` or a no-op assignment kept only to steer the compiler is not allowed;
  if nothing else works, leave the function for later.
- `tools/permute.py NAME --src work/draft.cpp --out work/perm/NAME` permutes a draft outside src/funcs.

## Stack objects (iterators, scoped helpers)

- When an inline ctor/method runs on a *local* object, gcc folds `this` to the frame address and stores come out
  as `off($sp)`. The game's form (stores through `$sN`, calls with `daddu $aN, $sN`) comes from a named pointer:
  `T* p = &obj;` and all stores/calls through `p` (or inline helpers on `p`). The field at +0 still folds to
  `X($sp)`; declaration order sets the stack layout.
- **One-register iterator:** Node gets `Valid()` (returns `this` or 0) and `GetData()`; the iterator gets
  `Next() { cur = cur->next->Valid(); if (!cur) return 0; return cur->GetData(); }` and
  `First(h) { cur = h; return Next(); }`.
- **Copy-register form (`daddu $sN, $sp, $zero`):** add `Advance(Node* c)` and write the loop as
  `if (d) { It* p = &it; do { ...; d = p->Advance(it.cur); } while (d); }`.
- Hardware addresses such as the scratchpad (`(Mat*)0x70003FC0`) are fine as constants.


## Findings from the 2026-11-05 rounds (all lanes)

- **Compare against a register known to hold 0** (`sltu v1,a1,v1` where `$zero` would do): write the test as an
  unsigned less-than against an inline's unsigned parameter that defaults to 0, e.g.
  `Node* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }`. A literal 0 is folded away before RTL.
  Use the same helper at every call site (func_002D1390, func_00272300).
- **Virtual call register pair:** vptr in `$v1` and function in `$v0` means the virtual returns a value; declare it
  `int` or a pointer. A `void` virtual gives the swapped pair. Declaring an ignored callee result as `int` fixes many
  argument-order ties too.
- **Loop bound reloaded every pass:** read it through an inline getter (`unsigned GetSize() { return m_size; }`).
- **Array of structs:** `(base + i)->field` gives the game's single induction variable; `base[i].field` may not.
- **Store order:** with several stores through one base, the game's first store is usually the source's last.
- **Unrotated top-tested loop:** `do { if (!c) break; ... } while (1);`.
- **Allocation:** an inline class `operator new` / `new[]` reproduces the game's alloc-then-construct calls.
- **`.lit4` floats** that are not round need enough digits to hit the exact bits (`3.141593f` = 0x40490FDC).
- **Busy-waits** (empty loops that re-read a volatile field or call a function) are real code and are fine. Dead
  stores, ignored-result calls and bare reads kept only to steer the compiler are not.
- **The permuter** (`tools/permute.py`) now takes units with `extern "C"`, bare struct names, bool literals and
  128-bit typedefs. Units with member functions still need a C-style copy with an explicit self pointer.
- **Diagnosing a register swap:** compile once with `-dl -dg` (in work/) and read the pseudos' use counts and live
  lengths: allocation priority is roughly uses × log2(uses) / live length, and ties go to the lower register number.
  Shortening or lengthening one temporary's live range (pass `x * 0.5f` directly instead of naming it) often flips it.
- **Registers for hoisted global addresses** are ordered by gcse in the order the expressions first appear (and, for
  ties, by a hash of the symbol name), not by `extern` declaration order.
- **Dead divide traps:** a `beql reg,$zero; break 0,7` with no `div` is a division whose result was optimised away;
  two orphaned `li` of the same constant mean a divide-and-modulo pair. Reproducing that never-read pair is allowed
  only with a comment citing the trap as evidence.
- **Jump-table switches:** an empty case is fine where the table or the compare tree proves it existed; never invent
  a case value that the binary does not show.
- **Check callee arity first:** before chasing a register swap, read the callee's asm for its real argument count and
  return type. A bogus `this`, a missing argument or a constructor declared `void` shifts live ranges everywhere.
- **addu operand order:** a member array `m[i]` gives `addu base, idx`; a pointer `p[i]` gives `addu idx, base`.
- **Loop direction:** `for (i = 0; i < n; i++)` becomes a reversed `bnez` loop with a counter copy;
  `for (; n > 0; n--)` gives `bgtz`. The polarity of `?:` picks `movn` vs `movz`.
- **Not every swap is allocation:** many near misses are sched1/sched2 order, gcse/CSE merging or loop hoisting.
  `-fno-schedule-insns` (diagnostic only) tells you quickly whether scheduling is the cause.
- **Volatile reloads with an unused result:** when the game's binary itself reloads a volatile field after updating
  it (e.g. `lw` of a request counter after `++m34`, value never used), reproduce it with a plausible inline accessor on
  the class (`int NextId() { return ++m_34; }`, called as `s->NextId();`), used the same way across the family. Bare
  expression statements, comma tricks and ignored reads of non-volatile data remain banned.

## Findings from the 2026-11-12 rounds (lane 3)

- **Cross-jumping as an allocation lever:** writing a shared tail twice (a `case`'s if/else arm that repeats another
  case's body) adds uses before register allocation; gcc merges the copies afterwards. Case order decides which copy
  survives, and with it the block layout (func_002A7A08). This replaces a `goto` into another case.
- **Stopping an unwanted if-conversion:** where the game keeps `beqz` with 0 in the delay slot, gcc may rewrite
  `ret = 0 / ret = load` as `ret = 0; if (c) ret = load;`. An extra inline return layer (`Node::Data()` called
  from `Iter::Advance`) stops it (func_002B5278, func_002D5F80).
- **Top-tested inner loop:** g++ rotates a loop only when its first conditional jump goes to the loop end; write
  `for (int j = 0; ; j++) { ... if (v) { ... } else break; }` to keep the test at the top (func_002B8018).
- **Signatures are behaviour:** check each callee's real return register. strcpy-like callees return `char*` in
  `$v0`; a callee returning 0/1 in `$v0` must not be declared `float` (that tested `$f0`).
- **Parameters = what callers pass.** If the game's call site loads an argument register before the call, declare
  that parameter even when the callee ignores it, with a comment citing the call site. Never invent one no caller sets.

## Explaining scheduling and allocation ties (`sched_explain.py`, `regalloc_explain.py`)

Two diagnostics read cc1plus's own dumps so you do not have to. Both compile the unit exactly as `cc.py` does
(pinned cflags + the unit's `/* cflags: */`) plus dump flags, in a private `build/explain_*` directory (`--keep DIR`
keeps the dumps), map every word of our function to its RTL insn (`-dp` + a label per insn, checked against
match.py's object), and diff against the game.

- `tools/sched_explain.py NAME [--src F] [--pass 1|2] [--block N] [--all] [--why A B] [--keep DIR]`
  (`-dN -dS -dR -fsched-verbose-5`). Without `--block` it shows the blocks that hold the first differing words,
  sched1 and sched2: the dependence table, then every cycle's ready list best first with gcc 2.95's
  `rank_for_schedule` keys (priority, register weight [sched1], class relative to the last scheduled insn,
  dependents, luid), what was issued, and the first key that puts each candidate below the one above.
  `--why A B` names the key that orders two insns (uids from the tables or the word listing), or says they were
  never ready together (dependences/latency decide, not ranking). A `luid` decision is a pure source-order tie:
  swap the statements. Each block ends with a model check against the order the compiler printed; sched2 agrees
  everywhere we measured, sched1 on ~99% of pairs (the rest, flagged `!!`, are unexplained priority inversions in
  float/TImode-heavy blocks: trust the dump order there).
- `tools/regalloc_explain.py NAME [--src F] [--pseudo N] [--no-local] [--keep DIR]` (`-dl -dg`). Lists global
  allocation in find_reg order with refs, live length, priority (`floor_log2(refs)*refs/live*size`; ties go to the
  lower pseudo number, i.e. the value created first), calls crossed, conflicts, preferences and the register it
  ended with; checks that order against the `.greg` dump; lists local-alloc's per-block choices; then, at each
  differing word that is the same instruction with other registers, names the pseudo and why it missed the game's
  register: lost to an earlier conflicting pseudo (priority or tie), a local pseudo or hard register live across
  it, a call it crosses, local-alloc tying a result to a dying source (`combine_regs`), or a `(clobber (scratch))`
  that reload fills after allocation. REG_EQUIV pseudos (constants, stack arguments) show `EQUIV`: their live
  length was doubled, so they go late.

Dump flags this cc1plus accepts: `-dN -dS -dl -dg -dR -dp`, `-fsched-verbose-N` (not `-fsched-verbose=N`). None
of them changes the code. The tools never touch `src/` and are safe to run beside other agents (one compile each).

## `-mno-split-addresses` (allowed per file since 2026-11-12)

The Ratchet & Clank 3 decomp, built with the same SN 1.36 compiler, found that this flag was set per source file in
the original builds: it changes how global addresses are formed (`lui`/`addiu` pairs vs. split `%hi`/`%lo` uses).
A sweep of all 460 nonmatching units found no new exact match, but 27 units got closer, notably func_002D41E0
(544 -> 275 differing words), func_00116A48 (821 -> 656), func_00189750 (235 -> 173), func_001D4648 (52 -> 31) and
func_001538C8 (20 -> 11). Try it as `/* cflags: -mno-split-addresses */` when the game loads a global's address as a
whole and you get split loads. Neighbouring functions from one source file should share the flag.
