struct Col_00147A70 {
    union {
        struct { unsigned char r, g, b, a; };
        unsigned int v;
    };
    Col_00147A70() {}
};

extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void func_001477C8(Col_00147A70 (*c)[2], Col_00147A70* src, unsigned short x, unsigned short y, unsigned short w, unsigned short h);

static inline unsigned int Blend(Col_00147A70 (*c)[2], const float* w)
{
    unsigned char out[4];
    out[0] = (int)(w[0] * c[0][0].r + w[1] * c[0][1].r + w[2] * c[1][0].r + w[3] * c[1][1].r);
    out[1] = (int)(w[0] * c[0][0].g + w[1] * c[0][1].g + w[2] * c[1][0].g + w[3] * c[1][1].g);
    out[2] = (int)(w[0] * c[0][0].b + w[1] * c[0][1].b + w[2] * c[1][0].b + w[3] * c[1][1].b);
    out[3] = (int)(w[0] * c[0][0].a + w[1] * c[0][1].a + w[2] * c[1][0].a + w[3] * c[1][1].a);
    return *(unsigned int*)out;
}

extern "C" void func_00147A70(Col_00147A70* src, unsigned short sw, unsigned short sh, unsigned int* dst, unsigned short dw, unsigned short dh, int bpp)
{
    float pos[2];
    float step[2];
    float frac[2];
    unsigned short ipos[2];
    func_003315B8(pos, 0, sizeof(pos));
    func_003315B8(frac, 0, sizeof(frac));
    func_003315B8(ipos, 0, sizeof(ipos));
    Col_00147A70 c[2][2];
    float w[4];
    step[0] = (float)sw / (float)dw;
    step[1] = (float)sh / (float)dh;
    for (int y = 0; y < dh; y++) {
        ipos[1] = (int)pos[1];
        frac[1] = pos[1] - (float)ipos[1];
        for (int x = 0; x < dw; x++) {
            ipos[0] = (int)pos[0];
            frac[0] = pos[0] - (float)ipos[0];
            w[0] = (1.0f - frac[0]) * (1.0f - frac[1]);
            w[1] = frac[0] * (1.0f - frac[1]);
            w[2] = (1.0f - frac[0]) * frac[1];
            w[3] = frac[0] * frac[1];
            func_001477C8(c, src, ipos[0], ipos[1], sw, sh);
            unsigned int* d = dst++;
            *d = Blend(c, w);
            pos[0] += step[0];
        }
        pos[0] = 0.0f;
        pos[1] += step[1];
    }
}
