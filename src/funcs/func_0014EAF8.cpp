typedef int qword __attribute__((mode(TI)));

struct Vec_0014EAF8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0014EAF8() {}
    Vec_0014EAF8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Rgba_0014EAF8 {
    unsigned char r, g, b, a;
    Rgba_0014EAF8() {}
    Rgba_0014EAF8(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa) { r = ar; g = ag; b = ab; a = aa; }
};

struct Elem_0014EAF8 {
    Vec_0014EAF8 pos;
    Rgba_0014EAF8 col;
    Elem_0014EAF8() {}
};

extern void* D_00388A70;
extern void* D_0038A634;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

struct Cache_0014EAF8 {
    char m0[0x400];
    int m400;
    int m404;
    Elem_0014EAF8 elems[0x300];
    Cache_0014EAF8() {}
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

extern "C" void func_001448B0(void* list);
extern "C" Cache_0014EAF8* func_001448C0(void* list, int a);
extern "C" int func_0010BE08();
extern "C" void* func_003315B8(void* d, int c, int n);
extern "C" void func_00152078(void* list, Cache_0014EAF8** item, Cache_0014EAF8* p);

Cache_0014EAF8* func_0014EAF8(int key)
{
    Cache_0014EAF8* c;
    func_001448B0(D_0038A634);
    for (;;) {
        Cache_0014EAF8* n = func_001448C0(D_0038A634, 0);
        if (!n)
            break;
        c = n;
        if (c->m404 == key)
            return c;
    }
    if (func_0010BE08() <= 0x9617)
        return 0;
    c = new Cache_0014EAF8;
    c->m404 = key;
    c->m400 = 0;
    func_003315B8(c, 0, 0x400);
    for (int i = 0; i < 0x300; i++) {
        Elem_0014EAF8* e = &c->elems[i];
        e->pos = Vec_0014EAF8(0.0f, 0.0f, 0.0f, 1.0f);
        e->col = Rgba_0014EAF8(0x80, 0x80, 0x80, 0x80);
    }
    Cache_0014EAF8* item = c;
    func_00152078(D_0038A634, &item, c);
    return c;
}
