extern void* D_00388A70;
extern void* D_0038E5F0[2];
extern int D_0038E5F8[2];
extern int D_0038E600;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* mem, int a, int b, int c);

void func_001E5B40(int a, int b)
{
    void** slot = &D_0038E5F0[D_0038E600];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 8, a, b);
    D_0038E5F8[D_0038E600] = 1;
}
