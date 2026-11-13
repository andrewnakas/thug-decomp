/* fuzzy: 76.9 */
typedef int qword_00209608 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00209608 {
    union {
        struct { float x, y, z, w; };
        qword_00209608 q;
    };
    Vec_00209608() {}
    Vec_00209608(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_00209608 operator-(const Vec_00209608& a, const Vec_00209608& b)
{
    float x = a.x - b.x; float y = a.y - b.y; float z = a.z - b.z; float w = a.w - b.w;
    Vec_00209608 r;
    r.x = x; r.y = y; r.z = z; r.w = w;
    return r;
}
static inline float Length_00209608(Vec_00209608 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

struct Seg_00209608 {
    Vec_00209608 a;
    Vec_00209608 b;
};

struct Vert_00209608 {
    Vec_00209608 p;
    float val;
};

struct Face8_00209608 {
    char pad0[4];
    unsigned char v[3];
    char pad7;
};
struct Face10_00209608 {
    char pad0[4];
    unsigned short v[3];
};

struct Geom_00209608 {
    char pad0[0xA];
    unsigned char mA;
    unsigned char mB;
    union {
        Face8_00209608* f8;
        Face10_00209608* f10;
    } mC;
    char pad10[0x38 - 0x10];
    unsigned char* m38;
};

class Sector_00209608 {
public:
    int m0;
    int m4;
    Geom_00209608* m8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual Vec_00209608 GetVertex(int idx);
};

extern "C" Seg_00209608* func_00101F40(Seg_00209608* s, Vec_00209608* a, Vec_00209608* b);
extern "C" int func_00101F60(Seg_00209608* a, Seg_00209608* b, Vec_00209608* pa, Vec_00209608* pb, float* mua,
                             float* mub, int clamp);

static inline int FaceVert_00209608(Geom_00209608* g, int face, int i)
{
    if (g->mA) {
        return g->mC.f8[face].v[i];
    }
    return g->mC.f10[face].v[i];
}

struct Obj_00209608 {
    char pad0[0x40];
    float m40;
    float m44;
    float m48;
    char pad4C[0x50 - 0x4C];
    int m50;
    char pad54[0x70 - 0x54];
    Sector_00209608* m70;
    char pad74[0x88 - 0x74];
    signed char m88;
    float GetValue();
};

float Obj_00209608::GetValue()
{
    Vert_00209608 v[3];
    if (!m88) {
        return 0.5f;
    }
    Sector_00209608* sec = m70;
    Geom_00209608* g = sec->m8;
    int face = m50;
    float px = m40;
    float py = m44;
    float pz = m48;
    for (unsigned int i = 0; i < 3; i++) {
        const Vec_00209608& pos = sec->GetVertex(FaceVert_00209608(g, face, i));
        float x = pos.x - px;
        float y = pos.y - py;
        float z = pos.z - pz;
        v[i].p.w = 1.0f;
        v[i].p.x = x;
        v[i].p.y = y;
        v[i].p.z = z;
        v[i].val = g->m38[FaceVert_00209608(g, face, i)] * 0.003921568859f;
    }
    Vec_00209608 p(0.0f, 0.0f, 0.0f, 1.0f);
    Seg_00209608 s1;
    func_00101F40(&s1, &v[0].p, &p);
    Seg_00209608 s2;
    func_00101F40(&s2, &v[1].p, &v[2].p);
    Vec_00209608 pb;
    float mua;
    float mub;
    func_00101F60(&s1, &s2, &p, &pb, &mua, &mub, 0);
    float t = Length_00209608(p - v[1].p);
    t /= Length_00209608(v[2].p - v[1].p);
    float mid = v[1].val + (v[2].val - v[1].val) * t;
    float u = sqrtf(v[0].p.x * v[0].p.x + v[0].p.y * v[0].p.y + v[0].p.z * v[0].p.z);
    u /= Length_00209608(p - v[0].p);
    return v[0].val + (mid - v[0].val) * u;
}
