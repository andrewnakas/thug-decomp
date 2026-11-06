typedef int qword __attribute__((mode(TI)));
union Vec_0028F0C8 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028F0C8() {}
    Vec_0028F0C8(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_0028F0C8(float x, float y, float z)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = 1.0f;
    }
    void operator+=(const Vec_0028F0C8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float LengthSqr() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
};
inline Vec_0028F0C8 operator*(const Vec_0028F0C8& a, float k) { return Vec_0028F0C8(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0028F0C8 operator+(const Vec_0028F0C8& a, const Vec_0028F0C8& b)
{
    return Vec_0028F0C8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_0028F0C8 operator-(const Vec_0028F0C8& a, const Vec_0028F0C8& b)
{
    return Vec_0028F0C8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline Vec_0028F0C8 operator-(const Vec_0028F0C8& a) { return Vec_0028F0C8(-a[0], -a[1], -a[2], -a[3]); }

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
extern void* D_00388A70;

static inline void Release_0028F0C8(void** ref)
{
    if (*ref == 0)
        return;
    func_00183CB8(*ref, ref);
    *ref = 0;
}

struct Coll_0028F0C8 {
    Vec_0028F0C8 start;
    Vec_0028F0C8 end;
    char pad20[0xA0 - 0x20];
    Vec_0028F0C8 hit;
    char padB0[0xC0 - 0xB0];
    void* mC0;
    char padC4[0xE0 - 0xC4];
    ~Coll_0028F0C8() { Release_0028F0C8(&mC0); }
};

struct Body_0028F0C8 {
    char pad0[0x50];
    Vec_0028F0C8 m50;
    char pad60[0x80 - 0x60];
    Vec_0028F0C8 m80;
    char pad90[0xB0 - 0x90];
    Vec_0028F0C8 mB0;
};

struct Handle_0028F0C8 {
    Body_0028F0C8* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};

struct Rec_0028F0C8 {
    char pad0[0x1C];
    Handle_0028F0C8* m1C;
    unsigned int m20;
    void Clear()
    {
        Handle_0028F0C8* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Valid()
    {
        Handle_0028F0C8* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        Clear();
        return false;
    }
};

struct Sub_0028F0C8 {
    char pad0[0x1C];
    int m1C;
    char pad20[0xAC - 0x20];
    int mAC;
    char padB0[0xC4 - 0xB0];
    int mC4;
};

struct Wall_0028F0C8 {
    int m0;
};

struct Skater_0028F0C8 {
    char pad0[0xA0];
    Vec_0028F0C8 mA0;
    Wall_0028F0C8 mB0;
    char padB4[0x150 - 0xB4];
    Vec_0028F0C8 m150;
    Vec_0028F0C8 m160;
    char pad170[0x270 - 0x170];
    Vec_0028F0C8 m270;
    Vec_0028F0C8 m280;
    char pad290[0x5B0 - 0x290];
    Sub_0028F0C8* m5B0;
    bool AtPos(const Vec_0028F0C8& p) const
    {
        return p.c[0] == mA0.c[0] && p.c[1] == mA0.c[1] && p.c[2] == mA0.c[2] && p.c[3] == mA0.c[3];
    }
    int State() { return m5B0->m1C; }
};

struct State_0028F0C8 {
    char pad0[0x184];
    float m184;
};

struct Game_0028F0C8 {
    char pad0[0xAC];
    unsigned int mAC;
};

extern int D_0039415C;
extern int D_00394160;
extern int D_00394164;
extern int D_00394168;
extern Vec_0028F0C8 D_00453000[5];
extern Game_0028F0C8* D_00392808;

extern "C" int func_0028E1C0(Skater_0028F0C8* s, unsigned short a, unsigned short b);
extern "C" int func_00209A00(Wall_0028F0C8* w);
extern "C" Body_0028F0C8* func_00209A30(Wall_0028F0C8* w);
extern "C" void func_0018DF70(void* p, Wall_0028F0C8* w);
extern "C" void func_001B6BC0(void* p, Vec_0028F0C8* v);
extern "C" void func_001B6BD0(void* p, Vec_0028F0C8* v);
extern "C" void func_00209240(Coll_0028F0C8* c);
extern "C" void func_00209350(Coll_0028F0C8* c, int a, int b);
extern "C" void func_00209360(Coll_0028F0C8* c, const Vec_0028F0C8& v);
extern "C" void func_00209370(Coll_0028F0C8* c, const Vec_0028F0C8& v);
extern "C" int func_002093E8(Coll_0028F0C8* c, int a, int b);
extern "C" void func_0027C720(Skater_0028F0C8* s, int v);
extern "C" void func_001848F0(Body_0028F0C8* b, unsigned int name, int v);

struct Obj_0028F0C8 {
    char pad0[0xC];
    Body_0028F0C8* mC;
    char pad10[0x1C - 0x10];
    int m1C;
    int m20;
    Skater_0028F0C8* m24;
    void* m28;
    void* m2C;
    Rec_0028F0C8* m30;
    State_0028F0C8* m34;
    void Update();
};

void Obj_0028F0C8::Update()
{
    m20 = 0;
    bool moved = !m24->AtPos(mC->m50);
    if (!moved)
        return;
    m24->m270 = mC->m50;
    m24->m280 = mC->m50;
    Body_0028F0C8* b = mC;
    Skater_0028F0C8* sk = m24;
    sk->m270 += b->m80 * 0.001f;
    m24->m270[1] += 8.0f;
    m24->m280[1] -= 4800.0f;
    if (func_0028E1C0(m24, 0x10, 0)) {
        Sub_0028F0C8* sb = m24->m5B0;
        if (!sb->mC4 && !sb->mAC && m30->Valid()) {
            if (m24->State() == 0 || m24->State() == 1) {
                if (!func_00209A00(&m24->mB0) || func_00209A30(&m24->mB0) != m30->m1C->m0) {
                    mC->mB0 += m30->m1C->m0->mB0;
                    m30->Clear();
                }
            }
        }
        if (!D_0039415C) D_0039415C = 1;
        if (!D_00394160) D_00394160 = 1;
        if (!D_00394164) D_00394164 = 1;
        float h = mC->m50[1] - m24->m150[1];
        m34->m184 = h;
        if (h < 0.001f)
            mC->m50[1] = m24->m150[1] + 0.001f;
        if (m24->State() != 4)
            func_0018DF70(m28, &m24->mB0);
        func_001B6BC0(m2C, &m24->m150);
        func_001B6BD0(m2C, &m24->m160);
        if (D_00392808->mAC != 0xD443A2BC) {
            Coll_0028F0C8 c;
            func_00209240(&c);
            func_00209350(&c, 0x810, 0);
            func_00209360(&c, mC->m50 + Vec_0028F0C8(0.0f, 3000.0f, 0.0f, 0.0f));
            {
                Vec_0028F0C8 e = mC->m50 + mC->m80;
                func_00209370(&c, e);
            }
            if (func_002093E8(&c, 1, 0)) {
                Body_0028F0C8* bb = mC;
                Vec_0028F0C8 v = bb->m50 - c.hit;
                if (v.LengthSqr() < 36.0f) {
                    bb->m50 = c.hit;
                } else {
                    if ((bb->m50 - m24->mA0).LengthSqr() < 1.0f)
                        bb->m50 = c.hit;
                    else
                        bb->m50 = m24->mA0;
                    Body_0028F0C8* b2 = mC;
                    b2->mB0 = b2->mB0 * -0.5f;
                    if (m24->State() == 4) {
                        func_0027C720(m24, 1);
                        func_001848F0(mC, 0xAFAA46BA, 0);
                        mC->m50[1] += 2.0f;
                    }
                }
            }
        }
        m1C = 0;
        Body_0028F0C8* bd = mC;
        m24->mA0 = bd->m50;
        return;
    }
    if (!((m24->State() == 4 || m24->State() == 3) && D_00392808->mAC == 0xD443A2BC)) {
        m20 = 1;
        if (!D_00394168) {
            /* one-time init of the offset table D_00453000[5] */
            Vec_0028F0C8* p = D_00453000;
            p->Set(0.0f, 0.0f, 0.0f, 1.0f);
            p++;
            p->Set(0.1f, 0.1f, 0.1f, 1.0f);
            p++;
            p->Set(-0.2f, 0.0f, 0.0f, 1.0f);
            p++;
            p->Set(0.0f, 0.0f, -0.2f, 1.0f);
            p++;
            p->Set(0.2f, 0.0f, 0.0f, 1.0f);
            D_00394168 = 1;
        }
        if (m1C < 5)
            mC->m50 = m24->mA0 + D_00453000[m1C++];
        else
            m1C = 0;
        Body_0028F0C8* b3 = mC;
        b3->mB0 = -b3->mB0 + Vec_0028F0C8(0.101f, 0.101f, 0.1001f);
        if (m24->State() != 0 && m24->State() != 1)
            func_0027C720(m24, 1);
    }
    m34->m184 = 0.0f;
}
