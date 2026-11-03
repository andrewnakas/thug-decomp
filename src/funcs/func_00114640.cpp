extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_001147D0(void* p);
extern void* D_00389044;
extern int D_00389048;

void* func_00114640(int create)
{
    if (!D_00389044 && create) {
        D_00389044 = func_001147D0(func_00104760(0x24, 0, 1));
    }
    D_00389048++;
    return D_00389044;
}
