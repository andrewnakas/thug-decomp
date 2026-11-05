typedef int qword __attribute__((mode(TI)));
union Vec_001C6C18 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    Vec_001C6C18& operator=(const Vec_001C6C18& o)
    {
        q = o.q;
        return *this;
    }
    float operator[](int i) const { return c[i]; }
    float LengthSqr() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void operator-=(const Vec_001C6C18& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Mat_001C6C18 {
    Vec_001C6C18 r[4];
    Mat_001C6C18& operator=(const Mat_001C6C18& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_001C6C18& operator[](int i) { return r[i]; }
    const Vec_001C6C18& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_001C6C18& m);
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
    void Invert(const Mat_001C6C18& in);
};

static inline float Det3_001C6C18(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_001C6C18::Det() const
{
    const Mat_001C6C18& m = *this;
    return m[0][0] * Det3_001C6C18(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_001C6C18::Adjoint(const Mat_001C6C18& m)
{
    r[0].c[0] = Det3_001C6C18(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_001C6C18(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_001C6C18(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_001C6C18(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_001C6C18(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_001C6C18(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_001C6C18(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_001C6C18(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_001C6C18(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_001C6C18(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_001C6C18(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_001C6C18(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_001C6C18(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_001C6C18(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_001C6C18::Invert(const Mat_001C6C18& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) {
        float s = 1.0f / d;
        if (s != 1.0f) {
            r[0] *= s;
            r[1] *= s;
            r[2] *= s;
            r[3] *= s;
        }
    }
}
inline void Mat_001C6C18::Invert()
{
    Mat_001C6C18 t;
    t.Invert(*this);
    *this = t;
}

extern "C" void func_00323298(Vec_001C6C18* out, const Mat_001C6C18* m, const Vec_001C6C18* v);
static inline Vec_001C6C18 operator*(const Mat_001C6C18& m, const Vec_001C6C18& v)
{
    Vec_001C6C18 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline void Neg_001C6C18(Vec_001C6C18& r, const Vec_001C6C18& v)
{
    r.c[0] = -v[0];
    r.c[1] = -v[1];
    r.c[2] = -v[2];
    r.c[3] = -v[3];
}
static inline void Scale_001C6C18(Vec_001C6C18& r, const Vec_001C6C18& v, float k)
{
    r.c[0] = v[0] * k;
    r.c[1] = v[1] * k;
    r.c[2] = v[2] * k;
    r.c[3] = v[3] * k;
}

struct Rail_001C6C18;
struct Node_001C6C18 {
    char pad0[0x50];
    int m50;
};
struct Base_001C6C18 {
    char pad0[0xC];
    int mC;
    int m10;
    Base_001C6C18* m14;
};
struct Cand_001C6C18 : Base_001C6C18 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Rail_001C6C18* GetRail();
    Cand_001C6C18* Next() { return (Cand_001C6C18*)m14; }
};

extern "C" void func_00183CB8(void* p, void* pp);
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" unsigned int func_0010FC30();
struct Handle_001C6C18 {
    void* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};
struct Rec_001C6C18 {
    char pad0[0x1C];
    Handle_001C6C18* m1C;
    unsigned int m20;
    void Clear()
    {
        Handle_001C6C18* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};
struct Obj_001C6C18;
struct Name_001C6C18 {
    char s[8];
};
extern Name_001C6C18 D_0038D798[];
extern "C" void func_001C4210(Obj_001C6C18* o, Vec_001C6C18* v, float f);
struct State_001C6C18 {
    int m0;
    int m4;
    unsigned int m8;
    void Set(int s)
    {
        if (m4 != s) {
            m4 = s;
            m8 = func_0010FC30();
        }
    }
};
struct Phys_001C6C18 {
    char pad0[0xA0];
    int mA0;
    char padA4[0xE4 - 0xA4];
    State_001C6C18 mE4;
};
struct Sk_001C6C18 {
    char pad0[0x5B0];
    Phys_001C6C18* m5B0;
};
struct Info_001C6C18 {
    Vec_001C6C18 m0;
    Vec_001C6C18 m10;
    float m20;
    float m24;
    float m28;
    int m2C;
    Node_001C6C18* m30;
    char pad34[0x40 - 0x34];
};
struct World_001C6C18 {
    char pad0[0x28];
    Rail_001C6C18* m28;
};
struct Obj_001C6C18;
extern World_001C6C18* D_0038FC78;
extern void* D_0038C608;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C6C18(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" int func_00269BC8(Rail_001C6C18* r, Vec_001C6C18* a, Vec_001C6C18* b, Vec_001C6C18* p, Obj_001C6C18* o,
                             Info_001C6C18* info, float f);
extern "C" Cand_001C6C18* func_00187278(void* p, unsigned int id);
extern "C" Mat_001C6C18 func_001B7750(Cand_001C6C18* o);
extern "C" Handle_001C6C18* func_0020A6C0(void* mem, int id);
extern "C" float func_001CB6F8(Obj_001C6C18* o);
extern "C" float func_001CB670(Obj_001C6C18* o);
extern "C" void func_001BF130(Obj_001C6C18* o, int state);

struct Obj_001C6C18 {
    char pad0[0x30];
    Vec_001C6C18 m30;
    Vec_001C6C18 m40;
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C6C18 m60;
    char pad70[0x80 - 0x70];
    Vec_001C6C18 m80;
    unsigned int m90;
    char pad94[0xC4 - 0x94];
    float mC4;
    char padC8[0x970 - 0xC8];
    Vec_001C6C18 m970;
    char pad980[0xA1C - 0x980];
    Node_001C6C18* mA1C;
    int mA20;
    Rail_001C6C18* mA24;
    char padA28[0xA3C - 0xA28];
    Rec_001C6C18* mA3C;
    char padA40[0xA44 - 0xA40];
    Sk_001C6C18* mA44;
    char padA48[0xB54 - 0xA48];
    float mB54;
    char padB58[0xBD0 - 0xB58];
    Vec_001C6C18 mBD0;
    char padBE0[0xBE4 - 0xBE0];
    float mBE4;
    char padBE8[0xBF0 - 0xBE8];
    float mBF0;
    float mBF4;
    float mBF8;
    char padBFC[0xC10 - 0xBFC];
    Vec_001C6C18 mC10;
    char padC20[0xC30 - 0xC20];
    Vec_001C6C18 mC30;
    float mC40;
    float mC44;
    char padC48[0xC80 - 0xC48];
    int mC80;
    Name_001C6C18 mC84;
    int Snap();
};

int Obj_001C6C18::Snap()
{
    if (mA44->m5B0->mA0) return 0;
    float l = m40.LengthSqr();
    float k1 = Param_001C6C18(0x01D1E6AF);
    float k2 = Param_001C6C18(0xCC461B87);
    float r = k1 * (k2 + (Param_001C6C18(0x7213EF07) - k2) * mB54);
    if (l > r * r) return 0;
    Info_001C6C18 info;
    Vec_001C6C18 v;
    m80[3] = 1.0f;
    m30[3] = 1.0f;
    mA24 = D_0038FC78->m28;
    Neg_001C6C18(v, m60);
    int found = func_00269BC8(mA24, &m80, &m30, &v, this, &info, func_001E5318(0xA8276303, 0));
    if (found) {
        mA3C->Clear();
    } else {
        for (Cand_001C6C18* o = func_00187278(D_0038C608, 0x1CDFB2A3); o && !found; o = o->Next()) {
            Mat_001C6C18 inv = func_001B7750(o);
            inv.Invert();
            Vec_001C6C18 la = inv * m80;
            Vec_001C6C18 lb = inv * m30;
            mA24 = o->GetRail();
            Vec_001C6C18 n;
            Neg_001C6C18(n, m60);
            found = func_00269BC8(mA24, &la, &lb, &n, this, &info, func_001E5318(0xA8276303, 0));
            if (found) {
                int id = o->mC;
                Rec_001C6C18* rc = mA3C;
                rc->Clear();
                rc->m1C = func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), id);
            }
        }
    }
    if (!found) return 0;
    mA1C = info.m30;
    mA20 = info.m30->m50;
    m50 = 0.0f;
    m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mBF0 = info.m20;
    mBF4 = info.m28;
    mBF8 = info.m24;
    mC10 = m30;
    mC30 = info.m0;
    mC84 = D_0038D798[0];
    func_001C4210(this, &info.m10, Param_001C6C18(0xFDC8AEC0));
    mC80 = 1;
    Scale_001C6C18(v, info.m10, Param_001C6C18(0xC3263E6E));
    m970 = v;
    mBD0 = info.m10;
    mBE4 = m30[1];
    mC40 = mC4;
    mC44 = func_001CB670(this);
    func_001BF130(this, 4);
    m90 = 0xEB71D98E;
    return 1;
}
