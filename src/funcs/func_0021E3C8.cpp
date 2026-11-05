struct Skater_0021E3C8 {
    char pad0[0x31C];
    int m31C;
};

struct Mgr_0021E3C8 {
    char pad0[0x39C];
    void* m39C;
};

struct Script_0021E3C8 {
    char pad0[0x18];
    void* m18;
};

extern Mgr_0021E3C8* D_0038FC78;
extern char D_003716F8[];
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E84E8(void* params, char* name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Skater_0021E3C8* func_00184D70(int id);
extern "C" Skater_0021E3C8* func_0022DE70(Mgr_0021E3C8* m, int id);
extern "C" void* func_0025FCA8(void* a, unsigned int name);
extern "C" void func_001E6AC8(void* a, void* b);

bool Cmd_0021E3C8(void* params, Script_0021E3C8* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0xA1DC81F9, &name, 0);
    int id = 0;
    int skater;
    Skater_0021E3C8* s;
    if (func_001E84E8(params, D_003716F8, &skater, 0)) {
        s = func_00184D70(skater);
    } else {
        func_001E7DE8(params, 0x5B8AB877, &id, 0);
        s = func_0022DE70(D_0038FC78, id);
    }
    if (!s) return false;
    if (!s->m31C) return false;
    void* r = func_0025FCA8(D_0038FC78->m39C, name);
    if (!r) return false;
    func_001E6AC8(script->m18, r);
    return true;
}
