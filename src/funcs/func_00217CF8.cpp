struct Script_00217CF8;

struct ObjBase_00217CF8 {
    char pad0[0x14];
    ObjBase_00217CF8* m_next;
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
    virtual void Call(unsigned int a, int b, Script_00217CF8* script);
};

extern void* D_0038C608;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" ObjBase_00217CF8* func_00187278(void* mgr, unsigned int id);

bool func_00217CF8(void* params, Script_00217CF8* script)
{
    unsigned int id;
    unsigned int a;
    func_001E8398(params, 0xB6015EA8, &id, 1);
    func_001E8398(params, 0xB990D003, &a, 1);
    int b = 0;
    func_001E8180(params, 0x7031F10C, &b, 0);
    for (ObjBase_00217CF8* o = func_00187278(D_0038C608, id); o; o = o->m_next)
        o->Call(a, b, script);
    return true;
}
