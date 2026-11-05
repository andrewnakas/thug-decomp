extern char D_003928D0[];
extern char D_0037AD88[];
extern void* D_00392808;
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" void func_002C4FD8(void* p, int a, int b, int c);

bool func_002CB5C8(void* params, void* script)
{
    int v = 0;
    func_001E7E58(params, D_003928D0, &v, 1);
    int n = func_001E87B8(params, D_0037AD88);
    func_002C4FD8(D_00392808, 0, v, n);
    return true;
}
