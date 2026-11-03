#!/usr/bin/env python3
"""Prove the toolchain is the pinned one before judging anything.

    python tools/toolcheck.py            # check
    python tools/toolcheck.py --record   # (maintainer, after a deliberate tools change) record the canary

Checks: sha256 of every pinned binary (toolchain/checksums.sha256: wibo, the SN
compiler package, objdiff-cli), that GNU as for R5900 runs, and a canary
compile: tests/fixtures/canary.cpp must compile to .text bytes with the sha1 in
tests/fixtures/canary.sha1. No disc needed.
"""
import hashlib
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import cc  # noqa: E402
from common import BUILD, ROOT, TOOLCHAIN, compiler_config, tool  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402

CANARY = ROOT / "tests" / "fixtures" / "canary.cpp"
CANARY_SHA1 = ROOT / "tests" / "fixtures" / "canary.sha1"


def sha256(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def canary_digest():
    out = BUILD / "toolcheck" / "canary.o"
    cc.compile_obj(CANARY, out, compiler_config(), literals=False)
    with open(out, "rb") as f:
        return hashlib.sha1(ELFFile(f).get_section_by_name(".text").data()).hexdigest()


def main():
    bad = []
    for line in (TOOLCHAIN / "checksums.sha256").read_text().splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        want, rel = line.split(None, 1)
        p = ROOT / rel
        if not p.exists():
            bad.append(f"{rel}: missing (run python3 toolchain/setup.py)")
        elif sha256(p) != want:
            bad.append(f"{rel}: sha256 differs from toolchain/checksums.sha256")
    try:
        subprocess.run([tool("mipsel-linux-gnu-as"), "-march=r5900", "--version"], capture_output=True, check=True)
    except (OSError, subprocess.CalledProcessError):
        bad.append("mipsel-linux-gnu-as not runnable")
    if not bad:
        try:
            got = canary_digest()
            want = CANARY_SHA1.read_text().split()[0] if CANARY_SHA1.exists() else None
            if "--record" in sys.argv:
                CANARY_SHA1.write_text(got + "\n")
                print(f"recorded canary {got}")
            elif got != want:
                bad.append(f"canary compiled to {got}, expected {want}: the pipeline changed")
        except cc.StageError as e:
            bad.append(f"canary failed to compile: {e}")
    if bad:
        print("TOOLCHECK FAIL")
        for b in bad:
            print(f"  {b}")
        sys.exit(1)
    print("TOOLCHECK OK")


if __name__ == "__main__":
    main()
