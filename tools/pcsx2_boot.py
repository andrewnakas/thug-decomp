#!/usr/bin/env python3
"""Boot an ELF in PCSX2 with your game disc, press buttons on a virtual pad, and save screenshots.

    python tools/pcsx2_boot.py build/functional/SLUS_207.31 --tag functional
    python tools/pcsx2_boot.py build/SLUS_207.31 --tag original --seconds 120 \
        --press 40:start --press 50:cross --shot-every 5

Used to show the functional build (tools/build_functional.py) reaches the same screens as the original.
Nothing of your PCSX2 setup is changed: PCSX2 runs with -datapath work/pcsx2/<tag>/data, a private settings
directory (work/pcsx2/<tag>/data/PCSX2) seeded from a copy of ~/.config/PCSX2/inis/PCSX2.ini and a copy of your BIOS folder, with fresh
memory cards. Outputs (all under work/, git-ignored):
    work/pcsx2/<tag>/shot_<t>s.png   PCSX2 screenshots, named by seconds since boot
    work/pcsx2/<tag>/emulog.txt      PCSX2's log, with the game's own EE printf output (EnableEEConsole)

Input: a virtual pad on /dev/uinput with its own ids (pid.codes 1209:7468) and an SDL mapping passed in
SDL_GAMECONTROLLERCONFIG; SDL is told to ignore every other pad, so the virtual one is SDL-0 and your keyboard
and real controllers are not touched. --press T:BUTTON[+BUTTON][:HOLD] presses at T seconds after boot. Buttons: cross circle square
triangle start select up down left right l1 r1.
Screenshots: the pad's Guide button is bound to PCSX2's Screenshot hotkey (PNG in snaps/); PINE (PCSX2's
IPC socket) is only used to see when the game is running.

PCSX2: --pcsx2 (default ~/Applications/pcsx2/AppRun or the v2.8.2 AppImage in ~/Downloads).
The disc: --iso (default: disc/*.iso, following the symlink to your dump).
"""
import argparse
import configparser
import fcntl
import os
import shutil
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
HOME = Path.home()

# ---------------------------------------------------------------- uinput pad
PAD_VID, PAD_PID, PAD_VER = 0x1209, 0x7468, 0x0001
# SDL GUID: bus 3 (USB), crc 0, vendor, product, version (little-endian 16-bit fields)
PAD_GUID = (f"0300{0:04x}{PAD_VID & 0xFF:02x}{PAD_VID >> 8:02x}0000{PAD_PID & 0xFF:02x}{PAD_PID >> 8:02x}0000"
            f"{PAD_VER & 0xFF:02x}{PAD_VER >> 8:02x}0000")
PAD_MAPPING = (f"{PAD_GUID},THUG test pad,a:b0,b:b1,y:b2,x:b3,leftshoulder:b4,rightshoulder:b5,back:b6,start:b7,"
               "guide:b8,leftstick:b9,rightstick:b10,dpup:h0.1,dpright:h0.2,dpdown:h0.4,dpleft:h0.8,"
               "leftx:a0,lefty:a1,lefttrigger:a2,rightx:a3,righty:a4,righttrigger:a5,platform:Linux,")
EV_SYN, EV_KEY, EV_ABS = 0, 1, 3
BTN = {"cross": 0x130, "circle": 0x131, "triangle": 0x133, "square": 0x134, "l1": 0x136, "r1": 0x137,
       "select": 0x13A, "start": 0x13B, "mode": 0x13C, "thumbl": 0x13D, "thumbr": 0x13E}
HAT = {"left": (0x10, -1), "right": (0x10, 1), "up": (0x11, -1), "down": (0x11, 1)}
ABS_RANGES = {0: (-32768, 32767), 1: (-32768, 32767), 2: (0, 255), 3: (-32768, 32767), 4: (-32768, 32767),
              5: (0, 255), 0x10: (-1, 1), 0x11: (-1, 1)}
UI_SET_EVBIT, UI_SET_KEYBIT, UI_SET_ABSBIT = 0x40045564, 0x40045565, 0x40045567
UI_DEV_CREATE, UI_DEV_DESTROY = 0x5501, 0x5502


class Pad:
    def __init__(self):
        self.fd = os.open("/dev/uinput", os.O_WRONLY | os.O_NONBLOCK)
        for ev in (EV_KEY, EV_ABS, EV_SYN):
            fcntl.ioctl(self.fd, UI_SET_EVBIT, ev)
        for code in BTN.values():
            fcntl.ioctl(self.fd, UI_SET_KEYBIT, code)
        for code in ABS_RANGES:
            fcntl.ioctl(self.fd, UI_SET_ABSBIT, code)
        absmax, absmin = [0] * 64, [0] * 64
        for code, (lo, hi) in ABS_RANGES.items():
            absmin[code], absmax[code] = lo, hi
        dev = struct.pack("80sHHHHi", b"THUG test pad", 0x03, PAD_VID, PAD_PID, PAD_VER, 0)
        dev += struct.pack("64i", *absmax) + struct.pack("64i", *absmin) + bytes(4 * 64 * 2)
        os.write(self.fd, dev)
        fcntl.ioctl(self.fd, UI_DEV_CREATE)

    def emit(self, typ, code, value):
        os.write(self.fd, struct.pack("llHHi", 0, 0, typ, code, value))
        os.write(self.fd, struct.pack("llHHi", 0, 0, EV_SYN, 0, 0))

    def press(self, names, hold=0.15):
        for n in names:
            if n in HAT:
                self.emit(EV_ABS, HAT[n][0], HAT[n][1])
            else:
                self.emit(EV_KEY, BTN[n], 1)
        time.sleep(hold)
        for n in names:
            if n in HAT:
                self.emit(EV_ABS, HAT[n][0], 0)
            else:
                self.emit(EV_KEY, BTN[n], 0)

    def close(self):
        try:
            fcntl.ioctl(self.fd, UI_DEV_DESTROY)
        finally:
            os.close(self.fd)


# Preset routes (fresh memory cards; timings are loose because loads vary by a few seconds):
#   title: skip the intro movies (Start) up to Story Options.
#   level: title, Start New Story, skip the opening cutscene, then "up, cross" pairs pick DONE in the
#          Edit Skater and Create Options menus, which loads the first level (New Jersey).
ROUTES = {
    "title": [f"{t}:start" for t in (12, 16, 20, 24, 28)],
    "level": [f"{t}:start" for t in (12, 16, 20, 24, 28, 36)] + ["40:cross"]
             + [f"{t}:start" for t in (55, 65, 75)]
             + [x for t in (82, 88, 94, 100, 106) for x in (f"{t}:up", f"{t + 2}:cross")],
}


# ---------------------------------------------------------------- PINE
class Pine:
    def __init__(self, slot):
        rt = os.environ.get("XDG_RUNTIME_DIR", "/tmp")
        self.path = f"{rt}/pcsx2.sock" + ("" if slot == 28011 else f".{slot}")

    def call(self, op, payload=b""):
        with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as s:
            s.settimeout(10)
            s.connect(self.path)
            msg = bytes([op]) + payload
            s.sendall(struct.pack("<I", len(msg) + 4) + msg)
            head = s.recv(4)
            n, = struct.unpack("<I", head)
            data = b""
            while len(data) < n - 4:
                chunk = s.recv(n - 4 - len(data))
                if not chunk:
                    break
                data += chunk
            if not data or data[0] != 0:
                raise OSError(f"PINE op {op} failed")
            return data[1:]

    def status(self):       # 0 running, 1 paused, 2 shutdown
        return struct.unpack("<I", self.call(0x0F))[0]

    def read32(self, addr):
        return struct.unpack("<I", self.call(0x02, struct.pack("<I", addr)))[0]

    def save_state(self, slot):
        self.call(0x09, bytes([slot]))

    def game_id(self):
        d = self.call(0x0C)
        return d[4:4 + struct.unpack("<I", d[:4])[0]].rstrip(b"\0").decode(errors="replace")


# ---------------------------------------------------------------- settings
def make_datapath(data, pine_slot, extra=()):
    data.mkdir(parents=True, exist_ok=True)
    (data / "inis").mkdir(exist_ok=True)
    if not (data / "bios").exists():
        shutil.copytree(HOME / ".config/PCSX2/bios", data / "bios")
    ini = configparser.RawConfigParser(strict=False, interpolation=None)
    ini.optionxform = str
    ini.read(HOME / ".config/PCSX2/inis/PCSX2.ini")

    def put(sect, key, val):
        if not ini.has_section(sect):
            ini.add_section(sect)
        ini.set(sect, key, val)
    put("UI", "ConfirmShutdown", "false")
    put("UI", "StartFullscreen", "false")
    put("UI", "SetupWizardIncomplete", "false")
    put("EmuCore", "EnablePINE", "true")
    put("EmuCore", "PINESlot", str(pine_slot))
    put("EmuCore", "EnableFastBoot", "true")
    put("EmuCore", "SaveStateOnShutdown", "false")
    put("EmuCore", "BackupSavestate", "false")
    put("EmuCore", "EnableCheats", "false")
    put("Logging", "EnableFileLogging", "true")
    put("Logging", "EnableEEConsole", "true")
    put("Logging", "EnableIOPConsole", "false")
    put("InputSources", "SDL", "true")
    put("InputSources", "SDLControllerEnhancedMode", "false")
    put("InputSources", "BackgroundInput", "true")
    pad = {"Type": "DualShock2", "Up": "SDL-0/DPadUp", "Right": "SDL-0/DPadRight", "Down": "SDL-0/DPadDown",
           "Left": "SDL-0/DPadLeft", "Select": "SDL-0/Back", "Start": "SDL-0/Start",
           "L1": "SDL-0/LeftShoulder", "R1": "SDL-0/RightShoulder", "Triangle": "SDL-0/FaceNorth",
           "Circle": "SDL-0/FaceEast", "Cross": "SDL-0/FaceSouth", "Square": "SDL-0/FaceWest"}
    for k, v in pad.items():
        put("Pad1", k, v)
    put("Hotkeys", "Screenshot", "SDL-0/Guide")
    put("EmuCore/GS", "ScreenshotFormat", "0")
    for spec in extra:                   # "Section/Sub/Key=value": the last '/' splits section and key
        k, _, v = spec.partition("=")
        sect, _, key = k.rpartition("/")
        put(sect, key, v)
    with open(data / "inis" / "PCSX2.ini", "w") as f:
        ini.write(f, space_around_delimiters=True)


def find_pcsx2():
    for p in (HOME / "Applications/pcsx2/AppRun", HOME / "Downloads/pcsx2-v2.8.2-linux-appimage-x64-Qt.AppImage"):
        if p.exists():
            return str(p)
    sys.exit("PCSX2 not found: pass --pcsx2")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("elf")
    ap.add_argument("--tag", required=True)
    ap.add_argument("--iso")
    ap.add_argument("--pcsx2")
    ap.add_argument("--seconds", type=float, default=90)
    ap.add_argument("--shot-every", type=float, default=10)
    ap.add_argument("--shot-start", type=float, default=5, help="seconds after boot of the first screenshot")
    ap.add_argument("--press", action="append", default=[], help="T:button[+button][:hold]")
    ap.add_argument("--route", choices=sorted(ROUTES), help="a preset button sequence (adds to --press)")
    ap.add_argument("--pine-slot", type=int, default=28111)
    ap.add_argument("--ini", action="append", default=[],
                    help="extra setting for the private PCSX2.ini, e.g. EmuCore/CPU/Recompiler/EnableEE=false")
    a = ap.parse_args()

    iso = a.iso or next((str(p) for p in sorted((ROOT / "disc").glob("*.iso"))), None)
    if not iso or not Path(iso).exists():
        sys.exit("no disc image: pass --iso or symlink yours into disc/")
    out = ROOT / "work" / "pcsx2" / a.tag
    if out.exists():
        for p in out.glob("shot_*.png"):
            p.unlink()
    base = out / "data"            # PCSX2 keeps its files in <datapath>/PCSX2
    data = base / "PCSX2"
    make_datapath(data, a.pine_slot, a.ini)
    for p in (data / "sstates").glob("*.p2s") if (data / "sstates").exists() else []:
        p.unlink()
    log = data / "logs" / "emulog.txt"
    if log.exists():
        log.unlink()
    presses = []
    for spec in a.press + (ROUTES[a.route] if a.route else []):
        parts = spec.split(":")
        presses.append((float(parts[0]), parts[1].split("+"), float(parts[2]) if len(parts) > 2 else 0.15))
    presses.sort()

    # The game reads its own executable name at boot and overflows a buffer on longer names (any ELF,
    # the original included, crashes with a TLB miss at pc 0x114318 storing to 0x2000000). Always boot
    # it under the retail name.
    elf = Path(a.elf).resolve()
    if elf.name != "SLUS_207.31":
        named = base / "elf" / "SLUS_207.31"
        named.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(elf, named)
        elf = named

    pad = Pad()
    time.sleep(1.0)
    cmd = [a.pcsx2 or find_pcsx2(), "-datapath", str(base), "-batch", "-fastboot", "-nofullscreen",
           "-elf", str(elf), "--", iso]
    print(" ".join(cmd))
    # SDL sees only the virtual pad, so it is always SDL-0 and a real controller plugged in is left alone
    env = dict(os.environ, SDL_GAMECONTROLLERCONFIG=PAD_MAPPING,
               SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT=f"0x{PAD_VID:04x}/0x{PAD_PID:04x}")
    proc = subprocess.Popen(cmd, stdout=open(out / "stdout.txt", "w"), stderr=subprocess.STDOUT, env=env)
    pine = Pine(a.pine_slot)
    t0 = None
    next_shot = a.shot_start
    shots = []
    try:
        deadline = time.time() + 60
        while t0 is None:
            if proc.poll() is not None:
                sys.exit(f"PCSX2 exited early ({proc.returncode}); see {out / 'stdout.txt'}")
            try:
                if pine.status() == 0:
                    t0 = time.time()
            except OSError:
                pass
            if time.time() > deadline:
                sys.exit("PINE never came up")
            time.sleep(0.5)
        print(f"running: {pine.game_id()}")
        while True:
            t = time.time() - t0
            if t > a.seconds or proc.poll() is not None:
                break
            while presses and presses[0][0] <= t:
                _, names, hold = presses.pop(0)
                print(f"{t:6.1f}s press {'+'.join(names)}")
                pad.press(names, hold)
            if t >= next_shot:
                try:
                    shots.append(save_shot(pad, data, out, int(t)))
                except OSError as e:
                    print(f"{t:6.1f}s screenshot failed: {e}")
                next_shot += a.shot_every
            time.sleep(0.1)
        status = "exited" if proc.poll() is not None else "running"
    finally:
        if proc.poll() is None:
            proc.terminate()
            try:
                proc.wait(20)
            except subprocess.TimeoutExpired:
                proc.kill()
        pad.close()
    if log.exists():
        shutil.copy(log, out / "emulog.txt")
    print(f"PCSX2 was {status} at the end; {len([s for s in shots if s])} screenshots in {out}")


def save_shot(pad, data, out, t):
    """Press the pad's Guide button, bound to PCSX2's Screenshot hotkey; collect the PNG from snaps/."""
    sdir = data / "snaps"
    before = set(sdir.rglob("*.png")) if sdir.exists() else set()
    pad.press(["mode"])
    for _ in range(50):
        time.sleep(0.1)
        new = sorted(set(sdir.rglob("*.png")) - before) if sdir.exists() else []
        if new:
            for _ in range(50):          # PCSX2 writes the PNG on a worker thread: wait for IEND
                time.sleep(0.1)
                if new[0].read_bytes()[-8:-4] == b"IEND":
                    break
            dst = out / f"shot_{t:03d}s.png"
            shutil.copy(new[0], dst)
            print(f"{t:6.1f}s {dst.relative_to(ROOT)}")
            return dst
    print(f"{t:6.1f}s no screenshot appeared")
    return None


if __name__ == "__main__":
    main()
