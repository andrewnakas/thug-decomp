extern char D_0038F468[];
extern "C" bool func_001E8890(void* params, char* name, const char** out, int required);
extern "C" void func_00131D68(const char* s);

extern "C" bool func_00210FE8(void* params, void* script)
{
    const char* s = 0;
    func_001E8890(params, D_0038F468, &s, 0);
    if (s)
        func_00131D68(s);
    return true;
}
