typedef int qword __attribute__((mode(TI)));

struct Row_0027E0C8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator+=(const Row_0027E0C8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
struct Vec_0027E0C8 : Row_0027E0C8 {
    Vec_0027E0C8() {}
    Vec_0027E0C8(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_0027E0C8 operator+(const Row_0027E0C8& a, const Row_0027E0C8& b) { return Vec_0027E0C8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]); }
static inline Vec_0027E0C8 operator-(const Row_0027E0C8& a, const Row_0027E0C8& b) { return Vec_0027E0C8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_0027E0C8 operator*(const Row_0027E0C8& a, float k) { return Vec_0027E0C8(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }

struct Mat_0027E0C8;
extern "C" void func_00323318(Mat_0027E0C8* d, const Mat_0027E0C8* a, Mat_0027E0C8* b);
extern "C" Mat_0027E0C8* func_00100928(Mat_0027E0C8* out, float a);

struct Mat_0027E0C8 {
    Row_0027E0C8 r[4];
    Mat_0027E0C8() {}
    const Row_0027E0C8& operator[](int i) const { return r[i]; }
    Mat_0027E0C8(const Mat_0027E0C8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0027E0C8& operator=(const Mat_0027E0C8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_0027E0C8 operator*(const Mat_0027E0C8& b) const;
};

inline Mat_0027E0C8 Mat_0027E0C8::operator*(const Mat_0027E0C8& b) const
{
    Mat_0027E0C8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Body_0027E0C8 {
    char pad[0x50];
    Row_0027E0C8 m50;
    char pad60[0x10];
    Mat_0027E0C8 m70;
    Row_0027E0C8 mB0;
};

struct Obj_0027E0C8;
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" void func_0027E678(Obj_0027E0C8* self, Vec_0027E0C8* pos, Vec_0027E0C8* q, int i);
extern "C" int func_00101730(Row_0027E0C8* v, Row_0027E0C8* n);
extern "C" float func_00101D60(Row_0027E0C8* a, Row_0027E0C8* b, Row_0027E0C8* c);
extern "C" float sqrtf(float);
static inline float fabsf(float x) { return __builtin_fabsf(x); }

struct Obj_0027E0C8 {
    char pad0[0xC];
    Body_0027E0C8* mC;
    char pad10[0x10];
    Mat_0027E0C8 m20;
    char pad60[0x10];
    Row_0027E0C8 m70;
    char pad80[0x94 - 0x80];
    float m94;
    char pad98[0x160 - 0x98];
    Row_0027E0C8 m160;
    char pad170[0x340 - 0x170];
    Row_0027E0C8 m340;
    float m350;
    float m354;
    float m358;
    float m35C;
    void Update();
    static void Rot(Mat_0027E0C8& m, float a) { m = *func_00100928((Mat_0027E0C8*)0x70003FC0, a) * m; }
};

void Obj_0027E0C8::Update()
{
    if (m354 == 0.0f) return;
    if (m358 == 0.0f) return;
    Row_0027E0C8& v = m340;
    v.c[0] = 0.0f;
    v.c[1] = 0.0f;
    v.c[2] = 0.0f;
    v.c[3] = 1.0f;
    m350 = 1.0f;
    Body_0027E0C8* b = mC;
    Vec_0027E0C8 pos;
    Vec_0027E0C8 q;
    pos = b->m50 + b->m70.r[1] * func_002032A0(0xB45B39E2, 0);
    q = pos + mC->m70.r[0] * m354;
    func_0027E678(this, &pos, &q, 0);
    q = pos - mC->m70.r[0] * m354;
    func_0027E678(this, &pos, &q, 1);
    q = pos + mC->m70.r[2] * m354;
    func_0027E678(this, &pos, &q, 2);
    q = pos - mC->m70.r[2] * m354;
    func_0027E678(this, &pos, &q, 3);
    if (m350 == 1.0f) return;
    float k = m358 * (1.0f - m350);
    float len = sqrtf(v.c[0] * v.c[0] + v.c[1] * v.c[1] + v.c[2] * v.c[2]);
    if (len > 0.0f) {
        float s = k / len;
        v.c[0] *= s;
        v.c[1] *= s;
        v.c[2] *= s;
    }
    Row_0027E0C8& p = mC->mB0;
    p += m340;
    func_00101730(&mC->mB0, &m70);
    Body_0027E0C8* c = mC;
    if (c->m70.r[2][0] * m160[0] + c->m70.r[2][1] * m160[1] + c->m70.r[2][2] * m160[2] < 0.0f) {
        Row_0027E0C8 t = c->m70.r[2];
        func_00101730(&t, &m160);
        float ang = func_00101D60(&mC->m70.r[2], &t, &mC->m70.r[1]);
        float s = 1.0f;
        if (ang < 0.0f) s = -1.0f;
        float a = m35C * s * m94;
        if (fabsf(ang) < fabsf(a)) a = ang;
        Rot(mC->m70, a);
        Rot(m20, a);
    }
}
