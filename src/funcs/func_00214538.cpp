struct Obj_00214538 {
    char pad[0x1C];
    int m1C;
};

struct Script_00214538 {
    char pad[0xBC];
    Obj_00214538* mBC;
};

extern void* D_0038FC78;
extern char D_0038F578[];
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" Obj_00214538* func_0022DE70(void* g, int id);
extern "C" void func_00184C88(Obj_00214538* o, unsigned int a, int b);

bool Cmd_00214538(void* params, Script_00214538* script)
{
    int a = 0;
    func_001E8180(params, 0x7031F10C, &a, 0);
    unsigned int b = 0;
    func_001E8398(params, 0, &b, 0);
    Obj_00214538* o;
    if (script && script->mBC && script->mBC->m1C == 1) {
        o = script->mBC;
    } else {
        void* g = D_0038FC78;
        int id = 0;
        func_001E7E58(params, D_0038F578, &id, 0);
        o = func_0022DE70(g, id);
    }
    if (o) func_00184C88(o, b, a);
    return true;
}
