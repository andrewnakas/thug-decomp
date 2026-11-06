extern char D_0038F348[];
extern char D_0038F350[];
extern "C" bool func_001E84E8(void* params, char* name, int* out, int required);

bool Cmd_0020B4F8(void* params, void* script)
{
    int a = 0;
    func_001E84E8(params, D_0038F348, &a, 0);
    int b = 0;
    func_001E84E8(params, D_0038F350, &b, 0);
    return a == b;
}
