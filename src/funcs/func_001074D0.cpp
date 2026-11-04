extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node (vtable D_0035AE80; slot 1 is this deleting
// destructor). Pure with a body so it is not the key method.
class LinkNode1074D0 {
public:
    int m0;
    int m4;
    int m8;
    LinkNode1074D0* m_prev;
    LinkNode1074D0* m_next;
    virtual ~LinkNode1074D0() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

LinkNode1074D0::~LinkNode1074D0()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}
