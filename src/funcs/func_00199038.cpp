struct Wheel_00199038 {
    char pad0[0x8];
    float m8;
    char padC[0xB4 - 0xC];
    float mB4;
    char padB8[0xE4 - 0xB8];
    float mE4;
    char padE8[0x10C - 0xE8];
    float m10C;
    float m110;
    char pad114[0x220 - 0x114];
};

struct Obj_00199038 {
    char pad0[0x160];
    float m_dt;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00199038* m_wheels;
    char pad31C[0x354 - 0x31C];
    int m354;
    void Fn();
};

void Obj_00199038::Fn()
{
    if (!m354)
        return;
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00199038* w = &m_wheels[i];
        if (w->m10C == 0.0f)
            continue;
        float lim = w->m10C;
        float v = w->m8;
        float dt = m_dt;
        float a = __builtin_fabsf(-v / (dt * w->mE4));
        if (a < lim)
            lim = a;
        float s = lim;
        if (v >= 0.0f)
            s = -lim;
        float t = w->mE4 * s;
        w->mB4 += t;
        w->m8 = v + t * dt;
    }
}
