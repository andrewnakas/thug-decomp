extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Obj11ABA8 {
    int m_pad[5];
    virtual void Update();
    virtual ~Obj11ABA8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj11ABA8::~Obj11ABA8()
{
}
