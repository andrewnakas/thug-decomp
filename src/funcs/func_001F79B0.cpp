// Qualifiers follow the exactly-matched vsync handler func_001F77B0, which declares D_0038EAA4 (enable flag)
// and D_0038EAA8 (counter) volatile and D_00394118 plain; volatile on D_00394118 would change that matched code.
extern volatile int D_0038EAA4;
extern int D_00394118;
extern volatile int D_0038EAA8;
extern "C" int func_00345160(int mode);

static inline void WaitField_001F79B0(int field)
{
    while (func_00345160(0) == field) {
    }
}

extern "C" void func_001F79B0(int field)
{
    WaitField_001F79B0(field);
    D_0038EAA4 = 1;
    D_00394118 = 0;
    D_0038EAA8 = 0;
}
