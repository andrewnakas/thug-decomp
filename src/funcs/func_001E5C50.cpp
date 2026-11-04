extern void* D_00388A70;
extern void* D_0038E3C0[2];
extern int D_0038E3C8[2];
extern int D_0038E3D0;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* mem, int a, int b, int c);

void func_001E5C50(int a, int b)
{
    void** slot = &D_0038E3C0[D_0038E3D0];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0xC, a, b);
    D_0038E3C8[D_0038E3D0] = 1;
}
