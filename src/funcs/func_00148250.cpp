struct Rgba_00148250 {
    unsigned char r, g, b, a;
};

struct Cell_00148250 {
    unsigned short start;
    unsigned char count;
    unsigned char pad;
};

struct Pal_00148250 {
    char pad[0x10];
    unsigned char* m_pixels;
    Rgba_00148250* m_palette;
};

extern int D_00393F14;
extern Cell_00148250 D_003C7DC8[][8][8][8];
extern unsigned char* D_0038A8C4;

class B_00148250 {
public:
    int m0;
    int m4;
    virtual void v0();
};

class C_00148250 : public B_00148250 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m_bits;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Pal_00148250* m1C;
    virtual void v0();
    int Search(Rgba_00148250* c);
    int Lookup(Rgba_00148250* c);
};

int C_00148250::Lookup(Rgba_00148250* c)
{
    int shift = m_bits - 3;
    int r = c->r >> shift;
    int g = c->g >> shift;
    int b = c->b >> shift;
    int a;
    if (D_00393F14) {
        a = c->a >> shift;
    } else {
        a = 0;
    }
    Cell_00148250* cell = &D_003C7DC8[r][g][b][a];
    if (!cell->count) {
        Rgba_00148250 tmp = *c;
        return Search(&tmp);
    }
    Rgba_00148250* pal = m1C->m_palette;
    int best = 0x7FFFFFFF;
    int idx = 0;
    unsigned char* list = D_0038A8C4 + cell->start;
    for (int i = 0; i < cell->count; i++) {
        int k = *list;
        Rgba_00148250* p = &pal[k];
        int dr = p->r - c->r;
        int dg = p->g - c->g;
        int db = p->b - c->b;
        int da = p->a - c->a;
        int d = dr * dr + dg * dg + db * db + da * da * 2;
        if (d < best) {
            best = d;
            idx = k;
        }
        list++;
    }
    return idx;
}
