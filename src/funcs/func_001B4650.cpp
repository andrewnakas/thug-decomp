typedef int qword_001B4650 __attribute__((mode(TI)));

struct Vec_001B4650 {
    union {
        struct { float x, y, z, w; };
        qword_001B4650 q;
    };
    Vec_001B4650() {}
    Vec_001B4650(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001B4650 Cross_001B4650(const Vec_001B4650& a, const Vec_001B4650& b)
{
    return Vec_001B4650(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Mat_001B4650 {
    Vec_001B4650 r[4];
    Mat_001B4650& operator=(const Mat_001B4650& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

extern "C" void func_003233B8(Vec_001B4650* out, Vec_001B4650* in);

struct Model_001B4650 {
    char pad[0x50];
    Vec_001B4650 m50;
    char pad60[0xC0 - 0x60];
    Mat_001B4650 mC0;
};

struct Obj_001B4650 {
    char pad[0xC];
    Model_001B4650* mC;
    char pad10[0x10];
    unsigned int m20;
    char pad24[0x50 - 0x24];
    Vec_001B4650 m50;
    Vec_001B4650 m60;
    char pad70[0x130 - 0x70];
    Mat_001B4650 m130;
    void Method(Vec_001B4650* target);
};

void Obj_001B4650::Method(Vec_001B4650* target)
{
    Mat_001B4650 m = mC->mC0;
    Vec_001B4650 pos = mC->m50;
    if (m20 & 0x8000) {
        *target = m50;
        pos = m60;
    }
    {
        Vec_001B4650 dir(pos.x - target->x, pos.y - target->y, pos.z - target->z, pos.w - target->w);
        func_003233B8(&dir, &dir);
        m.r[2] = dir;
    }
    {
        Vec_001B4650 t = Cross_001B4650(m.r[1], m.r[2]);
        m.r[0] = t;
    }
    {
        Vec_001B4650 t = Cross_001B4650(m.r[2], m.r[0]);
        m.r[1] = t;
    }
    mC->mC0 = m;
    m130 = m;
}
