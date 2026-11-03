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

struct Data1530C8 {
    int m0;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Comp1530C8 : Base13F8B0 {
    char m_padC[0x1CC - 0xC];
    Elem13F778* m1CC;
    char m_pad1D0[0x200 - 0x1D0];
    Data1530C8* m200;
    Comp1530C8();
    virtual void Update();
    virtual ~Comp1530C8();
};

Comp1530C8::~Comp1530C8()
{
    delete[] m1CC;
    delete[] m200;
}
