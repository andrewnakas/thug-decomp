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

struct Data158248 {
    int m0;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Row158248 {
    Data158248* p;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Rgba158248 {
    unsigned char r, g, b, a;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Comp158248 : Base13F8B0 {
    char m_padC[0x1CC - 0xC];
    Elem13F778* m1CC;
    char m_pad1D0[0x200 - 0x1D0];
    int m200;
    Row158248* m204;
    char m_pad208[0x218 - 0x208];
    Rgba158248* m218;
    Rgba158248* m21C;
    Rgba158248* m220;
    Comp158248();
    virtual void Update();
    virtual ~Comp158248();
};

Comp158248::~Comp158248()
{
    delete[] m1CC;
    for (int i = 0; i < m200; i++) {
        delete[] m204[i].p;
    }
    delete[] m204;
    delete[] m218;
    delete[] m21C;
    delete[] m220;
}
