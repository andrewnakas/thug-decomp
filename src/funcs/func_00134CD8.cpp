extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node (vtable D_0035D5F8; slot 1 is this deleting
// destructor). Pure with a body so it is not the key method.
class LinkNode134CD8 {
public:
    int m0;
    int m4;
    int m8;
    LinkNode134CD8* m_prev;
    LinkNode134CD8* m_next;
    virtual ~LinkNode134CD8() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

LinkNode134CD8::~LinkNode134CD8()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}
