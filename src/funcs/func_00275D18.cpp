/* func_00275D18: landing velocity damp + feeler; MATCH: k = (aa-lim)/(K2-lim); k = 1.0f - k; (k reuses one pseudo, tying 1-q to q in local-alloc) */
/* sym: __15Feeler_00275D18 = 0x00209240 */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
typedef int qword_00275D18 __attribute__((mode(TI)));
struct Row_00275D18 {
    union {
        qword_00275D18 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    float Length() const { return sqrtf((*this)[0] * (*this)[0] + (*this)[1] * (*this)[1] + (*this)[2] * (*this)[2]); }
    void Normalize();
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Row_00275D18& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
struct Vec_00275D18 : Row_00275D18 {
    Vec_00275D18() {}
    Vec_00275D18(const Row_00275D18& o) { q = o.q; }
    void operator=(const Row_00275D18& o) { q = o.q; }
    Vec_00275D18(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
};
extern "C" void func_003233B8(Row_00275D18* dst, Row_00275D18* src);
inline void Row_00275D18::Normalize() { func_003233B8(this, this); }
inline Vec_00275D18 operator*(const Row_00275D18& a, float k) { return Vec_00275D18(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00275D18 operator+(const Row_00275D18& a, const Row_00275D18& b)
{
    return Vec_00275D18(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00275D18 operator-(const Row_00275D18& a, const Row_00275D18& b)
{
    return Vec_00275D18(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Mat_00275D18;
extern "C" void func_00323318(Mat_00275D18* d, const Mat_00275D18* a, Mat_00275D18* b);
extern "C" Mat_00275D18* func_00100928(Mat_00275D18* out, float a);
struct Mat_00275D18 {
    Row_00275D18 r[4];
    Mat_00275D18() {}
    const Row_00275D18& operator[](int i) const { return r[i]; }
    Mat_00275D18(const Mat_00275D18& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00275D18 operator*(const Mat_00275D18& b) const;
};
inline Mat_00275D18 Mat_00275D18::operator*(const Mat_00275D18& b) const
{
    Mat_00275D18 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

extern "C" void func_00183CB8(void* obj, void* ref);
struct Ref_00275D18 {
    void* m_obj;
    ~Ref_00275D18()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};
struct Feeler_00275D18 {
    Vec_00275D18 m_start;
    Vec_00275D18 m_end;
    char pad20[0xC0 - 0x20];
    Ref_00275D18 mC0;
    int mC4[7];
    Feeler_00275D18();
};
struct Body_00275D18 {
    char pad0[0x50];
    Vec_00275D18 m50;
    char pad60[0x70 - 0x60];
    Mat_00275D18 m70;
    Row_00275D18 mB0;
    char padC0[0x31C - 0xC0];
    int m31C;
};
struct Obj_00275D18 {
    char pad0[0xC];
    Body_00275D18* mC;
    char pad10[0x50 - 0x10];
    Vec_00275D18 m50;
    void Land(const Vec_00275D18* n, const Vec_00275D18* p);
};
extern "C" void func_00209380(Feeler_00275D18* f, Vec_00275D18* s, Vec_00275D18* e);
extern "C" void func_00209350(Feeler_00275D18* f, int a, int b);
extern "C" int func_002093E8(Feeler_00275D18* f, int a, int b);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);
extern "C" float func_00275B58(Obj_00275D18* o, Vec_00275D18 up, float* out);

static inline float DegToRad_00275D18(float d) { return d * 0.01745329425f; }
extern float D_00387F64;
void Obj_00275D18::Land(const Vec_00275D18* n, const Vec_00275D18* p)
{
    Vec_00275D18 a;
    Vec_00275D18 b;
    Row_00275D18 d;
    d.Set(mC->m50[0] - m50[0], mC->m50[1] - m50[1], mC->m50[2] - m50[2], mC->m50[3] - m50[3]);
    Row_00275D18 dc = d;
    Feeler_00275D18 f;
    d.Normalize();
    Body_00275D18* o = mC;
    Vec_00275D18 t = o->m70.r[1] * func_002032A0(0xD4205C9B, 0);
    float out;
    float ang = func_00275B58(this, *n, &out);
    float lim = func_002032A0(0x1483FD01, 0) * 0.01745329425f;
    float aa = fabsf(ang);
    if (lim < aa) {
        float k = (aa - lim) / (1.570796371f - lim);
        k = 1.0f - k;
        mC->mB0 *= k;
    }
    mC->m50 = *p - t;
    mC->m50 += *n * 6.0f;
    float len = dc.Length();
    Row_00275D18 v = mC->mB0;
    d = mC->mB0;
    d.Normalize();
    v = d * len;
    a = mC->m50 + t;
    a += t;
    b = mC->m50 + t + v + d * func_002032A0(0x20102726, 0);
    Vec_00275D18* e = &b;
    if (((a - b).Length() > 240.0f) == 0) {
        func_00209380(&f, &a, e);
        func_00209350(&f, 0x10, 0);
        if (func_002093E8(&f, 1, 0)) {
            Body_00275D18* bo = mC;
            if (bo->m31C) {
    Row_00275D18& vel = bo->mB0;
    float r = 3.141592979f - out;
    float s = func_00341068(r);
    float c = func_00340F60(r);
    float x = vel.c[0];
    float z = vel.c[2];
    vel.c[0] = c * x + s * z;
    vel.c[2] = -s * x + c * z;
    Mat_00275D18& m = mC->m70;
    m = *func_00100928((Mat_00275D18*)0x70003FC0, 3.141592979f - out) * m;
    mC->mB0 *= 0.5f;
            }
        }
    }
}
