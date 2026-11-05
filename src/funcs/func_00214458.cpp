struct Obj_00214458 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x31C - 0x20];
    int m31C;
};

struct Script_00214458 {
    char pad0[0xBC];
    Obj_00214458* mBC;
};

extern char D_0038F578[];
extern void* D_0038FC78;
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" Obj_00214458* func_0022DE70(void* m, int id);
extern "C" Obj_00214458* func_0022DD38(void* m);
extern "C" void func_00206870(Obj_00214458* o, unsigned int b, int a);

bool Cmd_00214458(void* params, Script_00214458* script)
{
    int a = 0;
    func_001E8180(params, 0x7031F10C, &a, 0);
    unsigned int b = 0;
    func_001E8398(params, 0, &b, 0);
    Obj_00214458* o;
    if (script && script->mBC && script->mBC->m1C == 1) {
        o = script->mBC;
    } else {
        void* m = D_0038FC78;
        int id = 0;
        if (func_001E7E58(params, D_0038F578, &id, 0))
            o = func_0022DE70(m, id);
        else
            o = func_0022DD38(m);
    }
    if (o && o->m31C) func_00206870(o, b, a);
    return true;
}
