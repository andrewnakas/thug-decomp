struct Wheel_00196B40 {
    char pad0[0x8];
    float m_speed;
    float m_angle;
    char pad10[0xB4 - 0x10];
    float m_accel;
    float Half() const { return m_accel * 0.5f; }
    char padB8[0x220 - 0xB8];
};

struct Obj_00196B40 {
    char pad0[0x160];
    float m_dt;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00196B40* m_wheels;
    void Fn();
};

void Obj_00196B40::Fn()
{
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00196B40* w = &m_wheels[i];
        w->m_angle += m_dt * (w->m_speed - m_dt * w->Half());
        if (w->m_angle > 628.31854f)
            w->m_angle -= 314.15927f;
        else if (w->m_angle < 0.0f)
            w->m_angle += 314.15927f;
    }
}
