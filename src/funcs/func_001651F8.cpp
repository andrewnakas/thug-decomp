extern "C" int func_00345160(int mode);
extern "C" int func_003449F8(int a, int b, int c, int d);

extern int D_0038882C;
extern int D_0038B900;

static inline bool IsPal_001651F8() { return D_0038882C == 1; }

struct Pmode_001651F8 {
    unsigned long en1 : 1;
    unsigned long en2 : 1;
    unsigned long crtmd : 3;
    unsigned long mmod : 1;
    unsigned long amod : 1;
    unsigned long slbg : 1;
    unsigned long alp : 8;
    unsigned long zero : 16;
    unsigned long pad : 32;
} __attribute__((packed));

struct Smode2_001651F8 {
    unsigned long intr : 1;
    unsigned long ffmd : 1;
    unsigned long dpms : 2;
    unsigned long pad : 60;
} __attribute__((packed));

struct Dispfb_001651F8 {
    unsigned long fbp : 9;
    unsigned long fbw : 6;
    unsigned long psm : 5;
    unsigned long pad0 : 12;
    unsigned long dbx : 11;
    unsigned long dby : 11;
    unsigned long pad1 : 10;
} __attribute__((packed));

struct Display_001651F8 {
    unsigned long dx : 12;
    unsigned int dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long pad0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long pad1 : 9;
} __attribute__((packed));

struct Bgcolor_001651F8 {
    unsigned long r : 8;
    unsigned long g : 8;
    unsigned long b : 8;
    unsigned long pad : 40;
} __attribute__((packed));

void func_001651F8(int interlace, int field, int width, int height)
{
    Smode2_001651F8 smode2;
    Pmode_001651F8 pmode;
    Dispfb_001651F8 dispfb1;
    Display_001651F8 display1;
    Dispfb_001651F8 dispfb2;
    Display_001651F8 display2;
    Bgcolor_001651F8 bgcolor;

    if (D_0038B900 == 0) {
        func_00345160(0);
        if (IsPal_001651F8()) {
            func_003449F8(0, 1, 2, 0);
        } else {
            func_003449F8(0, 1, 3, 0);
        }
        D_0038B900 = 1;
    }
    if (width == 0) {
        width = (D_0038882C == 1) ? 0x280 : 0x200;
    }
    if (height == 0) {
        height = (D_0038882C == 1) ? 0x1C0 : 0x200;
    }

    smode2.intr = 1;
    smode2.ffmd = field;
    smode2.dpms = 0;
    pmode.en1 = 1;
    pmode.en2 = 1;
    pmode.crtmd = 1;
    pmode.mmod = 1;
    pmode.amod = 0;
    pmode.slbg = interlace == 0;
    pmode.alp = interlace ? 0x80 : 0;

    dispfb2.fbp = width * height / 2048;
    dispfb2.fbw = width / 64;
    dispfb2.psm = 10;
    dispfb2.dbx = 0;
    dispfb2.dby = 0;
    pmode.zero = 0;
    pmode.pad = 0;

    if (IsPal_001651F8()) {
        display2.dx = 0x27C;
        display2.dy = 0x32;
    } else {
        display2.dx = 0x290;
        display2.dy = 0x48;
    }
    display2.magh = 0xA00 / width - 1;
    display2.magv = 0;
    display2.dw = 0x9FF;
    display2.dh = height - 1;

    dispfb1 = dispfb2;
    display1 = display2;
    bgcolor.r = 0;
    bgcolor.g = 0;
    bgcolor.b = 0;
    display1.dy = (int)display1.dy - 1;

    func_00345160(0);
    *(volatile unsigned long*)0x12000020 = *(unsigned long*)&smode2;
    *(volatile unsigned long*)0x12000070 = *(unsigned long*)&dispfb1;
    *(volatile unsigned long*)0x12000080 = *(unsigned long*)&display1;
    *(volatile unsigned long*)0x12000090 = *(unsigned long*)&dispfb2;
    *(volatile unsigned long*)0x120000A0 = *(unsigned long*)&display2;
    *(volatile unsigned long*)0x120000E0 = *(unsigned long*)&bgcolor;
    *(volatile unsigned long*)0x12000000 = *(unsigned long*)&pmode;
}
