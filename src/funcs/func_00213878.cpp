extern char D_003708F0[];
extern char D_00370900[];
extern "C" int func_001E7E58(void* params, void* name, int* out, int req);
extern "C" void func_001325E0(int a, int b);

bool func_00213878(void* params, void* script)
{
    int a;
    int b;
    b = 0;
    a = 0;
    func_001E7E58(params, D_003708F0, &a, 0);
    func_001E7E58(params, D_00370900, &b, 0);
    func_001325E0(a, b);
    return true;
}
