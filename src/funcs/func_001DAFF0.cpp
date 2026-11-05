struct G_001DAFF0 {
    int m0;
    unsigned int m4;
    int m8;
    G_001DAFF0* mC;
    G_001DAFF0* m10;
    void* m14;
};

extern G_001DAFF0 D_003E82E0;
extern char D_00363EC0[];

extern "C" void func_001DAFF0(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_003E82E0.m4 = 0xFFFFFFFF;
        D_003E82E0.m8 = 0;
        D_003E82E0.mC = &D_003E82E0;
        D_003E82E0.m10 = &D_003E82E0;
        D_003E82E0.m14 = D_00363EC0;
    }
}
