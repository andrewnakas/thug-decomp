extern void* D_0038E430[2];
extern int D_0038E438[2];
extern int D_0038E440;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_001E5AB8(int a, int b)
{
    void** slot = &D_0038E430[D_0038E440];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x10, a, b);
    D_0038E438[D_0038E440] = 1;
}
