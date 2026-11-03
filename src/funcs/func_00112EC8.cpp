extern unsigned int D_00388F00;
extern void* D_00388EFC;
extern "C" void func_00112F88(void* p, int mode);

void func_00112EC8()
{
    if (D_00388F00 > 1) {
        D_00388F00--;
        return;
    }
    if (D_00388EFC) {
        func_00112F88(D_00388EFC, 3);
    }
    D_00388EFC = 0;
    D_00388F00 = 0;
}
