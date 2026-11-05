extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void* func_00240850();
extern "C" void func_0023FBE0(void* mgr);
extern "C" void* func_0023EFA0(void* mgr);
extern "C" void func_001E6B30(void* s);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_0023D970(void* mgr);

void Apply_00225838(void* params)
{
    void* src = 0;
    func_001E8180(params, 0xAC7C2B62, &src, 0);
    void* mgr = func_00240850();
    func_0023FBE0(mgr);
    void* dst = func_0023EFA0(mgr);
    func_001E6B30(dst);
    func_001E6AC8(dst, src);
    func_0023D970(mgr);
}
