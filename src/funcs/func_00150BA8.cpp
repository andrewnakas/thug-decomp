typedef int qword __attribute__((mode(TI)));

struct Vec_00150BA8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Vert_00150BA8 {
    Vec_00150BA8 pos;
    int col;
    float u, v;
    int pad;
};

struct Tri_00150BA8 {
    Vert_00150BA8 v[3];
};

struct Cache_00150BA8 {
    char m0[0x400];
    int m400;
    int m404;
    char pad408[8];
    Tri_00150BA8 tris[0x100];
};

extern void* D_0038A634;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;

extern "C" void func_001448B0(void* list);
extern "C" Cache_00150BA8* func_001448C0(void* list, int a);
extern "C" void func_00168C90(float z);
extern "C" void func_00168D58();
extern "C" void func_00168D98(int a, int b, int c, int d);
extern "C" void func_00169A78(Vert_00150BA8* a, Vert_00150BA8* b, Vert_00150BA8* c,
                              float u0, float v0, float u1, float v1, float u2, float v2, int ca, int cb, int cc, int f);

static inline void Tag(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

void func_00150BA8()
{
    func_001448B0(D_0038A634);
    Cache_00150BA8* c = func_001448C0(D_0038A634, 0);
    bool any = c != 0;
    Tag(0x10000000, 0);
    if (any) {
        func_00168C90(24.0f);
    }
    while (c) {
        if (c->m400 >= 0) {
            func_00168D98(c->m404, 0x44, 0, 1);
            Tri_00150BA8* tri = c->tris;
            for (int i = 0; i <= c->m400; i++, tri++) {
                func_00169A78(&tri->v[0], &tri->v[1], &tri->v[2], tri->v[0].u, tri->v[0].v, tri->v[1].u, tri->v[1].v,
                              tri->v[2].u, tri->v[2].v, tri->v[0].col, tri->v[1].col, tri->v[2].col, 0);
            }
        }
        c = func_001448C0(D_0038A634, 0);
    }
    if (any) {
        func_00168D58();
    }
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
}
