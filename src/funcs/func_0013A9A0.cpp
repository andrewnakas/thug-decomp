extern void* D_00393EF8;
extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" void* func_001394A0(void* mgr, const char* name);
extern "C" void func_001390E0(void* mgr, void* o);

extern "C" bool func_0013A9A0(void* params)
{
    const char* name;
    func_001E8870(params, 0, &name, 0);
    void* o = func_001394A0(D_00393EF8, name);
    if (o) {
        func_001390E0(D_00393EF8, o);
    }
    return true;
}
