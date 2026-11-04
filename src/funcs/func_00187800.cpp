extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00184D50();
extern "C" void func_00184D30();

struct N_00187800 {
    int m0;
    int m4;
    int m8;
    N_00187800* m_next;
    N_00187800* m_prev;
    virtual void V0();
    virtual ~N_00187800()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct X_00187800 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~X_00187800();
};

struct B_00187800 {
    int m0;
    N_00187800 m_node;
    char pad1C[0x2C - 0x1C];
    virtual void V0();
    virtual ~B_00187800() {}
};

struct C_00187800 : B_00187800 {
    N_00187800 m_node2;
    X_00187800* m_obj;
    virtual void V0();
    virtual ~C_00187800();
    void Unregister(void* f, int a);
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

C_00187800::~C_00187800()
{
    Unregister((void*)func_00184D50, 0);
    Unregister((void*)func_00184D30, 0);
    delete m_obj;
}
