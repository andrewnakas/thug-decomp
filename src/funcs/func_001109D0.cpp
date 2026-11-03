struct Stream_001109D0 {
    char pad[0xC814];
    int m_busy;
    char pad2[0xC920 - 0xC818];
};

extern Stream_001109D0 D_003973D8[];
extern int D_0038881C;
extern int D_00388E24;
extern int D_00388E28;
extern char D_00388E40[];
extern char D_0035BC10[];
extern char D_0035BC28[];
extern char D_0035BC40[];
extern char D_0035BC58[];
extern char D_0035BC78[];
extern char D_0035BC98[];
extern char D_0035BCC0[];
extern char D_0035BCE0[];
extern char D_0035BD08[];
extern char D_0035BD20[];
extern char D_0035BD38[];
extern char D_0035BD48[];
extern char D_0035BD60[];
extern char D_0035BD78[];
extern char D_0035BD98[];
extern char D_0035BDB0[];
extern char D_0035BDD0[];
extern char D_0035BDE8[];
extern char D_0035BE00[];
extern char D_0035BE18[];
extern char D_0035BE40[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_003288E0(int);
extern "C" int func_003291C0(int);
extern "C" int func_00329070();
extern "C" void func_003331D0(char* buf, const char* fmt, ...);
extern "C" const char* func_00106818();
extern "C" int func_00320328(const char* path);
extern "C" int func_003202D8();
extern "C" void func_0031D560(int);
extern "C" void func_0031E848();
extern "C" int func_00112728(const char* name, int, int);
extern "C" int func_0031E880(const char* path, int mode);

extern "C" void func_001109D0()
{
    char path[0x80];
    char wad[0x80];
    int n = D_0038881C ? 1 : 3;
    for (int i = 0; i < n; i++) {
        D_003973D8[i].m_busy = 0;
    }
    int mode = 2;
    if (!D_0038881C) {
        return;
    }
    func_00103F28(D_0035BC10);
    func_003288E0(0);
    func_003291C0(2);
    func_00103F28(D_0035BC28);
    int type = func_00329070();
    switch (type) {
    case 0xFF:
        func_00103F28(D_0035BC40);
        break;
    case 0x14:
        func_00103F28(D_0035BC58);
        break;
    case 0x12:
        func_00103F28(D_0035BC78);
        break;
    case 0x13:
        func_00103F28(D_0035BC98);
        break;
    case 0x10:
        func_00103F28(D_0035BCC0);
        break;
    case 0x11:
        func_00103F28(D_0035BCE0);
        break;
    case 0xFE:
        func_00103F28(D_0035BD08);
        break;
    case 0xFD:
        func_00103F28(D_0035BD20);
        break;
    case 0x01:
        func_00103F28(D_0035BD38);
        break;
    case 0x00:
        func_00103F28(D_0035BD48);
        break;
    default:
        func_00103F28(D_0035BD60);
        break;
    }
    if (type == 0x12) {
        mode = 1;
        func_00103F28(D_0035BD78);
        func_003291C0(1);
        func_00103F28(D_0035BD98);
    }
    func_003331D0(path, D_0035BDB0, func_00106818());
    while (!func_00320328(path)) {
    }
    while (!func_003202D8()) {
    }
    func_0031D560(0);
    func_003288E0(0);
    func_003291C0(mode);
    func_0031E848();
    func_00103F28(D_0035BDD0);
    D_00388E24 = func_00112728(D_00388E40, 0, 0);
    func_00103F28(D_0035BDE8);
    while (D_00388E28 < 0) {
        func_003331D0(wad, D_0035BE00, func_00106818());
        if ((D_00388E28 = func_0031E880(wad, 1)) < 0) {
            func_00103F28(D_0035BE18);
        }
    }
    func_00103F28(D_0035BE40);
}
