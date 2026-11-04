struct Heap_00126E18 {
    char pad[0xE4];
    void* mE4;
};

extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00135D80();
extern Heap_00126E18* D_00388A70;

struct C_00126E18 {
    char pad[0x1AC];
    void** m1AC;
    void** m1B0;
    int m1B4;
    char pad1B8[4];
    int m1BC;
    void Alloc(int n, int keep);
};

void C_00126E18::Alloc(int n, int keep)
{
    if (m1BC) {
        func_0010A950(D_00388A70, D_00388A70->mE4);
        m1B0 = (void**)func_0010A638(D_00388A70, n * 4, 1, 0);
        func_0010A9B0(D_00388A70);
        for (int i = 0; i < n; i++)
            m1B0[i] = func_00135D80();
    }
    if (!keep) {
        m1B4 = n;
        func_0010A950(D_00388A70, D_00388A70->mE4);
        m1AC = (void**)func_0010A638(D_00388A70, n * 4, 1, 0);
        func_0010A9B0(D_00388A70);
        for (int i = 0; i < n; i++)
            m1AC[i] = func_00135D80();
    }
}
