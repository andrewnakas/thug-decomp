extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_002407D8(void* owner, bool flag);

bool Cmd_00243A00(void* params, void* script)
{
    void* owner = func_00240850();
    int v;
    func_001E7DE8(params, 0, &v, 1);
    func_002407D8(owner, v != 0);
    return true;
}
