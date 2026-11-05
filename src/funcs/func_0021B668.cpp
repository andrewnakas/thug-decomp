extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E050(void* g);
extern "C" int func_002628F0(void* p);

extern "C" bool func_0021B668(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    return func_002628F0(func_0022E050(D_0038FC78)) == v;
}
