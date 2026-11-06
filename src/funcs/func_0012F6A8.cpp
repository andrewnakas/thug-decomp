extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

class Elem_0012F6A8 {
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
    virtual void Apply(void* params);
};

struct RefBase_0012F6A8 {
    void* m_p;
    RefBase_0012F6A8* m_prev;
    RefBase_0012F6A8* m_next;
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
    RefBase_0012F6A8(const RefBase_0012F6A8& o);
    ~RefBase_0012F6A8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Ref_0012F6A8 {
    Elem_0012F6A8* m_p;
    Ref_0012F6A8* m_prev;
    Ref_0012F6A8* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = (Elem_0012F6A8*)o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012F6A8(const RefBase_0012F6A8& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012F6A8()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Mgr_0012F6A8;
extern Mgr_0012F6A8* D_00389A30;
extern "C" RefBase_0012F6A8 func_0012DC18(Mgr_0012F6A8* m, void* params, unsigned int name, int a);

extern "C" bool func_0012F6A8(void* params, void* script)
{
    Ref_0012F6A8 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 1);
    r.m_p->Apply(params);
    return true;
}
