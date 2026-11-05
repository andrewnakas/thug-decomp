extern "C" int func_00119818(void* p);

struct C_0025BE78 {
    char m_pad[0x1C];
    int m1C;
    int m20;
    int m24;
    char m28[0x54];
    char m7C[4];
    int Check();
};

int C_0025BE78::Check()
{
    if (m24) return 1;
    if (m1C) return 0;
    return func_00119818(m7C);
}
