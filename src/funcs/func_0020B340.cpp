struct Script_0020B340 {
    char m_pad0[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" bool func_001E7EB0(void* params, int name, float* out, int required);
extern "C" void func_001E6B90(void* params, int name);
extern "C" void func_001E7200(void* params, int name, int v);

bool Cmd_0020B340(void* params, Script_0020B340* script)
{
    int name = 0;
    if (!func_001E8398(params, 0, &name, 0))
        return false;
    float v = 0.0f;
    if (!func_001E7EB0(script->m_params, name, &v, 0))
        return false;
    func_001E6B90(script->m_params, name);
    func_001E7200(script->m_params, name, (int)v);
    return true;
}
