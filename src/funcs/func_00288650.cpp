typedef int qword __attribute__((mode(TI)));
union Vec_00288650 {
    qword q;
    struct { float x, y, z, w; } f;
};


struct Body_00288650 {
    char pad[0x50];
    Vec_00288650 m50;
    char pad60[0xB0 - 0x60];
    Vec_00288650 mB0;
};

struct Obj_00288650;
extern "C" int func_0028E1C0(Obj_00288650* o, unsigned short a, unsigned short b);
extern "C" float func_002032A0(unsigned int, int);
extern "C" void func_00101890(Vec_00288650* v, Vec_00288650* n);
extern "C" void func_001016A8(Vec_00288650* v, Vec_00288650* n);

struct Obj_00288650 {
    char pad0[0xC];
    Body_00288650* mC;
    char pad10[0x150 - 0x10];
    Vec_00288650 m150;
    Vec_00288650 m160;
    char pad170[0x270 - 0x170];
    Vec_00288650 m270;
    Vec_00288650 m280;
    char pad290[0x410 - 0x290];
    Vec_00288650 m410;
    bool Step();
};

bool Obj_00288650::Step()
{
    Vec_00288650 n;
    Vec_00288650 v;
    Vec_00288650 t;
    Vec_00288650* pv = &v;
    float x = m410.f.x * 18.0f;
    float y = m410.f.y * 18.0f;
    float z = m410.f.z * 18.0f;
    float w = m410.f.w * 18.0f;
    v.f.x = x; v.f.y = y; v.f.z = z; v.f.w = w;
    Body_00288650* b = mC;
    {
        float x2 = b->m50.f.x + v.f.x;
        float y2 = b->m50.f.y + v.f.y;
        float z2 = b->m50.f.z + v.f.z;
        float w2 = b->m50.f.w + v.f.w;
        n.f.x = x2; n.f.y = y2; n.f.z = z2; n.f.w = w2;
    }
    m270 = n;
    m280 = n;
    m280.f.y += func_002032A0(0x542CF0C7, 0);
    if (!func_0028E1C0(this, 16, 0)) return false;
    n = m160;
    if (-0.1000000015f < n.f.y) return false;
    {
        float x2 = m150.f.x - m280.f.x;
        float y2 = m150.f.y - m280.f.y;
        float z2 = m150.f.z - m280.f.z;
        float w2 = m150.f.w - m280.f.w;
        v.f.x = x2; v.f.y = y2; v.f.z = z2; v.f.w = w2;
    }
    func_00101890(pv, &n);
    Body_00288650* b2 = mC;
    m270 = b2->m50;
    {
        float x2 = b2->m50.f.x + v.f.x;
        float y2 = b2->m50.f.y + v.f.y;
        float z2 = b2->m50.f.z + v.f.z;
        float w2 = b2->m50.f.w + v.f.w;
        t.f.x = x2; t.f.y = y2; t.f.z = z2; t.f.w = w2;
    }
    m280 = t;
    if (func_0028E1C0(this, 16, 0)) {
        {
            float x2 = m150.f.x + m160.f.x;
            float y2 = m150.f.y + m160.f.y;
            float z2 = m150.f.z + m160.f.z;
            float w2 = m150.f.w + m160.f.w;
            t.f.x = x2; t.f.y = y2; t.f.z = z2; t.f.w = w2;
        }
        mC->m50 = t;
    } else {
        mC->m50 = m280;
    }
    func_001016A8(&mC->mB0, &n);
    return true;
}
