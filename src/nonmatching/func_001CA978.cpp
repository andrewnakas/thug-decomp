/* fuzzy: 92.0 */
typedef int qword_001CA978 __attribute__((mode(TI)));

struct Vec_001CA978 {
    union {
        qword_001CA978 q;
        float c[4];
    };
    Vec_001CA978() {}
    Vec_001CA978(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001CA978& operator+=(const Vec_001CA978& a)
    {
        c[0] += a[0];
        c[1] += a[1];
        c[2] += a[2];
        c[3] += a[3];
        return *this;
    }
};

static inline Vec_001CA978 operator-(const Vec_001CA978& a, const Vec_001CA978& b)
{
    return Vec_001CA978(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline Vec_001CA978 operator+(const Vec_001CA978& a, const Vec_001CA978& b)
{
    return Vec_001CA978(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_001CA978 operator*(const Vec_001CA978& a, float s)
{
    return Vec_001CA978(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void func_003233B8(Vec_001CA978* out, Vec_001CA978* in);
extern "C" void func_0026B1B0(Vec_001CA978* out, void* rail, int idx);

struct Ref_001CA978 {
    int m0;
    char pad4[0xB0 - 0x4];
    int mB0;
};

struct Lock_001CA978 {
    char pad0[0x1C];
    Ref_001CA978* m1C;
    unsigned int m20;
    bool Valid()
    {
        Ref_001CA978* r = m1C;
        if (!r) {
            return false;
        }
        if (r->m0) {
            return true;
        }
        func_0010A8D8(D_00388A70, r);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
};

struct Obj_001CA978 {
    char pad0[0x30];
    Vec_001CA978 m30;
    char pad40[0x60 - 0x40];
    Vec_001CA978 m60;
    char pad70[0xA1C - 0x70];
    int mA1C;
    int mA20;
    void* mA24;
    char padA28[0xA3C - 0xA28];
    Lock_001CA978* mA3C;
    char padA40[0xBF0 - 0xA40];
    float mBF0;
    float mBF4;
    float mBF8;
    Vec_001CA978 RailPoint()
    {
        Vec_001CA978 a;
        Vec_001CA978 b;
        func_0026B1B0(&a, mA24, mA1C);
        func_0026B1B0(&b, mA24, mA20);
        return a + (b - a) * mBF0;
    }
    void UpdateRailPos();
};

void Obj_001CA978::UpdateRailPos()
{
    m30 = RailPoint();
    m30[1] += mBF4;
    m30 += m60 * mBF8;
    if (!mA3C->Valid()) {
        return;
    }
    if (!mA3C->m1C->mB0) {
        return;
    }
    Vec_001CA978 n;
    {
        Vec_001CA978 a;
        Vec_001CA978 b;
        func_0026B1B0(&a, mA24, mA1C);
        func_0026B1B0(&b, mA24, mA20);
        n[0] = a[0] - b[0];
        n[1] = 0.0f;
        n[2] = a[2] - b[2];
        n[3] = a[3] - b[3];
    }
    func_003233B8(&n, &n);
    float x = n[0];
    n[0] = -n[2];
    n[1] = 0.0f;
    n[2] = x;
    n[3] = 1.0f;
    if (n[0] * m60[0] + n[2] * m60[2] > n[1]) {
        m60 = n;
    } else {
        Vec_001CA978 q;
        q[0] = -n[0];
        q[1] = -n[1];
        q[2] = -n[2];
        q[3] = -n[3];
        m60 = q;
    }
}
