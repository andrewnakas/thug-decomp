extern void* D_00388A70;
extern void* D_0038E468[2];
extern int D_0038E470[2];
extern int D_0038E478;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* mem, int a, int b, int c);

void func_001E5D60(int a, int b)
{
    void** slot = &D_0038E468[D_0038E478];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x14, a, b);
    D_0038E470[D_0038E478] = 1;
}
