extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_001303B0 {
    char pad0[0x18];
    unsigned int m_id;
};

struct RefBase_001303B0 {
    void* m_p;
    RefBase_001303B0* m_prev;
    RefBase_001303B0* m_next;
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
    RefBase_001303B0(const RefBase_001303B0& o);
    ~RefBase_001303B0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_001303B0 {
    Elem_001303B0* m_p;
    Ref_001303B0* m_prev;
    Ref_001303B0* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_001303B0*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_001303B0(const RefBase_001303B0& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_001303B0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_001303B0;
extern Mgr_001303B0* D_00389A30;
extern char D_00389A88[];
extern "C" RefBase_001303B0 func_0012DB48(Mgr_001303B0* m, unsigned int id, int a);
extern "C" void func_001262A0(Elem_001303B0* e, const char* text);

extern "C" void func_001303B0()
{
    Ref_001303B0 r = func_0012DB48(D_00389A30, 0xA6343CD4, 0);
    if (r.m_p) {
        func_001262A0(r.m_p, D_00389A88);
    }
}
