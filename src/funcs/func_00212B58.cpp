extern char D_0038F4F8[];
extern "C" int func_001E84E8(void* params, void* name, void** out, int req);
extern "C" void* func_001317D0(void* p);
extern "C" void func_00135530(void* p, int v);

bool func_00212B58(void* params, void* script)
{
    void* v;
    func_001E84E8(params, D_0038F4F8, &v, 0);
    func_00135530(func_001317D0(v), 0);
    return true;
}
