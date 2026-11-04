extern unsigned int D_0038DB3C;
extern void* D_0038DB38;
extern "C" void func_001CFF40(void* p, int mode);

void func_001CFE88()
{
    if (D_0038DB3C > 1) {
        D_0038DB3C--;
        return;
    }
    if (D_0038DB38) {
        func_001CFF40(D_0038DB38, 3);
    }
    D_0038DB38 = 0;
    D_0038DB3C = 0;
}
