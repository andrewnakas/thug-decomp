typedef int qword __attribute__((mode(TI)));
union Vec_00287748 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00287748() {}
    Vec_00287748(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_00287748(float x, float y, float z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        c[3] = 1.0f;
    }
    float Length() const;
    void Normalize();
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void Scale3(float f)
    {
        c[0] *= f;
        c[1] *= f;
        c[2] *= f;
    }
    void operator-=(const Vec_00287748& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator+=(const Vec_00287748& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_00287748*, Vec_00287748*);
inline float Vec_00287748::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline void Vec_00287748::Normalize() { func_003233B8(this, this); }
inline Vec_00287748 operator*(const Vec_00287748& a, float k) { return Vec_00287748(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00287748 operator+(const Vec_00287748& a, const Vec_00287748& b)
{
    return Vec_00287748(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00287748 operator-(const Vec_00287748& a, const Vec_00287748& b)
{
    return Vec_00287748(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_00287748(const Vec_00287748& a, const Vec_00287748& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_00287748 Cross_00287748(const Vec_00287748& a, const Vec_00287748& b)
{
    return Vec_00287748(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_00287748 {
    Vec_00287748 r[4];
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_00287748;
extern "C" Coll_00287748* func_00209280(Coll_00287748* c, const Vec_00287748& s, const Vec_00287748& e);
struct Coll_00287748 {
    Vec_00287748 start;
    Vec_00287748 end;
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

struct Body_00287748 {
    char pad0[0x50];
    Vec_00287748 m50;
    Vec_00287748 m60;
    Mat_00287748 m70;
    Vec_00287748 mB0;
};
struct State_00287748 {
    int pad;
    int state;
    unsigned int time;
};
struct Sub_00287748 {
    char pad0[0x3C];
    State_00287748 m3C;
    char pad48[0xAC - 0x48];
    int mAC;
    char padB0[0xFC - 0xB0];
    State_00287748 mFC;
};
struct Sk_00287748 {
    char pad0[0x2C];
    int m2C;
};
struct Ball_00287748 {
    char pad0[0xB0];
    Vec_00287748 mB0;
};
struct Wall_00287748 {
    Vec_00287748 start;
    Vec_00287748 end;
    char pad20[0x6C - 0x20];
    int m6C;
    char pad70[0xA0 - 0x70];
    Vec_00287748 hit;
    Vec_00287748 normal;
};
extern "C" unsigned int func_0010FC30();
struct Obj_00287748;
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00203D40(Body_00287748* o, unsigned int name);
extern "C" int func_00101730(Vec_00287748*, Vec_00287748*);
extern "C" void func_001016A8(Vec_00287748* v, Vec_00287748* n);
extern "C" int func_002093E8(Coll_00287748* c, int a, int b);
extern "C" int func_0028E1C0(Obj_00287748* o, unsigned short a, unsigned short b);
extern "C" void func_0028ED58(Coll_00287748* c, Wall_00287748* w);
extern "C" int func_00288208(Obj_00287748* o, Vec_00287748* t);
extern "C" int func_0019C9D8(Wall_00287748* w, Coll_00287748* c);
extern "C" int func_00283A68(Obj_00287748* o);
extern "C" int func_002843F0(Obj_00287748* o);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" void func_00270DD8(void* p, int a, float v);
extern "C" int func_00209A00(Wall_00287748* w);
extern "C" Ball_00287748* func_00209A30(Wall_00287748* w);

static inline void Set_00287748(State_00287748* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Obj_00287748 {
    char pad0[0xC];
    Body_00287748* mC;
    char pad10[0x70 - 0x10];
    Vec_00287748 m70;
    char pad80[0x94 - 0x80];
    float m94;
    char pad98[0xB0 - 0x98];
    Wall_00287748 mB0;
    char pad170[0x270 - 0x170];
    Vec_00287748 m270;
    Vec_00287748 m280;
    int m290;
    char pad294[0x598 - 0x294];
    void* m598;
    void* m59C;
    char pad5A0[0x5B0 - 0x5A0];
    Sub_00287748* m5B0;
    char pad5B4[0x5B8 - 0x5B4];
    Sk_00287748* m5B8;
    bool TryLip(Vec_00287748* target);
};

bool Obj_00287748::TryLip(Vec_00287748* target)
{
    Vec_00287748 d = mC->m50 - *target;
    d.Normalize();
    Body_00287748* b = mC;
    Vec_00287748 off = b->m70.r[1] * func_002032A0(0xD4205C9B, 0);
    m270 = *target + off;
    m280 = mC->m50 + off + d * func_002032A0(0x20102726, 0);
    if (!func_0028E1C0(this, 0x10, 0)) return false;
    Wall_00287748* w = &mB0;
    Vec_00287748 n = mB0.normal;
    float dt = n[0] * m70[0] + n[1] * m70[1] + n[2] * m70[2];
    if (!m290 || (dt < 0.8000000119f && n[1] < 0.5f)) {
        Coll_00287748 c;
        func_0028ED58(&c, w);
        bool steep = mB0.normal[1] < 0.1f;
        Vec_00287748 save = mC->m50;
        mC->m50 = m280 - off;
        if (func_00288208(this, target)) {
            if (10.0f < mC->mB0[1] || steep) {
                c.mC0.Release();
                return true;
            }
        }
        Body_00287748* b0 = mC;
        b0->m50 = save;
        func_0019C9D8(w, &c);
        Body_00287748* b1 = mC;
        if (0.5f < b1->m70.r[1][1]) {
            if (0.0f < b1->mB0[1]) {
                if (n[1] < 0.009999999776f) {
                    float h = func_002032A0(0x786B3272, 0);
                    c.start[1] += h;
                    c.end[1] += h;
                    if (!func_002093E8(&c, 1, 0)) {
                        if (4.0f < h) {
                            do {
                                c.start[1] -= 2.0f;
                                c.end[1] -= 2.0f;
                                if (func_002093E8(&c, 1, 0)) {
                                    mC->m50[1] += h;
                                    Coll_00287748::Ref* r = &c.mC0;
                                    r->Release();
                                    return true;
                                }
                                h -= 2.0f;
                            } while (4.0f < h);
                        }
                        mC->m50[1] += h;
                        Coll_00287748::Ref* r = &c.mC0;
                                    r->Release();
                        return true;
                    }
                }
            }
        }
        if (m5B0->m3C.state) {
            mC->m50 = mB0.hit - off;
            Body_00287748* b2 = mC;
            b2->m50 += n * func_002032A0(0x23410C14, 0);
            Vec_00287748* pn = &n;
            if (!m5B0->mAC)
                func_001016A8(&mC->mB0, pn);
            else
                func_00101730(&mC->mB0, &mB0.normal);
        } else if (!func_00283A68(this) && !func_002843F0(this)) {
            Set_00287748(&m5B0->mFC, 1);
            func_001BB080(m598, 6, w);
            if (!m5B8->m2C) {
                if (mB0.normal[1] < 0.05000000075f) {
                    Body_00287748* bb = mC;
                    float sp = bb->mB0.Length();
                    float k = func_00203D40(bb, 0xCC5F87AA);
                    func_00270DD8(m59C, w->m6C, sp / k);
                }
                float sy = 0.0f;
                if (-0.1f < n[1]) {
                    Body_00287748* bc = mC;
                    sy = bc->mB0[1];
                    bc->mB0[1] = 0.0f;
                }
                Vec_00287748* pn = &n;
                func_001016A8(&mC->mB0, pn);
                Body_00287748* bd = mC;
                bd->mB0 += n * (bd->mB0.Length() * 0.1f);
                if (-0.1f < n[1]) mC->mB0[1] = sy;
                Body_00287748* be = mC;
                float ry = be->m70.r[2][1];
                be->m70.r[2][1] = 0.0f;
                func_00101730(&mC->m70.r[2], pn);
                mC->m70.r[2][1] = ry;
                mC->m70.r[2] += n * 0.05000000075f;
                mC->m70.r[2].Normalize();
                mC->m70.r[0] = Cross_00287748(mC->m70.r[1], mC->m70.r[2]);
                mC->m70.r[0].Normalize();
                mC->m70.r[1] = Cross_00287748(mC->m70.r[2], mC->m70.r[0]);
                mC->m70.r[1].Normalize();
                mC->m50 = mB0.hit - off;
                Body_00287748* bf = mC;
                bf->m50 += n * func_002032A0(0x23410C14, 0);
                if (func_00209A00(w)) {
                    Vec_00287748 v = func_00209A30(w)->mB0;
                    if (0.0f < Dot_00287748(v, mB0.normal)) {
                        mC->m50 += v * m94 * 2.0f;
                        mC->mB0 += v;
                    }
                }
            }
        }
        Coll_00287748::Ref* r = &c.mC0;
        r->Release();
        return false;
    }
    return false;
}
