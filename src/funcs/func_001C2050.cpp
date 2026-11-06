typedef int qword __attribute__((mode(TI)));
union Vec_001C2050 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001C2050() {}
    Vec_001C2050(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_001C2050& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
inline Vec_001C2050 operator*(const Vec_001C2050& a, float k) { return Vec_001C2050(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C2050 operator+(const Vec_001C2050& a, const Vec_001C2050& b)
{
    return Vec_001C2050(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001C2050 operator-(const Vec_001C2050& a, const Vec_001C2050& b)
{
    return Vec_001C2050(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" unsigned int func_0010FC30();
static inline unsigned int Since_001C2050(unsigned int t) { return func_0010FC30() - t; }

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C2050(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

struct Sub_001C2050 {
    char pad0[0x104];
    int m104;
    char pad108[0x1B8 - 0x108];
    int m1B8;
};
struct Sk_001C2050 {
    char pad0[0x24];
    Sub_001C2050 m24;
};
struct Flag_001C2050 {
    char pad0[0x2C];
    int m2C;
};
struct Obj_001C2050;
extern int D_0038EE60;
extern char D_00363408[];
extern char D_00363427[];
extern char D_003634A8[];
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_001C5330(Obj_001C2050* o);
extern "C" void func_001C2500(Obj_001C2050* o);
extern "C" int func_001C0030(Obj_001C2050* o);
extern "C" void func_001C59B0(Obj_001C2050* o);
extern "C" void func_001C2870(Obj_001C2050* o);
extern "C" float func_001C6B28(Obj_001C2050* o);
extern "C" void func_001C2AB0(Obj_001C2050* o, Vec_001C2050* a, Vec_001C2050* b);
extern "C" int func_001C79C8(Obj_001C2050* o, Vec_001C2050* a, Vec_001C2050* b);
extern "C" int func_001CBB88(Obj_001C2050* o, Vec_001C2050* a, Vec_001C2050* b);
extern "C" int func_001C4780(Obj_001C2050* o);
extern "C" int func_001C3E68(Obj_001C2050* o);
extern "C" void func_001C2F10(Obj_001C2050* o);
extern "C" int func_001CE918(void* r, Vec_001C2050* a, Vec_001C2050* b);

struct Obj_001C2050 {
    char pad0[0x1C];
    int m1C;
    unsigned int m20;
    int m24;
    char pad28[0x30 - 0x28];
    Vec_001C2050 m30;
    Vec_001C2050 m40;
    float m50;
    char pad54[0x80 - 0x54];
    Vec_001C2050 m80;
    unsigned int m90;
    char pad94[0x98 - 0x94];
    float m98;
    char pad9C[0xBC - 0x9C];
    int mBC;
    char padC0[0x970 - 0xC0];
    Vec_001C2050 m970;
    char pad980[0xA28 - 0x980];
    Sk_001C2050* mA28;
    char padA2C[0xA38 - 0xA2C];
    Flag_001C2050* mA38;
    void* mA3C;
    char padA40[0xB58 - 0xA40];
    int mB58;
    char padB5C[0xBA0 - 0xB5C];
    Vec_001C2050 mBA0;
    float mBB0;
    void Air();
};

void Obj_001C2050::Air()
{
    Sk_001C2050* sk = mA28;
    func_001C5330(this);
    m90 = 0x439F4704;
    Sub_001C2050* sub = &sk->m24;
    func_001C2500(this);
    if (!func_001C0030(this)) mB58 = 0;
    if (mA38->m2C) return;
    func_001C59B0(this);
    func_001C2870(this);
    float g = -func_001C6B28(this);
    m30 += m40 * m98;
    m30 += mBA0 * m98;
    float dt = m98;
    float vy = m50;
    m50 = vy + g * dt;
    float h = dt * dt * 0.5f;
    m30[1] += vy * dt + g * h;
    if (m30[1] > mBB0) mBA0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_001C2AB0(this, &m80, &m30);
    if (m1C != 1) return;
    if (mA38->m2C) return;
    if (sk->m24.m104 && !mBC) {
        if (m24 < 2 || m24 > 4 || (float)Since_001C2050(m20) > Param_001C2050(0xE6E0C0A4)) {
            if (m24 == 3) {
                Vec_001C2050 a = m80;
                Vec_001C2050 b = m30;
                if (func_001C79C8(this, &a, &b)) {
                    D_0038EE60 = 0;
                    return;
                }
            } else {
                Vec_001C2050 a = m80;
                Vec_001C2050 b = m30;
                int ok = func_001C79C8(this, &a, &b) || func_001CBB88(this, &m80, &m30);
                if (ok) {
                    D_0038EE60 = 0;
                    return;
                }
            }
        }
    }
    D_0038EE60 = 0;
    if (sub->m1B8 && func_001C4780(this)) return;
    if (func_001C3E68(this)) return;
    func_001C2F10(this);
    if (mA38->m2C) return;
    Vec_001C2050 old = m30;
    Vec_001C2050 s = m30 + m970;
    Vec_001C2050 e = m80 + m970;
    if (func_001CE918(mA3C, &s, &e)) {
        m30 = s - m970;
        func_00103F28(D_00363408, D_00363427, 0x71F, D_003634A8);
        m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
        m50 = 0.0f;
        func_001C2AB0(this, &m30, &old);
    }
}
