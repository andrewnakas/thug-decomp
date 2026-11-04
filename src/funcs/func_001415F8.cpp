typedef int qword __attribute__((mode(TI)));

struct Vec_001415F8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001415F8() {}
    Vec_001415F8(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
};

static inline Vec_001415F8 operator-(const Vec_001415F8& a, const Vec_001415F8& b)
{
    return Vec_001415F8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001415F8 operator*(const Vec_001415F8& a, float s)
{
    return Vec_001415F8(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" Vec_001415F8 func_001415F8(const Vec_001415F8& p0, const Vec_001415F8& p2, const Vec_001415F8& p1, float t1, float t2)
{
    Vec_001415F8 d1, d2, a, b, r;
    d1 = (p1 - p0) * t1;
    d2 = (p2 - p0) * t2;
    float inv = 1.0f / (t1 * t2 * (t2 - t1));
    a = (d2 * t2 - d1 * t1) * inv;
    b = (d1 - d2) * inv;
    for (int i = 0; i < 3; i++) {
        float t = a[i] * -0.5f / b[i];
        r[i] = p0[i] + a[i] * t + b[i] * t * t;
    }
    r.w = 0.0f;
    return r;
}
