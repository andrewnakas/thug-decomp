extern char D_0038F720[];
extern "C" int func_001E84E8(void* params, void* name, void** out, int req);
extern "C" void* func_001E5548(void* p, int v);
extern "C" void func_001E6B30(void* p);

bool func_00219AF8(void* params, void* script)
{
    void* v;
    func_001E84E8(params, D_0038F720, &v, 1);
    func_001E6B30(func_001E5548(v, 1));
    return true;
}
