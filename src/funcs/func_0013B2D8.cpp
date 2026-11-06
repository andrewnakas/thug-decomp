extern void* D_004653C0[10];
extern "C" void func_00114B50(void* m);

extern "C" void func_0013B2D8()
{
    for (unsigned int i = 0; i < 10; i++) {
        if (D_004653C0[i])
            func_00114B50(D_004653C0[i]);
    }
}
