extern void* D_00393EB0;
extern "C" void func_0010A3D0(void* lock);
extern "C" void func_0010A3F8(void* lock);
extern "C" void func_0010C330(void* p);

extern "C" void func_0010A8D8(void* heap, void* p)
{
    func_0010A3D0(D_00393EB0);
    if (p) func_0010C330(p);
    func_0010A3F8(D_00393EB0);
}
