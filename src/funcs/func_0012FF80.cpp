struct Obj_0012FF80;
struct Handle_0012FF80;

extern "C" void func_00183C98(Obj_0012FF80* o, Handle_0012FF80* h);
extern "C" void func_00183CB8(Obj_0012FF80* o, Handle_0012FF80* h);

struct Obj_0012FF80 {
    char pad[0x1C];
    unsigned int m1C;
    char pad20[0x180];
    int m1A0;
};

struct Handle_0012FF80 {
    Obj_0012FF80* m_obj;
    Handle_0012FF80* m_prev;
    Handle_0012FF80* m_next;
    Handle_0012FF80(const Handle_0012FF80& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012FF80()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012FF80& operator=(Obj_0012FF80* o)
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
    Obj_0012FF80* operator->() const { return m_obj; }
    operator Obj_0012FF80*() const { return m_obj; }
};

static inline Handle_0012FF80 Make_0012FF80(const Handle_0012FF80& t)
{
    return t;
}

extern void* D_00389A30;
extern char D_00389A78[];
extern char D_00389A80[];
extern "C" Handle_0012FF80 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_00124288(Obj_0012FF80* o);

bool Cmd_0012FF80(void* params, void* script)
{
    Handle_0012FF80 h = Make_0012FF80(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    Obj_0012FF80* o = h;
    int sel = o->m1A0;
    if (sel == -1)
        return false;
    bool r = false;
    int v;
    if (func_001E7DE8(params, 0, &v, 0))
        r = sel == v;
    else if (func_001E87B8(params, D_00389A78))
        r = sel == 0;
    else if (func_001E87B8(params, D_00389A80))
        r = sel == func_00124288(o) - 1;
    return r;
}
