extern "C" void* func_00185578(void* obj, unsigned int name);

struct Comp_001BB080 {
    int m_base[6];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual int GetId();
};

struct Obj_001BB080 {
    int m_pad[29];
    int m74;
    int m78[4];
    char m88;
    signed char m89;
};

extern "C" void* func_00209A38(Obj_001BB080* o);
extern "C" int func_00209A00(Obj_001BB080* o);
extern "C" void* func_00209A30(Obj_001BB080* o);

struct C_001BB080 {
    int m_pad[4];
    void Update(int a, Obj_001BB080* o);
};

extern "C" void func_001BB2E8(C_001BB080* self, int a, int b, int c, void* d);

void C_001BB080::Update(int a, Obj_001BB080* o)
{
    if (!o->m89) return;
    if (!o->m74) return;
    if (func_00209A38(o)) {
        Comp_001BB080* c = (Comp_001BB080*)func_00185578(func_00209A38(o), 0xC472ECC5);
        int x = o->m74;
        int v;
        if (c) v = c->GetId();
        else v = 0;
        func_001BB2E8(this, a, x, v, func_00209A38(o));
    } else if (func_00209A00(o)) {
        if (!func_00209A30(o)) return;
        Comp_001BB080* c = (Comp_001BB080*)func_00185578(func_00209A30(o), 0xC472ECC5);
        int x = o->m74;
        int v;
        if (c) v = c->GetId();
        else v = 0;
        func_001BB2E8(this, a, x, v, func_00209A30(o));
    } else {
        func_001BB2E8(this, a, o->m74, 0, 0);
    }
}
