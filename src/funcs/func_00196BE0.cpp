typedef int qword __attribute__((mode(TI)));

struct Vec_00196BE0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00196BE0() {}
    Vec_00196BE0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

struct Mat_00196BE0 {
    Vec_00196BE0 r[4];
    Vec_00196BE0 Rotate(const float& x, const float& y, const float& z, const float& w) const
    {
        Vec_00196BE0 o;
        o.x = x * r[0].x + y * r[1].x + z * r[2].x;
        o.y = x * r[0].y + y * r[1].y + z * r[2].y;
        o.z = x * r[0].z + y * r[1].z + z * r[2].z;
        o.w = w;
        return o;
    }
};

struct Quat_00196BE0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    void GetMatrix(Mat_00196BE0& m, float s) const;
};

inline void Quat_00196BE0::GetMatrix(Mat_00196BE0& m, float s) const
{
    s = (s > 0.0f) ? 2.0f / s : 0.0f;
    float xs = x * s;
    float ys = y * s;
    float zs = z * s;
    float wx = w * xs;
    float wy = w * ys;
    float wz = w * zs;
    float xx = x * xs;
    float xy = x * ys;
    float xz = x * zs;
    float yy = y * ys;
    float yz = y * zs;
    float zz = z * zs;
    m.r[0].x = 1.0f - (yy + zz);
    m.r[1].x = xy + wz;
    m.r[2].x = xz - wy;
    m.r[0].y = xy - wz;
    m.r[1].y = 1.0f - (xx + zz);
    m.r[2].y = yz + wx;
    m.r[0].z = xz + wy;
    m.r[1].z = yz - wx;
    m.r[2].z = 1.0f - (xx + yy);
}

struct Wheel_00196BE0 {
    char pad0[0x90];
    Vec_00196BE0 m90;
    Vec_00196BE0 mA0;
    Vec_00196BE0 mB0;
    Vec_00196BE0 mC0;
    char padD0[0xD8 - 0xD0];
    float mD8;
    char padDC[0xE0 - 0xDC];
    float mE0;
    char padE4[0x220 - 0xE4];
};

struct Point_00196BE0 {
    Vec_00196BE0 m0;
    Vec_00196BE0 m10;
    Vec_00196BE0 m20;
    Vec_00196BE0 m30;
    Vec_00196BE0 m40;
    Vec_00196BE0 m50;
    Vec_00196BE0 m60;
    Vec_00196BE0 m70;
    float m80;
    float m84;
    char pad88[0x90 - 0x88];
    void Update(const struct Obj_00196BE0* o);
};

struct Obj_00196BE0 {
    char pad0[0x20];
    Vec_00196BE0 m_pos;
    Vec_00196BE0 m_mom;
    Quat_00196BE0 m_rot;
    Vec_00196BE0 m_angMom;
    char pad60[0x70 - 0x60];
    Mat_00196BE0 m_mat;
    Vec_00196BE0 m_vel;
    Vec_00196BE0 m_angVel;
    Mat_00196BE0 m_invInertia;
    Vec_00196BE0 m110;
    char pad120[0x170 - 0x120];
    Vec_00196BE0 m170;
    float m_invMass;
    char pad184[0x1C4 - 0x184];
    int m_numWheels;
    char pad1C8[0x1E0 - 0x1C8];
    Point_00196BE0 m_points[2];
    char pad300[0x318 - 0x300];
    Wheel_00196BE0* m_wheels;
    Vec_00196BE0 Offset(const Vec_00196BE0& t) const
    {
        return Vec_00196BE0(m_pos.x + t.x, m_pos.y + t.y, m_pos.z + t.z, m_pos.w + t.w);
    }
    void Update();
};

inline void Point_00196BE0::Update(const Obj_00196BE0* o)
{
    m30 = o->Offset(o->m_mat.Rotate(m0.x, m0.y, m0.z, m0.w));
    m40 = o->m_mat.Rotate(m10.x, m10.y, m10.z, m10.w);
    m50 = o->m_mat.Rotate(m20.x, m20.y, m20.z, m20.w);
    float a = 1.0f / m80;
    m60 = Vec_00196BE0(m40.x * a, m40.y * a, m40.z * a, m40.w * a);
    float b = 1.0f / m84;
    m70 = Vec_00196BE0(m50.x * b, m50.y * b, m50.z * b, m50.w * b);
}

extern "C" void func_001976A8(Obj_00196BE0* o);
extern "C" void func_001978D0(Obj_00196BE0* o);

void Obj_00196BE0::Update()
{
    m_rot.GetMatrix(m_mat, m_rot.x * m_rot.x + m_rot.y * m_rot.y + m_rot.z * m_rot.z + m_rot.w * m_rot.w);
    Vec_00196BE0& pos = m_mat.r[3];
    pos.Set(0.0f, 0.0f, 0.0f);
    m110 = m_mat.Rotate(m170.x, m170.y, m170.z, m170.w);
    func_001976A8(this);
    m_vel = Vec_00196BE0(m_mom.x * m_invMass, m_mom.y * m_invMass, m_mom.z * m_invMass, m_mom.w * m_invMass);
    m_vel.w = 0.0f;
    m_angVel = m_invInertia.Rotate(m_angMom.x, m_angMom.y, m_angMom.z, m_angMom.w);

    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00196BE0* w = &m_wheels[i];
        w->m90 = Offset(m_mat.Rotate(w->mC0.x, w->mC0.y, w->mC0.z, w->mC0.w));
        w->mA0 = w->mC0;
        w->mA0.y += w->mD8 - w->mE0;
        w->mA0 = Offset(m_mat.Rotate(w->mA0.x, w->mA0.y, w->mA0.z, w->mA0.w));
    }
    int j = 2;
    while (j-- != 0) {
        Point_00196BE0& p = m_points[j];
        p.Update(this);
    }
    func_001978D0(this);
}
