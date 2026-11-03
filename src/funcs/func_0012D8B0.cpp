struct Obj_0012D8B0;
struct Handle_0012D8B0;

extern "C" void func_00183C98(Obj_0012D8B0* o, Handle_0012D8B0* h);
extern "C" void func_00183CB8(Obj_0012D8B0* o, Handle_0012D8B0* h);

struct ObjBase_0012D8B0 {
    int m0;
    int m4;
    virtual ~ObjBase_0012D8B0();
};

struct Obj_0012D8B0 : ObjBase_0012D8B0 {
    char padC[0x3C];
    void* m48;
};

struct Handle_0012D8B0 {
    Obj_0012D8B0* m_obj;
    Handle_0012D8B0* m_prev;
    Handle_0012D8B0* m_next;
    Handle_0012D8B0(const Handle_0012D8B0& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012D8B0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Obj_0012D8B0* operator->() const { return m_obj; }
    operator Obj_0012D8B0*() const { return m_obj; }
};

class C_0012D8B0 {
public:
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2(Obj_0012D8B0* o);
    void Remove(int id, int a, void* b, void* c);
};

extern "C" Handle_0012D8B0 func_0012DB48(C_0012D8B0* self, int id, int flag);
extern "C" void func_0012EE60(C_0012D8B0* self, Handle_0012D8B0* h, int a, int b);
extern "C" void func_0012E9A8(C_0012D8B0* self, void* a, Handle_0012D8B0* h, void* b);
extern "C" void func_00124118(void* p, int a);
extern "C" void func_001EEC50(void* p, Obj_0012D8B0* o);

static inline Handle_0012D8B0 Make_0012D8B0(const Handle_0012D8B0& t)
{
    return t;
}

void C_0012D8B0::Remove(int id, int a, void* b, void* c)
{
    Handle_0012D8B0 h = Make_0012D8B0(func_0012DB48(this, id, 1));
    if (a) {
        func_0012EE60(this, &h, 0, 0);
        if (h->m48)
            func_00124118(h->m48, 0);
        func_0012E9A8(this, b, &h, c);
    } else {
        func_0012EE60(this, &h, 0, 0);
        if (c && h)
            func_001EEC50(c, h);
        V2(h);
        if (h)
            delete h.m_obj;
    }
}
