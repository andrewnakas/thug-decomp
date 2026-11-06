extern void* D_0038DB38;
extern char D_0038F368[];
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_001D05B0(void* mgr, unsigned int name, int a);
extern "C" void func_001D0460(void* mgr, void* p);
extern "C" void func_001D04E0(void* mgr, void* p);

extern "C" bool func_0020E490(void* params, void* script)
{
    void* mgr = D_0038DB38;
    const char* name = 0;
    func_001E8890(params, D_0038F368, &name, 1);
    void* p = func_001D05B0(mgr, func_001F0D78(name), 0);
    if (p) {
        func_001D0460(mgr, p);
        func_001D04E0(mgr, p);
    }
    return true;
}
