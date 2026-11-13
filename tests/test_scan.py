"""scan.py rejects the constructs that fake a match (no disc or toolchain needed)."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import scan  # noqa: E402

ALLOWED = {"-O1", "-O2"}


def problems(tmp_path, body, name="func_00100118.cpp"):
    f = tmp_path / name
    f.write_text(body)
    return scan.scan_file(f, ALLOWED, None)


def test_clean(tmp_path):
    assert problems(tmp_path, 'extern "C" int func_00100030(int);\nint f() { return func_00100030(1); }\n') == []


def test_inline_asm(tmp_path):
    assert problems(tmp_path, "void f() { __asm__(\"nop\"); }\n")


def test_string_literal(tmp_path):
    assert problems(tmp_path, 'void p(const char*); void f() { p("hi"); }\n')


def test_address(tmp_path):
    assert problems(tmp_path, "int f() { return *(int*)0x00393E80; }\n")


def test_flag_constant_is_not_an_address(tmp_path):
    assert problems(tmp_path, "int f(int x) { return x & 0x00200000; }\n") == []


def test_bad_name(tmp_path):
    assert problems(tmp_path, "int f() { return 0; }\n", name="func_00100118.c")


def test_cflags(tmp_path):
    assert problems(tmp_path, "/* cflags: -O3 */\nint f() { return 0; }\n")
    assert problems(tmp_path, "/* cflags: -O1 */\nint f() { return 0; }\n") == []


def test_bare_statement(tmp_path):
    assert problems(tmp_path, "struct S { volatile int m; void f(); };\nvoid S::f()\n{\n    m;\n}\n")
    assert problems(tmp_path, "void f(int x) { for (;;) { if (x) break; } return; }\n") == []


def test_declared_const(tmp_path):
    body = "int f(int x) { return x + 0x00149960; }\n"
    assert problems(tmp_path, body)
    assert problems(tmp_path, "/* const: 0x149960 */\n" + body) == []


# Inline-asm exception: only units on the allowlist, only as small `static inline` helpers.
ASM_ALLOW = {"func_0010F8B8"}
GOOD_ASM = """extern int D_00388D7C;
static inline void ExitHandler() { __asm__ __volatile__("sync.l\\n\\tei"); }
static inline void LoadVF4(const void* p) { __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p) : "memory"); }
static inline int Syscall(int n) { int r; __asm__ __volatile__("syscall" : "=r"(r) : "r"(n)); return r; }
int func_0010F8B8(int)
{
    D_00388D7C++;
    ExitHandler();
    return 0;
}
"""


def asm_problems(tmp_path, body, name="func_0010F8B8.cpp", allow=ASM_ALLOW):
    f = tmp_path / name
    f.write_text(body)
    return scan.scan_file(f, ALLOWED, None, allow)


def test_inline_asm_allowlisted_helpers(tmp_path):
    assert asm_problems(tmp_path, GOOD_ASM) == []


def test_inline_asm_not_allowlisted(tmp_path):
    assert asm_problems(tmp_path, GOOD_ASM, allow=set())
    assert asm_problems(tmp_path, GOOD_ASM, name="func_00100118.cpp")


def test_inline_asm_outside_static_inline(tmp_path):
    assert asm_problems(tmp_path, 'void func_0010F8B8() { __asm__ __volatile__("ei"); }\n')
    assert asm_problems(tmp_path, 'inline void Ei() { __asm__ __volatile__("ei"); }\n')
    assert asm_problems(tmp_path, '__asm__("ei");\n')
    assert asm_problems(tmp_path, 'struct S { static inline void Ei() { __asm__("ei"); } };\n')


def test_inline_asm_too_many_insns(tmp_path):
    assert asm_problems(tmp_path, 'static inline void F() { __asm__("sync.l; ei; nop; nop"); }\n')
    assert asm_problems(tmp_path, 'static inline void F() { __asm__("sync.l\\n\\tei\\n\\tnop\\n\\tnop"); }\n')
    assert asm_problems(tmp_path, 'static inline void F() { __asm__("sync.l; nop; ei"); }\n') == []


def test_inline_asm_one_statement_per_helper(tmp_path):
    assert asm_problems(tmp_path, 'static inline void F() { __asm__("di"); __asm__("ei"); }\n')


def test_inline_asm_directives_labels_branches(tmp_path):
    for t in (".word 0x4BE521AA", ".byte 1", ".half 2", ".set noreorder", "1: nop", "b 1f",
              "beq $2, $0, 8", "bc2t 8", "jr $31", "jal func_00100030", "eret", "nop%="):
        assert asm_problems(tmp_path, 'static inline void F() { __asm__ __volatile__("%s"); }\n' % t), t


def test_inline_asm_register_pinning(tmp_path):
    assert asm_problems(tmp_path, 'static inline int F() { register int x asm("$16"); return x; }\n')
    assert asm_problems(tmp_path, 'static inline int F() { int x __asm__("$16"); return x; }\n')


def test_inline_asm_strings_still_banned(tmp_path):
    assert asm_problems(tmp_path, GOOD_ASM + 'void p(const char*); void g() { p("hi"); }\n')


def test_inline_asm_allowlist_file():
    names = scan.inline_asm_allowlist()
    assert len(names) >= 23  # the original 23, plus reviewed hardware-op additions (RULES.md)
    assert "func_0010F8B8" in names and "func_002CE778" in names
    for stub in ("func_0010ED38", "func_00172340", "func_00172360", "func_002CE770"):
        assert stub not in names
