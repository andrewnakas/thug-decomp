extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_0012FEC0 {
    char pad0[0x1C];
    unsigned int m_type;
};

struct RefBase_0012FEC0 {
    void* m_p;
    RefBase_0012FEC0* m_prev;
    RefBase_0012FEC0* m_next;
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
    RefBase_0012FEC0(const RefBase_0012FEC0& o);
    ~RefBase_0012FEC0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012FEC0 {
    Elem_0012FEC0* m_p;
    Ref_0012FEC0* m_prev;
    Ref_0012FEC0* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012FEC0*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012FEC0(const RefBase_0012FEC0& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012FEC0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_0012FEC0;
extern Mgr_0012FEC0* D_00389A30;
extern char D_0035D2C8[];
extern "C" RefBase_0012FEC0 func_0012DC18(Mgr_0012FEC0* m, void* params, unsigned int name, int a);
extern "C" void func_001239E8(Elem_0012FEC0* e, float* x, float* y);
extern "C" void func_001E75F0(void* params, const char* name, float x, float y);

struct Script_0012FEC0 {
    char pad0[0x18];
    void* m_params;
};

extern "C" bool func_0012FEC0(void* params, Script_0012FEC0* script)
{
    Ref_0012FEC0 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 1);
    float x;
    float y;
    func_001239E8(r.m_p, &x, &y);
    func_001E75F0(script->m_params, D_0035D2C8, x, y);
    return true;
}
