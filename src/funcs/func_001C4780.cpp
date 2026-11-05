typedef int qword __attribute__((mode(TI)));
union Vec_001C4780 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    Vec_001C4780& operator=(const Vec_001C4780& o)
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
    void operator-=(const Vec_001C4780& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Mat_001C4780 {
    Vec_001C4780 r[4];
    Mat_001C4780& operator=(const Mat_001C4780& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_001C4780& operator[](int i) { return r[i]; }
    const Vec_001C4780& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_001C4780& m);
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
    void Invert(const Mat_001C4780& in);
};

static inline float Det3_001C4780(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_001C4780::Det() const
{
    const Mat_001C4780& m = *this;
    return m[0][0] * Det3_001C4780(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_001C4780::Adjoint(const Mat_001C4780& m)
{
    r[0].c[0] = Det3_001C4780(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_001C4780(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_001C4780(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_001C4780(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_001C4780(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_001C4780(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_001C4780(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_001C4780(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_001C4780(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_001C4780(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_001C4780(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_001C4780(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_001C4780(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_001C4780(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_001C4780::Invert(const Mat_001C4780& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) Scale(1.0f / d);
}
inline void Mat_001C4780::Invert()
{
    Mat_001C4780 t;
    t.Invert(*this);
    *this = t;
}

extern "C" void func_00323298(Vec_001C4780* out, const Mat_001C4780* m, const Vec_001C4780* v);
static inline Vec_001C4780 operator*(const Mat_001C4780& m, const Vec_001C4780& v)
{
    Vec_001C4780 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline void Sub_001C4780(Vec_001C4780& r, const Vec_001C4780& a, const Vec_001C4780& b)
{
    r.c[0] = a[0] - b[0];
    r.c[1] = a[1] - b[1];
    r.c[2] = a[2] - b[2];
    r.c[3] = a[3] - b[3];
}
struct Rail_001C4780;
struct Node_001C4780 {
    char pad0[0x50];
    int m50;
    int m54;
};
struct Base_001C4780 {
    char pad0[0xC];
    int mC;
    int m10;
    Base_001C4780* m14;
};
struct Cand_001C4780 : Base_001C4780 {
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
    virtual Rail_001C4780* GetRail();
    Cand_001C4780* Next() { return (Cand_001C4780*)m14; }
};
extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C4780;
extern "C" Coll_001C4780* func_00209280(Coll_001C4780* c, Vec_001C4780* s, Vec_001C4780* e);
extern "C" int func_002093E8(Coll_001C4780* c, int a, int b);
struct Coll_001C4780 {
    char pad0[0xA0];
    Vec_001C4780 mA0;
    char padB0[0xC0 - 0xB0];
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
struct World_001C4780 {
    char pad0[0x28];
    Rail_001C4780* m28;
};
struct Flag_001C4780 {
    char pad0[0x28];
    int m28;
};
extern World_001C4780* D_0038FC78;
extern void* D_0038C608;
extern char D_00363518[];
extern "C" int func_0026A270(Rail_001C4780* r, Vec_001C4780* a, Vec_001C4780* b, Vec_001C4780* out, Node_001C4780** node,
                             Node_001C4780* cur, float f, int k);
extern "C" int func_0028A718(void* o, Node_001C4780* n, Rail_001C4780* r, int k);
extern "C" Cand_001C4780* func_00187278(void* p, unsigned int id);
extern "C" Mat_001C4780 func_001B7750(Cand_001C4780* o);
extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" double func_0033ECA8(float x);
extern "C" void func_00103F28(char* fmt, ...);

struct Obj_001C4780 {
    char pad0[0x30];
    Vec_001C4780 m30;
    char pad40[0x80 - 0x40];
    Vec_001C4780 m80;
    unsigned int m90;
    char pad94[0x9B0 - 0x94];
    int m9B0;
    char pad9B4[0x9C0 - 0x9B4];
    Vec_001C4780 m9C0;
    Rail_001C4780* m9D0;
    Node_001C4780* m9D4;
    int m9D8;
    char pad9DC[0xA38 - 0x9DC];
    Flag_001C4780* mA38;
    char padA3C[0xA44 - 0xA3C];
    void* mA44;
    int Snap();
};

int Obj_001C4780::Snap()
{
    if (mA38->m28) return 0;
    int found = func_0026A270(D_0038FC78->m28, &m80, &m30, &m9C0, &m9D4, 0, 1.0f, 0);
    if (found) {
        m9D0 = D_0038FC78->m28;
        m9D8 = 0;
    } else {
        m80[3] = 1.0f;
        m30[3] = 1.0f;
        for (Cand_001C4780* o = func_00187278(D_0038C608, 0x1CDFB2A3); o && !found; o = o->Next()) {
            Mat_001C4780 m = func_001B7750(o);
            Mat_001C4780 inv = m;
            inv.Invert();
            Vec_001C4780 la = inv * m80;
            Vec_001C4780 lb = inv * m30;
            found = func_0026A270(o->GetRail(), &la, &lb, &m9C0, &m9D4, 0, 1.0f, 0);
            if (found) {
                m9D0 = o->GetRail();
                m9C0 = m * m9C0;
                m9D8 = o->mC;
            }
        }
    }
    if (!found) return 0;
    if (!func_0028A718(mA44, m9D4, m9D0, 1)) return 0;
    Node_001C4780* n = m9D4;
    if (!n->m54 && !n->m50) return 0;
    Coll_001C4780 c;
    func_00209280(&c, &m30, &m9C0);
    if (func_002093E8(&c, 1, 0)) {
        Vec_001C4780 d;
        Sub_001C4780(d, m9C0, c.mA0);
        if (d[0] * d[0] + d[1] * d[1] + d[2] * d[2] > 36.0f) {
            Coll_001C4780::Ref* h = &c.mC0;
            h->Release();
            return 0;
        }
    }
    if (func_001E5628(0x19FB78FA, 1))
        func_00103F28(D_00363518, 2, func_0033ECA8(m80[0]), func_0033ECA8(m80[1]), func_0033ECA8(m80[2]),
                      func_0033ECA8(m30[0]), func_0033ECA8(m30[1]), func_0033ECA8(m30[2]));
    m9B0 = 1;
    m90 = 0xA6A3147E;
    Coll_001C4780::Ref* h = &c.mC0;
    h->Release();
    return 1;
}
