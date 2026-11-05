struct Script_00241290 {
    char pad[0x18];
    void* m_params;
};

struct Owner_00241290 {
    char pad[0x58];
    void* m_58;
};

extern "C" Owner_00241290* func_00240850();
extern "C" void* func_001E5548(void* a, int b);
extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int required);
extern "C" void func_001E70C0(void* params, unsigned int name, char* value);

bool Cmd_00241290(void* params, Script_00241290* script)
{
    char* s;
    func_001E7C80(func_001E5548(func_00240850()->m_58, 1), 0x651533EC, &s, 1);
    func_001E70C0(script->m_params, 0x15F818D0, s);
    return true;
}
