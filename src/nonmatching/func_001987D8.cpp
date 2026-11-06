/* fuzzy: 93.8 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_001987D8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001987D8() {}
    Vec_001987D8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001987D8& operator+=(const Vec_001987D8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_001987D8& operator-=(const Vec_001987D8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline Vec_001987D8 operator*(const Vec_001987D8& v, float s)
{
    return Vec_001987D8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_001987D8 operator+(const Vec_001987D8& a, const Vec_001987D8& b)
{
    return Vec_001987D8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline float Dot_001987D8(const Vec_001987D8& a, const Vec_001987D8& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vec_001987D8 Cross_001987D8(const Vec_001987D8& a, const Vec_001987D8& b)
{
    return Vec_001987D8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

extern "C" void func_003233B8(Vec_001987D8* d, Vec_001987D8* s);

struct Wheel_001987D8 {
    float m0;
    int m_state;
    float m_spin;
    char padC[0x20 - 0xC];
    Vec_001987D8 m_pos;
    char pad30[0x40 - 0x30];
    float m40;
    char pad44[0x80 - 0x44];
    float m80;
    char pad84[0xB0 - 0x84];
    float m_slip;
    float mB4;
    char padB8[0xE0 - 0xB8];
    float m_radius;
    float mE4;
    char padE8[0x120 - 0xE8];
    Vec_001987D8 m_dir;
    Vec_001987D8 m_vel;
    char pad140[0x220 - 0x140];
};

struct Obj_001987D8 {
    char pad0[0x110];
    Vec_001987D8 m_pos;
    char pad120[0x140 - 0x120];
    Vec_001987D8 m_force;
    Vec_001987D8 m_torque;
    float m_dt;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_001987D8* m_wheels;
    void UpdateFriction();
};

void Obj_001987D8::UpdateFriction()
{
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_001987D8* w = &m_wheels[i];
        if (w->m_state == 1) continue;
        Vec_001987D8 dir = w->m_dir;
        Vec_001987D8 vel = w->m_vel;
        Vec_001987D8 tmp = dir * (w->m_spin * w->m_radius);
        vel -= tmp;
        float len = sqrtf(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
        w->m_slip = len;
        if (len < 1e-6f) continue;
        tmp = vel;
        func_003233B8(&tmp, &tmp);
        Vec_001987D8 F = tmp * (-w->m80 * w->m40);
        float dotF = Dot_001987D8(F, dir);
        float a = -w->m_radius * dotF;
        float c = -(Dot_001987D8(vel, dir) / w->m_radius) / (m_dt * w->mE4);
        float b = -c;
        float s;
        Vec_001987D8 force;
        if (__builtin_fabsf(a) < __builtin_fabsf(b)) {
            s = a;
            force = F;
        } else {
            s = b;
            force = F + dir * (c / w->m_radius - dotF);
        }
        m_force += force;
        m_torque += Cross_001987D8(Vec_001987D8(w->m_pos.x - m_pos.x, w->m_pos.y - m_pos.y, w->m_pos.z - m_pos.z, w->m_pos.w - m_pos.w), force);
        s *= w->mE4;
        float u = s * m_dt;
        w->mB4 += s;
        w->m_spin += u;
    }
}
