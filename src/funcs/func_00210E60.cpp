extern char D_0038F468[];
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int flag);
extern "C" void* func_00131E20(char* s);
extern "C" void func_00133848(void* mgr, char* s, bool flag);

bool Cmd_00210E60(void* params, void* script)
{
    char* s = 0;
    func_001E8890(params, D_0038F468, &s, 0);
    bool flag = func_001E8708(params, 0x417149C8);
    if (s)
        func_00133848(func_00131E20(s), s, flag);
    return true;
}
