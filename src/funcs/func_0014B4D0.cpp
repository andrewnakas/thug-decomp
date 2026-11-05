typedef int qword __attribute__((mode(TI)));

struct Rgba_0014B4D0 {
    unsigned char r, g, b, a;
};

struct Vec_0014B4D0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Sub_0014B4D0 {
    unsigned int m0;
    char pad[0x6C];
    Vec_0014B4D0 m70;
    char pad80[0x30];
    Vec_0014B4D0 mB0;
};

struct Menu_0014B4D0 {
    char pad[0x1C];
    Sub_0014B4D0* m1C;
    bool SetColor(const Rgba_0014B4D0* c);
};

bool Menu_0014B4D0::SetColor(const Rgba_0014B4D0* c)
{
    Vec_0014B4D0 v;
    v.x = c->r;
    v.y = c->g;
    v.z = c->b;
    v.w = 0.0f;
    Sub_0014B4D0* s = m1C;
    s->m70 = v;
    if (!(s->m0 & 0x10)) s->mB0 = v;
    return true;
}
