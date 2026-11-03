extern void* D_0038E630[2];
extern int D_0038E640;
extern void* D_00388A70;
extern "C" void* func_0010D300(void* pool);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

void* func_00122CF8(int size)
{
    void* pool = D_0038E630[D_0038E640];
    if (pool)
        return func_0010D300(pool);
    return func_0010A638(D_00388A70, size, 1, 0);
}
