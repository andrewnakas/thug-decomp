extern "C" bool func_001E7B58(void* params, unsigned int name, int type, int* out);
extern "C" void func_001E93D0(void* params, int a);

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required)
{
    int v;
    if (func_001E7B58(params, name, 1, &v)) {
        *out = v;
        return true;
    }
    if (required)
        func_001E93D0(params, 0);
    return false;
}
