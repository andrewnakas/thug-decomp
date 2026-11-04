struct Obj_0012EE60;
struct Handle_0012EE60;

extern "C" void func_00183C98(Obj_0012EE60* o, Handle_0012EE60* h);
extern "C" void func_00183CB8(Obj_0012EE60* o, Handle_0012EE60* h);

struct Handle_0012EE60 {
    Obj_0012EE60* m_obj;
    Handle_0012EE60* m_prev;
    Handle_0012EE60* m_next;
    Handle_0012EE60(const Handle_0012EE60& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012EE60()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012EE60& operator=(const Handle_0012EE60& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012EE60* p = h.m_obj;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    Handle_0012EE60& operator=(Obj_0012EE60* o)
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
    Obj_0012EE60* operator->() const { return m_obj; }
    operator Obj_0012EE60*() const { return m_obj; }
};

struct Obj_0012EE60 {
    char pad[0x48];
    Handle_0012EE60 m48;
};

struct Elem_0012EE60 {
    Handle_0012EE60 m_handle;
    int mC;
    Elem_0012EE60* m_next;
    int m14;
    int m18;
};

struct C_0012EE60 {
    char pad[0x64];
    Elem_0012EE60 m64[48];
    Elem_0012EE60* m5A4[2];
    int m5AC[2];
    void Remove(Handle_0012EE60* target, int parents, int mark);
};

extern "C" void func_0012F180(C_0012EE60* self, Elem_0012EE60* e);

void C_0012EE60::Remove(Handle_0012EE60* target, int parents, int mark)
{
    for (int i = 0; i < 2; i++) {
        Elem_0012EE60* prev = 0;
        Elem_0012EE60* e = m5A4[i];
        while (e) {
            func_0012F180(this, e);
            bool found = false;
            Elem_0012EE60* next = e->m_next;
            Handle_0012EE60 p = e->m_handle;
            if (parents && p)
                p = p->m48;
            while (p) {
                if (p == *target) {
                    found = true;
                    break;
                }
                p = p->m48;
            }
            if (found) {
                if (mark)
                    e->m18 = 1;
                else {
                    if (prev)
                        prev->m_next = next;
                    else
                        m5A4[i] = next;
                    e->m_handle = 0;
                    e = prev;
                    m5AC[i] = 1;
                }
            }
            prev = e;
            e = next;
        }
    }
}
