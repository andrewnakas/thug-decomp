extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

class Elem_00125800;

struct Ref_00125800 {
    Elem_00125800* m_p;
    Ref_00125800* m_prev;
    Ref_00125800* m_next;
    Ref_00125800()
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
    }
    ~Ref_00125800()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
    void Set(Elem_00125800* o)
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
};

class Elem_00125800 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x54 - 0x10];
    Ref_00125800 m_child;
    Ref_00125800 m_sibling;
    char pad6C[0x194 - 0x6C];
    float m_depth;
    void SetDepth(float d);
};

void Elem_00125800::SetDepth(float d)
{
    if (!(m_flags & 0x8000)) {
        m_depth = d;
        m_flags |= 0x1000;
    }
    Ref_00125800 r;
    r.Set(m_child.m_p);
    while (r.m_p) {
        r.m_p->SetDepth(d + 1.0f);
        r.Set(r.m_p->m_sibling.m_p);
    }
}
