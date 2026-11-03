extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Owned_002D2B40 {
    int m0[6];
    virtual void A();
    virtual void B();
    virtual ~Owned_002D2B40();
};

struct NodeA_002D2B40 {
    int m0;
    void* m_data;
    int m8;
    NodeA_002D2B40* m_next;
    NodeA_002D2B40* m_prev;
    virtual void Key();
    virtual ~NodeA_002D2B40()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct NodeB_002D2B40 {
    int m0;
    void* m_data;
    int m8;
    NodeB_002D2B40* m_next;
    NodeB_002D2B40* m_prev;
    virtual void Key();
    virtual ~NodeB_002D2B40()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_002D2B40;
struct Other_002D2B40;

struct Obj_002D2B40 {
    NodeA_002D2B40 m0;
    NodeB_002D2B40 m18;
    char pad30[0x160 - 0x30];
    Owned_002D2B40* m160;
    Owned_002D2B40* m164;
    Owned_002D2B40* m168;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002D2B40();
};

Obj_002D2B40::~Obj_002D2B40()
{
    delete m160;
    delete m164;
    delete m168;
}
