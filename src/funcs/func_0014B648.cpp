typedef int qword __attribute__((mode(TI)));

struct Rgba_0014B648 {
    unsigned char r, g, b, a;
};

struct Vec_0014B648 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Sub_0014B648 {
    unsigned int m0;
    char pad[0x3C];
    Vec_0014B648 m40[4];
    Vec_0014B648 m80[4];
    Vec_0014B648* Base(int i) { return &m40[i]; }
};

struct Menu_0014B648 {
    char pad[0x1C];
    Sub_0014B648* m1C;
    bool SetColor(int i, const Rgba_0014B648* c);
};

bool Menu_0014B648::SetColor(int i, const Rgba_0014B648* c)
{
    Vec_0014B648 v;
    v.x = c->r;
    v.y = c->g;
    v.z = c->b;
    v.w = 0.0f;
    Sub_0014B648* s = m1C;
    int mask = 0x20 << i;
    s->m40[i] = v;
    if (!(s->m0 & mask)) s->Base(i)[4] = v;
    return true;
}
