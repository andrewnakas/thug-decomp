extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_001240D8(void* elem, int on);

struct RefBase_0012DD18 {
    void* m_p;
    RefBase_0012DD18* m_prev;
    RefBase_0012DD18* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    RefBase_0012DD18(void* o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o);
    }
    RefBase_0012DD18(const RefBase_0012DD18& o);
    ~RefBase_0012DD18()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012DD18 {
    void* m_p;
    Ref_0012DD18* m_prev;
    Ref_0012DD18* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012DD18(const RefBase_0012DD18& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012DD18()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Node_0012DD18 {
    int m0;
    void* m_obj;
    int m8;
    Node_0012DD18* m_next;
    Node_0012DD18* Valid()
    {
        if (m_obj == (void*)-1) {
            return 0;
        }
        return this;
    }
    Node_0012DD18* Next() { return m_next->Valid(); }
    RefBase_0012DD18 GetRef() { return RefBase_0012DD18(m_obj); }
};

class Elem_0012DD18 {
public:
    int m0[4];
    Node_0012DD18* m_children;
    void SetChildrenActive(int on);
};

void Elem_0012DD18::SetChildrenActive(int on)
{
    Node_0012DD18* n = m_children->Valid();
    while (n) {
        Ref_0012DD18 r = n->GetRef();
        func_001240D8(r.m_p, on);
        n = n->Next();
    }
}
