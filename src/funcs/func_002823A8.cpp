typedef int qword __attribute__((mode(TI)));
union Vec_002823A8 {
    qword q;
    struct { float x, y, z, w; } f;
    float c[4];
    float& operator[](int i) { return c[i]; }
    void Set(float a, float b, float c, float d)
    {
        f.x = a;
        f.y = b;
        f.z = c;
        f.w = d;
    }
    Vec_002823A8* Self() { return this; }
    void Negate()
    {
        f.x = -f.x;
        f.y = -f.y;
        f.z = -f.z;
        f.w = -f.w;
    }
};
struct Mat_002823A8;
extern "C" Mat_002823A8* func_00100928(Mat_002823A8* out, float angle);
extern "C" void func_00323318(Mat_002823A8* a, Mat_002823A8* b, Mat_002823A8* out);
struct Mat_002823A8 {
    Vec_002823A8 r[4];
    Mat_002823A8* Self() { return this; }
    void Rot(float a)
    {
        Mat_002823A8 tm;
        Mat_002823A8 r;
        Mat_002823A8* src = func_00100928((Mat_002823A8*)0x70003FC0, a);
        Mat_002823A8* p = r.Self();
        *p = *src;
        func_00323318(p, this, p);
        tm = r;
        *this = tm;
    }
    void Copy(const Mat_002823A8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
    }
};
struct State_002823A8 {
    int pad;
    int state;
    unsigned int time;
};
struct Body_002823A8 {
    char pad[0x50];
    Vec_002823A8 m50;
    char pad60[0x70 - 0x60];
    Mat_002823A8 m70;
    Vec_002823A8 mB0;
};
struct Sub_002823A8 {
    char pad[0x3C];
    State_002823A8 m3C;
    State_002823A8 m48;
    char pad54[0x90 - 0x54];
    State_002823A8 m90;
    char pad9C[0xA8 - 0x9C];
    State_002823A8 mA8;
    char padB4[0xF0 - 0xB4];
    State_002823A8 mF0;
    char padFC[0x140 - 0xFC];
    Vec_002823A8 m140;
};
struct Target_002823A8 {
    Vec_002823A8 pos;
    Vec_002823A8 up;
    float m20;
};

extern "C" unsigned int func_0010FC30();
extern "C" float sqrtf(float);
extern "C" void func_003233B8(Vec_002823A8*, Vec_002823A8*);
extern "C" void func_001016A8(Vec_002823A8* v, Vec_002823A8* n);
extern "C" float func_00101D60(Vec_002823A8* a, Vec_002823A8* b, Vec_002823A8* c);
extern "C" void func_00103000(void* a, Mat_002823A8* b, Mat_002823A8* c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E72B0(void* p, unsigned int key, float v);
extern "C" void func_00184BC0(Body_002823A8* b, unsigned int name, int a, int c, int d, void* s);
extern "C" void func_00183F88(Body_002823A8* b, unsigned int name);
extern Vec_002823A8 D_00452FC0;
struct Obj_002823A8;
extern "C" float func_00282C38(Obj_002823A8* o, float a, float b, float c);

static inline void Set_002823A8(State_002823A8* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Obj_002823A8 {
    char pad0[0xC];
    Body_002823A8* mC;
    char pad10[0x3F4 - 0x10];
    float m3F4;
    char pad3F8[0x440 - 0x3F8];
    Mat_002823A8 m440;
    Mat_002823A8 m480;
    char pad4C0[0x520 - 0x4C0];
    float m520;
    float m524;
    char pad528[0x530 - 0x528];
    Vec_002823A8 m530;
    Mat_002823A8 m540;
    char pad580[0x5B0 - 0x580];
    Sub_002823A8* m5B0;
    void Start(Target_002823A8* t);
};

void Obj_002823A8::Start(Target_002823A8* t)
{
    Vec_002823A8 d;
    Vec_002823A8 dir;
    Mat_002823A8 bm;
    Vec_002823A8* up = &t->up;
    Body_002823A8* b = mC;
    {
        float x = t->pos.f.x - b->m50.f.x;
        float z = t->pos.f.z - b->m50.f.z;
        float w = t->pos.f.w - b->m50.f.w;
        d.f.y = 0.0f;
        d.f.x = x;
        d.f.z = z;
        d.f.w = w;
    }
    float zero = d.f.y;
    float len = sqrtf(d.f.x * d.f.x + d.f.z * d.f.z);
    if (d.f.x * b->mB0.f.x + d.f.z * b->mB0.f.z < zero) len = -len;
    float inv = 1.0f / len;
    dir.f.x = d.f.x * inv;
    dir.f.y = zero;
    dir.f.z = d.f.z * inv;
    dir.f.w = d.f.w * inv;
    Set_002823A8(&m5B0->mA8, 1);
    float tm = func_00282C38(this, t->pos.f.y, mC->m50.f.y, mC->mB0.f.y);
    float s = len / tm;
    Set_002823A8(&m5B0->mA8, 0);
    m5B0->m140.Set(s * dir.f.x, zero, s * dir.f.z, 1.0f);
    D_00452FC0 = m5B0->m140;
    m3F4 = t->pos.f.y;
    Vec_002823A8* pd = &dir;
    Set_002823A8(&m5B0->mA8, 1);
    Set_002823A8(&m5B0->m3C, 1);
    Set_002823A8(&m5B0->mF0, 1);
    Set_002823A8(&m5B0->m48, 0);
    Set_002823A8(&m5B0->m90, 0);
    mC->mB0.f.x = zero;
    mC->mB0.f.z = zero;
    bm = mC->m70;
    Vec_002823A8 fw;
    Mat_002823A8 m;
    fw = dir;
    fw.f.y = -(fw.f.x * t->up.f.x + fw.f.z * t->up.f.z) / t->up.f.y;
    func_003233B8(&fw, &fw);
    m.r[2] = fw;
    Vec_002823A8* fwd = m.r[2].Self();
    func_001016A8(fwd, up);
    func_003233B8(fwd, fwd);
    m.r[1] = t->up;
    {
        Vec_002823A8 c;
        float x = m.r[1].f.y * m.r[2].f.z - m.r[1].f.z * m.r[2].f.y;
        float y = m.r[1].f.z * m.r[2].f.x - m.r[1].f.x * m.r[2].f.z;
        float z = m.r[1].f.x * m.r[2].f.y - m.r[1].f.y * m.r[2].f.x;
        c.f.w = zero;
        c.f.x = x; c.f.z = z; c.f.y = y;
        m.r[0] = c;
    }
    Vec_002823A8* p3 = &m.r[3];
    p3->Set(zero, zero, zero, 1.0f);
    m530 = m.r[2];
    m440.Copy(m);
    if (m440.r[2][1] > zero) {
        m440.r[2].Negate();
        m440.r[0].Negate();
    }
    {
        Vec_002823A8 h;
        h = mC->m70.r[2];
        h.f.y = zero;
        m.Rot(-func_00101D60(&h, pd, &mC->m70.r[1]));
    }
    func_00103000(&m480, &bm, &m);
    m520 = zero;
    m524 = tm;
    m540.Copy(bm);
    void* sc = func_001E6978(func_001190D0(8));
    func_001E72B0(sc, 0xBB00FE40, mC->m50.f.y - t->m20);
    func_00184BC0(mC, 0xC7ED5FEF, -1, 0, 0, sc);
    func_00183F88(mC, 0x8FFEFB28);
}
