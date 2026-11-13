/* cflags: -fno-strength-reduce */
/* fuzzy: 50.0 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00151A68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00151A68;
extern "C" Vec_00151A68 func_001522A8(Mat_00151A68* m, Vec_00151A68* v);

struct Mat_00151A68 {
    Vec_00151A68 r[4];
    Vec_00151A68 Xform(Vec_00151A68* v) { return func_001522A8(this, v); }
};

struct Vert_00151A68 {
    float x, y, z;
    char pad[0x20 - 0xC];
};

struct Tri_00151A68 {
    Vert_00151A68 v[3];
};

struct Obj_00151A68 {
    Vec_00151A68* m0;
    char pad4[0xC - 0x4];
    Mat_00151A68* mC;
    char pad10[0x20 - 0x10];
    int m20;
    char pad24[0x2C - 0x24];
    Tri_00151A68* m2C;
};

extern "C" void func_00143208(Obj_00151A68* o, int i, float t);

static inline void Sub(Vec_00151A68& out, const Vert_00151A68& p, const Vec_00151A68& c)
{
    out.x = p.x - c.x;
    out.y = p.y - c.y;
    out.z = p.z - c.z;
    out.w = 1.0f;
}

static inline void Add(Vec_00151A68& v, const Vec_00151A68& c)
{
    v.x += c.x;
    v.y += c.y;
    v.z += c.z;
    v.w += c.w;
}

static inline void Store(Vert_00151A68& p, const Vec_00151A68& v)
{
    p.x = v.x;
    p.y = v.y;
    p.z = v.z;
}

extern "C" void func_00151A68(Obj_00151A68* o, float t)
{
    Tri_00151A68* tri = o->m2C;
    for (int i = 0; i < o->m20; i++) {
        Vec_00151A68 v[4];
        Sub(v[0], tri->v[0], o->m0[i]);
        Sub(v[1], tri->v[1], o->m0[i]);
        Sub(v[2], tri->v[2], o->m0[i]);
        v[0] = o->mC[i].Xform(&v[0]);
        v[1] = o->mC[i].Xform(&v[1]);
        v[2] = o->mC[i].Xform(&v[2]);
        func_00143208(o, i, t);
        Add(v[0], o->m0[i]);
        Add(v[1], o->m0[i]);
        Add(v[2], o->m0[i]);
        Store(tri->v[0], v[0]);
        Store(tri->v[1], v[1]);
        Store(tri->v[2], v[2]);
        tri++;
    }
}
