typedef int qword __attribute__((mode(TI)));

struct Vec_001C2F10 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
    Vec_001C2F10() {}
    Vec_001C2F10(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_001C2F10& operator=(const Vec_001C2F10& o)
    {
        q = o.q;
        return *this;
    }
    Vec_001C2F10 operator*(float s) const { return Vec_001C2F10(x * s, y * s, z * s, w * s); }
    Vec_001C2F10& operator-=(const Vec_001C2F10& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

struct Order_001C2F10 {
    int v[7];
};

struct Entry_001C2F10 {
    int m_active;
    char pad4[0x10 - 4];
    Vec_001C2F10 m_normal;
    char pad20[0x30 - 0x20];
    char m_sub[0xA4 - 0x30];
    int m_A4;
    char padA8[0x110 - 0xA8];
};

struct Data_001C2F10 {
    char pad[0x184];
    float m184;
};

struct Info_001C2F10 {
    char pad[0x1FC];
    char m1FC[4];
    int m200;
};

struct Time_001C2F10 {
    char pad[0x580];
    unsigned int m580;
};

struct Flag_001C2F10 {
    char pad[0x2C];
    int m2C;
};

struct Hit_001C2F10 {
    char pad[0xB0];
    Vec_001C2F10 mB0;
};

extern Order_001C2F10 D_003634D0;
extern "C" unsigned int func_0010FC30();
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_001B0EF0(void* a, int b);
extern "C" void func_001C1D98(void* p);
extern "C" void func_001BB080(void* a, int b, void* c);
extern "C" float func_001E5318(unsigned int key, int def);
extern "C" void* func_001E5548(unsigned int key, int def);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int f);
extern "C" int func_00209A00(void* p);
extern "C" Hit_001C2F10* func_00209A30(void* p);
extern "C" unsigned int func_0026FDA0(void* p);

static inline float Dot_001C2F10(const Vec_001C2F10& a, const Vec_001C2F10& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float Param_001C2F10(unsigned int key)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &v, 1);
    return v;
}

struct Sk_001C2F10 {
    char pad0[0xC];
    void* mC;
    char pad10[0x20 - 0x10];
    unsigned int m20;
    char pad24[0x40 - 0x24];
    Vec_001C2F10 m40;
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C2F10 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0xA0 - 0x94];
    Vec_001C2F10 mA0;
    float mB0;
    char padB4[0xD0 - 0xB4];
    Entry_001C2F10 m_ent[7];
    char pad840[0xA28 - 0x840];
    Info_001C2F10* mA28;
    char padA2C[0xA34 - 0xA2C];
    void* mA34;
    Flag_001C2F10* mA38;
    char padA3C[0xA40 - 0xA3C];
    Data_001C2F10* mA40;
    Time_001C2F10* mA44;
    char padA48[0xB70 - 0xA48];
    Vec_001C2F10 mB70;
    void Bounce();
    const Vec_001C2F10& GetNormal(int i) const { return m_ent[i].m_normal; }
};

void Sk_001C2F10::Bounce()
{
    if (!mA28->m200) return;
    if (m50 > 0.0f) return;
    Data_001C2F10* d = mA40;
    if (d->m184 < func_001E5318(0xD5349CC6, 0)) return;
    unsigned int start = mA44->m580;
    float dt = func_0010FC30() - start;
    if (dt < func_001E5318(0x82135DD7, 0)) return;
    start = m20;
    dt = func_0010FC30() - start;
    if (dt < func_001E5318(0x4C2B6DF3, 0)) return;
    Order_001C2F10 order = D_003634D0;
    int i;
    int idx;
    for (i = 0; i < 7; i++) {
        idx = order.v[i];
        if (m_ent[idx].m_active) break;
    }
    if (i == 7) return;
    Vec_001C2F10 v;
    if (mB0 == 0.0f)
        v = mB70;
    else
        v = mA0;
    float dot = Dot_001C2F10(v, m_ent[idx].m_normal);
    if (dot < 0.0f) {
        v -= m_ent[idx].m_normal * (dot + dot);
    }
    float a = Param_001C2F10(0x420D18BC);
    float b = Param_001C2F10(0x246D0BF3);
    unsigned int c = func_0026FDA0(mA28->m1FC);
    float t = c / Param_001C2F10(0x12333EBD);
    float r;
    if (t > 1.0f)
        r = 1.0f;
    else
        r = t;
    m50 = a * (b + (1.0f - b) * r);
    float s = Param_001C2F10(0x99510695);
    mB70 = m60;
    m40 = v * s;
    void* sub = m_ent[idx].m_sub;
    if (func_00209A00(sub)) {
        Vec_001C2F10 h = func_00209A30(sub)->mB0;
        m50 += h.y;
        m40.x += h.x;
        m40.z += h.z;
    }
    func_001C1D98(this);
    func_001BB080(mA34, 2, sub);
    if (!mA38->m2C) {
        func_001B0EF0(func_00185578(mC, 0x270F56E1), (m_ent + idx)->m_A4);
        mA44->m580 = func_0010FC30();
        m90 = 0xCF74F6B7;
    }
}
