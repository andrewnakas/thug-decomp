extern char D_0038F400[];
extern "C" int func_001E8938(void* params, void* name, float* out, int req);
extern "C" void* func_00131E48();
extern "C" void func_0020F590(void* p, float v);

bool func_0020FD40(void* params, void* script)
{
    float v = 0.0f;
    func_001E8938(params, D_0038F400, &v, 1);
    v = v * 0.01f;
    void* p = func_00131E48();
    if (p)
        func_0020F590(p, v);
    return true;
}
