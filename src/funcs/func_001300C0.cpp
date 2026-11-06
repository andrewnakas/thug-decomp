extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_001300C0 {
    char pad0[0x18];
    unsigned int m_id;
};

struct RefBase_001300C0 {
    void* m_p;
    RefBase_001300C0* m_prev;
    RefBase_001300C0* m_next;
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
    RefBase_001300C0(const RefBase_001300C0& o);
    ~RefBase_001300C0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_001300C0 {
    Elem_001300C0* m_p;
    Ref_001300C0* m_prev;
    Ref_001300C0* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_001300C0*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_001300C0(const RefBase_001300C0& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_001300C0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_001300C0;
extern Mgr_001300C0* D_00389A30;
extern "C" RefBase_001300C0 func_0012DC18(Mgr_001300C0* m, void* params, unsigned int name, int a);

extern "C" bool func_001300C0(void* params)
{
    Ref_001300C0 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 0);
    if (r.m_p) {
        return true;
    }
    return false;
}
