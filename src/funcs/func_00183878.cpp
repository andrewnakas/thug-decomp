extern "C" int abs(int);

struct C_00183878 {
    unsigned char m0;
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
    unsigned char m_a;
    char pad5[0x13 - 0x5];
    unsigned char m_r2;
    unsigned char m_g2;
    unsigned char m_b2;
    unsigned char m_a2;
    void Snap();
};

static inline bool Near(int c)
{
    return abs(128 - c) < 51;
}

void C_00183878::Snap()
{
    m_r2 = m_r;
    m_g2 = m_g;
    m_b2 = m_b;
    m_a2 = m_a;
    if (Near(m_r)) m_r = 128;
    if (Near(m_g)) m_g = 128;
    if (Near(m_b)) m_b = 128;
    if (Near(m_a)) m_a = 128;
    if (Near(m_r2) && Near(m_g2)) {
        m_r2 = 128;
        m_g2 = 128;
    }
    if (Near(m_b2) && Near(m_a2)) {
        m_b2 = 128;
        m_a2 = 128;
    }
}
