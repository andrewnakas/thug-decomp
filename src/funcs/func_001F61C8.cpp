extern "C" int func_0031BCE0(int);
extern "C" void func_0031BCC0(int);
extern "C" void func_001F5AF8(int);
extern "C" void func_001F5A88(int);

#define REG_001F61C8(a) (*(volatile unsigned int*)(a))

struct Ctx_001F61C8;
extern "C" int func_001F5A40(Ctx_001F61C8*, unsigned int);

struct Ctx_001F61C8 {
    unsigned int m0;
    unsigned int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
    int m40;
    int m44;
};

int func_001F61C8(Ctx_001F61C8* c)
{
    unsigned int v = c->m38;
    unsigned int s6 = v & 0x7F;
    unsigned int n = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    unsigned int addr = c->m1C - n * 16;
    unsigned int qwc = c->m24 + n;
    unsigned int ctrl = c->m28 | 0x100;
    unsigned int src = c->m20;
    func_0031BCE0(c->m40);
    if (addr < c->m0) {
        int cnt = c->m8;
        unsigned int size = cnt << 11;
        qwc = (c->m0 - addr) >> 4;
        src = c->m4 & 0x0FFFFFFF;
        addr += size;
        int t = 0;
        if (c->m1C != c->m0)
            t = (c->m1C == c->m0 + size) ? 0 : 3;
        ctrl = (c->m28 & 0x0FFFFFFF) | (t << 28) | 0x100;
        if ((cnt - c->mC) % cnt < 0 || (cnt - c->mC) % cnt >= c->m10) {
            c->mC = cnt - 1;
            c->m10 = c->m10 + 1;
        }
    } else {
        int s1 = func_001F5A40(c, c->m1C);
        int s2 = func_001F5A40(c, addr);
        if (s1 != s2) {
            int cnt = c->m8;
            unsigned int base = c->m0;
            unsigned int a = base + (c->m1C - base) % (unsigned int)(cnt << 11);
            qwc = (base + (s1 << 11) - addr) >> 4;
            src = (s1 * 16 + c->m4) & 0x0FFFFFFF;
            unsigned int b = base + (((c->mC + c->m10) % cnt) << 11);
            int t = (a == b) ? 0 : 3;
            ctrl = (c->m28 & 0x0FFFFFFF) | (t << 28) | 0x100;
            if ((s2 + cnt - c->mC) % cnt < 0 || (s2 + cnt - c->mC) % cnt >= c->m10) {
                c->m10 = c->m10 + 1;
                c->mC = s2;
            }
        }
    }
    if (c->m2C && c->m30) {
        REG_001F61C8(0x1000B010) = c->m2C;
        REG_001F61C8(0x1000B020) = c->m30;
        func_001F5A88(c->m34 | 0x100);
    }
    if (c->m10) {
        while ((int)REG_001F61C8(0x10002010) < 0)
            ;
        REG_001F61C8(0x10002000) = s6;
        while ((int)REG_001F61C8(0x10002010) < 0)
            ;
    }
    REG_001F61C8(0x1000B410) = addr;
    REG_001F61C8(0x1000B430) = src;
    REG_001F61C8(0x1000B420) = qwc;
    if (c->m10)
        func_001F5AF8(ctrl);
    REG_001F61C8(0x10002010) = c->m3C;
    c->m44 = 1;
    func_0031BCC0(c->m40);
    return 1;
}
