extern "C" int func_00100030(int n);

struct Ch_0015CC60 {
    int m_period;
    int pad4;
    float m_rate;
};

struct C_0015CC60 {
    int pad0;
    Ch_0015CC60 m4;
    char pad10[0x18];
    int m28;
    int m2C;
    int pad30;
    Ch_0015CC60 m34;
    char pad40[0x4];
    int m44;
    char pad48[0x424];
    float m46C;
    float pad470;
    float m474;
    char pad478[0x18];
    unsigned char m490[0x400];
    unsigned char m890[0x400];
    unsigned char mC90[0x400];
    unsigned int m1090;
    void Update();
};

void C_0015CC60::Update()
{
    if (m2C == 0)
        return;
    if (m44) {
        float rate = m4.m_rate;
        if ((float)(0x400 / m4.m_period) < rate)
            rate = (float)(0x400 / m4.m_period);
        float old = m46C;
        float now = old + rate;
        m46C = now;
        int n = (int)now - (int)old;
        for (int i = 0; i < n; i++) {
            if (m490[m1090] != 0xFF)
                break;
            m490[m1090] = -2 - m4.m_period;
            m890[m1090] = func_00100030(0xFF);
            mC90[m1090] = func_00100030(0xFF);
            m28++;
            if (m1090 == 0) {
                m1090 = 0x19B;
            } else if (m1090 == 0x19B) {
                m1090 = 0;
                continue;
            }
            if (m1090 & 1)
                m1090 = (m1090 >> 1) ^ 0x240;
            else
                m1090 >>= 1;
        }
    } else {
        float rate = m34.m_rate;
        if ((float)(0x400 / m34.m_period) < rate)
            rate = (float)(0x400 / m34.m_period);
        float old = m474;
        float now = old + rate;
        m474 = now;
        int n = (int)now - (int)old;
        for (int i = 0; i < n; i++) {
            if (m490[m1090] != 0xFF)
                break;
            m490[m1090] = -2 - m34.m_period;
            m890[m1090] = func_00100030(0xFF);
            mC90[m1090] = func_00100030(0xFF);
            m28++;
            if (m1090 == 0) {
                m1090 = 0x19B;
            } else if (m1090 == 0x19B) {
                m1090 = 0;
                continue;
            }
            if (m1090 & 1)
                m1090 = (m1090 >> 1) ^ 0x240;
            else
                m1090 >>= 1;
        }
    }
}
