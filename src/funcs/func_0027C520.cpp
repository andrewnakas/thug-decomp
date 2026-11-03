extern "C" int func_0010FC30();
extern "C" void func_00184920(void* obj, unsigned int name, float a, int b);
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" unsigned int func_0033EBE0(float x);

struct Vec_0027C520 {
    float x, y, z, w;
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

struct Flag_0027C520 {
    int m0;
    int m4;
    int m8;
    void Set(int v)
    {
        if (m4 != v) {
            m4 = v;
            m8 = func_0010FC30();
        }
    }
};

struct Phys_0027C520 {
    char m_pad[0x1C];
    int m1C;
    char m_pad2[0x6C - 0x20];
    Flag_0027C520 m6C;
    char m_pad3[0x140 - 0x78];
    Vec_0027C520 m140;
    int m150;
    char m_pad4[0x160 - 0x154];
    Vec_0027C520 m160;
    Vec_0027C520 m170;
};

struct Skater_0027C520 {
    char m_pad[0xC];
    void* mC;
    char m_pad2[0x9C - 0x10];
    int m9C;
    char m_pad3[0x2A4 - 0xA0];
    unsigned int m2A4;
    unsigned int m2A8;
    unsigned int m2AC;
    char m_pad4[0x58C - 0x2B0];
    int m58C;
    char m_pad5[0x5B0 - 0x590];
    Phys_0027C520* m5B0;
    void Reset();
};

void Skater_0027C520::Reset()
{
    if (m58C) {
        m58C = 0;
        func_00184920(mC, 0x5E27200A, 0.0f, 0);
    }
    m2AC = func_0033EBE0(func_002032A0(0xE4412EB7, 0));
    if (m2A4 < m2A8)
        m2A4 = m2A8;
    if (m5B0->m1C == 1 && m9C == 3)
        m5B0->m6C.Set(0);
    m5B0->m1C = 0;
    m5B0->m160.Set(0.0f, 1.0f, 0.0f);
    m5B0->m170.Set(0.0f, 1.0f, 0.0f);
    m5B0->m140.Set(0.0f, 0.0f, 0.0f);
    m5B0->m150 = 0;
}
