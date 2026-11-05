extern void* D_0038FC78;
extern char D_0038F5A8[];
extern "C" bool func_001E7E58(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_0022DE70(void* g, unsigned int v);
extern "C" void* func_00203360(void* p);
extern "C" void func_002383A8(void* p);

extern "C" bool func_00219F28(void* params, void* script)
{
    unsigned int v;
    func_001E7E58(params, D_0038F5A8, &v, 1);
    func_002383A8(func_00203360(func_0022DE70(D_0038FC78, v)));
    return true;
}
