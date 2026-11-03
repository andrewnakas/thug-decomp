extern "C" void* func_00104760(unsigned int size, int a, int b);
extern "C" void* func_0029E7A8(void* mem);
extern void* D_00392068;
extern unsigned int D_0039206C;

extern "C" void* func_0029E710(int create) {
    if (!D_00392068 && create) {
        D_00392068 = func_0029E7A8(func_00104760(0x115C0, 0, 1));
    }
    D_0039206C = D_0039206C + 1;
    return D_00392068;
}
