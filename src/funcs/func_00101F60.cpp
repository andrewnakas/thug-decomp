typedef int qword __attribute__((mode(TI)));

struct Vector {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vector() {}
    Vector(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float operator[](int i) const { return (&x)[i]; }
};

static inline Vector operator-(const Vector& a, const Vector& b) { return Vector(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }

extern "C" float fabsf(float);

static inline Vector Add(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vector Scale(const Vector& a, float s)
{
    return Vector(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline float Dot(const Vector& a, const Vector& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float Clamp(float v, float lo, float hi)
{
    float t;
    if (v > hi) {
        t = hi;
    } else {
        t = v;
    }
    float r;
    if (t < lo) {
        r = lo;
    } else {
        r = t;
    }
    return r;
}

struct Seg_00101F60 {
    Vector p0;
    Vector p1;
};

extern "C" int func_00101F60(Seg_00101F60* a, Seg_00101F60* b, Vector* pa, Vector* pb, float* mua, float* mub, int clamp)
{
    const Vector& ae = a->p1;
    Vector p13;
    Vector p43;
    Vector p21;
    p13 = a->p0 - b->p0;
    p43 = b->p1 - b->p0;
    if (fabsf(p43.x) < 0.00001f && fabsf(p43.y) < 0.00001f && fabsf(p43.z) < 0.00001f) {
        return 0;
    }
    p21 = ae - a->p0;
    if (fabsf(p21.x) < 0.00001f && fabsf(p21.y) < 0.00001f && fabsf(p21.z) < 0.00001f) {
        return 0;
    }
    float d1343 = Dot(p13, p43);
    float d4321 = Dot(p43, p21);
    float d1321 = Dot(p13, p21);
    float d4343 = Dot(p43, p43);
    float d2121 = Dot(p21, p21);
    float denom = d2121 * d4343 - d4321 * d4321;
    if (fabsf(denom) < 0.00001f) {
        return 0;
    }
    *mua = (d1343 * d4321 - d1321 * d4343) / denom;
    if (clamp) {
        *mua = Clamp(*mua, 0.0f, 1.0f);
    }
    *mub = (d1343 + d4321 * *mua) / d4343;
    if (clamp) {
        *mub = Clamp(*mub, 0.0f, 1.0f);
    }
    *pa = Add(a->p0, Scale(p21, *mua));
    *pb = Add(b->p0, Scale(p43, *mub));
    return 1;
}
