typedef int qword __attribute__((mode(TI)));

struct Vec_00198518 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00198518() {}
    Vec_00198518(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00198518& operator+=(const Vec_00198518& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_00198518 Cross_00198518(const Vec_00198518& a, const Vec_00198518& b)
{
    return Vec_00198518(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Wheel_00198518 {
    float m_len;
    int m_state;
    char pad8[0x20 - 0x8];
    Vec_00198518 m_pos;
    Vec_00198518 m_vel;
    float m_avg;
    float m_hist[10];
    char pad6C[0x70 - 0x6C];
    Vec_00198518 m_normal;
    char pad80[0xD8 - 0x80];
    float m_rest;
    char padDC[0xE8 - 0xDC];
    float m_spring;
    float m_damp;
    char padF0[0x220 - 0xF0];
};

struct Obj_00198518 {
    char pad0[0x80];
    Vec_00198518 m80;
    char pad90[0x110 - 0x90];
    Vec_00198518 m_pos;
    char pad120[0x124 - 0x120];
    signed char m_histIdx;
    char pad125[0x140 - 0x125];
    Vec_00198518 m_force;
    Vec_00198518 m_torque;
    char pad160[0x180 - 0x160];
    float m180;
    char pad184[0x1C4 - 0x184];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00198518* m_wheels;
    void UpdateSuspension();
};

void Obj_00198518::UpdateSuspension()
{
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00198518* w = &m_wheels[i];
        if (w->m_state == 1) {
            w->m_hist[m_histIdx] = (386.4f / m180) / (float)(unsigned int)m_numWheels;
        } else {
            Vec_00198518 g = m80;
            float f = -w->m_spring * (w->m_rest - w->m_len)
                    * (w->m_normal.x * g.x + w->m_normal.y * g.y + w->m_normal.z * g.z)
                    + -w->m_damp * (w->m_vel.x * w->m_normal.x + w->m_vel.y * w->m_normal.y + w->m_vel.z * w->m_normal.z);
            Vec_00198518 F(w->m_normal.x * f, w->m_normal.y * f, w->m_normal.z * f, w->m_normal.w * f);
            m_force += F;
            m_torque += Cross_00198518(Vec_00198518(w->m_pos.x - m_pos.x, w->m_pos.y - m_pos.y, w->m_pos.z - m_pos.z, w->m_pos.w - m_pos.w), F);
            w->m_hist[m_histIdx] = f;
            w->m_avg = 0.0f;
            for (int j = 9; j != -1; j--) {
                w->m_avg += w->m_hist[j];
            }
            w->m_avg *= 0.1f;
        }
    }
    m_histIdx++;
    m_histIdx %= 10;
}
