extern void* D_00391E98[2];
extern int D_00391EA0[2];
extern int D_00391EA8;
extern "C" void func_0010D280(void* heap, int flags);

void func_0029C6B0() {
    void* h = D_00391E98[D_00391EA8];
    if (h) {
        if (D_00391EA0[D_00391EA8]) {
            func_0010D280(h, 3);
        }
        D_00391E98[D_00391EA8] = 0;
    }
}
