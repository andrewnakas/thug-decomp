extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Elem_0012F278 {
    char pad0[0x18];
    unsigned int m_id;
};

struct RefBase_0012F278 {
    void* m_p;
    RefBase_0012F278* m_prev;
    RefBase_0012F278* m_next;
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
    RefBase_0012F278(const RefBase_0012F278& o);
    ~RefBase_0012F278()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012F278 {
    Elem_0012F278* m_p;
    Ref_0012F278* m_prev;
    Ref_0012F278* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012F278*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012F278(const RefBase_0012F278& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012F278()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Script_0012F278 {
    char pad0[0x18];
    void* m_params;
};

struct Mgr_0012F278;
extern Mgr_0012F278* D_00389A30;
extern unsigned int D_0038C6D4;
extern char D_00389A48[];
extern "C" int func_001E84E8(void* params, const char* name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" RefBase_0012F278 func_0012D310(Mgr_0012F278* m, int type, unsigned int id, void* params);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int v);

extern "C" bool func_0012F278(void* params, Script_0012F278* script)
{
    int type;
    func_001E84E8(params, D_00389A48, &type, 0);
    unsigned int id = D_0038C6D4;
    func_001E8398(params, 0x40C698AF, &id, 0);
    Ref_0012F278 r = func_0012D310(D_00389A30, type, id, params);
    id = r.m_p->m_id;
    func_001E7360(script->m_params, 0x40C698AF, id);
    return true;
}
