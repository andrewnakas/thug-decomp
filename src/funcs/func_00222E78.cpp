struct Script_00222E78 {
    char pad[0x18];
    void* m_params;
};

extern char D_00371AE0[];
extern "C" int func_00132650();
extern "C" void func_001E7268(void* params, char* name, int value);

bool Cmd_00222E78(void* params, Script_00222E78* script)
{
    int v = func_00132650();
    func_001E7268(script->m_params, D_00371AE0, v);
    return true;
}
