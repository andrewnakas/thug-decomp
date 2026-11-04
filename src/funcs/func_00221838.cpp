struct X_00221838 {
    int m0;
    char m4[4];
};

struct Script_00221838 {
    char pad0[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" X_00221838* func_0022E3C8(void* m, int idx);
extern "C" void* func_0011FE18(void* list, unsigned int name);
extern "C" void func_001E6AC8(void* dst, void* src);

bool Cmd_00221838(void* params, Script_00221838* script)
{
    int idx = 0;
    func_001E7DE8(params, 0x67E6859A, &idx, 0);
    void* list = func_0022E3C8(D_0038FC78, idx)->m4;
    unsigned int name;
    if (!func_001E8398(params, 0xB6F08F39, &name, 0)) return false;
    void* v = func_0011FE18(list, name);
    if (!v) return false;
    func_001E6AC8(script->m18, v);
    return true;
}
