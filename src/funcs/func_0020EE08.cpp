extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E1348(unsigned int v);

extern "C" bool func_0020EE08(void* params, void* script)
{
    unsigned int v = 0;
    if (func_001E8398(params, 0, &v, 0))
        return func_001E1348(v) != 0;
    return false;
}
