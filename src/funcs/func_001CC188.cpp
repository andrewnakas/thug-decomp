typedef int qword_001CC188 __attribute__((mode(TI)));

struct Vec_001CC188 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001CC188 q;
    };
    Vec_001CC188() {}
    Vec_001CC188(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_001CC188& operator-=(const Vec_001CC188& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline Vec_001CC188 operator-(const Vec_001CC188& a, const Vec_001CC188& b)
{
    return Vec_001CC188(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001CC188 operator*(const Vec_001CC188& a, float s)
{
    return Vec_001CC188(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct State_001CC188 {
    char pad[0x20];
    Vec_001CC188 m_vel;
    Vec_001CC188 ScaledVel(float s) const
    {
        return Vec_001CC188(m_vel.x * s, m_vel.y * s, m_vel.z * s, m_vel.w * s);
    }
};

struct Out_001CC188 {
    Vec_001CC188 m_pos;
    Vec_001CC188 m_vel;
};

extern "C" void* func_001E5548(unsigned int, int);
extern "C" bool func_001E7EB0(void*, unsigned int, float*, int);
extern "C" void func_003233B8(Vec_001CC188*, Vec_001CC188*);

static inline float GetPhysics_001CC188(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

bool func_001CC188(void* self, Vec_001CC188* from, Vec_001CC188* to, State_001CC188* st, Out_001CC188* out)
{
    if (from->y > to->y)
        return false;
    Vec_001CC188 dir = *to - *from;
    func_003233B8(&dir, &dir);
    if (dir.y < 0.9950000048f)
        return false;
    out->m_pos = *to - dir * GetPhysics_001CC188(0x76BF49E0);
    out->m_pos -= st->ScaledVel(GetPhysics_001CC188(0x35B3BBDA));
    out->m_vel = st->m_vel;
    return true;
}
