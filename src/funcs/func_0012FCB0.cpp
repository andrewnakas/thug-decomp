struct Obj_0012FCB0;
struct Handle_0012FCB0;

extern "C" void func_00183C98(Obj_0012FCB0* o, Handle_0012FCB0* h);
extern "C" void func_00183CB8(Obj_0012FCB0* o, Handle_0012FCB0* h);

struct Obj_0012FCB0 {
    char pad[0x1C];
    unsigned int m1C;
    char pad20[0x180];
    char* m1A0;
};

struct Handle_0012FCB0 {
    Obj_0012FCB0* m_obj;
    Handle_0012FCB0* m_prev;
    Handle_0012FCB0* m_next;
    Handle_0012FCB0(const Handle_0012FCB0& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012FCB0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012FCB0& operator=(Obj_0012FCB0* o)
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
    Obj_0012FCB0* operator->() const { return m_obj; }
    operator Obj_0012FCB0*() const { return m_obj; }
};

static inline Handle_0012FCB0 Make_0012FCB0(const Handle_0012FCB0& t)
{
    return t;
}

extern void* D_00389A30;
extern char D_00389A68[];
extern "C" Handle_0012FCB0 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" bool func_00127BE8(Obj_0012FCB0* o, char* buf, int size);
extern "C" void func_001E7138(void* s, char* name, char* v);

struct Script_0012FCB0 {
    char pad[0x18];
    void* m18;
};

bool Cmd_0012FCB0(void* params, Script_0012FCB0* script)
{
    Handle_0012FCB0 h = Make_0012FCB0(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    switch (h->m1C) {
    case 0x5200DFB6:
        if (h->m1A0)
            func_001E7138(script->m18, D_00389A68, h->m1A0);
        break;
    case 0x40D92263: {
        char buf[0x200];
        if (func_00127BE8(h, buf, 0x200))
            func_001E7138(script->m18, D_00389A68, buf);
        break;
    }
    }
    return false;
}
