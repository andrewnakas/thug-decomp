extern char D_0038F550[];
extern char D_0038F558[];
extern "C" void* func_00230490(void* params, int a);
extern "C" bool func_001E8A50(void* params, const char* name, int* out, int required);
extern "C" bool func_001E8A10(void* params, const char* name, int* out, int required);
extern "C" void func_00203068(void* p, int a, int b);

extern "C" bool func_00212E50(void* params, void* script)
{
    void* p = func_00230490(params, 1);
    int a;
    int b;
    func_001E8A50(params, D_0038F550, &a, 1);
    func_001E8A10(params, D_0038F558, &b, 1);
    func_00203068(p, a, b);
    return true;
}
