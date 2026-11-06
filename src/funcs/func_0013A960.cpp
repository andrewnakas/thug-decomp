extern void* D_00393EF8;
extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" void* func_00138F58(void* mgr, const char* name, int a, int b, int c);

extern "C" bool func_0013A960(void* params)
{
    const char* name;
    func_001E8870(params, 0, &name, 0);
    return func_00138F58(D_00393EF8, name, 0, 1, 1) != 0;
}
