extern void* D_0038E3A8[2];
extern int D_0038E3B8;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0010D300(void* heap, unsigned int size);

void* func_001E8C80(unsigned int size) {
    void* h = D_0038E3A8[D_0038E3B8];
    if (h) {
        return func_0010D300(h, size);
    }
    return func_0010A638(D_00388A70, size, 1, 0);
}
