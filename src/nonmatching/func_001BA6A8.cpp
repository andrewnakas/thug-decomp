/* fuzzy: 74.0 */
typedef int qword_001BA6A8 __attribute__((mode(TI)));

struct Vec_001BA6A8 {
    union {
        struct { float x, y, z, w; };
        qword_001BA6A8 q;
    };
    Vec_001BA6A8() {}
    Vec_001BA6A8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001BA6A8 operator*(const Vec_001BA6A8& v, float s)
{
    return Vec_001BA6A8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_001BA6A8 operator+(const Vec_001BA6A8& a, const Vec_001BA6A8& b)
{
    return Vec_001BA6A8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001BA6A8 Cross_001BA6A8(const Vec_001BA6A8& a, const Vec_001BA6A8& b)
{
    return Vec_001BA6A8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot_001BA6A8(const Vec_001BA6A8& a, const Vec_001BA6A8& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat_001BA6A8 {
    union {
        struct { float x, y, z, w; };
        qword_001BA6A8 q;
    };
    Quat_001BA6A8& operator*=(const Quat_001BA6A8& b);
};

Quat_001BA6A8& Quat_001BA6A8::operator*=(const Quat_001BA6A8& b)
{
    Vec_001BA6A8 va;
    Vec_001BA6A8 vb;
    vb.q = b.q;
    va.q = q;
    Vec_001BA6A8 v = vb * w + va * b.w + Cross_001BA6A8(va, vb);
    float nw = b.w * w - Dot_001BA6A8(va, vb);
    x = v.x;
    y = v.y;
    z = v.z;
    w = nw;
    return *this;
}
