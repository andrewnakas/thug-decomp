struct Script_0020C178 {
    char m_pad0[0x18];
    void* m18;
};

extern char D_0038F368[];
extern "C" bool func_001E84E8(void* params, char* name, int* out, int required);
extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" void func_001E6B90(void* p, int v);

bool Cmd_0020C178(void* params, Script_0020C178* script)
{
    int v;
    if (!func_001E84E8(params, D_0038F368, &v, 0))
        func_001E8398(params, 0, &v, 1);
    func_001E6B90(script->m18, v);
    return true;
}
