typedef int qword __attribute__((mode(TI)));

struct Vec_0014B538 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

struct Rgba_0014B538 {
    unsigned char r, g, b, a;
    Rgba_0014B538(int r_, int g_, int b_, int a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct Blk_0014B538 {
    unsigned int m_mask;
    int pad[0x1B];
    Vec_0014B538 m_70;
};

extern Vec_0014B538 D_003DDA50;

class Obj_0014B538 {
public:
    char pad[0x1C];
    Blk_0014B538* m_blk;
    Rgba_0014B538 GetColor();
};

Rgba_0014B538 Obj_0014B538::GetColor()
{
    Blk_0014B538* b = m_blk;
    const Vec_0014B538* p;
    if (b->m_mask & 1)
        p = &b->m_70;
    else
        p = &D_003DDA50;
    Vec_0014B538 v = *p;
    unsigned char r = (int)v.f.x;
    Rgba_0014B538 c(r, (unsigned int)v.f.y, (unsigned int)v.f.z, 0);
    return c;
}
