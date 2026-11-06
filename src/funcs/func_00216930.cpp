struct Game_00216930 {
    char pad0[0x84];
    void* m84;
};

struct Script_00216930 {
    char pad0[0x18];
    void* m_params;
};

extern char D_0038F610[];
extern Game_00216930* D_0038FC78;
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void* func_0026EE38(void* p);
extern "C" int func_0026DF90(void* p);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, int value);

bool Cmd_00216930(void* params, Script_00216930* script)
{
    void* out = script->m_params;
    void* p = D_0038FC78->m84;
    unsigned int name = func_001F0D78(D_0038F610);
    func_001E7A30(out, name, 3, func_0026DF90(func_0026EE38(p)));
    return true;
}
