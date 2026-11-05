struct Script_00222EB8 {
    char pad[0x18];
    void* m_params;
};

extern char D_00371AF0[];
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" char* func_00132670(int v);
extern "C" void func_001E7138(void* params, char* name, char* value);

bool Cmd_00222EB8(void* params, Script_00222EB8* script)
{
    int v;
    func_001E7DE8(params, 0, &v, 1);
    char* str = func_00132670(v);
    func_001E7138(script->m_params, D_00371AF0, str);
    return true;
}
