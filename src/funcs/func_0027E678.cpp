typedef int qword_0027E678 __attribute__((mode(TI)));

struct Vec_0027E678 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0027E678 q;
    };
};

struct Obj_0027E678 {
    char m_pad0[0x140];
    float m_maxSpeed;
    char m_pad144[0x160 - 0x144];
    Vec_0027E678 m_vel;
    char m_pad170[0x270 - 0x170];
    Vec_0027E678 m_start;
    Vec_0027E678 m_end;
    char m_pad290[0x340 - 0x290];
    Vec_0027E678 m_pos;
    float m_speed;
    char m_pad354[0x38C - 0x354];
    unsigned int m_time[2];
    void Launch(Vec_0027E678* start, Vec_0027E678* end, bool which);
};

extern "C" unsigned int func_0010FC30();
extern "C" bool func_0028E1C0(Obj_0027E678* self, int flags, int a);

void Obj_0027E678::Launch(Vec_0027E678* start, Vec_0027E678* end, bool which)
{
    for (int i = 0; i < 4; i++) {
        if (i != which) {
            unsigned int last = m_time[!which];
            if (func_0010FC30() - last > 500) {
                return;
            }
        }
    }
    m_start.q = start->q;
    m_end.q = end->q;
    if (!func_0028E1C0(this, 0x10, 0)) {
        return;
    }
    Vec_0027E678* pos = &m_pos;
    pos->x += m_vel.x;
    pos->y += m_vel.y;
    pos->z += m_vel.z;
    pos->w += m_vel.w;
    if (m_maxSpeed < m_speed) {
        m_speed = m_maxSpeed;
    }
    m_time[which] = func_0010FC30();
}
