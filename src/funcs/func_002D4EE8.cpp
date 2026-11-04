extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0031BCB0(void* p);

struct Owned_002D4EE8 {
    int m0[6];
    virtual void A();
    virtual void B();
    virtual ~Owned_002D4EE8();
};

struct Node_002D4EE8 {
    int m0;
    void* m_data;
    int m8;
    Node_002D4EE8* m_next;
    Node_002D4EE8* m_prev;
    virtual void Key();
    virtual ~Node_002D4EE8()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Iter_002D4EE8 {
    int m0;
    int m4;
    virtual void Key();
    virtual ~Iter_002D4EE8() {}
};

struct Obj_002D4EE8 {
    Owned_002D4EE8* m0;
    char pad4[0x320 - 4];
    void* m320;
    char pad324[0x350 - 0x324];
    Node_002D4EE8 m350;
    Iter_002D4EE8 m368;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002D4EE8();
};

Obj_002D4EE8::~Obj_002D4EE8()
{
    func_0031BCB0(m320);
    delete m0;
}
