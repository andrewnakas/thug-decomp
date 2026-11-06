typedef int qword_001A80B8 __attribute__((mode(TI)));

struct Vec_001A80B8 {
    union {
        struct { float x, y, z, w; };
        qword_001A80B8 q;
    };
    Vec_001A80B8() {}
    Vec_001A80B8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001A80B8 operator-(const Vec_001A80B8& a, const Vec_001A80B8& b)
{
    return Vec_001A80B8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001A80B8 operator+(const Vec_001A80B8& a, const Vec_001A80B8& b)
{
    return Vec_001A80B8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001A80B8 operator*(const Vec_001A80B8& v, float s)
{
    return Vec_001A80B8(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern "C" float func_0010FAB8();

static inline float Frames_001A80B8()
{
    return func_0010FAB8() * 60.0f;
}

struct Model_001A80B8 {
    char pad[0x50];
    Vec_001A80B8 m50;
};

struct Obj_001A80B8;
extern "C" void func_001A6BB8(Obj_001A80B8* o, int node);

struct Obj_001A80B8 {
    char pad[0xC];
    Model_001A80B8* mC;
    char pad10[0x14];
    float m24;
    char pad28[0x130 - 0x28];
    Vec_001A80B8 m130;
    float m140;
    float m144;
    float m148;
    float m14C;
    int m150;
    char pad154[0x1C0 - 0x154];
    Vec_001A80B8 m1C0;
    char pad1D0[0x210 - 0x1D0];
    float m210;
    int Method();
};

int Obj_001A80B8::Method()
{
    if (m14C != 0.0f) {
        m24 += m14C * Frames_001A80B8();
        if (m148 <= m24) {
            m24 = m148;
            m14C = 0.0f;
        }
    }
    m144 += m210 * m24;
    if (m140 <= m144) {
        mC->m50 = m130;
        if (m150 != -1)
            func_001A6BB8(this, m150);
        return 1;
    }
    float t = m144 / m140;
    Vec_001A80B8 d((m130.x - m1C0.x) * t, (m130.y - m1C0.y) * t, (m130.z - m1C0.z) * t, (m130.w - m1C0.w) * t);
    Vec_001A80B8 p(m1C0.x + d.x, m1C0.y + d.y, m1C0.z + d.z, m1C0.w + d.w);
    mC->m50 = p;
    return 0;
}
