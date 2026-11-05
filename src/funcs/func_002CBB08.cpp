extern void* D_00392808;
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" void func_002C6FE8(void* p, int v);

extern "C" bool func_002CBB08(void* params)
{
    int v;
    func_001E7DE8(params, 0, &v, 1);
    func_002C6FE8(D_00392808, v);
    return true;
}
