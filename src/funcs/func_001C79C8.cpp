typedef int qword __attribute__((mode(TI)));
union Vec_001C79C8 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    Vec_001C79C8& operator=(const Vec_001C79C8& o)
    {
        q = o.q;
        return *this;
    }
    float operator[](int i) const { return c[i]; }
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
    void operator-=(const Vec_001C79C8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Mat_001C79C8 {
    Vec_001C79C8 r[4];
    Mat_001C79C8& operator=(const Mat_001C79C8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_001C79C8& operator[](int i) { return r[i]; }
    const Vec_001C79C8& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_001C79C8& m);
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
    void Invert(const Mat_001C79C8& in);
};

static inline float Det3_001C79C8(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_001C79C8::Det() const
{
    const Mat_001C79C8& m = *this;
    return m[0][0] * Det3_001C79C8(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_001C79C8::Adjoint(const Mat_001C79C8& m)
{
    r[0].c[0] = Det3_001C79C8(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_001C79C8(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_001C79C8(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_001C79C8(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_001C79C8(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_001C79C8(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_001C79C8(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_001C79C8(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_001C79C8(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_001C79C8(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_001C79C8(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_001C79C8(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_001C79C8(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_001C79C8(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_001C79C8::Invert(const Mat_001C79C8& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) Scale(1.0f / d);
}
inline void Mat_001C79C8::Invert()
{
    Mat_001C79C8 t;
    t.Invert(*this);
    *this = t;
}

extern "C" void func_00323298(Vec_001C79C8* out, const Mat_001C79C8* m, const Vec_001C79C8* v);
static inline Vec_001C79C8 operator*(const Mat_001C79C8& m, const Vec_001C79C8& v)
{
    Vec_001C79C8 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline void Scale_001C79C8(Vec_001C79C8& r, const Vec_001C79C8& v, float k)
{
    r.c[0] = v[0] * k;
    r.c[1] = v[1] * k;
    r.c[2] = v[2] * k;
    r.c[3] = v[3] * k;
}

struct Rail_001C79C8;
struct Node_001C79C8 {
    char pad0[0x50];
    int m50;
};
struct Base_001C79C8 {
    char pad0[0xC];
    int mC;
    int m10;
    Base_001C79C8* m14;
};
struct Cand_001C79C8 : Base_001C79C8 {
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
    virtual Rail_001C79C8* GetRail();
    Cand_001C79C8* Next() { return (Cand_001C79C8*)m14; }
};

extern "C" void func_00183CB8(void* p, void* pp);
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" unsigned int func_0010FC30();
struct Handle_001C79C8 {
    void* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};
struct Rec_001C79C8 {
    char pad0[0x1C];
    Handle_001C79C8* m1C;
    unsigned int m20;
    void Clear()
    {
        Handle_001C79C8* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};
struct State_001C79C8 {
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
struct Phys_001C79C8 {
    char pad0[0xE4];
    State_001C79C8 mE4;
};
struct Sk_001C79C8 {
    char pad0[0x5B0];
    Phys_001C79C8* m5B0;
};
struct Info_001C79C8 {
    Vec_001C79C8 m0;
    Vec_001C79C8 m10;
    float m20;
    float m24;
    float m28;
    int m2C;
    Node_001C79C8* m30;
    char pad34[0x40 - 0x34];
};
struct World_001C79C8 {
    char pad0[0x28];
    Rail_001C79C8* m28;
};
struct Obj_001C79C8;
extern World_001C79C8* D_0038FC78;
extern void* D_0038C608;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" int func_00269BC8(Rail_001C79C8* r, Vec_001C79C8* a, Vec_001C79C8* b, Vec_001C79C8* p, Obj_001C79C8* o,
                             Info_001C79C8* info, float f);
extern "C" Cand_001C79C8* func_00187278(void* p, unsigned int id);
extern "C" Mat_001C79C8 func_001B7750(Cand_001C79C8* o);
extern "C" Handle_001C79C8* func_0020A6C0(void* mem, int id);
extern "C" float func_001CB6F8(Obj_001C79C8* o);
extern "C" float func_001CB670(Obj_001C79C8* o);
extern "C" void func_001BF130(Obj_001C79C8* o, int state);

struct Obj_001C79C8 {
    char pad0[0x30];
    Vec_001C79C8 m30;
    Vec_001C79C8 m40;
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C79C8 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0xC4 - 0x94];
    float mC4;
    char padC8[0x970 - 0xC8];
    Vec_001C79C8 m970;
    char pad980[0xA1C - 0x980];
    Node_001C79C8* mA1C;
    int mA20;
    Rail_001C79C8* mA24;
    char padA28[0xA3C - 0xA28];
    Rec_001C79C8* mA3C;
    char padA40[0xA44 - 0xA40];
    Sk_001C79C8* mA44;
    char padA48[0xBF0 - 0xA48];
    float mBF0;
    float mBF4;
    float mBF8;
    int mBFC;
    int Snap(Vec_001C79C8* a, Vec_001C79C8* b);
};

int Obj_001C79C8::Snap(Vec_001C79C8* a, Vec_001C79C8* b)
{
    if (m50 > 50.0f) return 0;
    float da;
    float db;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xA8C13E74, &da, 1);
    (*a)[1] += da;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xA8C13E74, &db, 1);
    (*b)[1] += db;
    (*a)[3] = 1.0f;
    (*b)[3] = 1.0f;
    Info_001C79C8 info;
    mA24 = D_0038FC78->m28;
    int found = func_00269BC8(mA24, a, b, &m60, this, &info, func_001E5318(0x30CE7F2C, 0));
    if (found) {
        mA3C->Clear();
    } else {
        for (Cand_001C79C8* o = func_00187278(D_0038C608, 0x1CDFB2A3); o && !found; o = o->Next()) {
            Mat_001C79C8 inv = func_001B7750(o);
            inv.Invert();
            Vec_001C79C8 la = inv * *a;
            Vec_001C79C8 lb = inv * *b;
            mA24 = o->GetRail();
            found = func_00269BC8(mA24, &la, &lb, &m60, this, &info, func_001E5318(0x30CE7F2C, 0));
            if (found) {
                int id = o->mC;
                Rec_001C79C8* rc = mA3C;
                rc->Clear();
                rc->m1C = func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), id);
            }
        }
    }
    if (!found) return 0;
    mA1C = info.m30;
    mA20 = info.m30->m50;
    m30 = info.m0;
    m60 = info.m10;
    mBF0 = info.m20;
    mBF4 = info.m28;
    mBF8 = info.m24;
    mBFC = info.m2C;
    float k;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xC3263E6E, &k, 1);
    Vec_001C79C8 sv;
    Scale_001C79C8(sv, m60, k);
    m970 = sv;
    m970[1] = func_001CB6F8(this);
    m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m50 = 0.0f;
    mC4 = func_001CB670(this);
    func_001BF130(this, 2);
    m90 = 0x4194ECCA;
    mA44->m5B0->mE4.Set(1);
    return 1;
}
