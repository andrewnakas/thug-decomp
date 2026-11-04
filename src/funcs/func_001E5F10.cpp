extern void* D_0038E5F0[2];
extern int D_0038E5F8[2];
extern int D_0038E600;
extern "C" void func_0010D280(void* heap, int flags);

void func_001E5F10() {
    void* h = D_0038E5F0[D_0038E600];
    if (h) {
        if (D_0038E5F8[D_0038E600]) {
            func_0010D280(h, 3);
        }
        D_0038E5F0[D_0038E600] = 0;
    }
}
