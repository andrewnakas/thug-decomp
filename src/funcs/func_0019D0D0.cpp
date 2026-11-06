extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_0019D0D0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019D0D0() {}
    Vec_0019D0D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019D0D0 operator-() const { return Vec_0019D0D0(-x, -y, -z, -w); }
    void Normalize();
    float Dot(const Vec_0019D0D0& o) const { return x * o.x + y * o.y + z * o.z; }
    Vec_0019D0D0& operator+=(const Vec_0019D0D0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_0019D0D0 operator*(const Vec_0019D0D0& v, float s)
{
    return Vec_0019D0D0(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern "C" void func_003233B8(Vec_0019D0D0* d, Vec_0019D0D0* s);
inline void Vec_0019D0D0::Normalize() { func_003233B8(this, this); }

struct A_0019D0D0 {
    char pad0[0x90];
    Vec_0019D0D0 m90;
    Vec_0019D0D0 Back() const { return Vec_0019D0D0(-m90.x, -m90.y, -m90.z, -m90.w); }
};

struct B_0019D0D0 {
    char pad0[0xB0];
    Vec_0019D0D0 mB0;
    char padC0[0x120 - 0xC0];
    int m120;
};

struct Obj_0019D0D0 {
    char pad0[0x1C];
    A_0019D0D0* m1C;
    B_0019D0D0* m20;
    char pad24[0x40 - 0x24];
    Vec_0019D0D0 m40;
    void Update();
};

void Obj_0019D0D0::Update()
{
    Vec_0019D0D0 d(-m20->mB0.x, 0.0f, -m20->mB0.z, -m20->mB0.w);
    float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    d.Normalize();
    if (m20->m120 < 2) {
        if (len < 88000008.0f) {
            return;
        }
        m40 = d;
        return;
    }
    float s = len * 0.003787878901f;
    float t;
    if (s > 1.0f) {
        t = 1.0f;
    } else {
        t = s;
    }
    float f = t * d.Dot(m1C->Back());
    m40 = m1C->Back();
    m40.y = 0.0f;
    m40.Normalize();
    if (f > 0.0f) {
        m40 += d * f;
        m40.Normalize();
    }
}
