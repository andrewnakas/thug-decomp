extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_001E6AE8(void* s, int flags);
extern void* D_00388A70;

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp19D580 : Base184DD8 {
    int m1C[18];
    void* m64;
    int m68[7];
    void* m84;
    int m88;
    void* m8C;
    Comp19D580();
    virtual void Update();
    virtual ~Comp19D580();
};

Comp19D580::~Comp19D580()
{
    if (m64) func_0010A8D8(D_00388A70, m64);
    if (m84) func_001E6AE8(m84, 3);
    if (m8C) func_001E6AE8(m8C, 3);
}
