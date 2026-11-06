struct Script_0021EDA8 {
    char pad[0x18];
    void* m_params;
};
extern void* D_0038FC78;
extern char D_0038F810[];
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_002624F0(void* p);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, int v);

extern "C" bool func_0021EDA8(void* params, Script_0021EDA8* script)
{
    void* p = func_0022E368(D_0038FC78, 0);
    void* out = script->m_params;
    unsigned int name = func_001F0D78(D_0038F810);
    func_001E7A30(out, name, 3, func_002624F0(p));
    return true;
}
