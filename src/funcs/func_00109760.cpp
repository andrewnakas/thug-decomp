extern void* D_00388A44;
extern "C" int func_001E8870(void* params, int name, int* out, int req);
extern "C" int func_001091B0(void* o, int v);

int Cmd_00109760(void* params)
{
    void* o = D_00388A44;
    int v;
    func_001E8870(params, 0, &v, 1);
    return func_001091B0(o, v);
}
