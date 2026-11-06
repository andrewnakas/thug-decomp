typedef int qword __attribute__((mode(TI)));
union Vec_001C97D8 {
    qword q;
    float c[4];
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

extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C97D8;
extern "C" Coll_001C97D8* func_00209240(Coll_001C97D8* c);
extern "C" int func_002093E8(Coll_001C97D8* c, int a, int b);
struct Coll_001C97D8 {
    Vec_001C97D8 m0;
    Vec_001C97D8 m10;
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void func_0026B1B0(Vec_001C97D8* out, void* rail, int idx);

static inline void Add_001C97D8(Vec_001C97D8& r, const Vec_001C97D8& a, const Vec_001C97D8& b)
{
    r.c[0] = a[0] + b[0];
    r.c[1] = a[1] + b[1];
    r.c[2] = a[2] + b[2];
    r.c[3] = a[3] + b[3];
}
static inline void Sub_001C97D8(Vec_001C97D8& r, const Vec_001C97D8& a, const Vec_001C97D8& b)
{
    r.c[0] = a[0] - b[0];
    r.c[1] = a[1] - b[1];
    r.c[2] = a[2] - b[2];
    r.c[3] = a[3] - b[3];
}

static inline float Clamp_001C97D8(float v)
{
    float a = v;
    if (v > 1.0f) a = 1.0f;
    float b = a;
    if (a < 0.0f) b = 0.0f;
    return b;
}

static inline float Advance_001C97D8(float t, float step, bool fwd)
{
    if (fwd) return t + step;
    return t - step;
}

struct Obj_001C97D8 {
    char pad0[0x30];
    Vec_001C97D8 m30;
    char pad40[0x60 - 0x40];
    Vec_001C97D8 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0x970 - 0x94];
    Vec_001C97D8 m970;
    char pad980[0xA1C - 0x980];
    int mA1C;
    int mA20;
    void* mA24;
    char padA28[0xBF0 - 0xA28];
    float mBF0;
    char padBF4[0xC00 - 0xBF4];
    float mC00;
    void Move(float amount);
};

extern "C" int func_001C9C38(Obj_001C97D8* o, Vec_001C97D8* dir, Vec_001C97D8* pos, int fwd, Vec_001C97D8* n,
                             float t, Vec_001C97D8* d, int a, int b);
extern "C" int func_001CAC08(Obj_001C97D8* o, float* t, int a, int b, int* pa, int* pb);
extern "C" void func_001CA670(Obj_001C97D8* o, int neg, Vec_001C97D8* d, float dist);

void Obj_001C97D8::Move(float amount)
{
    float oldT = mBF0;
    Vec_001C97D8 start;
    Add_001C97D8(start, m30, m970);
    Vec_001C97D8 pos = m30;
    Vec_001C97D8 off = m970;
    Vec_001C97D8 dir = m60;
    int oldA = mA1C;
    int oldB = mA20;
    Vec_001C97D8 n;
    n.Set(-m60[2], 0.0f, m60[0], 1.0f);
    Vec_001C97D8 d;
    Vec_001C97D8 a;
    Vec_001C97D8 b;
    func_0026B1B0(&a, mA24, oldA);
    func_0026B1B0(&b, mA24, mA20);
    Sub_001C97D8(d, a, b);
    bool fwd = 0.0f < amount;
    bool same;
    if (n[0] * d[0] + n[1] * d[1] + n[2] * d[2] < 0.0f)
        same = fwd;
    else
        same = !fwd;
    a = d;
    if (func_001C9C38(this, &m60, &m30, fwd, &n, mBF0, &a, mA1C, mA20)) {
        mC00 = 0.0f;
        m90 = 0x4194ECCA;
        return;
    }
    float step = fabsf(amount) / sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
    float t = Advance_001C97D8(mBF0, step, same);
    mBF0 = t;
    if (t < 0.0f || t > 1.0f) {
        if (!func_001CAC08(this, &mBF0, mA1C, mA20, &mA1C, &mA20)) {
            mC00 = 0.0f;
            float v = mBF0;
            float lo;
            if (v > 1.0f)
                lo = 1.0f;
            else
                lo = v;
            float r;
            if (lo < 0.0f)
                r = 0.0f;
            else
                r = lo;
            mBF0 = r;
            m90 = 0x4194ECCA;
            goto collide;
        }
        float v = mBF0;
        float dist = fabsf(v - Clamp_001C97D8(v)) * sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        bool under = v < 0.0f;
        if (same)
            a = d;
        else {
            a[0] = -d[0];
            a[1] = -d[1];
            a[2] = -d[2];
            a[3] = -d[3];
        }
        func_001CA670(this, under, &a, dist);
    }
    m90 = fwd ? 0x2D9815C3 : 0x279B1F0B;
collide:
    Add_001C97D8(a, m30, m970);
    Coll_001C97D8 c;
    func_00209240(&c);
    c.m0 = start;
    c.m10 = a;
    if (func_002093E8(&c, 1, 0)) {
        m90 = 0x4194ECCA;
        m30 = pos;
        mBF0 = oldT;
        mA1C = oldA;
        mA20 = oldB;
        m970 = off;
        m60 = dir;
        mC00 = 0.0f;
    }
    Coll_001C97D8::Ref* h = &c.mC0;
    h->Release();
}
