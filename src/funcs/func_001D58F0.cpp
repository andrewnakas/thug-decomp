typedef int qword_001D58F0 __attribute__((mode(TI)));

struct Vec_001D58F0 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D58F0 q;
    };
    Vec_001D58F0() {}
    Vec_001D58F0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_001D58F0 operator-(const Vec_001D58F0& a, const Vec_001D58F0& b)
{
    return Vec_001D58F0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
static inline Vec_001D58F0 Cross_001D58F0(const Vec_001D58F0& a, const Vec_001D58F0& b)
{
    return Vec_001D58F0(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Face8_001D58F0 {
    char pad0[4];
    unsigned char v[3];
    char pad7;
};
struct Face10_001D58F0 {
    char pad0[4];
    unsigned short v[3];
};
struct CVert_001D58F0 {
    unsigned short x, y, z;
};
struct FVert_001D58F0 {
    float x, y, z;
};

struct Geom_001D58F0 {
    char pad0[0xA];
    unsigned char mA;
    unsigned char mB;
    union {
        Face8_001D58F0* f8;
        Face10_001D58F0* f10;
    } mC;
    Vec_001D58F0 m10;
    char pad20[0x30 - 0x20];
    union {
        CVert_001D58F0* c;
        FVert_001D58F0* f;
    } m30;
};

struct Hit_001D58F0 {
    Vec_001D58F0 normal;
    Vec_001D58F0 point;
    int m20;
};

extern "C" void func_003233B8(Vec_001D58F0* out, Vec_001D58F0* in);
extern "C" bool func_001D1EF0(void* line, void* obj, Hit_001D58F0* hit, float t, void* data);
extern "C" unsigned short* func_001D8118(Geom_001D58F0* g, void* key, unsigned int* count);
extern "C" bool func_001D2220(void* line, void* a, Vec_001D58F0* v0, Vec_001D58F0* v1, Vec_001D58F0* v2, float* t);

struct Coll_001D58F0 {
    char pad0[0x8];
    Geom_001D58F0* m8;
};
static inline void GetVert_001D58F0(Geom_001D58F0* g, int i, Vec_001D58F0& out)
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

static inline void Normalize_001D58F0(Vec_001D58F0& v) { func_003233B8(&v, &v); }

extern "C" bool func_001D58F0(Coll_001D58F0* self, void* line, void* a, void* data, void* key)
{
    bool hitAny = false;
    unsigned int count;
    unsigned short* idx = func_001D8118(self->m8, key, &count);
    for (unsigned int n = 0; n < count; n++, idx++) {
        Vec_001D58F0 v0;
        Vec_001D58F0 v1;
        Vec_001D58F0 v2;
        Geom_001D58F0* g = self->m8;
        if (g->mA) {
            Face8_001D58F0* f = &g->mC.f8[*idx];
            GetVert_001D58F0(self->m8, f->v[0], v0);
            GetVert_001D58F0(self->m8, f->v[1], v1);
            GetVert_001D58F0(self->m8, f->v[2], v2);
        } else {
            Face10_001D58F0* f = &g->mC.f10[*idx];
            GetVert_001D58F0(self->m8, f->v[0], v0);
            GetVert_001D58F0(self->m8, f->v[1], v1);
            GetVert_001D58F0(self->m8, f->v[2], v2);
        }
        float t;
        if (func_001D2220(line, a, &v0, &v1, &v2, &t)) {
            Hit_001D58F0 hit;
            hit.point = v0;
            hit.m20 = *idx;
            Vec_001D58F0 e1 = v1 - v0;
            Vec_001D58F0 e2 = v2 - v0;
            hit.normal = Cross_001D58F0(e1, e2);
            Normalize_001D58F0(hit.normal);
            if (func_001D1EF0(line, self, &hit, t, data)) hitAny = true;
        }
    }
    return hitAny;
}
