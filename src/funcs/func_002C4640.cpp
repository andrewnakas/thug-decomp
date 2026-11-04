extern void* D_003929B8[2];
extern int D_003929C0[2];
extern int D_003929C8;
extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, int b);

void func_002C4640(int a, int b)
{
    void** slot = &D_003929B8[D_003929C8];
    *slot = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x1C, a, b);
    D_003929C0[D_003929C8] = 1;
}
