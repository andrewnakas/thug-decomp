extern "C" int func_001E8870(void* params, int name, int* out, int req);
extern "C" void func_00130AE0(int v);

bool Cmd_00130E10(void* params)
{
    int v;
    func_001E8870(params, 0, &v, 0);
    func_00130AE0(v);
    return true;
}
