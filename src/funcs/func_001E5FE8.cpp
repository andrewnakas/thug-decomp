extern void* D_0038E430[2];
extern int D_0038E438[2];
extern int D_0038E440;
extern "C" void func_0010D280(void* heap, int flags);

void func_001E5FE8() {
    void* h = D_0038E430[D_0038E440];
    if (h) {
        if (D_0038E438[D_0038E440]) {
            func_0010D280(h, 3);
        }
        D_0038E430[D_0038E440] = 0;
    }
}
