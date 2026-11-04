extern void* D_00392738[2];
extern int D_00392740[2];
extern int D_00392748;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_002C4580(int a, int b)
{
    void** slot = &D_00392738[D_00392748];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x10, a, b);
    D_00392740[D_00392748] = 1;
}
