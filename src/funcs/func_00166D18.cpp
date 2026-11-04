struct Heap_00166D18 {
    char pad0[0xD8];
    void* mD8;
};

struct File_00166D18 {
    char pad0[0xC];
    void* mC;
};

struct Tex_00166D18;

extern Heap_00166D18* D_00388A70;
extern File_00166D18* D_0035997C[];
extern char D_00360CC8[];
extern void* D_00393F38;
extern int D_0038B988;

extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" int func_00332798(void* f, const char* fmt);
extern "C" void func_001657F0(Tex_00166D18* t, int* w, int* h, int fmt);
extern "C" int func_00165890(Tex_00166D18* t, int w, int h, int fmt);
extern "C" void func_00165CB0(int a, int b, int c, int d, int w, int h, int e);
extern "C" void func_00165AF8(int a, int b, int c, int d, int w, int h, int e);
extern "C" int func_00166CB8(Tex_00166D18* t, int w, int h);

static inline int SizeLog(int s)
{
    int i;
    for (i = 0; i < 11; i++) {
        if (s == (0x400 >> i)) break;
    }
    return i;
}

extern "C" int func_00166D18(Tex_00166D18* t, int w, int h, int a, int b)
{
    if (SizeLog(w) == 11 || SizeLog(h) == 11) {
        func_00332798(D_0035997C[0]->mC, D_00360CC8);
        return 0;
    }
    int w0 = w;
    int h0 = h;
    int w1 = w / 2;
    int h1 = h / 2;
    func_001657F0(t, &w0, &h0, 0x14);
    func_001657F0(t, &w1, &h1, 2);
    int n;
    if (func_00165890(t, w0, h0, 0x14) < func_00165890(t, w1, h1, 2)) {
        n = func_00165890(t, w1, h1, 2);
    } else {
        n = func_00165890(t, w0, h0, 0x14);
    }
    int sz = n << 6;
    func_0010A950(D_00388A70, D_00388A70->mD8);
    D_00393F38 = func_0010A638(D_00388A70, n << 8, 1, 0);
    D_0038B988 = sz;
    func_0010A9B0(D_00388A70);
    func_00165CB0(0, (w / 128 > 0 ? w / 128 : 1) * 2, 0, 0, w, h, a);
    func_00165AF8(0, (w / 256 > 0 ? w / 256 : 1) * 2, 0, 0, w / 2, h / 2, b);
    if (D_00393F38) {
        func_0010A8D8(D_00388A70, D_00393F38);
    }
    D_00393F38 = 0;
    D_0038B988 = 0;
    return func_00166CB8(t, w, h);
}
