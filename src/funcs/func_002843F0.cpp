typedef int qword __attribute__((mode(TI)));
union Vec_002843F0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_002843F0() {}
    Vec_002843F0(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_002843F0(float x, float y, float z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        c[3] = 1.0f;
    }
    float Length() const;
    void Normalize();
    void operator+=(const Vec_002843F0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_002843F0*, Vec_002843F0*);
inline float Vec_002843F0::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline void Vec_002843F0::Normalize() { func_003233B8(this, this); }
inline Vec_002843F0 operator*(const Vec_002843F0& a, float k) { return Vec_002843F0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_002843F0 operator+(const Vec_002843F0& a, const Vec_002843F0& b)
{
    return Vec_002843F0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_002843F0 operator-(const Vec_002843F0& a, const Vec_002843F0& b)
{
    return Vec_002843F0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_002843F0(const Vec_002843F0& a, const Vec_002843F0& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_002843F0 Cross_002843F0(const Vec_002843F0& a, const Vec_002843F0& b)
{
    return Vec_002843F0(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_002843F0 {
    Vec_002843F0 r[4];
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_002843F0;
extern "C" Coll_002843F0* func_00209280(Coll_002843F0* c, const Vec_002843F0& s, const Vec_002843F0& e);
struct Coll_002843F0 {
    Vec_002843F0 start;
    Vec_002843F0 end;
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

struct Body_002843F0 {
    char pad0[0x50];
    Vec_002843F0 m50;
    Vec_002843F0 m60;
    Mat_002843F0 m70;
    Vec_002843F0 mB0;
    void GetMatrix(Mat_002843F0* out) { *out = m70; }
};
struct Trick_002843F0 {
    char pad0[0x6C];
    int m6C;
    int Id() const { return m6C; }
};
struct Sk_002843F0 {
    char pad0[0x2C];
    int m2C;
};
struct Mgr_002843F0 {
    char pad0[0x1400];
    int m1400;
};
struct Snd_002843F0 {
    char pad0[0x24];
    int m24;
};
struct Obj_002843F0;
extern "C" int func_001ABFF8(Mgr_002843F0* m, unsigned int name);
extern "C" float func_002032A0(unsigned int, int);
extern "C" unsigned int func_0033EBE0(float);
extern "C" int func_001ABB20(Mgr_002843F0* m, unsigned int name, unsigned int t, unsigned int f);
extern "C" int func_0010FC30();
extern "C" int func_00101730(Vec_002843F0*, Vec_002843F0*);
extern "C" int func_002093E8(Coll_002843F0* c, int a, int b);
extern "C" void func_001016A8(Vec_002843F0* v, Vec_002843F0* n);
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);
extern "C" void func_001B0EB8(Mgr_002843F0* m, int a);
extern "C" void func_0019C9D8(Trick_002843F0* t, void* p);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" int func_0028E1C0(Obj_002843F0* o, unsigned short a, unsigned short b);
extern "C" void func_001848F0(Body_002843F0* b, unsigned int name, int a);
extern "C" void func_0027C720(Obj_002843F0* o, int v);
extern "C" void func_00280188(Obj_002843F0* o);

struct Obj_002843F0 {
    char pad0[0xC];
    Body_002843F0* mC;
    char pad10[0x20 - 0x10];
    Mat_002843F0 m20;
    char pad60[0xB0 - 0x60];
    Vec_002843F0 mB0;
    char padC0[0x150 - 0xC0];
    Vec_002843F0 m150;
    Vec_002843F0 m160;
    char pad170[0x190 - 0x170];
    Trick_002843F0 m190;
    char pad200[0x270 - 0x200];
    Vec_002843F0 m270;
    Vec_002843F0 m280;
    char pad290[0x298 - 0x290];
    int m298;
    char pad29C[0x410 - 0x29C];
    Vec_002843F0 m410;
    int m420;
    char pad424[0x598 - 0x424];
    void* m598;
    Snd_002843F0* m59C;
    Mgr_002843F0* m5A0;
    char pad5A4[0x5B8 - 0x5A4];
    Sk_002843F0* m5B8;
    bool TryWall();
};

bool Obj_002843F0::TryWall()
{
    if (!m298) return false;
    if (!func_001ABFF8(m5A0, 0x20689278)) {
        unsigned int t = func_0033EBE0(func_002032A0(0x5D241B00, 0) * 1000.0f);
        if (!func_001ABB20(m5A0, 0x20689278, t, 0xFFFFFFFF)) return false;
    }
    int s = m420;
    float el = (float)(func_0010FC30() - s);
    if (func_002032A0(0xF0C74EC2, 0) * 1000.0f < el) {
        Body_002843F0* b = mC;
        if (0.0f < b->mB0[1]) {
            Vec_002843F0 p = m150;
            Vec_002843F0 n = m160;
            Vec_002843F0 u(0.0f, b->mB0[1] * 0.15f, 0.0f);
            func_00101730(&u, &n);
            p += u;
            Coll_002843F0 c;
            Coll_002843F0* pc = &c;
            func_00209280(pc, p + n * 6.0f, p - n * 6.0f);
            if (!func_002093E8(pc, 1, 0)) {
                pc->mC0.Release();
                return false;
            }
            pc->mC0.Release();
        }
        void* tb = &mB0;
        Vec_002843F0* up = &m410;
        *up = m160;
        Vec_002843F0 a = m160;
        a[1] = 0.0f;
        a.Normalize();
        Vec_002843F0 v = mC->mB0;
        v[1] = 0.0f;
        v.Normalize();
        Vec_002843F0 h = mC->mB0;
        h[1] = 0.0f;
        func_001016A8(&h, &a);
        if (h.Length() < func_002032A0(0xF0636A67, 0)) return false;
        float d = fabsf(Dot_002843F0(v, a));
        if (-func_00341068(func_002032A0(0xAE23E850, 0) * 0.01745329425f) < m410[1]) {
            if (d < func_00341068(func_002032A0(0x6AC9F64D, 0) * 0.01745329425f)) {
                Body_002843F0* b2 = mC;
                if (func_00340F60(func_002032A0(0xBFCBB7E8, 0) * 0.01745329425f) < b2->m70.r[1][1]) {
                    if (!m5A0->m1400) func_001B0EB8(m5A0, 0);
                    Trick_002843F0* tr = &m190;
                    func_0019C9D8(tr, tb);
                    m59C->m24 = tr->Id();
                    func_001BB080(m598, 3, tr);
                    if (m5B8->m2C) return false;
                    Vec_002843F0 save = m150;
                    Vec_002843F0 dd = mC->m50 - mC->m60;
                    func_00101730(&dd, up);
                    m270 = mC->m50;
                    m280 = mC->m50 + dd * 3.0f;
                    if (func_0028E1C0(this, 0x10, 0)) return false;
                    m420 = func_0010FC30();
                    mC->m50 = save;
                    mC->m50 += *up;
                    func_00101730(&mC->mB0, up);
                    mC->m70.r[2] = mC->mB0;
                    mC->m70.r[2].Normalize();
                    mC->m70.r[1] = *up;
                    mC->m70.r[0] = Cross_002843F0(mC->m70.r[1], mC->m70.r[2]);
                    mC->m70.r[0].Normalize();
                    mC->GetMatrix(&m20);
                    Vec_002843F0 q(-m410[2], 0.0f, m410[0], 0.0f);
                    if (mC->mB0[0] * q[0] + mC->mB0[2] * q[2] < 0.0f)
                        func_001848F0(mC, 0x5DE19C83, 0);
                    else
                        func_001848F0(mC, 0x51372712, 0);
                    func_0027C720(this, 2);
                    func_00280188(this);
                    return true;
                }
            }
        }
    }
    return false;
}
