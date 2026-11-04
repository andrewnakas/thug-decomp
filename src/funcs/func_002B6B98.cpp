extern void* D_00392588[2];
extern int D_00392590[2];
extern int D_00392598;
extern "C" void func_0010D280(void* heap, int flags);

void func_002B6B98() {
    void* h = D_00392588[D_00392598];
    if (h) {
        if (D_00392590[D_00392598]) {
            func_0010D280(h, 3);
        }
        D_00392588[D_00392598] = 0;
    }
}
