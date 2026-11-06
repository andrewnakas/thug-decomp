struct Struct_0020D120 {
    char m_pad0[0xC];
    int mC;
};

struct Script_0020D120 {
    char m_pad0[0x18];
    void* m_params;
};

extern char D_003700D0[];

extern "C" bool func_001E8248(void* params, int name, Struct_0020D120** out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, int value);

bool Cmd_0020D120(void* params, Script_0020D120* script)
{
    Struct_0020D120* s = 0;
    func_001E8248(params, 0, &s, 0);
    int v = 0;
    if (s)
        v = s->mC;
    void* p = script->m_params;
    func_001E7A68(p, func_001F0D78(D_003700D0), 1, v);
    return true;
}
