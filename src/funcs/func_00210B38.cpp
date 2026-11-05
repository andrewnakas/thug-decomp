extern bool D_0038F44C;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

extern "C" bool func_00210B38(void* params, void* script)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    D_0038F44C = v != 0;
    return true;
}
