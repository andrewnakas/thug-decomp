extern void* D_00391EB0[2];
extern int D_00391EB8[2];
extern int D_00391EC0;
extern "C" void func_0010D280(void* heap, int flags);

void func_0029C718() {
    void* h = D_00391EB0[D_00391EC0];
    if (h) {
        if (D_00391EB8[D_00391EC0]) {
            func_0010D280(h, 3);
        }
        D_00391EB0[D_00391EC0] = 0;
    }
}
