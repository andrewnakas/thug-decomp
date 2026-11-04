struct Script_00124AC0 {
    char pad[0x18];
    void* m18;
};

struct Obj_00124AC0;

extern "C" void func_00183C98(Obj_00124AC0* o, void* h);
extern "C" void func_00183CB8(Obj_00124AC0* o, void* h);

struct Handle_00124AC0 {
    Obj_00124AC0* m_obj;
    Handle_00124AC0* m_prev;
    Handle_00124AC0* m_next;
    Handle_00124AC0(Obj_00124AC0* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_00124AC0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Base_00124AC0 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1(void* params);
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8(void* p);
    virtual void V9(void* params);
};

struct C_00124AC0 : public Base_00124AC0 {
    char padC[0x18 - 0xC];
    void* m18;
    char pad1C[0x48 - 0x1C];
    Obj_00124AC0* m48;
    bool CallMember(unsigned int id, void* params, Script_00124AC0* script);
};

extern void* D_00389A30;
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" void func_001EFFB0(Script_00124AC0* s, unsigned int v);
extern "C" void func_00124118(Obj_00124AC0* o, int on);
extern "C" void func_0012D8B0(void* mgr, void* a, int b, int c, Script_00124AC0* s);
extern "C" bool func_001842E0(C_00124AC0* o, unsigned int id, void* params, Script_00124AC0* script);

bool C_00124AC0::CallMember(unsigned int id, void* params, Script_00124AC0* script)
{
    if (id == 0x6C63C7C5) {
        V1(params);
    } else if (id == 0xDD0C8DF3) {
        float f;
        if (func_001E7EB0(params, 0x906B67BA, &f, 0))
            func_001EFFB0(script, (unsigned int)(f * 1000.0f));
        V9(params);
    } else if (id == 0xC6870028) {
        void* mgr = D_00389A30;
        Handle_00124AC0 h(m48);
        func_00124118(h.m_obj, 0);
        func_0012D8B0(mgr, m18, 1, 0, script);
        func_00124118(h.m_obj, 1);
    } else if (id == 0x9492F814) {
        V8(script->m18);
    } else {
        return func_001842E0(this, id, params, script);
    }
    return true;
}
