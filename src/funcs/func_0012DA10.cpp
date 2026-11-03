struct Obj_0012DA10;
struct Handle_0012DA10;

extern "C" void func_00183C98(Obj_0012DA10* o, Handle_0012DA10* h);
extern "C" void func_00183CB8(Obj_0012DA10* o, Handle_0012DA10* h);

struct Obj_0012DA10 {
    char pad[0x48];
    Obj_0012DA10* m48;
};

struct Handle_0012DA10 {
    Obj_0012DA10* m_obj;
    Handle_0012DA10* m_prev;
    Handle_0012DA10* m_next;
    Handle_0012DA10(Obj_0012DA10* const& o)
    {
        m_prev = 0;
        m_next = 0;
        Obj_0012DA10* p = o;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
    }
    ~Handle_0012DA10()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012DA10& operator=(Obj_0012DA10* const& o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012DA10* p = o;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    bool operator==(Obj_0012DA10* o) const { return m_obj == o; }
    Obj_0012DA10* operator->() const { return m_obj; }
    operator Obj_0012DA10*() const { return m_obj; }
};

class C_0012DA10 {
public:
    char pad[0x4C];
    Handle_0012DA10 m4C;
    void Focus(Handle_0012DA10* a, Handle_0012DA10* b, void* c);
};

extern "C" void func_0012EE60(C_0012DA10* self, Handle_0012DA10* h, int a, int b);
extern "C" void func_00125418(Obj_0012DA10* o, Handle_0012DA10* a, void* c);

void C_0012DA10::Focus(Handle_0012DA10* a, Handle_0012DA10* b, void* c)
{
    Handle_0012DA10 h((*b)->m48);
    Obj_0012DA10* o = *a;
    if (o) {
        if (m4C == *b || !m4C) {
            m4C = o;
            while (m4C->m48)
                m4C = m4C->m48;
        }
    }
    func_0012EE60(this, b, 0, 0);
    func_00125418(*b, a, c);
}
