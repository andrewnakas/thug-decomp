extern void* D_00390AD0;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" void* func_00259EF8(void* p);

extern "C" void* func_00259EB8()
{
    if (!D_00390AD0) D_00390AD0 = func_00259EF8(func_0010A638(D_00388A70, 0x260, 1, 0));
    return D_00390AD0;
}
