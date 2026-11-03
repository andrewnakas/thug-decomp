struct Obj_0012E9A8;
struct Handle_0012E9A8;

extern "C" void func_00183C98(Obj_0012E9A8* o, Handle_0012E9A8* h);
extern "C" void func_00183CB8(Obj_0012E9A8* o, Handle_0012E9A8* h);

struct ObjBase_0012E9A8 {
    int m0;
    int m4;
    virtual ~ObjBase_0012E9A8();
};

struct Obj_0012E9A8 : ObjBase_0012E9A8 {
    char padC[0x48];
    Obj_0012E9A8* m54;
    char pad58[8];
    Obj_0012E9A8* m60;
};

struct Handle_0012E9A8 {
    Obj_0012E9A8* m_obj;
    Handle_0012E9A8* m_prev;
    Handle_0012E9A8* m_next;
    Handle_0012E9A8(Obj_0012E9A8* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012E9A8(const Handle_0012E9A8& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012E9A8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012E9A8& operator=(const Handle_0012E9A8& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        Obj_0012E9A8* p = h.m_obj;
        m_obj = p;
        if (p)
            func_00183C98(p, this);
        return *this;
    }
    Obj_0012E9A8* operator->() const { return m_obj; }
    operator Obj_0012E9A8*() const { return m_obj; }
};

static inline Handle_0012E9A8 Make_0012E9A8(const Handle_0012E9A8& t)
{
    return t;
}

class C_0012E9A8 {
public:
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2(Obj_0012E9A8* o);
    void Release(int keep, Handle_0012E9A8* h, void* b);
};

extern "C" void func_00124118(Obj_0012E9A8* o, int a);
extern "C" void func_001EEC50(void* p, Obj_0012E9A8* o);
extern "C" void func_0012DA10(C_0012E9A8* self, Handle_0012E9A8* a, Handle_0012E9A8* b, int c);

void C_0012E9A8::Release(int keep, Handle_0012E9A8* h, void* b)
{
    func_00124118(*h, 0);
    Handle_0012E9A8 c = Make_0012E9A8((*h)->m54);
    while (c) {
        Handle_0012E9A8 next = Make_0012E9A8(c->m60);
        Release(0, &c, b);
        c = next;
    }
    if (!keep) {
        if (b && *h)
            func_001EEC50(b, *h);
        {
            Handle_0012E9A8 z(0);
            func_0012DA10(this, &z, h, 1);
        }
        V2(*h);
        if (*h)
            delete h->m_obj;
    }
}
