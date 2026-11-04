typedef int qword __attribute__((mode(TI)));
union Vec_0027DD70 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct VecC_0027DD70 {
    Vec_0027DD70 v;
    VecC_0027DD70(float x, float y, float z, float w)
    {
        v.f.x = x; v.f.y = y; v.f.z = z; v.f.w = w;
    }
};
struct Mat_0027DD70 {
    Vec_0027DD70 r[4];
    Mat_0027DD70* Self() { return this; }
};
extern "C" Mat_0027DD70* func_00100928(Mat_0027DD70* out, float angle);
extern "C" void func_00323318(Mat_0027DD70* a, Mat_0027DD70* b, Mat_0027DD70* out);
extern "C" float func_002032A0(unsigned int, int);
extern "C" void func_001016A8(VecC_0027DD70* v, Vec_0027DD70* n);
extern "C" float func_00101D60(Vec_0027DD70* a, VecC_0027DD70* b, Vec_0027DD70* c);
extern "C" float sqrtf(float);
static inline float fabsf(float x) { return __builtin_fabsf(x); }

struct Body_0027DD70 {
    char pad[0x70];
    Mat_0027DD70 m70;
    Vec_0027DD70 mB0;
};

struct Obj_0027DD70 {
    char pad0[0xC];
    Body_0027DD70* mC;
    char pad10[0x10];
    Mat_0027DD70 m20;
    char pad60[0x70 - 0x60];
    Vec_0027DD70 m70;
    char pad80[0x94 - 0x80];
    float m94;
    int Align();
    void Rot(Mat_0027DD70* dst, float a)
    {
        Mat_0027DD70 tm;
        Mat_0027DD70 r;
        Mat_0027DD70* src = func_00100928((Mat_0027DD70*)0x70003FC0, a);
        Mat_0027DD70* p = r.Self();
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

extern "C" int func_0027D958(Obj_0027DD70* self);

int Obj_0027DD70::Align()
{
    if (func_0027D958(this)) {
        Body_0027DD70* b = mC;
        Vec_0027DD70* v = &b->mB0;
        Vec_0027DD70 dir;
        if (sqrtf(v->f.x * v->f.x + v->f.y * v->f.y + v->f.z * v->f.z) < 0.001f)
            dir = b->m70.r[2];
        else
            dir = b->mB0;
        VecC_0027DD70 down(0.0f, -1.0f, 0.0f, 1.0f);
        func_001016A8(&down, &m70);
        float ang = func_00101D60(&dir, &down, &mC->m70.r[1]);
        float k = func_002032A0(0x7DD5678B, 0);
        float s = 1.0f;
        if (ang < 0.0f) s = -1.0f;
        float a = k * s * m94;
        if (fabsf(ang) < fabsf(a)) a = ang;
        Rot(&mC->m70, a);
        Rot(&m20, a);
        return 1;
    }
    return 0;
}
