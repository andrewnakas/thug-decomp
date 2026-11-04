struct Rgba_00160D18 {
    unsigned char r, g, b, a;
};

struct Quant_00160D18 {
    int m0, m4, m8, mC;
};

struct Heap_00160D18 {
    char pad0[0xD8];
    void* mD8;
};

extern Heap_00160D18* D_00388A70;
extern "C" void func_0010A950(Heap_00160D18* heap, void* ctx);
extern "C" void func_0010A9B0(Heap_00160D18* heap);
extern "C" int func_00160B80(Quant_00160D18* q);
extern "C" void func_0015FA80(Quant_00160D18* q, Rgba_00160D18* cols, int w, int h, int bits, float weight);
extern "C" void func_001608D8(Rgba_00160D18* pal, int n, Quant_00160D18* q);
extern "C" void func_00160CC8(Quant_00160D18* q);

extern "C" void func_00160D18(Rgba_00160D18* pal, Rgba_00160D18* cols, int w, int h, int bits, int n)
{
    func_0010A950(D_00388A70, D_00388A70->mD8);
    Quant_00160D18 q;
    if (!func_00160B80(&q))
        return;
    func_0015FA80(&q, cols, w, h, bits, 1.0f);
    func_001608D8(pal, n, &q);
    for (int i = 0; i < 0x100; i += 0x20) {
        for (int j = 0; j < 8; j++) {
            Rgba_00160D18 t = pal[i + j + 8];
            pal[i + j + 8] = pal[i + j + 16];
            pal[i + j + 16] = t;
        }
    }
    func_00160CC8(&q);
    func_0010A9B0(D_00388A70);
}
