typedef int qword __attribute__((mode(TI)));

struct Vec_00101BC8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" void func_003233B8(Vec_00101BC8* dst, Vec_00101BC8* src);
extern "C" float func_003412F0(float x);

extern "C" float func_00101BC8(const Vec_00101BC8* a, const Vec_00101BC8* b)
{
    Vec_00101BC8 u;
    Vec_00101BC8 v;
    u.q = a->q;
    v.q = b->q;
    func_003233B8(&u, &u);
    func_003233B8(&v, &v);
    float d = u.x * v.x + u.y * v.y + u.z * v.z;
    if (d > 1.0f) d = 1.0f;
    if (d < -1.0f) d = -1.0f;
    return func_003412F0(d) * 57.29577637f;
}
