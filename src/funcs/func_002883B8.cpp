typedef int qword __attribute__((mode(TI)));
union Vec_002883B8 {
    qword q;
    struct { float x, y, z, w; } f;
    void operator+=(const Vec_002883B8& o)
    {
        f.x += o.f.x;
        f.y += o.f.y;
        f.z += o.f.z;
        f.w += o.f.w;
    }
};

struct Body_002883B8 {
    char pad[0x50];
    Vec_002883B8 m50;
    char pad60[0x80 - 0x60];
    Vec_002883B8 m80;
    char pad90[0xB0 - 0x90];
    Vec_002883B8 mB0;
};

struct Obj_002883B8;
extern "C" int func_0028E1C0(Obj_002883B8* o, unsigned short a, unsigned short b);
extern "C" float func_002032A0(unsigned int, int);
extern "C" unsigned int func_001E53A0(unsigned int, int);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00101890(Vec_002883B8* v, Vec_002883B8* n);
extern "C" void func_001016A8(Vec_002883B8* v, Vec_002883B8* n);

struct Obj_002883B8 {
    char pad0[0xC];
    Body_002883B8* mC;
    char pad10[0x150 - 0x10];
    Vec_002883B8 m150;
    Vec_002883B8 m160;
    char pad170[0x270 - 0x170];
    Vec_002883B8 m270;
    Vec_002883B8 m280;
    char pad290[0x580 - 0x290];
    unsigned int m580;
    bool Climb();
};

bool Obj_002883B8::Climb()
{
    if (mC->m80.f.y < 0.0f) return false;
    float k = func_002032A0(0x542CF0C7, 0);
    unsigned int start = m580;
    unsigned int el = func_0010FC30() - start;
    if (!(func_001E53A0(0x2757ED2C, 0) < el)) k = 6.0f;
    Body_002883B8* b = mC;
    Vec_002883B8 v;
    {
        float x = b->m80.f.x * k;
        float y = b->m80.f.y * k;
        float z = b->m80.f.z * k;
        float w = b->m80.f.w * k;
        v.f.x = x; v.f.y = y; v.f.z = z; v.f.w = w;
    }
    m270 = b->m50;
    m280 = b->m50;
    m280 += v;
    if (!func_0028E1C0(this, 16, 0)) return false;
    Vec_002883B8 n = m160;
    if (-0.1000000015f < n.f.y) return false;
    Vec_002883B8 d;
    {
        float x = m150.f.x - m280.f.x;
        float y = m150.f.y - m280.f.y;
        float z = m150.f.z - m280.f.z;
        float w = m150.f.w - m280.f.w;
        d.f.x = x; d.f.y = y; d.f.z = z; d.f.w = w;
    }
    func_00101890(&d, &n);
    Body_002883B8* b2 = mC;
    m270 = b2->m50;
    Vec_002883B8 t;
    {
        float x = b2->m50.f.x + d.f.x;
        float y = b2->m50.f.y + d.f.y;
        float z = b2->m50.f.z + d.f.z;
        float w = b2->m50.f.w + d.f.w;
        t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
    }
    m280 = t;
    if (func_0028E1C0(this, 16, 0)) {
        Vec_002883B8 s;
        {
            float x = m160.f.x * 0.001000000047f;
            float y = m160.f.y * 0.001000000047f;
            float z = m160.f.z * 0.001000000047f;
            float w = m160.f.w * 0.001000000047f;
            s.f.x = x; s.f.y = y; s.f.z = z; s.f.w = w;
        }
        {
            float x = m150.f.x + s.f.x;
            float y = m150.f.y + s.f.y;
            float z = m150.f.z + s.f.z;
            float w = m150.f.w + s.f.w;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
        }
        mC->m50 = t;
    } else {
        mC->m50 = m280;
    }
    func_001016A8(&mC->mB0, &n);
    return true;
}
