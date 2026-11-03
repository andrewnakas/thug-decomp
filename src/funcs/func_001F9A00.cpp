struct Net_001F9A00 {
    char m_pad[0x2C4];
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
};

extern "C" void func_0010FE68();
extern "C" int func_001DFD90();
extern "C" int func_001F96A0(Net_001F9A00*);
extern "C" void func_001FA658(Net_001F9A00*, int);
extern "C" int func_001F88B0(Net_001F9A00*);
extern "C" int func_001F89F0(Net_001F9A00*);

int func_001F9A00(Net_001F9A00* n)
{
    if (n->m2C8 == 0) {
        func_0010FE68();
        if (func_001DFD90())
            return 0;
        int r = func_001F96A0(n);
        n->m2C8 = 1;
        if (!r)
            return 0;
    } else if (n->m2D0) {
        func_001FA658(n, 7);
        return 0;
    }
    if (!func_001F88B0(n))
        return 0;
    if (n->m2C4 == 0 || n->m2CC != 0)
        n->m2C4 = func_001F89F0(n);
    n->m2D0 = 0;
    return n->m2C4;
}
