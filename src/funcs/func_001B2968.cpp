typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_001B2968 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B2968() {}
    Vec_001B2968(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001B2968 Sub_001B2968(const Vec_001B2968& a, const Vec_001B2968& b)
{
    return Vec_001B2968(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Obj_001B2968 {
    char pad0[0x30];
    float m_30;
};

struct Node_001B2968 {
    char pad0[0x50];
    Vec_001B2968 m_pos;
};

struct C_001B2968;
extern "C" float func_001E5318(unsigned int name, int flag);
extern "C" int func_001E53A0(unsigned int name, int flag);
extern "C" void func_001B3508(C_001B2968* self);
extern "C" void func_001B3538(C_001B2968* self);
extern "C" Obj_001B2968* func_00185578(Node_001B2968* node, unsigned int name);
extern "C" float func_00101BC8(Vec_001B2968* a, Vec_001B2968* b);
extern "C" float func_00340F60(float x);
extern "C" void func_001B2ED8(C_001B2968* self, Vec_001B2968 target, float w);

struct C_001B2968 {
    char pad0[0xC];
    Node_001B2968* m_node;
    char pad1[0x20 - 0x10];
    int m_flags;
    char pad2[0x44 - 0x24];
    int m_prev;
    int m_cur;
    int m_next;
    Vec_001B2968 m_prevPos;
    Vec_001B2968 m_curPos;
    Vec_001B2968 m_nextPos;
    int m_80;
    int m_84;
    int Steer();
};

int C_001B2968::Steer()
{
    int turning = 0;
    Vec_001B2968 a = m_curPos;
    a.y = 0.0f;
    Vec_001B2968 b = m_node->m_pos;
    b.y = 0.0f;
    Vec_001B2968 d = Sub_001B2968(b, a);
    float dist2 = d.x * d.x + d.z * d.z;
    float w = func_001E5318(0x57342672, 1);
    func_001B3508(this);
    if (m_next == m_prev) {
        if (dist2 <= func_001E5318(0x65B46F32, 1)) func_001B3538(this);
    } else {
        int r;
        if (m_flags & 1) {
            r = func_001E53A0(0x354BEDA1, 1);
        } else {
            r = func_001E53A0(0x5B21AB0E, 1);
        }
        if (m_84 != 0 && m_80 >= m_84) {
            func_001B3538(this);
        } else if (m_next != -1 && dist2 < (float)r) {
            if (m_84 == 0) {
                float k = dist2 + dist2;
                Obj_001B2968* o = func_00185578(m_node, 0x0A015E17);
                Vec_001B2968 p0 = m_prevPos;
                Vec_001B2968 p1 = m_curPos;
                Vec_001B2968 p2 = m_nextPos;
                p0.y = 0.0f;
                p1.y = 0.0f;
                p2.y = 0.0f;
                Vec_001B2968 e1 = Sub_001B2968(p1, p0);
                Vec_001B2968 e2 = Sub_001B2968(p2, p1);
                float s = func_00340F60(func_00101BC8(&e1, &e2) * 0.0174532942f);
                m_84 = (int)(sqrtf(sqrtf(s * k + k)) / o->m_30 * 60.0f);
                if (m_84 <= 0) m_84 = 1;
            }
            turning = 1;
            float f;
            if (m_84 == 0) {
                f = 0.0f;
            } else {
                f = (1.0f - (float)(m_84 - m_80) / (float)m_84) * 0.5f;
            }
            float step = w * f;
            m_80++;
            func_001B2ED8(this, m_nextPos, step);
            w -= step;
        }
    }
    func_001B2ED8(this, m_curPos, w);
    return turning;
}
