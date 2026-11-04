extern char D_00392860[];
extern "C" int func_001E7D18(void* p, char* key, int* out, int req);
extern "C" void* func_002C0368();
extern "C" void func_002BD2B0(void* p, int v);

extern "C" bool func_002CBAA0(void* params)
{
    int v = 0;
    func_001E7D18(params, D_00392860, &v, 1);
    func_002BD2B0(func_002C0368(), v);
    return true;
}
