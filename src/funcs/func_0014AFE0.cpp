struct G_0014AFE0 {
    int m0;
    unsigned int m4;
    int m8;
    G_0014AFE0* mC;
    G_0014AFE0* m10;
    void* m14;
};

extern G_0014AFE0 D_003CBDC8;
extern char D_0035F390[];

extern "C" void func_0014AFE0(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_003CBDC8.m4 = 0xFFFFFFFF;
        D_003CBDC8.m8 = 0;
        D_003CBDC8.mC = &D_003CBDC8;
        D_003CBDC8.m10 = &D_003CBDC8;
        D_003CBDC8.m14 = D_0035F390;
    }
}
