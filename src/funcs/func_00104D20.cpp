extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node; its own deleting destructor is the one at 0x00104988
// (vtable D_0035A960). The destructor is declared pure (with a body) so it is
// not the key method and the vtables stay in the asm.
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

inline LinkNode::~LinkNode()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}

// Derived node (vtable D_0035A9A0) with an empty destructor; again pure so
// that Run is the key method.
class LinkNode104D20 : public LinkNode {
public:
    virtual ~LinkNode104D20() = 0;
    virtual void Run();
};

LinkNode104D20::~LinkNode104D20()
{
}
