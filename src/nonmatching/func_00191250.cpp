/* fuzzy: 48.2 */
/* Rigid-body contact solver for the points in D_003E4540 (0x30 each: position, normal, cached effective mass,
   accumulated normal impulse, rolling factor, in-contact and mass-cached flags). Up to 20 passes of normal
   impulses (restitution m24) until no contact point approaches; on failure it fires the m90 event or zeroes
   both velocities. Then friction impulses (capped by m28 times the normal impulse, optionally constrained to the
   contact's axis in body space), rolling resistance (m2C, scaled by the frame time), optional debug lines, and
   an impact event / sound volume when the deepest approach speed exceeds mA8. */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00191250 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00191250() {}
    Vec_00191250(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00191250(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    Vec_00191250& operator+=(const Vec_00191250& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_00191250& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vec_00191250 operator+(const Vec_00191250& a, const Vec_00191250& b)
{
    return Vec_00191250(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00191250 operator-(const Vec_00191250& a, const Vec_00191250& b)
{
    return Vec_00191250(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_00191250 operator*(const Vec_00191250& a, float s)
{
    return Vec_00191250(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline Vec_00191250 Cross_00191250(const Vec_00191250& a, const Vec_00191250& b)
{
    return Vec_00191250(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot_00191250(const Vec_00191250& a, const Vec_00191250& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Mat_00191250 {
    Vec_00191250 r[3];
};

static inline Vec_00191250 operator*(const Vec_00191250& v, const Mat_00191250& m)
{
    return Vec_00191250(v.x * m.r[0].x + v.y * m.r[1].x + v.z * m.r[2].x,
                        v.x * m.r[0].y + v.y * m.r[1].y + v.z * m.r[2].y,
                        v.x * m.r[0].z + v.y * m.r[1].z + v.z * m.r[2].z, v.w);
}

struct Pt_00191250 {
    Vec_00191250 pos;
    Vec_00191250 normal;
    float m_effMass;
    float m_impulse;
    float m_rolling;
    char m_contact;
    char m_massCached;
    char pad2E[2];
};

struct Contact_00191250 {
    char pad0[0x10];
    Vec_00191250 m_axis;
    char m_hasAxis;
    char pad21[0x30 - 0x21];
};

struct Body_00191250;

extern int D_0038C9AC;
extern int D_0038E0A0;
extern Pt_00191250 D_003E4540[];

extern "C" float func_00191170(Body_00191250* self, Vec_00191250* dir, Vec_00191250* pos);
extern "C" void func_00101890(Vec_00191250* v, const Vec_00191250* n);
extern "C" void func_001235E8(Vec_00191250 a, Vec_00191250 b, unsigned int c0, unsigned int c1, int n);
extern "C" float func_0010FAB8();
extern "C" void* func_00184B30(int a, int b, int c, int d, int e);
extern "C" void func_001EFDC0(void* p);
extern "C" int func_001DD708(int a);
extern "C" void func_001E72B0(int s, unsigned int name, float v);
extern "C" void func_001A3208(int a, int b);

struct Body_00191250 {
    char pad0[0xC];
    int m0C;
    char pad10[0x1C - 0x10];
    float m_invInertia;
    char pad20[0x24 - 0x20];
    float m_restitution;
    float m_friction;
    float m_rolling;
    char pad30[0x50 - 0x30];
    Contact_00191250* m_contacts;
    unsigned short m_numPts;
    char pad56[0x88 - 0x56];
    int m88;
    char pad8C[0x90 - 0x8C];
    int m90;
    int m94;
    char pad98[0x9C - 0x98];
    int m9C;
    char padA0[0xA8 - 0xA0];
    float m_impactMin;
    float m_impactMax;
    char padB0[0xE0 - 0xB0];
    Vec_00191250 m_pos;
    Vec_00191250 m_vel;
    char pad100[0x110 - 0x100];
    Vec_00191250 m_angVel;
    Mat_00191250 m_orient;
    char pad150[0x16C - 0x150];
    int m16C;
    void Solve();
};

void Body_00191250::Solve()
{
    Vec_00191250 vel = m_vel;
    Vec_00191250 angVel = m_angVel;
    float maxApproach = 0.0f;
    int iter = 0;

    for (;;) {
        bool done = true;
        for (int i = m_numPts - 1; i != -1; i--) {
            Pt_00191250* p = &D_003E4540[i];
            if (!p->m_contact)
                continue;
            Vec_00191250 v = m_vel;
            Vec_00191250 c = Cross_00191250(m_angVel, p->pos);
            v.x += c.x;
            v.y += c.y;
            v.z += c.z;
            float dot = Dot_00191250(p->normal, v);
            if (dot > 0.0f)
                continue;
            done = false;
            if (maxApproach < -dot)
                maxApproach = -dot;
            float target = -m_restitution * dot;
            if (!p->m_massCached) {
                p->m_effMass = func_00191170(this, &p->normal, &p->pos);
                p->m_massCached = 1;
            }
            float j = (target - dot) * p->m_effMass;
            p->m_impulse += j;
            Vec_00191250 imp = p->normal;
            imp *= j;
            m_vel += imp;
            m_angVel += Cross_00191250(p->pos, imp) * m_invInertia;
        }
        if (++iter == 20) {
            if (m90) {
                func_001EFDC0(func_00184B30(m0C, m90, m94, 0, 0));
                return;
            }
            m_vel.Set(0.0f, 0.0f, 0.0f);
            m_angVel.Set(0.0f, 0.0f, 0.0f);
            return;
        }
        if (m_numPts == 1 || done)
            break;
    }

    for (int i = m_numPts - 1; i != -1; i--) {
        Pt_00191250* p = &D_003E4540[i];
        Contact_00191250* con = &m_contacts[i];
        if (!p->m_contact)
            continue;
        Vec_00191250 v = vel;
        Vec_00191250 c = Cross_00191250(angVel, p->pos);
        v.x += c.x;
        v.y += c.y;
        v.z += c.z;
        Vec_00191250 t = v + p->normal * -Dot_00191250(p->normal, v);
        if (con->m_hasAxis) {
            Vec_00191250 axis = con->m_axis * m_orient;
            axis = axis - p->normal * Dot_00191250(p->normal, axis);
            float len = axis.Length();
            if (len > 0.001f) {
                axis *= 1.0f / len;
                func_00101890(&t, &axis);
            }
        }
        float speed = t.Length();
        if (speed < 0.001f)
            continue;
        t *= 1.0f / speed;
        float j = speed * func_00191170(this, &t, &p->pos);
        float limit = m_friction * p->m_impulse;
        if (limit < j)
            j = limit;
        Vec_00191250 imp = t;
        imp *= -j;
        if (D_0038C9AC) {
            if (con->m_hasAxis) {
                Vec_00191250 a = p->pos + m_pos;
                func_001235E8(a + Vec_00191250(0.0f, 1.0f, 0.0f), a + imp * 6.0f + Vec_00191250(0.0f, 1.0f, 0.0f),
                              0xFF00FFFF, 0xFF00FFFF, 1);
            } else {
                Vec_00191250 a = p->pos + m_pos;
                func_001235E8(a + Vec_00191250(0.0f, 1.0f, 0.0f), a + imp * 6.0f + Vec_00191250(0.0f, 1.0f, 0.0f),
                              0xFFFF00FF, 0xFFFF00FF, 1);
            }
        }
        Vec_00191250 ang = Cross_00191250(p->pos, imp) * m_invInertia;
        m_vel += imp;
        m_angVel += ang;
        vel += imp;
        angVel += ang;
    }

    float dt = func_0010FAB8();
    for (int i = m_numPts - 1; i != -1; i--) {
        Pt_00191250* p = &D_003E4540[i];
        if (!p->m_contact)
            continue;
        Vec_00191250 imp = p->normal * (-m_rolling * p->m_rolling * dt);
        Vec_00191250 ang = Cross_00191250(p->pos, imp) * m_invInertia;
        m_vel += imp;
        m_angVel += ang;
        if (D_0038C9AC) {
            Vec_00191250 a = p->pos + m_pos;
            func_001235E8(a, a + imp * 60.0f, 0xFF00FFFF, 0xFFFFFFFF, 1);
        }
    }

    if (m_impactMin < maxApproach) {
        if (m88)
            func_001EFDC0(func_00184B30(m0C, m88, m94, 0, 0));
        if (m9C && 0x2A - func_001DD708(D_0038E0A0) >= 0xD) {
            float vol = maxApproach * 100.0f / m_impactMax;
            if (vol > 100.0f)
                vol = 100.0f;
            if (vol < 0.0f)
                vol = 0.0f;
            func_001E72B0(m9C, 0x9E497FC6, vol);
            func_001A3208(m16C, m9C);
        }
    }
}
