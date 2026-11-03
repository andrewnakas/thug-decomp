struct Script_002429A0 {
    char m_pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_0023F168(void* goals);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" int func_0023EFA8(void* goals, unsigned int name);
extern "C" bool func_0023EFD0(void* goals, unsigned int name, const char* text, char* buf, int size);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);

int func_002429A0(void* params, Script_002429A0* script)
{
    char buf[0x200];
    unsigned int name;
    const char* text;
    void* goals = func_00240850();
    if (func_001E8708(params, 0xC4E78E22)) {
        func_0023F168(goals);
        return 1;
    }
    if (func_001E8398(params, 0xA1DC81F9, &name, 0)) {
        if (!func_001E7C80(params, 0xC4745838, &text, 0)) {
            return func_0023EFA8(goals, name);
        }
        if (func_0023EFD0(goals, name, text, buf, 0x200)) {
            func_001E6B90(script->m_params, 0x3EAFA520);
            func_001E70C0(script->m_params, 0x3EAFA520, buf);
        }
    }
    return 1;
}
