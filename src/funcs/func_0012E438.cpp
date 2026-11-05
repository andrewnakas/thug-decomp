/* sym: FindChild__10C_0012E438P15Handle_0012E438i = 0x0012EB90 */
/* sym: Find__10C_0012E438ii = 0x0012DB48 */
struct Obj_0012E438;
struct Handle_0012E438;

extern "C" void func_00183C98(Obj_0012E438* o, Handle_0012E438* h);
extern "C" void func_00183CB8(Obj_0012E438* o, Handle_0012E438* h);

struct Obj_0012E438 {
    char pad[0x18];
    int m18;
};

struct Handle_0012E438 {
    Obj_0012E438* m_obj;
    Handle_0012E438* m_prev;
    Handle_0012E438* m_next;
    Handle_0012E438(Obj_0012E438* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012E438(const Handle_0012E438& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012E438()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012E438& operator=(const Handle_0012E438& h)
    {
        Obj_0012E438* p = h.m_obj;
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    Handle_0012E438& operator=(Obj_0012E438* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
    Obj_0012E438* operator->() const { return m_obj; }
    operator Obj_0012E438*() const { return m_obj; }
};

static inline Handle_0012E438 Make_0012E438(const Handle_0012E438& t)
{
    return t;
}

extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" Obj_0012E438* func_00124238(Obj_0012E438* o, int i);
extern "C" Obj_0012E438* func_00189600(void* mgr, int id);
extern void* D_0038C7B0;

struct C_0012E438 {
    char pad[0x58];
    Handle_0012E438 m58;
    Handle_0012E438 FindChild(Handle_0012E438* parent, int id);
    Handle_0012E438 Find(int id, int flag);
    int Resolve(void* params, unsigned int name);
};

int C_0012E438::Resolve(void* params, unsigned int name)
{
    void* sub = 0;
    int id = 0;
    int index = -1;
    if (func_001E8180(params, name, &sub, 0)) {
        int cs = 0;
        func_001E8398(sub, 0, &cs, 0);
        int i = -1;
        func_001E7DE8(sub, 0, &i, 0);
        if (cs) {
            if (!m58)
                m58 = Find(cs, 0);
            else
                m58 = FindChild(&m58, cs);
            if (!m58) return 0;
        } else if (i != -1) {
            m58 = func_00124238(m58, i);
            if (!m58) return 0;
        }
        int r = Resolve(sub, 0xDD4CABD6);
        m58 = 0;
        return r;
    }
    if (func_001E8398(params, name, &id, 0)) {
        if (m58) {
            m58 = FindChild(&m58, id);
            id = m58->m18;
        } else {
            Obj_0012E438* o = func_00189600(D_0038C7B0, id);
            if (o) id = o->m18;
        }
        m58 = 0;
        return id;
    }
    if (func_001E7DE8(params, name, &index, 0)) {
        Handle_0012E438 h = Make_0012E438(func_00124238(m58, index));
        m58 = 0;
        if (h) return h->m18;
        return 0;
    }
    m58 = 0;
    return 0;
}
