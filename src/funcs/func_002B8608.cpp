typedef int qword __attribute__((mode(TI)));

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Vec_002B8608 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_002B8608() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Rgba_002B8608 {
    unsigned char r, g, b, a;
    Rgba_002B8608() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct PackedVert_002B8608 {
    unsigned short x, y, z;
};

struct FloatVert_002B8608 {
    float x, y, z;
};

struct Geo_002B8608 {
    char pad0[6];
    unsigned short m6;
    char pad8[3];
    unsigned char mB;
    char padC[4];
    Vec_002B8608 m10;
    char pad20[0x10];
    void* m30;
    char pad34[4];
    unsigned char* m38;
};

struct Src_002B8608 {
    int m0;
    char pad4[0x10];
    int m14;
};

extern "C" void* func_001317D0(int id);
extern "C" void* func_00134F18(void* p);
extern "C" int func_002B6E90(int id);
extern "C" int func_0013C7E0(void* g);
extern "C" void func_0013C808(void* g, Vec_002B8608* v);
extern "C" void func_0013C830(void* g, Rgba_002B8608* c);
extern "C" void func_0013C958(void* g, Rgba_002B8608* c);
extern "C" Geo_002B8608* func_0013C710(void* g);

static inline Vec_002B8608 GetVert_002B8608(Geo_002B8608* g, int i)
{
    if (g->mB) {
        Vec_002B8608 p;
        p = g->m10;
        p.x += ((PackedVert_002B8608*)g->m30)[i].x * 0.0625f;
        p.y += ((PackedVert_002B8608*)g->m30)[i].y * 0.0625f;
        p.z += ((PackedVert_002B8608*)g->m30)[i].z * 0.0625f;
        p.w = 0.0f;
        return p;
    } else {
        Vec_002B8608 p;
        p.x = ((FloatVert_002B8608*)g->m30)[i].x;
        p.y = ((FloatVert_002B8608*)g->m30)[i].y;
        p.z = ((FloatVert_002B8608*)g->m30)[i].z;
        p.w = 0.0f;
        return p;
    }
}

struct Obj_002B8608 {
    void Apply(Src_002B8608* s);
};

extern "C" void func_002B8930(Obj_002B8608* o, Vec_002B8608* p, Rgba_002B8608* c);

void Obj_002B8608::Apply(Src_002B8608* s)
{
    void* src = func_00134F18(func_001317D0(s->m0));
    void* dst = func_00134F18(func_001317D0(func_002B6E90(s->m14)));
    int n = func_0013C7E0(src);
    if (n) {
        Vec_002B8608* pos = new Vec_002B8608[n];
        Rgba_002B8608* col = new Rgba_002B8608[n];
        Rgba_002B8608* c = col;
        func_0013C808(src, pos);
        func_0013C830(dst, col);
        Vec_002B8608* p = pos;
        for (int i = 0; i < n; i++) {
            func_002B8930(this, p, c);
            c++;
            p++;
        }
        func_0013C958(src, col);
        delete[] pos;
        delete[] col;
    }
    Geo_002B8608* g = func_0013C710(src);
    Geo_002B8608* h = func_0013C710(dst);
    n = g->m6;
    for (int i = 0; i < n; i++) {
        Rgba_002B8608 c;
        unsigned char v = h->m38[i];
        c.a = 0xFF;
        c.r = v;
        c.g = v;
        c.b = v;
        Vec_002B8608 p = GetVert_002B8608(g, i);
        func_002B8930(this, &p, &c);
        g->m38[i] = (c.r + c.g + c.b) / 3;
    }
}
