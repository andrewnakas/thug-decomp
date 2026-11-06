/* fuzzy: 80.1 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_0019B080 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float& operator[](int i) { return (&x)[i]; }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    float LengthSqr() const { return x * x + y * y + z * z; }
    void Normalize();
    void Negate()
    {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
};

struct Quat_0019B080;
struct Mat_0019B080 {
    Vec_0019B080 r[4];
    Vec_0019B080& operator[](int i) { return r[i]; }
};

struct Quat_0019B080 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float& operator[](int i) { return (&x)[i]; }
    float LengthSqr() const { return x * x + y * y + z * z + w * w; }
    void GetMatrix(Mat_0019B080& m, float s) const;
};

inline void Quat_0019B080::GetMatrix(Mat_0019B080& m, float s) const
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
    m[0][0] = 1.0f - (yy + zz);
    m[1][0] = xy + wz;
    m[2][0] = xz - wy;
    m[0][1] = xy - wz;
    m[1][1] = 1.0f - (xx + zz);
    m[2][1] = yz + wx;
    m[0][2] = xz + wy;
    m[1][2] = yz - wx;
    m[2][2] = 1.0f - (xx + yy);
}

struct Slerp_0019B080 {
    char pad0[0x90];
    float m90;
    char pad94[0xA0 - 0x94];
};

extern "C" void func_003233B8(Vec_0019B080* d, Vec_0019B080* s);
extern "C" void* func_00102FD0(Slerp_0019B080* s);
extern "C" void func_00103000(Slerp_0019B080* s, Mat_0019B080* from, Mat_0019B080* to);
extern "C" void func_00103930(Slerp_0019B080* s, float t, Mat_0019B080* out);
extern "C" void func_00119228(Quat_0019B080* q, float w);
extern "C" void func_00119230(Quat_0019B080* q, float x, float y, float z);

struct Obj_0019B080 {
    char pad0[0x30];
    Vec_0019B080 m_mom;
    Quat_0019B080 m_rot;
    Vec_0019B080 m_angMom;
    char pad60[0x70 - 0x60];
    Mat_0019B080 m_mat;
    Vec_0019B080 m_vel;
    char padC0[0x12C - 0xC0];
    int m_resting;
    char pad130[0x134 - 0x130];
    float m134;
    char pad138[0x160 - 0x138];
    float m_dt;
    char pad164[0x1B4 - 0x164];
    float m1B4;
    float m1B8;
    float m1BC;
    int m1C0;
    char pad1C4[0x136C - 0x1C4];
    float m136C;
    bool Busy() { return m134 > 0.0f; }
    void Right();
};

inline void Vec_0019B080::Normalize()
{
    func_003233B8(this, this);
}

struct VecR_0019B080 : Vec_0019B080 {
    VecR_0019B080(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline VecR_0019B080 Cross(const Vec_0019B080& a, const Vec_0019B080& b)
{
    return VecR_0019B080(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

void Obj_0019B080::Right()
{
    if (m_resting)
        return;
    if (Busy())
        return;
    bool slow = m_vel.x * m_vel.x + m_vel.z * m_vel.z < m1B4 * m1B4;
    if (slow && !m1C0)
        return;
    m_rot.GetMatrix(m_mat, m_rot.x * m_rot.x + m_rot.y * m_rot.y + m_rot.z * m_rot.z + m_rot.w * m_rot.w);
    Vec_0019B080& pos = m_mat[3];
    pos.Set(0.0f, 0.0f, 0.0f);

    Mat_0019B080 target;
    if (slow) {
        target.r[2] = m_mat.r[2];
        target.r[2].y = 0.0f;
        target.r[2].Normalize();
    } else {
        target.r[2] = m_vel;
        target.r[2].Normalize();
    }
    if (target.r[2].x * m_mat.r[2].x + target.r[2].y * m_mat.r[2].y + target.r[2].z * m_mat.r[2].z < 0.0f) {
        target.r[2].Negate();
    }
    target.r[1].Set(0.0f, 1.0f, 0.0f);
    target.r[0] = Cross(target.r[1], target.r[2]);
    target.r[1] = Cross(target.r[2], target.r[0]);
    target.r[3].Set(0.0f, 0.0f, 0.0f);
    Slerp_0019B080 slerp;
    func_00102FD0(&slerp);
    func_00103000(&slerp, &m_mat, &target);
    if (m_vel.x * m_vel.x + m_vel.z * m_vel.z > 122500.0f) {
        float lim = m136C < m1B8 ? m136C : m1B8;
        func_00103930(&slerp, m1BC * m_dt * (lim / m1B8), &m_mat);
    } else {
        float lim = m136C < m1B8 ? m136C : m1B8;
        func_00103930(&slerp, m1BC * (m_dt * 0.3f) * (lim / m1B8), &m_mat);
    }

    Quat_0019B080 r;
    Mat_0019B080& m = m_mat;
    float tr = m[0][0] + m[1][1] + m[2][2];
    if (tr > 0.0f) {
        float sq = sqrtf(tr + 1.0f);
        float h = sq * 0.5f;
        sq = 0.5f / sq;
        func_00119228(&r, h);
        func_00119230(&r, (m[2][1] - m[1][2]) * sq, (m[0][2] - m[2][0]) * sq, (m[1][0] - m[0][1]) * sq);
    } else {
        int i = 0;
        if (m[0][0] < m[1][1])
            i = 1;
        if (m[i][i] < m[2][2])
            i = 2;
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        float sq = sqrtf(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
        r[i] = sq * 0.5f;
        sq = 0.5f / sq;
        r[j] = (m[j][i] + m[i][j]) * sq;
        r[k] = (m[k][i] + m[i][k]) * sq;
        r[3] = (m[k][j] - m[j][k]) * sq;
    }
    m_rot = r;
}
