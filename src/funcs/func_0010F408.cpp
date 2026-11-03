struct Heap_0010F408 {
    char pad[0x110];
    void* m110;
    void* m114;
};

struct Ent_0010F408 {
    int offset;
    int size;
    int m8;
    int mC;
};

struct Arc_0010F408 {
    int m0;
    void* m4;
    void* m8;
    char* mC;
    int count;
    int m14;
    Ent_0010F408 ents[128];
    char* data[128];
    int mA18;
};

extern Heap_0010F408* D_00388A70;
extern "C" void func_0010ECF8(void* p);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" char* func_0010BDE0(int size);
extern "C" int func_0010BEE8(void* p);
extern "C" void* func_0010BE88(int size, void* p);
extern "C" void func_0010BEB8(void* p);

extern "C" int func_0010F408(Arc_0010F408* a, int unused, int size)
{
    if (a->m4) {
        func_0010ECF8(a->m4);
        a->m4 = 0;
    }
    char* p = a->mC;
    int* hdr = (int*)p;
    p += 8;
    if (a->mC + size < p) {
        return 0;
    }
    a->count = hdr[1];
    func_00331404(a->ents, p, a->count << 4);
    p += a->count << 4;
    if (a->mC + size < p) {
        return 0;
    }
    for (int i = 0; i < a->count; i++) {
        a->data[i] = a->mC + a->ents[i].offset;
    }
    for (int i = a->count - 1; i >= 0; i--) {
        int sz = a->ents[i].size;
        char* src = a->data[i];
        func_0010A950(D_00388A70, D_00388A70->m110);
        a->data[i] = func_0010BDE0(sz);
        func_00331404(a->data[i], src, sz);
        func_0010A9B0(D_00388A70);
        func_0010A950(D_00388A70, D_00388A70->m114);
        a->m8 = func_0010BE88(func_0010BEE8(a->m8) - sz, a->m8);
        func_0010A9B0(D_00388A70);
    }
    func_0010BEB8(a->m8);
    a->m8 = 0;
    a->mC = 0;
    a->mA18 = 1;
    return 1;
}
