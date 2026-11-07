typedef int qword __attribute__((mode(TI)));
union Vec_001C3870 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001C3870() {}
    Vec_001C3870(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    Vec_001C3870(float x, float y, float z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        c[3] = 1.0f;
    }
};
inline Vec_001C3870 operator*(const Vec_001C3870& a, float k) { return Vec_001C3870(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C3870 operator+(const Vec_001C3870& a, const Vec_001C3870& b)
{
    return Vec_001C3870(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001C3870 operator-(const Vec_001C3870& a, const Vec_001C3870& b)
{
    return Vec_001C3870(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" float func_00340F60(float a);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C3870(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C3870;
extern "C" Coll_001C3870* func_00209240(Coll_001C3870* c);
extern "C" bool func_002093E8(Coll_001C3870* c, int a, int b);
struct Coll_001C3870 {
    Vec_001C3870 start;
    Vec_001C3870 end;
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
    char padC4[0xD4 - 0xC4];
    int mD4;
    char padD8[0xE0 - 0xD8];
};

struct Box_001C3870 {
    Vec_001C3870 mn;
    Vec_001C3870 mx;
};
struct Order_001C3870 {
    int k[3];
};
extern Order_001C3870 D_00363508[];

struct Sensor_001C3870 {
    char pad0[0xD0];
    int mD0;
    char padD4[0xE0 - 0xD4];
    Vec_001C3870 mE0;
    int mF0;
    char padF4[0x168 - 0xF4];
    unsigned short m168;
    char pad16A[0x110 - 0x6A];
};
struct Phys_001C3870 {
    char pad0[0xA0];
    int mA0;
};
struct Sk_001C3870 {
    char pad0[0x5B0];
    Phys_001C3870* m5B0;
};
struct Flag_001C3870 {
    char pad0[0x2C];
    int m2C;
};
struct Obj_001C3870;
extern "C" void func_00102340(Box_001C3870* box, const Vec_001C3870* a, const Vec_001C3870* b);
extern "C" int func_001DAD40();
extern "C" void func_001DA948(int h, Box_001C3870* box);
extern "C" void func_001DADB0(int h);
extern "C" Vec_001C3870 func_001C63B0(Obj_001C3870* o, int k);
extern "C" float func_001C6B28(Obj_001C3870* o);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" void func_001BF130(Obj_001C3870* o, int state);
extern "C" void func_001C4030(Obj_001C3870* o, Vec_001C3870* a, float* b);
extern "C" void func_00184920(void* obj, unsigned int name, int a, float t);
extern "C" void func_00183F88(void* obj, unsigned int name);
extern "C" float sqrtf(float);

struct Obj_001C3870 {
    char pad0[0xC];
    void* mC;
    char pad10[0x30 - 0x10];
    Vec_001C3870 m30;
    Vec_001C3870 m40;
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C3870 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0xA0 - 0x94];
    Vec_001C3870 mA0;
    char padB0[0xA34 - 0xB0];
    void* mA34;
    Flag_001C3870* mA38;
    char padA3C[0xA44 - 0xA3C];
    Sk_001C3870* mA44;
    char padA48[0xA70 - 0xA48];
    char mA70[0xB50 - 0xA70];
    int mB50;
    char padB54[0xB70 - 0xB54];
    Vec_001C3870 mB70;
    Sensor_001C3870* Sensor(int k) { return (Sensor_001C3870*)((char*)this + k * 0x110); }
    int Wallplant();
};

int Obj_001C3870::Wallplant()
{
    if (mA44->m5B0->mA0) return 0;
    Order_001C3870 order = D_00363508[0];
    int any = 0;
    float up = Param_001C3870(0xDA85F5AE);
    float reach = Param_001C3870(0x99978D2B) * 3.0f;
    float step = (up - Param_001C3870(0x6DA7F696)) * 0.11111111f;
    Coll_001C3870 c;
    func_00209240(&c);
    Box_001C3870 box;
    func_00102340(&box, &(m30 - Vec_001C3870(reach + 1.0f, 0.0f, reach + 1.0f)),
                  &(m30 + Vec_001C3870(reach + 1.0f, up + 1.0f, reach + 1.0f)));
    int h = func_001DAD40();
    func_001DA948(h, &box);
    c.mD4 = h;
    for (int i = 0; i < 3; i++) {
        int k = order.k[i];
        Sensor_001C3870* e = Sensor(k);
        if (!e->mD0 || (e->m168 & 2)) continue;
        float d = e->mE0[0] * mA0[0] + e->mE0[1] * mA0[1] + e->mE0[2] * mA0[2];
        if (-func_00340F60(Param_001C3870(0x78E6A5EC) * 0.017453294f) < d) {
            e->mF0 = 0;
            continue;
        }
        c.start = m30;
        c.start[1] += up;
        c.end = c.start + func_001C63B0(this, k) * reach;
        int r = !func_002093E8(&c, 1, 0);
        e->mF0 = r;
        if (r) any = 1;
    }
    if (!any) {
        func_001DADB0(h);
        Coll_001C3870::Ref* ref = &c.mC0;
        ref->Release();
        return 0;
    }
    float top = m30[1] + up;
    for (int i = 0; i < 3; i++) {
        int k = order.k[i];
        Sensor_001C3870* e = Sensor(k);
        if (!e->mD0 || !e->mF0) continue;
        c.start = m30;
        c.start[1] += up;
        c.end = c.start + func_001C63B0(this, k) * reach;
        int j = 8;
        while (j--) {
            c.start[1] -= step;
            c.end[1] -= step;
            if (func_002093E8(&c, 1, 0)) break;
        }
        if (c.start[1] < top) top = c.start[1];
    }
    func_001DADB0(h);
    float extra = Param_001C3870(0x72660978);
    float hgt = top + step + extra - m30[1];
    float v = sqrtf(func_001C6B28(this) * 2.0f * hgt);
    if (mB50) {
        func_001BB080(mA34, 2, mA70);
        if (mA38->m2C) {
            Coll_001C3870::Ref* ref = &c.mC0;
            ref->Release();
            return 1;
        }
    }
    m50 = v;
    func_001BF130(this, 1);
    mB70 = m60;
    func_001C4030(this, &m40, &m50);
    m90 = 0x584CF9E9;
    func_00184920(mC, 0x8687163A, 0, 0.0f);
    func_00183F88(mC, 0x6B9CA247);
    Coll_001C3870::Ref* ref = &c.mC0;
    ref->Release();
    return 1;
}
