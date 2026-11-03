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
