extern "C" void* func_001046B0(unsigned int size);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct LinkNode1049E0 {
    int m0;
    unsigned int m4;
    int m8;
    LinkNode1049E0* m_prev;
    LinkNode1049E0* m_next;
    void* m_vtbl;
};

struct Obj1049E0 {
    int m0;
    int m4;
    LinkNode1049E0 m_node;
    int m20;
    int m24;
    Obj1049E0();
};

class Obj104E38;

// Self-linked node owned by an Obj104E38 (vtable D_0035AA00, deleting
// destructor func_00105318, defined elsewhere).
class OwnerLink {
public:
    int m0;
    Obj104E38* m_owner;
    int m8;
    OwnerLink* m_prev;
    OwnerLink* m_next;
    virtual ~OwnerLink();
    virtual void Run();
    OwnerLink(Obj104E38* owner) : m_owner(owner), m8(0)
    {
        m_prev = this;
        m_next = this;
    }
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

class Obj104E38 : public Obj1049E0 {
public:
    OwnerLink* m_link;
    Obj104E38();
};

Obj104E38::Obj104E38()
{
    m_link = new OwnerLink(this);
}
