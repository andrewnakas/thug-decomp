typedef int qword __attribute__((mode(TI)));

struct Vec_00101820 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00101820() {}
    Vec_00101820(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_00101820 operator*(const Vec_00101820& a, float s)
{
    return Vec_00101820(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" float sqrtf(float);

extern "C" Vec_00101820* func_00101820(Vec_00101820* v, const Vec_00101820* n)
{
    *v = *n * sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    return v;
}
