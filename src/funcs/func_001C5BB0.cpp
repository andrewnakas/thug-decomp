typedef int qword_001C5BB0 __attribute__((mode(TI)));

struct Vec_001C5BB0 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001C5BB0 q;
    };
    Vec_001C5BB0() {}
    Vec_001C5BB0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const;
};

extern "C" float sqrtf(float);

inline float Vec_001C5BB0::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

extern "C" void func_003233B8(Vec_001C5BB0* d, Vec_001C5BB0* s);

struct Obj_001C5BB0 {
    char pad0[0x50];
    Vec_001C5BB0 m_pos;
    char pad60[0x80 - 0x60];
    Vec_001C5BB0 m_at;
    Vec_001C5BB0 m_up;
    char padA0[0xB0 - 0xA0];
    Vec_001C5BB0 m_vel;
};

struct Walk_001C5BB0 {
    char pad0[0xC];
    Obj_001C5BB0* m_obj;
    char pad10[0x30 - 0x10];
    Vec_001C5BB0 m_pos;
    Vec_001C5BB0 m_vel;
    float m_speed;
    char pad54[0xC];
    Vec_001C5BB0 m_up;
    Vec_001C5BB0 m_at;
    char pad80[0x9A0 - 0x80];
    float m_upY;
    void Sync();
};

void Walk_001C5BB0::Sync()
{
    Obj_001C5BB0* o = m_obj;
    m_pos.q = o->m_pos.q;
    m_vel.q = o->m_vel.q;
    m_vel.y = 0.0f;
    m_speed = o->m_vel.y;
    m_at.q = o->m_at.q;
    m_up.q = o->m_up.q;
    m_upY = m_up.y;
    m_up.y = 0.0f;
    Vec_001C5BB0* up = &m_up;
    float len = up->Length();
    Vec_001C5BB0* at = &m_at;
    if (len < 0.001f) {
        m_up.q = Vec_001C5BB0(-o->m_at.x, -o->m_at.y, -o->m_at.z, -o->m_at.w).q;
        m_up.y = 0.0f;
        func_003233B8(up, up);
        m_at.y += 0.01f;
        func_003233B8(at, at);
    } else {
        float s = 1.0f / len;
        up->x *= s;
        up->y *= s;
        up->z *= s;
        up->w *= s;
    }
}
