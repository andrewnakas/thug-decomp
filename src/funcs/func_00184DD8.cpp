extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Obj184DD8 {
    int m_pad[6];
    virtual void Update();
    virtual ~Obj184DD8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj184DD8::~Obj184DD8()
{
}
