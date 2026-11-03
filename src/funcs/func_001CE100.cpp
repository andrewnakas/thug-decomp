struct Sk_001CE100 {
    char m_pad[0x20];
    int m20;
    float m24;
    float m28;
};

struct Tune_001CE100 {
    char m_pad[0xC0];
    float mC0;
    char m_padC4[0xCC - 0xC4];
    float mCC;
    char m_padD0[0x10C - 0xD0];
    float m10C;
};

struct Cam_001CE100 {
    char m_pad[0x28];
    float m28;
    char m_pad2C[0xA4 - 0x2C];
    Sk_001CE100* mA4;
    char m_padA8[0xAC - 0xA8];
    Tune_001CE100* mAC;
    void GetZoom(float* fov, float* dist);
};

void Cam_001CE100::GetZoom(float* fov, float* dist)
{
    float target = 1.0f;
    if (mA4->m20 && mA4->m24 != 1.0f)
        target = mA4->m24;
    m28 += (target - m28) * mAC->m10C;
    *dist = mAC->mC0 * m28;
    if (mA4->m28 < 0.0f) {
        float range = 0.628f;
        *dist = *dist * ((mA4->m28 + range) / range * 0.6f + 0.4f);
    }
    float f = mAC->mCC;
    if (m28 < 1.0f)
        f = (f - 3.0f) * m28 + 3.0f;
    *fov = f;
}
