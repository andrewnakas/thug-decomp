/* fuzzy: 97.5 */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
typedef int qword __attribute__((mode(TI)));
union Vec_00280918 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00280918() {}
    Vec_00280918(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Normalize();
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
    float LengthSqr() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};
extern "C" void func_003233B8(Vec_00280918*, Vec_00280918*);
inline void Vec_00280918::Normalize() { func_003233B8(this, this); }
inline Vec_00280918 operator*(const Vec_00280918& a, float k) { return Vec_00280918(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00280918 operator+(const Vec_00280918& a, const Vec_00280918& b)
{
    return Vec_00280918(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00280918 operator-(const Vec_00280918& a, const Vec_00280918& b)
{
    return Vec_00280918(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline Vec_00280918 operator-(const Vec_00280918& a) { return Vec_00280918(-a[0], -a[1], -a[2], -a[3]); }
static inline void Add_00280918(Vec_00280918& r, const Vec_00280918& a, const Vec_00280918& b)
{
    r.Set(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline float Dot_00280918(const Vec_00280918& a, const Vec_00280918& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

extern "C" void func_001BA4F0(void* q, const Vec_00280918* axis, float angle);
extern "C" void func_001BA5D0(Vec_00280918* out, const void* q, const Vec_00280918* v);
union Quat_00280918 {
    qword q;
    float c[4];
    Quat_00280918(const Vec_00280918& axis, float a) { func_001BA4F0(this, &axis, a); }
    void Rotate(Vec_00280918& out, const Vec_00280918& v) const { func_001BA5D0(&out, this, &v); }
};

struct Mat_00280918 {
    Vec_00280918 r0, r1, r2, r3;
    Mat_00280918& operator=(const Mat_00280918& o)
    {
        r0 = o.r0;
        r1 = o.r1;
        r2 = o.r2;
        r3 = o.r3;
        return *this;
    }
    Vec_00280918& operator[](int i) { return (&r0)[i]; }
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_00280918 {
    Vec_00280918 start;
    Vec_00280918 end;
    char pad20[0xA0 - 0x20];
    Vec_00280918 hit;
    Vec_00280918 normal;
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

struct Body_00280918 {
    char pad0[0x50];
    Vec_00280918 m50;
    Vec_00280918 m60;
    Mat_00280918 m70;
    Vec_00280918 mB0;
};
struct State_00280918 {
    int pad;
    int state;
    unsigned int time;
};
struct Sub_00280918 {
    char pad0[0x48];
    State_00280918 m48;
    char pad54[0x60 - 0x54];
    State_00280918 m60;
    char pad6C[0xA8 - 0x6C];
    State_00280918 mA8;
    char padB4[0xF0 - 0xB4];
    State_00280918 mF0;
    char padFC[0x140 - 0xFC];
    Vec_00280918 m140;
};
struct Ctl_00280918 {
    char pad0[0x74];
    int m74;
    char pad78[0x98 - 0x78];
    int m98;
};
struct Obj_00280918;
extern "C" unsigned int func_0010FC30();
extern "C" void* func_00209240(Coll_00280918* c);
extern "C" int func_002093E8(Coll_00280918* c, int a, int b);
extern "C" int func_00281438(Obj_00280918* o, Vec_00280918* dir, Vec_00280918* n, int* flag, Vec_00280918* pos, Vec_00280918* up);
extern "C" float func_00282C38(Obj_00280918* o, float a, float b, float c);
extern "C" void func_001016A8(Vec_00280918* v, Vec_00280918* n);
extern "C" float func_00101D60(Vec_00280918* a, Vec_00280918* b, Vec_00280918* c);
extern "C" Mat_00280918* func_00100928(Mat_00280918* out, float angle);
extern "C" void func_00323318(Mat_00280918* a, Mat_00280918* b, Mat_00280918* out);
extern "C" void func_00103000(Mat_00280918* a, Mat_00280918* b, Mat_00280918* c);
extern "C" void func_00103930(Mat_00280918* a, Mat_00280918* out, float t);
extern "C" void func_00103E60(Mat_00280918* a);
extern "C" void func_00184BC0(Body_00280918* b, unsigned int name, int a, int c, int d, void* s);
extern "C" void func_00183F88(Body_00280918* b, unsigned int name);

static inline void Set_00280918(State_00280918* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Obj_00280918 {
    char pad0[0xC];
    Body_00280918* mC;
    char pad10[0x3F4 - 0x10];
    float m3F4;
    char pad3F8[0x480 - 0x3F8];
    Mat_00280918 m480;
    char pad4C0[0x520 - 0x4C0];
    int m520;
    float m524;
    char pad528[0x530 - 0x528];
    Vec_00280918 m530;
    Mat_00280918 m540;
    char pad580[0x594 - 0x580];
    Ctl_00280918* m594;
    char pad598[0x5B0 - 0x598];
    Sub_00280918* m5B0;
    int Try();
};

int Obj_00280918::Try()
{
    int hit = 0;
    Vec_00280918 up = mC->m70.r1;
    up[1] = 0.0f;
    up.Normalize();
    Vec_00280918 side;
    side.Set(-up[2], 0.0f, up[0], 0.0f);
    Vec_00280918 back = -mC->mB0;
    back.Normalize();
    Vec_00280918 dir = back;
    {
        Quat_00280918 q(side, 1.5707964f);
        Vec_00280918 r;
        q.Rotate(r, dir);
        dir = r;
    }
    int flag = 0;
    Coll_00280918 c;
    Vec_00280918 pos;
    Vec_00280918 fwd;
    Coll_00280918* pc = &c;
    func_00209240(pc);
    c.start = mC->m50 + dir * 0.5f;
    c.end = mC->m50 + dir * 0.5f;
    c.end[1] -= 4000.0f;
    Vec_00280918 p;
    Vec_00280918 n;
    if (func_002093E8(pc, 1, 0)) {
        n = c.normal;
        p = c.hit;
        n[1] = 0.0f;
        n.Normalize();
        Vec_00280918 a = -dir;
        hit = func_00281438(this, &a, &n, &flag, &pos, &fwd);
        if (!hit) {
            a.Set(-n[2], 0.0f, n[0], 1.0f);
            if (m594->m74 && !m594->m98) {
                Vec_00280918 b;
                Add_00280918(b, a, -dir);
                b.Normalize();
                hit = func_00281438(this, &b, &n, &flag, &pos, &fwd);
            } else if (m594->m98 && !m594->m74) {
                Vec_00280918 b;
                Add_00280918(b, -a, -dir);
                b.Normalize();
                hit = func_00281438(this, &b, &n, &flag, &pos, &fwd);
            }
        }
    }
    if (!hit) {
        Coll_00280918::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    n[1] = 0.0f;
    n[0] = pos[0] - p[0];
    n[2] = pos[2] - p[2];
    n[3] = pos[3] - p[3];
    float zero = n[1];
    float dist = sqrtf(n[0] * n[0] + n[2] * n[2]);
    pos[1] = mC->m50[1];
    Vec_00280918 h = fwd;
    h[1] = zero;
    h.Normalize();
    Body_00280918* bd = mC;
    Vec_00280918 vel = bd->mB0;
    Vec_00280918* v = &bd->mB0;
    if (fabsf(Dot_00280918(up, h)) < 0.9f || dist > 24.0f) {
        bd->mB0[1] = v->Length();
        mC->mB0[0] = zero;
        mC->mB0[2] = zero;
    }
    dist += 1.0f;
    Set_00280918(&m5B0->mA8, 1);
    float t = func_00282C38(this, pos[1], mC->m50[1], mC->mB0[1]);
    Set_00280918(&m5B0->mA8, 0);
    if (t < 0.1f)
        t = 0.1f;
    float s = dist / t;
    if (dist > 24.0f && mC->mB0.LengthSqr() < s * s) {
        Coll_00280918::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    Vec_00280918 end = pos;
    end[1] = mC->m50[1];
    c.start = mC->m50;
    c.end = end;
    if (!func_002093E8(&c, 1, 0)) {
        Vec_00280918 e;
        if (!flag) {
            e = pos - mC->m50;
            e[1] = -(e[0] * fwd[0] + e[2] * fwd[2]) / fwd[1];
            e.Normalize();
        } else {
            Vec_00280918 d = pos - mC->m50;
            d.Normalize();
            if (Dot_00280918(d, h) < 0.0f)
                e.Set(0.0f, 1.0f, 0.0f, 1.0f);
            else
                e.Set(0.0f, -1.0f, 0.0f, 1.0f);
        }
        Mat_00280918 m = mC->m70;
        Mat_00280918 nm;
        nm.r2 = e;
        func_001016A8(&nm[2], &fwd);
        nm.r2.Normalize();
        nm.r1 = fwd;
        {
            Vec_00280918 x(nm.r1[1] * nm.r2[2] - nm.r1[2] * nm.r2[1],
                           nm.r1[2] * nm.r2[0] - nm.r1[0] * nm.r2[2],
                           nm.r1[0] * nm.r2[1] - nm.r1[1] * nm.r2[0], 0.0f);
            nm.r0 = x;
        }
        Vec_00280918* p3 = &nm.r3;
        p3->Set(0.0f, 0.0f, 0.0f, 1.0f);
        m530 = nm.r2;
        float ang = func_00101D60(&mC->m70.r2, &vel, &mC->m70.r1);
        if (fabsf(ang) < 0.52359885f)
            ang = 0.0f;
        Mat_00280918 tm;
        Mat_00280918* ptm;
        {
            Mat_00280918 r;
            Mat_00280918* src = func_00100928((Mat_00280918*)0x70003FC0, -ang);
            Mat_00280918* pr = &r;
            *pr = *src;
            func_00323318(pr, &nm, pr);
            ptm = &tm;
            tm = r;
            nm = r;
        }
        func_00103000(&m480, &m, &nm);
        m520 = 0;
        float k = t;
        if (t < 0.9f)
            k = 0.9f;
        m524 = k;
        m540 = m;
        func_00103930(&m480, ptm, 0.5f);
        if (tm.r1[1] < 0.0f)
            func_00103E60(&m480);
        float inv = 1.0f / t;
        m3F4 = pos[1];
        m5B0->m140 = (pos - mC->m50) * inv;
        m5B0->m140[1] = 0.0f;
        if (!flag)
            func_00184BC0(mC, 0xA5179E9E, -1, 0, 0, 0);
        else
            func_00184BC0(mC, 0x283BB5D6, -1, 0, 0, 0);
        func_00183F88(mC, 0x8FFEFB28);
        Set_00280918(&m5B0->mA8, 1);
        Set_00280918(&m5B0->mF0, 0);
        Set_00280918(&m5B0->m48, 0);
        Set_00280918(&m5B0->m60, 0);
    }
    Coll_00280918::Ref* r = &c.mC0;
        r->Release();
    return 1;
}
