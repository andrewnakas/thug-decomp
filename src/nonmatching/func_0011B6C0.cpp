/* fuzzy: 72.6 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec11B6C0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec11B6C0() {}
    Vec11B6C0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec11B6C0 operator*(const Vec11B6C0& v, float s)
{
    return Vec11B6C0(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec11B6C0 operator+(const Vec11B6C0& a, const Vec11B6C0& b)
{
    return Vec11B6C0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec11B6C0 Cross11B6C0(const Vec11B6C0& a, const Vec11B6C0& b)
{
    return Vec11B6C0(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot11B6C0(const Vec11B6C0& a, const Vec11B6C0& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat11B6C0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat11B6C0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
    Quat11B6C0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Quat11B6C0 operator*(const Quat11B6C0& a, const Quat11B6C0& b)
{
    Quat11B6C0 r(a);
    Vec11B6C0 va;
    Vec11B6C0 vb;
    va.q = r.q;
    vb.q = b.q;
    Vec11B6C0 v = vb * r.w + va * b.w + Cross11B6C0(va, vb);
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = r.w * b.w - Dot11B6C0(va, vb);
    return r;
}

struct Pose11B6C0 {
    Quat11B6C0 q[64];
    Vec11B6C0 v[64];
};

struct Info11B6C0 {
    char pad[0x1C];
    int m1C;
};

extern "C" void* func_0011AC50(void* self);
extern "C" void* func_0011AC30(void* self);
extern "C" Info11B6C0* func_00185578(void* o, unsigned int id);
extern "C" int func_0011D798(void* skel, unsigned int id);
extern "C" float func_0011D4C0(Quat11B6C0* q);
extern "C" int func_0011D9E8(void* skel);
extern "C" int func_0011D7D0(void* skel, int i);

struct C_0011B6C0 {
    char pad[0x18];
    int m18;
    int Apply(Pose11B6C0* pose);
};

int C_0011B6C0::Apply(Pose11B6C0* pose)
{
    void* skel = func_0011AC50(this);
    Info11B6C0* info = func_00185578(func_0011AC30(this), 0x488AF07A);
    if (info && info->m1C) {
        int idx = func_0011D798(skel, 0x98971FAF);
        if (idx != -1) {
            Quat11B6C0* q = &pose->q[idx];
            *q = Quat11B6C0(0.0f, 0.0f, 1.0f, 0.0f) * *q;
            float l = sqrtf(func_0011D4C0(q));
            if (l > 0.0f) {
                float inv = 1.0f / l;
                q->x *= inv;
                q->y *= inv;
                q->z *= inv;
                q->w *= inv;
            }
        }
    }
    if (m18) {
        Quat11B6C0 quats[64];
        Vec11B6C0 vecs[64];
        int n = func_0011D9E8(skel);
        int i;
        for (i = 0; i < n; i++)
            quats[i] = pose->q[i];
        for (i = 0; i < n; i++)
            vecs[i] = pose->v[i];
        for (i = 0; i < n; i++) {
            int j = func_0011D7D0(skel, i);
            if (j != -1) {
                pose->v[i] = vecs[j];
                pose->q[i] = quats[j];
            } else {
                pose->q[i] = quats[i];
                pose->v[i] = vecs[i];
            }
            pose->q[i].x = -pose->q[i].x;
            pose->q[i].w = -pose->q[i].w;
            pose->v[i].x = -pose->v[i].x;
        }
    }
    return 1;
}
