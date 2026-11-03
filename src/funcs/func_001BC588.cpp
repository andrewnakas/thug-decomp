extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" void func_001F0210(unsigned int id, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* s, int flags);

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp1BC588 : Base184DD8 {
    int m1C[18];
    int m64;
    Comp1BC588();
    virtual void Update();
    virtual ~Comp1BC588();
};

Comp1BC588::~Comp1BC588()
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0x40C698AF, m64);
    func_001F0210(0x2575B406, s, 0, 0, 0);
    if (s) func_001E6AE8(s, 3);
}
