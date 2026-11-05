typedef int qword __attribute__((mode(TI)));

struct Vec_001016A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001016A8() {}
    Vec_001016A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_001016A8& operator-=(const Vec_001016A8& b)
    {
        x -= b.x; y -= b.y; z -= b.z; w -= b.w;
        return *this;
    }
};

static inline Vec_001016A8 operator*(const Vec_001016A8& a, float s)
{
    return Vec_001016A8(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" Vec_001016A8* func_001016A8(Vec_001016A8* v, const Vec_001016A8* n)
{
    float d = v->x * n->x + v->y * n->y + v->z * n->z;
    *v -= *n * d;
    return v;
}
