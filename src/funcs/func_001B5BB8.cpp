typedef int qword __attribute__((mode(TI)));

struct V_001B5BB8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_001B5BB8 {
    V_001B5BB8 r[4];
    void Set(const Mat_001B5BB8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
    }
};

struct Vec_001B5BB8 {
    float x, y, z, w;
    Vec_001B5BB8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern "C" void func_00101238(Mat_001B5BB8* m, const Vec_001B5BB8* ang);

struct Model_001B5BB8 {
    char pad0[0xC0];
    Mat_001B5BB8 mC0;
};

struct Obj_001B5BB8 {
    char pad0[0xC];
    Model_001B5BB8* mC;
    char pad10[0x20 - 0x10];
    unsigned int m_flags;
    char pad24[0x8C - 0x24];
    float m8C;
    V_001B5BB8 m90;
    V_001B5BB8 mA0;
    V_001B5BB8 mB0;
    char padC0[0xD0 - 0xC0];
    int mD0;
    float mD4;
    float mD8;
    float mDC;
    Mat_001B5BB8 mE0;
    float m120;
    float m124;
    char pad128[0x130 - 0x128];
    Mat_001B5BB8 m130;
    void Update();
};

void Obj_001B5BB8::Update()
{
    float dt = m8C;
    float t = dt / mD8;
    mDC += dt;
    if (t > 1.0f) t = 1.0f;
    float rest = 180.0f - m124;
    if (m_flags & 0x200) mD4 += t * mD0;
    if (m_flags & 0x400) m120 += t * rest;
    if (mDC >= mD8 || 1.0f <= t) {
        if (m_flags & 0x200) mD4 = mD0;
        if (m_flags & 0x400) m120 = rest;
        m_flags &= ~0x200;
        m_flags &= ~0x400;
    }
    if ((m_flags & 0x400) && rest < m120) m120 = rest;
    Mat_001B5BB8 mat = mE0;
    Vec_001B5BB8 ang(m120 * 0.0174532942f, mD4 * 0.0174532942f, 0.0f, 1.0f);
    func_00101238(&mat, &ang);
    mC->mC0.Set(mat);
    m130.Set(mat);
    mA0 = mat.r[1];
    m90 = mat.r[1];
    mB0 = mat.r[1];
}
