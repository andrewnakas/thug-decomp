/* sym: _vt$13Node_00244450 = 0x00373BE8 */
/* sym: _vt$12Obj_00244450 = 0x00373B00 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Node_00244450 {
    int m0;
    int m4;
    int m8;
    Node_00244450* m_next;
    Node_00244450* m_prev;
    virtual void Update();
    virtual ~Node_00244450()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Obj_00244450;
extern "C" void func_00248800(Obj_00244450* self, unsigned int name);
extern "C" void func_00248920(void* p, int a);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" void func_00244330(Obj_00244450* self, void* p);

struct Obj_00244450 : Node_00244450 {
    void* m18;
    int m1C;
    void* m20;
    void* m24;
    int m28;
    void* m2C;
    void* m30;
    virtual void Update();
    virtual ~Obj_00244450();
};

Obj_00244450::~Obj_00244450()
{
    func_00248800(this, 0x83B57984);
    if (m18) func_00248920(m18, 3);
    if (m20) func_001E6AE8(m20, 3);
    if (m24) func_001E6AE8(m24, 3);
    func_00244330(this, m2C);
    func_00244330(this, m30);
}
