typedef int qword __attribute__((mode(TI)));

struct Row_0014DDA0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_0014DDA0 {
    Row_0014DDA0 r[4];
    Mat_0014DDA0& operator=(const Mat_0014DDA0& m)
    {
        r[0] = m.r[0];
        r[1] = m.r[1];
        r[2] = m.r[2];
        r[3] = m.r[3];
        return *this;
    }
};

struct Obj_0014DDA0 {
    int m0;
    int m4;
    char pad8[0x30 - 0x8];
    Mat_0014DDA0 m30;
    void Fn(const Mat_0014DDA0& m);
};

extern "C" void func_0014E048(Obj_0014DDA0* self);

void Obj_0014DDA0::Fn(const Mat_0014DDA0& m)
{
    m30 = m;
    if (m4 != 2)
        func_0014E048(this);
}
