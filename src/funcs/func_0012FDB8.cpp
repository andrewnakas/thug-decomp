struct Obj_0012FDB8;
struct Handle_0012FDB8;

extern "C" void func_00183C98(Obj_0012FDB8* o, Handle_0012FDB8* h);
extern "C" void func_00183CB8(Obj_0012FDB8* o, Handle_0012FDB8* h);

struct Obj_0012FDB8 {
    char pad[0x1C];
    unsigned int m1C;
    char pad20[0x180];
    char* m1A0;
};

struct Handle_0012FDB8 {
    Obj_0012FDB8* m_obj;
    Handle_0012FDB8* m_prev;
    Handle_0012FDB8* m_next;
    Handle_0012FDB8(const Handle_0012FDB8& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012FDB8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012FDB8& operator=(Obj_0012FDB8* o)
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
    Obj_0012FDB8* operator->() const { return m_obj; }
    operator Obj_0012FDB8*() const { return m_obj; }
};

static inline Handle_0012FDB8 Make_0012FDB8(const Handle_0012FDB8& t)
{
    return t;
}

extern void* D_00389A30;
extern char D_00389A70[];
extern "C" Handle_0012FDB8 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" int func_00126470(Obj_0012FDB8* o);
extern "C" int func_00127DE0(Obj_0012FDB8* o);
extern "C" void func_001E7268(void* s, char* name, int v);

struct Script_0012FDB8 {
    char pad[0x18];
    void* m18;
};

bool Cmd_0012FDB8(void* params, Script_0012FDB8* script)
{
    Handle_0012FDB8 h = Make_0012FDB8(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    int v;
    switch (h->m1C) {
    case 0x5200DFB6:
        v = func_00126470(h);
        break;
    case 0x40D92263:
        v = func_00127DE0(h);
        break;
    default:
        return false;
    }
    func_001E7268(script->m18, D_00389A70, v);
    return true;
}
