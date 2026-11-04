/* sym: _vt$12Obj_0024EEE0 = 0x00374960 */
/* sym: _vt$13Node_0024EEE0 = 0x00374990 */
/* sym: _$_12Mem_0024EEE0 = 0x001E6AE8 */
extern "C" void func_0024EC78(void* self);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Node_0024EEE0 {
    int m0;
    int m4;
    int m8;
    Node_0024EEE0* m_next;
    Node_0024EEE0* m_prev;
    virtual void Update();
    virtual ~Node_0024EEE0()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Mem_0024EEE0 {
    int m0;
    int m4;
    ~Mem_0024EEE0();
};

struct Obj_0024EEE0 {
    int m0;
    Mem_0024EEE0 m_mem;
    Node_0024EEE0 m_node;
    virtual void Update();
    virtual ~Obj_0024EEE0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0024EEE0::~Obj_0024EEE0()
{
    func_0024EC78(this);
}
