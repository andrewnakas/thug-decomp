struct Obj_0021E4A0 {
    char pad0[0x31C];
    int m31C;
};

struct Mgr_0021E4A0 {
    char pad0[0x39C];
    void* m39C;
};

extern char D_003716F8[];
extern Mgr_0021E4A0* D_0038FC78;
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Obj_0021E4A0* func_00184D70(unsigned int name);
extern "C" Obj_0021E4A0* func_0022DE70(Mgr_0021E4A0* m, int i);
extern "C" bool func_0025F838(void* p, unsigned int name);

bool Cmd_0021E4A0(void* params, void* script)
{
    unsigned int name;
    int idx = 0;
    Obj_0021E4A0* o;
    if (func_001E84E8(params, D_003716F8, &name, 0)) {
        o = func_00184D70(name);
    } else {
        func_001E7DE8(params, 0x5B8AB877, &idx, 0);
        o = func_0022DE70(D_0038FC78, idx);
    }
    if (o && o->m31C) {
        unsigned int n2 = 0;
        func_001E8398(params, 0xA1DC81F9, &n2, 0);
        return func_0025F838(D_0038FC78->m39C, n2);
    }
    return true;
}
