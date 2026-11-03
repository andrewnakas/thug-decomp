extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Owned_002D7D80 {
    int m0[6];
    virtual void A();
    virtual void B();
    virtual ~Owned_002D7D80();
};

struct Node_002D7D80 {
    int m0;
    void* m_data;
    int m8;
    Node_002D7D80* m_next;
    Node_002D7D80* m_prev;
    virtual void Key();
    virtual ~Node_002D7D80()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_002D7D80 {
    int m0;
    int m4;
    int m8;
    Owned_002D7D80* mC;
    int m10;
    Node_002D7D80 m14;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002D7D80();
};

Obj_002D7D80::~Obj_002D7D80()
{
    delete mC;
}
