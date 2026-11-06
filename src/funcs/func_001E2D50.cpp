struct Port_001E2D50 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern int D_0038E280;
extern char D_00364500[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_0010E4A0(int a);
extern "C" void func_001E2A20(int a, int b, int c);

extern "C" int func_001E2D50(Port_001E2D50* p, int* out)
{
    *out = 0;
    int mask;
    if (p->m4 == 1)
        mask = 1 << p->m0;
    else
        mask = 0x10 << p->m0;
    if (D_0038E280 & mask) {
        func_00103F28(D_00364500, p->m0, p->m4 - 1, D_0038E280);
        int v = -1;
        if (p->m0)
            v = p->m0;
        *out = v;
    }
    if (!func_0010E4A0(p->mC)) {
        func_001E2A20(p->m0, p->m4 - 1, !p->m0 ? 0x30000 : 0x8000);
        return 1;
    }
    return 0;
}
