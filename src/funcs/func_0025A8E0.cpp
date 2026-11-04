/* sym: _vt$13Node_0025A8E0 = 0x00375768 */
/* sym: _vt$12Obj_0025A8E0 = 0x00375700 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" int func_0013B268(void* p);

class Item_0025A8E0 {
public:
    char pad0[8];
    virtual ~Item_0025A8E0() = 0;
    virtual void V1();
};

struct Node_0025A8E0 {
    int m0;
    int m4;
    int m8;
    Node_0025A8E0* m_next;
    Node_0025A8E0* m_prev;
    virtual void Update();
    virtual ~Node_0025A8E0()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_0025A8E0 : Node_0025A8E0 {
    Item_0025A8E0* m18;
    char pad1C[0x38 - 0x1C];
    void* m38;
    virtual void Update();
    virtual ~Obj_0025A8E0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0025A8E0::~Obj_0025A8E0()
{
    if (m38)
        func_001E6AE8(m38, 3);
    if (m18 && !func_0013B268(m18))
        delete m18;
}
