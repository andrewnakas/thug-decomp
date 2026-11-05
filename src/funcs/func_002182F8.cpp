extern char D_0038F590[];
extern "C" int func_001E84E8(void* params, void* name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void* func_00141250(int id);

bool func_002182F8(void* params)
{
    int v = 0;
    if (!func_001E84E8(params, D_0038F590, &v, 0))
        func_001E8398(params, 0, &v, 1);
    return func_00141250(v) != 0;
}
