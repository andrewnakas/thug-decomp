extern "C" bool func_001E7B58(void* params, unsigned int name, int type, void** out);
extern "C" void func_001E93D0(void* params, int a);

extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required)
{
    void* v;
    if (func_001E7B58(params, name, 12, &v)) {
        *out = v;
        return true;
    }
    if (required)
        func_001E93D0(params, 0);
    return false;
}
