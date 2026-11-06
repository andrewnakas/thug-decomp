extern char D_0038F3A0[];
extern "C" bool func_001E7DE8(void* params, int name, int* out, int required);
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void func_001E0CA8(int a, int b, int c);

bool Cmd_0020E1F8(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    func_001E0CA8(v, func_001E87B8(params, D_0038F3A0), 0);
    return true;
}
