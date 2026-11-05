struct Script_002283F0 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038F9C4;
extern unsigned int D_0038F9C8;
extern "C" void func_001E77D0(void* params, unsigned int name, void* value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

bool Cmd_002283F0(void* params, Script_002283F0* script)
{
    func_001E77D0(script->m_params, 0x6D2AB6A, D_0038F9C4);
    func_001E7360(script->m_params, 0x7321A8D6, D_0038F9C8);
    return true;
}
