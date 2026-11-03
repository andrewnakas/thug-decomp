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

struct Elem13F778 {
    char m_pad[0x30];
    Elem13F778();
    ~Elem13F778();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Data154628 {
    int m0;
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Rgba155170 {
    unsigned char r, g, b, a;
    Rgba155170() {}
};

struct Info139468 {
    char m_pad[0x1C];
    int m1C;
    char m_pad20[0x2C - 0x20];
    int m2C;
};

struct Comp155170 : Base13F8B0 {
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
    Data154628* m200;
    char m_pad204[0x208 - 0x204];
    long m208;
    int m210;
    float m214;
    Rgba155170 m218[3];
    Rgba155170 m224[3];
    Rgba155170 m230[3];
    int m23C;
    Comp155170(int a, int n, float f, int id, int b, int c, int d);
    virtual void Update();
    virtual ~Comp155170();
};

Comp155170::Comp155170(int a, int n, float f, int id, int b, int c, int d)
{
    m1C4 = a;
    m164 = n;
    m168 = 0;
    m1CC = new Elem13F778[n];
    m200 = new Data154628[n * 3];
    m23C = 0;
    Info139468* info = (Info139468*)func_00139468(D_00393EF8, id);
    if (info) {
        int v = info->m2C;
        if (!v) v = info->m1C;
        m23C = v;
    }
    m208 = func_00168738(b, c);
    for (int i = 0; i < 3; i++) {
        m218[i].r = 0x80;
        m218[i].g = 0x80;
        m218[i].b = 0x80;
        m218[i].a = 0x80;
        m224[i].r = 0x80;
        m224[i].g = 0x80;
        m224[i].b = 0x80;
        m224[i].a = 0x80;
        m230[i].r = 0x80;
        m230[i].g = 0x80;
        m230[i].b = 0x80;
        m230[i].a = 0x80;
    }
    m210 = d;
    m214 = f;
    m1E4 = -1.0f;
}
