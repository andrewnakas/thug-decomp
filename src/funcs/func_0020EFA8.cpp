extern void* D_0038E0A0;
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001DD448(void* p, int v);

int func_0020EFA8(void* params, void* script)
{
    int v;
    if (func_001E8398(params, 0, &v, 0))
        return func_001DD448(D_0038E0A0, v);
    return 0;
}
