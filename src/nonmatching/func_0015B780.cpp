/* fuzzy: 84.2 */
typedef int qword_0015B780 __attribute__((mode(TI)));

struct V4_0015B780 {
    union {
        qword_0015B780 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_0015B780() {}
    void Set(const V4_0015B780& v, float aw)
    {
        q = v.q;
        w = aw;
    }
    void Zero()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
    V4_0015B780(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline V4_0015B780 operator-(const V4_0015B780& a, const V4_0015B780& b)
{
    return V4_0015B780(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_0015B780 operator*(const V4_0015B780& a, float s)
{
    return V4_0015B780(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct C_0015B780 {
    char pad0[0x8];
    int m8;
    float mC;
    float m10;
    float m14;
    char pad18[0x14];
    float m2C;
    float m30;
    char pad34[0x4C];
    V4_0015B780 m80;
    V4_0015B780 m90;
    V4_0015B780 mA0;
    char padB0[0x1C0];
    V4_0015B780 m270;
    V4_0015B780 m280;
    V4_0015B780 m290;
    V4_0015B780 m2A0;
    V4_0015B780 m2B0;
    V4_0015B780 m2C0;
    void Calc();
};

void C_0015B780::Calc()
{
    V4_0015B780 p0 = m80;
    p0.w = mC;
    V4_0015B780 p1 = m90;
    p1.w = m10;
    V4_0015B780 p2 = mA0;
    p2.w = m14;
    float t = m2C;
    float s = t * m30 * 0.01f;
    V4_0015B780 a;
    V4_0015B780 b;
    if (m8) {
        float inv = 1.0f / (s * t * (t - s));
        a = ((p1 - p0) * (t * t) - (p2 - p0) * (s * s)) * inv;
        b = ((p2 - p0) * s - (p1 - p0) * t) * inv;
    } else {
        a = (p2 - p0) * (1.0f / t);
        b.Zero();
    }
    m270 = p0 - V4_0015B780(m2A0.x * 1.5f, m2A0.y * 1.5f, m2A0.z * 1.5f, m2A0.w * 1.5f);
    m280 = a - V4_0015B780(m2B0.x * 1.5f, m2B0.y * 1.5f, m2B0.z * 1.5f, m2B0.w * 1.5f);
    m290 = b - V4_0015B780(m2C0.x * 1.5f, m2C0.y * 1.5f, m2C0.z * 1.5f, m2C0.w * 1.5f);
}
