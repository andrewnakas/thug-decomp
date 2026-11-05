extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00149AE8(void* mem, int a, int b, int c, int d, int e);
extern void* D_00388A70;

extern "C" void* func_00149FA8(int a, int b, int c, int d, int e)
{
    return func_00149AE8(func_0010A638(D_00388A70, 0x18, 1, 0), a, b, c, d, e);
}
