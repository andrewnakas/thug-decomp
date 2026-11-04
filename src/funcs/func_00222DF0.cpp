struct Script_00222DF0 {
    char pad0[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_00371AB8[];
extern char D_00371AC8[];

extern "C" bool func_001E7D18(void* params, const char* name, const char** out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_0022DD38(void* mgr);
extern "C" void* func_00203360(void* obj);
extern "C" int func_0023A168(void* goals, unsigned int name, int a, int b, int c);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00222DF0(void* params, Script_00222DF0* script)
{
    const char* name;
    func_001E7D18(params, D_00371AB8, &name, 1);
    unsigned int crc = func_001F0D78(name);
    int r = func_0023A168(func_00203360(func_0022DD38(D_0038FC78)), crc, 0, 0, 1);
    func_001E7268(script->m_params, D_00371AC8, r);
    return true;
}
