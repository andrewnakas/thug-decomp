/* fuzzy: 90.3 */
struct Box_001608D8 {
    unsigned char lo[4];
    unsigned char hi[4];
};

struct Quant_001608D8 {
    Box_001608D8* m0;
    float* m4;
    void* m8;
};

struct Sum_001608D8 {
    float n;
    float c[4];
};

extern "C" int func_00160858(void* hist, int a);
extern "C" float func_00160108(void* hist, Box_001608D8* b);
extern "C" int func_001606A8(void* hist, Box_001608D8* a, Box_001608D8* b);
extern "C" void func_0015FE20(int i, void* hist, Box_001608D8* b);
extern "C" void func_001600A0(Sum_001608D8* s, void* hist, Box_001608D8* b);

extern "C" int func_001608D8(unsigned char* out, int max, Quant_001608D8* q)
{
    int i = 1;
    int n = max;
    int cnt = func_00160858(q->m8, 5);
    if (cnt < n) n = cnt;
    q->m0[0].lo[0] = 0;
    q->m0[0].lo[1] = 0;
    q->m0[0].lo[2] = 0;
    q->m0[0].lo[3] = 0;
    q->m0[0].hi[0] = 0x20;
    q->m0[0].hi[1] = 0x20;
    q->m0[0].hi[2] = 0x20;
    q->m0[0].hi[3] = 0x20;
    q->m4[0] = func_00160108(q->m8, q->m0);
    int best;
    int j;
    for (; i < n; i++) {
        best = -1;
        float bv = 0.0f;
        for (j = 0; j < i; j++) {
            if (bv < q->m4[j]) {
                bv = q->m4[j];
                best = j;
            }
        }
        if (best == -1) break;
        if (func_001606A8(q->m8, &q->m0[best], &q->m0[i])) {
            q->m4[best] = func_00160108(q->m8, &q->m0[best]);
            q->m4[i] = func_00160108(q->m8, &q->m0[i]);
        } else {
            q->m4[best] = 0.0f;
            i--;
        }
    }
    for (j = 0; j < max; j++) {
        unsigned char* p = &out[j * 4];
        if (j < n) {
            func_0015FE20(j, q->m8, &q->m0[j]);
            Sum_001608D8 s;
            func_001600A0(&s, q->m8, &q->m0[j]);
            float k = (0.0f < s.n) ? 255.9999f / s.n : 0.0f;
            p[0] = (int)(s.c[0] * k);
            p[1] = (int)(s.c[1] * k);
            p[2] = (int)(s.c[2] * k);
            p[3] = (int)(s.c[3] * k);
        } else {
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
        }
    }
    return n;
}
