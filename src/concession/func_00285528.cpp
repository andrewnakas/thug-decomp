/* force: {"kind": "lfr", "block": 79, "reg": 1465, "hard": 34} */
/* force: {"kind": "lfr", "block": 79, "reg": 1470, "hard": 35} */
/* sym: __as__13Wall_00285528RC13Wall_00285528 = 0x0019C9D8 */
typedef int qword __attribute__((mode(TI)));

union Vec_00285528 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00285528() {}
    Vec_00285528(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void operator+=(const Vec_00285528& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Vec_00285528& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float Length2() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    void SetLength(float len);
};

extern "C" float sqrtf(float);

inline void Vec_00285528::SetLength(float len)
{
    float cur = sqrtf(Length2());
    if (cur > 0.0f) {
        float k = len / cur;
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
    }
}

inline Vec_00285528 operator*(const Vec_00285528& a, float k) { return Vec_00285528(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00285528 operator+(const Vec_00285528& a, const Vec_00285528& b)
{
    return Vec_00285528(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

struct Mat_00285528 {
    Vec_00285528 r[4];
    const Vec_00285528& operator[](int i) const { return r[i]; }
    Vec_00285528 Up() const { return Vec_00285528(r[1][0], r[1][1], r[1][2], r[1][3]); }
    Mat_00285528& operator=(const Mat_00285528& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

static inline float Sq_00285528(float x) { return x * x; }

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);

/* Pooled resource handle with a position at +0x60. */
struct Res_00285528 {
    void* h;
    char pad4[0x60 - 4];
    Vec_00285528 m60;
};
extern "C" int func_0020A760(Res_00285528* r, Vec_00285528* pos);
static inline void Free_00285528(Res_00285528* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}
struct Holder_00285528 {
    char pad[0x1C];
    Res_00285528* m1C;
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
        Res_00285528* r = m1C;
        if (r) {
            Free_00285528(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_00285528* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Body_00285528 {
    char pad[0x50];
    Vec_00285528 m50;
    Vec_00285528 m60;
    Mat_00285528 m70;
    Vec_00285528 mB0;
};
struct Wall_00285528 {
    char pad0[0x6C];
    int m6C;
    char pad70[0xA0 - 0x70];
    Vec_00285528 hit;
    Vec_00285528 normal;
    char padC0[0xE0 - 0xC0];
    Wall_00285528& operator=(const Wall_00285528& o);
};
struct State_00285528 {
    int pad;
    int state;
    unsigned int time;
    bool On() { return state != 0; }
    int Elapsed()
    {
        int start = time;
        return func_0010FC30() - start;
    }
};
static inline unsigned int Since_00285528(unsigned int t) { return func_0010FC30() - t; }
static inline void Set_00285528(State_00285528* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Sub_00285528 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x3C - 0x20];
    State_00285528 m3C;
    State_00285528 m48;
    State_00285528 m54;
    State_00285528 m60;
    char pad6C[0x9C - 0x6C];
    State_00285528 m9C;
    State_00285528 mA8;
    State_00285528 mB4;
    char padC0[0xF0 - 0xC0];
    State_00285528 mF0;
    State_00285528 mFC;
    char pad108[0x13C - 0x108];
    int m13C;
    Vec_00285528 m140;
};
struct Timer_00285528 {
    int m0;
};
struct Pad_00285528 {
    char pad0[0x4];
    Timer_00285528 m4;
    char pad8[0x2C - 0x8];
    int m2C;
    char pad30[0xBC - 0x30];
    int mBC;
    char padC0[0x128 - 0xC0];
    int m128;
};
struct Input_00285528 {
    char pad0[0x24];
    Pad_00285528 pad;
};
struct Ctrl_00285528 {
    char pad0[0x2C];
    int m2C;
    char pad30[0x54 - 0x30];
    int m54;
};
struct Sk_00285528 {
    char pad0[0x2C];
    int m2C;
};
struct Snd_00285528 {
    char pad0[0x20];
    int m20;
    int m24;
};
struct Sys_00285528 {
    char pad0[0x1400];
    int m1400;
};
struct Target_00285528 {
    Vec_00285528 pos;
    Vec_00285528 up;
    float m20;
};

struct Obj_00285528;
extern "C" void func_00100DC0(Mat_00285528* m, int axis);
extern "C" void func_001016A8(Vec_00285528* v, Vec_00285528* n);
extern "C" int func_00101730(Vec_00285528* v, Vec_00285528* n);
extern "C" Vec_00285528* func_00101820(Vec_00285528* a, const Vec_00285528& b);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void func_001B0EB8(Sys_00285528* p, int a);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" float func_002032A0(unsigned int, int);
extern "C" int func_00203300(unsigned int, int);
extern "C" float func_00203D40(void* self, unsigned int name);
extern "C" int func_0026FD78(Timer_00285528* t);
extern "C" unsigned int func_0026FDA0(Timer_00285528* t);
extern "C" void func_00270C98(Snd_00285528* self, int a, float vol);
extern "C" void func_0027C720(Obj_00285528* self, int a);
extern "C" void func_0027DFB8(Obj_00285528* self);
extern "C" void func_0027FDB0(Obj_00285528* o, Vec_00285528* v);
extern "C" void func_0027FF70(Obj_00285528* self);
extern "C" void func_00280188(Obj_00285528* o);
extern "C" void func_00280448(Obj_00285528* o);
extern "C" int func_002817F0(Obj_00285528* o, int up, Vec_00285528* pos, Vec_00285528* from, Vec_00285528* vel,
                             Target_00285528* out);
extern "C" void func_002823A8(Obj_00285528* o, Target_00285528* t);
extern "C" float func_00282B58(Obj_00285528* o);
extern "C" void func_00282F68(Obj_00285528* o, Vec_00285528* v);
extern "C" void func_00283050(Obj_00285528* o);
extern "C" int func_00285258(Obj_00285528* o);
extern "C" void func_002867A8(Obj_00285528* o);
extern "C" void func_00286EF8(Obj_00285528* o);
extern "C" void func_00287160(Obj_00285528* o);
extern "C" void func_00287368(Obj_00285528* o);
extern "C" void func_002875A0(Obj_00285528* o);
extern "C" bool func_00287748(Obj_00285528* o, Vec_00285528* target);
extern "C" int func_00288208(Obj_00285528* o, Vec_00285528* t);
extern "C" bool func_002883B8(Obj_00285528* o);
extern "C" int func_0028E1C0(Obj_00285528* o, unsigned short a, unsigned short b);
extern "C" void func_003233B8(Vec_00285528* dst, Vec_00285528* src);

struct Obj_00285528 {
    char pad0[0xC];
    Body_00285528* mC;
    char pad10[0x20 - 0x10];
    Mat_00285528 m20;
    Vec_00285528 m60;
    Vec_00285528 m70;
    Vec_00285528 m80;
    int m90;
    float m94;
    char pad98[0xB0 - 0x98];
    Wall_00285528 mB0;
    Wall_00285528 m190;
    Vec_00285528 m270;
    Vec_00285528 m280;
    int m290;
    char pad294[0x2F0 - 0x294];
    Vec_00285528 m2F0;
    Vec_00285528 m300;
    char pad310[0x320 - 0x310];
    float m320;
    char pad324[0x384 - 0x324];
    float m384;
    char pad388[0x3E0 - 0x388];
    int m3E0;
    int m3E4;
    int m3E8;
    char pad3EC[0x3F4 - 0x3EC];
    float m3F4;
    unsigned int m3F8;
    char pad3FC[0x530 - 0x3FC];
    Vec_00285528 m530;
    char pad540[0x588 - 0x540];
    unsigned int m588;
    char pad58C[0x594 - 0x58C];
    Input_00285528* m594;
    void* m598;
    Snd_00285528* m59C;
    Sys_00285528* m5A0;
    Ctrl_00285528* m5A4;
    char pad5A8[0x5B0 - 0x5A8];
    Sub_00285528* m5B0;
    Holder_00285528* m5B4;
    Sk_00285528* m5B8;
    void Update();
};

void Obj_00285528::Update()
{
    Pad_00285528* pad = &m594->pad;
    Vec_00285528 grav(0.0f, func_00282B58(this), 0.0f, 1.0f);

    Set_00285528(&m5B0->m54, 0);
    if (m5B0->m3C.state || m5B0->mA8.state || m5B0->mF0.state || m5B0->m9C.state)
        Set_00285528(&m5B0->mFC, 1);
    func_002867A8(this);
    func_00286EF8(this);
    func_00287160(this);
    if (m5B0->mB4.state || pad->mBC || pad->m128)
        func_00287368(this);
    if (!m5B0->m3C.state && !m5B0->mA8.state && !m5A4->m2C && !m5A4->m54)
        func_002875A0(this);
    if (m384 != 0.0f)
        func_0027DFB8(this);

    Vec_00285528 vel = mC->mB0;
    if (m5B0->mA8.state) {
        if (vel[1] < 0.0f && mC->m50[1] < m3F4)
            m5B0->m140.SetLength(0.1f);
        else
            vel += m5B0->m140;
    }

    Vec_00285528 off(0.0f, 0.0f, 0.0f, 1.0f);
    if (m5B4->Update(&mC->m50))
        off = m5B4->m1C->m60;

    float dt = m94;
    mC->m50 += vel * dt + grav * (0.5f * dt * dt);
    mC->m50 += off;
    mC->mB0 += grav * m94;

    if (m5B0->m60.state) {
        if (m5B0->m48.state && m5B0->m3C.state) {
            m270 = mC->m50 + mC->m70.Up();
            m280 = mC->m50 + mC->m70.r[1] * -23.0f;
            if (!func_0028E1C0(this, 0x10, 0)) {
                func_00280448(this);
                Timer_00285528* t = &pad->m4;
                if (func_0026FD78(t) > func_00203300(0x6BB5B751, 0)
                    && (int)func_0026FDA0(t) > func_00203300(0x6BB5B751, 0))
                    Set_00285528(&m5B0->m60, 0);
            }
        }
        if (m5B0->m60.Elapsed() > func_00203300(0x26495947, 0))
            Set_00285528(&m5B0->m60, 0);
    } else if (m5B0->m3C.state && (pad->mBC || pad->m128) && !m5B0->mA8.state && mC->mB0[1] > 0.0f) {
        func_00280448(this);
    }

    if (!m5B4->Valid() && m5B0->m48.state && m5B0->m3C.state) {
        m270[0] = mC->m50[0];
        m270[1] = m2F0[1];
        m270[2] = mC->m50[2];
        m280 = m270;
        m270 += m300 * 30.0f;
        m280 -= m300 * 30.0f;
        int hit;
        if (m320 > 0.5f) {
            m270[1] += m320;
            m280[1] += m320;
            hit = func_0028E1C0(this, 0, 8);
            if (!hit) {
                float lift = m320;
                m320 = lift * 0.5f;
                m270[1] -= lift;
                m280[1] -= lift;
                hit = func_0028E1C0(this, 0, 8);
            }
        } else {
            hit = func_0028E1C0(this, 0, 8);
        }
        if (!hit) {
            int i = 0;
            do {
                m270[1] -= 3.0f;
                m280[1] -= 3.0f;
                hit = func_0028E1C0(this, 0, 8);
                if (hit) {
                    m2F0[1] = mB0.hit[1];
                    break;
                }
                i++;
            } while (i < 10);
        }
        float d = sqrtf(m300[0] * mB0.normal[0] + m300[2] * mB0.normal[2]);
        if (hit && d > 0.02f) {
            Vec_00285528 p = mB0.hit;
            if (p[1] < m2F0[1])
                p[1] = m2F0[1];
            m2F0 = p;
            mC->m50[0] = p[0];
            mC->m50[2] = p[2];
            m300 = mB0.normal;
            Body_00285528* b = mC;
            b->m50 += m300 * func_002032A0(0x78384871, 0);
            Vec_00285528 dir = m300;
            dir[1] = 0.0f;
            func_003233B8(&dir, &dir);
            Vec_00285528 face = dir;
            func_0027FDB0(this, &face);
            func_00101730(&mC->mB0, &dir);
        } else {
            Set_00285528(&m5B0->m48, 0);
        }
    }

    if (m5B0->m3C.On() && !m5B0->mA8.state && !m5A4->m2C && !m5A4->m54)
        func_0027FF70(this);
    else
        m20 = mC->m70;

    bool lip;
    {
        Vec_00285528 probe = mC->m60 + off;
        lip = func_00287748(this, &probe);
    }
    if (m5B0->m1C == 2 || m5B0->m1C == 5)
        return;
    m270 = mC->m60 + off;
    m280 = mC->m50;
    if (!lip && func_0028E1C0(this, 0x10, 0)) {
        bool flat = mB0.normal[1] < 0.1f;
        bool stuck = false;
        Vec_00285528 probe = mC->m60 + off;
        if (func_00288208(this, &probe) && (mC->mB0[1] > 10.0f || flat)) {
            unsigned int start = m5B4->m20;
            stuck = Since_00285528(start) > 500;
        }
        if (!stuck) {
            Vec_00285528 n = mB0.normal;
            Vec_00285528* pn = &n;
            mC->m50 = mB0.hit;
            mC->m50 += n;
            if (m290) {
                func_0027C720(this, 0);
                func_00280188(this);
                if (m5B0->m3C.state || m5B0->mA8.state) {
                    m3E4 = 1;
                    m3E8 = 1;
                } else {
                    m3E8 = 0;
                }
                m3E0 = m5B0->mA8.state;
                Wall_00285528* wall = &mB0;
                int surf = wall->m6C;
                m5B0->m13C = surf;
                m59C->m20 = surf;
                float speed = sqrtf(mC->mB0.Length2());
                float vol = speed / func_00203D40(mC, 0xCC5F87AA);
                func_00270C98(m59C, m5B0->m13C, vol);
                if (!m5A0->m1400)
                    func_001B0EB8(m5A0, 0);
                Wall_00285528* last = &m190;
                *last = *wall;
                int id = last->m6C;
                m59C->m24 = id;
                func_001BB080(m598, 3, last);
                if (m5B8->m2C) {
                    func_001848F0(mC, 0x532B16EF, 0);
                    return;
                }
                if (!m3E8 && !m3E4 && mC->mB0[0] == 0.0f && mC->mB0[2] == 0.0f && pad->m2C) {
                    mC->mB0[1] = 0.0f;
                } else {
                    if (!m5B0->mA8.state) {
                        func_001016A8(&mC->mB0, &mB0.normal);
                    } else {
                        Vec_00285528 saved = mC->mB0;
                        func_00101820(&mC->mB0, m530);
                        func_00101730(&mC->mB0, &mB0.normal);
                        Vec_00285528 v = mC->mB0;
                        func_00282F68(this, &v);
                        if (v[1] > 0.0f) {
                            mC->mB0 = saved;
                            func_001016A8(&mC->mB0, &mB0.normal);
                        }
                        if (mC->mB0.Length2() < Sq_00285528(func_001E5318(0x59484878, 0))) {
                            Vec_00285528* pv = &mC->mB0;
                            pv->SetLength(func_001E5318(0x59484878, 0));
                        }
                    }
                    if (mC->mB0.Length2() < 100.0f) {
                        mC->mB0.Set(0.0f, 0.0f, 0.0f, 0.0f);
                    }
                }
                Set_00285528(&m5B0->m3C, 0);
                m60 = mB0.normal;
                m70 = mB0.normal;
                m80 = mB0.normal;
                mC->m70.r[1] = mB0.normal;
                func_00100DC0(&mC->m70, 1);
                m20 = mC->m70;
                func_001848F0(mC, 0x532B16EF, 0);
                return;
            }
            func_00101730(&mC->mB0, pn);
            func_00101730(&mC->m70.r[2], pn);
            func_00100DC0(&mC->m70, 2);
            m20 = mC->m70;
            Body_00285528* b = mC;
            b->m50 += n * func_002032A0(0x23410C14, 0);
            Set_00285528(&m5B0->mFC, 1);
        }
    } else if (!m5B0->m3C.state) {
        func_00283050(this);
    }

    if (func_002883B8(this))
        Set_00285528(&m5B0->mFC, 1);
    func_00285258(this);
    if (!m5B0->mFC.state && (pad->mBC || pad->m128)) {
        unsigned int last = m3F8;
        int recent = 0;
        if (m588 < last)
            recent = Since_00285528(last) < 250;
        Target_00285528 target;
        if (func_002817F0(this, recent, &mC->m50, &mC->m60, &mC->mB0, &target))
            func_002823A8(this, &target);
    }
}
