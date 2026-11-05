extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

extern "C" bool func_0020B310(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    return v == 0;
}
