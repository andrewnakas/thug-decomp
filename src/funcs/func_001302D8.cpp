extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_001302D8 {
    char pad0[0x18];
    unsigned int m_id;
};

struct RefBase_001302D8 {
    void* m_p;
    RefBase_001302D8* m_prev;
    RefBase_001302D8* m_next;
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
    RefBase_001302D8(const RefBase_001302D8& o);
    ~RefBase_001302D8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_001302D8 {
    Elem_001302D8* m_p;
    Ref_001302D8* m_prev;
    Ref_001302D8* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_001302D8*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_001302D8(const RefBase_001302D8& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_001302D8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_001302D8;
extern Mgr_001302D8* D_00389A30;
extern char D_0035D2E0[];
extern "C" RefBase_001302D8 func_0012DB48(Mgr_001302D8* m, unsigned int id, int a);
extern "C" void func_001262A0(Elem_001302D8* e, const char* text);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

extern "C" void func_001302D8(int a, int b)
{
    Ref_001302D8 r = func_0012DB48(D_00389A30, 0xA6343CD4, 0);
    Elem_001302D8* e = r.m_p;
    if (e) {
        char buf[0x40];
        func_003331D0(buf, D_0035D2E0, a, b);
        func_001262A0(e, buf);
    }
}
