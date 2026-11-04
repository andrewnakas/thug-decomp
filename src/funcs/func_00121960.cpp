extern void* D_0038E7C0[2];
extern int D_0038E7D0;
extern void* D_00388A70;
extern "C" void* func_0010D300(void* pool);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

void* func_00121960(int size)
{
    void* pool = D_0038E7C0[D_0038E7D0];
    if (pool)
        return func_0010D300(pool);
    return func_0010A638(D_00388A70, size, 1, 0);
}
