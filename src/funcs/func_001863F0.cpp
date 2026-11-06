extern void* D_0038C608;
extern int D_0038C60C;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00186498(void* mem);

void* func_001863F0(int create)
{
    if (!D_0038C608 && create)
        D_0038C608 = func_00186498(func_00104760(0x454, 0, 1));
    D_0038C60C++;
    return D_0038C608;
}
