extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0023F3F8(void* owner, int v);

bool Cmd_00242D48(void* params, void* script)
{
    void* owner = func_00240850();
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_0023F3F8(owner, v);
    return true;
}
