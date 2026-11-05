extern void* D_0038DB38;
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" void func_001D0A98(void* p, bool on);

extern "C" bool func_0020E800(void* params, void* script)
{
    void* p = D_0038DB38;
    int v;
    func_001E88D8(params, 0, &v, 1);
    func_001D0A98(p, v != 0);
    return true;
}
