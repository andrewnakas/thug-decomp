typedef int qword_001CE918 __attribute__((mode(TI)));

struct Vec_001CE918 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001CE918 q;
    };
    Vec_001CE918() {}
    Vec_001CE918(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_001CE918 operator*(const Vec_001CE918& a, float s)
{
    return Vec_001CE918(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline Vec_001CE918 operator+(const Vec_001CE918& a, const Vec_001CE918& b)
{
    return Vec_001CE918(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Obj_001CE918 {
    char pad[0xB0];
    Vec_001CE918 m_vel;
    Vec_001CE918 ScaledVel(float t) const
    {
        return Vec_001CE918(m_vel.x * t, m_vel.y * t, m_vel.z * t, m_vel.w * t);
    }
};

extern "C" Obj_001CE918* func_001CEA68(void*, Vec_001CE918*, Vec_001CE918*);
extern "C" float func_0010FAB8();

Obj_001CE918* func_001CE918(void* self, Vec_001CE918* pos, Vec_001CE918* dest)
{
    Vec_001CE918 hit;
    Vec_001CE918 hit2;
    Obj_001CE918* obj = func_001CEA68(self, pos, &hit);
    if (!obj)
        return 0;
    if (!func_001CEA68(self, dest, &hit2)) {
        *pos = *dest;
    } else {
        Vec_001CE918 p = *pos + obj->ScaledVel(func_0010FAB8()) * 2.0f;
        if (!func_001CEA68(self, &p, &hit2)) {
            *pos = p;
        } else {
            *pos = hit;
            pos->y += 1.0f;
        }
    }
    return obj;
}
