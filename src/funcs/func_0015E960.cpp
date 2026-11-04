extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00139468(void* mgr, int id);
extern "C" long func_00168738(int a, int b);
extern void* D_00388A70;
extern void* D_00393EF8;

struct Base13F8B0 {
    int m0;
    int m4;
    Base13F8B0();
    virtual ~Base13F8B0();
};

struct Tex_0015E960 {
    char pad0[0x28];
    long m28;
    long m30;
};

extern "C" int func_0017EDA8(Tex_0015E960* t);
extern "C" int func_0017ED88(Tex_0015E960* t);

struct Info_0015E960 {
    char m_pad[0x1C];
    Tex_0015E960* m1C;
    char m_pad20[0x2C - 0x20];
    Tex_0015E960* m2C;
};

struct Hdr_0015E960 {
    char pad[0x2C];
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Part_0015E960 {
    char pad[0x20];
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Comp_0015E960 : Base13F8B0 {
    char m_padC[0x1A4 - 0xC];
    float m1A4;
    float m1A8;
    char m_pad1AC[0x1C4 - 0x1AC];
    int m1C4;
    char m_pad1C8[0x1E4 - 0x1C8];
    float m1E4;
    char m_pad1E8[0x20C - 0x1E8];
    Tex_0015E960* m20C;
    long m210;
    int m218;
    int m21C;
    int m220;
    Hdr_0015E960* m224;
    Part_0015E960* m228;
    Part_0015E960* m22C;
    Part_0015E960* m230;
    float m234;
    int m238;
    char m_pad23C[0x280 - 0x23C];
    int m280;
    int m284;
    int m288;
    int m28C;
    long m290;
    int m298;
    char m_pad29C[0x2A0 - 0x29C];
    long m2A0;
    int m2A8;
    char m_pad2AC[0x2B0 - 0x2AC];
    long m2B0;
    int m2B8;
    char m_pad2BC[0x2C0 - 0x2BC];
    int m2C0;
    char m_pad2C4[0x2C8 - 0x2C4];
    int m2C8;
    char m_pad2CC[0x2D0 - 0x2CC];
    int m2D0;
    int m2D4;
    int m2D8;
    int m2DC;
    char m_pad2E0[0x374 - 0x2E0];
    int m374;
    int m378;
    Comp_0015E960(int a, int n, int id, int b, int c);
    virtual void Update();
    virtual ~Comp_0015E960();
};

Comp_0015E960::Comp_0015E960(int a, int n, int id, int b, int c)
{
    m1C4 = a;
    m218 = n;
    m21C = 0;
    m20C = 0;
    Info_0015E960* info = (Info_0015E960*)func_00139468(D_00393EF8, id);
    if (info) {
        Tex_0015E960* t = info->m2C;
        if (!t) t = info->m1C;
        m20C = t;
    }
    m210 = func_00168738(b, c);
    m220 = 1;
    m224 = new Hdr_0015E960;
    Part_0015E960* p = new Part_0015E960[m218];
    m228 = p;
    m22C = p + m218 - 1;
    m230 = p;
    m234 = (m1A4 + m1A8) * 0.5f;
    m238 = 0;
    m280 = 0x8004;
    m284 = 0x10000000;
    m288 = 0xE;
    m28C = 0;
    m290 = m210;
    m298 = 0x42;
    if (m20C) {
        m2D0 = 8;
        m2D4 = func_0017EDA8(m20C) * 16 - 8;
        m2D8 = func_0017ED88(m20C) * 16 - 8;
        m2DC = 8;
        m2A0 = m20C->m28;
        m2B0 = m20C->m30;
    }
    m2A8 = 6;
    m2B8 = 0x14;
    m2C0 = 0x5000B;
    m2C8 = 0x47;
    m374 = 0x60AB4000;
    m378 = 0x434312;
    m1E4 = -1.0f;
}
