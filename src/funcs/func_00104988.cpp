extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node (vtable D_0035A960; slot 1 is this deleting
// destructor). Pure with a body so it is not the key method.
class LinkNode {
public:
    int m0;
    int m4;
    int m8;
    LinkNode* m_prev;
    LinkNode* m_next;
    virtual ~LinkNode() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

LinkNode::~LinkNode()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}
