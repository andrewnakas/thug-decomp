/* fuzzy: 97.6 */
extern "C" float fabsf(float);
extern "C" float func_0010FAB8();
extern "C" unsigned int func_0010FC30();

struct Gear_001CEE80 {
    float m0;
    float m4;
    float m8;
    float mC;
};

static inline float Clamp_001CEE80(float v, float lo, float hi)
{
    if (v > hi) v = hi;
    float r;
    if (v < lo)
        r = lo;
    else
        r = v;
    return r;
}
static inline float Min_001CEE80(float a, float b) { return a < b ? a : b; }
static inline unsigned int Since_001CEE80(unsigned int t) { return func_0010FC30() - t; }

struct Wheel_001CEE80 {
    char pad0[0x8];
    float m8;
    char padC[0xD4 - 0xC];
    int mD4;
    char padD8[0xE0 - 0xD8];
    float mE0;
    char padE4[0x220 - 0xE4];
};

struct Veh_001CEE80 {
    char pad0[0x120];
    int m120;
    char pad124[0x318 - 0x124];
    Wheel_001CEE80* m318;
    char pad31C[0x350 - 0x31C];
    int m350;
    int m354;
    char pad358[0x35C - 0x358];
    int m35C;
    char pad360[0x1368 - 0x360];
    float m1368;
};

struct Snd_001CEE80 {
    char pad0[0x20];
};

struct Body_001CEE80 {
    char pad0[0x50];
    char m50[0x10];
};

extern void* D_0038E0A0;
extern "C" void func_001DC540(Snd_001CEE80* s);
extern "C" void func_001DC578(Snd_001CEE80* s, int f);
extern "C" void func_001DC5A8(Snd_001CEE80* s, float v);
extern "C" float func_001DD758(void* mgr, int id);
extern "C" void func_001DDB00(void* mgr, Snd_001CEE80* s, void* pos, int a, int b, int c, float v);
extern "C" int func_001DD290(void* mgr, int id, Snd_001CEE80* s, int a, int b, int c, float v);
extern "C" void func_001DD7C8(void* mgr, int h, Snd_001CEE80* s, float v);

struct Eng_001CEE80;
extern "C" float func_001CF8E0(Eng_001CEE80* e, unsigned int name);
extern "C" float func_001CF8B8(Eng_001CEE80* e, unsigned int name);

struct Eng_001CEE80 {
    char pad0[0xC];
    Body_001CEE80* mC;
    char pad10[0x24 - 0x10];
    int m24;
    char pad28[0x30 - 0x28];
    int m30;
    char pad34[0x38 - 0x34];
    int m38;
    Gear_001CEE80 m3C[(0x9C - 0x3C) / 16];
    float m9C;
    int mA0;
    float mA4;
    unsigned int mA8;
    char padAC[0xB8 - 0xAC];
    Veh_001CEE80* mB8;
    void Update();
};

void Eng_001CEE80::Update()
{
    float dt = func_0010FAB8();
    float m = 1e20f;
    int i = 4;
    while (i--) {
        Wheel_001CEE80* w = &mB8->m318[i];
        if (w->mD4) {
            float x = fabsf(w->m8) * w->mE0;
            m = Min_001CEE80(m, x);
        }
    }
    float s = m * 0.056818183f;
    Veh_001CEE80* v = mB8;
    bool air = false;
    if (v->m350 || v->m35C) air = !v->m354;
    if (!air) s *= func_001CF8E0(this, 0xEC67BC97);
    m9C = s + (m9C - s) * (func_001CF8E0(this, 0x2A7095B) * dt);
    if (m9C < s) {
        float up = func_001CF8E0(this, 0xCA5EFD91) * dt;
        float c = m9C;
        float t = c + up;
        if (c < t) t = c;
        m9C = t;
    } else {
        float dn = func_001CF8E0(this, 0x77C8E7C8) * dt;
        float c = m9C;
        float t = c - dn;
        if (t < c) t = c;
        m9C = t;
    }
    Veh_001CEE80* vv = mB8;
    if (vv->m120) {
        int g = mA0;
        if (g < m38 - 1 && m3C[g].m0 < m9C) {
            mA0 = g + 1;
            mA8 = func_0010FC30();
        } else if (g > 0 && m9C < m3C[g].m4) {
            mA0 = g - 1;
            mA8 = func_0010FC30();
        }
    } else {
        if (func_001CF8E0(this, 0xC0F451D4) < vv->m1368) mA0 = 0;
    }
    float a = func_001CF8E0(this, 0xBFA32092);
    float el = Since_001CEE80(mA8);
    float b = a + (1.0f - a) * (el / func_001CF8E0(this, 0xFB6BD20E));
    float vol;
    if (1.0f < b)
        vol = 1.0f;
    else
        vol = b;
    const float* ga = &m3C[0].m8;
    const float* gb = &m3C[0].mC;
    int g = mA0;
    ga += g * 4;
    gb += g * 4;
    float lo = g ? m3C[g - 1].m0 : 0.0f;
    float rpm = *ga + (*gb - *ga) * ((m9C - lo) / (m3C[g].m0 - lo));
    mA4 = mA4 + (rpm - mA4) * (func_001CF8E0(this, 0x3DD9C040) * dt);
    float r0 = func_001CF8B8(this, 0x5AC84A3);
    float r1 = func_001CF8B8(this, 0x95DF9449);
    float k = Clamp_001CEE80((mA4 - r0) / (r1 - r0), 0.0f, 1.0f);
    Snd_001CEE80 snd;
    func_001DC540(&snd);
    void* mgr = D_0038E0A0;
    void* pos = mC->m50;
    func_001DDB00(mgr, &snd, pos, 0, 0, 0, func_001DD758(mgr, m30));
    float v0 = func_001CF8B8(this, 0xB8F81277);
    float v1 = func_001CF8B8(this, 0x288B029D);
    func_001DC5A8(&snd, vol * (v0 + (v1 - v0) * k));
    float p0 = func_001CF8B8(this, 0x2660AF3B);
    float p1 = func_001CF8B8(this, 0x9F46344A);
    float p = p0 + (p1 - p0) * k;
    if (!m24)
        m24 = func_001DD290(D_0038E0A0, m30, &snd, 0, 0, 0, p);
    else
        func_001DD7C8(D_0038E0A0, m24, &snd, p);
    func_001DC578(&snd, 2);
}
