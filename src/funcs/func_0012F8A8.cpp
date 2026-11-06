extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_0012F8A8 {
    char pad0[0x1C];
    unsigned int m_type;
};

struct RefBase_0012F8A8 {
    void* m_p;
    RefBase_0012F8A8* m_prev;
    RefBase_0012F8A8* m_next;
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
    RefBase_0012F8A8(const RefBase_0012F8A8& o);
    ~RefBase_0012F8A8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012F8A8 {
    Elem_0012F8A8* m_p;
    Ref_0012F8A8* m_prev;
    Ref_0012F8A8* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012F8A8*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012F8A8(const RefBase_0012F8A8& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012F8A8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_0012F8A8;
extern Mgr_0012F8A8* D_00389A30;
extern char D_0035D2B8[];
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" RefBase_0012F8A8 func_0012DB48(Mgr_0012F8A8* m, unsigned int id, int a);
extern "C" void func_001262A0(Elem_0012F8A8* e, void* arg);

extern "C" void func_0012F8A8(void* arg, int idx)
{
    Mgr_0012F8A8* m = D_00389A30;
    Ref_0012F8A8 r = func_0012DB48(m, func_001F0D78(D_0035D2B8) + idx, 0);
    if (r.m_p) {
        func_001262A0(r.m_p, arg);
    }
}
