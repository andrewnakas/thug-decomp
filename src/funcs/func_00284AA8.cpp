typedef int qword __attribute__((mode(TI)));
union Row_00284AA8 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00284AA8 {
    Row_00284AA8 r[4];
    Mat_00284AA8* Self() { return this; }
};
struct V3_00284AA8 { float x, y, z; };
extern "C" Mat_00284AA8* func_00100928(Mat_00284AA8* out, float angle);
extern "C" void func_00323318(Mat_00284AA8* a, Mat_00284AA8* b, Mat_00284AA8* out);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);
extern "C" float func_003412F0(float);
extern "C" float func_00340F60(float);

struct Body_00284AA8 {
    char pad[0x70];
    Mat_00284AA8 m70;
    V3_00284AA8 mB0;
};
struct Ctl_00284AA8 {
    char pad[0x74];
    int m74;
    char pad78[0x98 - 0x78];
    int m98;
};

static inline float Clamp_00284AA8(float v, float lo, float hi)
{
    if (hi < v) v = hi;
    if (v < lo) v = lo;
    return v;
}

struct Obj_00284AA8 {
    char pad0[0xC];
    Body_00284AA8* mC;
    char pad10[0x10];
    Mat_00284AA8 m20;
    char pad60[0x594 - 0x60];
    Ctl_00284AA8* m594;
    float Turn(V3_00284AA8* dir, float k, float* out);
    void Rot(Mat_00284AA8* dst, float a)
    {
        Mat_00284AA8 tm;
        Mat_00284AA8 r;
        Mat_00284AA8* src = func_00100928((Mat_00284AA8*)0x70003FC0, a);
        Mat_00284AA8* p = r.Self();
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

float Obj_00284AA8::Turn(V3_00284AA8* dir, float k, float* out)
{
    Body_00284AA8* b = mC;
    float d = b->m70.r[0].f.x * dir->x + b->m70.r[0].f.y * dir->y + b->m70.r[0].f.z * dir->z;
    d = Clamp_00284AA8(d, -1.0f, 1.0f);
    float ang = func_003412F0(d);
    if (1.570796371f < ang) ang -= 3.141592741f;
    float a = ang * func_002032A0(0xE07EE1A9, 0) * k;
    *out = a;
    Body_00284AA8* b2 = mC;
    float s = func_00341068(a);
    float co = func_00340F60(a);
    V3_00284AA8* v = &b2->mB0;
    float z = v->z;
    float x = v->x;
    v->x = co * x + s * z;
    v->z = -s * x + co * z;
    Rot(&mC->m70, *out);
    Rot(&m20, *out);
    return ang;
}
