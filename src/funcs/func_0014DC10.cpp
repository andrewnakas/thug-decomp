typedef int qword __attribute__((mode(TI)));

struct Row_0014DC10 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_0014DC10 {
    Row_0014DC10 r[3];
};

struct Obj_0014DC10 {
    int m0;
    int m4;
    char pad8[0x30 - 0x8];
    Mat_0014DC10 m30;
    void Fn(const Mat_0014DC10& m);
};

extern "C" void func_0014E048(Obj_0014DC10* self);

void Obj_0014DC10::Fn(const Mat_0014DC10& m)
{
    m30 = m;
    if (m4 != 2)
        func_0014E048(this);
}
