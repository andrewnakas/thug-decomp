/* fuzzy: 82.4 */
typedef int qword_001CA670 __attribute__((mode(TI)));

extern "C" float sqrtf(float);
extern "C" float func_00340F60(float x);

struct Vec_001CA670 {
    union {
        qword_001CA670 q;
        float c[4];
    };
    Vec_001CA670() {}
    Vec_001CA670(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

static inline Vec_001CA670 operator-(const Vec_001CA670& a, const Vec_001CA670& b)
{
    return Vec_001CA670(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline void Sub_001CA670(Vec_001CA670& r, const Vec_001CA670& a, const Vec_001CA670& b)
{
    r[0] = a[0] - b[0];
    r[1] = a[1] - b[1];
    r[2] = a[2] - b[2];
    r[3] = a[3] - b[3];
}
static inline void Neg_001CA670(Vec_001CA670& r, const Vec_001CA670& a)
{
    r[0] = -a[0];
    r[1] = -a[1];
    r[2] = -a[2];
    r[3] = -a[3];
}
static inline Vec_001CA670 operator*(const Vec_001CA670& a, float s)
{
    return Vec_001CA670(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}
static inline void Cross_001CA670(Vec_001CA670& r, const Vec_001CA670& a, const Vec_001CA670& b)
{
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
    r[3] = 0.0f;
}

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001CA670(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" void func_003233B8(Vec_001CA670* out, Vec_001CA670* in);
extern "C" void func_0026B1B0(Vec_001CA670* out, void* rail, int idx);
extern "C" void func_001CDF30(void* ctrl);

struct Obj_001CA670;
extern "C" float func_001CB6F8(Obj_001CA670* o);

struct Obj_001CA670 {
    char pad0[0x60];
    Vec_001CA670 m60;
    char pad70[0x970 - 0x70];
    Vec_001CA670 m970;
    char pad980[0xA18 - 0x980];
    void* mA18;
    int mA1C;
    int mA20;
    void* mA24;
    char padA28[0xBF0 - 0xA28];
    float mBF0;
    void SetOnRail(int neg, Vec_001CA670* d, float dist);
};

void Obj_001CA670::SetOnRail(int neg, Vec_001CA670* d, float dist)
{
    Vec_001CA670 v;
    Vec_001CA670 a;
    {
        Vec_001CA670 b;
        func_0026B1B0(&a, mA24, mA1C);
        func_0026B1B0(&b, mA24, mA20);
        Sub_001CA670(v, a, b);
        float len = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        float m = dist;
        if (len < dist) {
            m = len;
        }
        mBF0 = m / len;
        if (neg) {
            mBF0 = 1.0f - mBF0;
        }
        a.Set(-v[2], 0.0f, v[0], 1.0f);
        func_003233B8(&a, &a);
        Cross_001CA670(b, *d, m60);
        Vec_001CA670 e;
        Vec_001CA670 w;
        if (!neg) {
            w = v;
        } else {
            Neg_001CA670(w, v);
        }
        Cross_001CA670(e, w, a);
        if (b[1] * e[1] < e[3]) {
            a[0] = -a[0];
            a[1] = -a[1];
            a[2] = -a[2];
        }
    }
    if (a[0] * m60[0] + a[1] * m60[1] + a[2] * m60[2] < func_00340F60(1.0471977f)) {
        func_001CDF30(mA18);
    }
    m60 = a;
    m970 = m60 * Param_001CA670(0xC3263E6E);
    m970[1] = func_001CB6F8(this);
}
