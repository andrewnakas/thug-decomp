struct Obj_00127DE0;

extern "C" void func_00183C98(Obj_00127DE0* o, void* h);
extern "C" void func_00183CB8(Obj_00127DE0* o, void* h);
extern "C" int func_00126470(Obj_00127DE0* o);

struct Handle_00127DE0 {
    Obj_00127DE0* m_obj;
    Handle_00127DE0* m_prev;
    Handle_00127DE0* m_next;
    Handle_00127DE0(Obj_00127DE0* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_00127DE0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00127DE0& operator=(const Handle_00127DE0& o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
        return *this;
    }
};

struct Obj_00127DE0 {
    char pad0[0x60];
    Obj_00127DE0* m60;
};

struct C_00127DE0 {
    char pad0[0x54];
    Obj_00127DE0* m54;
    int Count();
};

int C_00127DE0::Count()
{
    int n = 0;
    Handle_00127DE0 h(Handle_00127DE0(m54).m_obj);
    while (h.m_obj) {
        Handle_00127DE0 next(Handle_00127DE0(h.m_obj->m60).m_obj);
        n += func_00126470(h.m_obj);
        if (next.m_obj)
            n++;
        h = next;
    }
    return n;
}
