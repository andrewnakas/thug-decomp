typedef int qword_001B5150 __attribute__((mode(TI)));

struct Vec_001B5150 {
    union {
        struct { float x, y, z, w; };
        qword_001B5150 q;
    };
    Vec_001B5150() {}
    Vec_001B5150(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001B5150 Cross_001B5150(const Vec_001B5150& a, const Vec_001B5150& b)
{
    return Vec_001B5150(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Mat_001B5150 {
    Vec_001B5150 r[4];
};

extern "C" void func_003233B8(Vec_001B5150* out, Vec_001B5150* in);

struct Model_001B5150 {
    char pad[0xC0];
    Mat_001B5150 mC0;
};

struct Obj_001B5150 {
    char pad[0xC];
    Model_001B5150* mC;
    char pad10[0x90 - 0x10];
    Vec_001B5150 m90;
    void Method();
};

void Obj_001B5150::Method()
{
    Mat_001B5150 m = mC->mC0;
    {
        Vec_001B5150 up(0.0f, 1.0f, 0.0f, 1.0f);
        m.r[2] = up;
    }
    func_003233B8(&m90, &m90);
    m.r[1] = m90;
    {
        Vec_001B5150 t = Cross_001B5150(m.r[1], m.r[2]);
        func_003233B8(&t, &t);
        m.r[0] = t;
    }
    {
        Vec_001B5150 t = Cross_001B5150(m.r[2], m.r[0]);
        func_003233B8(&t, &t);
        m.r[1] = t;
    }
    Mat_001B5150* d = &mC->mC0;
    *d = m;
}
