typedef int qword __attribute__((mode(TI)));

struct Vec_0027FF70 {
    union {
        float col[4];
        qword q;
    };
    Vec_0027FF70() {}
    Vec_0027FF70(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
    bool operator==(const Vec_0027FF70& b) const
    {
        return col[0] == b[0] && col[1] == b[1] && col[2] == b[2] && col[3] == b[3];
    }
};

static inline Vec_0027FF70 operator+(const Vec_0027FF70& a, const Vec_0027FF70& b)
{
    return Vec_0027FF70(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_0027FF70 operator-(const Vec_0027FF70& a, const Vec_0027FF70& b)
{
    return Vec_0027FF70(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Vec_0027FF70 operator*(const Vec_0027FF70& a, float s)
{
    return Vec_0027FF70(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}


struct Model_0027FF70 {
    char pad[0x70];
    Vec_0027FF70 m_70;
    Vec_0027FF70 m_80;
    Vec_0027FF70 m_90;
};

extern "C" float func_002032A0(unsigned int name, int def);
extern "C" void func_003233B8(Vec_0027FF70* d, Vec_0027FF70* s);
extern "C" void func_00100DC0(Vec_0027FF70* m, int axis);

struct Cam_0027FF70 {
    char pad0[0xC];
    Model_0027FF70* m_model;
    char pad10[0x20 - 0x10];
    Vec_0027FF70 m_20;
    Vec_0027FF70 m_30;
    Vec_0027FF70 m_40;
    Vec_0027FF70 m_50;
    Vec_0027FF70 m_60;
    Vec_0027FF70 m_70;
    Vec_0027FF70 m_80;
    float m_90;
    float m_94;

    void Update();
};

void Cam_0027FF70::Update()
{
    if (m_90 != 0.0f) {
        if (m_80 == m_70) {
            m_90 = 0.0f;
        } else {
            float t = m_90 - func_002032A0(0xD8120182, 0) * m_94 * 60.0f;
            m_90 = t;
            if (t <= 0.0f) {
                m_90 = 0.0f;
                m_60 = m_70;
            } else {
                m_60 = m_70 + (m_80 - m_70) * t;
                func_003233B8(&m_60, &m_60);
            }
        }
    }
    bool changed = !(m_30 == m_60);
    if (changed) {
        m_30 = m_60;
        func_00100DC0(&m_20, 1);
        m_20 = m_model->m_70;
        m_40 = m_model->m_90;
    }
}
