/* fuzzy: 65.2 */
extern "C" float sqrtf(float);
typedef int qword __attribute__((mode(TI)));

struct Vec_0014B1B0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0014B1B0() {}
    Vec_0014B1B0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vec_0014B1B0 operator-(const Vec_0014B1B0& a, const Vec_0014B1B0& b)
{
    return Vec_0014B1B0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0014B1B0 operator-(const Vec_0014B1B0& a)
{
    Vec_0014B1B0 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    r.w = -a.w;
    return r;
}

struct Light_0014B1B0 {
    Vec_0014B1B0 m_pos;
    float m10;
    float m_falloff;
    float m_scale;
    unsigned char m_col[4];
};

struct Model_0014B1B0 {
    unsigned int m_flags;
    char pad4[0x2C];
    Vec_0014B1B0 m_dir;
    char pad40[0x20];
    Vec_0014B1B0 m_col;
    char pad70[0x30];
    Vec_0014B1B0 m_baseCol;
    void SetDir(const Vec_0014B1B0& v)
    {
        m_flags |= 8;
        m_dir = v;
    }
    void SetColor(const Vec_0014B1B0& v)
    {
        m_col = v;
        if (!(m_flags & 0x80)) {
            m_baseCol = v;
        }
    }
};

extern "C" Light_0014B1B0* func_00136628(Vec_0014B1B0* pos);
extern "C" void func_003233B8(Vec_0014B1B0* d, Vec_0014B1B0* s);

class Base_0014B1B0 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Vec_0014B1B0* m14;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void SetLit(int a, bool on);
};

class Comp_0014B1B0 : public Base_0014B1B0 {
public:
    Model_0014B1B0* m1C;
    void Light(Vec_0014B1B0* pos, bool enable);
};

void Comp_0014B1B0::Light(Vec_0014B1B0* pos, bool enable)
{
    if (!enable) {
        return;
    }
    if (m14) {
        *pos = *m14;
    }
    Light_0014B1B0* l = func_00136628(pos);
    if (l) {
        Vec_0014B1B0 c = l->m_pos;
        Vec_0014B1B0 d = *pos - c;
        float f = d.Length() * l->m_falloff;
        Vec_0014B1B0 n = *pos - c;
        func_003233B8(&n, &n);
        m1C->SetDir(-n);
        float k = sqrtf(1.0f - f) * l->m_scale;
        unsigned char* col = l->m_col;
        m1C->SetColor(Vec_0014B1B0(k * col[0], k * col[1], k * col[2], 0.0f));
        SetLit(2, true);
    } else {
        SetLit(2, false);
    }
}
