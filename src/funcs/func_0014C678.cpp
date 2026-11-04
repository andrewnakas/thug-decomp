typedef int qword __attribute__((mode(TI)));

struct Vec {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec() {}
    Vec(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern "C" float sqrtf(float);

struct Obj_0014C678;
extern "C" Vec func_0013C5E0(Obj_0014C678* o);

inline Vec operator+(const Vec& a, const Vec& b)
{
    return Vec(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec operator-(const Vec& a, const Vec& b)
{
    return Vec(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vec operator*(const Vec& a, float s)
{
    return Vec(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Group_0014C678 {
    char pad0[0x10];
    Obj_0014C678* m_items[1];
    char pad1[0x19E];
    short m_count;
};

Vec func_0014C678(Group_0014C678* g)
{
    if (g->m_count == 0) {
        return Vec(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Vec s;
    Vec t;
    Vec sum;
    Vec d;
    s = func_0013C5E0(g->m_items[0]);
    for (int i = 1; i < g->m_count; i++) {
        t = func_0013C5E0(g->m_items[i]);
        d = t - s;
        float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        if (len + t.w <= s.w) continue;
        if (len + s.w <= t.w) {
            s = t;
        } else {
            sum = s + t;
            s = (sum + d * (d.w / len)) * 0.5f;
            s.w = (len + sum.w) * 0.5f;
        }
    }
    return s;
}
