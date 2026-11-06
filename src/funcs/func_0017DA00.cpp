extern void* D_003942CC;
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" void func_0017D6D8(void* data, int size, void* obj, int a, int b, int c, int d);

extern "C" void* func_0017DA00(void* data, int size, void* obj, int a, int b, int c, int d)
{
    func_00331404(D_003942CC, data, size);
    func_0017D6D8(data, size, obj, a, b, c, d);
    return obj;
}
