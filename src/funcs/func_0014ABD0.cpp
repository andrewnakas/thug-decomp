typedef int qword __attribute__((mode(TI)));

struct Rgba_0014ABD0 {
    unsigned char r, g, b, a;
};

struct Vec_0014ABD0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

extern Rgba_0014ABD0 D_003BEB00[];
extern Vec_0014ABD0 D_003DDA50;

extern "C" bool func_0014ABD0()
{
    Vec_0014ABD0 v;
    v.x = D_003BEB00[0].r;
    v.y = D_003BEB00[0].g;
    v.z = D_003BEB00[0].b;
    v.w = 0.0f;
    D_003DDA50 = v;
    return true;
}
