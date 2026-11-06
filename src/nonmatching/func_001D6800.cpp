/* fuzzy: 98.9 */
typedef int qword_001D6800 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_001D6800 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D6800 q;
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct CVert_001D6800 {
    unsigned short x, y, z;
};
struct FVert_001D6800 {
    float x, y, z;
};

struct Geom_001D6800 {
    int m0;
    short m4;
    unsigned short m6;
    char pad8[0xB - 0x8];
    unsigned char mB;
    char padC[0x10 - 0xC];
    Vec_001D6800 m10;
    char pad20[0x30 - 0x20];
    union {
        CVert_001D6800* c;
        FVert_001D6800* f;
    } m30;
};

static inline Vec_001D6800 GetVert_001D6800(Geom_001D6800* g, int i)
{
    Vec_001D6800 out;
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
    return out;
}

static inline float Length_001D6800(Vec_001D6800 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

struct Coll_001D6800 {
    int m0;
    char pad4[0x8 - 0x4];
    Geom_001D6800* m8;
    char padC[0xB0 - 0xC];
    float mB0;
    int mB4;
    void SetGeom(Geom_001D6800* g);
};

void Coll_001D6800::SetGeom(Geom_001D6800* g)
{
    m8 = g;
    if (g) {
        m0 = g->m0;
    }
    mB0 = 0.0f;
    for (int i = 0; i < m8->m6; i++) {
        float len = GetVert_001D6800(m8, i).Length();
        if (mB0 < len) {
            mB0 = len;
        }
    }
    mB4 = 1;
}
