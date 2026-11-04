struct Obj_0012DB48;
struct Handle_0012DB48;

extern "C" void func_00183C98(Obj_0012DB48* o, Handle_0012DB48* h);
extern "C" void func_00183CB8(Obj_0012DB48* o, Handle_0012DB48* h);

struct Handle_0012DB48 {
    Obj_0012DB48* m_obj;
    Handle_0012DB48* m_prev;
    Handle_0012DB48* m_next;
    Handle_0012DB48(Obj_0012DB48* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012DB48(const Handle_0012DB48& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012DB48()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    operator Obj_0012DB48*() const { return m_obj; }
};

extern "C" Obj_0012DB48* func_001895B0(void* mgr, int id);
extern void* D_0038C7B0;

static inline Handle_0012DB48 Make_0012DB48(Obj_0012DB48* o)
{
    Handle_0012DB48 t(o);
    return t;
}

struct C_0012DB48 {
    Handle_0012DB48 Find(int id, int flag);
};

Handle_0012DB48 C_0012DB48::Find(int id, int flag)
{
    Obj_0012DB48* o = func_001895B0(D_0038C7B0, id);
    if (o) {
        Handle_0012DB48 h = Make_0012DB48(o);
        return h;
    }
    Handle_0012DB48 h(0);
    return h;
}
