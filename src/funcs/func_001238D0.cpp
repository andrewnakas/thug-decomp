struct Node183CB8;

extern "C" void func_00183CB8(void* list, Node183CB8* node);

struct Node183CB8 {
    void* m_list;
    Node183CB8* m_prev;
    Node183CB8* m_next;
    Node183CB8()
    {
        m_prev = 0;
        m_next = 0;
        m_list = 0;
    }
    ~Node183CB8()
    {
        if (m_list) {
            func_00183CB8(m_list, this);
            m_list = 0;
        }
    }
};

struct B_00183D80 {
    int m0;
    int m4;
    virtual void V0();
    virtual ~B_00183D80();
};

struct C_001238D0 : B_00183D80 {
    char padC[0xC];
    unsigned int m18;
    char pad1C[0x2C];
    Node183CB8 m48;
    Node183CB8 m54;
    Node183CB8 m60;
    Node183CB8 m6C;
    virtual void V0();
    virtual ~C_001238D0();
};

extern "C" void func_00125418(C_001238D0* o, Node183CB8* n, int a);

C_001238D0::~C_001238D0()
{
    {
        Node183CB8 n;
        func_00125418(this, &n, 0);
    }
    m18 = 0xDEADBEEF;
}
