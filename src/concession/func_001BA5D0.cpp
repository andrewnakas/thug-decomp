/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 25, "first": [87, 81]} */
typedef int qword_001BA5D0 __attribute__((mode(TI)));

struct Vec_001BA5D0 {
    float x, y, z, w;
    Vec_001BA5D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Quat_001BA5D0 {
    union {
        qword_001BA5D0 q;
        struct {
            float x, y, z, w;
        };
    };
    Quat_001BA5D0()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
    Quat_001BA5D0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" void func_001BA6A8(Quat_001BA5D0* a, Quat_001BA5D0* b);

Vec_001BA5D0 Rotate_001BA5D0(const Quat_001BA5D0& q, const Vec_001BA5D0& v)
{
    Quat_001BA5D0 c;
    Quat_001BA5D0 p(v.x, v.y, v.z, 1.0f);
    c.x = -q.x;
    c.y = -q.y;
    c.z = -q.z;
    Quat_001BA5D0 r = q;
    c.w = q.w;
    func_001BA6A8(&r, &p);
    func_001BA6A8(&r, &c);
    return Vec_001BA5D0(r.x, r.y, r.z, r.w);
}
