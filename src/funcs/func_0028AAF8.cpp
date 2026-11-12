/* sym: Pos__14Graph_0028AAF8P13Node_0028AAF8 = 0x0026B1B0 */
typedef int qword __attribute__((mode(TI)));

union Vec_0028AAF8 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028AAF8() {}
    Vec_0028AAF8(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_0028AAF8(float x, float y, float z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        c[3] = 1.0f;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_0028AAF8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Vec_0028AAF8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    bool operator==(const Vec_0028AAF8& o) const
    {
        return o[0] == c[0] && o[1] == c[1] && o[2] == c[2] && o[3] == c[3];
    }
    float Length2() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    void Normalize();
    void Sub(const Vec_0028AAF8& a, const Vec_0028AAF8& b)
    {
        c[0] = a[0] - b[0];
        c[1] = a[1] - b[1];
        c[2] = a[2] - b[2];
        c[3] = a[3] - b[3];
    }
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_0028AAF8* dst, Vec_0028AAF8* src);
inline void Vec_0028AAF8::Normalize() { func_003233B8(this, this); }
inline Vec_0028AAF8 operator*(const Vec_0028AAF8& a, float k) { return Vec_0028AAF8(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0028AAF8 operator*(float k, const Vec_0028AAF8& a) { return Vec_0028AAF8(k * a[0], k * a[1], k * a[2], k * a[3]); }
inline Vec_0028AAF8 operator-(const Vec_0028AAF8& a, const Vec_0028AAF8& b)
{
    return Vec_0028AAF8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline Vec_0028AAF8 operator-(const Vec_0028AAF8& a) { return Vec_0028AAF8(-a[0], -a[1], -a[2], -a[3]); }
inline float Dot_0028AAF8(const Vec_0028AAF8& a, const Vec_0028AAF8& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
static inline float Sq_0028AAF8(float x) { return x * x; }

struct Mat_0028AAF8 {
    Vec_0028AAF8 r[4];
    const Vec_0028AAF8& operator[](int i) const { return r[i]; }
    Mat_0028AAF8& operator=(const Mat_0028AAF8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_0010A8D8(void* pool, void* p);

struct Res_0028AAF8 {
    void* h;
};
struct Holder_0028AAF8 {
    char pad[0x1C];
    Res_0028AAF8* m1C;
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
};

struct Body_0028AAF8 {
    char pad0[0x14];
    void* m14;
    char pad18[0x50 - 0x18];
    Vec_0028AAF8 m50;
    Vec_0028AAF8 m60;
    Mat_0028AAF8 m70;
    Vec_0028AAF8 mB0;
};
struct Wall_0028AAF8 {
    char pad0[0xA0];
    Vec_0028AAF8 hit;
    Vec_0028AAF8 normal;
    char padC0[0xE0 - 0xC0];
};
struct State_0028AAF8 {
    int pad;
    int state;
    unsigned int time;
};
static inline void Set_0028AAF8(State_0028AAF8* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Sub_0028AAF8 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x34 - 0x20];
    int m34;
    char pad38[0x3C - 0x38];
    State_0028AAF8 m3C;
    State_0028AAF8 m48;
    State_0028AAF8 m54;
    State_0028AAF8 m60;
    State_0028AAF8 m6C;
    char pad78[0xA8 - 0x78];
    State_0028AAF8 mA8;
    State_0028AAF8 mB4;
    char padC0[0xF0 - 0xC0];
    State_0028AAF8 mF0;
    State_0028AAF8 mFC;
    char pad108[0x138 - 0x108];
    int m138;
    int m13C;
};

/* Rail graph: nodes are 0x60 bytes, linked to the previous (+0x50) and next (+0x54) node. */
struct Node_0028AAF8 {
    char pad0[0x50];
    Node_0028AAF8* m50;
    Node_0028AAF8* m54;
    int m58;
    short m5C;
    unsigned char m5E;
    char pad5F[0x60 - 0x5F];
};
struct Graph_0028AAF8 {
    char pad0[0x50];
    Node_0028AAF8* m50;
    char pad54[0x58 - 0x54];
    void* m58;
    Vec_0028AAF8 Pos(Node_0028AAF8* n);
};
struct Pad_0028AAF8 {
    char pad0[0x8];
    int m8;
    char padC[0x2C - 0xC];
    int m2C;
    char pad30[0x50 - 0x30];
    int m50;
    char pad54[0x74 - 0x54];
    int m74;
};
struct Input_0028AAF8 {
    char pad0[0x24];
    Pad_0028AAF8 pad;
};
struct Hud_0028AAF8 {
    char pad0[0x1C];
    void* m1C;
};
struct Snd_0028AAF8 {
    char pad0[0x20];
    int m20;
};
struct Sys_0028AAF8 {
    char pad0[0xA68];
    int mA68;
};
struct Clock_0028AAF8 {
    char pad0[0x20];
    unsigned int m20;
};

extern char D_00376B80[];
extern char D_00376B9F[];
extern char D_00376BD0[];
extern char D_00376BE8[];
extern Vec_0028AAF8 D_00452FC0;

struct Obj_0028AAF8;
extern "C" int func_00100030(int n);
extern "C" void func_00101730(Vec_0028AAF8* v, Vec_0028AAF8* n);
extern "C" Vec_0028AAF8* func_00101820(Vec_0028AAF8* a, const Vec_0028AAF8& b);
extern "C" void func_00101890(Vec_0028AAF8* v, Vec_0028AAF8* n);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_00121960(int size);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001AEEA0(Sys_0028AAF8* p, int left, int flat, int back, int mirror);
extern "C" void func_001B0EF0(void* p, int v);
extern "C" void func_001BB2E8(void* self, int kind, int sound, void* params, void* handle);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE8C8(void* p, unsigned int name, int b, void* owner);
extern "C" int func_001EFDC0(void* p);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00203D40(void* self, unsigned int name);
extern "C" void func_0023AD28(void* p, unsigned int index);
extern "C" int func_0026F8D8(int a, int b, int c, int d);
extern "C" void func_00270C98(Snd_0028AAF8* self, int a, float vol);
extern "C" void func_002710B8(void* self, int mode, int mask);
extern "C" void func_0027C720(Obj_0028AAF8* o, int a);
extern "C" void func_0027FDB0(Obj_0028AAF8* o, Vec_0028AAF8* v);
extern "C" void func_0028DF70(Obj_0028AAF8* o, int v);
extern "C" int func_0028E1C0(Obj_0028AAF8* o, unsigned short a, unsigned short b);
extern "C" void func_0028E928(Obj_0028AAF8* o, int input, int left, int flat, int back, int mirror);
extern "C" void func_00291378(void* p);
extern "C" void func_002919B0(void* p);
extern "C" double func_0033ECA8(float x);
extern "C" int func_0033EBE0(float f);
extern "C" float func_00340F60(float);
extern "C" float func_00341068(float);

struct Obj_0028AAF8 {
    char pad0[0xC];
    Body_0028AAF8* mC;
    char pad10[0x20 - 0x10];
    Mat_0028AAF8 m20;
    Vec_0028AAF8 m60;
    Vec_0028AAF8 m70;
    char pad80[0xB0 - 0x80];
    Wall_0028AAF8 mB0;
    char pad190[0x270 - 0x190];
    Vec_0028AAF8 m270;
    Vec_0028AAF8 m280;
    char pad290[0x29C - 0x290];
    Node_0028AAF8* m29C;
    Graph_0028AAF8* m2A0;
    unsigned int m2A4;
    char pad2A8[0x2AC - 0x2A8];
    int m2AC;
    int m2B0;
    char pad2B4[0x2B8 - 0x2B4];
    int m2B8;
    int m2BC;
    char pad2C0[0x2E0 - 0x2C0];
    Vec_0028AAF8 m2E0;
    char pad2F0[0x3A0 - 0x2F0];
    Vec_0028AAF8 m3A0;
    int m3B0;
    char pad3B4[0x3EC - 0x3B4];
    int m3EC;
    char pad3F0[0x594 - 0x3F0];
    Input_0028AAF8* m594;
    void* m598;
    Snd_0028AAF8* m59C;
    Sys_0028AAF8* m5A0;
    char pad5A4[0x5A8 - 0x5A4];
    Hud_0028AAF8* m5A8;
    void* m5AC;
    Sub_0028AAF8* m5B0;
    Holder_0028AAF8* m5B4;
    Clock_0028AAF8* m5B8;
    void* ResHandle() { return m5B4->Valid() ? m5B4->m1C->h : 0; }
    void SetTerrain(Node_0028AAF8* n)
    {
        int terrain = n->m5E;
        m5B0->m13C = terrain;
        m59C->m20 = terrain;
    }
    void PlayGrindSound()
    {
        float speed = sqrtf(mC->mB0.Length2());
        float vol = speed / func_00203D40(mC, 0xCC5F87AA);
        func_00270C98(m59C, m5B0->m13C, vol);
    }
    void FaceUp()
    {
        if (m5B0->m1C == 2) {
            Vec_0028AAF8 up;
            up.Set(0.0f, 1.0f, 0.0f, 1.0f);
            func_0027FDB0(this, &up);
            m20 = mC->m70;
        }
    }
    void StartGrind(Vec_0028AAF8* pos, Node_0028AAF8* node, Graph_0028AAF8* graph, int noStall, int keepSpeed);
};

void Obj_0028AAF8::StartGrind(Vec_0028AAF8* pos, Node_0028AAF8* node, Graph_0028AAF8* graph, int noStall,
                              int keepSpeed)
{
    Pad_0028AAF8* pad = &m594->pad;
    func_002919B0(func_00185578(mC, 0x488AF07A));
    if (m29C != node) {
        unsigned int index = (unsigned int)((char*)node - (char*)graph->m50) / sizeof(Node_0028AAF8);
        func_0023AD28(m5A8->m1C, index);
    }
    m2A0 = graph;
    m29C = node;

    if (!node->m54 && !node->m50) {
        /* Single-point rail: hop over it. */
        m270 = mC->m50;
        m280 = *pos;
        if (func_0028E1C0(this, 0x10, 0)) {
            Vec_0028AAF8 d = *pos - mB0.hit;
            if (d.Length2() > 36.0f)
                return;
        }
        if (fabsf(mC->mB0[0]) < 0.01f && fabsf(mC->mB0[2]) < 0.01f) {
            mC->mB0[0] = mC->m70.r[2][0];
            mC->mB0[2] = mC->m70.r[2][2];
        }
        if (!keepSpeed && Sq_0028AAF8(mC->mB0[0]) + Sq_0028AAF8(mC->mB0[2]) > 100.0f) {
            Vec_0028AAF8 up(0.0f, 1.0f, 0.0f, 1.0f);
            func_00101730(&mC->mB0, &up);
        }
        Vec_0028AAF8 dir = mC->mB0;
        dir[1] = 0.0f;
        dir.Normalize();
        float ang = func_001E5318(0xBB357ECB, 0) * 0.017453294f;
        float s = func_00340F60(ang);
        float c = func_00341068(ang);
        Vec_0028AAF8 tilt(s * dir[0], c, s * dir[2]);
        void* params = m2A0->m58;
        void* slot = func_001E9378(params, m29C->m5C);
        func_001E8398(slot, 0xA1DC81F9, &m2B0, 1);
        func_001B0EF0(m5A0, m2B0);
        int sparks = 0;
        if (func_001E8398(slot, 0x2CA8A299, &sparks, 0))
            func_001BB2E8(m598, 3, m2B0, params != func_001E55B8(0xC472ECC5, 0) ? params : 0, ResHandle());
        mC->m50 = *pos;
        Set_0028AAF8(&m5B0->m3C, 0);
        Set_0028AAF8(&m5B0->m48, 0);
        FaceUp();
        func_0027C720(this, 4);
        SetTerrain(m29C);
        PlayGrindSound();
        float vy = mC->mB0[1];
        func_00101890(&mC->mB0, &dir);
        if (keepSpeed && Dot_0028AAF8(mC->mB0, mC->m70.r[2]) < 0.0f) {
            float speed2 = mC->mB0.Length2();
            float minSpeed;
            func_001E7EB0(func_001E5548(0x6775E538, 0), 0x896C8888, &minSpeed, 1);
            if (speed2 < Sq_0028AAF8(minSpeed * 1.1f)) {
                mC->mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
                dir = mC->m70.r[2];
                dir[1] = 0.0f;
                dir.Normalize();
            }
        }
        mC->mB0[1] = vy;
        Body_0028AAF8* b = mC;
        b->mB0 += dir * func_002032A0(0xA3EF4833, 0);
        m2A4 = func_0010FC30();
        Set_0028AAF8(&m5B0->mA8, 0);
        Set_0028AAF8(&m5B0->mF0, 0);
        Set_0028AAF8(&m5B0->mB4, 0);
        Set_0028AAF8(&m5B0->mFC, 0);
        m2AC = func_0033EBE0(func_002032A0(0x2B4645AD, 0));
        Set_0028AAF8(&m5B0->m6C, 0);
        func_00101820(&mC->mB0, tilt);
        if (sparks)
            func_001BB2E8(m598, 4, m2B0, params != func_001E55B8(0xC472ECC5, 0) ? params : 0, ResHandle());
        func_0027C720(this, 1);
        mC->m50[1] += 1.0f;
        func_001848F0(mC, 0xB8048F1D, 0);
        return;
    }

    float maxTilt = func_00341068(func_002032A0(0x8157C5D9, 0) * 0.017453294f);
    if (node->m58 & 1)
        maxTilt = func_00341068(func_002032A0(0xF3B6F95E, 0) * 0.017453294f);
    float maxUp = func_00341068(func_002032A0(0xE2A85FBB, 0) * 0.017453294f);
    float maxLean = func_00340F60(func_002032A0(0x61079462, 0) * 0.017453294f);
    if ((m3EC
            || (mC->mB0[1] > 0.0f && fabsf(mC->m70.r[1][1]) < maxUp && mC->m70.r[2][1] > 0.0f
                && fabsf(m70[1]) < maxLean && fabsf(mC->m70.r[0][1]) < maxTilt))
        && !noStall) {
        /* Rail stall: stop on the rail facing along the board. */
        mC->mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
        Set_0028AAF8(&m5B0->m3C, 0);
        Set_0028AAF8(&m5B0->m48, 0);
        Set_0028AAF8(&m5B0->m54, 0);
        Set_0028AAF8(&m5B0->m60, 0);
        func_00291378(m5AC);
        m2E0 = mC->m50;
        func_0027C720(this, 3);
        mC->m50 = *pos;
        Vec_0028AAF8 fwd = m70;
        fwd[1] = 0.0f;
        fwd.Normalize();
        mC->m70.r[1] = fwd;
        mC->m70.r[2].Set(0.0f, 1.0f, 0.0f, 1.0f);
        mC->m70.r[0].Set(-mC->m70.r[1][2], 0.0f, mC->m70.r[1][0], 0.0f);
        m20 = mC->m70;
        func_002710B8(func_00185578(mC, 0x11B4C67F), 0, 0x100000);
        func_0028DF70(this, 7);
        m5A0->mA68 = 0;
        Body_0028AAF8* b = mC;
        if (!b->m14)
            b->m14 = func_001EE428(func_00121960(0xF4));
        func_001EE8C8(mC->m14, 0x1647CF96, 0, mC);
        func_001EFDC0(mC->m14);
        m5B0->m138 = 1;
        SetTerrain(m29C);
        return;
    }

    SetTerrain(m29C);
    Node_0028AAF8* cur = m29C;
    Node_0028AAF8* prev = cur->m50;
    Vec_0028AAF8 dir;
    {
        Vec_0028AAF8 a = m2A0->Pos(prev);
        Vec_0028AAF8 b = m2A0->Pos(cur);
        dir.Sub(a, b);
    }
    dir.Normalize();
    m270 = mC->m50;
    m280 = *pos;
    if (func_0028E1C0(this, 0x10, 0)) {
        Vec_0028AAF8 d = *pos - mB0.hit;
        if (d.Length2() > 36.0f)
            return;
    }
    if (m5B0->mF0.state) {
        func_00103F28(D_00376B80, D_00376B9F, 0x1B5C, D_00376BD0);
        func_00103F28(D_00376BE8, D_00376B9F, 0x1B5D, func_0033ECA8(D_00452FC0[0]), func_0033ECA8(D_00452FC0[1]),
                      func_0033ECA8(D_00452FC0[2]));
        mC->mB0 += D_00452FC0;
    }
    if (mC->mB0[0] == 0.0f && mC->mB0[2] == 0.0f) {
        mC->mB0[0] = mC->m70.r[2][0];
        mC->mB0[2] = mC->m70.r[2][2];
    }
    if (!keepSpeed && Sq_0028AAF8(mC->mB0[0]) + Sq_0028AAF8(mC->mB0[2]) > 100.0f) {
        Vec_0028AAF8 up(0.0f, 1.0f, 0.0f);
        func_00101730(&mC->mB0, &up);
    }

    float along = Dot_0028AAF8(dir, mC->mB0);
    float sign;
    if (along == 0.0f) {
        sign = -1.0f;
        if (func_00100030(2))
            sign = 1.0f;
    } else {
        sign = 1.0f;
        if (along < 0.0f)
            sign = -1.0f;
    }
    if (sign < 0.0f) {
        if (!cur->m54) {
            Vec_0028AAF8 e = m2A0->Pos(cur);
            if (*pos == e)
                return;
        }
    } else {
        if (!prev->m50) {
            Vec_0028AAF8 e = m2A0->Pos(prev);
            if (*pos == e)
                return;
        }
    }

    func_0028DF70(this, 3);
    mC->m50 = *pos;
    Set_0028AAF8(&m5B0->m3C, 0);
    Set_0028AAF8(&m5B0->m48, 0);
    FaceUp();
    func_0027C720(this, 4);
    unsigned int last = m5B8->m20;
    if (func_0010FC30() != last)
        PlayGrindSound();
    float vy = mC->mB0[1];
    func_00101890(&mC->mB0, &dir);
    if (keepSpeed && Dot_0028AAF8(mC->mB0, mC->m70.r[2]) < 0.0f) {
        float speed2 = mC->mB0.Length2();
        float minSpeed;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x896C8888, &minSpeed, 1);
        if (speed2 < Sq_0028AAF8(minSpeed * 1.1f)) {
            mC->mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
            sign = 1.0f;
            if (Dot_0028AAF8(dir, mC->m70.r[2]) < 0.0f)
                sign = -1.0f;
        }
    }
    mC->mB0[1] = vy;

    int left = 0;
    int flat = 0;
    {
        Vec_0028AAF8* vel = &mC->mB0;
        *vel += dir * sign * func_002032A0(0x457BB395, 0);
    }
    m3B0 = 0;
    if (sign < 0.0f)
        dir = -dir;
    if (dir[0] * ((*pos)[2] - m3A0[2]) + dir[2] * -((*pos)[0] - m3A0[0]) < 0.0f)
        left = 1;

    m270.Set(0.0f, func_002032A0(0xE4D79235, 0), 0.0f, 0.0f);
    m280.Set(0.0f, -func_002032A0(0x9CD7ED5C, 0), 0.0f, 0.0f);
    m270 += *pos;
    m280 += *pos;
    Vec_0028AAF8 side(dir[2], 0.0f, -dir[0], 0.0f);
    side *= func_002032A0(0x31669752, 0);
    m270 += side;
    m280 += side;
    int hitA = func_0028E1C0(this, 0x10, 0);
    m270 -= 2.0f * side;
    m280 -= 2.0f * side;
    int hitB = func_0028E1C0(this, 0x10, 0);
    m2BC = (hitA && !left) || (hitB && left);
    m2B8 = hitA || hitB;

    float across = Dot_0028AAF8(dir, mC->m70.r[0]);
    float ahead = Dot_0028AAF8(dir, mC->m70.r[2]);
    if (fabsf(across) < func_002032A0(0xD0688D4E, 0)) {
        flat = 1;
        if (ahead < 0.0f)
            m3B0 = 1;
    } else {
        if (m5B0->m34)
            across = -across;
        if (across < 0.0f)
            m3B0 = 1;
    }
    m5A0->mA68 = 0;
    if (!func_001AEEA0(m5A0, left, flat, m3B0, m5B0->m34))
        func_0028E928(this, func_0026F8D8(pad->m8, pad->m2C, pad->m50, pad->m74), left, flat, m3B0, m5B0->m34);
    m2A4 = func_0010FC30();
}
