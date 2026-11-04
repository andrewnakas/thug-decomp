extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Obj104E38;

// Self-linked node (vtable D_0035AA00, deleting destructor func_00105318).
// The destructors are declared pure (with bodies) so they are not key methods.
class OwnerLink {
public:
    int m0;
    Obj104E38* m_owner;
    int m8;
    OwnerLink* m_prev;
    OwnerLink* m_next;
    virtual ~OwnerLink() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

inline OwnerLink::~OwnerLink()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}

// List head derived from it (vtable D_0035A9E8, see func_00104EE8) with an
// empty destructor.
class OwnerListHead : public OwnerLink {
public:
    virtual ~OwnerListHead() = 0;
    virtual void Run();
};

OwnerListHead::~OwnerListHead()
{
}
