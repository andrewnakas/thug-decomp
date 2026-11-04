extern "C" void func_002BC970(void* obj, int flags);
extern void* D_0039274C;
extern unsigned int D_00392750;

extern "C" void func_002BA9E0() {
    if (D_00392750 >= 2) {
        D_00392750 = D_00392750 - 1;
    } else {
        if (D_0039274C) {
            func_002BC970(D_0039274C, 3);
        }
        D_0039274C = 0;
        D_00392750 = 0;
    }
}
