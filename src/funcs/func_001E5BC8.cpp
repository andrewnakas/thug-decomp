extern void* D_0038E3A8[2];
extern int D_0038E3B0[2];
extern int D_0038E3B8;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_001E5BC8(int a, int b)
{
    void** slot = &D_0038E3A8[D_0038E3B8];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x10, a, b);
    D_0038E3B0[D_0038E3B8] = 1;
}
