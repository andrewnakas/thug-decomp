extern unsigned int D_00389048;
extern void* D_00389044;
extern "C" void func_001148B8(void* p, int mode);

void func_00114690()
{
    if (D_00389048 > 1) {
        D_00389048--;
        return;
    }
    if (D_00389044) {
        func_001148B8(D_00389044, 3);
    }
    D_00389044 = 0;
    D_00389048 = 0;
}
