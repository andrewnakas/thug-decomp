extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_002400D0(void* owner, int v);

bool Cmd_00243328(void* params, void* script)
{
    int v;
    func_001E7DE8(params, 0, &v, 1);
    func_002400D0(func_00240850(), v);
    return v != 0;
}
