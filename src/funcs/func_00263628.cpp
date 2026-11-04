/* sym: _vt$13Node_00263628 = 0x00375D50 */
/* sym: _vt$12Obj_00263628 = 0x00375D68 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Node_00263628 {
    int m0;
    int m4;
    int m8;
    Node_00263628* m_next;
    Node_00263628* m_prev;
    virtual void Update();
    virtual ~Node_00263628()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Item_00263628 {
    int m0;
    Node_00263628 m_node;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Obj_00263628 {
    char pad0[0x5C8];
    Item_00263628* m_items[21];
    char pad61C[0x670 - 0x61C];
    virtual void Update();
    virtual ~Obj_00263628();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00263628::~Obj_00263628()
{
    for (unsigned int i = 0; i < 21; i++) {
        delete m_items[i];
    }
}
