extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_001980F0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001980F0() {}
    Vec_001980F0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    float LengthSqr() const { return x * x + y * y + z * z; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001980F0& operator-=(const Vec_001980F0& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline Vec_001980F0 operator*(const Vec_001980F0& v, float s)
{
    return Vec_001980F0(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern "C" void func_003233B8(Vec_001980F0* d, Vec_001980F0* s);

struct Obj_001980F0 {
    char pad0[0x50];
    Vec_001980F0 m_vel;
    char pad60[0x84 - 0x60];
    float m84;
    char pad88[0x120 - 0x88];
    unsigned int m_state;
    char pad124[0x134 - 0x124];
    float m134;
    char pad138[0x160 - 0x138];
    float m160;
    char pad164[0x1D8 - 0x164];
    float m1D8;
    float m1DC;
    char pad1E0[0x34C - 0x1E0];
    float m34C;
    int m350;
    int pad354;
    int m358;
    bool OnGround() { return m_state < 3; }
    bool Busy() { return m134 > 0.0f; }
    void Update();
};

void Obj_001980F0::Update()
{
    if (m358 && !OnGround()) return;
    if (m350 == 0 && m34C != 0.0f && !OnGround()) return;
    if (Busy()) return;
    float f = m160 * m1DC * m_vel.LengthSqr();
    if (m_vel.Length() < f) {
        m_vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
    } else {
        Vec_001980F0 n = m_vel;
        func_003233B8(&n, &n);
        m_vel -= n * f;
    }
    if (m34C == 0.0f && !OnGround() && m84 > 0.5f) {
        float& vy = m_vel.y;
        float fr = m160 * m1D8;
        if (__builtin_fabsf(vy) < __builtin_fabsf(fr)) {
            vy = 0.0f;
        } else {
            vy = vy > 0.0f ? vy - fr : vy + fr;
        }
    }
}
