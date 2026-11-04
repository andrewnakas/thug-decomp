extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node (vtable D_003763E0; slot 1 is this deleting
// destructor). Pure with a body so it is not the key method.
class LinkNode_0026DF18 {
public:
    int m0;
    int m4;
    int m8;
    LinkNode_0026DF18* m_prev;
    LinkNode_0026DF18* m_next;
    virtual ~LinkNode_0026DF18() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

LinkNode_0026DF18::~LinkNode_0026DF18()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}
