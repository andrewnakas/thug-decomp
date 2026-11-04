extern "C" int func_001E8890(void* params, void* name, int* out, int req);
extern "C" void* func_00131E20(int a);
extern "C" void func_00133A20(void* a, int b);
extern char D_0038F468[];
extern char D_0038F470[];

bool Cmd_00210ED0(void* params)
{
    int a = 0;
    int b = 0;
    func_001E8890(params, D_0038F468, &a, 0);
    func_001E8890(params, D_0038F470, &b, 0);
    if (a && b) {
        func_00133A20(func_00131E20(a), b);
    }
    return true;
}
