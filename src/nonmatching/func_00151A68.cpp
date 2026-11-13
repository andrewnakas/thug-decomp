/* cflags: -fno-strength-reduce */
/* fuzzy: 82.9 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00151A68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
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
    out.Set(p.x - c.x, p.y - c.y, p.z - c.z, 1.0f);
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
        Vec_00151A68* c = &v[2];
        Vec_00151A68* a = &v[0];
        Vec_00151A68* b = &v[1];
        Sub(*a, tri->v[0], o->m0[i]);
        Sub(*b, tri->v[1], o->m0[i]);
        Sub(*c, tri->v[2], o->m0[i]);
        *a = o->mC[i].Xform(a);
        *b = o->mC[i].Xform(b);
        *c = o->mC[i].Xform(c);
        func_00143208(o, i, t);
        Add(*a, o->m0[i]);
        Add(*b, o->m0[i]);
        Add(*c, o->m0[i]);
        Store(tri->v[0], v[0]);
        Store(tri->v[1], v[1]);
        Store(tri->v[2], v[2]);
        tri++;
    }
}
