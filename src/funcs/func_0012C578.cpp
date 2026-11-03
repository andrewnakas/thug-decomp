struct Obj_0012C578;
struct Handle_0012C578;

extern "C" void func_00183C98(Obj_0012C578* o, Handle_0012C578* h);
extern "C" void func_00183CB8(Obj_0012C578* o, Handle_0012C578* h);

struct Obj_0012C578 {
    char pad[0x18];
    int m18;
    char pad1C[0x44];
    Obj_0012C578* m60;
};

struct Handle_0012C578 {
    Obj_0012C578* m_obj;
    Handle_0012C578* m_prev;
    Handle_0012C578* m_next;
    Handle_0012C578(Obj_0012C578* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012C578(const Handle_0012C578& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    void Clear()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    ~Handle_0012C578()
    {
        Clear();
    }
    Handle_0012C578& operator=(Obj_0012C578* o)
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
    Obj_0012C578* operator->() const { return m_obj; }
    operator Obj_0012C578*() const { return m_obj; }
};

struct Event_0012C578 {
    unsigned int m0;
    int m4;
    int m8;
};

struct Target_0012C578 {
    char pad[0x18];
    int m18;
    char pad1C[0x38];
    Obj_0012C578* m54;
};

static inline Handle_0012C578 Make_0012C578(const Handle_0012C578& t)
{
    return t;
}

extern "C" void func_00187CE8(Event_0012C578* e, int a, int b);

class B_0012C578 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
};

class C_0012C578 : public B_0012C578 {
public:
    char padC[0xC];
    int m18;
    char pad1C[0x1A0];
    Target_0012C578* m1BC;
    char pad1C0[0xC];
    int m1CC;
    int m1D0;
    void Handle(Event_0012C578* e);
};

extern "C" void func_0012C6F8(C_0012C578* o);
extern "C" void func_0012C898(C_0012C578* o, Handle_0012C578* h);

void C_0012C578::Handle(Event_0012C578* e)
{
    if (e->m0 == 0x3056434F && m1BC) {
        if (e->m8 == m1BC->m18) {
            m1D0 = 1;
            V10();
        }
        func_00187CE8(e, m18, 0);
    }
    if (e->m0 == 0x9D3FB516) {
        if (!m1BC)
            func_0012C6F8(this);
        for (Handle_0012C578 h(Make_0012C578(m1BC->m54)); h; h = h->m60) {
            if (h->m18 == e->m8) {
                func_0012C898(this, &h);
                func_00187CE8(e, m18, 0);
                break;
            }
        }
    }
}
