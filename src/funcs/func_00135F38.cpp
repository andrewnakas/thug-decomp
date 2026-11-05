typedef int qword __attribute__((mode(TI)));

struct Rgba_00135F38 {
    unsigned char r, g, b, a;
};

struct Vec_00135F38 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00135F38& operator=(const Vec_00135F38& o)
    {
        q = o.q;
        return *this;
    }
};

struct State_00135F38 {
    Rgba_00135F38 m0;
    Vec_00135F38 m10[2];
    Rgba_00135F38 m30[2];
    float m38;
    float m3C[2];
};

extern int D_00389E18;
extern State_00135F38 D_003BEB00;
extern State_00135F38 D_003BEB50[];

extern "C" void func_00135F38()
{
    int i = D_00389E18 + 1;
    D_00389E18 = i;
    if (i < 4) {
        D_003BEB50[i] = D_003BEB00;
        return;
    }
    D_00389E18 = i - 1;
}
