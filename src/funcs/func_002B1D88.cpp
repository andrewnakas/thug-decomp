extern void* D_00388A70;
extern char D_00379850[];
extern char D_00378D40[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct A_002B1D88 {
    int m0;
    ~A_002B1D88();
};

struct B_002B1D88 {
    int m0;
    ~B_002B1D88();
};

struct Data_002B1D88 {
    int m0;
    A_002B1D88 m4;
    char pad[0x5C - 0x8];
    B_002B1D88 m5C;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Comp_002B1D88 {
    char pad[0x18];
    virtual void A();
    virtual void B();
    virtual ~Comp_002B1D88();
};

struct Node_002B1D88 {
    int m0;
    void* m_data;
    int m8;
    Node_002B1D88* m_next;
    Node_002B1D88* m_prev;
    void* m_vt;
    ~Node_002B1D88() {
        m_vt = D_00378D40;
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Item_002B1D88 : Node_002B1D88 {
    char pad[0x48 - 0x18];
    Data_002B1D88* m48;
    char pad2[0x164 - 0x4C];
    void* m164;
    Comp_002B1D88* m168;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Item_002B1D88();
};

Item_002B1D88::~Item_002B1D88()
{
    m_vt = D_00379850;
    if (m48)
        delete m48;
    if (m168)
        delete m168;
    if (m164) {
        func_0010A8D8(D_00388A70, m164);
        m164 = 0;
    }
}
