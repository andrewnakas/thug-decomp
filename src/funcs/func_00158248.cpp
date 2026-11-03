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

struct Data158248 {
    int m0;
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Row158248 {
    Data158248* p;
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Rgba158248 {
    unsigned char r, g, b, a;
    Rgba158248() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Info139468 {
    char m_pad[0x1C];
    int m1C;
    char m_pad20[0x2C - 0x20];
    int m2C;
};

struct Comp158248 : Base13F8B0 {
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
    int m200;
    Row158248* m204;
    char m_pad208[0x210 - 0x208];
    long m210;
    Rgba158248* m218;
    Rgba158248* m21C;
    Rgba158248* m220;
    int m224;
    Comp158248(int a, int n, int id, int b, int c, int unused, int last);
    virtual void Update();
    virtual ~Comp158248();
};

Comp158248::Comp158248(int a, int n, int id, int b, int c, int unused, int last)
{
    m1C4 = a;
    m164 = n;
    m168 = 0;
    m1CC = new Elem13F778[n];
    m204 = new Row158248[last + 1];
    for (int i = 0; i < last + 1; i++) {
        m204[i].p = new Data158248[n * 3];
    }
    m200 = last + 1;
    m224 = 0;
    Info139468* info = (Info139468*)func_00139468(D_00393EF8, id);
    if (info) {
        int v = info->m2C;
        if (!v) v = info->m1C;
        m224 = v;
    }
    m210 = func_00168738(b, c);
    m218 = new Rgba158248[m200];
    m21C = new Rgba158248[m200];
    m220 = new Rgba158248[m200];
    for (int i = 0; i < m200; i++) {
        m218[i].r = 0x80;
        m218[i].g = 0x80;
        m218[i].b = 0x80;
        m218[i].a = 0x80;
        m21C[i].r = 0x80;
        m21C[i].g = 0x80;
        m21C[i].b = 0x80;
        m21C[i].a = 0x80;
        m220[i].r = 0x80;
        m220[i].g = 0x80;
        m220[i].b = 0x80;
        m220[i].a = 0x80;
    }
    m1E4 = -1.0f;
}
