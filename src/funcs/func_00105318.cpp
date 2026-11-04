extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Obj104E38;

// Self-linked node owned by an Obj104E38 (vtable D_0035AA00). The destructor
// is declared pure (with a body) so it is not the key method.
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

OwnerLink::~OwnerLink()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
    m_prev = this;
    m_next = this;
}
