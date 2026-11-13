/* fuzzy: 99.1 */
typedef int qword __attribute__((mode(TI)));

union Vec_001CD048 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    Vec_001CD048() {}
    Vec_001CD048(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float Dot3(const Vec_001CD048& o) const { return (*this)[0] * o[0] + (*this)[1] * o[1] + (*this)[2] * o[2]; }
    void operator+=(const Vec_001CD048& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
inline Vec_001CD048 operator*(const Vec_001CD048& a, float k) { return Vec_001CD048(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001CD048 operator+(const Vec_001CD048& a, const Vec_001CD048& b)
{
    return Vec_001CD048(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001CD048 operator-(const Vec_001CD048& a, const Vec_001CD048& b)
{
    return Vec_001CD048(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline Vec_001CD048 operator-(const Vec_001CD048& a) { return Vec_001CD048(-a[0], -a[1], -a[2], -a[3]); }
static inline Vec_001CD048 Cross_001CD048(const Vec_001CD048& a, const Vec_001CD048& b)
{
    return Vec_001CD048(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_001CD048;
/* fills *m with a rotation about X by angle (sin/cos via func_00341068/func_00340F60) and returns m */
extern "C" Mat_001CD048* func_00100890(Mat_001CD048* m, float angle);

struct Mat_001CD048 {
    Vec_001CD048 r0, r1, r2, r3;
    Mat_001CD048& RotX(float angle) { return *func_00100890(this, angle); }
    Vec_001CD048& operator[](int i) { return (&r0)[i]; }
    const Vec_001CD048& Row(int i) const { return (&r0)[i]; }
    Mat_001CD048() {}
    Mat_001CD048(const Mat_001CD048& o)
    {
        r0 = o.Row(0);
        r1 = o.Row(1);
        r2 = o.Row(2);
        r3 = o.Row(3);
    }
    Mat_001CD048& operator=(const Mat_001CD048& o)
    {
        r0 = o.Row(0);
        r1 = o.Row(1);
        r2 = o.Row(2);
        r3 = o.Row(3);
        return *this;
    }
};

/* interpolator between two matrices (func_00102FD8 builds it, func_00103930 evaluates it) */
struct Quat_001CD048 {
    Mat_001CD048 m_from;
    Mat_001CD048 m_to;
    Vec_001CD048 m80;
    float m90;
    int m94;
};

/* the camera object being driven */
struct CamObj_001CD048 {
    char pad0[0x50];
    Vec_001CD048 m_pos;
    char pad60[0x70 - 0x60];
    Mat_001CD048 m_mat;
    char padB0[0x104 - 0xB0];
    unsigned int m_flags;
};

struct Target_001CD048 {
    char pad0[0x50];
    Vec_001CD048 m50;
    char pad60[0x80 - 0x60];
    Vec_001CD048 m80;
    Vec_001CD048 m90;
    char padA0[0xB0 - 0xA0];
    Vec_001CD048 m_vel;
    char padC0[0x104 - 0xC0];
    unsigned int m104;
};

struct Board_001CD048 {
    char pad0[0x24C];
    float m24C;
    float m250;
};
struct Info_001CD048 {
    char pad0[0x24];
    Board_001CD048 m24;
};

struct Skater_001CD048 {
    char pad0[0x1C];
    int m1C;
    unsigned int m20;
    unsigned int m24;
    char pad28[0x60 - 0x28];
    Vec_001CD048 m60;
    char pad70[0xB4 - 0x70];
    int mB4;
    char padB8[0x95C - 0xB8];
    int m95C;
    char pad960[0xA28 - 0x960];
    Info_001CD048* mA28;
    char padA2C[0xA60 - 0xA2C];
    int mA60;
    int State() const { return m1C; }
};

struct Lock_001CD048 {
    char pad0[0x180];
    int m180;
};
struct Locker_001CD048 {
    char pad0[0x34];
    Lock_001CD048* m34;
};

struct Mode_001CD048 {
    char pad0[0x28];
    float m28;
    float m2C;
};

struct Tune_001CD048 {
    char pad0[0x124];
    float m124;
};

struct Comp_001CD048 {
    char pad0[0x278];
    float m278;
};

struct Cam_001CD048;
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern float D_00387B48;
extern float D_00387B4C;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_001B80F8(int a);
extern "C" float func_0010FAB8();
extern "C" unsigned int func_0010FC30();
extern "C" Comp_001CD048* func_00185578(CamObj_001CD048* o, unsigned int name);
extern "C" void func_003233B8(Vec_001CD048* d, Vec_001CD048* s);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);
extern "C" void func_00323318(Mat_001CD048* d, Mat_001CD048* a, Mat_001CD048* b);
extern "C" void func_00102FD8(Quat_001CD048* q, Mat_001CD048* from, Mat_001CD048* to);
extern "C" void func_00103930(Quat_001CD048* q, Mat_001CD048* m, float t);
extern "C" float func_0018B1D0(float rate, float dt);
extern "C" Vec_001CD048 func_001CE018(Cam_001CD048* cam, int snap);
extern "C" void func_001CE100(Cam_001CD048* cam, float* a, float* b);
extern "C" void func_0018B200(Vec_001CD048* pos, Mat_001CD048* m, const Vec_001CD048& at, Vec_001CD048* look, int a, int b);

static inline Mat_001CD048 Mul_001CD048(Mat_001CD048& a, const Mat_001CD048& b)
{
    Mat_001CD048 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

static inline unsigned int Elapsed_001CD048(unsigned int start) { return func_0010FC30() - start; }

static inline float Param_001CD048(unsigned int key)
{
    float v;
    func_001E7EB0(func_001E5548(0x1CDA02AE, 0), key, &v, 1);
    return v;
}

static inline void RotateY_001CD048(Vec_001CD048& v, float ang)
{
    float s = func_00341068(ang);
    float c = func_00340F60(ang);
    float x = c * v[0] + s * v[2];
    v[2] = -s * v[0] + c * v[2];
    v[0] = x;
}

static inline Vec_001CD048 Shake_001CD048(Skater_001CD048* sk)
{
    switch (sk->State()) {
    case 1:
        if (sk->m24 - 2 < 2 && Elapsed_001CD048(sk->m20) < 150) {
            return sk->m60 * -18.0f;
        }
        return Vec_001CD048(0.0f, 0.0f, 0.0f, 1.0f);
    case 2:
    case 3:
    case 4:
        return sk->m60 * -18.0f;
    default:
        return Vec_001CD048(0.0f, 0.0f, 0.0f, 1.0f);
    }
}

struct Cam_001CD048 {
    char pad0[0xC];
    CamObj_001CD048* mC;
    char pad10[0x1C - 0x10];
    int m_snapFrames;
    int m20;
    int m24;
    char pad28[0x40 - 0x28];
    Mat_001CD048 m_mat;
    float m80;
    int m84;
    char pad88[0x90 - 0x88];
    Vec_001CD048 m90;
    float mA0;
    Mode_001CD048* mA4;
    int mA8;
    Tune_001CD048* mAC;
    Target_001CD048* mB0;
    Skater_001CD048* mB4;
    Locker_001CD048* mB8;
    void Update();
};

void Cam_001CD048::Update()
{
    if (!mB0) {
        return;
    }
    if (mB8 && mB8->m34->m180) {
        mC->m_flags |= 1;
        return;
    }
    if (mB0->m104 & 8) {
        m_snapFrames = 3;
    }
    int snap;
    if (m_snapFrames > 0) {
        snap = 1;
        m_snapFrames--;
    } else {
        snap = m24 != 0;
    }
    int follow = 1;
    func_001B80F8(mA8);
    float dt = func_0010FAB8();
    float spin = func_00185578(mC, 0x27D7CD28)->m278;
    mC->m_mat = m_mat;

    Vec_001CD048 fwd(-mC->m_mat.r2[0], 0.0f, -mC->m_mat.r2[2], -mC->m_mat.r2[3]);
    func_003233B8(&fwd, &fwd);
    Vec_001CD048 heading = mB0->m90;
    heading[1] = 0.0f;
    func_003233B8(&heading, &heading);

    if (!m20) {
        if (spin != 0.0f || fwd.Dot3(heading) < func_00340F60(Param_001CD048(0xB8DA8A73) * D_00387B48)) {
            follow = 0;
        } else {
            Board_001CD048* b = &mB4->mA28->m24;
            int fast = 0;
            if (b->m24C == 0.0f && b->m250 == 0.0f && mB4->mB4) {
                fast = 1;
            }
            float hi, lo;
            if (!fast) {
                hi = Param_001CD048(0xBCEF6DDA);
                lo = Param_001CD048(0x824349E5);
            } else {
                hi = Param_001CD048(0x73DA1EC0);
                lo = Param_001CD048(0x0DA5CAD3);
            }
            Vec_001CD048& v = mB0->m_vel;
            float speed = sqrtf(v[0] * v[0] + v[2] * v[2]);
            if (speed < hi) {
                follow = 0;
                if (lo < speed) {
                    float t = (speed - lo) / (hi - lo);
                    fwd = fwd + (heading - fwd) * t;
                    func_003233B8(&fwd, &fwd);
                }
            }
        }
    }
    if (follow || m24) {
        fwd = heading;
    }
    if (spin != 0.0f && !m20) {
        RotateY_001CD048(fwd, Param_001CD048(0xF6F69DC8) * spin);
    }
    if (m84) {
        fwd = m90;
        RotateY_001CD048(fwd, mA4->m2C);
    }

    Mat_001CD048 m;
    m[2] = fwd;
    m[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
    m[0].Set(fwd[2], 0.0f, -fwd[0], 1.0f);
    m[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    {
        Mat_001CD048 rot;
        m = Mul_001CD048(m, rot.RotX(mAC->m124 + mA4->m28));
    }
    m.r0 = -m.r0;
    m.r2 = -m.r2;

    Vec_001CD048 up = mB0->m80;
    if (!snap) {
        Mat_001CD048& cur = mC->m_mat;
        if (m.r0.Dot3(cur.r0) > D_00387B4C && m.r1.Dot3(cur.r1) > D_00387B4C &&
            m.r2.Dot3(cur.r2) > D_00387B4C) {
            if (m20) {
                m20 = 0;
                mB4->m95C = 0;
            }
        } else {
            Quat_001CD048 q;
            func_00102FD8(&q, &mC->m_mat, &m);
            float rate = Param_001CD048(0x0C39B639);
            if (mB4->mA60) {
                rate *= Param_001CD048(0xD25348EB);
            }
            if (mB4->State() == 4 || mB4->State() == 3) {
                rate += rate;
            }
            if (spin != 0.0f && !m20) {
                rate *= Param_001CD048(0xB2DA3C87) * fabsf(spin);
            }
            if (m20) {
                rate *= Param_001CD048(0x7178E048);
            }
            if (m84) {
                if (m20) {
                    rate = Param_001CD048(0x0C39B639);
                    rate *= Param_001CD048(0x7178E048);
                } else {
                    rate = mA0;
                }
            }
            func_00103930(&q, &mC->m_mat, func_0018B1D0(rate, dt));
            m80 = m_mat.r2.Dot3(mC->m_mat.r2);
        }
    } else {
        mC->m_mat = m;
    }

    m_mat = mC->m_mat;
    Vec_001CD048 pos = func_001CE018(this, snap);
    float upScale, dist;
    func_001CE100(this, &upScale, &dist);
    pos += mC->m_mat.r2 * dist + up * upScale;
    Vec_001CD048 look = mB0->m50 + up * upScale;
    m[2] = look - pos;
    func_003233B8(&m[2], &m[2]);
    m[1] = mC->m_mat[1];
    m[0] = Cross_001CD048(m[1], m[2]);
    func_003233B8(&m[0], &m[0]);
    m[1] = Cross_001CD048(m[2], m[0]);
    func_003233B8(&m[1], &m[1]);
    mC->m_mat[0] = -m[0];
    mC->m_mat[1] = m[1];
    mC->m_mat[2] = -m[2];
    mC->m_mat[0][3] = 0.0f;
    mC->m_mat[1][3] = 0.0f;
    mC->m_mat[2][3] = 0.0f;
    mC->m_mat[3].Set(0.0f, 0.0f, 0.0f, 1.0f);

    func_0018B200(&pos, &mC->m_mat, pos - mC->m_mat.r2 * dist + Shake_001CD048(mB4), &look, 1, 1);
    pos[3] = 1.0f;
    mC->m_pos = pos;
    if (snap) {
        func_001B80F8(mA8);
    }
}
