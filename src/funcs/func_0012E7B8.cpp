struct Obj_0012E7B8;
struct Handle_0012E7B8;

extern "C" void func_00183C98(Obj_0012E7B8* o, Handle_0012E7B8* h);
extern "C" void func_00183CB8(Obj_0012E7B8* o, Handle_0012E7B8* h);

struct Obj_0012E7B8 {
    char pad[0x48];
    Obj_0012E7B8* m48;
};

struct Handle_0012E7B8 {
    Obj_0012E7B8* m_obj;
    Handle_0012E7B8* m_prev;
    Handle_0012E7B8* m_next;
    Handle_0012E7B8(Obj_0012E7B8* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012E7B8(const Handle_0012E7B8& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012E7B8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012E7B8& operator=(Obj_0012E7B8* const& o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012E7B8* p = o;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    Handle_0012E7B8& operator=(const Handle_0012E7B8& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012E7B8* p = h.m_obj;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    bool operator==(Obj_0012E7B8* o) const { return m_obj == o; }
    Obj_0012E7B8* operator->() const { return m_obj; }
    operator Obj_0012E7B8*() const { return m_obj; }
};

static inline Handle_0012E7B8 Make_0012E7B8(const Handle_0012E7B8& t)
{
    return t;
}

struct Node_0012E7B8 {
    int m0;
    unsigned int m_data;
    int m8;
    Node_0012E7B8* m_next;
    Node_0012E7B8* m_prev;
};

static inline Node_0012E7B8* Valid_0012E7B8(Node_0012E7B8* n)
{
    return n->m_data != 0xFFFFFFFF ? n : 0;
}

class C_0012E7B8 {
public:
    int m0;
    Node_0012E7B8 m_list;
    char pad18[0x34];
    Handle_0012E7B8 m4C;
    void Detach(Obj_0012E7B8* o);
};

extern "C" void func_00187588(C_0012E7B8* self, Obj_0012E7B8* o);

void C_0012E7B8::Detach(Obj_0012E7B8* o)
{
    Handle_0012E7B8 h = Make_0012E7B8(o);
    if (h && m4C == h) {
        m4C = 0;
        Node_0012E7B8* n = Valid_0012E7B8(m_list.m_next);
        while (n) {
            Handle_0012E7B8 c = Make_0012E7B8((Obj_0012E7B8*)n->m_data);
            if (!c->m48 && c != h) {
                m4C = c;
                break;
            }
            n = Valid_0012E7B8(n->m_next);
        }
    }
    func_00187588(this, o);
}
