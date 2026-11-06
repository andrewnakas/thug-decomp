struct Wheel_00198F80 {
    char pad0[0x8];
    float m8;
    char padC[0xB4 - 0xC];
    float mB4;
    char padB8[0xE4 - 0xB8];
    float mE4;
    char padE8[0x10C - 0xE8];
    float m10C;
    float m110;
    float m114;
    char pad118[0x220 - 0x118];
};

struct Obj_00198F80 {
    char pad0[0x160];
    float m_dt;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00198F80* m_wheels;
    char pad31C[0x354 - 0x31C];
    int m354;
    void Fn(float k);
};

void Obj_00198F80::Fn(float k)
{
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00198F80* w = &m_wheels[i];
        float a = __builtin_fabsf(-w->m8 / (m_dt * w->mE4));
        float lim = k * w->m114;
        if (a < lim) {
            w->m10C = lim - a;
            lim = a;
        } else {
            w->m10C = 0.0f;
        }
        float s = lim;
        if (w->m8 >= 0.0f)
            s = -lim;
        float t = w->mE4 * s;
        w->m8 += t * m_dt;
        w->mB4 += t;
    }
}
