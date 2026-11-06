/* sym: __13Quat_00288868RC12Vec_00288868f = 0x001BA4F0 */
/* func_00288868 (0x10BC): landing/wall-probe update. Quat ctor (0x001BA4F0) and by-value rotate (0x001BA5D0) live in the inline Turn() so the stack addresses are not CSE-shared; &m190 reached through GetWall()/per-branch named pointers gives the game gcse copies; goto into "tilted" for the c.lt/bc1t skip form. */
typedef int qword __attribute__((mode(TI)));
union Vec_00288868 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00288868() {}
    Vec_00288868(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_00288868(float x, float y, float z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        c[3] = 1.0f;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_00288868& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void Mul(const Vec_00288868& a, float k)
    {
        c[0] = a[0] * k;
        c[1] = a[1] * k;
        c[2] = a[2] * k;
        c[3] = a[3] * k;
    }
    void Add(const Vec_00288868& a, const Vec_00288868& b)
    {
        c[0] = a[0] + b[0];
        c[1] = a[1] + b[1];
        c[2] = a[2] + b[2];
        c[3] = a[3] + b[3];
    }
    void Sub(const Vec_00288868& a, const Vec_00288868& b)
    {
        c[0] = a[0] - b[0];
        c[1] = a[1] - b[1];
        c[2] = a[2] - b[2];
        c[3] = a[3] - b[3];
    }
    void Cross(const Vec_00288868& a, const Vec_00288868& b)
    {
        float x = a[1] * b[2] - a[2] * b[1];
        float y = a[2] * b[0] - a[0] * b[2];
        float z = a[0] * b[1] - a[1] * b[0];
        Set(x, y, z, 0.0f);
    }
    void Diff(const Vec_00288868& a, const Vec_00288868& b)
    {
        float x = a[0] - b[0];
        float y = a[1] - b[1];
        float z = a[2] - b[2];
        float w = a[3] - b[3];
        Set(x, y, z, w);
    }
    void Normalize();
};
extern "C" void func_003233B8(Vec_00288868*, Vec_00288868*);
inline void Vec_00288868::Normalize() { func_003233B8(this, this); }
inline Vec_00288868 operator*(const Vec_00288868& a, float k) { return Vec_00288868(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00288868 operator+(const Vec_00288868& a, const Vec_00288868& b)
{
    return Vec_00288868(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00288868 operator-(const Vec_00288868& a, const Vec_00288868& b)
{
    return Vec_00288868(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_00288868(const Vec_00288868& a, const Vec_00288868& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_00288868 Cross_00288868(const Vec_00288868& a, const Vec_00288868& b)
{
    return Vec_00288868(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_00288868 {
    Vec_00288868 r[4];
    const Vec_00288868& operator[](int i) const { return r[i]; }
    Mat_00288868& operator=(const Mat_00288868& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void Copy(const Mat_00288868& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00323318(Mat_00288868* a, Mat_00288868* b, Mat_00288868* out);

struct Res_00288868 {
    void* h;
    char pad4[0x60 - 4];
    Vec_00288868 m60;
    Mat_00288868 m70;
    int mB0;
};
struct Res_00288868;
extern "C" int func_0020A760(Res_00288868* r, Vec_00288868* pos);
static inline void Free_00288868(Res_00288868* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}
struct Holder_00288868 {
    char pad[0x1C];
    Res_00288868* m1C;
    unsigned int m20;
    bool Valid()
    {
        if (!m1C) return false;
        if (m1C->h) return true;
        func_0010A8D8(D_00388A70, m1C);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
    void Release()
    {
        Res_00288868* r = m1C;
        if (r) {
            Free_00288868(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_00288868* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Body_00288868 {
    char pad[0x50];
    Vec_00288868 m50;
    Vec_00288868 m60;
    Mat_00288868 m70;
    Vec_00288868 mB0;
};
struct Phys_00288868 {
    char pad0[0xC];
    Body_00288868* mC;
    char pad10[0x20 - 0x10];
    Mat_00288868 m20;
};
struct Wall_00288868 {
    char pad0[0x6C];
    int m6C;
    int m70;
    int m74;
    char pad78[0xA0 - 0x78];
    Vec_00288868 hit;
    Vec_00288868 normal;
    char padC0[0xE0 - 0xC0];
};
struct State_00288868 {
    int pad;
    int state;
    unsigned int time;
};
struct Sub_00288868 {
    char pad0[0x1C];
    int m1C;
    char pad20[0xA8 - 0x20];
    State_00288868 mA8;
    State_00288868 mB4;
    char padC0[0xF0 - 0xC0];
    State_00288868 mF0;
    State_00288868 mFC;
};
struct Sk_00288868 {
    char pad0[0x2C];
    int m2C;
};
struct Snd_00288868 {
    char pad0[0x24];
    int m24;
};
struct Pad_00288868 {
    char pad0[0x1400];
    int m1400;
};

struct Quat_00288868 {
    float c[4];
    Quat_00288868(const Vec_00288868& axis, float angle);
};
extern "C" Vec_00288868 func_001BA5D0(const Quat_00288868* q, const Vec_00288868* v);
struct Obj_00288868;
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00340F60(float);
extern "C" float fabsf(float);
extern "C" int func_0028E1C0(Obj_00288868* o, unsigned short a, unsigned short b);
extern "C" void func_001016A8(Vec_00288868* v, Vec_00288868* n);
extern "C" int func_00101730(Vec_00288868* v, Vec_00288868* n);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_00289B00(Obj_00288868* o, int a);
extern "C" void func_0027C720(Obj_00288868* o, int v);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void func_00184920(void* obj, unsigned int name, float f, int a);
extern "C" void func_0027FDB0(Obj_00288868* o, Vec_00288868* v);
extern "C" bool func_00288650(Obj_00288868* o);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" void func_001B0EB8(void* p, int a);
extern "C" void func_001B0EF0(void* p, int v);
extern "C" void func_0019C9D8(Wall_00288868* w, Wall_00288868* c);
extern "C" void func_0028E170(Obj_00288868* o);
extern "C" int func_00285258(Obj_00288868* o);
extern "C" void func_00100DC0(Mat_00288868* m, int axis);

static inline void Set_00288868(State_00288868* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Obj_00288868 {
    char pad0[0xC];
    Body_00288868* mC;
    char pad10[0x20 - 0x10];
    Mat_00288868 m20;
    Vec_00288868 m60;
    Vec_00288868 m70;
    Vec_00288868 m80;
    int m90;
    float m94;
    char pad98[0xB0 - 0x98];
    Wall_00288868 mB0;
    Wall_00288868 m190;
    char pad270[0x270 - 0x270];
    Vec_00288868 m270;
    Vec_00288868 m280;
    char pad290[0x298 - 0x290];
    int m298;
    int m29C;
    char pad2A0[0x2B4 - 0x2A0];
    int m2B4;
    char pad2B8[0x410 - 0x2B8];
    Vec_00288868 m410;
    unsigned int m420;
    char pad424[0x598 - 0x424];
    void* m598;
    Snd_00288868* m59C;
    Pad_00288868* m5A0;
    char pad5A4[0x5B0 - 0x5A4];
    Sub_00288868* m5B0;
    Holder_00288868* m5B4;
    Sk_00288868* m5B8;
    void Land();
    void SetUp()
    {
        Vec_00288868 up;
        up.Set(0.0f, 1.0f, 0.0f, 1.0f);
        func_0027FDB0(this, &up);
    }
    void StartFall()
    {
        func_0027C720(this, 1);
        func_00184920(mC, 0xD96F01F1, 0.0f, 0);
        func_001848F0(mC, 0x3B1001B6, 0);
    }
    Wall_00288868* GetWall() { return &m190; }
    void Turn(float ang)
    {
        mC->mB0[3] = 1.0f;
        Body_00288868* bd = mC;
        Quat_00288868 q(m410, ang);
        bd->mB0 = func_001BA5D0(&q, &bd->mB0);
    }
};


void Obj_00288868::Land()
{
    Set_00288868(&m5B0->mA8, 0);
    Set_00288868(&m5B0->mF0, 0);
    Set_00288868(&m5B0->mB4, 0);
    Set_00288868(&m5B0->mFC, 0);
    m29C = 0;
    m2B4 = 0;
    m420 = func_0010FC30();
    Holder_00288868* hold = m5B4;
    Vec_00288868 v(0.0f, 0.0f, 0.0f, 1.0f);
    bool ok = hold->Update(&mC->m50);
    Mat_00288868* pm = &m20;
    if (ok) {
        v = m5B4->m1C->m60;
        if (m5B4->m1C->mB0) {
            func_00323318(&mC->m70, &m5B4->m1C->m70, &mC->m70);
            func_00323318(pm, &m5B4->m1C->m70, pm);
        }
    }
    Vec_00288868 g(0.0f, func_002032A0(0x0C617CAF, 0), 0.0f);
    float dtm = m94;
    mC->m50 += mC->mB0 * dtm + g * (0.5f * dtm * dtm);
    mC->m50 += v;
    mC->mB0 += g * m94;
    Vec_00288868 n(m410[2], 0.0f, -m410[0], 0.0f);
    n.Normalize();
    Vec_00288868 ax;
    ax.Cross(n, m410);
    Vec_00288868 t;
    float ang = func_002032A0(0x64A48A64, 0);
    float dt = Dot_00288868(mC->m70.r[2], ax);
    if (0.6800000072f < dt)
        goto tilted;
    if (0.0f < dt && func_00340F60(ang) < dt)
        goto tilted;
    if (Dot_00288868(mC->m70.r[0], ax) <= 0.0f)
        ang = -ang;
    Turn(ang);
    mC->m70.r[2] = mC->mB0;
    mC->m70.r[2].Normalize();
    mC->m70.r[1] = m410;
    t.Cross(mC->m70.r[1], mC->m70.r[2]);
    mC->m70.r[0] = t;
    mC->m70.r[0].Normalize();
    m20.Copy(mC->m70);
tilted:
    t.Diff(mC->m50, mC->m60);
    t.Normalize();
    m270 = mC->m60;
    m280 = mC->m50;
    m280 += t * func_002032A0(0x20102726, 0);
    if (func_0028E1C0(this, 0x10, 0)) {
        Vec_00288868 n = mB0.normal;
        float k = Dot_00288868(n, m410);
        {
            Vec_00288868 p;
            p.Add(mB0.hit, n);
            mC->m50 = p;
        }
        if (!m298 || fabsf(k) < 0.009999999776f) {
            if (0.8999999762f < n[1]) {
                mC->m50 = mB0.hit;
                mC->m70.r[2] = mC->mB0;
                func_001016A8(&mC->m70.r[2], &n);
                mC->m70.r[2].Normalize();
                mC->m70.r[1] = n;
                mC->m70.r[0] = Cross_00288868(mC->m70.r[1], mC->m70.r[2]);
                mC->m70.r[0].Normalize();
                m20.Copy(mC->m70);
                Phys_00288868* ph = (Phys_00288868*)func_00185578(mC, 0xBF518E27);
                ph->m20.Copy(ph->mC->m70);
                m80 = mC->m70.r[1];
                m60 = mC->m70.r[1];
                m70 = mC->m70.r[1];
                func_00289B00(this, 1);
                if (m5B0->m1C != 4) {
                    func_0027C720(this, 0);
                    func_001848F0(mC, 0x532B16EF, 0);
                }
                return;
            }
            SetUp();
            mC->m50 += m410 * 18.0f;
            StartFall();
        } else {
            m410 = n;
            Vec_00288868 w = n;
            func_0027FDB0(this, &w);
            m20.Copy(mC->m70);
            func_00101730(&mC->mB0, &m410);
        }
    }
    if (func_00288650(this)) {
        SetUp();
        mC->m50 += m410 * 18.0f;
        StartFall();
    }
    Body_00288868* b0 = mC;
    m270 = b0->m70.r[1] * func_002032A0(0xE4D79235, 0);
    m270 += mC->m50;
    Body_00288868* b1 = mC;
    m280 = b1->m70.r[1] * func_002032A0(0x438BA168, 0);
    m280 += mC->m50;
    if (func_0028E1C0(this, 0x10, 0)) {
        Wall_00288868* hw = &mB0;
        m410 = mB0.normal;
        mC->m50 = mB0.hit;
        mC->m50 += m410;
        func_00101730(&mC->mB0, &m410);
        {
            Vec_00288868 w = m410;
            func_0027FDB0(this, &w);
        }
        m20.Copy(mC->m70);
        if (!m298) {
            Wall_00288868* cw = GetWall();
            mC->mB0 += m410 * 100.0f;
            SetUp();
            m20.Copy(mC->m70);
            StartFall();
            func_001BB080(m598, 1, cw);
            if (m5B8->m2C) return;
        } else {
            if (hw->m70 != GetWall()->m70) {
                func_001BB080(m598, 1, GetWall());
                if (m5B8->m2C) return;
                func_001BB080(m598, 5, GetWall());
                if (m5B8->m2C) return;
            }
            if (!m5A0->m1400)
                func_001B0EB8(m5A0, 0);
            func_0019C9D8(GetWall(), hw);
            int id = GetWall()->m6C;
            m59C->m24 = id;
        }
    } else {
        Wall_00288868* cw = GetWall();
        SetUp();
        m20.Copy(mC->m70);
        mC->m50 += m410 * 18.0f;
        StartFall();
        func_001BB080(m598, 1, cw);
        if (m5B8->m2C) return;
    }
    func_0028E170(this);
    if (func_00285258(this)) {
        func_001BB080(m598, 2, GetWall());
        if (m5B8->m2C) return;
        Vec_00288868* jp = &mC->mB0;
        *jp += m410 * func_002032A0(0x349D02D4, 0);
        mC->mB0[1] += func_002032A0(0x5A9DE35A, 0);
        mC->m70.r[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
        func_00100DC0(&mC->m70, 1);
        m20.Copy(mC->m70);
        m90 = 0;
        m80 = m70 = m60 = mC->m70.r[1];
    }
    func_001B0EF0(m5A0, GetWall()->m74);
}
