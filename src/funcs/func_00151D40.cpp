typedef int qword __attribute__((mode(TI)));

struct Vec_00151D40 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Vert_00151D40 {
    Vec_00151D40 pos;
    int col;
    float u, v;
    int pad;
};

struct Tri_00151D40 {
    Vert_00151D40 v[3];
};

struct Stat_00151D40 {
    char pad[0x40];
    int count;
};

struct Mesh_00151D40 {
    char pad[0x44];
    Stat_00151D40* stat;
};

struct Ctx_00151D40 {
    char pad[0xC];
    unsigned int flags;
    char pad10[0x28 - 0x10];
    int used[1];
};

struct Mat_00151D40;

extern "C" Ctx_00151D40* func_00170728(Mesh_00151D40* m);
extern "C" void func_001617A0(Ctx_00151D40* c);
extern "C" void func_00323298(Vec_00151D40* out, Mat_00151D40* m, Vec_00151D40* v);
extern "C" void func_00168BE8(int a);
extern "C" void func_00168E88(int a, int b, int c, int d);
extern "C" void func_00168D98(int a, int b, int c, int d);
extern "C" void func_00169A78(Vert_00151D40* a, Vert_00151D40* b, Vert_00151D40* c,
                              float u0, float v0, float u1, float v1, float u2, float v2, int ca, int cb, int cc, int f);
extern "C" void func_00169608(Vert_00151D40* a, Vert_00151D40* b, Vert_00151D40* c, int ca, int cb, int cc, int f);

extern Ctx_00151D40* D_0039427C;
extern int D_00394094;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern Mat_00151D40 D_003E1080;

static inline void Tag(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

class C_00151D40 {
public:
    char pad[0x20];
    int m20;
    int m24;
    Mesh_00151D40* m28;
    Tri_00151D40* m2C;
    int m30;
    int m34;
    void Draw();
};

void C_00151D40::Draw()
{
    if (!m20) return;
    bool tex = m30 != 0;
    if (tex) {
        Ctx_00151D40* c = func_00170728(m28);
        if (D_0039427C != c) {
            func_001617A0(c);
        }
        c->used[D_00394094] = 1;
        m28->stat->count++;
    }
    Vec_00151D40 t = m2C->v[0].pos;
    func_00323298(&t, &D_003E1080, &t);
    t.z = -1000.0f;
    Tag(0x10000000, *(unsigned int*)&t.z);
    Add((unsigned short)D_00394280 | 0x3000000);
    Add(0x2000000);
    unsigned int saved = D_00394280;
    D_00394280 = 0;
    if (tex) {
        func_00168BE8(1);
        func_00168E88(m30, m34, 1, 0);
    } else {
        func_00168D98(0, 0x44, 1, 0);
    }
    Tri_00151D40* tri = m2C;
    for (int i = 0; i < m20; i++, tri++) {
        if (tex) {
            func_00169A78(&tri->v[0], &tri->v[1], &tri->v[2], tri->v[0].u, tri->v[0].v, tri->v[1].u, tri->v[1].v,
                          tri->v[2].u, tri->v[2].v, tri->v[0].col, tri->v[1].col, tri->v[2].col, 1);
        } else {
            func_00169608(&tri->v[0], &tri->v[1], &tri->v[2], tri->v[0].col, tri->v[1].col, tri->v[2].col, 1);
        }
    }
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
    ((unsigned short*)D_00394278)[1] |= D_00394280 & 0x3FF;
    D_00394280 += saved;
    if (func_00170728(m28)->flags & 4) {
        Tag(0x10000000, 0);
        Add(0);
        Add(0);
        if (D_0039427C) {
            func_001617A0(0);
        }
    }
}
