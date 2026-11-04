extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct Node_001D0FC8 {
    int m_pad[8];
    virtual ~Node_001D0FC8() = 0;
    virtual void Update();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node_001D0FC8::~Node_001D0FC8()
{
}
