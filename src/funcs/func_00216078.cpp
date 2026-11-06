struct Script_00216078 {
    char m_pad0[0x18];
    void* m_params;
};

struct Mgr_00216078 {
    char m_pad0[0x3AC];
    int m3AC;
};

struct Obj_00216078 {
    char m_pad0[0x58];
    int m58;
};

extern Mgr_00216078* D_0038FC78;
extern char D_0038F608[];

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, int value);
extern "C" Obj_00216078* func_00240850();
extern "C" void func_001E7360(void* params, unsigned int name, int value);

bool Cmd_00216078(void* params, Script_00216078* script)
{
    void* p = script->m_params;
    Mgr_00216078* mgr = D_0038FC78;
    func_001E7A68(p, func_001F0D78(D_0038F608), 13, mgr->m3AC);
    func_001E7360(script->m_params, 0x16A0B364, func_00240850()->m58);
    return true;
}
