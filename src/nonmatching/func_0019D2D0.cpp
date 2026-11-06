/* fuzzy: 59.6 */
typedef int qword __attribute__((mode(TI)));

struct V_0019D2D0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Vec_0019D2D0 : V_0019D2D0 {
    Vec_0019D2D0() {}
    Vec_0019D2D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019D2D0(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    Vec_0019D2D0& operator=(const V_0019D2D0& o) { q = o.q; return *this; }
};

static inline Vec_0019D2D0 operator+(const V_0019D2D0& a, const V_0019D2D0& b)
{
    return Vec_0019D2D0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Mat_0019D2D0 {
    V_0019D2D0 r[4];
    Mat_0019D2D0() {}
    const V_0019D2D0& operator[](int i) const { return r[i]; }
    Mat_0019D2D0(const Mat_0019D2D0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" Mat_0019D2D0* func_001009C0(Mat_0019D2D0* out, float a);
extern "C" void func_00323318(Mat_0019D2D0* d, Mat_0019D2D0* a, Mat_0019D2D0* b);

static inline Mat_0019D2D0 Mul_0019D2D0(const Mat_0019D2D0& a, Mat_0019D2D0& b)
{
    Mat_0019D2D0 r(a);
    func_00323318(&r, &b, &r);
    return r;
}

struct Src_0019D2D0 {
    char pad0[0x50];
    V_0019D2D0 m50;
};

struct Ang_0019D2D0 {
    char pad0[0x2C];
    float m2C;
};

struct Obj_0019D2D0 {
    char pad0[0x1C];
    Src_0019D2D0* m1C;
    char pad20[0x30 - 0x20];
    V_0019D2D0 m30;
    char pad40[0x50 - 0x40];
    V_0019D2D0 m50;
    Mat_0019D2D0 m60;
    float mA0;
    float mA4;
    float mA8;
    char padAC[0xB0 - 0xAC];
    Ang_0019D2D0* mB0;
    void Func_0019D2D0();
};

void Obj_0019D2D0::Func_0019D2D0()
{
    Vec_0019D2D0 v;
    v = m30;
    float a = mB0->m2C;
    float s = func_00341068(a);
    float c = func_00340F60(a);
    float nx = c * v.x + s * v.z;
    float nz = -s * v.x + c * v.z;
    Mat_0019D2D0* m = &m60;
    m->r[0].Set(nz, 0.0f, -nx, 1.0f);
    m->r[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
    v.x = nx;
    v.z = nz;
    m60.r[2] = v;
    m->r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    m50 = m1C->m50 + Vec_0019D2D0(mA4 * v.x, mA0, mA4 * v.z);
    Mat_0019D2D0 rot;
    *m = Mul_0019D2D0(*func_001009C0(&rot, mA8 * 0.0174532942f), *m);
}
