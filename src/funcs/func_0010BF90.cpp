extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);

void* Alloc_0010BF90(int n, int size)
{
    return func_0010A638(D_00388A70, n * size, 1, 0);
}
