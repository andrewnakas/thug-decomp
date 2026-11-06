typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00190800 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00190800() {}
    Vec_00190800(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00190800& operator+=(const Vec_00190800& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_00190800& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

static inline Vec_00190800 operator*(const Vec_00190800& v, float s)
{
    return Vec_00190800(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_00190800 operator+(const Vec_00190800& a, const Vec_00190800& b)
{
    return Vec_00190800(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00190800 Cross_00190800(const Vec_00190800& a, const Vec_00190800& b)
{
    return Vec_00190800(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot_00190800(const Vec_00190800& a, const Vec_00190800& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat_00190800;
extern "C" float func_0011D4C0(Quat_00190800* q);

struct Quat_00190800 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat_00190800() {}
    Quat_00190800(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Quat_00190800& operator+=(const Quat_00190800& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Quat_00190800& operator*=(const Quat_00190800& b)
    {
        Vec_00190800 va;
        Vec_00190800 vb;
        va.q = q;
        vb.q = b.q;
        Vec_00190800 v = vb * w + va * b.w + Cross_00190800(va, vb);
        x = v.x;
        y = v.y;
        z = v.z;
        w = w * b.w - Dot_00190800(va, vb);
        return *this;
    }
    void Normalize(float len = 1.0f);
    float Length() { return sqrtf(func_0011D4C0(this)); }
    Quat_00190800& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

inline void Quat_00190800::Normalize(float len)
{
    float l = Length();
    if (l > 0.0f) {
        *this *= len / l;
    }
}

struct Pt_00190800 {
    Vec_00190800 pos;
    char pad10[0x20];
};

extern Pt_00190800 D_003E4540[];


struct Mat_00190800 {
    Vec_00190800 r[3];
    void FromQuat(const Quat_00190800& q, float n)
    {
        n = (n > 0.0f) ? 2.0f / n : 0.0f;
        float s = n;
        float qx = q.x;
        float qy = q.y;
        float qz = q.z;
        float qw = q.w;
        float xs = qx * s;
        float ys = qy * s;
        float zs = qz * s;
        float wx = qw * xs;
        float wy = qw * ys;
        float wz = qw * zs;
        float xx = qx * xs;
        float xy = qx * ys;
        float xz = qx * zs;
        float yy = qy * ys;
        float yz = qy * zs;
        float zz = qz * zs;
        r[0].x = 1.0f - (yy + zz);
        r[1].x = xy + wz;
        r[2].x = xz - wy;
        r[0].y = xy - wz;
        r[1].y = 1.0f - (xx + zz);
        r[2].y = yz + wx;
        r[0].z = xz + wy;
        r[1].z = yz - wx;
        r[2].z = 1.0f - (xx + yy);
}
    Vec_00190800 Rotate(const Vec_00190800& p) const
    {
        Vec_00190800 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

struct Body_00190800 {
    char pad0[0x20];
    float m20;
    char pad24[0x50 - 0x24];
    Pt_00190800* m50;
    unsigned short m54;
    char pad56[0xE0 - 0x56];
    Vec_00190800 mE0;
    Vec_00190800 mF0;
    Quat_00190800 m100;
    Vec_00190800 m110;
    Mat_00190800 m120;
    char pad150[0x160 - 0x150];
    signed char m160;
    void Integrate(float dt);
    Vec_00190800 Vel(float dt) const { return Vec_00190800(mF0.x * dt, mF0.y * dt, mF0.z * dt, mF0.w * dt); }
};

void Body_00190800::Integrate(float dt)
{
    if (m160 < 3) {
        Vec_00190800 t = mF0;
        float g = m20 * 0.5f;
        t.y += dt * g;
        t *= dt;
        mE0 += t;
        mF0.y += dt * m20;
    } else {
        mE0 += Vel(dt);
    }
    Quat_00190800 d = m100;
    d *= Quat_00190800(m110.x * -0.5f, m110.y * -0.5f, m110.z * -0.5f, 0.0f);
    d *= dt;
    m100 += d;
    m100.Normalize();
    m120.FromQuat(m100, m100.x * m100.x + m100.y * m100.y + m100.z * m100.z + m100.w * m100.w);
    int i = m54;
    while (i-- != 0) {
        Vec_00190800 r = m120.Rotate(m50[i].pos);
        D_003E4540[i].pos = r;
    }
}
