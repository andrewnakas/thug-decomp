typedef int qword __attribute__((mode(TI)));

struct V_0019BBB0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0019BBB0 {
    V_0019BBB0 r[4];
    Mat_0019BBB0() {}
    const V_0019BBB0& operator[](int i) const { return r[i]; }
    Mat_0019BBB0(const Mat_0019BBB0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

extern "C" Mat_0019BBB0* func_00100890(Mat_0019BBB0* out, float a);
extern "C" Mat_0019BBB0* func_001009C0(Mat_0019BBB0* out, float a);
extern "C" void func_00323318(Mat_0019BBB0* d, Mat_0019BBB0* a, Mat_0019BBB0* b);

static inline Mat_0019BBB0 Mul_0019BBB0(const Mat_0019BBB0& a, Mat_0019BBB0& b)
{
    Mat_0019BBB0 r(a);
    func_00323318(&r, &b, &r);
    return r;
}

struct Node_0019BBB0 {
    float m0;
    char pad4[0xC - 0x4];
    float mC;
    char pad10[0x14 - 0x10];
    float m14;
    char pad18[0xC0 - 0x18];
    V_0019BBB0 mC0;
    char padD0[0xDC - 0xD0];
    float mDC;
    char padE0[0x220 - 0xE0];
};

extern "C" void* func_0019EBD0(void* p);
extern "C" Mat_0019BBB0* func_0011D9E0(void* p);
extern "C" int func_0011D9E8(void* p);

struct Obj_0019BBB0 {
    char pad0[0x300];
    V_0019BBB0 m300;
    char pad310[0x318 - 0x310];
    Node_0019BBB0* m318;
    char pad31C[0x1374 - 0x31C];
    void* m1374;
    char pad1378[0x1380 - 0x1378];
    int m1380;
    void Func_0019BBB0();
};

void Obj_0019BBB0::Func_0019BBB0()
{
    Mat_0019BBB0* mats = func_0011D9E0(func_0019EBD0(m1374));
    int n = func_0011D9E8(func_0019EBD0(m1374));
    float one;
    for (int i = n - 1; i != -1; i--) {
        Mat_0019BBB0* m = &mats[i];
        if (m1380 == 2 || i == 0) {
            m->r[0].x = 0.0f; m->r[0].y = 0.0f; m->r[0].z = 0.0f; m->r[0].w = 0.0f;
            m->r[1].x = 0.0f; m->r[1].y = 0.0f; m->r[1].z = 0.0f; m->r[1].w = 0.0f;
            m->r[2].x = 0.0f; m->r[2].y = 0.0f; m->r[2].z = 0.0f; m->r[2].w = 0.0f;
            m->r[3].x = 0.0f; m->r[3].y = 0.0f; m->r[3].z = 0.0f; m->r[3].w = 0.0f;
        } else if (i == 1) {
            m->r[0].x = 0.0f; m->r[0].y = 0.0f; m->r[0].z = 0.0f; m->r[0].w = 0.0f;
            m->r[1].x = 0.0f; m->r[1].y = 0.0f; m->r[1].z = 0.0f; m->r[1].w = 0.0f;
            m->r[2].x = 0.0f; m->r[2].y = 0.0f; m->r[2].z = 0.0f; m->r[2].w = 0.0f;
            m->r[3].x = 0.0f; m->r[3].y = 0.0f; m->r[3].z = 0.0f; m->r[3].w = 0.0f;
            m->r[0].x = 1.0f; m->r[1].z = -1.0f; m->r[2].y = 1.0f;
            m->r[3] = m300;
        } else {
            Node_0019BBB0* nd = &m318[i - 2];
            one = 1.0f;
            m->r[0].x = 0.0f; m->r[0].y = 0.0f; m->r[0].z = 0.0f; m->r[0].w = 0.0f;
            m->r[1].x = 0.0f; m->r[1].y = 0.0f; m->r[1].z = 0.0f; m->r[1].w = 0.0f;
            m->r[2].x = 0.0f; m->r[2].y = 0.0f; m->r[2].z = 0.0f; m->r[2].w = 0.0f;
            m->r[3].x = 0.0f; m->r[3].y = 0.0f; m->r[3].z = 0.0f; m->r[3].w = 0.0f;
            m->r[0].x = -1.0f; m->r[1].z = one; m->r[2].y = one;
            {
                Mat_0019BBB0 t;
                *m = Mul_0019BBB0(*func_001009C0(&t, nd->m14), *m);
            }
            {
                Mat_0019BBB0 t;
                *m = Mul_0019BBB0(*func_00100890(&t, -nd->mC), *m);
            }
            m->r[3] = nd->mC0;
            float a = nd->m0;
            float b = nd->mDC;
            float f;
            if (b < a) f = b; else f = a;
            m->r[3].y += f;
            m->r[3].w = one;
        }
    }
}
