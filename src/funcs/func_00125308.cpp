struct Obj_00125308;
struct Handle_00125308;

extern "C" void func_00183C98(Obj_00125308* o, Handle_00125308* h);
extern "C" void func_00183CB8(Obj_00125308* o, Handle_00125308* h);

struct Obj_00125308 {
    char pad[0x18];
    int m18;
    char pad1C[0x38];
    Obj_00125308* m54;
    char pad58[8];
    Obj_00125308* m60;
};

struct Handle_00125308 {
    Obj_00125308* m_obj;
    Handle_00125308* m_prev;
    Handle_00125308* m_next;
    Handle_00125308(Obj_00125308* const& o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_00125308(const Handle_00125308& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_00125308()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00125308& operator=(Obj_00125308* o)
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
    Obj_00125308* operator->() const { return m_obj; }
    operator Obj_00125308*() const { return m_obj; }
};

Handle_00125308 func_00125308(Obj_00125308* owner, int id, int* index)
{
    int i = 0;
    Handle_00125308 h(owner->m54);
    while (h) {
        if (!id) {
            if (*index == i)
                break;
        } else if (h->m18 == id) {
            if (index)
                *index = i;
            break;
        }
        h = h->m60;
        i++;
    }
    return h;
}
