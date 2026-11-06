typedef int qword_0015F180 __attribute__((mode(TI)));

struct V4_0015F180 {
    union {
        qword_0015F180 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_0015F180() {}
    V4_0015F180(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_0015F180& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

static inline void Swap_0015F180(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}

struct Mat_0015F180;
extern "C" void func_00323298(V4_0015F180* d, Mat_0015F180* m, V4_0015F180* s);

struct Mat_0015F180 {
    V4_0015F180 r[4];
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
    void Apply(V4_0015F180* d, V4_0015F180* v)
    {
        func_00323298(d, this, v);
    }
    void Transpose()
    {
        Swap_0015F180(r[0].y, r[1].x);
        Swap_0015F180(r[0].z, r[2].x);
        Swap_0015F180(r[0].w, r[3].x);
        Swap_0015F180(r[1].z, r[2].y);
        Swap_0015F180(r[1].w, r[3].y);
        Swap_0015F180(r[2].w, r[3].z);
    }
};

struct FCol_0015F180 {
    float r, g, b, a;
};

struct Col_0015F180 {
    unsigned char r, g, b, a;
};

extern "C" void func_003233B8(V4_0015F180* d, V4_0015F180* s);

struct C_0015F180 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x110];
    float m16C, m170, m174, m178, m17C;
    char pad180[0x8];
    float m188, m18C, m190, m194;
    char pad198[0x4];
    float m19C;
    char pad1A0[0x4];
    float m1A4, m1A8, m1AC, m1B0, m1B4;
    char pad1B8[0x2C];
    float m1E4;
    char pad1E8[0x18];
    Col_0015F180 m200[3];
    char pad20C[0x28];
    float m234;
    Mat_0015F180 m240;
    char pad280[0x60];
    V4_0015F180 m2E0;
    V4_0015F180 m2F0;
    V4_0015F180 m300;
    V4_0015F180 m310;
    V4_0015F180 m320;
    V4_0015F180 m330;
    FCol_0015F180 m340;
    FCol_0015F180 m350;
    FCol_0015F180 m360;
    float m370;
    void Init();
    void Xform(V4_0015F180& p, const V4_0015F180& d, Mat_0015F180& m)
    {
        V4_0015F180 t(p.x + d.x * 1.5f, p.y + d.y * 1.5f, p.z + d.z * 1.5f, 0.0f);
        func_00323298(&t, &m, &t);
        p.x = t.x - d.x * 1.5f;
        p.y = t.y - d.y * 1.5f;
        p.z = t.z - d.z * 1.5f;
    }
};

void C_0015F180::Init()
{
    m234 = (m1A4 + m1A8) * 0.5f;
    float r;
    if (m1E4 <= 0.0f) {
        r = 0.0f;
    } else if (m1E4 >= 100.0f) {
        r = m234;
    } else {
        r = m1E4 * 0.01f * m234;
    }
    m370 = r;
    m310.x = m174;
    m310.y = 0.0f;
    m310.z = m178;
    m310.w = 0.0f;
    m2E0.x = m50 - m174 * 1.5f;
    m2E0.y = m54 - m310.y * 1.5f;
    m2E0.z = m58 - m178 * 1.5f;
    m2E0.w = m194;
    float speed = (m16C + m170) * 30.0f;
    V4_0015F180 dir(m1AC, m1B0, m1B4, 0.0f);
    func_003233B8(&dir, &dir);
    dir *= speed;
    float ang = m17C * 1.57079637f;
    float a = speed * ang;
    float b = (m170 - m16C) * 60.0f;
    m320.x = a;
    m320.y = b;
    m320.z = a;
    m320.w = 0.0f;
    m330.x = 0.0f;
    m330.y = 0.0f;
    m330.z = 0.0f;
    m330.w = 0.0f;
    m2F0.x = dir.x - m320.x * 1.5f;
    m2F0.y = dir.y - m320.y * 1.5f;
    m2F0.z = dir.z - m320.z * 1.5f;
    m2F0.w = (m19C - m194) / m234;
    m300.x = m188 * 1800.0f;
    m300.y = m18C * 1800.0f;
    m300.z = m190 * 1800.0f;
    m300.w = -m320.w;
    if (0.0f <= m1E4) {
        float i1 = 1.0f / r;
        float i2 = 1.0f / (m234 - r);
        m340.r = ((float)m200[1].r - (float)m200[0].r) * i1;
        m340.g = ((float)m200[1].g - (float)m200[0].g) * i1;
        m340.b = ((float)m200[1].b - (float)m200[0].b) * i1;
        m340.a = ((float)m200[1].a - (float)m200[0].a) * i1;
        m350.r = m200[1].r;
        m350.g = m200[1].g;
        m350.b = m200[1].b;
        m350.a = m200[1].a;
        m360.r = ((float)m200[2].r - (float)m200[1].r) * i2;
        m360.g = ((float)m200[2].g - (float)m200[1].g) * i2;
        m360.b = ((float)m200[2].b - (float)m200[1].b) * i2;
        m360.a = ((float)m200[2].a - (float)m200[1].a) * i2;
    } else {
        float i2 = 1.0f / m234;
        m350.r = m200[0].r;
        m350.g = m200[0].g;
        m350.b = m200[0].b;
        m350.a = m200[0].a;
        m360.r = ((float)m200[2].r - (float)m200[0].r) * i2;
        m360.g = ((float)m200[2].g - (float)m200[0].g) * i2;
        m360.b = ((float)m200[2].b - (float)m200[0].b) * i2;
        m360.a = ((float)m200[2].a - (float)m200[0].a) * i2;
    }
    m240.Ident();
    Mat_0015F180 t = m240;
    V4_0015F180 v;
    V4_0015F180* pv = &v;
    t.Transpose();
    v.Set(m2E0.x + m310.x * 1.5f, m2E0.y + m310.y * 1.5f, m2E0.z + m310.z * 1.5f, 0.0f);
    t.Apply(pv, pv);
    m2E0.x = v.x - m310.x * 1.5f;
    m2E0.y = v.y - m310.y * 1.5f;
    m2E0.z = v.z - m310.z * 1.5f;
    v.Set(m2F0.x + m320.x * 1.5f, m2F0.y + m320.y * 1.5f, m2F0.z + m320.z * 1.5f, 0.0f);
    t.Apply(pv, pv);
    m2F0.x = v.x - m320.x * 1.5f;
    m2F0.y = v.y - m320.y * 1.5f;
    m2F0.z = v.z - m320.z * 1.5f;
    v.Set(m300.x + m330.x * 1.5f, m300.y + m330.y * 1.5f, m300.z + m330.z * 1.5f, 0.0f);
    t.Apply(pv, pv);
    m300.x = v.x - m330.x * 1.5f;
    m300.y = v.y - m330.y * 1.5f;
    m300.z = v.z - m330.z * 1.5f;
}
