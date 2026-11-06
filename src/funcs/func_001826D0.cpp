extern void* D_0038C308;
extern int D_0038C30C;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00182768(void* mem);

void* func_001826D0(int create)
{
    if (!D_0038C308 && create)
        D_0038C308 = func_00182768(func_00104760(0x100, 0, 1));
    D_0038C30C++;
    return D_0038C308;
}
