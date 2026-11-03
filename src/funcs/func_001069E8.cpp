extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00106D10(void* p);
extern void* D_00388948;
extern int D_0038894C;

void* func_001069E8(int create)
{
    if (!D_00388948 && create) {
        D_00388948 = func_00106D10(func_00104760(0x24, 0, 1));
    }
    D_0038894C++;
    return D_00388948;
}
