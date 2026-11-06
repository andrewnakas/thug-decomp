/* fuzzy: 88.2 */
struct Heap_00174170 {
    char pad[0xDC];
    int mDC;
};

extern Heap_00174170* D_00388A70;
extern volatile int D_003942D4;
extern int D_00393F68;
extern int D_0038BE44;
extern int D_003942D8;
extern int D_00394274;
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" int func_0010BF90(int size, int align);
extern "C" void func_0010BEB8(int p);

static inline int Alloc(int size, int align)
{
    D_00393F68 = D_003942D4;
    return func_0010BF90(size, align);
}

extern "C" void func_00174170(int alloc)
{
    func_0010A950(D_00388A70, D_00388A70->mDC);
    if (alloc) {
        int p = Alloc(0x14996, 0x10);
        D_003942D4 = p;
        D_0038BE44 = p;
        D_003942D8 = 0x14996 * 0x10; /* a byte count (0x14996 qwords), not an address */
    } else if (D_0038BE44) {
        D_003942D4 = D_00393F68;
        func_0010BEB8(D_0038BE44);
        D_0038BE44 = 0;
        D_003942D8 = 0xA4CB0;
    }
    D_00394274 = 0;
    func_0010A9B0(D_00388A70);
}
