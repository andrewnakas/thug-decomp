typedef int qword __attribute__((mode(TI)));
union Row_002875A0 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_002875A0 {
    Row_002875A0 r[4];
    Mat_002875A0* Self() { return this; }
};
extern "C" Mat_002875A0* func_001009C0(Mat_002875A0* out, float angle);
extern "C" void func_00323318(Mat_002875A0* a, Mat_002875A0* b, Mat_002875A0* out);
extern "C" float fabsf(float);
extern "C" float func_001E5318(unsigned int name, int v);

struct Body_002875A0 {
    char pad[0x70];
    Mat_002875A0 m70;
    float mB0;
};

struct Obj_002875A0 {
    char pad0[0xC];
    Body_002875A0* mC;
    char pad10[0x10];
    Mat_002875A0 m20;
    char pad60[0x94 - 0x60];
    float m94;
    void Tilt();
    void Apply(float a)
    {
        Mat_002875A0 rot;
        Mat_002875A0 tm;
        Mat_002875A0 r;
        Body_002875A0* b2 = mC;
        Mat_002875A0* m1 = &b2->m70;
        Mat_002875A0* src = func_001009C0(&rot, a * m94);
        Mat_002875A0* p = r.Self();
        *p = *src;
        func_00323318(p, m1, p);
        tm = r;
        *m1 = tm;
        Mat_002875A0* m2 = &m20;
        *m2 = mC->m70;
    }
};

void Obj_002875A0::Tilt()
{
    Body_002875A0* b = mC;
    if (0.95f < fabsf(b->m70.r[2].f.y)) return;
    Row_002875A0 v;
    float vz = b->m70.r[2].f.x;
    float vx = -b->m70.r[2].f.z;
    v.f.y = 0.0f;
    v.f.z = vz;
    v.f.w = 0.0f;
    v.f.x = vx;
    float d = b->m70.r[1].f.x * v.f.x + b->m70.r[1].f.z * v.f.z;
    if (m94 * 1.19999993f < d) {
        Apply(func_001E5318(0xABD57877, 0) * 0.01745329425f);
    } else if (d < m94 * -1.19999993f) {
        Apply(-(func_001E5318(0xABD57877, 0) * 0.01745329425f));
    }
}
