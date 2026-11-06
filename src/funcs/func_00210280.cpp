struct Script_00210280 {
    char m_pad0[0xBC];
    void* m_obj;
};

extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" void func_001EE8C8(Script_00210280* script, int a, int b, void* obj);

bool Cmd_00210280(void* params, Script_00210280* script)
{
    int a = 0;
    func_001E8398(params, 0, &a, 0);
    int b = 0;
    func_001E8180(params, 0x7031F10C, &b, 0);
    func_001EE8C8(script, a, b, script->m_obj);
    return true;
}
