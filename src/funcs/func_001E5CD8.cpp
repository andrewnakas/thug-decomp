extern void* D_0038E630[2];
extern int D_0038E638[2];
extern int D_0038E640;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_001E5CD8(int a, int b)
{
    void** slot = &D_0038E630[D_0038E640];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x10, a, b);
    D_0038E638[D_0038E640] = 1;
}
