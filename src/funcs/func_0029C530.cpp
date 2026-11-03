extern void* D_00391EB0[2];
extern int D_00391EC0;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0010D300(void* heap, unsigned int size);

void* func_0029C530(unsigned int size) {
    void* h = D_00391EB0[D_00391EC0];
    if (h) {
        return func_0010D300(h, size);
    }
    return func_0010A638(D_00388A70, size, 1, 0);
}
