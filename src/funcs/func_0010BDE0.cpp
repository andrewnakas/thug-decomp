extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);

void* Alloc_0010BDE0(int size)
{
    return func_0010A638(D_00388A70, size, 1, 0);
}
