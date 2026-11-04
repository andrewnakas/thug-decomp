struct Obj_0012ECE0;
struct Handle_0012ECE0;

extern "C" void func_00183C98(Obj_0012ECE0* o, Handle_0012ECE0* h);
extern "C" void func_00183CB8(Obj_0012ECE0* o, Handle_0012ECE0* h);

struct Obj_0012ECE0 {
    char pad[0x18];
    int m18;
};

struct Handle_0012ECE0 {
    Obj_0012ECE0* m_obj;
    Handle_0012ECE0* m_prev;
    Handle_0012ECE0* m_next;
    Handle_0012ECE0& operator=(Obj_0012ECE0* o)
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
    bool operator==(Obj_0012ECE0* o) const { return m_obj == o; }
    bool IsValid() const { return m_obj != 0; }
    Obj_0012ECE0* operator->() const { return m_obj; }
    operator Obj_0012ECE0*() const { return m_obj; }
};

struct Elem_0012ECE0 {
    Handle_0012ECE0 m_handle;
    int mC;
    Elem_0012ECE0* m_next;
    int m14;
    int m18;
};

struct C_0012ECE0 {
    char pad[0x64];
    Elem_0012ECE0 m64[48];
    Elem_0012ECE0* m5A4[2];
    int m5AC[2];
    void Add(Handle_0012ECE0* h, int list);
};

extern "C" void func_0012F180(C_0012ECE0* self, Elem_0012ECE0* e);

void C_0012ECE0::Add(Handle_0012ECE0* h, int list)
{
    Elem_0012ECE0* last = 0;
    for (int i = 0; i < 2; i++) {
        for (Elem_0012ECE0* e = m5A4[i]; e; e = e->m_next) {
            func_0012F180(this, e);
            if (e->m_handle == *h && list == i) {
                e->m18 = 0;
                return;
            }
            last = e;
        }
    }
    for (int k = 0; k < 48; k++) {
        if (!m64[k].m_handle.IsValid()) {
            m64[k].m_handle = h->m_obj;
            m64[k].mC = (*h)->m18;
            m64[k].m_next = 0;
            m64[k].m18 = 0;
            if (last)
                last->m_next = &m64[k];
            else
                m5A4[list] = &m64[k];
            m5AC[list] = 1;
            return;
        }
    }
}
