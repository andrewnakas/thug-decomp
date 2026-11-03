extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00135DA0(void* p);
extern void* D_00388A70;

struct C_00126F28 {
    char pad[0x1AC];
    void** m1AC;
    void** m1B0;
    int m1B4;
    void Free(int keep);
};

void C_00126F28::Free(int keep)
{
    if (m1B0) {
        for (int i = 0; i < m1B4; i++)
            func_00135DA0(m1B0[i]);
        func_0010A8D8(D_00388A70, m1B0);
        m1B0 = 0;
    }
    if (!keep) {
        for (int i = 0; i < m1B4; i++)
            func_00135DA0(m1AC[i]);
        func_0010A8D8(D_00388A70, m1AC);
        m1B4 = 0;
    }
}
