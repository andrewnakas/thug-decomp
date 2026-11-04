extern unsigned int D_0038EB7C;
extern void* D_0038EB78;
extern "C" void func_001F9D50(void* p, int mode);

void func_001F8380()
{
    if (D_0038EB7C > 1) {
        D_0038EB7C--;
        return;
    }
    if (D_0038EB78) {
        func_001F9D50(D_0038EB78, 3);
    }
    D_0038EB78 = 0;
    D_0038EB7C = 0;
}
