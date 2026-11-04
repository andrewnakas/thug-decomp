extern void* D_0038E6C8[2];
extern int D_0038E6D8;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0010D300(void* heap, unsigned int size);

void* func_001EE120(unsigned int size) {
    void* h = D_0038E6C8[D_0038E6D8];
    if (h) {
        return func_0010D300(h, size);
    }
    return func_0010A638(D_00388A70, size, 1, 0);
}
