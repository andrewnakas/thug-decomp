extern int D_00394340;
extern "C" int func_001E2468(int op, unsigned short a, unsigned short b, int c, int d, int e);
extern "C" void func_001E2818();

extern "C" int func_001E23E0(unsigned short a, unsigned short b, int c, int d, int e)
{
    D_00394340 = 1;
    if (!func_001E2468(0x80D0, a, b, c, d, e))
        return 0;
    if (!func_001E2468(0x80F0, a, 1, 0, 0, 0))
        return 0;
    func_001E2818();
    return 1;
}
