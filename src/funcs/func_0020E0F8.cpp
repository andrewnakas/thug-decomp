extern void* D_0038FC78;
extern "C" void* func_0022E358(void* mgr);
extern "C" void func_0024F860(void* p);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E10E0();
extern "C" bool func_001E10E8(int n);
extern "C" bool func_001E1128();

extern "C" bool func_0020E0F8(void* params, void* script)
{
    func_0024F860(func_0022E358(D_0038FC78));
    int n;
    if (func_001E7DE8(params, 0, &n, 0)) {
        if (n < func_001E10E0())
            return func_001E10E8(n);
        return false;
    }
    return func_001E1128();
}
