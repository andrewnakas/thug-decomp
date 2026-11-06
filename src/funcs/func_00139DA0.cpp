extern void* D_00393EF4;
extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void* func_00138F58(void* mgr, const char* name, int a, int b, int c);

extern "C" bool func_00139DA0(void* params)
{
    const char* name;
    func_001E8870(params, 0, &name, 0);
    int f = func_001E8708(params, 0x3955FF2E);
    return func_00138F58(D_00393EF4, name, 1, !f, 1) != 0;
}
