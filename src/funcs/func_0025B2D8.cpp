extern "C" int func_00119818(void* p);

struct C_0025B2D8 {
    char m_pad[0x1C];
    int m1C;
    char m20[0x20];
    char m40[4];
    bool Check();
};

bool C_0025B2D8::Check()
{
    return m1C && func_00119818(m40);
}
