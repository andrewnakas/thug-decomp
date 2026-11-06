class Obj_00214BC8 {
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
    virtual void V9();
    virtual void Reset();
};

extern void* D_0038FC78;
extern "C" bool func_001E88D8(void* params, unsigned int name, int* out, int required);
extern "C" Obj_00214BC8* func_0022DE70(void* mgr, int id);
extern "C" void func_00185128(Obj_00214BC8* o, int a);

bool Cmd_00214BC8(void* params, void* script)
{
    int id;
    func_001E88D8(params, 0, &id, 1);
    Obj_00214BC8* o = func_0022DE70(D_0038FC78, id);
    if (o) {
        o->Reset();
        func_00185128(o, 0);
    }
    return true;
}
