/* fuzzy: 87.2 */
typedef int qword_001BA000 __attribute__((mode(TI)));

struct Vec_001BA000 {
    union {
        qword_001BA000 q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_001BA000() {}
    Vec_001BA000(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Approach(const Vec_001BA000& t, float a, float b)
    {
        x += (t.x - x) * a;
        y += (t.y - y) * b;
        z += (t.z - z) * a;
        w = 1.0f;
    }
};

struct Target_001BA000 {
    char pad[0x50];
    Vec_001BA000 m_pos;
};

struct State_001BA000 {
    char pad[0x40];
    int m40;
    char pad44[0x20];
    int m64;
    char pad68[0x44];
    int mAC;
    char padB0[0x2C];
    int mDC;
    char padE0[0x8];
    int mE8;
};

extern "C" float func_0010FAB8();
extern "C" float func_0018B1D0(float rate, float dt);

struct C_001BA000 {
    char pad[0x40];
    Vec_001BA000 m40;
    char pad50[0x90];
    float mE0;
    float mE4;
    float mE8;
    float mEC;
    char padF0[0x4];
    float mF4;
    float mF8;
    float mFC;
    char pad100[0x68];
    Target_001BA000* m168;
    State_001BA000* m16C;
    Vec_001BA000 GetPos(int snap);
};

Vec_001BA000 C_001BA000::GetPos(int snap)
{
    float dt = func_0010FAB8();
    if (!m168) {
        return Vec_001BA000(0.0f, 0.0f, 0.0f, 1.0f);
    }
    Vec_001BA000 target = m168->m_pos;
    if (mF4 > 0.0f) {
        mF4 -= dt;
        if (mF4 > 0.0f) {
            mFC += mF8 * dt;
        } else {
            mF4 = 0.0f;
            mFC = 1.0f;
        }
    } else {
        mFC = 1.0f;
    }
    float a;
    float b;
    if (m16C->m40 && !m16C->m64 && !m16C->mAC) {
        a = func_0018B1D0(mE8 * mFC, dt);
        b = func_0018B1D0(mEC * mFC, dt);
    } else {
        a = func_0018B1D0(mE0 * mFC, dt);
        b = func_0018B1D0(mE4 * mFC, dt);
        if (m16C->mDC)
            b = 1.0f;
        if (m16C->mE8)
            snap = 1;
    }
    if (snap)
        m40 = target;
    else
        m40.Approach(target, a, b);
    return m40;
}
