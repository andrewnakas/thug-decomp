/* fuzzy: 97.3 */
struct State_001BA1F8 {
    char pad[0x1C];
    int m_mode;
    char pad20[0x20];
    int m40;
    char pad44[0x20];
    int m64;
    char pad68[0x44];
    int mAC;
    char padB0[0x88];
    int m138;
};

struct Settings_001BA1F8 {
    char pad[0x20];
    int m_scaleOn;
    float m_scale;
    float m_slope;
};

extern float D_00387A4C;
extern float D_00387A50;
extern float D_00387A54;

struct C_001BA1F8 {
    char pad[0xC0];
    float mC0;
    char padC4[0x8];
    float mCC;
    char padD0[0x30];
    int m100;
    float m104;
    float m108;
    float m10C;
    float m110;
    float m114;
    float m118;
    char pad11C[0x14];
    float m130;
    char pad134[0x2C];
    Settings_001BA1F8* m160;
    char pad164[0x4];
    int m168;
    State_001BA1F8* m16C;
    void Get(float* a, float* b);
};

void C_001BA1F8::Get(float* a, float* b)
{
    if (!m168)
        return;
    m108 = 1.0f;
    if (!m100 && m16C->m40 && !m16C->m64 && !m16C->mAC && m16C->m138)
        m100 = 1;
    else if (!m16C->m40 || m16C->m64 || m16C->mAC)
        m100 = 0;
    if (m100) {
        m108 = m110;
    } else if (m16C->m_mode == 4) {
        m108 = m114;
    } else if (m16C->m_mode == 3) {
        m108 = m118;
    }
    if (m160->m_scaleOn && m160->m_scale != 1.0f)
        m108 *= m160->m_scale;
    m104 += (m108 - m104) * m10C;
    float r = mC0 * m104;
    *b = r;
    if (m160->m_slope < 0.0f)
        *b = r * ((m160->m_slope + D_00387A4C) / D_00387A4C * D_00387A50 + D_00387A54);
    float c = mCC;
    if (m16C->m_mode == 3)
        c = m130;
    if (m104 < 1.0f)
        *a = (c - 3.0f) * m104 + 3.0f;
    else
        *a = c;
}
