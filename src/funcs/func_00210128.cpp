extern int D_0038FBFC;
extern char D_0038F408[];
extern char D_0038F410[];
extern char D_0038F418[];
extern char D_0038F420[];
extern char D_0038F428[];

extern "C" bool func_001E7F50(void*, char*, float*, int);
extern "C" bool func_001E84E8(void*, char*, int*, int);
extern "C" void* func_00131E48();
extern "C" void func_0020FD98(void*, float, float, float, float, int);

bool func_00210128(void* params)
{
    if (!D_0038FBFC)
        return false;
    float a = 0.9f;
    func_001E7F50(params, D_0038F408, &a, 0);
    float b = -45.0f;
    func_001E7F50(params, D_0038F410, &b, 0);
    float c = 45.0f;
    func_001E7F50(params, D_0038F418, &c, 0);
    float d = 0.0f;
    func_001E7F50(params, D_0038F420, &d, 0);
    int e = 0;
    func_001E84E8(params, D_0038F428, &e, 0);
    void* p = func_00131E48();
    if (p)
        func_0020FD98(p, a, b, c, d, e);
    return true;
}
