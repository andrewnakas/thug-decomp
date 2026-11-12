/* fuzzy: 71.2 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0019AD48 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019AD48() {}
    Vec_0019AD48(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019AD48& operator+=(const Vec_0019AD48& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_0019AD48& operator-=(const Vec_0019AD48& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline Vec_0019AD48 operator+(const Vec_0019AD48& a, const Vec_0019AD48& b)
{
    return Vec_0019AD48(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_0019AD48 operator-(const Vec_0019AD48& a, const Vec_0019AD48& b)
{
    return Vec_0019AD48(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0019AD48 operator*(const Vec_0019AD48& v, float s)
{
    return Vec_0019AD48(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline float Dot_0019AD48(const Vec_0019AD48& a, const Vec_0019AD48& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vec_0019AD48 Bounce_0019AD48(const Vec_0019AD48& v, float k, const Vec_0019AD48& n)
{
    float vx = v.x * k;
    float vy = v.y * k;
    float vz = v.z * k;
    float vw = v.w * k;
    float d = 2.0f * (vx * n.x + vy * n.y + vz * n.z);
    Vec_0019AD48 r = n * d;
    return Vec_0019AD48(vx - r.x, vy - r.y, vz - r.z, vw - r.w);
}

extern "C" void func_00183CB8(int obj, int* ref);

struct Feeler_0019AD48 {
    Vec_0019AD48 m_start;
    Vec_0019AD48 m_end;
    char pad20[0x90 - 0x20];
    float m_dist;
    char pad94[0xA0 - 0x94];
    Vec_0019AD48 m_point;
    Vec_0019AD48 m_normal;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_0019AD48()
    {
        if (m_ref) {
            func_00183CB8(m_ref, &m_ref);
            m_ref = 0;
        }
    }
};

extern "C" void func_00209280(Feeler_0019AD48* f, const Vec_0019AD48& start, const Vec_0019AD48& end);
extern "C" int func_002093E8(Feeler_0019AD48* f, int a, int b);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_0018DF70(int obj, Feeler_0019AD48* f);
extern char D_00362060[];
extern char D_0036207F[];
extern char D_003620F0[];
extern char D_00362108[];

struct Obj_0019AD48 {
    char pad0[0x20];
    Vec_0019AD48 m_pos;
    Vec_0019AD48 m_vel;
    char pad40[0x137C - 0x40];
    int m137C;
    void Move(const Vec_0019AD48& delta);
};

void Obj_0019AD48::Move(const Vec_0019AD48& delta)
{
    Vec_0019AD48 old = m_pos;
    Feeler_0019AD48 f;
    func_00209280(&f, m_pos, Vec_0019AD48(m_pos.x + delta.x, m_pos.y + delta.y, m_pos.z + delta.z, m_pos.w + delta.w));
    if (func_002093E8(&f, 0, 0)) {
        func_00103F28(D_00362060, D_0036207F, 0xAF1, D_003620F0);
        m_pos = f.m_point + f.m_normal;
        m_pos += Bounce_0019AD48(delta, f.m_dist, f.m_normal);
        m_vel -= f.m_normal * (Dot_0019AD48(m_vel, f.m_normal) * 1.5f);
    } else {
        m_pos += delta;
    }
    f.m_start = m_pos;
    f.m_end = m_pos;
    f.m_end.y -= 4800.0f;
    if (!func_002093E8(&f, 0, 0)) {
        func_00103F28(D_00362060, D_0036207F, 0xB07, D_00362108);
        m_pos = old;
    } else {
        func_0018DF70(m137C, &f);
    }
}
