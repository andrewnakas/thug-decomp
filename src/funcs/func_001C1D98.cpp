typedef int qword_001C1D98 __attribute__((mode(TI)));
union Vec_001C1D98 {
    qword_001C1D98 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C1D98;
extern "C" Coll_001C1D98* func_00209240(Coll_001C1D98* c);
extern "C" int func_002093E8(Coll_001C1D98* c, int a, int b);
struct Coll_001C1D98 {
    Vec_001C1D98 m0;
    Vec_001C1D98 m10;
    char pad20[0xA0 - 0x20];
    Vec_001C1D98 mA0;
    char padB0[0xC0 - 0xB0];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C1D98(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" double func_0033ECA8(float x);
extern "C" double func_003411E0(double x);
extern "C" double func_0033E1B8(double a, double b);
extern "C" double func_0033E4C8(double a, double b);
extern "C" float func_0033E9B8(double x);

struct Obj_001C1D98;
extern "C" float func_001C6B28(Obj_001C1D98* o);

struct Obj_001C1D98 {
    char pad0[0x30];
    Vec_001C1D98 m30;
    char pad40[0x50 - 0x40];
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C1D98 m60;
    char pad70[0xB90 - 0x70];
    float mB90;
    char padB94[0xBA0 - 0xB94];
    Vec_001C1D98 mBA0;
    float mBB0;
    void CheckLanding();
};

void Obj_001C1D98::CheckLanding()
{
    Coll_001C1D98 c;
    func_00209240(&c);
    c.m0 = m30;
    c.m0[1] += Param_001C1D98(0x9EA1974A);
    c.m10 = c.m0;
    c.m10[1] += Param_001C1D98(0x48C0AC2A);
    if (func_002093E8(&c, 0, 0)) {
        float r = Param_001C1D98(0x06EBBAB7);
        Vec_001C1D98 off;
        off[0] = m60[0] * r;
        off[1] = m60[1] * r;
        off[2] = m60[2] * r;
        off[3] = m60[3] * r;
        float y = c.m0[1];
        c.m0[0] -= off[0];
        c.m0[1] -= off[1];
        c.m0[2] -= off[2];
        c.m0[3] -= off[3];
        c.m10[0] -= off[0];
        c.m10[1] -= off[1];
        c.m10[2] -= off[2];
        c.m10[3] -= off[3];
        float h = c.mA0[1] - y;
        if (!func_002093E8(&c, 0, 0)) {
            float g = func_001C6B28(this);
            float disc = m50 * m50 - (g + g) * h;
            if (0.0f < disc) {
                float t = func_0033E9B8(
                    func_0033E4C8(func_0033E1B8(func_0033ECA8(m50), func_003411E0(func_0033ECA8(disc))),
                                  func_0033ECA8(g)));
                mBB0 = m30[1] + h;
                mB90 = (m50 + m50) / g - t;
                float s = -r / t;
                off[0] = m60[0] * s;
                off[1] = m60[1] * s;
                off[2] = m60[2] * s;
                off[3] = m60[3] * s;
                mBA0 = off;
            }
        }
    }
    Coll_001C1D98::Ref* ref = &c.mC0;
    ref->Release();
}
