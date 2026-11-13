/* force: {"kind": "sched", "pass": 2, "block": 9, "clock": 1, "first": 386} */
typedef int qword_001C2870 __attribute__((mode(TI)));

struct Vec_001C2870 {
    union {
        struct {
            float x, y, z, w;
        } f;
        qword_001C2870 q;
    } u;
    Vec_001C2870() {}
    Vec_001C2870(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
};

static inline Vec_001C2870 operator+(const Vec_001C2870& a, const Vec_001C2870& b)
{
    return Vec_001C2870(a.u.f.x + b.u.f.x, a.u.f.y + b.u.f.y, a.u.f.z + b.u.f.z, a.u.f.w + b.u.f.w);
}

static inline Vec_001C2870 operator-(const Vec_001C2870& a, const Vec_001C2870& b)
{
    return Vec_001C2870(a.u.f.x - b.u.f.x, a.u.f.y - b.u.f.y, a.u.f.z - b.u.f.z, a.u.f.w - b.u.f.w);
}

extern "C" void func_00183CB8(void* p, void* pp);

struct Feeler_001C2870 {
    Vec_001C2870 m_start;
    Vec_001C2870 m_end;
    char m_pad20[0xA0 - 0x20];
    Vec_001C2870 m_point;
    Vec_001C2870 m_normal;
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } m_ref;
    char m_padC4[0xE0 - 0xC4];
};

extern "C" Feeler_001C2870* func_00209240(Feeler_001C2870* f);
extern "C" bool func_002093E8(Feeler_001C2870* f, int a, int b);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" Vec_001C2870* func_001016A8(Vec_001C2870* v, const Vec_001C2870* n);
extern "C" void func_00101890(Vec_001C2870* v, const Vec_001C2870* n);
extern "C" void func_001848F0(void* obj, unsigned int name, int flags);

static inline float GetParam_001C2870(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

struct Skater_001C2870 {
    char m_pad0[0xC];
    void* mC;
    char m_pad10[0x30 - 0x10];
    Vec_001C2870 m_pos;
    Vec_001C2870 m_vel;
    float m50;
    char m_pad54[0xBC0 - 0x54];
    int mBC0;
    void Snap();
};

void Skater_001C2870::Snap()
{
    if (mBC0)
        return;
    float d = GetParam_001C2870(0x9EA1974A);
    if (m50 < 0.0f)
        d -= 18.0f;
    Feeler_001C2870 f;
    func_00209240(&f);
    f.m_start = m_pos;
    f.m_end = m_pos;
    f.m_end.u.f.y += d;
    if (func_002093E8(&f, 1, 0)) {
        Vec_001C2870* vel = &m_vel;
        m_vel.u.f.y = m50;
        if (m_vel.u.f.x * f.m_normal.u.f.x + m_vel.u.f.y * f.m_normal.u.f.y + m_vel.u.f.z * f.m_normal.u.f.z < 0.0f)
            func_001016A8(vel, &f.m_normal);
        m50 = m_vel.u.f.y;
        m_vel.u.f.y = 0.0f;
        Vec_001C2870 diff = f.m_point - f.m_end;
        func_00101890(&diff, &f.m_normal);
        f.m_end = Vec_001C2870(m_pos.u.f.x + diff.u.f.x, m_pos.u.f.y + diff.u.f.y, m_pos.u.f.z + diff.u.f.z,
                               m_pos.u.f.w + diff.u.f.w);
        if (func_002093E8(&f, 1, 0))
            m_pos = f.m_point + f.m_normal;
        else
            m_pos = f.m_end;
        func_001848F0(mC, 0x6E84ACF3, 0);
    }
}
