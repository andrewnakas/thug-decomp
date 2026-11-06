extern void* D_00388A30;
extern int D_00388A34;
extern "C" int func_00108960(void* mgr, int a);

extern "C" int func_001092E8(int a)
{
    if (func_00108960(D_00388A30, a)) {
        D_00388A34 = 1;
        return 1;
    }
    D_00388A34 = 0;
    return 0;
}
