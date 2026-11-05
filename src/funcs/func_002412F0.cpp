extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_0023D1C8(void* owner, int v);

bool Cmd_002412F0(void* params, void* script)
{
    void* owner = func_00240850();
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    return func_0023D1C8(owner, v);
}
