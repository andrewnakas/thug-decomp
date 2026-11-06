/* sym: _$_13Base_0019FA28 = 0x00184DD8 */
/* sym: _vt$12Der_0019FA28 = 0x00362358 */
/* sym: _vt$13Node_0019FA28 = 0x0035C750 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Node_0019FA28 {
public:
    int m0;
    unsigned int m4;
    int m8;
    Node_0019FA28* m_next;
    Node_0019FA28* m_prev;
    virtual void F();
    virtual ~Node_0019FA28()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

class Base_0019FA28 {
public:
    char pad0[0x18];
    virtual void F();
    virtual ~Base_0019FA28();
};

class Der_0019FA28 : public Base_0019FA28 {
public:
    Node_0019FA28 m1C;
    char pad34[0x64 - 0x34];
    void* m64;
    virtual void F();
    virtual ~Der_0019FA28();
};

extern "C" void func_001A2728(Der_0019FA28* self);

Der_0019FA28::~Der_0019FA28()
{
    func_001A2728(this);
    if (m64)
        func_0010A8D8(D_00388A70, m64);
}
