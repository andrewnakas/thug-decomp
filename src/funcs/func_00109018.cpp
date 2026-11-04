extern unsigned int D_00388A48;
extern void* D_00388A44;
extern "C" void func_00108808(void* p, int mode);

void func_00109018()
{
    if (D_00388A48 > 1) {
        D_00388A48--;
        return;
    }
    if (D_00388A44) {
        func_00108808(D_00388A44, 3);
    }
    D_00388A44 = 0;
    D_00388A48 = 0;
}
