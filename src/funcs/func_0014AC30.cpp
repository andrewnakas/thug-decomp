typedef int qword __attribute__((mode(TI)));

struct Vec_0014AC30 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

struct Rgba_0014AC30 {
    unsigned char r, g, b, a;
    Rgba_0014AC30(int r_, int g_, int b_, int a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern Vec_0014AC30 D_003DDA50;

Rgba_0014AC30 GetColor_0014AC30()
{
    Vec_0014AC30 v = D_003DDA50;
    Rgba_0014AC30 c((int)v.f.x, (int)v.f.y, (int)v.f.z, 0x80);
    return c;
}
