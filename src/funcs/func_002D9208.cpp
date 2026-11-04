extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Owned_002D9208 {
    int m0[6];
    virtual void A();
    virtual void B();
    virtual ~Owned_002D9208();
};

struct NodeA_002D9208 {
    int m0;
    void* m_data;
    int m8;
    NodeA_002D9208* m_next;
    NodeA_002D9208* m_prev;
    virtual void Key();
    virtual ~NodeA_002D9208()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct NodeB_002D9208 {
    int m0;
    void* m_data;
    int m8;
    NodeB_002D9208* m_next;
    NodeB_002D9208* m_prev;
    virtual void Key();
    virtual ~NodeB_002D9208()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Elem_002D9208 {
    NodeA_002D9208 m0;
    NodeB_002D9208 m18;
    char pad30[0x20];
};

struct Obj_002D9208 {
    Owned_002D9208* m0;
    char pad4[0x7C - 4];
    Elem_002D9208 m7C[5];
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002D9208();
};

Obj_002D9208::~Obj_002D9208()
{
    delete m0;
}
