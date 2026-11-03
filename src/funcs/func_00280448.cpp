typedef int qword __attribute__((mode(TI)));
union Row_00280448 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00280448 {
    Row_00280448 r[4];
    Mat_00280448* Self() { return this; }
};
extern "C" Mat_00280448* func_00100890(Mat_00280448* out, float angle);
extern "C" void func_00323318(Mat_00280448* a, Mat_00280448* b, Mat_00280448* out);
extern "C" void func_003233B8(Row_00280448* a, Row_00280448* b);
extern "C" void func_00100DC0(Mat_00280448* m, int axis);
extern "C" float func_002032A0(unsigned int, int);
extern "C" int func_00203300(unsigned int, int);
extern "C" float sqrtf(float);
extern "C" unsigned int func_0010FC30();

struct State_00280448 { int pad; int state; unsigned int time; };
static inline void SetState_00280448(State_00280448* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Body_00280448 {
    char pad[0x70];
    Mat_00280448 m70;
    Row_00280448 mB0;
};
struct Tm_00280448 {
    int m0;
    int m4;
    bool Active() { return m4 != 0; }
};
extern "C" int func_0026FDA0(Tm_00280448* t);

struct Inner_00280448 {
    int m0;
    Tm_00280448 m4;
    char padC[0x50 - 0xC];
    int m50;
    char pad54[0x74 - 0x54];
    int m74;
    char pad78[0xB8 - 0x78];
    Tm_00280448 mB8;
    char padC0[0x128 - 0xC0];
    int m128;
};
struct Ctl_00280448 {
    char pad[0x24];
    Inner_00280448 m24;
    char pad150[0x194 - 0x150];
    int m194;
    char pad198[0x1B8 - 0x198];
    int m1B8;
};
struct Sub_00280448 {
    char pad[0x3C];
    State_00280448 m3C;
    State_00280448 m48;
    char pad54[0x60 - 0x54];
    State_00280448 m60;
    char pad6C[0xB4 - 0x6C];
    State_00280448 mB4;
    char padC0[0xFC - 0xC0];
    State_00280448 mFC;
};

struct Obj_00280448;
extern "C" int func_00280918(Obj_00280448* o);

struct Obj_00280448 {
    char pad0[0xC];
    Body_00280448* mC;
    char pad10[0x10];
    Mat_00280448 m20;
    Row_00280448 m60;
    char pad70[0x594 - 0x70];
    Ctl_00280448* m594;
    char pad598[0x5B0 - 0x598];
    Sub_00280448* m5B0;
    void Update();
    void Rot(Mat_00280448* m1, float a)
    {
        Mat_00280448 rot;
        Mat_00280448 tm;
        Mat_00280448 r;
        Mat_00280448* src = func_00100890(&rot, a);
        Mat_00280448* p = r.Self();
        *p = *src;
        func_00323318(p, m1, p);
        tm = r;
        *m1 = tm;
    }
    void Fix()
    {
        Row_00280448 t = mC->mB0;
        func_003233B8(&t, &t);
        mC->m70.r[2].f.x = t.f.x;
        mC->m70.r[2].f.z = t.f.z;
        func_003233B8(&mC->m70.r[2], &mC->m70.r[2]);
        func_00100DC0(&mC->m70, 2);
    }
};

void Obj_00280448::Update()
{
    Ctl_00280448* c = m594;
    Tm_00280448* t = &c->m24.m4;
    Inner_00280448* in = &c->m24;
    if ((t->m4 && func_0026FDA0(t) > func_00203300(0x9D2F8CC8, 0) && !c->m24.m50
         && !c->m24.m74 && !c->m1B8 && !c->m194)
        || in->mB8.Active() || in->m128) {
        if (!in->mB8.Active() && !in->m128) {
            Body_00280448* b = mC;
            Row_00280448* v = &b->mB0;
            float s = sqrtf(v->f.x * v->f.x + v->f.y * v->f.y + v->f.z * v->f.z);
            s = s * func_002032A0(0x13F33B41, 0);
            mC->mB0.f.x += -m60.f.x * s;
            mC->mB0.f.z += -m60.f.z * s;
            Body_00280448* b2 = mC;
            b2->mB0.f.y *= func_002032A0(0x848C5CD6, 0);
            Body_00280448* b3 = mC;
            Rot(&b3->m70, func_002032A0(0xD757F4BB, 0) * 0.01745329425f);
            SetState_00280448(&m5B0->m3C, 0);
            SetState_00280448(&m5B0->m48, 0);
            SetState_00280448(&m5B0->m60, 0);
            SetState_00280448(&m5B0->mFC, 0);
            Fix();
        } else if (!func_00280918(this)) {
            mC->mB0.f.x += -m60.f.x * 24.0f;
            mC->mB0.f.z += -m60.f.z * 24.0f;
            Body_00280448* b3 = mC;
            Rot(&b3->m70, func_002032A0(0xD757F4BB, 0) * 0.01745329425f);
            SetState_00280448(&m5B0->m3C, 0);
            SetState_00280448(&m5B0->m48, 0);
            SetState_00280448(&m5B0->m60, 0);
            SetState_00280448(&m5B0->mB4, 1);
            Fix();
            return;
        }
        Mat_00280448* m2 = &m20;
        *m2 = mC->m70;
    }
}
