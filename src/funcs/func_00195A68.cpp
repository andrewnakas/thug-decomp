typedef int qword __attribute__((mode(TI)));

struct Vec_00195A68 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00195A68() {}
    Vec_00195A68(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00195A68& operator+=(const Vec_00195A68& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_00195A68 operator*(const Vec_00195A68& v, float s)
{
    return Vec_00195A68(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_00195A68 operator+(const Vec_00195A68& a, const Vec_00195A68& b)
{
    return Vec_00195A68(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Mat_00195A68 {
    Vec_00195A68 r[3];
    Vec_00195A68 Rotate(float x, float y, float z, const float& w) const
    {
        Vec_00195A68 o;
        o.x = x * r[0].x + y * r[1].x + z * r[2].x;
        o.y = x * r[0].y + y * r[1].y + z * r[2].y;
        o.z = x * r[0].z + y * r[1].z + z * r[2].z;
        o.w = w;
        return o;
    }
    Vec_00195A68 Rotate(const Vec_00195A68& p) const
    {
        Vec_00195A68 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

struct Obj_00195A68 {
    char pad0[0x30];
    Vec_00195A68 m_mom;
    Vec_00195A68 m40;
    Vec_00195A68 m_angMom;
    int m60;
    int m64;
    char pad68[0xB0 - 0x68];
    Vec_00195A68 m_vel;
    Vec_00195A68 m_angVel;
    Mat_00195A68 m_invInertia;
    char pad100[0x134 - 0x100];
    float m134;
    char pad138[0x180 - 0x138];
    float m_invMass;
    char pad184[0x190 - 0x184];
    float m_inertia;
    void Apply(const Vec_00195A68& imp, const Vec_00195A68& t)
    {
        m_mom += imp * (1.0f / m_invMass);
        m_angMom += t * (1.0f / m_inertia);
    }
    Vec_00195A68 RotAng() const
    {
        return m_invInertia.Rotate(m_angMom.x, m_angMom.y, m_angMom.z, m_angMom.w);
    }
    void UpdateVel()
    {
        m_vel = Vec_00195A68(m_mom.x * m_invMass, m_mom.y * m_invMass, m_mom.z * m_invMass, m_mom.w * m_invMass);
        m_vel.w = 0.0f;
        m_angVel = RotAng();
    }
};

extern "C" void func_003233B8(Vec_00195A68* d, Vec_00195A68* s);
extern "C" float func_001000D0(float range);
extern "C" float func_001E5318(unsigned int name, int v);

extern "C" void func_00195A68(Obj_00195A68* o, const Vec_00195A68* in)
{
    Vec_00195A68 dir = *in;
    dir.y = 0.0f;
    func_003233B8(&dir, &dir);
    Vec_00195A68 side(-dir.z, 0.0f, dir.x, 1.0f);
    float f = (func_001000D0(0.5f) + 1.0f) * func_001E5318(0x3DB3FA83, 0);
    float s = func_001000D0(1.5f) * func_001E5318(0x39E99FEC, 0);
    float u = (func_001000D0(0.2f) + 1.0f) * func_001E5318(0x738500FD, 0);
    Vec_00195A68 imp = dir * f + side * s;
    imp.y += u;
    float ts = func_001000D0(1.5f) * func_001E5318(0x14DDB3EF, 0);
    float tf = (func_001000D0(0.8f) + 1.0f) * func_001E5318(0x4088E6EC, 0);
    Vec_00195A68 t = side * tf;
    t.y += ts;
    o->Apply(imp, t);
    o->UpdateVel();
    o->m134 = func_001E5318(0x771922A6, 0);
    o->m60 = 1;
    o->m64 = 0;
}
