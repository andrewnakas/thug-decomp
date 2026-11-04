typedef int qword __attribute__((mode(TI)));
union Row_00282C88 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00282C88 {
    Row_00282C88 r[4];
    Mat_00282C88* Self() { return this; }
};
struct V3_00282C88 { float x, y, z; };
extern "C" Mat_00282C88* func_00100928(Mat_00282C88* out, float angle);
extern "C" void func_00323318(Mat_00282C88* a, Mat_00282C88* b, Mat_00282C88* out);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);

struct Body_00282C88 {
    char pad[0x70];
    Mat_00282C88 m70;
    V3_00282C88 mB0;
};
struct Tm_00282C88 { int m0; int m4; };
extern "C" int func_0026FDA0(Tm_00282C88* t);
extern "C" float sqrtf(float);
struct Ctl_00282C88 {
    char pad[0x50];
    int m50;
    char pad54[0x70 - 0x54];
    Tm_00282C88 m70;
    char pad78[0x94 - 0x78];
    Tm_00282C88 m94;
};

struct Obj_00282C88 {
    char pad0[0xC];
    Body_00282C88* mC;
    char pad10[0x10];
    Mat_00282C88 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x400 - 0x98];
    int m400;
    char pad404[0x428 - 0x404];
    int m428;
    char pad42C[0x594 - 0x42C];
    Ctl_00282C88* m594;
    void Steer();
    void Rot(Mat_00282C88* dst, float a)
    {
        Mat_00282C88 tm;
        Mat_00282C88 r;
        Mat_00282C88* src = func_00100928((Mat_00282C88*)0x70003FC0, a);
        Mat_00282C88* p = r.Self();
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

void Obj_00282C88::Steer()
{
    float a = 0.0f;
    Body_00282C88* b = mC;
    Ctl_00282C88* c = m594;
    V3_00282C88* v = &b->mB0;
    float speed = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    Tm_00282C88* t = &c->m70;
    if (t->m4) {
        if (!c->m50) {
            a = func_002032A0(0x374E056B, 0);
        } else {
            a = func_002032A0(0x7933A8EF, 0);
            if (speed < 10.0f) {
                int ms = func_0026FDA0(t);
                if (ms < 600) a = a * (float)ms * 0.001666666707f;
            }
        }
    } else {
        t = &c->m94;
        if (t->m4) {
            if (!c->m50) {
                a = -func_002032A0(0x374E056B, 0);
            } else {
                a = -func_002032A0(0x7933A8EF, 0);
                if (speed < 10.0f) {
                    int ms = func_0026FDA0(t);
                    if (ms < 600) a = a * (float)ms * 0.001666666707f;
                }
            }
        }
    }
    if (a == 0.0f) return;
    a *= m94;
    m428 = 0.0f < a;
    if (!m400) {
        Body_00282C88* b2 = mC;
        float s = func_00341068(a);
        float co = func_00340F60(a);
        V3_00282C88* w = &b2->mB0;
        float z = w->z;
        float x = w->x;
        w->x = co * x + s * z;
        w->z = -s * x + co * z;
    }
    Rot(&mC->m70, a);
    Rot(&m20, a);
}
