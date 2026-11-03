typedef int qword __attribute__((mode(TI)));

union Vec_00287368 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};
struct Mat_00287368;
extern "C" void func_00323318(Mat_00287368* a, Mat_00287368* b, Mat_00287368* out);
extern "C" Mat_00287368* func_00100700(Mat_00287368* out, Vec_00287368* axis, float ang);
struct Mat_00287368 {
    Vec_00287368 r[4];
    Mat_00287368* Rotate(Vec_00287368* axis, float ang) { return func_00100700(this, axis, ang); }
    void MulBy(Mat_00287368& b) { func_00323318(this, &b, this); }
};

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" unsigned int func_0010FC30();

struct Coll_00287368 {
    Vec_00287368 start;
    Vec_00287368 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0xA0 - 0x6A];
    Vec_00287368 hit;
    Vec_00287368 normal;
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
    ~Coll_00287368() { mC0.Release(); }
};

struct State_00287368 { int pad; int state; unsigned int time; };
static inline void SetState_00287368(State_00287368* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Body_00287368 {
    char pad0[0x50];
    Vec_00287368 m50;
    char pad60[0x70 - 0x60];
    Mat_00287368 m70;
    char padB0[0xB4 - 0xB0];
    float mB4;
    void GetMatrix(Mat_00287368* out) { *out = m70; }
};

struct Sub_00287368 {
    char pad0[0x3C];
    State_00287368 m3C;
    char pad48[0xAC - 0x48];
    int mAC;
    char padB0[0xB4 - 0xB0];
    State_00287368 mB4;
};

struct Info_00287368 {
    char pad0[0x1C];
    int m1C;
};

extern "C" void func_00209240(Coll_00287368* c);
extern "C" bool func_002093E8(Coll_00287368* c, int a, int b);
extern "C" float func_00203D40(Body_00287368* o, unsigned int name);
extern "C" void func_003233B8(Vec_00287368* a, Vec_00287368* b);

struct Obj_00287368 {
    char pad0[0xC];
    Body_00287368* mC;
    char pad10[0x20 - 0x10];
    Mat_00287368 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x5B0 - 0x98];
    Sub_00287368* m5B0;
    Info_00287368* m5B4;
    void Align();
};

void Obj_00287368::Align()
{
    if (m5B0->mAC) return;
    if (0.0f < mC->mB4 && m5B4->m1C) return;
    Coll_00287368 c;
    func_00209240(&c);
    Body_00287368* b = mC;
    c.start = b->m50;
    c.end = b->m50;
    c.end.f.y -= 500.0f;
    if (!func_002093E8(&c, 1, 0)) return;
    if (c.m68 & 8) return;
    if (c.normal.f.y < 0.200000003f) return;
    SetState_00287368(&m5B0->m3C, 0);
    SetState_00287368(&m5B0->mB4, 1);
    if (0.8999999762f < mC->m70.r[1].f.y) return;
    float k = func_00203D40(mC, 0xE7116A96);
    Vec_00287368 t = mC->m70.r[1];
    t.f.y = 0.0f;
    func_003233B8(&t, &t);
    Vec_00287368 axis;
    axis.f.x = -t.f.z;
    axis.f.y = 0.0f;
    axis.f.z = t.f.x;
    axis.f.w = 0.0f;
    Mat_00287368 rot;
    Mat_00287368* m = &mC->m70;
    rot.Rotate(&axis, k * m94);
    m->MulBy(rot);
    mC->GetMatrix(&m20);
}
