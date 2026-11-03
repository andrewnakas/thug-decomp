struct Img_00149500 {
    char pad[0xC];
    unsigned short w;
    unsigned short h;
    char pad10[0x24 - 0x10];
    unsigned char* m24;
    unsigned char* m28;
};

static inline float Max(float a, float b) { return a > b ? a : b; }
static inline float Min(float a, float b) { return a < b ? a : b; }

static inline void RGBtoHSV(float r, float g, float b, float* h, float* s, float* v)
{
    float mx = Max(r, Max(g, b));
    float mn = Min(r, Min(g, b));
    *v = mx;
    float delta = mx - mn;
    if (mx == 0.0f) {
        *s = 0.0f;
        *h = -1.0f;
        return;
    }
    *s = delta / mx;
    if (delta == 0.0f) return;
    if (r == mx) {
        *h = (g - b) / delta;
    } else if (g == mx) {
        *h = (b - r) / delta + 2.0f;
    } else {
        *h = (r - g) / delta + 4.0f;
    }
    *h *= 60.0f;
    if (*h < 0.0f) *h += 360.0f;
}

static inline void HSVtoRGB(float h, float s, float v, float* r, float* g, float* b)
{
    s = Min(s, 1.0f);
    v = Min(v, 1.0f);
    if (s == 0.0f) {
        *r = *g = *b = v;
        return;
    }
    h *= 0.01666666754f;
    int i = (int)h;
    float f = h - (float)i;
    float p = v * (1.0f - s);
    float q = v * (1.0f - s * f);
    float t = v * (1.0f - s * (1.0f - f));
    switch (i) {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}

extern "C" int func_00149500(Img_00149500* img, int useDst, float dh, float ds, float dv)
{
    unsigned char* src;
    unsigned char* dst = img->m28;
    if (!img->m24 || useDst) {
        src = dst;
    } else {
        src = img->m24;
    }
    int n = img->w * img->h;
    for (int i = 0; i < n; i++) {
        float h, s, v;
        RGBtoHSV(src[0] * 0.003921568859f, src[1] * 0.003921568859f, src[2] * 0.003921568859f, &h, &s, &v);
        h += dh;
        if (h > 360.0f) h -= 360.0f;
        float r, g, b;
        HSVtoRGB(h, s * ds, v * dv, &r, &g, &b);
        dst[0] = (int)(r * 255.0f + 0.5f);
        dst[1] = (int)(g * 255.0f + 0.5f);
        dst[2] = (int)(b * 255.0f + 0.5f);
        src += 4;
        dst += 4;
    }
    return 1;
}
