typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);
extern "C" float func_00340F60(float x);
extern "C" float func_00341068(float x);

struct Vec11BB90 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec11BB90() {}
    Vec11BB90(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec11BB90 operator*(const Vec11BB90& v, float s)
{
    return Vec11BB90(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec11BB90 operator+(const Vec11BB90& a, const Vec11BB90& b)
{
    return Vec11BB90(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec11BB90 Cross11BB90(const Vec11BB90& a, const Vec11BB90& b)
{
    return Vec11BB90(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot11BB90(const Vec11BB90& a, const Vec11BB90& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat11BB90 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat11BB90() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
    Quat11BB90(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void SetEuler(const Vec11BB90& e)
    {
        float hz = e.z * 0.5f;
        float hy = e.y * 0.5f;
        float hx = e.x * 0.5f;
        float cz = func_00340F60(hz);
        float cy = func_00340F60(hy);
        float cx = func_00340F60(hx);
        float sz = func_00341068(hz);
        float sy = func_00341068(hy);
        float sx = func_00341068(hx);
        w = cz * cy * cx + sz * sy * sx;
        x = cz * cy * sx - sz * sy * cx;
        y = cz * sy * cx + sz * cy * sx;
        z = sz * cy * cx - cz * sy * sx;
    }
};

static inline Quat11BB90 EulerQuat(const Vec11BB90& e)
{
    Quat11BB90 r;
    r.SetEuler(e);
    return r;
}

static inline Quat11BB90 operator*(const Quat11BB90& a, const Quat11BB90& b)
{
    Quat11BB90 r(a);
    Vec11BB90 va;
    Vec11BB90 vb;
    va.q = r.q;
    vb.q = b.q;
    Vec11BB90 v = vb * r.w + va * b.w + Cross11BB90(va, vb);
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = r.w * b.w - Dot11BB90(va, vb);
    return r;
}

struct Entry11BB90 {
    unsigned int m0;
    char pad4[0x4C];
    int m50;
    char pad54[0x3C];
    Vec11BB90 m90;
    char padA0[0x50];
};

extern "C" void* func_0011AC50(void* self);
extern "C" void* func_0011AC30(void* self);
extern "C" void* func_00185578(void* o, unsigned int id);
extern "C" int func_001A2CD0(void* o);
extern "C" Entry11BB90* func_001A2CD8(void* o);
extern "C" int func_0011D798(void* skel, unsigned int id);
extern "C" float func_0011D4C0(Quat11BB90* q);

struct C_0011BB90 {
    int Apply(Quat11BB90* pose);
};

int C_0011BB90::Apply(Quat11BB90* pose)
{
    void* skel = func_0011AC50(this);
    void* o = func_00185578(func_0011AC30(this), 0x72AD7B23);
    int n = func_001A2CD0(o);
    Entry11BB90* e = func_001A2CD8(o);
    for (int i = 0; i < n; i++, e++) {
        int idx = func_0011D798(skel, e->m0);
        if (idx == -1)
            continue;
        Quat11BB90* q = &pose[idx];
        if (e->m50) {
            Vec11BB90 ang;
            ang.q = e->m90.q;
            ang.x *= 0.0015339808f;
            ang.y *= 0.0015339808f;
            ang.z *= 0.0015339808f;
            ang.w *= 0.0015339808f;
            Quat11BB90 rot = EulerQuat(ang);
            *q = rot * *q;
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
    return 0;
}
