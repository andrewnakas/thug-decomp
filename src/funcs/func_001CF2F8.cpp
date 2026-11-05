struct Wheel_001CF2F8 {
    int m0;
    int m4;
    char pad8[0xA8];
    float mB0;
    char padB4[0x40];
    float mF4;
    char padF8[0x128];
};

struct Phys_001CF2F8 {
    Wheel_001CF2F8 w[4];
};

struct Car_001CF2F8 {
    char pad0[0x318];
    Phys_001CF2F8* m318;
    char pad31C[0x38];
    int m354;
    int m358;
};

struct Model_001CF2F8 {
    char pad0[0x50];
    float m50[4];
};

struct Snd_001CF2F8 {
    char pad0[0x20];
};

struct Obj_001CF2F8 {
    char pad0[0xC];
    Model_001CF2F8* mC;
    char pad10[0x18];
    int m28;
    char pad2C[0x8];
    int m34;
    char pad38[0x78];
    float mB0;
    char padB4[0x4];
    Car_001CF2F8* mB8;
    void Update();
};

extern int D_0038E0A0;
extern "C" float func_001CF8E0(Obj_001CF2F8* o, unsigned int id);
extern "C" float func_0010FAB8();
extern "C" float func_001CF8B8(Obj_001CF2F8* o, unsigned int id);
extern "C" void func_001DC540(Snd_001CF2F8* s);
extern "C" void func_001DC578(Snd_001CF2F8* s, int f);
extern "C" float func_001DD758(int m, int id);
extern "C" void func_001DDB00(int m, Snd_001CF2F8* s, float* pos, int a, int b, int c, float v);
extern "C" void func_001DC5A8(Snd_001CF2F8* s, float v);
extern "C" int func_001DC658(Snd_001CF2F8* s);
extern "C" int func_001DD290(int m, int id, Snd_001CF2F8* s, int a, int b, int c, float v);
extern "C" void func_001DD7C8(int m, int h, Snd_001CF2F8* s, float v);
extern "C" void func_001DD448(int m, int h);

static inline float Max(float a, float b) { return a > b ? a : b; }
static inline float Clamp(float v, float lo, float hi)
{
    if (v > hi) v = hi;
    if (v < lo) return lo;
    return v;
}

void Obj_001CF2F8::Update()
{
    float target = 0.0f;
    Car_001CF2F8* car = mB8;
    Phys_001CF2F8* ph = car->m318;
    if (car->m354 || car->m358) {
        Wheel_001CF2F8* w = &ph->w[3];
        for (int i = 3; i != -1; i--) {
            int st = w->m4;
            if ((unsigned int)(st - 4) < 2 ||
                ((unsigned int)(st - 6) < 2 && w->mB0 > w->mF4)) {
                target = Max(target, w->mB0);
            }
            w--;
        }
    }
    float rate = func_001CF8E0(this, 0x95FBE774) * func_0010FAB8();
    mB0 = mB0 + (target - mB0) * rate;
    float t = Clamp(mB0 / func_001CF8B8(this, 0x28F1AAD0), 0.0f, 1.0f);
    Snd_001CF2F8 s;
    func_001DC540(&s);
    int mgr = D_0038E0A0;
    float* pos = mC->m50;
    func_001DDB00(mgr, &s, pos, 0, 0, 0, func_001DD758(mgr, m34));
    float lo = func_001CF8B8(this, 0x43E6CDF2);
    func_001DC5A8(&s, lo + (func_001CF8B8(this, 0x42EA5746) - lo) * t);
    float vlo = func_001CF8B8(this, 0x76F8F76E);
    float vol = vlo + (func_001CF8B8(this, 0xE68BE784) - vlo) * t;
    if (!func_001DC658(&s)) {
        if (!m28) m28 = func_001DD290(D_0038E0A0, m34, &s, 0, 0, 0, vol);
        else func_001DD7C8(D_0038E0A0, m28, &s, vol);
    } else if (m28) {
        func_001DD448(D_0038E0A0, m28);
        m28 = 0;
    }
    func_001DC578(&s, 2);
}
