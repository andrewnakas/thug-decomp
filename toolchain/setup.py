#!/usr/bin/env python3
"""One-command, idempotent toolchain install. No root needed.

    python3 toolchain/setup.py            # everything
    python3 toolchain/setup.py --check    # verify only (what the judge runs)

Installs into toolchain/ (git-ignored):
  compilers/<name>/            pinned SN ee-gcc package (compiler.toml, decompme/compilers), sha256-verified
  bin/wibo                     runs the Windows SN compiler on Linux (decompals/wibo), sha256-verified
  bin/mipsel-linux-gnu-*       GNU binutils (PATH, or the distro .deb unpacked without root)
  bin/objdiff-cli              pinned release, sha256-verified
  m2c/, decomp-permuter/       pinned commits
  ../.venv                     Python deps from requirements.txt (via uv if present)

Ends with a self-test: a canary C++ file must compile to known bytes, so a
broken toolchain is caught before it judges anything.
"""
import argparse
import hashlib
import os
import shutil
import subprocess
import sys
import tarfile
import tomllib
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TC = ROOT / "toolchain"
BIN = TC / "bin"
DL = TC / "dl"

OBJDIFF = {
    "url": "https://github.com/encounter/objdiff/releases/download/v3.8.2/objdiff-cli-linux-x86_64",
    "sha256": "e5445089a6f707e30cb5e02992451b604619cedfd2660ee2373a86bfefd9e718",
}
GIT_PINS = {
    "m2c": ("https://github.com/matt-kempster/m2c", "c632946b8cfbe8fce442b522dba92dfa72f1f317", TC / "m2c"),
    "decomp-permuter": ("https://github.com/simonlindholm/decomp-permuter",
                        "8556c81d80d1c1af98a858c8f4dc951357f29139", TC / "decomp-permuter"),
}
BINUTILS = ["as", "ld", "objcopy", "objdump", "nm", "readelf"]
BINUTILS_DEB = "binutils-mipsel-linux-gnu"



def say(msg):
    print(f"[setup] {msg}", flush=True)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def fetch(url, dest, want):
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists() and sha256(dest) == want:
        return dest
    say(f"download {url}")
    tmp = dest.with_suffix(dest.suffix + ".part")
    with urllib.request.urlopen(url) as r, open(tmp, "wb") as f:
        shutil.copyfileobj(r, f)
    got = sha256(tmp)
    if got != want:
        tmp.unlink()
        sys.exit(f"sha256 mismatch for {url}: {got} != {want}")
    os.replace(tmp, dest)
    return dest


def install_compiler(cfg, check):
    name = cfg["compiler"]["name"]
    spec = cfg["compilers"][name]
    driver = TC / "compilers" / spec["dir"] / spec["driver"]
    if check:
        if not driver.exists():
            sys.exit(f"compiler {name} missing")
        return
    arc = fetch(spec["url"], DL / Path(spec["url"].split("?")[0]).name, spec["sha256"])
    if not driver.exists():
        top = TC / "compilers" / Path(spec["dir"]).parts[0]
        top.mkdir(parents=True, exist_ok=True)
        with tarfile.open(arc) as t:
            t.extractall(top, filter="data")
    if not driver.exists():
        sys.exit(f"{driver} not found after unpacking {arc.name}")
    say(f"compiler {name} -> {driver.relative_to(ROOT)}")
    w = cfg["tools"]["wibo"]
    dest = BIN / "wibo"
    BIN.mkdir(exist_ok=True)
    fetch(w["url"], dest, w["sha256"])
    dest.chmod(0o755)


def install_binutils(check):
    BIN.mkdir(exist_ok=True)
    have = all((BIN / f"mipsel-linux-gnu-{t}").exists() for t in BINUTILS)
    if have:
        return
    if check:
        sys.exit("binutils missing")
    on_path = shutil.which("mipsel-linux-gnu-as")
    if on_path:
        prefix = Path(on_path).parent
        for t in BINUTILS:
            (BIN / f"mipsel-linux-gnu-{t}").symlink_to(prefix / f"mipsel-linux-gnu-{t}")
        say(f"binutils from PATH ({prefix})")
        return
    if not shutil.which("apt-get"):
        sys.exit("need mipsel-linux-gnu binutils: install binutils-mipsel-linux-gnu or use the Dockerfile")
    root = DL / "binutils"
    root.mkdir(parents=True, exist_ok=True)
    subprocess.run(["apt-get", "download", BINUTILS_DEB], cwd=root, check=True)
    deb = next(root.glob(f"{BINUTILS_DEB}_*.deb"))
    subprocess.run(["dpkg-deb", "-x", str(deb), str(root)], check=True)
    libdir = next(p for p in root.rglob("libbfd-*mipsel*.so")).parent
    for t in BINUTILS:
        w = BIN / f"mipsel-linux-gnu-{t}"
        w.write_text(f'#!/bin/sh\nexport LD_LIBRARY_PATH="{libdir}${{LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}}"\n'
                     f'exec "{root}/usr/bin/mipsel-linux-gnu-{t}" "$@"\n')
        w.chmod(0o755)
    say(f"binutils unpacked from {deb.name} (no root)")


def install_objdiff(check):
    dest = BIN / "objdiff-cli"
    if check:
        if not dest.exists() or sha256(dest) != OBJDIFF["sha256"]:
            sys.exit("objdiff-cli missing or wrong sha256")
        return
    fetch(OBJDIFF["url"], dest, OBJDIFF["sha256"])
    dest.chmod(0o755)


def install_git(check):
    for name, (url, rev, dest) in GIT_PINS.items():
        if check:
            if not dest.exists():
                sys.exit(f"{name} missing")
            continue
        if not (dest / ".git").exists():
            say(f"clone {name}")
            subprocess.run(["git", "clone", "-q", url, str(dest)], check=True)
        cur = subprocess.run(["git", "-C", str(dest), "rev-parse", "HEAD"], capture_output=True,
                             text=True).stdout.strip()
        if cur != rev:
            subprocess.run(["git", "-C", str(dest), "fetch", "-q", "origin", rev], check=False)
            subprocess.run(["git", "-C", str(dest), "checkout", "-q", rev], check=True)


def install_venv(check):
    venv = ROOT / ".venv"
    py = venv / "bin" / "python"
    if check:
        if not py.exists():
            sys.exit(".venv missing")
        return
    uv = shutil.which("uv")
    if not py.exists():
        if uv:
            subprocess.run([uv, "venv", "-q", str(venv)], check=True)
        else:
            subprocess.run([sys.executable, "-m", "venv", str(venv)], check=True)
    if uv:
        subprocess.run([uv, "pip", "install", "-q", "-p", str(py), "-r", "requirements.txt"],
                       cwd=ROOT, check=True)
    else:
        subprocess.run([str(py), "-m", "pip", "install", "-q", "-r", "requirements.txt"],
                       cwd=ROOT, check=True)


def self_test():
    py = ROOT / ".venv" / "bin" / "python"
    r = subprocess.run([str(py), "tools/toolcheck.py"], cwd=ROOT)
    if r.returncode != 0:
        sys.exit("toolchain self-test FAILED")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--minimal", action="store_true",
                    help="compiler, binutils, objdiff, venv only (CI compile job)")
    a = ap.parse_args()
    cfg = tomllib.loads((TC / "compiler.toml").read_text())
    install_venv(a.check)
    install_compiler(cfg, a.check)
    install_binutils(a.check)
    install_objdiff(a.check)
    if not a.minimal:
        install_git(a.check)
    self_test()
    say("OK")


if __name__ == "__main__":
    main()
