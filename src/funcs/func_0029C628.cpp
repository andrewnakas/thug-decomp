extern void* D_00388A70;
extern void* D_00391EB0[2];
extern int D_00391EB8[2];
extern int D_00391EC0;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

extern "C" void func_0029C628(int a, int b)
{
    void** slot = &D_00391EB0[D_00391EC0];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x14, a, b);
    D_00391EB8[D_00391EC0] = 1;
}
