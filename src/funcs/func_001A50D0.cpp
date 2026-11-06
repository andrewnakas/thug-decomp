typedef int qword_001A50D0 __attribute__((mode(TI)));

struct Row_001A50D0 {
    union {
        struct { float x, y, z, w; };
        qword_001A50D0 q;
    };
};

struct Mat_001A50D0 {
    Row_001A50D0 r[4];
};

extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" Mat_001A50D0* func_00323318(Mat_001A50D0* dst, const Mat_001A50D0* a, const Mat_001A50D0* b);

struct Skel_001A50D0 {
    char pad[0x10];
    Mat_001A50D0 m10;
    char pad50[0xB0 - 0x50];
    Mat_001A50D0 mB0;
    char padF0[0x150 - 0xF0];
    Mat_001A50D0 m150;
};

struct Model_001A50D0 {
    char pad[0x260];
    int m260;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_0019EBD0(void* comp);
extern "C" Skel_001A50D0* func_0013EF50(int model);

struct Obj_001A50D0 {
    char pad[0xC];
    void* mC;
    char pad10[0x30 - 0x10];
    float m30;
    void Method();
};

void Obj_001A50D0::Method()
{
    void* c = func_00185578(mC, 0x222756D5);
    if (c)
        func_0019EBD0(c);
    Model_001A50D0* m = (Model_001A50D0*)func_00185578(mC, 0x286A8D26);
    Skel_001A50D0* s = func_0013EF50(m ? m->m260 : 0);
    Mat_001A50D0 a;
    Mat_001A50D0 b;
    a = s->mB0;
    func_00323318(&a, &s->m10, &a);
    b = s->m150;
    func_00323318(&b, &s->m10, &b);
    Row_001A50D0 d;
    d.x = a.r[3].x - b.r[3].x;
    d.y = a.r[3].y - b.r[3].y;
    d.z = a.r[3].z - b.r[3].z;
    d.w = a.r[3].w - b.r[3].w;
    m30 = fabsf(sqrtf(d.x * d.x + d.y * d.y + d.z * d.z));
}
