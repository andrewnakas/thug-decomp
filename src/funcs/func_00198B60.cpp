extern "C" float fabsf(float);
struct Obj_00198B60;
extern "C" int func_00197880(Obj_00198B60* self, float speed);

struct Wheel_00198B60 {
    int m0;
    int m_state;
    float m_speed;
    char padC[0xB4 - 0xC];
    float m_spin;
    char padB8[0xD4 - 0xB8];
    int m_grounded;
    char padD8[0xE4 - 0xD8];
    float m_ratio;
    char padE8[0x220 - 0xE8];
};

struct Obj_00198B60 {
    char pad0[0x160];
    float m160;
    char pad164[0x1C4 - 0x164];
    int m_count;
    unsigned int m1C8;
    char pad1CC[0x318 - 0x1CC];
    Wheel_00198B60* m_wheels;
    char pad31C[0x320 - 0x31C];
    float m320;
    char pad324[0x328 - 0x324];
    float m328[8];
    char pad348[0x350 - 0x348];
    int m350;
    int m354;
    char pad358[0x35C - 0x358];
    int m35C;
    void Brake();
};

void Obj_00198B60::Brake()
{
    if (m350) {
        return;
    }
    if (m35C) {
        return;
    }
    if (m354) {
        return;
    }
    int i = m_count;
    while (i-- != 0) {
        Wheel_00198B60* w = &m_wheels[i];
        if (w->m_grounded && w->m_state != 1) {
            float t = m328[func_00197880(this, fabsf(w->m_speed))];
            float d = m320 * t * t / (float)m1C8;
            float speed = w->m_speed;
            float k = m160;
            float r = w->m_ratio;
            float lim = fabsf(-speed / (k * r));
            if (lim < d) {
                d = lim;
            }
            float a = d;
            if (speed >= 0.0f) {
                a = -d;
            }
            float dv = r * a;
            w->m_spin += dv;
            w->m_speed = speed + dv * k;
        }
    }
}
