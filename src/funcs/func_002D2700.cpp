extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_00304190();
extern "C" void func_0010A9B0(void* heap);

struct Heap_002D2700 {
    char pad0[0x108];
    int m108;
};

extern Heap_002D2700* D_00388A70;

void func_002D2700() {
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_00304190();
    func_0010A9B0(D_00388A70);
}
