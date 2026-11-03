typedef int qword __attribute__((mode(TI)));
union Vec_00284D00 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct V3_00284D00 { float x, y, z; };

struct Body_00284D00 {
    char pad[0x50];
    Vec_00284D00 m50;
    char pad60[0x70 - 0x60];
    Vec_00284D00 m70;
    Vec_00284D00 m80;
    char pad90[0xB0 - 0x90];
    V3_00284D00 mB0;
};
struct Tm_00284D00 {
    int m0;
    int m4;
    bool Active() { return m4 != 0; }
};
struct Inner_00284D00 {
    char pad[0x4C];
    Tm_00284D00 m4C;
    char pad54[0x70 - 0x54];
    Tm_00284D00 m70;
};
struct Ctl_00284D00 {
    char pad[0x24];
    Inner_00284D00 m24;
};

struct Obj_00284D00;
extern "C" int func_0028E1C0(Obj_00284D00* o, unsigned short a, unsigned short b);
extern "C" float func_002032A0(unsigned int, int);
extern "C" unsigned int func_0026FDA0(Tm_00284D00* t);
extern "C" int func_00101890(Vec_00284D00* v, Vec_00284D00* n);
extern "C" float sqrtf(float);

struct Obj_00284D00 {
    char pad0[0xC];
    Body_00284D00* mC;
    char pad10[0x150 - 0x10];
    Vec_00284D00 m150;
    Vec_00284D00 m160;
    char pad170[0x270 - 0x170];
    Vec_00284D00 m270;
    Vec_00284D00 m280;
    char pad290[0x594 - 0x290];
    Ctl_00284D00* m594;
    void Strafe();
};

void Obj_00284D00::Strafe()
{
    V3_00284D00* vel = &mC->mB0;
    float speed = sqrtf(vel->x * vel->x + vel->y * vel->y + vel->z * vel->z);
    if (func_002032A0(0xBC33D268, 0) < speed) return;
    Inner_00284D00* in = &m594->m24;
    float f;
    if (in->m4C.Active()) {
        f = (float)func_0026FDA0(&in->m4C);
    } else {
        if (!in->m70.Active()) return;
        f = (float)func_0026FDA0(&in->m70);
    }
    f = f * 0.001000000047f;
    float lim = func_002032A0(0x435F0653, 0);
    if (lim < f) f = lim;
    if (in->m70.m4) f = -f;
    float a = f / lim * func_002032A0(0x4B8BAB12, 0);
    Body_00284D00* b = mC;
    float k = func_002032A0(0xBFBBD0AF, 0);
    Vec_00284D00 t0;
    Vec_00284D00 v;
    Vec_00284D00* pv = &v;
    {
        float x = b->m80.f.x * k; float y = b->m80.f.y * k; float z = b->m80.f.z * k; float w = b->m80.f.w * k;
        v.f.x = x; v.f.y = y; v.f.z = z; v.f.w = w;
    }
    {
        float x = b->m50.f.x + v.f.x; float y = b->m50.f.y + v.f.y; float z = b->m50.f.z + v.f.z; float w = b->m50.f.w + v.f.w;
        t0.f.x = x; t0.f.y = y; t0.f.z = z; t0.f.w = w;
    }
    m270 = t0;
    Body_00284D00* b1 = mC;
    {
        float x = b1->m70.f.x * a; float y = b1->m70.f.y * a; float z = b1->m70.f.z * a; float w = b1->m70.f.w * a;
        v.f.x = x; v.f.y = y; v.f.z = z; v.f.w = w;
    }
    {
        float x = m270.f.x + v.f.x; float y = m270.f.y + v.f.y; float z = m270.f.z + v.f.z; float w = m270.f.w + v.f.w;
        t0.f.x = x; t0.f.y = y; t0.f.z = z; t0.f.w = w;
    }
    m280 = t0;
    if (!func_0028E1C0(this, 16, 0)) return;
    {
        float x = m150.f.x - m280.f.x; float y = m150.f.y - m280.f.y; float z = m150.f.z - m280.f.z; float w = m150.f.w - m280.f.w;
        t0.f.x = x; t0.f.y = y; t0.f.z = z; t0.f.w = w;
    }
    v = m160;
    func_00101890(&t0, pv);
    Body_00284D00* b2 = mC;
    Vec_00284D00 u;
    {
        float x = b2->m50.f.x + b2->m80.f.x; float y = b2->m50.f.y + b2->m80.f.y; float z = b2->m50.f.z + b2->m80.f.z; float w = b2->m50.f.w + b2->m80.f.w;
        u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
    }
    m270 = u;
    {
        float x = m270.f.x + t0.f.x; float y = m270.f.y + t0.f.y; float z = m270.f.z + t0.f.z; float w = m270.f.w + t0.f.w;
        u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
    }
    m280 = u;
    if (func_0028E1C0(this, 16, 0)) return;
    Body_00284D00* b3 = mC;
    {
        float x = m280.f.x - b3->m80.f.x; float y = m280.f.y - b3->m80.f.y; float z = m280.f.z - b3->m80.f.z; float w = m280.f.w - b3->m80.f.w;
        u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
    }
    b3->m50 = u;
}
