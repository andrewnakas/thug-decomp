typedef int qword_0027F6B0 __attribute__((mode(TI)));

union Vec_0027F6B0 {
    qword_0027F6B0 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0027F6B0() {}
    Vec_0027F6B0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_0027F6B0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};

static inline Vec_0027F6B0 operator*(const Vec_0027F6B0& a, float k)
{
    return Vec_0027F6B0(a[0] * k, a[1] * k, a[2] * k, a[3] * k);
}
static inline Vec_0027F6B0 operator+(const Vec_0027F6B0& a, const Vec_0027F6B0& b)
{
    return Vec_0027F6B0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_0027F6B0 operator-(const Vec_0027F6B0& a, const Vec_0027F6B0& b)
{
    return Vec_0027F6B0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline float Dot_0027F6B0(const Vec_0027F6B0& a, const Vec_0027F6B0& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

extern "C" float sqrtf(float);
extern "C" unsigned int func_0010FC30();

/* A value plus the time it last changed. */
struct Flag_0027F6B0 {
    int m0;
    int value;
    unsigned int time;
    void Set(int v)
    {
        if (value != v) {
            value = v;
            time = func_0010FC30();
        }
    }
};

struct Phys_0027F6B0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x40 - 0x20];
    int m40;
    char pad44[0x54 - 0x44];
    Flag_0027F6B0 m54;
    Flag_0027F6B0 m60;
    char pad6C[0xD8 - 0x6C];
    Flag_0027F6B0 mD8;
    char padE4[0x13C - 0xE4];
    int m13C;
};

struct Model_0027F6B0 {
    char pad0[0x50];
    Vec_0027F6B0 pos;
    Vec_0027F6B0 oldPos;
    char pad70[0x80 - 0x70];
    Vec_0027F6B0 vel;
    Vec_0027F6B0 m90;
    char padA0[0xB0 - 0xA0];
    Vec_0027F6B0 mB0;
};

/* Rail/grind state; func_0026FDA0 / func_0026FD78 return the time since m8 / mC of the timer block. */
struct Timer_0027F6B0 {
    int m0;
    int m4;
    unsigned int m8;
    unsigned int mC;
};

struct Rail_0027F6B0 {
    char pad0[0x4];
    Timer_0027F6B0 timer;
    char pad14[0xBC - 0x14];
    int mBC;
    char padC0[0x128 - 0xC0];
    int m128;
};

struct Info_0027F6B0 {
    char pad0[0x24];
    Rail_0027F6B0 rail;
};

struct Ctrl_0027F6B0 {
    char pad0[0x20];
    int m20;
    int m24;
};

struct Pad_0027F6B0 {
    char pad0[0x1400];
    int m1400;
};

struct Hook_0027F6B0 {
    char pad0[0x2C];
    int m2C;
};

/* Collision snapshot (copied with func_0019C9D8). */
struct Snap_0027F6B0 {
    char pad0[0x6C];
    int m6C;
    int m70;
    char pad74[0xA0 - 0x74];
    Vec_0027F6B0 hit;
    Vec_0027F6B0 normal;
    char padC0[0xE0 - 0xC0];
};

struct Target_0027F6B0 {
    Vec_0027F6B0 pos;
    Vec_0027F6B0 up;
    float m20;
};

struct Skater_0027F6B0 {
    char pad0[0xC];
    Model_0027F6B0* mC;
    char pad10[0x70 - 0x10];
    Vec_0027F6B0 m70;
    char pad80[0xB0 - 0x80];
    Snap_0027F6B0 mB0;
    Snap_0027F6B0 m190;
    Vec_0027F6B0 m270;
    Vec_0027F6B0 m280;
    int m290;
    int m294;
    char pad298[0x594 - 0x298];
    Info_0027F6B0* m594;
    void* m598;
    Ctrl_0027F6B0* m59C;
    Pad_0027F6B0* m5A0;
    char pad5A4[0x5B0 - 0x5A4];
    Phys_0027F6B0* m5B0;
    char pad5B4[0x5B8 - 0x5B4];
    Hook_0027F6B0* m5B8;
    void Update();
};

extern "C" float func_002032A0(unsigned int name, int def);
extern "C" int func_00203300(unsigned int name, int def);
extern "C" float func_00340F60(float x);
extern "C" float func_003412F0(float x);
extern "C" float func_00341158(float x);
extern "C" void func_00101730(Vec_0027F6B0* v, const Vec_0027F6B0* n);
extern "C" int func_0028E1C0(Skater_0027F6B0* self, unsigned short a, unsigned short b);
extern "C" void func_0027FDB0(Skater_0027F6B0* self, Vec_0027F6B0* dir);
extern "C" void func_0027FF70(Skater_0027F6B0* self);
extern "C" void func_00280188(Skater_0027F6B0* self);
extern "C" void func_00280220(Skater_0027F6B0* self);
extern "C" void func_00280448(Skater_0027F6B0* self);
extern "C" void func_0027C720(Skater_0027F6B0* self, int state);
extern "C" void func_001BB080(void* self, int a, Snap_0027F6B0* s);
extern "C" void func_001B0EB8(Pad_0027F6B0* self, int on);
extern "C" void func_0019C9D8(Snap_0027F6B0* dst, const Snap_0027F6B0* src);
extern "C" void func_00184920(Model_0027F6B0* m, unsigned int name, int d, float f);
extern "C" void func_001848F0(Model_0027F6B0* m, unsigned int name, int b);
extern "C" int func_0026FD78(Timer_0027F6B0* timer);
extern "C" int func_0026FDA0(Timer_0027F6B0* timer);
extern "C" int func_002817F0(Skater_0027F6B0* self, int up, Vec_0027F6B0* pos, Vec_0027F6B0* from, Vec_0027F6B0* vel,
                             Target_0027F6B0* out);
extern "C" void func_002823A8(Skater_0027F6B0* self, Target_0027F6B0* t);

/* Moves the skater along the current collision contact: probes ahead, decides whether the contact
   still holds (angle and distance limits), commits the new snapshot, or falls back to state 1. */
void Skater_0027F6B0::Update()
{
    float cosAng = 0.0f;
    int ok = 0;
    Model_0027F6B0* model = mC;
    Info_0027F6B0* info = m594;
    float k = func_002032A0(0xE4D79235, 0);
    Rail_0027F6B0* rail = &info->rail;
    m270 = model->vel * k;
    m280 = mC->vel * -200.0f;
    m270 += mC->pos;
    m280 += mC->pos;
    if (func_0028E1C0(this, 0x10, 0)) {
        Model_0027F6B0* body = mC;
        Vec_0027F6B0 d = body->pos - mB0.hit;
        float dist = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        float along = Dot_0027F6B0(body->vel, d);
        if (!m290) {
            if (along < 0.001f) {
                Vec_0027F6B0 n = mB0.hit + mB0.normal;
                body->pos = n;
            }
        } else {
            ok = 1;
            Vec_0027F6B0 n = mB0.normal;
            Vec_0027F6B0 a = body->m90;
            float facing = Dot_0027F6B0(a, n);
            Vec_0027F6B0 b = a;
            func_00101730(&a, &n);
            func_00101730(&b, &m70);
            cosAng = Dot_0027F6B0(a, b);
            float limit;
            if (!info->rail.timer.m4)
                limit = func_00340F60(func_002032A0(0xEF161C2A, 0) * 0.01745329425f);
            else
                limit = func_00340F60(func_002032A0(0x4138283E, 0) * 0.01745329425f);
            if (0.0f < facing && 0.0f < cosAng && cosAng < limit) {
                ok = 0;
            } else {
                if (0.0f < along) {
                    float ang = func_003412F0(cosAng);
                    Vec_0027F6B0 e = mC->pos - mC->oldPos;
                    float len = sqrtf(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
                    float step = len * func_00341158(ang);
                    float minStep = func_002032A0(0x899BA3D0, 0);
                    if (step < minStep)
                        step = minStep;
                    if (step < dist)
                        ok = 0;
                }
                if (ok) {
                    m5B0->m54.Set(m294);
                    Vec_0027F6B0 e = n;
                    func_0027FDB0(this, &e);
                }
            }
        }
        if (!ok)
            goto fail;
        mC->pos = mB0.hit;
        if (!m5B0->m1C) {
            if (2.0f < sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]) && 0.99f < cosAng)
                m5B0->mD8.Set(1);
        }
        Snap_0027F6B0* cur = &mB0;
        int id = cur->m6C;
        Snap_0027F6B0* prev = &m190;
        m5B0->m13C = id;
        m59C->m20 = id;

        func_0027FF70(this);
        func_00280188(this);
        if (prev->m70 != cur->m70) {
            func_001BB080(m598, 4, prev);
            if (m5B8->m2C)
                return;
            func_001BB080(m598, 5, cur);
            if (m5B8->m2C)
                return;
        }
        if (!m5A0->m1400)
            func_001B0EB8(m5A0, 0);
        func_0019C9D8(prev, cur);
        m59C->m24 = prev->m6C;
    }
    if (ok)
        return;
fail:
    func_0027C720(this, 1);
    func_00184920(mC, 0xD96F01F1, 0, 0.0f);
    func_001848F0(mC, 0x3B1001B6, 0);
    func_00280220(this);
    if (m5B0->m40) {
        m5B0->m60.Set(1);
        if (!rail->mBC && !rail->m128)
            func_00280448(this);
        if (func_0026FD78(&rail->timer) > func_00203300(0x6BB5B751, 0) &&
            func_0026FDA0(&rail->timer) > func_00203300(0x6BB5B751, 0))
            m5B0->m60.Set(0);
    } else if (rail->mBC || rail->m128) {
        Target_0027F6B0 t;
        Model_0027F6B0* m = mC;
        if (func_002817F0(this, 1, &m->pos, &m->oldPos, &m->mB0, &t))
            func_002823A8(this, &t);
    }
    func_001BB080(m598, 1, &m190);
}
