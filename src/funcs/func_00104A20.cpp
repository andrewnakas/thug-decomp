extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Self-linked list node (vtable D_0035A960); see func_00104D20. The
// destructors are declared pure (with bodies) so they are not key methods.
class LinkNode {
public:
    int m0;
    int m4;
    int m8;
    LinkNode* m_prev;
    LinkNode* m_next;
    virtual ~LinkNode() = 0;
    virtual void Run();
};

inline LinkNode::~LinkNode()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}

// Derived node (vtable D_0035A9A0); its out-of-line deleting destructor is
// func_00104D20. Declared inline here so that Run is the key method.
class LinkNode104D20 : public LinkNode {
public:
    virtual ~LinkNode104D20() {}
    virtual void Run();
};

// Same layout as Obj1049E0 (its constructor is func_001049E0).
struct Obj1049E0 {
    int m0;
    int m4;
    LinkNode104D20 m_node;
    int m20;
    int m24;
    ~Obj1049E0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj1049E0::~Obj1049E0()
{
}
