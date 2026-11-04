typedef int qword __attribute__((mode(TI)));
union Row_00286EF8 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00286EF8 {
    Row_00286EF8 r[4];
    Mat_00286EF8* Self() { return this; }
};
extern "C" Mat_00286EF8* func_00100890(Mat_00286EF8* out, float angle);
extern "C" void func_00323318(Mat_00286EF8* a, Mat_00286EF8* b, Mat_00286EF8* out);
extern "C" float func_002032A0(unsigned int, int);


struct Body_00286EF8 {
    char pad[0x70];
    Mat_00286EF8 m70;
};
struct Tm_00286EF8 { int m0; int m4; };
extern "C" int func_0026FDA0(Tm_00286EF8* t);
extern "C" float func_00203D40(Body_00286EF8* o, unsigned int name);

struct Sub_00286EF8 {
    char pad[0x40];
    int m40;
    char pad44[0xAC - 0x44];
    int mAC;
    char padB0[0x118 - 0xB0];
    int m118;
};
struct Ctl_00286EF8 {
    char pad[0x28];
    Tm_00286EF8 m28;
    char pad30[0x4C - 0x30];
    Tm_00286EF8 m4C;
    char pad54[0x194 - 0x54];
    int m194;
    char pad198[0x1B8 - 0x198];
    int m1B8;
};

struct Obj_00286EF8 {
    char pad0[0xC];
    Body_00286EF8* mC;
    char pad10[0x10];
    Mat_00286EF8 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x594 - 0x98];
    Ctl_00286EF8* m594;
    char pad598[0x5B0 - 0x598];
    Sub_00286EF8* m5B0;
    void Rotate();
    void Rot(Mat_00286EF8* dst, float a)
    {
        Mat_00286EF8 rot;
        Mat_00286EF8 tm;
        Mat_00286EF8 r;
        Mat_00286EF8* src = func_00100890(&rot, a * m94);
        Mat_00286EF8* p = r.Self();
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

void Obj_00286EF8::Rotate()
{
    Sub_00286EF8* s = m5B0;
    if (s->mAC) return;
    if (s->m118) return;
    if (s->m40) return;
    Ctl_00286EF8* c = m594;
    if (c->m194) return;
    if (c->m1B8) return;
    float f = 0.0f;
    int t = 0;
    Tm_00286EF8* t1 = &c->m28;
    if (t1->m4) {
        f = func_00203D40(mC, 0xCBFDD841);
        t = func_0026FDA0(t1);
    }
    Tm_00286EF8* t2 = &c->m4C;
    if (t2->m4) {
        f = -func_00203D40(mC, 0xCBFDD841);
        t = func_0026FDA0(t2);
    }
    float lo = func_002032A0(0x5F70EF46, 0);
    float hi = func_002032A0(0x12CD2D14, 0);
    float ft = (float)t;
    if (ft <= lo) return;
    if (ft < hi) f = f * (ft - lo) / (hi - lo);
    if (f == 0.0f) return;
    Rot(&mC->m70, f);
    Rot(&m20, f);
}
