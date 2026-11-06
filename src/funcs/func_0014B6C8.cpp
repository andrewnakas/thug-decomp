typedef int qword __attribute__((mode(TI)));

struct Vec_0014B6C8 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

struct Rgba_0014B6C8 {
    unsigned char r, g, b, a;
    Rgba_0014B6C8(int r_, int g_, int b_, int a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct Blk_0014B6C8 {
    unsigned int m_mask;
    int pad[0xF];
    Vec_0014B6C8 m_vecs[3];
};

extern Vec_0014B6C8 D_003DDA20[];

class Obj_0014B6C8 {
public:
    char pad[0x1C];
    Blk_0014B6C8* m_blk;
    Rgba_0014B6C8 GetColor(int i);
};

Rgba_0014B6C8 Obj_0014B6C8::GetColor(int i)
{
    Blk_0014B6C8* b = m_blk;
    const Vec_0014B6C8* p;
    if (b->m_mask & (2 << i))
        p = &b->m_vecs[i];
    else
        p = &D_003DDA20[i];
    Vec_0014B6C8 v = *p;
    unsigned char r = (int)v.f.x;
    Rgba_0014B6C8 c(r, (unsigned int)v.f.y, (unsigned int)v.f.z, 0);
    return c;
}
