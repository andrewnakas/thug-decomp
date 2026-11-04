typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_001C5CF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C5CF0() {}
    Vec_001C5CF0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    Vec_001C5CF0& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
};

static inline Vec_001C5CF0 Cross_001C5CF0(const Vec_001C5CF0& a, const Vec_001C5CF0& b)
{
    return Vec_001C5CF0(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline Vec_001C5CF0 operator*(const Vec_001C5CF0& a, float s)
{
    return Vec_001C5CF0(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Mat_001C5CF0 {
    Vec_001C5CF0 r0;
    Vec_001C5CF0 r1;
    Vec_001C5CF0 r2;
    Vec_001C5CF0 r3;
    Mat_001C5CF0& operator=(const Mat_001C5CF0& o)
    {
        r0 = o.r0;
        r1 = o.r1;
        r2 = o.r2;
        r3 = o.r3;
        return *this;
    }
};

extern "C" void func_003233B8(Vec_001C5CF0* dst, Vec_001C5CF0* src);

struct Body_001C5CF0 {
    char m_pad0[0x50];
    Vec_001C5CF0 m50;
    char m_pad60[0x10];
    Mat_001C5CF0 m70;
    Vec_001C5CF0 mB0;
    Mat_001C5CF0 mC0;
};

struct Cam_001C5CF0 {
    char m_pad0[0x250];
    Vec_001C5CF0 m250;
};

struct Obj_001C5CF0 {
    char m_pad0[0xC];
    Body_001C5CF0* mC;
    char m_pad10[0xC];
    int m1C;
    char m_pad20[0x10];
    Vec_001C5CF0 m30;
    Vec_001C5CF0 m40;
    float m50;
    char m_pad54[0xC];
    Vec_001C5CF0 m60;
    Vec_001C5CF0 m70;
    char m_pad80[0x44];
    float mC4;
    char m_padC8[0x954 - 0xC8];
    float m954;
    char m_pad958[0x9A0 - 0x958];
    float m9A0;
    char m_pad9A4[0xA30 - 0x9A4];
    Cam_001C5CF0* mA30;
    char m_padA34[0xC00 - 0xA34];
    float mC00;
    void Orient();
};

void Obj_001C5CF0::Orient()
{
    m60 *= sqrtf(1.0f - m9A0 * m9A0);
    m60.y = m9A0;
    Mat_001C5CF0 m;
    m.r0 = Vec_001C5CF0(m70.y * m60.z - m70.z * m60.y, m70.z * m60.x - m70.x * m60.z,
                        m70.x * m60.y - m70.y * m60.x, 0.0f);
    func_003233B8(&m.r0, &m.r0);
    m.r1 = m70;
    m.r2 = Cross_001C5CF0(m.r0, m.r1);
    Vec_001C5CF0& pos = m.r3;
    pos.Set(0.0f, 0.0f, 0.0f);
    mC->m50 = m30;
    mC->m70 = m;
    mC->mC0 = m;
    switch (m1C) {
    case 0:
    case 1:
        mC->mB0 = m40;
        mC->mB0.y = m50;
        break;
    case 2:
        mC->mB0.Set(-m60.z, 0.0f, m60.x);
        mC->mB0 *= mC00;
        break;
    case 3:
        mC->mB0.Set(0.0f, m954, 0.0f);
        break;
    default:
        mC->mB0.Set(0.0f, 0.0f, 0.0f);
        break;
    }
    mA30->m250 = m.r1 * mC4;
}
