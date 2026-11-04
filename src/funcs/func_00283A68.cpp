typedef int qword __attribute__((mode(TI)));
union Vec_00283A68 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00283A68() {}
    Vec_00283A68(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_00283A68(float x, float y, float z)
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
    void operator-=(const Vec_00283A68& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator+=(const Vec_00283A68& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_00283A68*, Vec_00283A68*);
inline float Vec_00283A68::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline void Vec_00283A68::Normalize() { func_003233B8(this, this); }
inline Vec_00283A68 operator*(const Vec_00283A68& a, float k) { return Vec_00283A68(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00283A68 operator+(const Vec_00283A68& a, const Vec_00283A68& b)
{
    return Vec_00283A68(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00283A68 operator-(const Vec_00283A68& a, const Vec_00283A68& b)
{
    return Vec_00283A68(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_00283A68(const Vec_00283A68& a, const Vec_00283A68& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_00283A68 Cross_00283A68(const Vec_00283A68& a, const Vec_00283A68& b)
{
    return Vec_00283A68(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_00283A68 {
    Vec_00283A68 r[4];
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_00283A68;
extern "C" Coll_00283A68* func_00209280(Coll_00283A68* c, const Vec_00283A68& s, const Vec_00283A68& e);
struct Coll_00283A68 {
    Vec_00283A68 start;
    Vec_00283A68 end;
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

struct Body_00283A68 {
    char pad0[0x50];
    Vec_00283A68 m50;
    Vec_00283A68 m60;
    Mat_00283A68 m70;
    Vec_00283A68 mB0;
    void GetMatrix(Mat_00283A68* out) { *out = m70; }
};
struct State_00283A68 {
    int pad;
    int state;
    unsigned int time;
};
struct Sub_00283A68 {
    char pad0[0xE4];
    State_00283A68 mE4;
    char padF0[0xFC - 0xF0];
    State_00283A68 mFC;
    char pad108[0x114 - 0x108];
    State_00283A68 m114;
    char pad120[0x184 - 0x120];
    float m184;
};
struct Ctl_00283A68 {
    char pad0[0x1DC];
    int m1DC;
};
struct Sk_00283A68 {
    char pad0[0x2C];
    int m2C;
};
struct Arr_00283A68 {
    char pad0[0xC];
    unsigned int mC;
};
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
struct Handle_00283A68 {
    void* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};
extern "C" unsigned int func_0010FC30();
struct Rec_00283A68 {
    char pad0[0x1C];
    Handle_00283A68* m1C;
    unsigned int m20;
    void Clear()
    {
        Handle_00283A68* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Valid()
    {
        Handle_00283A68* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        Clear();
        return false;
    }
};
struct Wall_00283A68 {
    Vec_00283A68 start;
    Vec_00283A68 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0x74 - 0x6A];
    int m74;
    char pad78[0xA0 - 0x78];
    Vec_00283A68 hit;
    Vec_00283A68 normal;
    int Flag8() const { return m68 & 8; }
};
struct Obj_00283A68;
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" int func_00101730(Vec_00283A68*, Vec_00283A68*);
extern "C" int func_002093E8(void* c, int a, int b);
extern "C" float func_00341068(float);
extern "C" Arr_00283A68* func_001E55B8(unsigned int id, int v);
extern "C" int func_001E9378(Arr_00283A68* a, int i);
extern "C" int func_001AC030(void* m, int v, int a, unsigned int b);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" int func_00209A00(Wall_00283A68* w);
extern "C" int func_00209A30(Wall_00283A68* w);
extern "C" Handle_00283A68* func_0020A6C0(void* mem, int id);
extern "C" void func_001848F0(Body_00283A68* b, unsigned int name, int a);
extern "C" void func_001B0EF0(void* m, int v);
extern "C" void func_0027C720(Obj_00283A68* o, int v);

static inline void Set_00283A68(State_00283A68* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
static inline float Max_00283A68(float a, float b) { return a > b ? a : b; }

struct Obj_00283A68 {
    char pad0[0xC];
    Body_00283A68* mC;
    char pad10[0x20 - 0x10];
    Mat_00283A68 m20;
    char pad60[0xB0 - 0x60];
    Wall_00283A68 mB0;
    char pad170[0x580 - 0x170];
    unsigned int m580;
    char pad584[0x594 - 0x584];
    Ctl_00283A68* m594;
    void* m598;
    void* m59C;
    void* m5A0;
    char pad5A4[0x5B0 - 0x5A4];
    Sub_00283A68* m5B0;
    Rec_00283A68* m5B4;
    Sk_00283A68* m5B8;
    bool TryWall();
};

bool Obj_00283A68::TryWall()
{
    if (mC->m70.r[1][1] < 0.1f) return false;
    unsigned int s = m580;
    float el = (float)(func_0010FC30() - s);
    if (el < func_001E5318(0x82135DD7, 0)) return false;
    Sub_00283A68* sb = m5B0;
    if (sb->m184 < func_001E5318(0xD5349CC6, 0)) return false;
    if (!mB0.Flag8()) {
        if (0.1f < fabsf(mB0.normal[1])) return false;
    }
    Wall_00283A68* w = &mB0;
    Body_00283A68* b = mC;
    float sp = b->mB0.Length();
    if (sp < 0.01f) return false;
    Vec_00283A68 vel = b->mB0 * (1.0f / sp);
    Vec_00283A68 dir = vel;
    dir[1] = 0.0f;
    dir.Normalize();
    Vec_00283A68 n = mB0.normal;
    n[1] = 0.0f;
    n.Normalize();
    float d = Dot_00283A68(dir, n);
    if (-func_00341068(func_001E5318(0x8F79CC1C, 0) * 0.01745329425f) < d) return false;
    Body_00283A68* b1 = mC;
    if (0.0f < b1->mB0[1] && m594->m1DC) {
        Vec_00283A68 p = mB0.hit;
        Vec_00283A68 nn = mB0.normal;
        Vec_00283A68 u(0.0f, b1->mB0[1] * 0.15f, 0.0f);
        func_00101730(&u, &nn);
        p += u;
        Coll_00283A68 c;
        Coll_00283A68* pc = &c;
        func_00209280(pc, p + nn * 6.0f, p - nn * 6.0f);
        if (!func_002093E8(pc, 1, 0)) {
            pc->mC0.Release();
            return false;
        }
        pc->mC0.Release();
    }
    int found = 0;
    Arr_00283A68* arr = func_001E55B8(0x5D1F84A7, 0);
    for (unsigned int i = 0; i < arr->mC; i++) {
        if (func_001AC030(m5A0, func_001E9378(arr, i), 1, 0xFFFFFFFF)) {
            found = 1;
            break;
        }
    }
    if (!found) return false;
    func_001BB080(m598, 2, w);
    if (m5B8->m2C) return true;
    mC->mB0[1] = 0.0f;
    Body_00283A68* b2 = mC;
    Vec_00283A68 r = n * Dot_00283A68(b2->mB0, n);
    b2->mB0 -= r * 2.0f;
    Body_00283A68* b3 = mC;
    float h = sqrtf(b3->mB0[0] * b3->mB0[0] + b3->mB0[2] * b3->mB0[2]);
    if (9.999999747e-05f < h) {
        b3->mB0[1] = 0.0f;
        Body_00283A68* b4 = mC;
        Vec_00283A68* v = &b4->mB0;
        float mn = func_001E5318(0x7CEE396C, 0);
        float t = func_001E5318(0x9B2D4A3, 0);
        float tgt = Max_00283A68(mn, h - t);
        float l = v->Length();
        if (0.0f < l) v->Scale3(tgt / l);
    } else {
        b3->mB0 = dir * -func_001E5318(0x7CEE396C, 0);
    }
    mC->mB0[1] = func_001E5318(0x74957FA, 0);
    if (func_00209A00(w) && (!m5B4->Valid() || func_00209A30(w) != (int)m5B4->m1C->m0)) {
        m5B4->Clear();
        int id = func_00209A30(w);
        Rec_00283A68* r = m5B4;
        r->Clear();
        r->m1C = func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), id);
    }
    mB0.start = mB0.hit;
    mB0.end = mB0.hit + mB0.normal * func_001E5318(0x24BE8F0, 0);
    if (func_002093E8(w, 1, 0))
        mC->m50 = mB0.hit + mB0.normal * 0.1f;
    else
        mC->m50 = mB0.end;
    mC->m70.r[2] = mC->mB0;
    mC->m70.r[2][1] = 0.0f;
    mC->m70.r[2].Normalize();
    mC->m70.r[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
    mC->m70.r[0] = Cross_00283A68(mC->m70.r[1], mC->m70.r[2]);
    mC->GetMatrix(&m20);
    m580 = func_0010FC30();
    func_001848F0(mC, 0xCF74F6B7, 0);
    func_001B0EF0(m5A0, w->m74);
    Set_00283A68(&m5B0->m114, 0);
    Set_00283A68(&m5B0->mFC, 0);
    Set_00283A68(&m5B0->mE4, 1);
    func_0027C720(this, 5);
    return true;
}
