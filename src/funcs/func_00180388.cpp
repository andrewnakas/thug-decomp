extern "C" void* func_0010BDE0(int size);
extern "C" void* func_0010E1E8(const char* name, int* size, void* buf, int max);
extern "C" int func_00180180(void* obj, void* data, int a, int b, int c, int d);

extern "C" void* func_00180388(const char* name, int a, int b, int c, int d, int* size)
{
    void* obj = func_0010BDE0(0x50);
    func_00180180(obj, func_0010E1E8(name, size, 0, 0), a, b, c, d);
    return obj;
}
