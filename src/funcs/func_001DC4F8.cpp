extern unsigned int D_0038E0A4;
extern void* D_0038E0A0;
extern "C" void func_001DC758(void* p, int mode);

void func_001DC4F8()
{
    if (D_0038E0A4 > 1) {
        D_0038E0A4--;
        return;
    }
    if (D_0038E0A0) {
        func_001DC758(D_0038E0A0, 3);
    }
    D_0038E0A0 = 0;
    D_0038E0A4 = 0;
}
