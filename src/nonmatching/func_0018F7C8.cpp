/* fuzzy: 97.7 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct V_0018F7C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float LenSq() const { return x * x + y * y + z * z; }
    V_0018F7C8& operator-=(const V_0018F7C8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline float LenSq_0018F7C8(const V_0018F7C8& v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

struct Vec_0018F7C8 : V_0018F7C8 {
    Vec_0018F7C8() {}
    Vec_0018F7C8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_0018F7C8 operator*(const V_0018F7C8& v, float s)
{
    return Vec_0018F7C8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0018F7C8 operator+(const V_0018F7C8& a, const V_0018F7C8& b)
{
    return Vec_0018F7C8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_0018F7C8 operator-(const V_0018F7C8& a, const V_0018F7C8& b)
{
    return Vec_0018F7C8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Mat_0018F7C8 {
    V_0018F7C8 r[4];
    const V_0018F7C8& operator[](int i) const { return r[i]; }
    Mat_0018F7C8& operator=(const Mat_0018F7C8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_0018F7C8(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_0018F7C8 {
    V_0018F7C8 m_start;
    V_0018F7C8 m_end;
    char pad20[0x90 - 0x20];
    float m_dist;
    char pad94[0xB0 - 0x94];
    V_0018F7C8 m_normal;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_0018F7C8()
    {
        Release_0018F7C8(&m_ref);
    }
};

struct Model_0018F7C8 {
    char pad0[0x50];
    V_0018F7C8 m50;
    char pad60[0x70 - 0x60];
    Mat_0018F7C8 m70;
    V_0018F7C8 mB0;
    Mat_0018F7C8 mC0;
};

extern char D_00361F58[];
extern char D_00361F77[];
extern char D_00361FA0[];
extern int D_0038C9A8[1];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" float func_0010FAB8();
extern "C" void func_00184950(Model_0018F7C8* m);
extern "C" void func_00209240(Feeler_0018F7C8* f);
extern "C" int func_002093E8(Feeler_0018F7C8* f, int a, int b);

struct Body_0018F7C8;
extern "C" void func_00190120(Body_0018F7C8* b);
extern "C" void func_00190218(Body_0018F7C8* b);
extern "C" void func_00190800(Body_0018F7C8* b, float dt);
extern "C" void func_00190CF8(Body_0018F7C8* b);
extern "C" void func_00190E50(Body_0018F7C8* b);
extern "C" int func_00190EC8(Body_0018F7C8* b);
extern "C" void func_00191250(Body_0018F7C8* b);
extern "C" void func_00192A68(Body_0018F7C8* b);

struct Body_0018F7C8 {
    char pad0[0xC];
    Model_0018F7C8* mC;
    char pad10[0x20 - 0x10];
    float m20;
    float m24;
    char pad28[0x70 - 0x28];
    V_0018F7C8 m70;
    char pad80[0xB4 - 0x80];
    int mB4;
    char padB8[0xD0 - 0xB8];
    float mD0;
    int mD4;
    char padD8[0xE0 - 0xD8];
    V_0018F7C8 mE0;
    V_0018F7C8 mF0;
    char pad100[0x120 - 0x100];
    Mat_0018F7C8 m120;
    char pad160[0x164 - 0x160];
    float m164;
    void Update();
    Vec_0018F7C8 Vel(float dt) const { return Vec_0018F7C8(mF0.x * dt, mF0.y * dt, mF0.z * dt, mF0.w * dt); }
    Vec_0018F7C8 Ahead(const V_0018F7C8& d) const { return Vec_0018F7C8(mE0.x + d.x, mE0.y + d.y, mE0.z + d.z, mE0.w + d.w); }
    Vec_0018F7C8 Local(const Mat_0018F7C8& m) const
    {
        Vec_0018F7C8 o;
        o.x = m70.x * m.r[0].x + m70.y * m.r[1].x + m70.z * m.r[2].x;
        o.y = m70.x * m.r[0].y + m70.y * m.r[1].y + m70.z * m.r[2].y;
        o.z = m70.x * m.r[0].z + m70.y * m.r[1].z + m70.z * m.r[2].z;
        o.w = m70.w;
        return o;
    }
};

void Body_0018F7C8::Update()
{
    float dt = func_0010FAB8();
    func_00190120(this);
    if (m164 > 0.0f) {
        m164 = m164 - dt;
    } else if (!(mB4 & 2)) {
        func_00190218(this);
    }
    if (mD0 >= 0.0f) {
        if (mD0 <= dt) {
            func_00184950(mC);
        } else {
            mD0 = mD0 - dt;
        }
    }
    if (mD4 == 0) {
        mC->mC0 = m120;
        if (D_0038C9A8[0]) {
            func_00192A68(this);
        }
        return;
    }
    int iter = 0;
    int hit;
    V_0018F7C8& vel = mF0;
    do {
        Feeler_0018F7C8 f;
        func_00209240(&f);
        float step = dt;
        f.m_end = Ahead(Vel(dt));
        f.m_start = mE0;
        f.m_end.y += (dt * 0.5f) * dt * m20;
        hit = func_002093E8(&f, 0, 0);
        if (hit) {
            Vec_0018F7C8 d = f.m_end - f.m_start;
            float len = sqrtf(d.LenSq());
            step = (f.m_dist * len - 6.0f) / sqrtf(LenSq_0018F7C8(vel));
            if (step < 0.0f) {
                step = 0.0f;
            }
        }
        func_00190800(this, step);
        if (hit) {
            float dot = mF0.x * f.m_normal.x + mF0.y * f.m_normal.y + mF0.z * f.m_normal.z;
            mF0 -= f.m_normal * (m24 * dot + dot);
        }
        dt -= step;
        iter++;
        if (iter == 5) {
            func_00103F28(D_00361F58, D_00361F77, 0x22F, D_00361FA0);
            func_00190E50(this);
            break;
        }
    } while (hit);
    if (func_00190EC8(this)) {
        func_00191250(this);
    }
    func_00190CF8(this);
    mC->m50 = Ahead(Local(m120));
    mC->m70 = m120;
    mC->mC0 = m120;
    mC->mB0 = mF0;
    if (D_0038C9A8[0]) {
        func_00192A68(this);
    }
}
