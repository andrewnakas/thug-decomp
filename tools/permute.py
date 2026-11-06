#!/usr/bin/env python3
"""Set up (and optionally run) decomp-permuter on one function, wired to the
exact pipeline the gate uses.

    python tools/permute.py func_00112345              # set up + verify
    python tools/permute.py func_00112345 --run -j8    # ... then permute

Writes work/permute/<name>/ with base.c (the preprocessed unit), target.o (the
original), compile.sh (calls tools/cc.py with the unit's own cflags) and
settings.toml. Before anything runs it checks for drift: compile.sh on base.c
must produce the same .text as match.py's compile of the unit, and the
permuter's verdict (score 0 or not) must agree with match.py. thps64 lost days
to permuter setups that silently scored a different pipeline.

decomp-permuter parses C, not C++: it works on units written as C-compatible
code (free functions, extern "C" callees, structs without member functions).
base.c drops extern "C" and declares bool and a typedef per struct so pycparser
reads it; compile.sh wraps the file in extern "C" { } again before compiling.
For class members, permute a C-style copy (`Foo* self` as the first argument)
under work/ and port the winning shape back by hand.
"""
import argparse
import os
import re
import shlex
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
from common import ROOT, compiler_config, file_cflags, tool, unit_path  # noqa: E402

PERMUTER = ROOT / "toolchain" / "decomp-permuter"


TI_TYPEDEF = re.compile(r"typedef\s+(\w+)\s+(\w+)\s+__attribute__\s*\(\(\s*mode\s*\(\s*TI\s*\)\s*\)\)\s*;")
# for pycparser only (compile.sh drops both lines): C has no bool, true or false
PRELUDE = "typedef _Bool bool;\nenum { false, true };\n"
EXTERN_C_BLOCK = re.compile(r'extern\s+"C"\s*\{')
EXTERN_C = re.compile(r'extern\s+"C"\s*')


def to_c(src):
    """The preprocessed unit as C the permuter can parse: no extern "C" (compile.sh wraps the whole
    file in one), and bool declared for pycparser (compile.sh removes that line again)."""
    out, depth = [], 0
    i = 0
    while i < len(src):
        m = EXTERN_C_BLOCK.match(src, i)
        if m:
            depth += 1
            i = m.end()
            # find the matching close brace of this block and drop it
            level, j = 1, i
            while j < len(src) and level:
                level += {"{": 1, "}": -1}.get(src[j], 0)
                j += 1
            src = src[:j - 1] + src[j:] if level == 0 else src
            continue
        out.append(src[i])
        i += 1
    text = EXTERN_C.sub("", "".join(out))
    # C++ uses struct names bare; C needs a typedef (also valid C++, so compile.sh keeps it)
    tags = dict.fromkeys(re.findall(r"\b(struct|union)\s+([A-Za-z_]\w*)\s*[{;]", text))
    typedefs = "".join(f"typedef {kw} {n} {n};\n" for kw, n in tags)
    # 128-bit types: pycparser cannot read __attribute__((mode(TI))); compile.sh restores it
    text = TI_TYPEDEF.sub(r"typedef \1 \2;", text)
    return PRELUDE + typedefs + text


def to_cpp(src_c, dst, ti_names):
    """Inverse of to_c for compile.sh: works on the permuter's regenerated source too."""
    t = Path(src_c).read_text()
    t = re.sub(r"^\s*typedef\s+_Bool\s+bool\s*;\s*$", "", t, flags=re.M)
    t = re.sub(r"enum\s*\{\s*false\s*,\s*true\s*\}\s*;", "", t)
    for n in ti_names:
        t = re.sub(rf"typedef\s+(\w+)\s+{n}\s*;", rf"typedef \1 {n} __attribute__((mode(TI)));", t)
    Path(dst).write_text('extern "C" {\n' + t + "\n}\n")


def text_bytes(o, name):
    return match.read_obj(o, match.func_row(name)["addr"]).words


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--to-cpp":   # internal: called by the generated compile.sh
        to_cpp(sys.argv[2], sys.argv[3], sys.argv[4:])
        return
    ap = argparse.ArgumentParser()
    ap.add_argument("name")
    ap.add_argument("--run", action="store_true")
    ap.add_argument("--src", help="permute this draft instead of src/funcs/<name>.cpp")
    ap.add_argument("--out", help="permuter directory (default work/permute/<name>)")
    a, rest = ap.parse_known_args()
    name = a.name
    unit = (ROOT / a.src).resolve() if a.src else unit_path(name)
    if not unit.exists():
        sys.exit(f"{unit.relative_to(ROOT)} missing: python tools/new_func.py {name}")
    d = (ROOT / a.out).resolve() if a.out else ROOT / "work" / "permute" / name
    d.mkdir(parents=True, exist_ok=True)

    cfg = compiler_config()
    pre = subprocess.run(["cpp", "-P", "-undef", "-D__GNUC__=2", "-D__GNUC_MINOR__=95", *cfg["compiler"]["cppflags"],
                          "-DPERMUTER", str(unit)],
                         capture_output=True, text=True, cwd=ROOT)
    if pre.returncode != 0:
        sys.exit(pre.stderr)
    (d / "base.c").write_text(to_c(pre.stdout))

    flags = cfg["compiler"]["cflags"] + file_cflags(unit)
    py = sys.executable
    # base.c is C for the permuter's parser; compile.sh turns it back into the C++ the gate compiles
    # (tools/permute.py --to-cpp: drop the C-only prelude, restore 128-bit typedefs, wrap in extern "C")
    ti = " ".join(n for _, n in TI_TYPEDEF.findall(pre.stdout))
    (d / "compile.sh").write_text(
        "#!/bin/sh\n# generated by tools/permute.py: same pipeline as tools/match.py\n"
        f"# usage: compile.sh input.c -o output.o\n"
        f"cd {shlex.quote(str(ROOT))} || exit 1\n"
        "src=\"$3.cpp\"\n"
        f"{shlex.quote(py)} tools/permute.py --to-cpp \"$1\" \"$src\" {ti} || exit 1\n"
        f"exec {shlex.quote(py)} tools/cc.py cxx \"$src\" \"$3\" --func {name} --cflags {shlex.quote(' '.join(flags + ['-x', 'c++']))}\n")
    os.chmod(d / "compile.sh", 0o755)
    (d / "settings.toml").write_text(
        f'func_name = "{name}"\ncompiler_type = "gcc"\n'
        f'objdump_command = "{tool("mipsel-linux-gnu-objdump")} -drz -m mips:5900"\n')

    res = match.compare(name, unit)
    if res.error:
        sys.exit(f"unit does not compile: {res.error}")
    target = ROOT / "build" / "match" / "target" / f"{name}.o"
    (d / "target.o").write_bytes(target.read_bytes())

    # drift check 1: compile.sh(base.c) == match.py's object
    out = d / "drift.o"
    r = subprocess.run([str(d / "compile.sh"), str(d / "base.c"), "-o", str(out)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("compile.sh failed on base.c:\n" + r.stderr)
    ours = ROOT / "build" / "match" / f"{name}.o"
    if text_bytes(out, name) != text_bytes(ours, name):
        sys.exit("DRIFT: compile.sh output differs from tools/match.py's compile; not permuting")

    print(f"permuter dir ready: {d.relative_to(ROOT)} "
          f"(match.py: {'MATCH' if res.ok else f'{len(res.diffs)} instruction(s) differ'})")
    if res.ok:
        print("already matches; nothing to permute")
        return

    # drift check 2: the permuter's own base score must say "not matching" too
    proc = subprocess.Popen([py, "-u", str(PERMUTER / "permuter.py"), str(d), "-j1"],
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    base = None
    for line in proc.stdout:
        if "Syntax error" in line:
            proc.kill()
            sys.exit("decomp-permuter cannot parse this unit (it reads C, not C++): permute a C-style "
                     "copy with an explicit self pointer under work/, then port the shape back")
        m = re.search(r"base score = (\d+)", line)
        if m:
            base = int(m.group(1))
            break
    proc.kill()
    proc.wait()
    if base is None or base == 0:
        sys.exit(f"DRIFT: permuter base score {base} but match.py sees {len(res.diffs)} difference(s)")
    print(f"permuter base score {base} (agrees: not yet matching)")
    if a.run:
        os.execv(py, [py, str(PERMUTER / "permuter.py"), str(d), "--stop-on-zero", *rest])
    else:
        print(f"run: {py} {PERMUTER.relative_to(ROOT)}/permuter.py {d.relative_to(ROOT)} --stop-on-zero -j8")


if __name__ == "__main__":
    main()
