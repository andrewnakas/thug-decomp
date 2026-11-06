/* fuzzy: 98.5 */
typedef int qword __attribute__((mode(TI)));
union Vec_001DDB00 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    Vec_001DDB00& operator=(const Vec_001DDB00& o)
    {
        q = o.q;
        return *this;
    }
    float operator[](int i) const { return c[i]; }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void operator-=(const Vec_001DDB00& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Mat_001DDB00 {
    Vec_001DDB00 r[4];
    Mat_001DDB00& operator=(const Mat_001DDB00& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_001DDB00& operator[](int i) { return r[i]; }
    const Vec_001DDB00& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_001DDB00& m);
    void Invert();
    void Scale(float s)
    {
        if (s != 1.0f) {
            r[0] *= s;
            r[1] *= s;
            r[2] *= s;
            r[3] *= s;
        }
    }
    void Invert(const Mat_001DDB00& in);
};

static inline float Det3_001DDB00(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_001DDB00::Det() const
{
    const Mat_001DDB00& m = *this;
    return m[0][0] * Det3_001DDB00(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_001DDB00::Adjoint(const Mat_001DDB00& m)
{
    r[0].c[0] = Det3_001DDB00(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_001DDB00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_001DDB00(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_001DDB00(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_001DDB00(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_001DDB00(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_001DDB00(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_001DDB00(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_001DDB00(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_001DDB00(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_001DDB00(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_001DDB00(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_001DDB00(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_001DDB00(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_001DDB00::Invert(const Mat_001DDB00& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) Scale(1.0f / d);
}
inline void Mat_001DDB00::Invert()
{
    Mat_001DDB00 t;
    t.Invert(*this);
    *this = t;
}

extern "C" void func_00323298(Vec_001DDB00* out, const Mat_001DDB00* m, const Vec_001DDB00* v);
static inline Vec_001DDB00 operator*(const Mat_001DDB00& m, const Vec_001DDB00& v)
{
    Vec_001DDB00 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline void Diff_001DDB00(Vec_001DDB00& r, const Vec_001DDB00& a, const Vec_001DDB00& b)
{
    float x = a[0] - b[0];
    float y = a[1] - b[1];
    float z = a[2] - b[2];
    float w = a[3] - b[3];
    r.c[0] = x;
    r.c[1] = y;
    r.c[2] = z;
    r.c[3] = w;
}
static inline void Neg_001DDB00(Vec_001DDB00& r, const Vec_001DDB00& a)
{
    float x = -a[0];
    float y = -a[1];
    float z = -a[2];
    float w = -a[3];
    r.c[0] = x;
    r.c[1] = y;
    r.c[2] = z;
    r.c[3] = w;
}
static inline float Dot_001DDB00(const Vec_001DDB00& a, const Vec_001DDB00& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern float D_0038E0A8;
extern "C" void func_003233B8(Vec_001DDB00* out, Vec_001DDB00* in);
struct Snd_001DDB00 {
    float m0[5];
    int m14;
};
struct Mgr_001DDB00;
extern "C" int func_001DC418();
extern "C" void func_001DC6D0(Snd_001DDB00* s);
extern "C" int func_001DCAF8(Mgr_001DDB00* m);
extern "C" void* func_0013B108(Vec_001DDB00* pos, int a);
extern "C" Vec_001DDB00* func_00114E18(void* o);
extern "C" Mat_001DDB00* func_00114E48(void* o);
extern "C" float func_001DC5F0(Snd_001DDB00* s);
extern "C" int func_001DC658(Snd_001DDB00* s);
extern "C" void func_001DD960(Mgr_001DDB00* m, Vec_001DDB00* dir, float* w);

static inline void Normalize_001DDB00(Vec_001DDB00& v) { func_003233B8(&v, &v); }

extern "C" void func_001DDB00(Mgr_001DDB00* self, Snd_001DDB00* s, Vec_001DDB00* pos, int type, void* obj,
                              Vec_001DDB00* pos2, float radius)
{
    if (func_001DC418()) return;
    func_001DC6D0(s);
    if (func_001DCAF8(self)) return;
    if (!obj) {
        obj = func_0013B108(pos, 0);
        if (!obj) return;
    }
    Vec_001DDB00 d;
    Diff_001DDB00(d, *func_00114E18(obj), *pos);
    float dist = sqrtf(Dot_001DDB00(d, d));
    if (pos2) {
        Diff_001DDB00(d, *pos2, *func_00114E18(obj));
        radius = dist + sqrtf(Dot_001DDB00(d, d));
    } else if (radius == 0.0f)
        radius = D_0038E0A8;
    if (radius <= dist) return;
    float f = dist / radius;
    float g = 0.0f;
    switch (type) {
    case 0:
        g = ((1.0f - f * f) + (1.0f - f) * 3.0f) * 25.0f;
        break;
    case 1:
        g = (1.0f - f) * 100.0f;
        break;
    case 2:
        g = (1.0f - f) * (1.0f - f) * 100.0f;
        break;
    case 3:
        g = sqrtf(1.0f - f) * 100.0f;
        break;
    }
    switch (s->m14) {
    case 0:
    case 1: {
        float a = fabsf(g);
        if (fabsf(func_001DC5F0(s)) < a) {
            Diff_001DDB00(d, *pos, *func_00114E18(obj));
            func_003233B8(&d, &d);
            Vec_001DDB00 side;
            Neg_001DDB00(side, func_00114E48(obj)->r[0]);
            float t = (Dot_001DDB00(d, side) + 1.0f) * 0.5f;
            float l = (1.0f - t * t) * g;
            float r = (1.0f - (1.0f - t) * (1.0f - t)) * g;
            if (s->m14 == 1) {
                int ch = 0;
                if (s->m0[0] < r) {
                    s->m0[0] = r;
                    ch = 1;
                }
                if (s->m0[1] < l) {
                    s->m0[1] = l;
                    ch = 1;
                }
                if (!ch) return;
                Vec_001DDB00 fwd;
                Neg_001DDB00(fwd, func_00114E48(obj)->r[2]);
                if (Dot_001DDB00(d, fwd) < 0.0f) s->m0[0] = -s->m0[0];
            } else {
                if (s->m0[0] < r) s->m0[0] = r;
                if (s->m0[1] < l) s->m0[1] = l;
            }
        }
        break;
    }
    case 2: {
        float a = fabsf(g);
        if (func_001DC5F0(s) < a) {
            Mat_001DDB00 m = *func_00114E48(obj);
            m.Invert();
            Diff_001DDB00(d, *pos, *func_00114E18(obj));
            Vec_001DDB00 lp = m * d;
            Normalize_001DDB00(lp);
            {
                float w[5];
                func_001DD960(self, &lp, w);
                for (int i = 0; i < 5; i++) {
                    if (w[i] > 0.0f) {
                        float v = g * w[i];
                        if (s->m0[i] < v) s->m0[i] = v;
                    }
                }
            }
            if (!func_001DC658(s)) {
                float sum = 0.0f;
                for (int i = 0; i < 5; i++) sum += s->m0[i] * s->m0[i];
                float len = sqrtf(sum);
                for (int i = 0; i < 5; i++) s->m0[i] = g * s->m0[i] / len;
            }
        }
        break;
    }
    }
}
