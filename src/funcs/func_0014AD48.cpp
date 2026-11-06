typedef int qword __attribute__((mode(TI)));

struct Vec_0014AD48 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Color_0014AD48 {
    unsigned char r, g, b, a;
};

extern Vec_0014AD48 D_003DDA20[];

extern "C" Color_0014AD48* func_0014AD48(Color_0014AD48* out, int i)
{
    Vec_0014AD48 v = D_003DDA20[i];
    Color_0014AD48 c;
    c.a = 0x80;
    c.r = (int)v.x;
    c.g = (int)v.y;
    c.b = (int)v.z;
    *out = c;
    return out;
}
