/* fuzzy: 91.8 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Res_00152E08 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x2C - 0x20];
    int m2C;
};

extern void* D_00393EF8;
extern "C" Res_00152E08* func_00139468(void* table, int id);
extern "C" long func_00168738(int a, int b);

struct Base13F8B0 {
    int m0;
    int m4;
    Base13F8B0();
    virtual ~Base13F8B0();
};

struct Elem13F778 {
    char m_pad[0x30];
    Elem13F778();
    ~Elem13F778();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Data1530C8 {
    int m0;
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Color_00152E08 {
    unsigned char r, g, b, a;
    Color_00152E08() {}
};

struct Comp1530C8 : Base13F8B0 {
    char m_padC[0x164 - 0xC];
    int m164;
    int m168;
    char m_pad16C[0x1C4 - 0x16C];
    int m1C4;
    char m_pad1C8[0x1CC - 0x1C8];
    Elem13F778* m1CC;
    char m_pad1D0[0x1E4 - 0x1D0];
    float m1E4;
    char m_pad1E8[0x200 - 0x1E8];
    Data1530C8* m200;
    char m_pad204[0x208 - 0x204];
    long m208;
    Color_00152E08 m210[4];
    Color_00152E08 m220[4];
    Color_00152E08 m230[4];
    int m240;
    Comp1530C8(int owner, int n, int id, int a, int b);
    virtual void Update();
    virtual ~Comp1530C8();
};

Comp1530C8::Comp1530C8(int owner, int n, int id, int a, int b)
{
    m1C4 = owner;
    m164 = n;
    m168 = 0;
    m1CC = new Elem13F778[n];
    m200 = new Data1530C8[n * 3];
    m240 = 0;
    Res_00152E08* r = func_00139468(D_00393EF8, id);
    if (r) {
        int v = r->m2C;
        if (v == 0) v = r->m1C;
        m240 = v;
    }
    m208 = func_00168738(a, b);
    for (int i = 0; i < 4; i++) {
        m220[i].r = 0x80;
        m220[i].g = 0x80;
        m220[i].b = 0x80;
        m220[i].a = 0x80;
        m230[i].r = 0x80;
        m230[i].g = 0x80;
        m230[i].b = 0x80;
        m230[i].a = 0x80;
        m210[i].r = 0x80;
        m210[i].g = 0x80;
        m210[i].b = 0x80;
        m210[i].a = 0x80;
    }
    m1E4 = -1.0f;
}
