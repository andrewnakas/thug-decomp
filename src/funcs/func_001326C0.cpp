extern "C" int func_001E88D8(void* params, int name, int* out, int req);
extern "C" void func_00132630(int v);

bool Cmd_001326C0(void* params)
{
    int v = 0;
    func_001E88D8(params, 0, &v, 0);
    func_00132630(v);
    return true;
}
