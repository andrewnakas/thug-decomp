struct Script_00222B38 {
    char pad0[0x18];
    void* m_params;
};

extern char D_0038F8E0[];
extern char D_003719C8[];
extern char D_0038F900[];
extern char D_003719D8[];
extern char D_00371AA8[];

extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);

bool func_00222B38(void* params, Script_00222B38* script)
{
    unsigned int name;
    func_001E84E8(params, D_0038F8E0, &name, 1);
    void* s = func_001E5548(name, 1);
    unsigned int value;
    if (!func_001E84E8(s, D_003719C8, &value, 0) && !func_001E84E8(s, D_0038F900, &value, 0))
        value = func_001F0D78(D_003719D8);
    func_001E73C8(script->m_params, D_00371AA8, value);
    return true;
}
