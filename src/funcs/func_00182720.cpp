extern unsigned int D_0038C30C;
extern void* D_0038C308;
extern "C" void func_001827B0(void* p, int mode);

void func_00182720()
{
    if (D_0038C30C > 1) {
        D_0038C30C--;
        return;
    }
    if (D_0038C308) {
        func_001827B0(D_0038C308, 3);
    }
    D_0038C308 = 0;
    D_0038C30C = 0;
}
