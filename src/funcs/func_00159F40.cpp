extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Base13F8B0 {
    int m0;
    int m4;
    Base13F8B0();
    virtual ~Base13F8B0();
};

struct Elem13F778 {
    char m_pad[0x30];
    ~Elem13F778();
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Data159BC8 {
    int m0;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Row159BC8 {
    Data159BC8* p;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Rgba159BC8 {
    unsigned char r, g, b, a;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Comp159BC8 : Base13F8B0 {
    char m_padC[0x1CC - 0xC];
    Elem13F778* m1CC;
    char m_pad1D0[0x200 - 0x1D0];
    int m200;
    Row159BC8* m204;
    char m_pad208[0x220 - 0x208];
    Rgba159BC8* m220;
    Rgba159BC8* m224;
    Rgba159BC8* m228;
    Comp159BC8();
    virtual void Update();
    virtual ~Comp159BC8();
};

Comp159BC8::~Comp159BC8()
{
    delete[] m1CC;
    for (int i = 0; i < m200; i++) {
        delete[] m204[i].p;
    }
    delete[] m204;
    delete[] m220;
    delete[] m224;
    delete[] m228;
}
