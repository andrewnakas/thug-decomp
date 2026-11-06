struct Rgba_00147F08 {
    unsigned char r, g, b, a;
};

struct Pal_00147F08 {
    char pad[0x14];
    Rgba_00147F08* m14;
};

struct Img_00147F08 {
    char pad[0x10];
    unsigned char m10;
    char pad11[0xB];
    Pal_00147F08* m1C;
    unsigned char Nearest(const Rgba_00147F08* c);
};

unsigned char Img_00147F08::Nearest(const Rgba_00147F08* c)
{
    int n = 1 << m10;
    Rgba_00147F08* p = m1C->m14;
    int best = 0x7FFFFFFF;
    unsigned char idx = 0;
    for (int i = 0; i < n; i++) {
        int dr = p->r - c->r;
        int dg = p->g - c->g;
        int db = p->b - c->b;
        int da = p->a - c->a;
        int d = dr * dr + dg * dg + db * db + da * da * 2;
        p++;
        if (d < best) {
            best = d;
            idx = i;
        }
    }
    return idx;
}
