extern void* D_0038FC78;
extern char D_0038F598[];

extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" bool func_001E88D8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00185128(void* obj, bool flag);

class Obj_00214B40 {
public:
    char pad0[8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Hide();
};

extern "C" Obj_00214B40* func_0022DE70(void* mgr, int id);

bool func_00214B40(void* params)
{
    bool flag = func_001E87B8(params, D_0038F598);
    int id;
    func_001E88D8(params, 0, &id, 1);
    Obj_00214B40* o = func_0022DE70(D_0038FC78, id);
    if (o) {
        o->Hide();
        func_00185128(o, flag);
    }
    return true;
}
