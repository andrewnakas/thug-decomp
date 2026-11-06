extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_0012F760 {
    char pad0[0x18];
    unsigned int m_id;
};

struct RefBase_0012F760 {
    void* m_p;
    RefBase_0012F760* m_prev;
    RefBase_0012F760* m_next;
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
    RefBase_0012F760(const RefBase_0012F760& o);
    ~RefBase_0012F760()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012F760 {
    Elem_0012F760* m_p;
    Ref_0012F760* m_prev;
    Ref_0012F760* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012F760*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012F760(const RefBase_0012F760& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012F760()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_0012F760;
extern Mgr_0012F760* D_00389A30;
extern "C" RefBase_0012F760 func_0012DC18(Mgr_0012F760* m, void* params, unsigned int name, int a);
extern char D_00389A50[];
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" void func_00124118(Elem_0012F760* e, int on);

extern "C" bool func_0012F760(void* params, void* script)
{
    Ref_0012F760 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 1);
    if (func_001E87B8(params, D_00389A50)) {
        func_00124118(r.m_p, 0);
    } else {
        func_00124118(r.m_p, 1);
    }
    return true;
}
