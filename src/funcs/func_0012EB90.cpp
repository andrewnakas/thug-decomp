struct Obj_0012EB90;
struct Handle_0012EB90;

extern "C" void func_00183C98(Obj_0012EB90* o, Handle_0012EB90* h);
extern "C" void func_00183CB8(Obj_0012EB90* o, Handle_0012EB90* h);

struct Obj_0012EB90 {
    char pad[0x54];
    Obj_0012EB90* m54;
    char pad58[8];
    Obj_0012EB90* m60;
};

struct Handle_0012EB90 {
    Obj_0012EB90* m_obj;
    Handle_0012EB90* m_prev;
    Handle_0012EB90* m_next;
    Handle_0012EB90(Obj_0012EB90* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012EB90(const Handle_0012EB90& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012EB90()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012EB90& operator=(Obj_0012EB90* o)
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
    Obj_0012EB90* operator->() const { return m_obj; }
    operator Obj_0012EB90*() const { return m_obj; }
};

static inline Handle_0012EB90 Make_0012EB90(const Handle_0012EB90& t)
{
    return t;
}

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_001840A0(Obj_0012EB90* o, unsigned int name, int* out);
extern char D_0035D278[];

struct C_0012EB90 {
    Handle_0012EB90 FindChild(Handle_0012EB90* parent, int id);
};

Handle_0012EB90 C_0012EB90::FindChild(Handle_0012EB90* parent, int id)
{
    unsigned int name = func_001F0D78(D_0035D278);
    Handle_0012EB90 c = Make_0012EB90((*parent)->m54);
    while (c) {
        int v;
        if (func_001840A0(c, name, &v) && v == id)
            return c;
        c = c->m60;
    }
    Handle_0012EB90 r(0);
    return r;
}
