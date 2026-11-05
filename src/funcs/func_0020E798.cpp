extern void* D_0038DB38;
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int id, int* out, int req);
extern "C" void func_001D0BC8(void* o, int v);

bool func_0020E798(void* params, void* script)
{
    void* o = D_0038DB38;
    int v;
    if (!func_001E8398(params, 0, &v, 0))
        func_001E88D8(params, 0, &v, 1);
    func_001D0BC8(o, v);
    return true;
}
