extern int D_0038DF18;
extern void* D_004686C8[];
extern "C" void func_001DA8C0(void* p, int flags);

extern "C" void func_001DADB0(void* p)
{
    for (int i = 0; i < D_0038DF18; i++) {
        if (D_004686C8[i] == p) {
            D_0038DF18--;
            D_004686C8[i] = D_004686C8[D_0038DF18];
            break;
        }
    }
    if (p)
        func_001DA8C0(p, 3);
}
