struct V3_002828D8 { float x, y, z; };
struct Body_002828D8 {
    char pad[0xB0];
    V3_002828D8 mB0;
};
struct Sub_002828D8 {
    char pad[0x1C];
    int m1C;
    char pad20[0xA0 - 0x20];
    int mA0;
    char padA4[0xAC - 0xA4];
    int mAC;
};

extern "C" float func_00203D40(Body_002828D8* o, unsigned int name);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float sqrtf(float);
extern "C" long func_0033ECA8(float);
extern "C" int func_00103F28(const char* fmt, ...);
extern char D_00376B38[];
extern int D_00391A60;

static inline float Min_002828D8(float a, float b)
{
    return a < b ? a : b;
}

static inline float Speed_002828D8(Body_002828D8* b)
{
    V3_002828D8* v = &b->mB0;
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

struct Obj_002828D8 {
    char pad0[0xC];
    Body_002828D8* mC;
    char pad10[0x94 - 0x10];
    float m94;
    char pad98[0x2D0 - 0x98];
    int m2D0;
    char pad2D4[0x3B4 - 0x2D4];
    float m3B4;
    float m3B8;
    float m3BC;
    char pad3C0[0x430 - 0x3C0];
    float m430;
    char pad434[0x5B0 - 0x434];
    Sub_002828D8* m5B0;
    void Boost();
};

void Obj_002828D8::Boost()
{
    if (m2D0 && !m5B0->mAC && !m5B0->mA0) {
        float maxs = func_00203D40(mC, 0x2EACDDB3);
        float speed = Speed_002828D8(mC);
        if (speed < maxs * 1.25f) return;
        float r = speed / maxs;
        float k = func_002032A0(0xC6B38BE0, 0);
        m3B8 = 1.00000002e+20f;
        m3BC = 1.00000002e+20f;
        m430 = Min_002828D8(r, k);
    } else if (m430 == 1.0f) {
        return;
    }
    m3B4 = -1.0f;
    float x = m430 - m94 * func_002032A0(0xF9B006AA, 0);
    m430 = x;
    if (x < 1.0f) {
        m430 = 1.0f;
        m3B4 = 0.0f;
        return;
    }
    float maxs = func_00203D40(mC, 0x2EACDDB3);
    float speed = Speed_002828D8(mC);
    float lim = m430 * maxs;
    float t = speed * 1.100000024f;
    float s;
    if (m5B0->m1C != 1) {
        s = Min_002828D8(t, m3B8);
    } else {
        s = m3B8;
    }
    s = Min_002828D8(lim, s);
    if (s < maxs) {
        m3B4 = 0.0f;
        m430 = 1.0f;
        return;
    }
    m3B8 = s;
    float g = func_00203D40(mC, 0x2EACDDB3);
    int c = D_00391A60 + 1;
    m3BC = m3B8 / maxs * g;
    D_00391A60 = c;
    while (!(D_00391A60 = D_00391A60 % 10)) {
        long d = func_0033ECA8(m3B8 / maxs);
        func_00103F28(D_00376B38, d);
        D_00391A60 = D_00391A60 + 1;
    }
}
