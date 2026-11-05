extern void* D_0038FC78;
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void* func_0022E050(void* mgr);
extern "C" void func_002628E8(void* p, int v);

bool func_0021B628(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    func_002628E8(func_0022E050(D_0038FC78), v);
    return true;
}
