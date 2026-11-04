extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int req);
extern "C" void* func_0022DE70(int a, int b);
extern "C" void* func_0022DD38(int a);
extern "C" void func_001E73C8(void* s, void* name, int v);
extern int D_0038FC78;
extern char D_0038F848[];

struct Obj_0021DF98 {
    char pad0[0x18];
    int m_18;
    char pad1C[0x31C - 0x1C];
    int m_31C;
};

struct Script_0021DF98 {
    char pad0[0x18];
    void* m_18;
};

bool Cmd_0021DF98(void* params, Script_0021DF98* script)
{
    int id;
    Obj_0021DF98* o;
    if (func_001E7DE8(params, 0x5B8AB877, &id, 0)) {
        o = (Obj_0021DF98*)func_0022DE70(D_0038FC78, id);
    } else {
        o = (Obj_0021DF98*)func_0022DD38(D_0038FC78);
    }
    if (o) {
        if (o->m_31C) {
            func_001E73C8(script->m_18, D_0038F848, o->m_18);
            return true;
        }
        return false;
    }
    return false;
}
