struct Script_00222D40 {
    char pad[0x18];
    void* m_params;
};

struct Mgr_00222D40 {
    char pad0[0x24];
    void* m_24;
    char pad28[0x84 - 0x28];
    void* m_84;
};

extern Mgr_00222D40* D_0038FC78;
extern char D_0038F868[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_00263930(void* a);
extern "C" void* func_0026EE60(void* a, int b);
extern "C" void func_0026EB38(void* a, void* b);

bool Cmd_00222D40(void* params, Script_00222D40* script)
{
    Mgr_00222D40* mgr = D_0038FC78;
    int v;
    if (!func_001E7E58(params, D_0038F868, &v, 0)) {
        v = func_00263930(mgr->m_24);
    }
    func_0026EB38(func_0026EE60(mgr->m_84, v), script->m_params);
    return true;
}
