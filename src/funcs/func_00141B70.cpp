typedef int qword __attribute__((mode(TI)));

struct Vec_00141B70 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00141B70() {}
    Vec_00141B70(const Vec_00141B70& v) { q = v.q; }
    Vec_00141B70(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Vec_00141B70 operator+(const Vec_00141B70& b) const { return Vec_00141B70((*this)[0] + b[0], (*this)[1] + b[1], (*this)[2] + b[2], (*this)[3] + b[3]); }
    Vec_00141B70 operator-(const Vec_00141B70& b) const { return Vec_00141B70((*this)[0] - b[0], (*this)[1] - b[1], (*this)[2] - b[2], (*this)[3] - b[3]); }
    Vec_00141B70 operator*(float s) const { return Vec_00141B70((*this)[0] * s, (*this)[1] * s, (*this)[2] * s, (*this)[3] * s); }
};

extern "C" Vec_00141B70 func_001415F8(Vec_00141B70 p0, Vec_00141B70 p2, Vec_00141B70 p1, float t1, float t2);
Vec_00141B70 Min_00141810(const Vec_00141B70& a, const Vec_00141B70& b);
Vec_00141B70 Max_00141890(const Vec_00141B70& a, const Vec_00141B70& b);


/* sym: Min_00141810__FRC12Vec_00141B70T0 = 0x00141810 */
/* sym: Max_00141890__FRC12Vec_00141B70T0 = 0x00141890 */

extern "C" float sqrtf(float);

class C_00141B70 {
public:
    int m0;
    int m4;
    int m8;
    float mC[3];
    float m18[3];
    char pad24[0x8];
    float m2C;
    float m30;
    char pad34[0x4C];
    Vec_00141B70 m80[3];
    Vec_00141B70 mB0[3];
    char padE0[0x80];
    Vec_00141B70 m160;
    Vec_00141B70 m170;
    Vec_00141B70 m180;
    void Update();
};

void C_00141B70::Update()
{
    Vec_00141B70 p0, p1, p2;
    Vec_00141B70 e0, e1, e2;
    Vec_00141B70 lo0, lo1, lo2;
    Vec_00141B70 hi0, hi1, hi2;
    Vec_00141B70 mn;
    Vec_00141B70 mx;
    Vec_00141B70 one(1.0f, 1.0f, 1.0f, 1.0f);
    p0 = m80[0];
    p1 = m80[1];
    p2 = m80[2];
    p0.w = mC[0];
    p1.w = mC[1];
    p2.w = mC[2];
    e0 = Vec_00141B70(mB0[0].x * 0.5f, mB0[0].y * 0.5f, mB0[0].z * 0.5f, mB0[0].w * 0.5f);
    e1 = Vec_00141B70(mB0[1].x * 0.5f, mB0[1].y * 0.5f, mB0[1].z * 0.5f, mB0[1].w * 0.5f);
    e2 = Vec_00141B70(mB0[2].x * 0.5f, mB0[2].y * 0.5f, mB0[2].z * 0.5f, mB0[2].w * 0.5f);
    e0.w = m18[0] * 0.5f;
    e1.w = m18[1] * 0.5f;
    e2.w = m18[2] * 0.5f;
    lo0 = p0 - e0 - one * p0.w - one * e0.w;
    lo1 = p1 - e1 - one * p1.w - one * e1.w;
    lo2 = p2 - e2 - one * p2.w - one * e2.w;
    hi0 = p0 + e0 + one * p0.w + one * e0.w;
    hi1 = p1 + e1 + one * p1.w + one * e1.w;
    hi2 = p2 + e2 + one * p2.w + one * e2.w;
    mn = Min_00141810(lo0, lo2);
    mx = Max_00141890(hi0, hi2);
    if (m8) {
        Vec_00141B70 t;
        t = func_001415F8(lo0, lo1, lo2, m2C * m30 * 0.01f, m2C);
        mn = Min_00141810(mn, t);
        t = func_001415F8(hi0, hi1, hi2, m2C * m30 * 0.01f, m2C);
        mx = Max_00141890(mx, t);
    }
    Vec_00141B70 h((mx.x - mn.x) * 0.5f, (mx.y - mn.y) * 0.5f, (mx.z - mn.z) * 0.5f, 0.0f);
    Vec_00141B70 c(mn.x + h.x, mn.y + h.y, mn.z + h.z, mn.w);
    m160 = mn;
    m170 = mx;
    m180 = c;
    m180.w = sqrtf(h.x * h.x + h.y * h.y + h.z * h.z);
}
