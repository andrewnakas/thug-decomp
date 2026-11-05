extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" void func_00180180(void* obj, void* data, int a, int b, int c, int d);

extern "C" void* func_00180430(const void* src, int size, int a, int b, int c, int d)
{
    void* obj = func_0010BDE0(0x50);
    void* data = func_0010BDE0(size);
    func_00331404(data, src, size);
    func_00180180(obj, data, a, b, c, d);
    return obj;
}
