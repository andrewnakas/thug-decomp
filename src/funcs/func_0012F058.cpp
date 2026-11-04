struct Obj_0012F058;
struct Handle_0012F058;

extern "C" void func_00183C98(Obj_0012F058* o, Handle_0012F058* h);
extern "C" void func_00183CB8(Obj_0012F058* o, Handle_0012F058* h);

struct Handle_0012F058 {
    Obj_0012F058* m_obj;
    Handle_0012F058* m_prev;
    Handle_0012F058* m_next;
    Handle_0012F058(const Handle_0012F058& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012F058()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012F058& operator=(const Handle_0012F058& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012F058* p = h.m_obj;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    Handle_0012F058& operator=(Obj_0012F058* o)
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
    Obj_0012F058* operator->() const { return m_obj; }
    operator Obj_0012F058*() const { return m_obj; }
};

struct Obj_0012F058 {
    char pad[0x48];
    Handle_0012F058 m48;
};

struct Elem_0012F058 {
    Handle_0012F058 m_handle;
    int mC;
    Elem_0012F058* m_next;
    int m14;
    int m18;
};

struct C_0012F058 {
    char pad[0x64];
    Elem_0012F058 m64[48];
    Elem_0012F058* m5A4[2];
    int m5AC[2];
    void Unmark(Handle_0012F058* target);
};

extern "C" void func_0012F180(C_0012F058* self, Elem_0012F058* e);

void C_0012F058::Unmark(Handle_0012F058* target)
{
    for (int i = 0; i < 2; i++) {
        for (Elem_0012F058* e = m5A4[i]; e; e = e->m_next) {
            if (e->m18) {
                func_0012F180(this, e);
                Handle_0012F058 p = e->m_handle;
                while (p) {
                    if (p == *target) {
                        e->m18 = 0;
                        break;
                    }
                    p = p->m48;
                }
            }
        }
    }
}
