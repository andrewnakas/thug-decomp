extern "C" float sqrtf(float);

struct Vec_0013B108 {
    float x, y, z, w;
    Vec_0013B108() {}
    Vec_0013B108(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float LengthSqr() const { return x * x + y * y + z * z; }
};

static inline Vec_0013B108 operator-(const Vec_0013B108& a, const Vec_0013B108& b)
{
    return Vec_0013B108(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

extern "C" int func_0013B248();
extern "C" void* func_0013B0E8(int i);
extern "C" Vec_0013B108* func_00114E18(void* o);

extern "C" void* func_0013B108(Vec_0013B108* p, float* dist)
{
    int i = 0;
    void* found = 0;
    float best = -1.0f;
    int n = func_0013B248();
    for (; i < n; i++) {
        void* o = func_0013B0E8(i);
        if (!o) {
            continue;
        }
        Vec_0013B108 d = *p - *func_00114E18(o);
        float d2 = d.LengthSqr();
        if (best < 0.0f || d2 < best) {
            best = d2;
            found = o;
        }
    }
    if (!found) {
        return 0;
    }
    if (dist) {
        *dist = sqrtf(best);
    }
    return found;
}
