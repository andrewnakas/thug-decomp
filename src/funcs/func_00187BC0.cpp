/* sym: _vt$13Node_00187BC0 = 0x00361B98 */
/* sym: _vt$13Link_00187BC0 = 0x0035D358 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Link_00187BC0 {
public:
    int m0;
    void* m_owner;
    int m8;
    Link_00187BC0* m_prev;
    Link_00187BC0* m_next;

    virtual void Key();
    virtual ~Link_00187BC0()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

class Node_00187BC0 {
public:
    int m0;
    Link_00187BC0 m_link;
    char pad1C[0x10];

    virtual void Key();
    virtual ~Node_00187BC0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node_00187BC0::~Node_00187BC0()
{
}
