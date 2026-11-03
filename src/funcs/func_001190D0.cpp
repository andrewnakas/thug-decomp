extern void* D_0038E5F0[2];
extern int D_0038E600;
extern void* D_00388A70;
extern "C" void* func_0010D300(void* pool);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

void* func_001190D0(int size)
{
    void* pool = D_0038E5F0[D_0038E600];
    if (pool)
        return func_0010D300(pool);
    return func_0010A638(D_00388A70, size, 1, 0);
}
