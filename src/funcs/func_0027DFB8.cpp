typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_0027DFB8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    float LengthSqr() const { return x * x + y * y + z * z; }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_0027DFB8& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    Vec_0027DFB8& operator-=(const Vec_0027DFB8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline float Frames_0027DFB8(float t) { return t * 60.0f; }

struct Body_0027DFB8 {
    char pad[0xB0];
    Vec_0027DFB8 m_vel;
};

struct Obj_0027DFB8 {
    char pad0[0xC];
    Body_0027DFB8* m_body;
    char pad10[0x94 - 0x10];
    float m_94;
    char pad98[0x378 - 0x98];
    float m_378;

    void Damp();
};

void Obj_0027DFB8::Damp()
{
    Vec_0027DFB8* vel = &m_body->m_vel;
    Vec_0027DFB8 v = *vel;
    float len = v.Length();
    if (len < 0.0001f || (v *= m_378 * Frames_0027DFB8(m_94) / len, len * len < v.LengthSqr())) {
        vel->Set(0.0f, 0.0f, 0.0f, 1.0f);
        return;
    }
    *vel -= v;
}
