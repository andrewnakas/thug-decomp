extern void* D_0038FC78;
extern "C" int func_001E8A30(void* params, unsigned int name, int* out, int req);
extern "C" void* func_0022E358(void* a);
extern "C" int func_0024F938(void* a);

extern "C" bool func_0022EFE0(void* params)
{
    int v;
    func_001E8A30(params, 0, &v, 1);
    return v == func_0024F938(func_0022E358(D_0038FC78));
}
