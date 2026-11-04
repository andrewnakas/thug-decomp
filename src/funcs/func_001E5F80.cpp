extern void* D_0038E3A8[2];
extern int D_0038E3B0[2];
extern int D_0038E3B8;
extern "C" void func_0010D280(void* heap, int flags);

void func_001E5F80() {
    void* h = D_0038E3A8[D_0038E3B8];
    if (h) {
        if (D_0038E3B0[D_0038E3B8]) {
            func_0010D280(h, 3);
        }
        D_0038E3A8[D_0038E3B8] = 0;
    }
}
