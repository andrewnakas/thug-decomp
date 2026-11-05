struct Script_00242DA8 {
    char pad[0x18];
    void* m_params;
};

struct Owner_00242DA8 {
    char pad[0x20];
    unsigned int m_20;
};

extern "C" Owner_00242DA8* func_00240850();
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

bool Cmd_00242DA8(void* params, Script_00242DA8* script)
{
    unsigned int v = func_00240850()->m_20;
    if (v) {
        func_001E7360(script->m_params, 0x9982E501, v);
        return true;
    }
    return false;
}
