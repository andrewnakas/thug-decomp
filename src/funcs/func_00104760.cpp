extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_003315B8(void* p, int c, int n);

extern "C" void* func_00104760(int size, int b, int a)
{
    void* p = func_0010A638(D_00388A70, size, a, b);
    if (p) func_003315B8(p, 0, size);
    return p;
}
