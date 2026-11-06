extern void* D_00388A70;
extern void* D_00388C28[2];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" int func_0010D490(int i);
extern "C" void* func_0010D300(void* pool);

extern "C" void* func_0010D3C8(int i)
{
    if (D_00388C28[i]) return func_0010D300(D_00388C28[i]);
    return func_0010A638(D_00388A70, func_0010D490(i), 1, 0);
}
