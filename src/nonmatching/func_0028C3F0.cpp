/* fuzzy: 97.3 */
extern "C" float sqrtf(float);
typedef int qword __attribute__((mode(TI)));

union Vec_0028C3F0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028C3F0() {}
    Vec_0028C3F0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_0028C3F0(float x, float y, float z)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = 1.0f;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_0028C3F0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    float Length2() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    float Length() const { return sqrtf(Length2()); }
    void Normalize();
};
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_0028C3F0* dst, Vec_0028C3F0* src);
inline void Vec_0028C3F0::Normalize() { func_003233B8(this, this); }
inline Vec_0028C3F0 operator*(const Vec_0028C3F0& a, float k) { return Vec_0028C3F0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0028C3F0 operator+(const Vec_0028C3F0& a, const Vec_0028C3F0& b)
{
    return Vec_0028C3F0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_0028C3F0 operator-(const Vec_0028C3F0& a, const Vec_0028C3F0& b)
{
    return Vec_0028C3F0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_0028C3F0(const Vec_0028C3F0& a, const Vec_0028C3F0& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_0028C3F0 Cross_0028C3F0(const Vec_0028C3F0& a, const Vec_0028C3F0& b)
{
    return Vec_0028C3F0(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_0028C3F0 {
    Vec_0028C3F0 r0;
    Vec_0028C3F0 r1;
    Vec_0028C3F0 r2;
    Vec_0028C3F0 r3;
    Vec_0028C3F0& operator[](int i) { return (&r0)[i]; }
    const Vec_0028C3F0& operator[](int i) const { return (&r0)[i]; }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);

/* Pooled resource handle: position at +0x60, transform at +0x70. */
struct Res_0028C3F0 {
    void* h;
    char pad4[0x60 - 4];
    Vec_0028C3F0 m60;
    Mat_0028C3F0 m70;
    int mB0;
};
extern "C" int func_0020A760(Res_0028C3F0* r, Vec_0028C3F0* pos);
static inline void Free_0028C3F0(Res_0028C3F0* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}
struct Holder_0028C3F0 {
    char pad[0x1C];
    Res_0028C3F0* m1C;
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
        Res_0028C3F0* r = m1C;
        if (r) {
            Free_0028C3F0(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_0028C3F0* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Body_0028C3F0 {
    char pad[0x50];
    Vec_0028C3F0 m50;
    Vec_0028C3F0 m60;
    Mat_0028C3F0 m70;
    Vec_0028C3F0 mB0;
    const Vec_0028C3F0& GetPos() const { return m50; }
};
struct Wall_0028C3F0 {
    char pad0[0x68];
    unsigned short m68;
    char pad6A[0xA0 - 0x6A];
    Vec_0028C3F0 hit;
    Vec_0028C3F0 normal;
    char padC0[0xE0 - 0xC0];
};
struct State_0028C3F0 {
    int pad;
    int state;
    unsigned int time;
};
static inline void Set_0028C3F0(State_0028C3F0* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Sub_0028C3F0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x6C - 0x20];
    State_0028C3F0 m6C;
    char pad78[0xA8 - 0x78];
    State_0028C3F0 mA8;
    State_0028C3F0 mB4;
    char padC0[0xF0 - 0xC0];
    State_0028C3F0 mF0;
    State_0028C3F0 mFC;
    char pad108[0x12C - 0x108];
    State_0028C3F0 m12C;
    int m138;
    int m13C;
};

/* Rail graph node: previous/next links, sound id at +0x5C, terrain at +0x5E. */
struct Node_0028C3F0 {
    char pad0[0x50];
    Node_0028C3F0* m50;
    Node_0028C3F0* m54;
    int m58;
    short m5C;
    unsigned char m5E;
};
struct Graph_0028C3F0 {
    char pad0[0x58];
    int m58;
};
struct Mode_0028C3F0 {
    char pad0[0x1C];
    unsigned int m1C;
    char pad20[0xB0 - 0x20];
    char mB0[0xEC - 0xB0];
    int mEC;
    int mF0;
};
struct Score_0028C3F0 {
    char pad0[0x1544];
    float m1544;
};
struct Hud_0028C3F0 {
    char pad0[0x1C];
    Score_0028C3F0* m1C;
};
struct Snd_0028C3F0 {
    char pad0[0x20];
    int m20;
};
struct Game_0028C3F0 {
    char pad0[0x24];
    void* m24;
    void* Get24() { return m24; }
};
struct Prefs_0028C3F0 {
    char pad0[0xAC];
    unsigned int mAC;
};

extern Game_0028C3F0* D_0038FC78;
extern int D_00390EF8;
extern Prefs_0028C3F0* D_00392808;

struct Obj_0028C3F0;
extern "C" void func_001016A8(Vec_0028C3F0* v, Vec_0028C3F0* n);
extern "C" Vec_0028C3F0* func_00101820(Vec_0028C3F0* a, const Vec_0028C3F0& b);
extern "C" void func_00101890(Vec_0028C3F0* v, Vec_0028C3F0* n);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001B0EF0(void* p, int v);
extern "C" Mat_0028C3F0 func_001B7750(void* src);
extern "C" int func_001CB7B8(Node_0028C3F0* n, int bit);
extern "C" int func_001E53A0(unsigned int key, int a);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001E9378(void* a, int i);
extern "C" float func_002032A0(unsigned int, int);
extern "C" void func_00237A30(Score_0028C3F0* p, int v);
extern "C" void func_00260A28(void* p);
extern "C" int func_00263BD8(void*, unsigned int);
extern "C" void func_00263C18(void*, int);
extern "C" bool func_0026A968(const Vec_0028C3F0& a, const Vec_0028C3F0& b);
/* Graph point of a node (returns the vector by value through the hidden pointer). */
extern "C" Vec_0028C3F0 func_0026B1B0(Graph_0028C3F0* g, Node_0028C3F0* n);
extern "C" void func_0027C720(Obj_0028C3F0* o, int a);
extern "C" int func_00285258(Obj_0028C3F0* o);
extern "C" void func_0028D958(Obj_0028C3F0* o, const Vec_0028C3F0& in);
extern "C" void func_0028DF70(Obj_0028C3F0* o, int v);
extern "C" int func_0028E1C0(Obj_0028C3F0* o, unsigned short a, unsigned short b);
extern "C" void func_00323318(Mat_0028C3F0* d, Mat_0028C3F0* a, Mat_0028C3F0* b);
extern "C" int func_0033EBE0(float f);
extern "C" float func_00340F60(float);

/* Graph point of node n on this object's rail graph. */
#define Pos(n) func_0026B1B0(m2A0, (n))

struct Obj_0028C3F0 {
    char pad0[0xC];
    Body_0028C3F0* mC;
    char pad10[0x20 - 0x10];
    Mat_0028C3F0 m20;
    Vec_0028C3F0 m60;
    Vec_0028C3F0 m70;
    Vec_0028C3F0 m80;
    int m90;
    float m94;
    char pad98[0xB0 - 0x98];
    Wall_0028C3F0 mB0;
    char pad190[0x270 - 0x190];
    Vec_0028C3F0 m270;
    Vec_0028C3F0 m280;
    char pad290[0x29C - 0x290];
    Node_0028C3F0* m29C;
    Graph_0028C3F0* m2A0;
    unsigned int m2A4;
    char pad2A8[0x2AC - 0x2A8];
    int m2AC;
    int m2B0;
    char pad2B4[0x3B0 - 0x2B4];
    int m3B0;
    char pad3B4[0x42C - 0x3B4];
    int m42C;
    char pad430[0x59C - 0x430];
    Snd_0028C3F0* m59C;
    void* m5A0;
    char pad5A4[0x5A8 - 0x5A4];
    Hud_0028C3F0* m5A8;
    Mode_0028C3F0* m5AC;
    Sub_0028C3F0* m5B0;
    Holder_0028C3F0* m5B4;
    void Update();
};

void Obj_0028C3F0::Update()
{
    Set_0028C3F0(&m5B0->mA8, 0);
    Set_0028C3F0(&m5B0->mF0, 0);
    Set_0028C3F0(&m5B0->mB4, 0);
    Set_0028C3F0(&m5B0->mFC, 0);
    if (m5B4->Valid()) {
        func_001B7750(func_00185578(m5B4->m1C->h, 0x1CDFB2A3));
        if (m5B4->Update(&mC->m50)) {
            mC->m50 += m5B4->m1C->m60;
            if (m5B4->m1C->mB0) {
                func_00323318(&mC->m70, &m5B4->m1C->m70, &mC->m70);
                func_00323318(&m20, &m5B4->m1C->m70, &m20);
            }
        }
    }
    m2AC = func_0033EBE0(func_002032A0(0x2B4645AD, 0));
    Set_0028C3F0(&m5B0->m6C, 0);

    if (func_00285258(this)) {
        func_0028DF70(this, 2);
        m2AC = func_0033EBE0(func_002032A0(0x0BF35053, 0));
        Set_0028C3F0(&m5B0->m12C, 1);
        mC->m50[1] += 1.0f;
    } else {
        switch (m5AC->m1C) {
        case 0x255ED86F:
        case 0x8D10119D:
            func_00260A28(m5AC->mB0);
            if (func_00263BD8(D_0038FC78->Get24(), 0xCD09E062)) {
                func_00263C18(D_0038FC78->Get24(), func_001E53A0(0xCD09E062, 0));
                m5AC->mEC = 0;
                m5AC->mF0 = 0;
                D_00390EF8 = 1;
            }
            break;
        case 0xA549B57B: /* present in the game's compare tree, no action */
            break;
        default:
            break;
        }

        Node_0028C3F0* node = m29C;
        Node_0028C3F0* prev = node->m50;
        Node_0028C3F0* next = 0;

        float before = 1.0f;
        Vec_0028C3F0 dir;
        float len;
        {
            Vec_0028C3F0 a = Pos(prev);
            Vec_0028C3F0 b = Pos(node);
            float dx = a[0] - b[0];
            float dy = a[1] - b[1];
            float dz = a[2] - b[2];
            float dw = a[3] - b[3];
            len = sqrtf(dx * dx + dy * dy + dz * dz);
            float inv = 1.0f / len;
            dir.Set(dx * inv, dy * inv, dz * inv, dw * inv);
        }
        if (Dot_0028C3F0(dir, mC->mB0) < 0.0f)
            before = -1.0f;
        float after = 1.0f;
        Vec_0028C3F0 g(0.0f, func_002032A0(0xD1F46992, 0), 0.0f, 1.0f);
        func_00101890(&g, &dir);
        mC->mB0 += g * m94;
        if (Dot_0028C3F0(dir, mC->mB0) < 0.0f)
            after = -1.0f;
        if (after != before)
            m3B0 ^= 1;

        bool blocked = false;
        if (after < 0.0f) {
            if (node->m54 && func_001CB7B8(node->m54, 2)) {
                Vec_0028C3F0 u;
                Vec_0028C3F0 v;
                u = Pos(prev) - Pos(node);
                v = Pos(node) - Pos(node->m54);
                u[1] = 0.0f;
                v[1] = 0.0f;
                u.Normalize();
                v.Normalize();
                if (Dot_0028C3F0(u, v) < func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f))
                    blocked = true;
                else
                    next = node->m54;
            } else {
                blocked = true;
            }
        } else {
            if (prev && prev->m50 && func_001CB7B8(prev->m50, 2)) {
                Vec_0028C3F0 u;
                Vec_0028C3F0 v;
                u = Pos(node) - Pos(prev);
                v = Pos(prev) - Pos(prev->m50);
                u[1] = 0.0f;
                v[1] = 0.0f;
                u.Normalize();
                v.Normalize();
                if (Dot_0028C3F0(u, v) < func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f))
                    blocked = true;
                else
                    next = prev;
            } else {
                blocked = true;
            }
        }

        float over = 0.0f;
        float dist;
        if (after < 0.0f)
            dist = (mC->GetPos() - Pos(prev)).Length();
        else
            dist = (mC->GetPos() - Pos(node)).Length();
        if (len + 0.1f < dist) {
            over = dist - len;
            if (after < 0.0f) {
                if (node->m54 && func_001CB7B8(node->m54, 2)) {
                    bool clear = func_0026A968(Pos(node), Pos(node->m54));
                    if (clear && !blocked) {
                        mC->m50 = Pos(node);
                        m29C = node->m54;
                        int terrain = m29C->m5E;
                        m5B0->m13C = terrain;
                        m59C->m20 = terrain;
                        func_0028DF70(this, 5);
                    } else {
                        func_0028D958(this, Pos(node));
                    }
                } else {
                    func_0028D958(this, Pos(node));
                }
            } else {
                if (prev->m50 && func_001CB7B8(prev, 2)) {
                    bool clear = func_0026A968(Pos(prev), Pos(prev->m50));
                    if (clear && !blocked) {
                        mC->m50 = Pos(prev);
                        m29C = prev;
                        int terrain = prev->m5E;
                        m5B0->m13C = terrain;
                        m59C->m20 = terrain;
                        func_0028DF70(this, 5);
                    } else {
                        func_0028D958(this, Pos(prev));
                    }
                } else {
                    func_0028D958(this, Pos(prev));
                }
            }
        }
        if (m5B0->m1C == 4) {
            Node_0028C3F0* cur = m29C;
            Vec_0028C3F0 t = Pos(cur->m50) - Pos(cur);
            t.Normalize();
            float sign = 1.0f;
            if (Dot_0028C3F0(t, mC->mB0) < 0.0f)
                sign = -1.0f;
            m2A4 = func_0010FC30();
            func_00101820(&mC->mB0, t);
            mC->mB0 *= sign;
            float k = sign;
            if (m3B0)
                k = -k;
            Vec_0028C3F0 face = t * k;

            m20[2] = m20[2] + (face - m20[2]) * 0.3f;
            m20[2].Normalize();
            m20[0].Set(m20[2][2], 0.0f, -m20[2][0], 0.0f);
            m20[0].Normalize();
            m20[1] = Cross_0028C3F0(m20[2], m20[0]);
            m20[1].Normalize();

            mC->m70[2] = face;
            mC->m70[2].Normalize();
            mC->m70[0].Set(mC->m70[2][2], 0.0f, -mC->m70[2][0], 0.0f);
            mC->m70[0].Normalize();
            mC->m70[1] = Cross_0028C3F0(mC->m70[2], mC->m70[0]);
            mC->m70[1].Normalize();

            Vec_0028C3F0 lift(0.0f, 0.0f, 0.0f);
            Vec_0028C3F0 old = mC->m50;
            mC->m50 += mC->mB0 * m94;
            mC->m50 += face * over;
            mC->m50 += lift;
            Vec_0028C3F0 step = mC->m50 - old;
            Vec_0028C3F0 heading = step;
            heading.Normalize();

            bool level = false;
            if (!blocked && D_00392808->mAC != 0xD443A2BC) {
                Vec_0028C3F0 u = Pos(node->m50) - Pos(node);
                Vec_0028C3F0 w = Pos(next->m50) - Pos(next);
                u.Normalize();
                w.Normalize();
                if (fabsf(u[1] - w[1]) < 0.01f)
                    level = true;
            }
            if (blocked || level) {
                m270 = old;
                m280 = mC->m50;
                m280 += step + heading * 6.0f;
                m270 += mC->m70.r1;
                m280 += mC->m70.r1;
                if (func_0028E1C0(this, 0x10, 0)
                    && (D_00392808->mAC == 0xD443A2BC || !(mB0.m68 & 0x1000))) {
                    func_0028DF70(this, 4);
                    mC->m50 = mC->m60;
                    mC->m50[1] += 1.0f;
                    func_001016A8(&mC->mB0, &mB0.normal);
                    func_0027C720(this, 1);
                    func_001848F0(mC, 0xAFAA46BA, 0);
                }
            }
        }
    }

    m70 = mC->m70.r1;
    func_00237A30(m5A8->m1C, (int)((float)m42C * m5A8->m1C->m1544));
    Node_0028C3F0* cur = m29C;
    if (m2A0->m58) {
        func_001E8A30(func_001E9378(func_001E55B8(0xC472ECC5, 0), cur->m5C), 0xA1DC81F9, &m2B0, 1);
        func_001B0EF0(m5A0, m2B0);
    }
}
