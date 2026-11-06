typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00196678 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00196678() {}
    Vec_00196678(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00196678& operator+=(const Vec_00196678& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
        return *this;
    }
};


static inline Vec_00196678 operator*(const Vec_00196678& v, float s)
{
    return Vec_00196678(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_00196678 operator+(const Vec_00196678& a, const Vec_00196678& b)
{
    return Vec_00196678(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00196678 AddTo(float x, float y, float z, float w, const Vec_00196678& b)
{
    return Vec_00196678(x + b.x, y + b.y, z + b.z, w + b.w);
}

static inline Vec_00196678 Cross_00196678(const Vec_00196678& a, const Vec_00196678& b)
{
    return Vec_00196678(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot_00196678(const Vec_00196678& a, const Vec_00196678& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Quat_00196678;
extern "C" float func_0011D4C0(Quat_00196678* q);

struct Quat_00196678 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat_00196678() {}
    Quat_00196678(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Quat_00196678& operator+=(const Quat_00196678& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
        return *this;
    }
    float Length() { return sqrtf(func_0011D4C0(this)); }
    void Normalize(float len = 1.0f)
    {
        float l = Length();
        if (l > 0.0f) {
            float inv = len / l;
            x *= inv;
            y *= inv;
            z *= inv;
            w *= inv;
        }
    }
};

static inline Quat_00196678 operator*(const Quat_00196678& a, const Quat_00196678& b)
{
    Quat_00196678 r(a);
    float bw = b.w;
    Vec_00196678 va;
    Vec_00196678 vb;
    va.q = r.q;
    vb.q = b.q;
    Vec_00196678 v = vb * r.w + va * bw + Cross_00196678(va, vb);
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = r.w * bw - Dot_00196678(va, vb);
    return r;
}

struct Mat_00196678 {
    Vec_00196678 r[4];
    Vec_00196678 Rotate(float x, float y, float z, const float& w) const
    {
        Vec_00196678 o;
        o.x = x * r[0].x + y * r[1].x + z * r[2].x;
        o.y = x * r[0].y + y * r[1].y + z * r[2].y;
        o.z = x * r[0].z + y * r[1].z + z * r[2].z;
        o.w = w;
        return o;
    }
};

struct Obj_00196678;
extern "C" void func_0019AD48(Obj_00196678* self, const Vec_00196678& f);
extern "C" void func_00196B40(Obj_00196678* self);
extern "C" void func_0019B080(Obj_00196678* self);
extern "C" void func_00195E38(Obj_00196678* self);
extern "C" void func_00196BE0(Obj_00196678* self);

struct Obj_00196678 {
    char pad0[0x30];
    Vec_00196678 m30;
    Quat_00196678 m40;
    Vec_00196678 m50;
    char pad60[0xB0 - 0x60];
    Vec_00196678 mB0;
    Vec_00196678 mC0;
    Mat_00196678 mD0;
    char pad110[0x120 - 0x110];
    int m120;
    char pad124[0x140 - 0x124];
    Vec_00196678 m140;
    Vec_00196678 m150;
    float m160;
    char pad164[0x180 - 0x164];
    float m180;
    char pad184[0x1370 - 0x184];
    float m1370;
    void Step();
};

void Obj_00196678::Step()
{
    Vec_00196678 v(m140.x * m180, m140.y * m180, m140.z * m180, m140.w * m180);
    Vec_00196678 w = mD0.Rotate(m150.x, m150.y, m150.z, m150.w);
    m30 += Vec_00196678(m140.x * m160, m140.y * m160, m140.z * m160, m140.w * m160);
    func_0019AD48(this, AddTo(mB0.x, mB0.y, mB0.z, mB0.w, v * (m160 * 0.5f)) * m160);
    float k = m160 * -0.5f;
    float h = m160 * 0.5f;
    Vec_00196678 s = Vec_00196678(mC0.x + w.x * h, mC0.y + w.y * h, mC0.z + w.z * h, mC0.w + w.w * h) * k;
    Quat_00196678 d = m40 * Quat_00196678(s.x, s.y, s.z, 0.0f);
    m40 += d;
    m40.Normalize();
    m50 += Vec_00196678(m150.x * m160, m150.y * m160, m150.z * m160, m150.w * m160);
    func_00196B40(this);
    if (m120 == 0 && m1370 == 0.0f) {
        func_0019B080(this);
    }
    func_00195E38(this);
    func_00196BE0(this);
}
