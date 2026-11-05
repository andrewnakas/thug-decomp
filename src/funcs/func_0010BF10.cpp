extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void* func_003314B4(void* dst, const void* src, int n);

extern "C" void* func_0010BF10(void* old, int size)
{
    void* p = 0;
    if (size) {
        p = func_0010A638(D_00388A70, size, 1, 0);
    }
    if (old) {
        if (p) {
            func_003314B4(p, old, size);
        }
        func_0010A8D8(D_00388A70, old);
    }
    return p;
}
