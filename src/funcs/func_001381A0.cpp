extern char D_00389F50[];
extern char D_00389F58[];
extern "C" void func_001E7E58(void* params, const void* name, void* out, int b);
extern "C" void func_00138090(int a, int b);

int func_001381A0(void* params)
{
    int a;
    int b;
    func_001E7E58(params, D_00389F50, &a, 0);
    func_001E7E58(params, D_00389F58, &b, 0);
    func_00138090(a, b);
    return 1;
}
