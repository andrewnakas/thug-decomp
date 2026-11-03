extern void* D_003929B8[2];
extern int D_003929C0[2];
extern int D_003929C8;
extern "C" void func_0010D280(void* heap, int flags);

void func_002C4810() {
    void* h = D_003929B8[D_003929C8];
    if (h) {
        if (D_003929C0[D_003929C8]) {
            func_0010D280(h, 3);
        }
        D_003929B8[D_003929C8] = 0;
    }
}
