extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Base_002B5340 {
    int m0;
    void* m_data;
    int m8;
    Base_002B5340* m_next;
    Base_002B5340* m_prev;
    virtual void Key();
    virtual ~Base_002B5340()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Node_002B5340 {
    int m0;
    void* m_data;
    int m8;
    Node_002B5340* m_next;
    Node_002B5340* m_prev;
    virtual void Key();
    virtual ~Node_002B5340()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_002B5340;
extern "C" void func_002B5278(Obj_002B5340* o);

struct Obj_002B5340 : Base_002B5340 {
    char pad[0xB0 - 0x18];
    void Key();
    Node_002B5340 mB0;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002B5340();
};

Obj_002B5340::~Obj_002B5340()
{
    func_002B5278(this);
}
