extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_0023D668(void* owner, int v);

bool Cmd_002416D8(void* params, void* script)
{
    void* owner = func_00240850();
    int v;
    func_001E7DE8(params, 0, &v, 1);
    return func_0023D668(owner, v);
}
