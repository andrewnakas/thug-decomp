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

struct Data1524D0 {
    int m0;
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Rgba1524D0 {
    unsigned char r, g, b, a;
};

struct Info139468 {
    char m_pad[0x1C];
    int m1C;
    char m_pad20[0x2C - 0x20];
    int m2C;
};

struct Comp1524D0 : Base13F8B0 {
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
    Data1524D0* m200;
    char m_pad204[0x208 - 0x204];
    long m208;
    Rgba1524D0 m210;
    Rgba1524D0 m214;
    Rgba1524D0 m218;
    int m21C;
    Comp1524D0(int a, int n, int id, int b, int c);
    virtual void Update();
    virtual ~Comp1524D0();
};

Comp1524D0::Comp1524D0(int a, int n, int id, int b, int c)
{
    m1C4 = a;
    m164 = n;
    m168 = 0;
    m1CC = new Elem13F778[n];
    m200 = new Data1524D0[n * 3];
    m21C = 0;
    Info139468* info = (Info139468*)func_00139468(D_00393EF8, id);
    if (info) {
        int v = info->m2C;
        if (!v) v = info->m1C;
        m21C = v;
    }
    m208 = func_00168738(b, c);
    m210.r = 0x80;
    m210.g = 0x80;
    m210.b = 0x80;
    m210.a = 0x80;
    m214.r = 0x80;
    m214.g = 0x80;
    m214.b = 0x80;
    m214.a = 0x80;
    m218.r = 0x80;
    m218.g = 0x80;
    m218.b = 0x80;
    m218.a = 0x80;
    m1E4 = -1.0f;
}
