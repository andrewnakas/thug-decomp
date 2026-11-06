extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_0010F1C0(void* p);
extern void* D_00388CA4;
extern int D_00388CA8;

extern "C" void* func_0010F118(int create)
{
    if (!D_00388CA4 && create) {
        D_00388CA4 = func_0010F1C0(func_00104760(0x1C, 0, 1));
    }
    D_00388CA8++;
    return D_00388CA4;
}
