extern char D_00370288[];

extern "C" bool func_001E8870(void* params, int name, int* out, int required);
extern "C" bool func_001E8890(void* params, char* name, int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001E0210(int a, int b, int c);

bool Cmd_0020E178(void* params)
{
    int a = 0;
    int b = 0;
    func_001E8870(params, 0, &a, 0);
    func_001E8890(params, D_00370288, &b, 0);
    bool c = true;
    if (func_001E8708(params, 0x389129E4))
        c = false;
    if (a)
        func_001E0210(a, c, b);
    return true;
}
