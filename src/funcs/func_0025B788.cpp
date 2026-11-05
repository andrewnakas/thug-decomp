extern "C" void func_00118158(void* a, int b, int c);

struct C_0025B788 {
    char m_pad[0x18];
    int m18;
    char m1C[0x5C];
    void* m78;
    int Run(int a);
};

int C_0025B788::Run(int a)
{
    if (m78) func_00118158(m78, m18, a);
    return 1;
}
