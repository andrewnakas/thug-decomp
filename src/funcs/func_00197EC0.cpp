extern "C" float func_00341158(float);
extern "C" float func_003414F0(float, float);

struct Wheel_00197EC0 {
    char pad0[0x10];
    float m10;
    float m14;
    char pad18[0xD0 - 0x18];
    int m_type;
    char padD4[0x220 - 0xD4];
};

struct Obj_00197EC0 {
    char pad0[0x160];
    float m160;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    int pad1C8;
    float m1CC;
    float m1D0;
    float m1D4;
    char pad1D8[0x318 - 0x1D8];
    Wheel_00197EC0* m_wheels;
    char pad31C[0x34C - 0x31C];
    float m34C;
    char pad350[0x1354 - 0x350];
    float m1354;
    void Update();
};

static inline void Steer_00197EC0(Obj_00197EC0* o, float angle, float& a, float& b)
{
    if (__builtin_fabsf(angle) > 0.001f) {
        float r = o->m1D0 / func_00341158(angle * o->m1CC);
        if (r > 0.0f) {
            a = -func_003414F0(o->m1D0, r - o->m1D4 * 0.5f);
            b = -func_003414F0(o->m1D0, r + o->m1D4 * 0.5f);
        } else {
            r = -r;
            a = func_003414F0(o->m1D0, r + o->m1D4 * 0.5f);
            b = func_003414F0(o->m1D0, r - o->m1D4 * 0.5f);
        }
    } else {
        a = 0.0f;
        b = 0.0f;
    }
}

static inline float Lerp_00197EC0(float a, float b, float t)
{
    return a + (b - a) * t;
}

void Obj_00197EC0::Update()
{
    float b2, a2, b1, a1;
    m1354 = Lerp_00197EC0(m1354, m34C, m160 * 10.0f);
    Steer_00197EC0(this, m34C, a1, b1);
    Steer_00197EC0(this, m1354, a2, b2);
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00197EC0* w = &m_wheels[i];
        int t = w->m_type;
        if (t != 0) {
            float s = b1;
            if (t == 1) s = a1;
            w->m10 = s;
            s = b2;
            if (t == 1) s = a2;
            w->m14 = s;
        }
    }
}
