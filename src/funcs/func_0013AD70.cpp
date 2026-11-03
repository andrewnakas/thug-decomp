extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Obj13AD70 {
    int m_pad[5];
    virtual void Update();
    virtual ~Obj13AD70();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj13AD70::~Obj13AD70()
{
}
