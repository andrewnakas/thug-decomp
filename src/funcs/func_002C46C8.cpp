extern void* D_003929D0[2];
extern int D_003929D8[2];
extern int D_003929E0;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_002C46C8(int a, int b)
{
    void** slot = &D_003929D0[D_003929E0];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x18, a, b);
    D_003929D8[D_003929E0] = 1;
}
