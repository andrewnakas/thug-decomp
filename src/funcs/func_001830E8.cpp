extern unsigned int D_0038C3C4;
extern void* D_0038C3C0;
extern "C" void func_00183208(void* p, int mode);

void func_001830E8()
{
    if (D_0038C3C4 > 1) {
        D_0038C3C4--;
        return;
    }
    if (D_0038C3C0) {
        func_00183208(D_0038C3C0, 3);
    }
    D_0038C3C0 = 0;
    D_0038C3C4 = 0;
}
