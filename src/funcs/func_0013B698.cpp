struct Script_0013B698 {
    char pad[0x18];
    void* m_params;
};

extern char D_0035E1B0[];
extern char D_0035E1C0[];
extern char D_0035E1D0[];
extern char D_0035E1E8[];
extern char D_0035E1F8[];
extern char D_0038A100[];
extern char D_0038A108[];
extern "C" int func_0013B0E0();
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);

bool Cmd_0013B698(void* params, Script_0013B698* script)
{
    void* out = script->m_params;
    switch (func_0013B0E0()) {
    case 1:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0035E1C0));
        break;
    case 2:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0035E1D0));
        break;
    case 3:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0035E1E8));
        break;
    case 0:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0035E1F8));
        break;
    case 4:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0038A100));
        break;
    case 5:
        func_001E73C8(out, D_0035E1B0, func_001F0D78(D_0038A108));
        break;
    }
    return true;
}
