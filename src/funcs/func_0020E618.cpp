extern void* D_0038DB38;

extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_001D0BD0(void* mgr);
extern "C" bool func_001D0AA8(void* mgr, const char* name, int n, int id, bool a, bool b);

bool func_0020E618(void* params)
{
    void* mgr = D_0038DB38;
    const char* name;
    int n = 0;
    func_001E8870(params, 0xA1DC81F9, &name, 0);
    func_001E8A30(params, 0x4D20D794, &n, 1);
    bool a = false;
    if (func_001E8708(params, 0x90E07C79))
        a = true;
    bool b = true;
    if (!func_001E8708(params, 0x23028E29))
        b = false;
    return func_001D0AA8(mgr, name, n, func_001D0BD0(mgr), a, b);
}
