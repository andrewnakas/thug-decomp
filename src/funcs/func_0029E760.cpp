extern "C" void func_0029F318(void* obj, int flags);
extern void* D_00392068;
extern unsigned int D_0039206C;

extern "C" void func_0029E760() {
    if (D_0039206C >= 2) {
        D_0039206C = D_0039206C - 1;
    } else {
        if (D_00392068) {
            func_0029F318(D_00392068, 3);
        }
        D_00392068 = 0;
        D_0039206C = 0;
    }
}
