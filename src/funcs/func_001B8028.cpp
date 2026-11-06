typedef int qword_001B8028 __attribute__((mode(TI)));

struct Vec_001B8028 {
    qword_001B8028 q;
};

struct Mat_001B8028 {
    Vec_001B8028 r[4];
};

extern "C" void func_00114E08(void* p, Vec_001B8028* pos);
extern "C" void func_00114E20(void* p, Mat_001B8028* mat);

struct Xform_001B8028 {
    Vec_001B8028 pos;
    Mat_001B8028 mat;
};

struct Model_001B8028 {
    char pad[0x50];
    Vec_001B8028 m50;
    Vec_001B8028 m60;
    Mat_001B8028 m70;
    char padB0[0x10];
    Mat_001B8028 mC0;
};

struct Obj_001B8028 {
    char pad[0xC];
    Model_001B8028* mC;
    char pad10[0xC];
    int m1C;
    void* m20;
    void Method();
};

void Obj_001B8028::Method()
{
    Xform_001B8028 t;
    if (m1C) {
        Mat_001B8028* mat = &t.mat;
        Model_001B8028* o = mC;
        t.pos = o->m50;
        t.mat = o->m70;
        Mat_001B8028* d = &o->mC0;
        *d = t.mat;
        func_00114E08(m20, &t.pos);
        func_00114E20(m20, mat);
    }
}
