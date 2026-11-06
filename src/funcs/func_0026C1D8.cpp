extern void* D_00391360;
extern void* D_00388A70;
extern "C" void func_0026C228();
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" void* func_0026C7D0(void* p, int n);

void Init_0026C1D8()
{
    if (D_00391360) {
        func_0026C228();
        return;
    }
    D_00391360 = func_0026C7D0(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
}
