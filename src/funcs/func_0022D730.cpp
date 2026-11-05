extern char D_0038FCB0[];
extern void* D_0038FC78;
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" void func_0022D728(void* a, int v);

extern "C" int func_0022D730(void* params)
{
    int v = 0x78;
    func_001E7E58(params, D_0038FCB0, &v, 0);
    func_0022D728(D_0038FC78, v);
    return 1;
}
