extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);
extern "C" void func_001D7610(void* p, int mode);

struct Node_001D33D8 {
    int m0;
    unsigned short m_flags;
    short m6;
    void* m8;
    virtual void Update();
    virtual ~Node_001D33D8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node_001D33D8::~Node_001D33D8()
{
    if (m8 && (m_flags & 0x8000)) {
        func_001D7610(m8, 3);
    }
}
