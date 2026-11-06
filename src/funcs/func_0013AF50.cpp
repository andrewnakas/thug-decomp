extern int* D_0038A0E4;
extern void* D_004653C0[];

extern "C" void* func_0013AF50(int n)
{
    int count = 0;
    for (unsigned int i = 0; i < 10; i++) {
        int idx = D_0038A0E4[i];
        if (idx >= 0) {
            if (count == n) {
                return D_004653C0[idx];
            }
            count++;
        }
    }
    return 0;
}
