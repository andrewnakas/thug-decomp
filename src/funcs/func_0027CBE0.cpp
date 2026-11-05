typedef int qword_0027CBE0 __attribute__((mode(TI)));

extern "C" float sqrtf(float x);

struct Vec_0027CBE0 {
    union {
        struct {
            float x, y, z, w;
        } f;
        qword_0027CBE0 q;
    } u;
    float LengthSqr() const { return u.f.x * u.f.x + u.f.y * u.f.y + u.f.z * u.f.z; }
    void SetLength(float len)
    {
        float l = sqrtf(LengthSqr());
        if (l > 0.0f) {
            float s = len / l;
            u.f.x *= s;
            u.f.y *= s;
            u.f.z *= s;
        }
    }
    void Set(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
    Vec_0027CBE0& operator-=(const Vec_0027CBE0& o)
    {
        u.f.x -= o.u.f.x;
        u.f.y -= o.u.f.y;
        u.f.z -= o.u.f.z;
        u.f.w -= o.u.f.w;
        return *this;
    }
};

struct Body_0027CBE0 {
    char m_pad[0xB0];
    Vec_0027CBE0 m_vel;
};

struct Obj_0027CBE0 {
    char m_pad[0xC];
    Body_0027CBE0* m_body;
    char m_pad10[0x94 - 0x10];
    float m_drag;
    void Damp(float dt);
};

void Obj_0027CBE0::Damp(float dt)
{
    float len2 = m_body->m_vel.LengthSqr();
    if (len2 < 0.00001f)
        return;
    Vec_0027CBE0 d = m_body->m_vel;
    float drag = m_drag * 60.0f;
    d.SetLength(dt * drag * len2);
    if (len2 < d.LengthSqr())
        m_body->m_vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
    else
        m_body->m_vel -= d;
}
