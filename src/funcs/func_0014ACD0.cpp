typedef int qword __attribute__((mode(TI)));

struct Rgba_0014ACD0 {
    unsigned char r, g, b, a;
};

struct Tab_0014ACD0 {
    char pad[0x30];
    Rgba_0014ACD0 col[1];
};

struct Vec_0014ACD0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

extern Tab_0014ACD0 D_003BEB00;
extern Vec_0014ACD0 D_003DDA20[];

extern "C" bool func_0014ACD0(int i)
{
    Vec_0014ACD0 v;
    v.x = D_003BEB00.col[i].r;
    v.y = D_003BEB00.col[i].g;
    v.z = D_003BEB00.col[i].b;
    v.w = 0.0f;
    D_003DDA20[i] = v;
    return true;
}
