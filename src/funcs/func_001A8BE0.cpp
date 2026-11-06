typedef int qword __attribute__((mode(TI)));

union Vec_001A8BE0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001A8BE0() {}
    Vec_001A8BE0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator-=(const Vec_001A8BE0& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator+=(const Vec_001A8BE0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator*=(float f)
    {
        c[0] *= f;
        c[1] *= f;
        c[2] *= f;
        c[3] *= f;
    }
};

inline Vec_001A8BE0 operator*(const Vec_001A8BE0& a, float k) { return Vec_001A8BE0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001A8BE0 operator+(const Vec_001A8BE0& a, const Vec_001A8BE0& b)
{
    return Vec_001A8BE0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001A8BE0 operator-(const Vec_001A8BE0& a, const Vec_001A8BE0& b)
{
    return Vec_001A8BE0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline Vec_001A8BE0 Cross_001A8BE0(const Vec_001A8BE0& a, const Vec_001A8BE0& b)
{
    return Vec_001A8BE0(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_003233B8(Vec_001A8BE0* dst, Vec_001A8BE0* src);
extern "C" int func_001A8940(const Vec_001A8BE0* start, const Vec_001A8BE0* end, Vec_001A8BE0* hit,
                             Vec_001A8BE0* verts);

struct Feeler_001A8BE0 {
    char pad0[0xC0];
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void func_00209240(Feeler_001A8BE0* f);

struct Body_001A8BE0 {
    char pad0[0x50];
    Vec_001A8BE0 pos;
    Vec_001A8BE0 m60;
    Vec_001A8BE0 m70;
    Vec_001A8BE0 m80;
    Vec_001A8BE0 m90;
};

struct Align_001A8BE0 {
    char pad0[0xC];
    Body_001A8BE0* mC;
    char pad10[0x3C - 0x10];
    float m3C;
    float m40;
    char pad44[0x50 - 0x44];
    Vec_001A8BE0 m50[3];
    int m80;
    char pad84[0x90 - 0x84];
    Vec_001A8BE0 m90[3];
    Vec_001A8BE0 mC0[3];
    Vec_001A8BE0 mF0[3];

    int Snap();
};

int Align_001A8BE0::Snap()
{
    if (m3C == 0.0f && m40 == 0.0f) {
        return 0;
    }
    Vec_001A8BE0 start;
    Vec_001A8BE0 end;
    if (m80) {
        mC->m70 = Cross_001A8BE0(mC->m80, mC->m90);
        func_003233B8(&mC->m70, &mC->m70);
        start.Set(0.0f, __builtin_fabsf(m3C) * 12.0f, 0.0f, 1.0f);
        end.Set(0.0f, -(__builtin_fabsf(m40) * 12.0f), 0.0f, 1.0f);
        start += mC->pos;
        end += mC->pos;
        Vec_001A8BE0 hit;
        if (func_001A8940(&start, &end, &hit, m50)) {
            mC->pos = hit;
            return 1;
        }
        return 0;
    }
    float k = 12.0f;
    Vec_001A8BE0 fwd;
    Vec_001A8BE0 side;
    Vec_001A8BE0 hitA;
    Vec_001A8BE0 hitB;
    Feeler_001A8BE0 f;
    func_00209240(&f);
    int all = 0;
    mC->m80.Set(0.0f, 1.0f, 0.0f, 1.0f);
    mC->m70 = Cross_001A8BE0(mC->m80, mC->m90);
    func_003233B8(&mC->m70, &mC->m70);
    fwd = mC->m90 * 72.0f;
    side = mC->m70 * 30.0f;
    mC->pos -= fwd;
    mC->pos += side;
    start = end = mC->pos;
    start[1] += m3C * k;
    end[1] -= m40 * k;
    int okA = func_001A8940(&start, &end, &hitA, m90) != 0;
    mC->pos -= side + side;
    start = end = mC->pos;
    start[1] += m3C * k;
    end[1] -= m40 * k;
    if (func_001A8940(&start, &end, &hitB, mC0)) {
        all = 1;
        if (okA) {
            mC->m70 = hitA - hitB;
            func_003233B8(&mC->m70, &mC->m70);
        }
    }
    mC->pos += fwd + fwd;
    mC->pos += side;
    start = end = mC->pos;
    start[1] += m3C * 12.0f;
    end[1] -= m40 * 12.0f;
    mC->pos -= fwd;
    Vec_001A8BE0 hitC;
    if (func_001A8940(&start, &end, &hitC, mF0) && all && okA) {
        float h = 0.5f;
        mC->pos[1] = hitA[1] + hitB[1];
        mC->pos[1] *= h;
        mC->pos[1] += hitC[1];
        mC->pos[1] *= h;
        Vec_001A8BE0 n;
        n = hitA + hitB;
        n.Set(hitC[0] - n[0] * h, hitC[1] - n[1] * h, hitC[2] - n[2] * h, hitC[3] - n[3] * h);
        func_003233B8(&n, &n);
        mC->m90 += n;
        mC->m90 *= h;
        mC->m80 = Cross_001A8BE0(mC->m90, mC->m70);
        func_003233B8(&mC->m80, &mC->m80);
        return 1;
    }
    return 0;
}
