extern int D_003940F0[2];
extern int D_003940F8[2];
extern int D_003940E8[2];
extern "C" void func_001DEEE0();
extern "C" void func_001DEF18(int);
extern "C" void func_001E22B0();
extern "C" void func_001E23B0(int, unsigned short, int);

void func_001E1E50()
{
    func_001DEEE0();
    func_001DEF18(-1);
    for (int i = 0; i < 2; i++) {
        D_003940F0[i] = 1;
        D_003940F8[i] = 0;
        D_003940E8[i] = 0;
        func_001E22B0();
        func_001E23B0(0x8030, i | 0x1600, 0x1FFFFF);
        func_001E23B0(0x8030, i | 0x1700, 0);
        D_003940F0[i] = 0;
    }
}
