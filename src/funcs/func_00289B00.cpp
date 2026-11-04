typedef int qword __attribute__((mode(TI)));
union Vec_00289B00 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    Vec_00289B00& operator=(const Vec_00289B00& o)
    {
        q = o.q;
        return *this;
    }
    float operator[](int i) const { return c[i]; }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void operator-=(const Vec_00289B00& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Mat_00289B00 {
    Vec_00289B00 r[4];
    Mat_00289B00& operator=(const Mat_00289B00& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_00289B00& operator[](int i) { return r[i]; }
    const Vec_00289B00& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_00289B00& m);
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
    void Invert(const Mat_00289B00& in);
};

static inline float Det3_00289B00(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_00289B00::Det() const
{
    const Mat_00289B00& m = *this;
    return m[0][0] * Det3_00289B00(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_00289B00::Adjoint(const Mat_00289B00& m)
{
    r[0].c[0] = Det3_00289B00(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_00289B00(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_00289B00(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_00289B00(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_00289B00(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_00289B00(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_00289B00(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_00289B00(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_00289B00(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_00289B00(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_00289B00(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_00289B00(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_00289B00(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_00289B00(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_00289B00::Invert(const Mat_00289B00& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) Scale(1.0f / d);
}
inline void Mat_00289B00::Invert()
{
    Mat_00289B00 t;
    t.Invert(*this);
    *this = t;
}

extern "C" void func_00323298(Vec_00289B00* out, const Mat_00289B00* m, const Vec_00289B00* v);
static inline Vec_00289B00 operator*(const Mat_00289B00& m, const Vec_00289B00& v)
{
    Vec_00289B00 r;
    func_00323298(&r, &m, &v);
    return r;
}

struct Body_00289B00 {
    char pad0[0x50];
    Vec_00289B00 m50;
    Vec_00289B00 m60;
    char pad70[0xB0 - 0x70];
    Vec_00289B00 mB0;
};
struct Rail_00289B00;
struct Node_00289B00;

struct Base_00289B00 {
    char pad0[0xC];
    int mC;
    int m10;
    Base_00289B00* m14;
};
struct Cand_00289B00 : Base_00289B00 {
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
    virtual Rail_00289B00* GetRail();
    Cand_00289B00* Next() { return (Cand_00289B00*)m14; }
};

extern "C" void func_00183CB8(void* p, void* pp);
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" unsigned int func_0010FC30();
static inline unsigned int Since_00289B00(unsigned int t) { return func_0010FC30() - t; }
struct Handle_00289B00 {
    Body_00289B00* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};
struct Rec_00289B00 {
    char pad0[0x1C];
    Handle_00289B00* m1C;
    unsigned int m20;
    void Clear()
    {
        Handle_00289B00* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};
struct Sub_00289B00 {
    char pad0[0x1C];
    int m1C;
    char pad20[0xA0 - 0x20];
    int mA0;
};
struct Ctl_00289B00 {
    char pad0[0x1DC];
    int m1DC;
};
struct Glob_00289B00 {
    char pad0[0xAC];
    unsigned int mAC;
};
struct World_00289B00 {
    char pad0[0x28];
    Rail_00289B00* m28;
};
struct Obj_00289B00;
extern Glob_00289B00* D_00392808;
extern World_00289B00* D_0038FC78;
extern void* D_0038C608;
extern "C" int func_001E53A0(unsigned int name, int v);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00340F60(float);
extern "C" int func_0026A270(Rail_00289B00* r, Vec_00289B00* a, Vec_00289B00* b, Vec_00289B00* out, Node_00289B00** node,
                             Node_00289B00* cur, float f, int k);
extern "C" void func_00279FD0(int, Vec_00289B00*, Vec_00289B00*);
extern "C" int func_0028A718(Obj_00289B00* o, Node_00289B00* n, Rail_00289B00* r, int k);
extern "C" void func_0028AAF8(Obj_00289B00* o, Vec_00289B00* p, Node_00289B00* n, Rail_00289B00* r, int a, int b);
extern "C" Cand_00289B00* func_00187278(void* p, unsigned int id);
extern "C" Mat_00289B00 func_001B7750(Cand_00289B00* o);
extern "C" Handle_00289B00* func_0020A6C0(void* mem, int id);

struct Obj_00289B00 {
    char pad0[0xC];
    Body_00289B00* mC;
    char pad10[0x2A4 - 0x10];
    unsigned int m2A4;
    int pad2A8;
    unsigned int m2AC;
    char pad2B0[0x424 - 0x2B0];
    int m424;
    char pad428[0x580 - 0x428];
    unsigned int m580;
    char pad584[0x594 - 0x584];
    Ctl_00289B00* m594;
    char pad598[0x5B0 - 0x598];
    Sub_00289B00* m5B0;
    Rec_00289B00* m5B4;
    void TryRail(int force);
};

void Obj_00289B00::TryRail(int force)
{
    if (m5B0->m1C != 1 && !force) return;
    if (m5B0->mA0) return;
    if (m424) return;
    if (!m594->m1DC) return;
    unsigned int s = m580;
    if (func_0010FC30() - s < (unsigned int)func_001E53A0(0x96DCA7DC, 0)) return;
    Vec_00289B00 a = mC->m60;
    Vec_00289B00 b = mC->m50;
    float k;
    if (D_00392808->mAC != 0xD443A2BC && Since_00289B00(m2A4) < m2AC)
        k = func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.01745329425f);
    else
        k = 1.0f;
    Vec_00289B00 hit;
    Node_00289B00* node;
    Rail_00289B00* rail = D_0038FC78->m28;
    if (func_0026A270(rail, &a, &b, &hit, &node, 0, k, 0)) {
        func_00279FD0(2, &mC->m60, &mC->m50);
        m5B4->Clear();
        if (func_0028A718(this, node, rail, 0)) func_0028AAF8(this, &hit, node, rail, 0, 0);
        return;
    }
    for (Cand_00289B00* o = func_00187278(D_0038C608, 0x1CDFB2A3); o; o = o->Next()) {
        Rail_00289B00* r = o->GetRail();
        Mat_00289B00 m = func_001B7750(o);
        Mat_00289B00 inv = m;
        inv.Invert();
        a[3] = 1.0f;
        b[3] = 1.0f;
        Vec_00289B00 la = inv * a;
        Vec_00289B00 lb = inv * b;
        if (func_0026A270(r, &la, &lb, &hit, &node, 0, k, 0)) {
            hit[3] = 1.0f;
            hit = m * hit;
            if (func_0028A718(this, node, r, 0)) {
                func_0028AAF8(this, &hit, node, r, 0, 0);
                int id = o->mC;
                Rec_00289B00* rc = m5B4;
                rc->Clear();
                rc->m1C = func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), id);
                mC->mB0 -= m5B4->m1C->m0->mB0;
            }
            return;
        }
    }
}
