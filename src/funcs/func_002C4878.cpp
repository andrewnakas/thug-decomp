extern void* D_00392738[2];
extern int D_00392740[2];
extern int D_00392748;
extern "C" void func_0010D280(void* heap, int flags);

void func_002C4878() {
    void* h = D_00392738[D_00392748];
    if (h) {
        if (D_00392740[D_00392748]) {
            func_0010D280(h, 3);
        }
        D_00392738[D_00392748] = 0;
    }
}
