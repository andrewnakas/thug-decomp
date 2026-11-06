/* fuzzy: 88.0 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_00195E38 {
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
};

struct Quat_00195E38;
struct Mat_00195E38 {
    Vec_00195E38 r[4];
    Vec_00195E38& operator[](int i) { return r[i]; }
};

struct Quat_00195E38 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float& operator[](int i) { return (&x)[i]; }
    float LengthSqr() const { return x * x + y * y + z * z + w * w; }
    void GetMatrix(Mat_00195E38& m, float s) const;
};

inline void Quat_00195E38::GetMatrix(Mat_00195E38& m, float s) const
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

struct Slerp_00195E38 {
    char pad0[0x90];
    float m90;
    char pad94[0xA0 - 0x94];
};

extern "C" void func_003233B8(Vec_00195E38* d, Vec_00195E38* s);
extern "C" unsigned int func_0010FC30();
extern "C" float func_0010FAB8();
extern "C" void* func_00102FD0(Slerp_00195E38* s);
extern "C" void func_00103000(Slerp_00195E38* s, Mat_00195E38* from, Mat_00195E38* to);
extern "C" void func_00103930(Slerp_00195E38* s, float t, Mat_00195E38* out);
extern "C" void func_00119228(Quat_00195E38* q, float w);
extern "C" void func_00119230(Quat_00195E38* q, float x, float y, float z);

static inline unsigned int Elapsed(unsigned int since)
{
    return func_0010FC30() - since;
}

struct Obj_00195E38 {
    char pad0[0x30];
    Vec_00195E38 m_mom;
    Quat_00195E38 m_rot;
    Vec_00195E38 m_angMom;
    char pad60[0x70 - 0x60];
    Mat_00195E38 m_mat;
    Vec_00195E38 m_vel;
    Vec_00195E38 m_angVel;
    char padD0[0x120 - 0xD0];
    int m120;
    char pad124[0x12C - 0x124];
    int m_resting;
    unsigned int m_restTime;
    char pad134[0x350 - 0x134];
    int m350;
    char pad354[0x1370 - 0x354];
    float m1370;
    void Update();
};

void Obj_00195E38::Update()
{
    m_rot.GetMatrix(m_mat, m_rot.x * m_rot.x + m_rot.y * m_rot.y + m_rot.z * m_rot.z + m_rot.w * m_rot.w);
    Vec_00195E38& pos = m_mat[3];
    pos.Set(0.0f, 0.0f, 0.0f);

    float up = m_mat[1][1];
    if (up > 0.999f) {
        m_resting = 0;
        return;
    }
    bool still = false;
    if (m_vel.LengthSqr() < 90000.0f && m_angVel.LengthSqr() < 0.6168503165f && pos.y < m1370 && up < 0.25f
        && (m120 == 0 || up < pos.y)) {
        still = m350 != 0;
    }
    if (!m_resting) {
        if (!still)
            return;
        m_mom.Set(0.0f, 0.0f, 0.0f);
        m_angMom.Set(0.0f, 0.0f, 0.0f);
        m_resting = 1;
        m_restTime = func_0010FC30();
    }
    if (Elapsed(m_restTime) >= 5301) {
        m_resting = 0;
        return;
    }
    if (Elapsed(m_restTime) < 300)
        return;

    Mat_00195E38 target;
    target.r[2] = m_mat.r[2];
    target.r[2].y = 0.0f;
    func_003233B8(&target.r[2], &target.r[2]);
    target.r[1].Set(0.0f, 1.0f, 0.0f);
    target.r[0].Set(target.r[2].z, 0.0f, -target.r[2].x);
    Slerp_00195E38 slerp;
    func_00102FD0(&slerp);
    func_00103000(&slerp, &m_mat, &target);
    float t = func_0010FAB8() * 3.0f / slerp.m90;
    if (t > 1.0f)
        t = 1.0f;
    func_00103930(&slerp, t, &m_mat);

    Quat_00195E38 r;
    Mat_00195E38& m = m_mat;
    float tr = m[0][0] + m[1][1] + m[2][2];
    float sq;
    if (tr > 0.0f) {
        sq = sqrtf(tr + 1.0f);
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
        sq = sqrtf(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
        r[i] = sq * 0.5f;
        sq = 0.5f / sq;
        r[j] = (m[j][i] + m[i][j]) * sq;
        r[k] = (m[k][i] + m[i][k]) * sq;
        r[3] = (m[k][j] - m[j][k]) * sq;
    }
    m_rot = r;
}
