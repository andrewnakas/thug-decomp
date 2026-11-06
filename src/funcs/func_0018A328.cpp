extern void* D_0038C7B0;
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" void func_00189F98(void* mgr, void* script, int v);

bool func_0018A328(void* params, void* script)
{
    int v;
    func_001E8398(params, 0x7321A8D6, &v, 0);
    func_00189F98(D_0038C7B0, script, v);
    return true;
}
