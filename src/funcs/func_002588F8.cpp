typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_002588F8;
extern "C" void func_003233B8(Row_002588F8* dst, Row_002588F8* src);
extern "C" float func_003412F0(float x);

struct Row_002588F8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Row_002588F8& operator=(const Row_002588F8& o)
    {
        q = o.q;
        return *this;
    }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
    void operator+=(const Row_002588F8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Row_002588F8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void Normalize() { func_003233B8(this, this); }
    void SetLength(float k)
    {
        float l = Length();
        if (l > 0.0f) {
            float s = k / l;
            c[0] *= s;
            c[1] *= s;
            c[2] *= s;
        }
    }
};
struct Vec_002588F8 : Row_002588F8 {
    Vec_002588F8() {}
    Vec_002588F8(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_002588F8 operator-(const Row_002588F8& a, const Row_002588F8& b) { return Vec_002588F8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_002588F8 operator+(const Row_002588F8& a, const Row_002588F8& b) { return Vec_002588F8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]); }
static inline Vec_002588F8 Cross(const Row_002588F8& a, const Row_002588F8& b)
{
    return Vec_002588F8(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}
static inline float Dot(const Row_002588F8& a, const Row_002588F8& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }


struct Obj_002588F8 {
    char pad0[0x10];
    Row_002588F8 m10;
    char pad20[0x10];
    Row_002588F8 m30;
    Row_002588F8 m40;
    Row_002588F8 m50;
    char pad60[0x20];
    Row_002588F8 m80;
    Row_002588F8 m90;
    char padA0[0x20];
    float mC0;
    int mC4;
    float mC8;
    char padCC[4];
    Row_002588F8 mD0;
    Row_002588F8 mE0;
    float mF0;
    float mF4;
    float mF8;
    int Update();
};

int Obj_002588F8::Update()
{
    Row_002588F8 b;
    Row_002588F8 a;
    a = m10 - m80;
    b = m90 - m80;
    float la = a.Length();
    mE0 = m80;
    b *= la / sqrtf(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
    mE0 += b;
    if (mC4 & 1) return 0;
    if (la == 0.0f) return 2;
    b = mE0 - m10;
    b *= 0.5f;
    float lb = b.Length();
    a = m10 + b;
    a -= m80;
    float lm = a.Length();
    if ((lm == 0.0f) | (lm * 6.0f < lb)) return 0;
    float r = lb * la / lm;
    mF8 = r;
    if (r == 0.0f) return 2;
    mD0 = a;
    float k = la * la;
    k /= lm;
    mD0.SetLength(k);
    mD0 += m80;
    m30 = mD0 - m10;
    m50 = mD0 - mE0;
    if (m30.Length() == 0.0f) return 2;
    if (m50.Length() == 0.0f) return 2;
    m30.Normalize();
    m50.Normalize();
    float ang = func_003412F0(Dot(m30, m50));
    mF0 = ang;
    mF4 = mF8 * ang;
    m40 = Cross(m30, m50);
    if (m40.Length() == 0.0f) return 2;
    m40.Normalize();
    m50 = Cross(m30, m40);
    if (m50.Length() == 0.0f) return 2;
    m50.Normalize();
    mC0 = mC8;
    mC8 = 0.0f;
    return 1;
}
