struct Wheel_00198CE8 {
    int m0;
    int m_state;
    float m_speed;
    char padC[0xB4 - 0xC];
    float m_spin;
    char padB8[0xD0 - 0xB8];
    int m_D0;
    int m_grounded;
    char padD8[0xE4 - 0xD8];
    float m_ratio;
    char padE8[0x220 - 0xE8];
};

struct Obj_00198CE8;

static inline float NegPart_00198CE8(float v)
{
    if (v < 0.0f) {
        return -v;
    }
    return 0.0f;
}
extern "C" int func_00197880(Obj_00198CE8* self, float speed);

struct Obj_00198CE8 {
    char pad0[0x84];
    float m84;
    char pad88[0x160 - 0x88];
    float m160;
    char pad164[0x1C4 - 0x164];
    int m_count;
    unsigned int m1C8;
    char pad1CC[0x318 - 0x1CC];
    Wheel_00198CE8* m_wheels;
    float m31C;
    char pad320[0x328 - 0x320];
    float m328[6];
    float m340;
    float m344;
    char pad348[0x350 - 0x348];
    int m350;
    int m354;
    int m358;
    int m35C;
    void Drive();
};

void Obj_00198CE8::Drive()
{
    float t = m84 * m84 * 1.111111164f;
    float f;
    if (1.0f < t) {
        f = 1.0f;
    } else {
        f = t;
    }
    if (!m350 && !m35C) {
        return;
    }
    if (m354) {
        return;
    }
    int i = m_count;
    while (i-- != 0) {
        Wheel_00198CE8* w = &m_wheels[i];
        if (!w->m_grounded) {
            continue;
        }
        if (m358 && w->m_D0) {
            continue;
        }
        int g;
        if (!m35C) {
            float s = w->m_speed;
            g = func_00197880(this, s > 0.0f ? s : 0.0f);
        } else {
            g = func_00197880(this, NegPart_00198CE8(w->m_speed));
        }
        float d = m31C * m344 * m328[g] / (float)m1C8;
        d *= f;
        if (m35C) {
            d *= -m340;
        }
        if (m358 && m1C8 == 4) {
            d += d;
        }
        float dv = w->m_ratio * d;
        w->m_speed += dv * m160;
        w->m_spin += dv;
    }
}
