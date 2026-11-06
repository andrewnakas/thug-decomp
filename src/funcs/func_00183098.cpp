extern void* D_0038C3C0;
extern int D_0038C3C4;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00183130(void* mem);

void* func_00183098(int create)
{
    if (!D_0038C3C0 && create)
        D_0038C3C0 = func_00183130(func_00104760(0x134, 0, 1));
    D_0038C3C4++;
    return D_0038C3C0;
}
