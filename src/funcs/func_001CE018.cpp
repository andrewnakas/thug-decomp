typedef int qword_001CE018 __attribute__((mode(TI)));

struct Vec_001CE018 {
    union {
        qword_001CE018 q;
        struct {
            float x, y, z, w;
        } f;
    };
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Params_001CE018 {
    char pad0[0xE0];
    float m_lagXZ;
    float m_lagY;
};

struct Target_001CE018 {
    char pad0[0x50];
    Vec_001CE018 m_pos;
};

extern "C" float func_0010FAB8();
extern "C" float func_0018B1D0(float rate, float dt);

static inline float Lerp_001CE018(float a, float b, float t)
{
    return a + (b - a) * t;
}

struct Cam_001CE018 {
    char pad0[0x30];
    Vec_001CE018 m_pos;
    char pad40[0x6C];
    Params_001CE018* m_params;
    Target_001CE018* m_target;

    Vec_001CE018 UpdatePos(bool snap);
};

Vec_001CE018 Cam_001CE018::UpdatePos(bool snap)
{
    if (snap) {
        m_pos = m_target->m_pos;
    } else {
        float kxz = func_0018B1D0(m_params->m_lagXZ, func_0010FAB8());
        float ky = func_0018B1D0(m_params->m_lagY, func_0010FAB8());
        m_pos.Set(Lerp_001CE018(m_pos.f.x, m_target->m_pos.f.x, kxz), Lerp_001CE018(m_pos.f.y, m_target->m_pos.f.y, ky),
                  Lerp_001CE018(m_pos.f.z, m_target->m_pos.f.z, kxz), 1.0f);
    }
    return m_pos;
}
