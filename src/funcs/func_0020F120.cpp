extern void* D_0038E0A0;
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001DD678(void* p, int v, int z);

int func_0020F120(void* params, void* script)
{
    int v = 0;
    if (func_001E8398(params, 0, &v, 0))
        return func_001DD678(D_0038E0A0, v, 0);
    return 0;
}
