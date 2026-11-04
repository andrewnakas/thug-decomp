struct Obj_0012F970;
struct Handle_0012F970;

extern "C" void func_00183C98(Obj_0012F970* o, Handle_0012F970* h);
extern "C" void func_00183CB8(Obj_0012F970* o, Handle_0012F970* h);

struct Sub_0012F970 {
    char pad[0x80];
};

struct Obj_0012F970 {
    char pad[0x80];
    Sub_0012F970 m80;
    char pad100[0x88];
    float m188;
    float m18C;
};

struct Handle_0012F970 {
    Obj_0012F970* m_obj;
    Handle_0012F970* m_prev;
    Handle_0012F970* m_next;
    Handle_0012F970(const Handle_0012F970& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012F970()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012F970& operator=(Obj_0012F970* o)
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
    Obj_0012F970* operator->() const { return m_obj; }
    operator Obj_0012F970*() const { return m_obj; }
};

static inline Handle_0012F970 Make_0012F970(const Handle_0012F970& t)
{
    return t;
}

struct Script_0012F970 {
    char pad[0x18];
    void* m18;
};

extern void* D_00389A30;
extern char D_00389A58[];
extern char D_00389A60[];
extern "C" Handle_0012F970 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" float func_0012C128(Sub_0012F970* s);
extern "C" float func_0012C130(Sub_0012F970* s);
extern "C" void func_001E7268(void* s, char* name, int v);

bool Cmd_0012F970(void* params, Script_0012F970* script)
{
    Handle_0012F970 h = Make_0012F970(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    float sw = h->m188;
    int w = (int)(sw * func_0012C128(&h->m80));
    float sh = h->m18C;
    int hh = (int)(sh * func_0012C130(&h->m80));
    func_001E7268(script->m18, D_00389A58, w);
    func_001E7268(script->m18, D_00389A60, hh);
    return true;
}
