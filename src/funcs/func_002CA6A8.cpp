extern void* D_00392808;
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" void func_002C70C8(void* p, int v);

extern "C" bool func_002CA6A8(void* params)
{
    int v = 0;
    func_001E8398(params, 0x4C72ED98, &v, 0);
    func_002C70C8(D_00392808, v);
    return true;
}
