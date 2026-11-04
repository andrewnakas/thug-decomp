extern void* D_00392808;
extern char D_003928D0[];
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" void func_002C4FD8(void* p, int a, int b, int c);

extern "C" bool func_002CB580(void* params)
{
    int v = 0;
    func_001E7E58(params, D_003928D0, &v, 1);
    func_002C4FD8(D_00392808, 1, v, 0);
    return true;
}
