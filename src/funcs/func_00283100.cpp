typedef int qword __attribute__((mode(TI)));
union Vec_00283100 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00283100() {}
    Vec_00283100(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Scale3(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
    }
    void operator-=(const Vec_00283100& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

inline Vec_00283100 operator*(const Vec_00283100& a, float k) { return Vec_00283100(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00283100 operator+(const Vec_00283100& a, const Vec_00283100& b)
{
    return Vec_00283100(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00283100 operator-(const Vec_00283100& a, const Vec_00283100& b)
{
    return Vec_00283100(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_00283100;
extern "C" Coll_00283100* func_00209280(Coll_00283100* c, const Vec_00283100& s, const Vec_00283100& e);
struct Coll_00283100 {
    Vec_00283100 start;
    Vec_00283100 end;
    char pad20[0xC0 - 0x20];
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

struct Body_00283100 {
    char pad0[0x50];
    Vec_00283100 m50;
    char pad60[0x70 - 0x60];
    Vec_00283100 m70;
    Vec_00283100 m80;
};
struct Info_00283100 {
    char pad0[0x1C];
    int m1C;
};
struct Ctl_00283100 {
    char pad0[0x74];
    int m74;
    char pad78[0x98 - 0x78];
    int m98;
    char pad9C[0xBC - 0x9C];
    int mBC;
    char padC0[0x128 - 0xC0];
    int m128;
};
struct Sk_00283100 {
    char pad0[0x2C];
    int m2C;
};
struct Obj_00283100;
extern "C" float func_002032A0(unsigned int, int);
extern "C" int func_0028E1C0(Obj_00283100* o, unsigned short a, unsigned short b);
extern "C" int func_002843F0(Obj_00283100* o);
extern "C" float func_00284AA8(Obj_00283100* o, Vec_00283100* dir, float k, float* out);
extern "C" int func_002093E8(Coll_00283100* c, int a, int b);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" float sqrtf(float);

struct Obj_00283100 {
    char pad0[0xC];
    Body_00283100* mC;
    char pad10[0xA0 - 0x10];
    Vec_00283100 mA0;
    char padB0[0xB0 - 0xB0];
    Vec_00283100 mB0;
    char padC0[0x150 - 0xC0];
    Vec_00283100 m150;
    Vec_00283100 m160;
    char pad170[0x270 - 0x170];
    Vec_00283100 m270;
    Vec_00283100 m280;
    char pad290[0x594 - 0x290];
    Ctl_00283100* m594;
    void* m598;
    char pad59C[0x5B0 - 0x59C];
    Info_00283100* m5B0;
    char pad5B4[0x5B8 - 0x5B4];
    Sk_00283100* m5B8;
    bool Check(float a, float b);
};

bool Obj_00283100::Check(float a, float b)
{
    if (m5B0->m1C == 2) return false;
    Body_00283100* bd = mC;
    m270 = bd->m50 + bd->m80 * func_002032A0(0xB45B39E2, 0);
    float c = b;
    if (m5B0->m1C == 1) c = b + func_002032A0(0x1C58C8B4, 0);
    m280 = m270 + mC->m70 * a * c;
    if (!func_0028E1C0(this, 0x10, 0)) return false;
    Vec_00283100 n = m160;
    int st = m5B0->m1C;
    Vec_00283100* pb = &mB0;
    if (st == 1) {
        if (func_002843F0(this)) return true;
        float d = c - b;
        Vec_00283100 t = m150;
        t -= m270;
        float len = sqrtf(t[0] * t[0] + t[1] * t[1] + t[2] * t[2]);
        float e = len - d;
        if (0.0f < e) {
            if (0.0f < len)
                t.Scale3(e / len);
            mC->m50 -= t * 0.1f;
            Ctl_00283100* ct = m594;
            if (m5B0->m1C != st) {
                if (ct->m128) return false;
                if (ct->mBC) return false;
                if (ct->m74) return false;
                if (ct->m98) return false;
                float out;
                func_00284AA8(this, &n, 0.2f, &out);
            }
        }
        return false;
    }
    Body_00283100* b1 = mC;
    float dot = n[0] * b1->m80[0] + n[1] * b1->m80[1] + n[2] * b1->m80[2];
    if (dot < 0.25f) {
        if (-0.25f < dot) {
            b1->m50 = mA0;
            float out2;
            func_00284AA8(this, &n, 0.2f, &out2);
            Coll_00283100 cl;
            Coll_00283100* pc = &cl;
            func_00209280(pc, m150 + n, m150 + n * b);
            if (!func_002093E8(pc, 1, 0)) {
                func_001BB080(m598, 6, pb);
                if (!m5B8->m2C) {
                    Body_00283100* b2 = mC;
                    b2->m50 = pc->end - b2->m80 * func_002032A0(0xB45B39E2, 0);
                    pc->mC0.Release();
                    return true;
                }
            }
            Coll_00283100::Ref* r = &cl.mC0;
            r->Release();
        }
    }
    return false;
}
