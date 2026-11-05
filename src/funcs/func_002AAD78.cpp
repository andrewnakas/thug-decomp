extern void* D_00392068;
extern char D_003921F8[];
extern char D_00378B78[];
extern "C" int func_001E7E58(void* p, char* key, signed char* out, int req);
extern "C" int func_001E84E8(void* p, char* key, int* out, int req);
extern "C" void func_002A8630(void* m, int a, int b);

extern "C" bool func_002AAD78(void* params)
{
    signed char c;
    int v;
    void* m = D_00392068;
    func_001E7E58(params, D_003921F8, &c, 1);
    func_001E84E8(params, D_00378B78, &v, 1);
    func_002A8630(m, c, v);
    return true;
}
