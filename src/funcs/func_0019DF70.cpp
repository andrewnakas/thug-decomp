extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));

struct Row_0019DF70 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Row_0019DF70& operator+=(const Row_0019DF70& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Row_0019DF70& operator-=(const Row_0019DF70& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
    void operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void RotateY(float a);
};

struct Vec_0019DF70 : Row_0019DF70 {
    Vec_0019DF70() {}
    Vec_0019DF70(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_0019DF70 operator*(const Row_0019DF70& v, float s)
{
    return Vec_0019DF70(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0019DF70 operator+(const Row_0019DF70& a, const Row_0019DF70& b)
{
    return Vec_0019DF70(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_0019DF70 operator-(const Row_0019DF70& a, const Row_0019DF70& b)
{
    return Vec_0019DF70(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0019DF70 operator-(const Row_0019DF70& a)
{
    return Vec_0019DF70(-a.x, -a.y, -a.z, -a.w);
}

extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

inline void Row_0019DF70::RotateY(float a)
{
    float s = func_00341068(a);
    float c = func_00340F60(a);
    float x0 = x;
    float z0 = z;
    x = c * x0 + s * z0;
    z = -s * x0 + c * z0;
}

struct Mat_0019DF70 {
    Row_0019DF70 r[4];
};

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_00183C98(void* p, void* pp);

struct Ref_0019DF70 {
    void* p;
    void Release()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
    ~Ref_0019DF70() { Release(); }
    void operator=(void* q)
    {
        Release();
        p = q;
        if (q)
            func_00183C98(q, this);
    }
};

struct Feeler_0019DF70 {
    Row_0019DF70 m_start;
    Row_0019DF70 m_end;
    char pad20[0xA0 - 0x20];
    Row_0019DF70 m_point;
    Row_0019DF70 m_normal;
    Ref_0019DF70 m_ref;
    char padC4[0xE0 - 0xC4];
};

struct Spawn_0019DF70 {
    char pad0[0xBC];
    Ref_0019DF70 mBC;
};

struct Body_0019DF70 {
    char pad0[0x50];
    Row_0019DF70 m50;
    char pad60[0x70 - 0x60];
    Mat_0019DF70 m70;
    char padB0[0xC0 - 0xB0];
    Mat_0019DF70 mC0;
};

struct Obj_0019DF70 {
    char pad0[0xC];
    Body_0019DF70* mC;
    char pad10[0x20 - 0x10];
    Row_0019DF70 m20;
    int m30;
    int m34;
    float m38;
    int m3C;
    float m40;
    char pad44[0x48 - 0x44];
    int m48;
    int m4C;
    char pad50[0x54 - 0x50];
    float m54;
    char pad58[0x60 - 0x58];
    int m60;
    char pad64[0x70 - 0x64];
    float m70;
    char pad74[0x78 - 0x74];
    int m78;
    short m7C;
    short m7E;
    char pad80[0x88 - 0x80];
    int m88;
    int m8C;
    Row_0019DF70 m90;
    Row_0019DF70 mA0;
    Row_0019DF70 mB0;
    Mat_0019DF70 mC0;
    float m100;
    Vec_0019DF70 Ahead(const Row_0019DF70& t) const
    {
        return Vec_0019DF70(m90.x + t.x, m90.y + t.y, m90.z + t.z, m90.w + t.w);
    }
    float Bounce(Row_0019DF70* v, const Row_0019DF70& r);
    void Update();
};

extern "C" int func_00100030(int n);
extern "C" void func_00101238(Mat_0019DF70* m, Row_0019DF70* a);
extern "C" bool func_0019DEF0(Obj_0019DF70* o);
extern "C" void func_0019DDF8(Obj_0019DF70* o);
extern "C" void func_003233B8(Row_0019DF70* d, Row_0019DF70* s);
extern "C" void func_00209240(Feeler_0019DF70* f);
extern "C" void func_00209380(Feeler_0019DF70* f, Row_0019DF70* a, Row_0019DF70* b);
extern "C" int func_002093E8(Feeler_0019DF70* f, int a, int b);
extern "C" Spawn_0019DF70* func_001F0750(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_001EFDC0(Spawn_0019DF70* s);
extern "C" void func_00184950(Body_0019DF70* b);

inline float Obj_0019DF70::Bounce(Row_0019DF70* v, const Row_0019DF70& r)
{
    float speed = v->Length();
    *v = -r;
    float len = v->Length();
    float k = speed * m40;
    if (0.0f < len) {
        len = k / len;
        v->x *= len;
        v->y *= len;
        v->z *= len;
    }
    v->RotateY((float)(func_00100030(m60 * 2) - m60) * 0.017453294f);
    return speed;
}

void Obj_0019DF70::Update()
{
    mA0 = m90;
    switch (m7E) {
    case 0: {
        int r = func_00100030(8);
        float f = (float)((m30 >> 2) + func_00100030((m30 >> 2) * 3)) * 0.017453294f;
        m20.x = f;
        if (r & 1)
            m20.x = -f;
        f = (float)((m30 >> 2) + func_00100030((m30 >> 2) * 3)) * 0.017453294f;
        m20.y = f;
        if (r & 2)
            m20.y = -f;
        f = (float)((m30 >> 2) + func_00100030((m30 >> 2) * 3)) * 0.017453294f;
        m20.z = f;
        if (r & 4)
            m20.z = -f;
        m20.w = 1.0f;
        m4C = 0;
        m7E++;
    }
    case 1: {
        Row_0019DF70 a;
        m90 += Vec_0019DF70(mB0.x * m100, mB0.y * m100, mB0.z * m100, mB0.w * m100);
        if (m4C) {
            func_0019DEF0(this);
        } else {
            a = m20;
            a *= m100;
            func_00101238(&mC0, &a);
        }
        Row_0019DF70 dir = mB0;
        func_003233B8(&dir, &dir);
        Vec_0019DF70 end = Ahead(dir * m70);
        mB0.y -= m54 * m100;
        Feeler_0019DF70 coll;
        func_00209240(&coll);
        func_00209380(&coll, &mA0, &end);
        if (func_002093E8(&coll, 1, 0)) {
            if (m88) {
                Spawn_0019DF70* s = func_001F0750(m88, m8C, 0, 0, -1, 0, 0, 0, 0, 0);
                s->mBC = mC;
                func_001EFDC0(s);
            }
            Row_0019DF70 d;
            Row_0019DF70 rf;
            d = Vec_0019DF70(m90.x - mA0.x, m90.y - mA0.y, m90.z - mA0.z, m90.w - mA0.w);
            Row_0019DF70 n = coll.m_normal;
            m48++;
            rf = n * (2.0f * (d.x * n.x + d.y * n.y + d.z * n.z));
            rf -= d;
            float speed = Bounce(&mB0, rf);
            m90 = coll.m_point - dir * m70;
            if (fabsf(mB0.y) < m38 + m54 * m100 * 2.0f) {
                if (m3C) {
                    if (!m4C)
                        func_0019DDF8(this);
                    m7E++;
                    break;
                }
                m7C = 1;
                if (m78)
                    func_00184950(mC);
                return;
            }
            if (m38 + m38 < speed) {
                if (m34) {
                    Row_0019DF70* p = &a;
                    a.x = (float)(func_00100030(m34 * 2) - m34) * 0.017453294f;
                    a.y = (float)(func_00100030(m34 * 2) - m34) * 0.017453294f;
                    a.z = (float)(func_00100030(m34 * 2) - m34) * 0.017453294f;
                    func_00101238(&mC0, p);
                }
                m7E = 0;
            } else if (m3C && !m4C) {
                func_0019DDF8(this);
            }
        }
        break;
    }
    case 2:
        if (func_0019DEF0(this)) {
            m7C = 1;
            if (m78)
                func_00184950(mC);
        }
        break;
    }
    mC->m50 = m90;
    Mat_0019DF70* dm = &mC->m70;
    *dm = mC0;
    Mat_0019DF70* dm2 = &mC->mC0;
    *dm2 = mC0;
}
