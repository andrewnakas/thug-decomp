extern "C" int func_0031AA28(int, int, unsigned char*);

struct Lock_00107CA0 {
    int m0;
    int m_count;
};

struct Pad_00107CA0 {
    char pad[0x10];
    int m_10;
    int m_14;
    char pad18[0x60 - 0x18];
    unsigned char m_60[0x20];
    unsigned char m_80[0x20];
    unsigned char m_A0[0x20];
    Lock_00107CA0 m_lock;
    int m_C8;
    int m_CC;
    int m_D0;
    int m_D4;
    int padD8;
    int m_DC;
    void SetActuator(int i, int level);
};

void Pad_00107CA0::SetActuator(int i, int level)
{
    if (m_C8)
        return;
    if (m_DC == 2 && (m_CC & 2) && i >= 0 && i < m_D4) {
        float v = (float)level * (float)m_80[i] * 0.01f;
        if (m_80[i] == 1) {
            if (v > 0.001f)
                m_60[i] = 1;
            else
                m_60[i] = 0;
        } else {
            m_60[i] = (int)v;
        }
        func_0031AA28(m_10, m_14, m_60);
    }
}
