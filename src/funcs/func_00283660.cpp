typedef int qword __attribute__((mode(TI)));
union Vec_00283660 {
    qword q;
    struct { float x, y, z, w; } f;
    void operator-=(const Vec_00283660& o)
    {
        f.x -= o.f.x;
        f.y -= o.f.y;
        f.z -= o.f.z;
        f.w -= o.f.w;
    }
};
struct Mat_00283660 {
    Vec_00283660 r[4];
};
struct State_00283660 { int pad; int state; unsigned int time; };

struct Body_00283660 {
    char pad[0x70];
    Mat_00283660 m70;
    Vec_00283660 mB0;
    void GetMatrix(Mat_00283660* out) { *out = m70; }
};
struct Sub_00283660 {
    char pad[0x108];
    State_00283660 m108;
};
struct Ctl_00283660 {
    char pad[0x1DC];
    int m1DC;
};

extern "C" unsigned int func_0010FC30();
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" float func_00341068(float);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" int func_00101730(Vec_00283660*, Vec_00283660*);
extern "C" void func_003233B8(Vec_00283660*, Vec_00283660*);
extern "C" float sqrtf(float);

static inline float Max_00283660(float a, float b)
{
    return a > b ? a : b;
}

struct Obj_00283660 {
    char pad0[0xC];
    Body_00283660* mC;
    char pad10[0x10];
    Mat_00283660 m20;
    char pad60[0x70 - 0x60];
    Vec_00283660 m70;
    char pad80[0x160 - 0x80];
    Vec_00283660 m160;
    char pad170[0x580 - 0x170];
    unsigned int m580;
    unsigned int m584;
    char pad588[0x594 - 0x588];
    Ctl_00283660* m594;
    char pad598[0x5B0 - 0x598];
    Sub_00283660* m5B0;
    bool Bounce();
};

bool Obj_00283660::Bounce()
{
    if (!m594->m1DC) return false;
    unsigned int s = m584;
    float el = (float)(func_0010FC30() - s);
    if (el < func_001E5318(0x17D543, 0)) return false;
    Body_00283660* b = mC;
    float d = b->m70.r[2].f.x * m160.f.x + b->m70.r[2].f.y * m160.f.y + b->m70.r[2].f.z * m160.f.z;
    float a = func_001E5318(0x1483FD01, 0);
    if (-func_00341068((a - 1.0f) * 0.01745329425f) <= d) return false;
    unsigned int s2 = m580;
    float el2 = (float)(func_0010FC30() - s2);
    if (el2 < func_001E5318(0x17D543, 0)) return false;
    func_001848F0(mC, 0x4C03635B, 0);
    State_00283660* st = &m5B0->m108;
    if (st->state != 0) {
        st->state = 0;
        st->time = func_0010FC30();
        return false;
    }
    Body_00283660* b1 = mC;
    float dn = b1->mB0.f.x * m160.f.x + b1->mB0.f.y * m160.f.y + b1->mB0.f.z * m160.f.z;
    Vec_00283660 p;
    Vec_00283660 q;
    {
        float x = m160.f.x * dn; float y = m160.f.y * dn; float z = m160.f.z * dn; float w = m160.f.w * dn;
        p.f.x = x; p.f.y = y; p.f.z = z; p.f.w = w;
    }
    {
        float x = p.f.x + p.f.x; float y = p.f.y + p.f.y; float z = p.f.z + p.f.z; float w = p.f.w + p.f.w;
        q.f.x = x; q.f.y = y; q.f.z = z; q.f.w = w;
    }
    b1->mB0 -= q;
    Body_00283660* b2 = mC;
    Vec_00283660* v2 = &b2->mB0;
    float sp = sqrtf(v2->f.x * v2->f.x + v2->f.y * v2->f.y + v2->f.z * v2->f.z);
    if (0.001000000047f < sp) {
        float mn = func_001E5318(0xB78542C2, 0);
        float k = func_001E5318(0x1112FB1C, 0);
        float f = Max_00283660(mn, sp - k) / sp;
        v2->f.x *= f;
        v2->f.y *= f;
        v2->f.z *= f;
        v2->f.w *= f;
    } else {
        float m = -func_001E5318(0xB78542C2, 0);
        Body_00283660* b3 = mC;
        {
            float x = b3->m70.r[2].f.x * m; float y = b3->m70.r[2].f.y * m; float z = b3->m70.r[2].f.z * m; float w = b3->m70.r[2].f.w * m;
            q.f.x = x; q.f.y = y; q.f.z = z; q.f.w = w;
        }
        b2->mB0 = q;
    }
    func_00101730(&mC->mB0, &m70);
    mC->m70.r[2] = mC->mB0;
    func_003233B8(&mC->m70.r[2], &mC->m70.r[2]);
    mC->m70.r[1] = m70;
    Body_00283660* b4 = mC;
    {
        float x = b4->m70.r[1].f.y * b4->m70.r[2].f.z - b4->m70.r[1].f.z * b4->m70.r[2].f.y;
        float y = b4->m70.r[1].f.z * b4->m70.r[2].f.x - b4->m70.r[1].f.x * b4->m70.r[2].f.z;
        float z = b4->m70.r[1].f.x * b4->m70.r[2].f.y - b4->m70.r[1].f.y * b4->m70.r[2].f.x;
        q.f.w = 0.0f;
        q.f.x = x; q.f.z = z; q.f.y = y;
        b4->m70.r[0] = q;
    }
    mC->GetMatrix(&m20);
    m584 = func_0010FC30();
    return true;
}
