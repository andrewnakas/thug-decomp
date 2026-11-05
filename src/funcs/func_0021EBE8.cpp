extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0022DCE0(void* mgr, int v, int a);

extern "C" bool func_0021EBE8(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    func_0022DCE0(D_0038FC78, v, 0);
    return true;
}
