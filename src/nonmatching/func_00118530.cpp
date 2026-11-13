/* fuzzy: 89.4 */
/* sym: _vt$10Comp118530 = 0x0035C638 */
typedef int qword __attribute__((mode(TI)));

extern "C" float func_00341068(float x);
extern "C" float func_00340F60(float x);
extern "C" float sqrtf(float);
struct Quat118530;
extern "C" void func_00119230(Quat118530* q, float x, float y, float z);
extern "C" void func_00119228(Quat118530* q, float w);

struct Vec118530 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec118530() {}
    Vec118530(float ax, float ay, float az, float aw = 1.0f) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vec118530 operator*(const Vec118530& v, float s)
{
    return Vec118530(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec118530 operator+(const Vec118530& a, const Vec118530& b)
{
    return Vec118530(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec118530 Cross118530(const Vec118530& a, const Vec118530& b)
{
    return Vec118530(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot118530(const Vec118530& a, const Vec118530& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat118530 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat118530() {}
    Quat118530(const Vec118530& axis, float half)
    {
        float s = axis.Length();
        s = (s > 0.0f) ? 1.0f / s : 0.0f;
        s *= func_00341068(half);
        func_00119230(this, s * axis.x, s * axis.y, s * axis.z);
        func_00119228(this, func_00340F60(half));
    }
    void Identity() { w = 1.0f; x = 0.0f; y = 0.0f; z = 0.0f; }
    void operator*=(const Quat118530& b)
    {
        Vec118530 va;
        Vec118530 vb;
        va.q = q;
        vb.q = b.q;
        Vec118530 r = vb * w + va * b.w + Cross118530(va, vb);
        x = r.x;
        y = r.y;
        z = r.z;
        w = w * b.w - Dot118530(va, vb);
    }
};

static inline Quat118530 operator*(const Quat118530& a, const Quat118530& b)
{
    Quat118530 r;
    r.q = a.q;
    Vec118530 va;
    Vec118530 vb;
    va.q = r.q;
    vb.q = b.q;
    Vec118530 v = vb * r.w + va * b.w + Cross118530(va, vb);
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = r.w * b.w - Dot118530(va, vb);
    return r;
}

struct Base118238 {
    int m_pad[5];
    Base118238();
    virtual ~Base118238();
};

struct Comp118530 : Base118238 {
    int m18[2];
    Quat118530 m20;
    Vec118530 m30;
    int m40;
    Comp118530(int a, const Quat118530& rot, const Vec118530& pos, int t);
    virtual ~Comp118530();
    virtual void F2();
    virtual void F3();
};

Comp118530::Comp118530(int a, const Quat118530& rot, const Vec118530& pos, int t)
{
    m20.Identity();
    Quat118530 q(Vec118530(1.0f, 0.0f, 0.0f), 0.78539824f);
    m20 = rot * q;
    m30.x = pos.x;
    m30.y = pos.z;
    m30.z = -pos.y;
    m30.w = 1.0f;
    m40 = t;
}
