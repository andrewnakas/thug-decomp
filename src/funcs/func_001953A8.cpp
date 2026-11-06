extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Row_001953A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float& operator[](int i) { return (&x)[i]; }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    Row_001953A8& operator-=(const Row_001953A8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

struct Vec_001953A8 : Row_001953A8 {
    Vec_001953A8() {}
    Vec_001953A8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001953A8 operator*(const Row_001953A8& v, float s)
{
    return Vec_001953A8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_001953A8 operator+(const Vec_001953A8& a, const Vec_001953A8& b)
{
    return Vec_001953A8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Mat_001953A8 {
    Row_001953A8 r[4];
    Row_001953A8& operator[](int i) { return r[i]; }
    Mat_001953A8& operator*=(const Mat_001953A8& o);
    void RotX(float a);
    void RotY(float a);
    void RotZ(float a);
    void Identity()
    {
        r[0].x = 1.0f;
        r[0].y = 0.0f;
        r[0].z = 0.0f;
        r[0].w = 0.0f;
        r[1].x = 0.0f;
        r[1].y = 1.0f;
        r[1].z = 0.0f;
        r[1].w = 0.0f;
        r[2].x = 0.0f;
        r[2].y = 0.0f;
        r[2].z = 1.0f;
        r[2].w = 0.0f;
        r[3].x = 0.0f;
        r[3].y = 0.0f;
        r[3].z = 0.0f;
        r[3].w = 1.0f;
    }
};

struct Quat_001953A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float& operator[](int i) { return (&x)[i]; }
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001953A8 {
    Row_001953A8 start;
    Row_001953A8 end;
    char pad20[0xA0 - 0x20];
    Row_001953A8 hit;
    char padB0[0xC0 - 0xB0];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
        ~Ref() { Release(); }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

struct Wheel_001953A8 {
    char pad0[0x8];
    int m8;
    char padC[0xC4 - 0xC];
    float mC4;
    float mC8;
    char padCC[0xD0 - 0xCC];
    int mD0;
    char padD4[0xD8 - 0xD4];
    float mD8;
    char padDC[0xE0 - 0xDC];
    float mE0;
    char padE4[0xE8 - 0xE4];
    float mE8;
    char padEC[0x220 - 0xEC];
};

struct Body_001953A8 {
    char pad0[0x50];
    Vec_001953A8 m50;
    char pad60[0x70 - 0x60];
    Mat_001953A8 m70;
    Vec_001953A8 mB0;
    Mat_001953A8 mC0;
};

struct Base_001953A8 {
    char pad0[0xC];
    Body_001953A8* mC;
    char pad10[0x18 - 0x10];
    virtual void V0();
    virtual void V1();
};

struct Obj_001953A8 : Base_001953A8 {
    char pad1C[0x20 - 0x1C];
    Vec_001953A8 m20;
    Vec_001953A8 m30;
    Quat_001953A8 m40;
    Vec_001953A8 m50;
    int m60;
    char pad64[0x70 - 0x64];
    Mat_001953A8 m70;
    Vec_001953A8 mB0;
    char padC0[0x128 - 0xC0];
    int m128;
    char pad12C[0x180 - 0x12C];
    float m180;
    char pad184[0x1C4 - 0x184];
    unsigned int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_001953A8* m_wheels;
    char pad31C[0x1384 - 0x31C];
    int m1384;
    void* m1388;
    void Reset(void* src);
};

extern "C" void func_00229FF8(void* src, Vec_001953A8* pos);
extern "C" void func_0022A268(void* src, Vec_001953A8* rot);
extern "C" Mat_001953A8* func_00100890(Mat_001953A8* m, float a);
extern "C" Mat_001953A8* func_00100928(Mat_001953A8* m, float a);
extern "C" Mat_001953A8* func_001009C0(Mat_001953A8* m, float a);
extern "C" Mat_001953A8* func_00323318(Mat_001953A8* out, const Mat_001953A8* a, const Mat_001953A8* b);
extern "C" Coll_001953A8* func_00209280(Coll_001953A8* c, const Vec_001953A8& s, const Vec_001953A8& e);
extern "C" int func_002093E8(Coll_001953A8* c, int a, int b);
extern "C" void func_00119228(Quat_001953A8* q, float w);
extern "C" void func_00119230(Quat_001953A8* q, float x, float y, float z);
inline Mat_001953A8& Mat_001953A8::operator*=(const Mat_001953A8& o)
{
    func_00323318(this, &o, this);
    return *this;
}
inline void Mat_001953A8::RotX(float a)
{
    Mat_001953A8 t;
    *this *= *func_00100890(&t, a);
}
inline void Mat_001953A8::RotY(float a)
{
    Mat_001953A8 t;
    *this *= *func_00100928(&t, a);
}
inline void Mat_001953A8::RotZ(float a)
{
    Mat_001953A8 t;
    *this *= *func_001009C0(&t, a);
}
extern "C" void func_0019BBB0(Obj_001953A8* o);
extern "C" void func_0019BEA0(Obj_001953A8* o);
extern "C" void func_00186398(void* o, int v);

void Obj_001953A8::Reset(void* src)
{
    Vec_001953A8 pos;
    func_00229FF8(src, &pos);
    Vec_001953A8 rot;
    func_0022A268(src, &rot);
    Mat_001953A8 m;
    m.Identity();
    if (rot.x != 0.0f || rot.y != 0.0f || rot.z != 0.0f) {
        m.RotX(rot.x);
        m.RotY(rot.y);
        m.RotZ(rot.z);
    }
    float h = 0.0f;
    int i = 4;
    while (i-- != 0) {
        Wheel_001953A8* w = &m_wheels[i];
        h += w->mD8 + w->mC4 + 386.4f / (m180 * (float)m_numWheels * w->mE8);
        h -= w->mE0;
    }
    h *= 0.25f;
    Coll_001953A8 coll;
    func_00209280(&coll, pos + Vec_001953A8(0.0f, 24.0f, 0.0f, 1.0f), pos + Vec_001953A8(0.0f, -240.0f, 0.0f, 1.0f));
    if (func_002093E8(&coll, 0, 0))
        pos.y = coll.hit.y - h;
    int idx = -1;
    int k = 4;
    while (k-- != 0) {
        if (!m_wheels[k].mD0) {
            idx = k;
            break;
        }
    }
    float d = m_wheels[idx].mC8;
    pos -= Vec_001953A8(m.r[2].x * d, m.r[2].y * d, m.r[2].z * d, m.r[2].w * d);
    m20 = pos;

    Quat_001953A8 r;
    float tr = m[0][0] + m[1][1] + m[2][2];
    float sq;
    if (tr > 0.0f) {
        sq = sqrtf(tr + 1.0f);
        func_00119228(&r, sq * 0.5f);
        sq = 0.5f / sq;
        func_00119230(&r, (m[2][1] - m[1][2]) * sq, (m[0][2] - m[2][0]) * sq, (m[1][0] - m[0][1]) * sq);
    } else {
        int a = 0;
        if (m[0][0] < m[1][1])
            a = 1;
        if (m[a][a] < m[2][2])
            a = 2;
        int b = (a + 1) % 3;
        int c = (b + 1) % 3;
        sq = sqrtf(m[a][a] - (m[b][b] + m[c][c]) + 1.0f);
        r[a] = sq * 0.5f;
        sq = 0.5f / sq;
        r[b] = (m[b][a] + m[a][b]) * sq;
        r[c] = (m[c][a] + m[a][c]) * sq;
        r[3] = (m[c][b] - m[b][c]) * sq;
    }
    m40 = r;
    m30.Set(0.0f, 0.0f, 0.0f);
    m50.Set(0.0f, 0.0f, 0.0f);
    m1384 = 1;
    int n = 60;
    while (n-- != 0) {
        int j = m_numWheels;
        while (j-- != 0)
            m_wheels[j].m8 = 0;
        V1();
    }
    m1384 = 0;
    m30.Set(0.0f, 0.0f, 0.0f);
    m50.Set(0.0f, 0.0f, 0.0f);
    m128 = 1;
    m60 = 0;
    mC->m50 = m20;
    mC->mB0 = mB0;
    Mat_001953A8* dm = &mC->m70;
    *dm = m70;
    dm = &mC->mC0;
    *dm = mC->m70;
    func_0019BBB0(this);
    func_0019BEA0(this);
    func_00186398(mC, 1);
    func_00186398(m1388, 1);
}
