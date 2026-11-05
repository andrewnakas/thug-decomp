typedef int qword __attribute__((mode(TI)));

struct Vec_0027FDB0 {
    union {
        float col[4];
        qword q;
    };
    Vec_0027FDB0() {}
    Vec_0027FDB0(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
    void Set(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
};

static inline Vec_0027FDB0 operator+(const Vec_0027FDB0& a, const Vec_0027FDB0& b)
{
    return Vec_0027FDB0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_0027FDB0 operator*(const Vec_0027FDB0& a, float s)
{
    return Vec_0027FDB0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}
static inline bool operator==(const Vec_0027FDB0& a, const Vec_0027FDB0& b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

struct Ref_0027FDB0;
extern "C" void func_00183CB8(void* p, Ref_0027FDB0* ref);

struct Ref_0027FDB0 {
    void* m_p;

    Ref_0027FDB0() {}
    ~Ref_0027FDB0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Feeler_0027FDB0 {
    char pad[0xC0];
    Ref_0027FDB0 m_ref;
    char padC4[0xE0 - 0xC4];

    Feeler_0027FDB0() {}
};

struct Model_0027FDB0 {
    char pad[0x50];
    Vec_0027FDB0 m_pos;
    char pad60[0x10];
    Vec_0027FDB0 m_70;
    Vec_0027FDB0 m_80;
};

struct Game_0027FDB0 {
    char pad[0xAC];
    unsigned int m_level;
};

extern Game_0027FDB0* D_00392808;
extern "C" void func_00209280(Feeler_0027FDB0* f, Vec_0027FDB0* start, Vec_0027FDB0* end);
extern "C" int func_002093E8(Feeler_0027FDB0* f, int a, int b);
extern "C" void func_00100DC0(Vec_0027FDB0* m, int a);

struct Cam_0027FDB0 {
    char pad0[0xC];
    Model_0027FDB0* m_model;
    char pad10[0x60 - 0x10];
    Vec_0027FDB0 m_60;
    Vec_0027FDB0 m_70;
    Vec_0027FDB0 m_80;
    float m_90;

    void SetDir(Vec_0027FDB0* v);
};

void Cam_0027FDB0::SetDir(Vec_0027FDB0* v)
{
    if (D_00392808->m_level != 0xD443A2BC && (*v)[1] > 0.0f) {
        Feeler_0027FDB0 f;
        Vec_0027FDB0 end = m_model->m_pos + *v * 72.0f;
        func_00209280(&f, &m_model->m_pos, &end);
        if (func_002093E8(&f, 1, 0)) {
            v->Set(0.0f, 1.0f, 0.0f, 1.0f);
        }
    }
    bool changed = !(*v == m_70);
    if (changed) {
        m_70 = *v;
        m_80 = m_60;
        m_90 = 1.0f;
        m_model->m_80 = *v;
        func_00100DC0(&m_model->m_70, 1);
    }
}
