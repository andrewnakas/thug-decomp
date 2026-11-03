typedef int qword __attribute__((mode(TI)));

struct Rgba_00136030 {
    unsigned char r, g, b, a;
};

struct Vec_00136030 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00136030& operator=(const Vec_00136030& o)
    {
        q = o.q;
        return *this;
    }
};

struct State_00136030 {
    Rgba_00136030 m0;
    Vec_00136030 m10[2];
    Rgba_00136030 m30[2];
    float m38;
    float m3C[2];
};

extern int D_00389E18;
extern State_00136030 D_003BEB00;
extern State_00136030 D_003BEB50[];
extern "C" void func_0014AB48();

extern "C" int func_00136030()
{
    int i = D_00389E18;
    if (i >= 0) {
        D_00389E18 = i - 1;
        D_003BEB00 = D_003BEB50[i];
        func_0014AB48();
        return 1;
    }
    return 0;
}
