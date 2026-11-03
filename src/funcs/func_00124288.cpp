struct Obj_00124288;
struct Handle_00124288;

extern "C" void func_00183C98(Obj_00124288* o, Handle_00124288* h);
extern "C" void func_00183CB8(Obj_00124288* o, Handle_00124288* h);

struct Obj_00124288 {
    char pad[0x60];
    Obj_00124288* m60;
};

struct Handle_00124288 {
    Obj_00124288* m_obj;
    Handle_00124288* m_prev;
    Handle_00124288* m_next;
    Handle_00124288(Obj_00124288* const& o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_00124288()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00124288& operator=(Obj_00124288* o)
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
    Obj_00124288* operator->() const { return m_obj; }
    operator Obj_00124288*() const { return m_obj; }
};

struct C_00124288 {
    char pad[0x54];
    Obj_00124288* m54;
    int Count();
};

int C_00124288::Count()
{
    Handle_00124288 h(m54);
    int n = 0;
    while (h) {
        h = h->m60;
        n++;
    }
    return n;
}
