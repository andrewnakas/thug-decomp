extern void* D_0038FC78;
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void func_0022DC98(void* a, int v, int b);

extern "C" int func_0021EC68(void* params)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    func_0022DC98(D_0038FC78, v, 1);
    return 1;
}
