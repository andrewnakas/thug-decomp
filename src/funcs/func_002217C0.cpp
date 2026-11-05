struct Script_002217C0 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00121AB0(unsigned int a, unsigned int b, int c);
extern "C" void func_001E6AC8(void* dst, void* src);

bool Cmd_002217C0(void* params, Script_002217C0* script)
{
    unsigned int a;
    unsigned int b;
    func_001E8398(params, 0xB6F08F39, &a, 1);
    func_001E8398(params, 0x4BB2084E, &b, 1);
    func_001E6AC8(script->m_params, func_00121AB0(a, b, 1));
    return false;
}
