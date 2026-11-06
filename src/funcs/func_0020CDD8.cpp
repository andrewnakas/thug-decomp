extern void* D_0038FC78;
extern char D_003700C0[];
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void func_002624C8(void* p, const char* s);

extern "C" bool func_0020CDD8(void* params, void* script)
{
    void* p = func_0022E368(D_0038FC78, 0);
    const char* s = D_003700C0;
    func_001E7C80(params, 0, &s, 0);
    func_002624C8(p, s);
    return true;
}
