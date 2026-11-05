extern void* D_00388A44;
extern "C" int func_001E8870(void*, int, void*, int);
extern "C" int func_00109060(void* o, int v);

int Cmd_001095F0(void* params)
{
    int v;
    func_001E8870(params, 0, &v, 1);
    return func_00109060(D_00388A44, v);
}
