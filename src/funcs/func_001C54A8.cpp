typedef int qword __attribute__((mode(TI)));

struct Vec_001C54A8 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
        float c[4];
    };
    Vec_001C54A8() {}
    Vec_001C54A8(const Vec_001C54A8& o) { q = o.q; }
    Vec_001C54A8(float ax, float ay, float az, float aw)
    {
        c[0] = ax;
        c[1] = ay;
        c[2] = az;
        c[3] = aw;
    }
    Vec_001C54A8& operator=(const Vec_001C54A8& o)
    {
        q = o.q;
        return *this;
    }
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float LengthSqr() const { return x * x + y * y + z * z; }
    void operator+=(const Vec_001C54A8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Vec_001C54A8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

inline Vec_001C54A8 operator+(const Vec_001C54A8& a, const Vec_001C54A8& b)
{
    return Vec_001C54A8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

inline Vec_001C54A8 operator-(const Vec_001C54A8& a, const Vec_001C54A8& b)
{
    return Vec_001C54A8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

inline Vec_001C54A8 operator*(const Vec_001C54A8& a, float s)
{
    return Vec_001C54A8(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

extern "C" void func_00183CB8(int obj, int* ref);

struct Ref_001C54A8 {
    int p;
    ~Ref_001C54A8()
    {
        if (p) {
            func_00183CB8(p, &p);
            p = 0;
        }
    }
};

struct Feeler_001C54A8 {
    Vec_001C54A8 m_start;
    Vec_001C54A8 m_end;
    char pad20[0xA0 - 0x20];
    Vec_001C54A8 m_point;
    Vec_001C54A8 m_normal;
    Ref_001C54A8 m_ref;
    char padC4[0xE0 - 0xC4];
};

extern "C" float sqrtf(float);
extern "C" void func_00209240(Feeler_001C54A8* f);
extern "C" int func_002093E8(Feeler_001C54A8* f, int a, int b);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" double func_0033ECA8(float x);
extern char D_00363408[];
extern char D_00363427[];
extern char D_00363548[];
extern char D_00363578[];
extern char D_003635A8[];

struct Sk_001C54A8 {
    char pad0[0x1C];
    int m_state;
    char pad20[0x30 - 0x20];
    Vec_001C54A8 m_pos;
    char pad40[0x80 - 0x40];
    Vec_001C54A8 m_old;
    char pad90[0x98 - 0x90];
    float m98;
    char pad9C[0x970 - 0x9C];
    Vec_001C54A8 m_push;
    char pad980[0xBC0 - 0x980];
    int m_planeOn;
    char padBC4[0xBD0 - 0xBC4];
    Vec_001C54A8 m_planeN;
    float m_planeD;
    void Push();
    float PlaneDist(const Vec_001C54A8& q) const { return q.x * m_planeN.x + q.y * m_planeN.y + q.z * m_planeN.z - m_planeD; }
};

void Sk_001C54A8::Push()
{
    float len2 = m_push.LengthSqr();
    if (len2 == 0.0f) return;
    switch (m_state) {
    case 0:
    case 1:
    case 3: {
        float len = sqrtf(len2);
        float max = m98 * 1000.0f;
        Vec_001C54A8 d = m_push;
        if (max < len) {
            m_push -= m_push * (max / len);
        } else {
            m_push.Set(0.0f, 0.0f, 0.0f, 1.0f);
        }
        if (m_state == 3) break;
        Feeler_001C54A8 f;
        func_00209240(&f);
        f.m_start = m_old + d;
        f.m_end = m_pos + m_push;
        if (func_002093E8(&f, 1, 0)) {
            Vec_001C54A8 p = f.m_point + f.m_normal * 0.1f;
            Vec_001C54A8 delta = p - f.m_end;
            m_pos += delta;
            func_00103F28(D_00363408, D_00363427, 0xAE2, D_00363548);
            func_00103F28(D_00363578, D_00363427, 0xAE3, func_0033ECA8(delta.x), func_0033ECA8(delta.y),
                          func_0033ECA8(delta.z));
            func_00103F28(D_003635A8, D_00363427, 0xAE4, func_0033ECA8(m_push.x), func_0033ECA8(m_push.y),
                          func_0033ECA8(m_push.z));
        }
        if (m_planeOn) {
            float dist = PlaneDist(m_pos + m_push);
            if (dist > 0.0f) {
                m_pos -= m_planeN * dist;
            }
        }
        break;
    }
    case 2:
    case 4:
        break;
    }
}
