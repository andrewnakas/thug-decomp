extern void* D_003929D0[2];
extern int D_003929E0;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0010D300(void* heap, unsigned int size);

void* func_002CBBF0(unsigned int size) {
    void* h = D_003929D0[D_003929E0];
    if (h) {
        return func_0010D300(h, size);
    }
    return func_0010A638(D_00388A70, size, 1, 0);
}
