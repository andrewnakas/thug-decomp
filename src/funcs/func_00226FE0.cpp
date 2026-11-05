struct Script_00226FE0 {
    char pad[0x18];
    void* m_params;
};

extern char D_00372208[];
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_002277F0(unsigned int v);
extern "C" int func_00225D90(unsigned int v, int n);
extern "C" void func_001E7268(void* params, char* name, int value);

bool Cmd_00226FE0(void* params, Script_00226FE0* script)
{
    unsigned int v = 0;
    func_001E8398(params, 0, &v, 0);
    int r = func_00225D90(v, func_002277F0(v));
    func_001E7268(script->m_params, D_00372208, r);
    return true;
}
