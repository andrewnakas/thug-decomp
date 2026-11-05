struct Game_002411C8 {
    char pad0[0x58];
    unsigned int m_58;
};

struct Script_002411C8 {
    char pad0[0x18];
    void* m_params;
};

extern char D_0038FF40[];

extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" Game_002411C8* func_00240850();
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7C80(void* s, unsigned int name, const char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);

bool func_002411C8(void* params, Script_002411C8* script)
{
    char buf[0x80];
    const char* suffix;
    const char* prefix;
    func_001E8870(params, 0x6D11ED74, &suffix, 1);
    func_001E7C80(func_001E5548(func_00240850()->m_58, 1), 0x651533EC, &prefix, 1);
    func_00331A9C(buf, prefix);
    func_00331678(buf, D_0038FF40);
    func_00331678(buf, suffix);
    void* out = script->m_params;
    func_001E7360(out, 0x9982E501, func_001F0D78(buf));
    func_001E70C0(script->m_params, 0xBFECC45B, buf);
    return true;
}
