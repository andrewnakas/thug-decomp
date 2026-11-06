typedef int qword_001D6B00 __attribute__((mode(TI)));

struct Vec_001D6B00 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D6B00 q;
    };
    Vec_001D6B00() {}
    Vec_001D6B00(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_001D6B00 operator-(const Vec_001D6B00& a, const Vec_001D6B00& b)
{
    return Vec_001D6B00(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
static inline Vec_001D6B00 Cross_001D6B00(const Vec_001D6B00& a, const Vec_001D6B00& b)
{
    return Vec_001D6B00(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Seg_001D6B00;
struct Box_001D6B00;
struct Face8_001D6B00 {
    char pad0[4];
    unsigned char v[3];
    char pad7;
};
struct Face10_001D6B00 {
    char pad0[4];
    unsigned short v[3];
};
struct CVert_001D6B00 {
    unsigned short x, y, z;
};
struct FVert_001D6B00 {
    float x, y, z;
};

struct Geom_001D6B00 {
    char pad0[0xA];
    unsigned char mA;
    unsigned char mB;
    union {
        Face8_001D6B00* f8;
        Face10_001D6B00* f10;
    } mC;
    Vec_001D6B00 m10;
    char pad20[0x30 - 0x20];
    union {
        CVert_001D6B00* c;
        FVert_001D6B00* f;
    } m30;
};

struct Hit_001D6B00 {
    Vec_001D6B00 normal;
    Vec_001D6B00 point;
    int m20;
};

extern "C" void func_003233B8(Vec_001D6B00* out, Vec_001D6B00* in);
extern "C" bool func_001D1EF0(void* line, void* obj, Hit_001D6B00* hit, float t, void* data);
extern "C" unsigned short* func_001D8118(Geom_001D6B00* g, Box_001D6B00* box, unsigned int* count);
extern "C" bool func_001D2220(Seg_001D6B00* seg, Vec_001D6B00* d, Vec_001D6B00* v0, Vec_001D6B00* v1, Vec_001D6B00* v2, float* t);

struct Seg_001D6B00 {
    Vec_001D6B00 p0;
    Vec_001D6B00 p1;
};
struct Box_001D6B00 {
    Vec_001D6B00 mn;
    Vec_001D6B00 mx;
};
struct Mat_001D6B00 {
    Vec_001D6B00 r[4];
};
struct Coll_001D6B00 {
    char pad0[0x8];
    Geom_001D6B00* m8;
    char padC[0x10 - 0xC];
    Vec_001D6B00 m10;
    Mat_001D6B00 m20;
};
extern "C" void func_00101F38(Seg_001D6B00* seg);
extern "C" void func_001D4F18(Coll_001D6B00* self, void* line, Seg_001D6B00* seg);
extern "C" void func_00102328(Box_001D6B00* box, Vec_001D6B00* p);
extern "C" void func_00102358(Box_001D6B00* box, Vec_001D6B00* p);
extern "C" Vec_001D6B00 func_001522A8(Mat_001D6B00* m, Vec_001D6B00* v);
static inline void GetVert_001D6B00(Geom_001D6B00* g, int i, Vec_001D6B00& out)
{
    if (g->mB) {
        out = g->m10;
        out.x += g->m30.c[i].x * 0.0625f;
        out.y += g->m30.c[i].y * 0.0625f;
        out.z += g->m30.c[i].z * 0.0625f;
        out.w = 0.0f;
    } else {
        out.x = g->m30.f[i].x;
        out.y = g->m30.f[i].y;
        out.z = g->m30.f[i].z;
        out.w = 0.0f;
    }
}

static inline void Normalize_001D6B00(Vec_001D6B00& v) { func_003233B8(&v, &v); }
static inline Vec_001D6B00 Xform_001D6B00(Mat_001D6B00* m, Vec_001D6B00& v) { return func_001522A8(m, &v); }

extern "C" bool func_001D6B00(Coll_001D6B00* self, void* line, void* unused, void* data)
{
    bool hitAny = false;
    Seg_001D6B00 seg;
    func_00101F38(&seg);
    func_001D4F18(self, line, &seg);
    Vec_001D6B00* pe = &seg.p1;
    Vec_001D6B00 d = seg.p1 - seg.p0;
    Box_001D6B00 box;
    func_00102328(&box, &seg.p0);
    func_00102358(&box, pe);
    unsigned int count;
    unsigned short* idx = func_001D8118(self->m8, &box, &count);
    for (unsigned int n = 0; n < count; n++, idx++) {
        Vec_001D6B00 v0;
        Vec_001D6B00 v1;
        Vec_001D6B00 v2;
        Geom_001D6B00* g = self->m8;
        if (g->mA) {
            Face8_001D6B00* f = &g->mC.f8[*idx];
            GetVert_001D6B00(self->m8, f->v[0], v0);
            GetVert_001D6B00(self->m8, f->v[1], v1);
            GetVert_001D6B00(self->m8, f->v[2], v2);
        } else {
            Face10_001D6B00* f = &g->mC.f10[*idx];
            GetVert_001D6B00(self->m8, f->v[0], v0);
            GetVert_001D6B00(self->m8, f->v[1], v1);
            GetVert_001D6B00(self->m8, f->v[2], v2);
        }
        float t;
        if (func_001D2220(&seg, &d, &v0, &v1, &v2, &t)) {
            Hit_001D6B00 hit;
            hit.point = v0;
            hit.m20 = *idx;
            Vec_001D6B00 e1 = v1 - v0;
            Vec_001D6B00 e2 = v2 - v0;
            hit.normal = Cross_001D6B00(e1, e2);
            Normalize_001D6B00(hit.normal);
            hit.point = Xform_001D6B00(&self->m20, hit.point);
            hit.point.x += self->m10.x;
            hit.point.y += self->m10.y;
            hit.point.z += self->m10.z;
            hit.point.w += self->m10.w;
            hit.normal = Xform_001D6B00(&self->m20, hit.normal);
            if (func_001D1EF0(line, self, &hit, t, data)) hitAny = true;
        }
    }
    return hitAny;
}
