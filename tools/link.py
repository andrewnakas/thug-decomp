#!/usr/bin/env python3
"""Link build/link.ld and rebuild SLUS_207.31, or verify it.

    python tools/link.py build/SLUS_207.31                 # ld + objcopy + splice
    python tools/link.py --verify build/SLUS_207.31 build/SLUS_207.31.ok

The output file = asm/bin/elfhdr.bin (first page of your disc's ELF)
                + the linked main segment (.text .vutext .data .rodata .lit4 .sdata)
                + asm/bin/elftail.bin (DNAS blob, non-alloc sections, section headers).
--verify writes the stamp only when the sha1 matches, so a mismatching build
never looks up to date to ninja.
"""
import hashlib
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BUILD, EXE_NAME, EXE_SHA1, FILE_OFF, ROOT, SEG_END, tool  # noqa: E402


def link(out):
    out = Path(out)
    elf = BUILD / "main.elf"
    r = subprocess.run([tool("mipsel-linux-gnu-ld"), "-nostdlib", "--no-check-sections", "-EL",
                        "-T", str(BUILD / "link.ld"), "-Map", str(BUILD / "main.map"),
                        "-o", str(elf)], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("ld failed:\n" + r.stderr[-6000:])
    main_bin = BUILD / "main.bin"
    r = subprocess.run([tool("mipsel-linux-gnu-objcopy"), "-O", "binary", "-j", ".main",
                        str(elf), str(main_bin)], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("objcopy failed:\n" + r.stderr)
    body = main_bin.read_bytes()
    want = SEG_END - FILE_OFF
    if len(body) != want:
        sys.exit(f"main segment is 0x{len(body):X} bytes, expected 0x{want:X}: "
                 "a function or data object has the wrong size (run tools/first_diff.py)")
    head = (ROOT / "asm/bin/elfhdr.bin").read_bytes()
    tail = (ROOT / "asm/bin/elftail.bin").read_bytes()
    out.write_bytes(head + body + tail)


def verify(exe, stamp):
    h = hashlib.sha1(Path(exe).read_bytes()).hexdigest()
    Path(stamp).unlink(missing_ok=True)
    if h != EXE_SHA1:
        print(f"{EXE_NAME}: MISMATCH (sha1 {h}, want {EXE_SHA1})")
        print("run: python tools/first_diff.py")
        sys.exit(1)
    Path(stamp).write_text(h + "\n")
    print(f"{EXE_NAME}: OK ({h})")


if __name__ == "__main__":
    if sys.argv[1] == "--verify":
        verify(sys.argv[2], sys.argv[3])
    else:
        link(sys.argv[1])
