extern "C" int func_001E88D8(void* params, unsigned int id, int* out, int req);
extern "C" void* func_0021B380(int v, void* params);
extern "C" void func_00263C48(void* p, int v);

bool func_0021F718(void* params, void* script)
{
    int v;
    func_001E88D8(params, 0x2E0B1465, &v, 1);
    func_00263C48(func_0021B380(v, params), v);
    return true;
}
