struct Rgba_0015FA80 {
    unsigned char r, g, b, a;
};

struct Col_0015FA80 {
    float r, g, b, a;
};

struct Bin_0015FA80 {
    float weight;
    float r, g, b, a;
    float sq;
};

struct Quant_0015FA80 {
    char pad0[8];
    void* m8;
    void Add(Rgba_0015FA80* cols, int w, int h, int bits, float weight);
};

extern "C" int func_0015F958(Rgba_0015FA80* c);
extern "C" Bin_0015FA80* func_0015F9C8(Quant_0015FA80* self, void* tree, int key, int depth);

void Quant_0015FA80::Add(Rgba_0015FA80* cols, int w, int h, int bits, float weight)
{
    int n = w * h;
    switch (bits / 8) {
    case 3:
        break;
    case 4: {
        Rgba_0015FA80* p = cols;
        for (int i = 0; i < n; i++) {
            Rgba_0015FA80 c = *p;
            int key = func_0015F958(&c);
            p++;
            Bin_0015FA80* b = func_0015F9C8(this, m8, key, 5);
            Col_0015FA80 f;
            f.r = c.r * 0.00392156886f;
            f.g = c.g * 0.00392156886f;
            f.b = c.b * 0.00392156886f;
            f.a = c.a * 0.00392156886f;
            b->weight += weight;
            f.r *= weight;
            f.g *= weight;
            f.b *= weight;
            f.a *= weight;
            b->r += f.r;
            b->g += f.g;
            b->b += f.b;
            b->a += f.a;
            b->sq += weight * (f.r * f.r + f.g * f.g + f.b * f.b + f.a * f.a);
        }
        break;
    }
    }
}
