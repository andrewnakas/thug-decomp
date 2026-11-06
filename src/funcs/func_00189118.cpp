extern void* D_0038C7B0;
extern int D_0038C7B4;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00189440(void* mem);

void* func_00189118(int create)
{
    if (!D_0038C7B0 && create)
        D_0038C7B0 = func_00189440(func_00104760(0xB220, 0, 1));
    D_0038C7B4++;
    return D_0038C7B0;
}
