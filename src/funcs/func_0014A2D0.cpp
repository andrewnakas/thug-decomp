struct Img_0014A2D0 {
    char pad[0x1C];
    void* m1C;
    char pad20[0xC];
    void* m2C;
};

struct Spr_0014A2D0 {
    char pad[0x1C];
    float m1C;
    float m20;
    unsigned short m24;
    unsigned short m26;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    int m3C;
};

extern "C" void func_0017F6A0(Spr_0014A2D0* s, void* tex);

struct Elem_0014A2D0 {
    Img_0014A2D0* m_img;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    char pad20[0x8];
    unsigned short m_w;
    unsigned short m_h;
    char pad2C[0x8];
    int m34;
    char pad38[0x8];
    Spr_0014A2D0* m40;
    void Apply();
};

void Elem_0014A2D0::Apply()
{
    if (m_img) {
        func_0017F6A0(m40, m_img->m2C ? m_img->m2C : m_img->m1C);
    } else {
        func_0017F6A0(m40, 0);
    }
    m40->m1C = m4;
    m40->m20 = m8;
    m40->m24 = m_w;
    m40->m26 = m_h;
    m40->m28 = mC;
    m40->m2C = m10;
    float sx = m14 + 1.0f;
    float hw = m_w * 0.5f;
    m40->m30 = sx * hw;
    float sy = m18 + 1.0f;
    float hh = m_h * 0.5f;
    m40->m34 = sy * hh;
    m40->m38 = m1C;
    m40->m3C = m34;
}
