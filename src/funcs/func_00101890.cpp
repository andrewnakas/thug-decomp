typedef int qword __attribute__((mode(TI)));

struct Vec_00101890 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00101890() {}
    Vec_00101890(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_00101890 operator*(const Vec_00101890& a, float s)
{
    return Vec_00101890(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" float sqrtf(float);

extern "C" Vec_00101890* func_00101890(Vec_00101890* v, const Vec_00101890* n)
{
    *v = *n * (v->x * n->x + v->y * n->y + v->z * n->z);
    return v;
}
