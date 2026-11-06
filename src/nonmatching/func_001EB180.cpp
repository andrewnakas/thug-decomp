/* fuzzy: 96.4 */
struct Comp_001EB180 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x8 - 2];
    union {
        int i;
        float f;
    };
};

extern "C" float fabsf(float x);
extern "C" int func_001EC7A0(unsigned char* p);
extern "C" int func_00100080(int n);
extern "C" int func_00100030(int n);

static inline float ReadFloat_001EB180(unsigned char* p)
{
    union {
        int i;
        float f;
    } u;
    u.i = func_001EC7A0(p);
    return u.f;
}

static inline int Round_001EB180(float x)
{
    if (x < 0.0f) {
        return (int)(x - 0.1f);
    }
    return (int)(x + 0.1f);
}

extern "C" unsigned char* func_001EB180(unsigned char* p, Comp_001EB180* c, int r)
{
    p++;
    float a = ReadFloat_001EB180(p);
    p += 4;
    float b = ReadFloat_001EB180(p);
    p += 4;
    int ia = Round_001EB180(a);
    int ib = Round_001EB180(b);
    int type;
    bool whole = true;
    if (fabsf(a - (float)ia) > 1e-05f || fabsf(b - (float)ib) > 1e-05f) {
        whole = false;
    }
    if (whole) {
        if (ib < ia) {
            int t = ia;
            ia = ib;
            ib = t;
        }
        int v;
        if (r) {
            v = func_00100080(ib - ia + 1);
        } else {
            v = func_00100030(ib - ia + 1);
        }
        ia += v;
        c->i = ia;
        type = 1;
    } else {
        if (b < a) {
            float t = a;
            a = b;
            b = t;
        }
        int v;
        if (r) {
            v = func_00100080(0x7FF9);
        } else {
            v = func_00100030(0x7FF9);
        }
        c->f = a + (float)v * (b - a) * 3.052503234e-05f;
        type = 2;
    }
    c->m_type = type;
    return p;
}
