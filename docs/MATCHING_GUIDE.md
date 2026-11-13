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
A sweep of all 460 nonmatching units found no new exact match. Its word-count gains turned out to be
coincidental alignment where checked (func_002D41E0, func_002BD080, func_002A0840 all got worse by fuzzy score),
so judge the flag by `match.py`'s fuzzy score and by the asm itself, not by the differing-word count. Try it as `/* cflags: -mno-split-addresses */` when the game loads a global's address as a
whole and you get split loads. Neighbouring functions from one source file should share the flag.

## Where is the mismatch, and which C++ makes this asm? (`diffmap.py`, `shapedb.py`)

Two tools for large near misses whose problems are structural (loop and switch shapes, missing inlines, types).

- `tools/diffmap.py NAME [--src F] [--callsite] [--regions N] [--asm] [--html OUT] [--json OUT]` compiles the unit
  as match.py does and once more with `-g`. This cc1plus writes stabs line notes (`.stabn 68`), and `-g` does not
  change the code (shapedb's build checks it on every matched unit). A label next to each note, assembled by SN's
  own as, maps every word of ours to its C++ line. Our words are aligned with the game's the way `match.fuzzy`
  aligns them (difflib over register-free shapes), and each unaligned stretch is aligned again on opcodes. Every
  word is then `ok`, `reg` (same instruction, other registers), `diff` (same opcode, other immediate or target),
  `extra` (ours only) or `miss` (the game's only, charged to the line of our word just before it). The output is
  the source with per-line counts and a heat mark, then the worst regions, worst first: game address range, our
  offsets, the statements involved and any inlined helper lines. gcc 2.95 records no call site for inlined code,
  so its words carry the inline body's line numbers. Every listing also charges them to the calling statement
  (`<< inlined here`), and `--callsite` charges them there in the per-line counts too. `--html` writes a
  side-by-side heat view (source | aligned game/ours asm).
- `tools/shapedb.py build [-j3]` indexes every src/funcs unit into `build/shapedb/shapes.sqlite` (git-ignored;
  incremental: unchanged units are reused). It cuts each unit's game asm into basic blocks and turns every
  instruction into a register- and address-free shape token (opcode, register class arg/temp/saved/float/sp/zero,
  immediate class, memory base and offset class, relocation kind, branch direction). It stores each block and
  each window of 2–3 blocks with a MinHash/LSH signature and the unit's word → line map. Run it through
  `memgate` (`memgate --need 4 --max 8 -- .venv/bin/python tools/shapedb.py build -j3`).
- `tools/shapedb.py query NAME [--block ADDR] [--top N] [--regions N]` takes the game's words of the worst
  diffmap regions of a src/nonmatching unit, or the basic block at `--block` (that needs no unit at all). It
  prints the matched units whose blocks have the most similar shape, with their asm and the exact C++ lines that
  produced it (`[inlined]` lines come from an inline helper, `[calls inline]` is the statement that called it).
  Use it as "this idiom produced this exact code" and read the hit's source; a hit is a lead, not a recipe.
  `shapedb.py loo` runs the leave-one-out retrieval test.

What the tools measured (2026-11-12):
- **Index build.** 8,724 units in 486 s at `-j3`: 114k entries, 80 MB. For every unit, the `-g` words equal
  the game's.
- **Query.** About 2 s, most of it the compile and the alignment; `--block` alone takes well under 1 s.
- **Leave-one-out** (`shapedb.py loo --recent 10`, 584 queries of 6+ words). The top hit's C++ has the same
  shape (token similarity ≥ 0.6 after names and numbers are abstracted) in 48% of queries, and one of the top 5
  in 62% (60% when identical-asm clones are left out). For random entries of the same size the figure is 10%.
  Short, common idioms (iterators, list inserts, compare trees) are found reliably. Long, function-specific
  blocks often have no good hit.

Structural findings these tools surfaced:
- **Constant-count loops.** `-O2` does not unroll loops. When the game has a run of near-identical stores or
  calls where ours has a `for (k = 0; k < 3; k++)`, the original wrote it out (func_0014F538 40.0 → 48.2;
  func_001780F0's zero-init). diffmap prints `loops: ours N, game 0` for such regions.
- **Case body order.** gcc places case bodies in source order, whatever the order of the compare tree. diffmap
  lists the game's body order and marks the cases that are out of place (`!!case`).
- **Cross-jumping.** A "moved code" pair (our extra words = the game's missing words elsewhere) usually means the
  other copy survived cross-jumping or the blocks are in another order. Check the statement order of the
  duplicated tails.

## Dead-looking code: the instruction test (ruling 2026-11-12)

A statement whose result is never read is allowed **only if every instruction it produces exists in the game's
asm**. Then the original source had it, and the compiler kept it, e.g. a value computed and stored to a stack
local that nothing reads (func_00219A98) or a whole-vector copy that rewrites a member with its own value
(func_002BB818). Add a comment citing the game's instructions. A statement that only steers the compiler (it emits
nothing of its own, or emits instructions the game does not have) stays banned: dead initialisations folded away,
self-assignments, empty branches, invented `case` values. Small local buffers such as `unsigned short seq[1]` passed
as message data are ordinary C++.

## Findings from lane 2's fuzzy push (2026-11-12)

- **A `goto` loop is not a loop to gcc:** no alignment nop, no loop weighting, no hoisting. A nop before an 8-aligned
  label in the game means the original had a real `for`/`while`/`do`.
- **`break` vs `return`:** `break` keeps a found-block inside the loop; `return` moves it out.
- **Conditional moves follow the branch polarity:** `r = b; if (a >= b) r = a;` gives `slti`/`movn`.
- **Repeat the full array index expression at each use** to get the game's CSE register copies.
- **A 1-element array local** (`unsigned short seq[1]`) gets its stack slot at its declaration, ahead of scalars
  whose address is taken.
- **Vector operators:** `const float& operator[](int) const` (or a `const Vec& Row(int) const` accessor) inside the
  operators folds member reference arguments to base+offset (fixed five units).
- **Count-down loops:** `while (k--)` and `for (i = n; --i != -1;)`.
- **Callee arity again:** two more units had a wrong argument count; check the callee's asm first.
- **Stale per-file flags:** removing a leftover `-fno-gcse` gained 6 points on one unit; re-check flags after reworks.
- **diffmap caveat:** its "moved code" flag can misalign when a switch has several identical tails (func_001FF970).
- **Element alignment changes the address shape:** a 16-byte-aligned element type keeps the field offset in the
  load; a 4-aligned struct puts base+field in a register, which loop.c hoists (func_00208088, func_00208C50).
- **Duplicate whole case bodies** when the game does not hoist case constants: the bigger loop blocks hoisting,
  and cross-jumping merges the tails afterwards (func_001F4850).
- **Bool temps give `xori`/`beqz`:** `bool leaf = bits == 3; if (!leaf) ...`.
- **Return slot before locals:** an inline member returning a Vec by value, used as `m = F();`, places the return
  slot ahead of the inline's locals.
- **Reuse a Vec in place** when the game reuses its stack slot.
- **Compare against `0.0f` right after storing `w = 0`** and gcc reloads the zero from the stack slot.

## Per-file flags need neighbour evidence (2026-11-13)

A per-file flag is a claim about how the original *source file* was compiled. Before shipping one, check that the
already-matched functions around the unit (the same source file) still match with it. If they break, the gain is
a coincidence: don't ship it (lane 2 found this for `-fno-schedule-insns` on func_001D7350 / func_001DA8F0).
`-mvu0-use-vf0-vf2` is allowed (RAC3, same SN 1.36 compiler, found it on all its ranges): it changes loop.c's
hoisting and strength-reduction thresholds even in code without VU0. It matched func_00165CB0, and all 38 matched
loop units around it still match. See docs/techniques/LAST_MILE.md for the measured flag results and why
`-fforce-addr`, `-fno-cse-follow-jumps` and `-fno-expensive-optimizations` are not allowed (yet).

## More from lane 2's second pass (2026-11-13)

- **Merged early-out conditions:** `if (a || b || c) return X;` gives one shared in-loop exit block (decides what
  loop.c hoists).
- **Write a shared tail in both if/else arms** to keep gcc's block order; cross-jumping merges them afterwards.
- **A `goto` outer loop** where the game has no alignment nop at that loop head (loop.c then hoists nothing).
- **Stack slot order:** address-taken scalars get their slot late; a 1-element array (`T k[1]`, `T k[2]`) gets its
  slot at its declaration.
- **`T* pm = &obj` for call arguments with direct `obj.field` stores** reproduces `&obj` kept in a saved register.
- **A callee doing `daddu v0,a0` is a constructor:** declare it returning the pointer.
- **Offset-0 field via base+offset, other fields via a pointer register** = it was a member function; write it as one.
- **A second reference to the same member** reproduces the game copying the pointer into a callee-saved register.
- **Float `&&` tests stay un-inverted** inside return-early inline helpers.
- **In-place `*=`** removes Vec temporaries and shrinks the frame.
- **Loops the game did not strength-reduce:** `for (i = 0; i < n;) { int k = i + 1; ...; i = k; }`.
- **Split an aggregate local into per-row Vec locals** so they reuse freed temp slots.
- **EABI mixed float/pointer arguments:** the prototype's argument order decides evaluation order.

## Equivalence fixes need instruction-level proof (2026-11-13)

A "behaviour fix" in a src/nonmatching unit can itself be wrong: #596's func_001E0F20 swapped its two indices the
wrong way (the game computes `a1*0xCB0 + a0*0x28`, record = 2nd argument), and only a later exact match exposed it.
So every equivalence fix must cite, in a comment or the PR body, the game's instructions it follows (the address
arithmetic, the store width, the argument registers the callee reads), and a reviewer checks them against the asm.
An exact match is proof; a higher fuzzy score is not. Boot-test the functional build after behaviour fixes land.

More idioms from lane 2:
- **Always-true first loop test** (`state = -1`): `while (a && b)`; rotation decides which constant is hoisted.
- **Bit-test polarity** follows early `return false`s with a single final `return true`.
- **One extra inline layer around an address-taken local** decides whether `&t` stays in a register (inline members
  with their own temps, or an implicit derived-class ctor).
- **Block-entry slots precede expression temps:** declare named Vec locals up front, assign via `operator*=`.
- **toupper:** an inline taking `unsigned char d` stops CSE folding `c - 'a' + 'A'` into `c - 32`.
- **7-byte copies:** 8-aligned types in `__builtin_memcpy` give the game's lw/lhu/lbu.

## `volatile` follows interrupt access (ruling 2026-11-13)

Declare a global or member `volatile` exactly when an interrupt/vsync handler (or another thread) also touches it,
and say so in a comment naming the handler. That is what the original programmers had to write, and it shows in
the asm as reloads the compiler would otherwise have folded. Per-variable choices are fine when they follow that
rule. Where an exactly-matched unit already declares the same symbol, its qualifiers are proof of the original
declaration and win: the vsync handler func_001F77B0 (matched) declares D_0038EAA4/EAA8 volatile but the counter
D_00394118 plain even though the handler increments it, so func_001F79B0 uses the same split. Never add `volatile`
to a variable no handler or thread touches just to force a reload.
One narrow exception: in the 23 inline-asm-allowlisted units, a `volatile` *local* union that type-puns a VU0/COP2
128-bit value through the stack is allowed (it stands in for the original's memory-operand asm, which the
single-instruction-helper rule does not permit); comment it (func_0016FCF8).

## `-fno-gcse` is usually wrong (2026-11-13)

The game seems to have been built with gcse on almost everywhere: func_001AC030 and func_002B9A28 matched exactly
only after dropping `-fno-gcse` and reworking the source under default flags. A unit's source tuned around a wrong
flag scores worse when the flag is simply removed (all 15 remaining flagged units did), so the test is the
neighbour test: if the matched same-file neighbours break with the flag, rework the unit under defaults.

## If/else turned into "default, then overwrite" (lane 2, 2026-11-13)

Where the game keeps a two-arm branch (`if (p) v = load; else v = dflt;`) but ours becomes `v = dflt; if (p) v = load`
(or a movz/movn), jump.c's if/else simplification plus its conditional-move step fired (in jump1, after cse2 when
cse2 changed a jump, or in jump2). Any of these keeps the branch: an arm longer than one insn; an else-arm with side
effects or a possibly trapping load; an else insn with a non-REG_EQUAL note; the arms setting the variable in
different modes (HI vs SI); a block between the arms; the variable used in the test. Shapes that do it:
- **A:** a `short` return with the extension at the join: `short BoardId() { if (m_board) return m_board->Id(); return -1; }`.
- **B:** the else-arm re-reads the member: `FirstItem() { if (m_next->IsEnd()) return 0; return m_next; }`
  (matched func_0022DD38).

## Case values proven by elimination (ruling 2026-11-13)

An empty `case` is allowed when the binary pins its value exactly, even if its table entry equals the default: e.g.
a table spanning 1..6 exists only with 6 labels, and if 1, 2, 3, 5, 6 are accounted for, the sixth is 4
(func_002284B0). The value set may also be pinned by a whole-binary writer analysis: every store to the switched
field/array (including struct copies and bulk copies) writes only known constants, leaving exactly one candidate
(func_001D5EE0, func_001CD048; cite the writer addresses). If more than one value would fit, it is invented and
stays banned (e.g. switches on 32-bit script checksums).

## Lever sweep results and idioms (lane 2, 2026-11-13)

On 40 stuck units the levers that moved units most often were: separate/one-use locals and statement order (5),
inline layers / `operator=` / a reference to a sub-object / evaluation order (5), and writing a shared tail out in
each case instead of a `goto` or ternary (2, incl. one exact match: the extra loads raise `this`'s allocation
priority). If-conversion shapes helped 1. Try those first.
- An alignment nop where nothing is hoisted can mean the second loop sits inside the first loop's exit.
- `Ray& ray = m_ray;` (a reference to a sub-object) keeps its address in a callee-saved register across a call.
- A chained `a = b = x` gives one load stored twice.
- An inline member that calls another inline member defined *later* in the class body is emitted out of line
  (`jal`) by g++ 2.95; define the callee first.
- A parameter copied into a local counter (`int left = count;`) reproduces the game's spill of that copy.
