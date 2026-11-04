struct Color_00128948 {
    unsigned char r, g, b, a;
};

struct Sub_00128948 {
    float m0;
    char pad4[0x20 - 0x4];
    float m20;
    float m24;
    int m28;
    char pad2C[0x30 - 0x2C];
    float m30;
    float m34;
    float m38;
    char pad3C[0x50 - 0x3C];
};

struct C_00128948 {
    char pad0[0x8];
    union {
        unsigned long m8;
        struct {
            unsigned int m8lo;
            unsigned int m_flags;
        };
    };
    char pad10[0xC4 - 0x10];
    float mC4;
    Color_00128948 m_color;
    char padCC[0x130 - 0xCC];
    Sub_00128948 m130;
    float m180;
    float m184;
    float m188;
    float m18C;
    char pad190[0x194 - 0x190];
    float m194;
    char pad198[0x1A4 - 0x198];
    void* m1A4;
    void Update();
};

extern "C" int func_00125E10(C_00128948* self);
extern "C" void func_0013B8F0(void* o, int on);
extern "C" void func_0013B980(void* o, float a, float b);
extern "C" void func_0013B9B0(void* o, unsigned short w, unsigned short h);
extern "C" void func_0013BA10(void* o, float a, float b);
extern "C" void func_0013B9E0(void* o, float a, float b);
extern "C" void func_0013BAA0(void* o, int v);
extern "C" void func_0013BA70(void* o, float v);
extern "C" void func_0013BAD8(void* o, const Color_00128948& c);
extern "C" void func_0013BA40(void* o, float v);

void C_00128948::Update()
{
    int off = 0;
    if (m130.m30 < -200.0f || m130.m30 > 648.0f)
        off = 1;
    int vis = func_00125E10(this);
    func_0013B8F0(m1A4, vis);
    if (!(m8 & 0x180000000000UL))
        return;
    Color_00128948 c = m_color;
    if (m130.m0 >= 0.0001f)
        c.a = (int)(Color_00128948(m_color).a * m130.m0);
    else
        c.a = 0;
    Sub_00128948* s = &m130;
    func_0013B980(m1A4, s->m20, s->m24);
    func_0013B9B0(m1A4, (int)m188, (int)m18C);
    func_0013BA10(m1A4, m180, m184);
    func_0013B9E0(m1A4, s->m34, s->m38);
    if (m_flags & 0x80000) {
        func_0013BAA0(m1A4, s->m28);
        func_0013B8F0(m1A4, (m_flags & 0x100000) || vis);
    } else {
        func_0013BA70(m1A4, m194);
        func_0013B8F0(m1A4, off || vis);
    }
    func_0013BAD8(m1A4, Color_00128948(c));
    func_0013BA40(m1A4, mC4);
}
