extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_0012FBC8 {
    char pad0[0x1C];
    unsigned int m_type;
};

struct RefBase_0012FBC8 {
    void* m_p;
    RefBase_0012FBC8* m_prev;
    RefBase_0012FBC8* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    RefBase_0012FBC8(const RefBase_0012FBC8& o);
    ~RefBase_0012FBC8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012FBC8 {
    Elem_0012FBC8* m_p;
    Ref_0012FBC8* m_prev;
    Ref_0012FBC8* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012FBC8*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012FBC8(const RefBase_0012FBC8& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012FBC8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_0012FBC8;
extern Mgr_0012FBC8* D_00389A30;
extern "C" RefBase_0012FBC8 func_0012DC18(Mgr_0012FBC8* m, void* params, unsigned int name, int a);
extern "C" int func_00127F00(Elem_0012FBC8* e);
extern "C" int func_00126538(Elem_0012FBC8* e);

extern "C" int func_0012FBC8(void* params)
{
    Ref_0012FBC8 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 1);
    switch (r.m_p->m_type) {
    case 0x5200DFB6:
        return func_00126538(r.m_p);
    case 0x40D92263:
        return func_00127F00(r.m_p);
    }
    return 0;
}
