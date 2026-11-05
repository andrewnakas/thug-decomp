extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E11C8(int v);

extern "C" int func_0020EB38(void* params)
{
    int v = 0;
    if (func_001E8398(params, 0, &v, 0)) return func_001E11C8(v);
    return 0;
}
