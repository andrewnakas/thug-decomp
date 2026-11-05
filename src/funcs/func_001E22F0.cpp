extern "C" void func_001E23B0(int a, unsigned short b, int c);

extern "C" void func_001E22F0()
{
    for (int i = 0; i < 2; i++)
        func_001E23B0(0x8040, i | 0x1700, 0);
}
