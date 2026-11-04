extern char D_0038F4B8[];
extern char D_0038F4C0[];
extern char D_0038F350[];
extern char D_0038F4C8[];
extern char D_00370710[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00103F28(const char* fmt);

bool func_00212648(void* params)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    func_001E7E58(params, D_0038F4B8, &a, 0);
    func_001E7E58(params, D_0038F4C0, &b, 0);
    func_001E7E58(params, D_0038F350, &c, 0);
    func_001E7E58(params, D_0038F4C8, &d, 0);
    func_00103F28(D_00370710);
    return true;
}
