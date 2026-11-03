struct Heap_001220E8 {
    char pad[0xDC];
    void* mDC;
};

struct Rgba_001220E8 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_001220E8(const Rgba_001220E8& o) { v = o.v; }
};

extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_00138760(void* o, int a, int b);
extern "C" void func_001221B8(void* o, int a, int b, Rgba_001220E8 c);
extern "C" void func_00122618(void* o, int a);
extern "C" void func_00138970(void* o, int a, int b);
extern "C" void func_00138788(void* o, int a);

extern Heap_001220E8* D_00388A70;
extern int D_003895E8;

int func_001220E8(void* o, int a1, int a2, int a3, Rgba_001220E8 c)
{
    func_0010A950(D_00388A70, D_00388A70->mDC);
    func_00138760(o, 0, 0);
    func_0010A9B0(D_00388A70);
    func_001221B8(o, a1, a3, c);
    func_00122618(o, a1);
    if (D_003895E8)
        func_00138970(o, D_003895E8, a2);
    func_00138788(o, a2);
    return 1;
}
