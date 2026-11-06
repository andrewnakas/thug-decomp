/* fuzzy: 96.5 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001C1808 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
        float c[4];
    };
    Vec_001C1808() {}
    Vec_001C1808(const Vec_001C1808& o) { q = o.q; }
    Vec_001C1808(float ax, float ay, float az, float aw)
    {
        c[0] = ax;
        c[1] = ay;
        c[2] = az;
        c[3] = aw;
    }
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    float LengthSqr() const { return x * x + y * y + z * z; }
    void Scale3(float s)
    {
        x *= s;
        y *= s;
        z *= s;
    }
    void operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
};

inline Vec_001C1808 operator+(const Vec_001C1808& a, const Vec_001C1808& b)
{
    return Vec_001C1808(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

inline Vec_001C1808 operator*(const Vec_001C1808& a, float s)
{
    return Vec_001C1808(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

extern "C" float sqrtf(float);
extern "C" void* func_001E5548(unsigned int key, int def);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int f);
extern "C" unsigned int func_0026FDA0(void* p);
extern "C" void func_001BB080(void* a, int b, void* c);
extern "C" void func_001C5BB0(void* sk);
extern "C" float func_001C6218(void* sk);
extern "C" void func_00101890(Vec_001C1808* v, Vec_001C1808* n);
extern "C" void func_001C1D98(void* sk);
extern "C" void func_001C5CF0(void* sk);
extern "C" void func_001C4030(void* sk, float* a, float* b);
extern "C" void func_001BF130(void* sk, int a);
extern "C" void func_00184920(void* o, unsigned int key, float f, int a);

static inline float Param_001C1808(unsigned int key)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &v, 1);
    return v;
}

struct Info_001C1808 {
    char pad[0x1FC];
    char m1FC[4];
};

struct Flag_001C1808 {
    char pad[0x2C];
    int m2C;
};

struct Obj_001C1808 {
    char pad[0xB0];
    float mB0;
    float mB4;
    float mB8;
};

struct Sk_001C1808 {
    char pad0[0xC];
    Obj_001C1808* mC;
    char pad10[0x1C - 0x10];
    int m_state;
    char pad20[0x30 - 0x20];
    Vec_001C1808 m30;
    Vec_001C1808 m40;
    char pad50[0x60 - 0x50];
    Vec_001C1808 m60;
    char pad70[0xA0 - 0x70];
    Vec_001C1808 mA0;
    float mB0;
    char padB4[0x970 - 0xB4];
    Vec_001C1808 m970;
    char pad980[0xA28 - 0x980];
    Info_001C1808* mA28;
    char padA2C[0xA34 - 0xA2C];
    void* mA34;
    Flag_001C1808* mA38;
    char padA3C[0xA70 - 0xA3C];
    char mA70[0xB50 - 0xA70];
    int mB50;
    float mB54;
    char padB58[0xB70 - 0xB58];
    Vec_001C1808 mB70;
    char padB80[0xBC0 - 0xB80];
    int mBC0;
    char padBC4[0xBD0 - 0xBC4];
    Vec_001C1808 mBD0;
    float mBE0;
    float mBE4;
    char padBE8[0xBF4 - 0xBE8];
    float mBF4;
    void Update();
};

void Sk_001C1808::Update()
{
    float k = 0.0f;
    switch (m_state) {
    case 0:
    case 1: {
        k = Param_001C1808(0x246D0BF3);
        unsigned int c = func_0026FDA0(mA28->m1FC);
        float t = c / Param_001C1808(0x12333EBD);
        float r;
        if (t > 1.0f)
            r = 1.0f;
        else
            r = t;
        k += (1.0f - k) * r;
        break;
    }
    case 2:
    case 3:
    case 4:
        k = Param_001C1808(0xF2FA5845);
        break;
    }
    if (m_state == 0 && mB50) {
        func_001BB080(mA34, 2, mA70);
        if (mA38->m2C) return;
    }
    Obj_001C1808* o = mC;
    o->mB4 = k * Param_001C1808(0x63D62A21);
    switch (m_state) {
    case 0:
    case 1: {
        float zero = 0.0f;
        func_001C5BB0(this);
        Vec_001C1808* v = &m40;
        if (mB0 != zero) {
            float a = func_001C6218(this);
            float b = Param_001C1808(0x839FE542);
            float lo = Param_001C1808(0xCC461B87);
            float hi = Param_001C1808(0x7213EF07);
            float s = a * b / (lo + (hi - lo) * mB54);
            float d = m40.x * mA0.x + m40.y * mA0.y + m40.z * mA0.z;
            if (d > zero) {
                func_00101890(v, &mA0);
                float l = sqrtf(v->LengthSqr());
                if (l < s && l > zero) {
                    v->Scale3(s / l);
                }
            } else {
                *v = mA0 * s;
            }
            m60 = mA0;
            mB70 = m60;
        } else {
            mB70 = m60;
        }
        func_001C1D98(this);
        float l2 = v->LengthSqr();
        if (l2 > 0.01f) {
            mB70 = *v;
            mB70 *= 1.0f / sqrtf(l2);
        } else {
            mB70 = m60;
        }
        func_001C5CF0(this);
        break;
    }
    case 4: {
        mBC0 = 1;
        Vec_001C1808 q = m30 + m970;
        mBE0 = mBD0.x * q.x + mBD0.y * q.y + mBD0.z * q.z;
        mC->mB0 = 0.0f;
        mC->mB8 = 0.0f;
        mB70 = m60;
        break;
    }
    case 2: {
        mBD0 = m60;
        mBC0 = 1;
        Vec_001C1808 q = m30 + m970;
        mBE0 = mBD0.x * q.x + mBD0.y * q.y + mBD0.z * q.z;
        mBE4 = m30.y - mBF4;
        mC->mB0 = 0.0f;
        mC->mB8 = 0.0f;
        mB70 = m60;
        break;
    }
    case 3:
        mC->mB0 = 0.0f;
        mC->mB8 = 0.0f;
        mB70 = m60;
        break;
    }
    func_001C4030(this, &mC->mB0, &mC->mB4);
    func_001BF130(this, 1);
    func_00184920(mC, 0x8687163A, 0.0f, 0);
}
