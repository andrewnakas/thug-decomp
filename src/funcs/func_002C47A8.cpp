extern void* D_003929D0[2];
extern int D_003929D8[2];
extern int D_003929E0;
extern "C" void func_0010D280(void* heap, int flags);

void func_002C47A8() {
    void* h = D_003929D0[D_003929E0];
    if (h) {
        if (D_003929D8[D_003929E0]) {
            func_0010D280(h, 3);
        }
        D_003929D0[D_003929E0] = 0;
    }
}
