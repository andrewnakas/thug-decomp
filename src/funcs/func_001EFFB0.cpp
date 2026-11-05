extern "C" int func_0010FC30();

struct C_001EFFB0 {
    char m_pad[0x9C];
    int m9C;
    int mA0;
    int mA4;
    void Start(int a);
};

void C_001EFFB0::Start(int a)
{
    mA0 = a;
    mA4 = 2;
    m9C = func_0010FC30();
}
