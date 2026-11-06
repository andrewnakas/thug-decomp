typedef int qword __attribute__((mode(TI)));

struct Vec_0019EFF8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_0019EFF8 {
    Vec_0019EFF8 r[4];
};

struct Model_0019EFF8 {
    char pad0[0x50];
    Vec_0019EFF8 m50;
    char pad60[0x70 - 0x60];
    Mat_0019EFF8 m70;
};

extern "C" int func_0011EAF0(void* anim);
extern "C" void func_00323298(Vec_0019EFF8* out, Mat_0019EFF8* m, Vec_0019EFF8* in);

static inline Vec_0019EFF8 Xform_0019EFF8(Mat_0019EFF8* m, Vec_0019EFF8* v)
{
    Vec_0019EFF8 r;
    func_00323298(&r, m, v);
    return r;
}

struct Obj_0019EFF8 {
    char pad0[0xC];
    Model_0019EFF8* mC;
    char pad10[0x1C - 0x10];
    void* m1C;
    int Fn(int a, Vec_0019EFF8* out);
};

int Obj_0019EFF8::Fn(int a, Vec_0019EFF8* out)
{
    if (!func_0011EAF0(m1C))
        out->Set(0.0f, 0.0f, 0.0f, 1.0f);
    Mat_0019EFF8 m = mC->m70;
    m.r[3] = mC->m50;
    m.r[3].w = 1.0f;
    *out = Xform_0019EFF8(&m, out);
    return 0;
}
