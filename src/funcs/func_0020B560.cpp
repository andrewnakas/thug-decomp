extern char D_0038F348[];
extern char D_0038F350[];
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" unsigned int func_001F0D78(char* s);

bool Cmd_0020B560(void* params, void* script)
{
    char* a;
    char* b;
    func_001E8890(params, D_0038F348, &a, 1);
    func_001E8890(params, D_0038F350, &b, 1);
    return func_001F0D78(a) == func_001F0D78(b);
}
