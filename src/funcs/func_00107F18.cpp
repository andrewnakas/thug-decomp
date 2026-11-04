extern "C" int func_0031AA28(int, int, unsigned char*);

struct Lock_00107F18 {
    int m0;
    int m_count;
};

struct Pad_00107F18 {
    char pad[0x10];
    int m_10;
    int m_14;
    char pad18[0x60 - 0x18];
    unsigned char m_60[0x40];
    unsigned char m_A0[0x20];
    Lock_00107F18 m_lock;
    int m_C8;
    int m_CC;
    int m_D0;
    int m_D4;
    int padD8;
    int m_DC;
    void Func();
};

void Pad_00107F18::Func()
{
    Lock_00107F18* l = &m_lock;
    if (l->m_count && --l->m_count == 0 && m_DC == 2 && (m_CC & 2)) {
        for (int i = 0; i < m_D4; i++)
            m_60[i] = m_A0[i];
        func_0031AA28(m_10, m_14, m_60);
    }
}
