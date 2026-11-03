extern char D_00389F60[];
extern char D_00389F68[];
extern "C" void func_001E7E58(void* params, const void* name, void* out, int b);
extern "C" void func_001380B0(int a, int b);

int func_00138200(void* params)
{
    int a;
    int b;
    func_001E7E58(params, D_00389F60, &a, 0);
    func_001E7E58(params, D_00389F68, &b, 0);
    func_001380B0(a, b);
    return 1;
}
