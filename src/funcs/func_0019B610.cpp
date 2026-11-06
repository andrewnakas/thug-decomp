typedef int qword __attribute__((mode(TI)));

struct Vec_0019B610 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019B610() {}
    Vec_0019B610(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_0019B610 {
    Vec_0019B610 r[4];
};

static inline Vec_0019B610 Cross_0019B610(const Vec_0019B610& a, const Vec_0019B610& b)
{
    return Vec_0019B610(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline Vec_0019B610 operator*(const Vec_0019B610& a, float s)
{
    return Vec_0019B610(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline Vec_0019B610 operator+(const Vec_0019B610& a, const Vec_0019B610& b)
{
    return Vec_0019B610(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_0019B610 Rotate_0019B610(const Vec_0019B610& v, const Mat_0019B610& m)
{
    Vec_0019B610 o;
    o.x = v.x * m.r[0].x + v.y * m.r[1].x + v.z * m.r[2].x;
    o.y = v.x * m.r[0].y + v.y * m.r[1].y + v.z * m.r[2].y;
    o.z = v.x * m.r[0].z + v.y * m.r[1].z + v.z * m.r[2].z;
    o.w = v.w;
    return o;
}

class Body_0019B610 {
public:
    char pad0[0xD0];
    Mat_0019B610 m_invInertia;
    char pad110[0x180 - 0x110];
    float m_invMass;
    float ImpulseDenom(Vec_0019B610* r, Vec_0019B610* n);
};

float Body_0019B610::ImpulseDenom(Vec_0019B610* r, Vec_0019B610* n)
{
    Vec_0019B610 nn = *n;
    Vec_0019B610 rn = Cross_0019B610(*r, *n);
    Vec_0019B610 lin = nn * m_invMass;
    Vec_0019B610 t = Rotate_0019B610(rn, m_invInertia);
    Vec_0019B610 s = lin + Cross_0019B610(t, *r);
    return 1.0f / (n->x * s.x + n->y * s.y + n->z * s.z);
}
