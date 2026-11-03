extern void* D_00392570[2];
extern int D_00392578[2];
extern int D_00392580;
extern "C" void func_0010D280(void* heap, int flags);

void func_002B6AB8() {
    void* h = D_00392570[D_00392580];
    if (h) {
        if (D_00392578[D_00392580]) {
            func_0010D280(h, 3);
        }
        D_00392570[D_00392580] = 0;
    }
}
