typedef int qword_0027DAC8 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_0027DAC8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0027DAC8 q;
    };
    Vec_0027DAC8() {}
    Vec_0027DAC8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    Vec_0027DAC8& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    Vec_0027DAC8& operator+=(const Vec_0027DAC8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_0027DAC8 operator*(const Vec_0027DAC8& a, float s)
{
    return Vec_0027DAC8(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Body_0027DAC8 {
    char pad[0x90];
    Vec_0027DAC8 m_dir;
    char padA0[0x10];
    Vec_0027DAC8 m_vel;
};

struct State_0027DAC8 {
    char pad[0x28];
    int m28;
};

struct Skater_0027DAC8 {
    char pad0[0xC];
    Body_0027DAC8* m_body;
    char pad10[0x94 - 0x10];
    float m94;
    char pad98[0x400 - 0x98];
    int m400;
    char pad404[0x5B0 - 0x404];
    State_0027DAC8* m5B0;
};

extern "C" void func_003233B8(Vec_0027DAC8*, Vec_0027DAC8*);
extern "C" float func_00203D40(Body_0027DAC8*, unsigned int);

void func_0027DAC8(Skater_0027DAC8* self)
{
    Vec_0027DAC8 dir;
    if (self->m400) {
        dir = self->m_body->m_vel;
        if (dir.Length() < 0.5f)
            dir = self->m_body->m_dir;
        else
            func_003233B8(&dir, &dir);
    } else {
        dir = self->m_body->m_dir;
    }
    if (self->m5B0->m28)
        dir *= func_00203D40(self->m_body, 0x3D24128E);
    else
        dir *= func_00203D40(self->m_body, 0x5F9B864D);
    self->m_body->m_vel += dir * self->m94;
}
