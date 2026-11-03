#!/usr/bin/env python3
"""Extract and verify the Tony Hawk's Underground (USA, PS2) disc image.

Reads ISO9660 straight from the 2048-byte-sector DVD image (no mounting, no
root), checks SYSTEM.CNF boots SLUS_207.31, writes the files the decomp needs
to disc/files/ and compares their SHA-1s with config/checksums.us.sha1.

    python tools/extract_disc.py [path/to/image.iso]   # default: first .iso under disc/
    python tools/extract_disc.py --all                 # also the big asset files (~1 GB)
    python tools/extract_disc.py --write-checksums     # (maintainer) record checksums

By default only the boot ELF, SYSTEM.CNF and the IOP modules are written: the
decomp needs nothing else, and SKATE5.WAD alone is 900 MB.
"""
import argparse
import hashlib
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SECTOR = 2048
EXPECTED_SERIAL = "SLUS_207.31"
CHECKSUMS = ROOT / "config" / "checksums.us.sha1"
DEFAULT_SET = ("SYSTEM.CNF", "SLUS_207.31", "IOP/")


class Disc:
    def __init__(self, path):
        self.f = open(path, "rb")

    def read(self, lba, count=1):
        self.f.seek(lba * SECTOR)
        return self.f.read(count * SECTOR)


def walk(disc, lba, size, prefix=""):
    data = disc.read(lba, (size + SECTOR - 1) // SECTOR)
    off = 0
    while off < len(data):
        rlen = data[off]
        if rlen == 0:  # records never straddle sectors; skip to the next one
            off = (off // SECTOR + 1) * SECTOR
            continue
        rec = data[off:off + rlen]
        ext = struct.unpack_from("<I", rec, 2)[0]
        ln = struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]
        name = rec[33:33 + rec[32]]
        off += rlen
        if name in (b"\x00", b"\x01"):
            continue
        path = prefix + name.decode("ascii").split(";")[0]
        if flags & 2:
            yield from walk(disc, ext, ln, path + "/")
        else:
            yield path, ext, ln


def sha1(b):
    return hashlib.sha1(b).hexdigest()


def wanted(path, everything):
    return everything or any(path == w or (w.endswith("/") and path.startswith(w)) for w in DEFAULT_SET)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image", nargs="?")
    ap.add_argument("--out", default=str(ROOT / "disc" / "files"))
    ap.add_argument("--all", action="store_true", help="extract every file, not just code")
    ap.add_argument("--write-checksums", action="store_true")
    a = ap.parse_args()

    image = Path(a.image) if a.image else next(iter(sorted((ROOT / "disc").glob("*.iso"))), None)
    if not image or not image.exists():
        sys.exit("no disc image found: put your .iso (or a symlink to it) under disc/, or pass its path")
    disc = Disc(image)
    pvd = disc.read(16)
    if pvd[1:6] != b"CD001":
        sys.exit(f"{image}: no ISO9660 volume descriptor (not a PS2 DVD image?)")
    root = pvd[156:156 + 34]
    rlba, rlen = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]

    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    sums = {}
    for path, ext, ln in walk(disc, rlba, rlen):
        if not wanted(path, a.all):
            continue
        data = disc.read(ext, (ln + SECTOR - 1) // SECTOR)[:ln]
        dst = out / path
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_bytes(data)
        sums[path] = sha1(data)
        print(f"{ext:8d} {ln:10d} {path}")

    cnf = (out / "SYSTEM.CNF").read_text(errors="replace")
    boot = next((l for l in cnf.splitlines() if l.strip().upper().startswith("BOOT")), "")
    if EXPECTED_SERIAL not in boot.upper():
        sys.exit(f"SYSTEM.CNF boots {boot.strip()!r}, expected {EXPECTED_SERIAL}: wrong disc or region")
    print(f"boot: {boot.strip()}")

    if a.write_checksums:
        lines = [f"{h}  {p}" for p, h in sorted(sums.items())]
        CHECKSUMS.write_text("\n".join(lines) + "\n")
        print(f"wrote {CHECKSUMS.relative_to(ROOT)} ({len(lines)} files)")
        return

    if not CHECKSUMS.exists():
        sys.exit("config/checksums.us.sha1 missing")
    bad = n = 0
    for line in CHECKSUMS.read_text().splitlines():
        h, p = line.split(None, 1)
        if p not in sums and not wanted(p, False):
            continue  # asset file not extracted this run
        n += 1
        if sums.get(p) != h:
            print(f"MISMATCH {p}: {sums.get(p)} != {h}")
            bad += 1
    if bad:
        sys.exit(f"{bad} file(s) differ from the known-good USA disc")
    print(f"OK: {n} files match config/checksums.us.sha1")


if __name__ == "__main__":
    main()
