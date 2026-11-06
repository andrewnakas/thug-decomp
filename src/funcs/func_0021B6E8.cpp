extern void* D_0038FC78;
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" void* func_0022E050(void* a);
extern "C" int func_002630E8(void* a, int v);

extern "C" int func_0021B6E8(void* params)
{
    int v;
    func_001E8398(params, 0xA1DC81F9, &v, 1);
    return func_002630E8(func_0022E050(D_0038FC78), v);
}
