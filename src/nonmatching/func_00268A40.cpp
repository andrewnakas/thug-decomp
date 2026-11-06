/* fuzzy: 96.9 */
// NEAR MISS (same size 0x5F4, 21 words; "Starting overlapping rail removal"). Left: (1) bbox test pointer regs v0/v1 swapped and the game materialises &b->m10/&b->m20 one block later (after the first direct-offset compare) - here local Vec* bl/bh give the pointer form but too early; (2) final sum: game computes nearX+nearZ (x in v0) then n + that; "n + (nx + nz)" puts x in v1, "n + nx + nz" (this file) gets regs right but adds n first. Idioms that fixed the rest: int n = 0 hoisted before the e/f normalise calls (s2 saved), Gap inline computes the two fabsf first and span = hi - lo as its own statement, Vec 4-float ctor so operator- constructs in place.
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);
extern "C" float fabsf(float);

struct Vec_00268A40 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00268A40() {}
    Vec_00268A40(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_00268A40 operator-(const Vec_00268A40& a, const Vec_00268A40& b) { return Vec_00268A40(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }

extern "C" void func_003233B8(Vec_00268A40* d, Vec_00268A40* s);
extern "C" Vec_00268A40* func_001016A8(Vec_00268A40* v, const Vec_00268A40* n);
static inline void Norm_00268A40(Vec_00268A40& v) { func_003233B8(&v, &v); }

struct Node_00268A40 {
    char pad0[0x10];
    Vec_00268A40 m10;
    Vec_00268A40 m20;
    Vec_00268A40 m30;
    char pad40[0x10];
    Node_00268A40* m50;
    char pad54[0xC];
};

extern char D_00376190[];
extern char D_003761B8[];
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_0026B460(Node_00268A40* n, int a);
extern "C" int func_001CB7B8(Node_00268A40* n, int a);

static inline bool Overlap_00268A40(const Vec_00268A40& lo1, const Vec_00268A40& hi1, const Vec_00268A40& lo2, const Vec_00268A40& hi2)
{
    return lo1[0] <= hi2[0] && lo2[0] <= hi1[0] && lo1[2] <= hi2[2] && lo2[2] <= hi1[2] && lo1[1] <= hi2[1] && lo2[1] <= hi1[1];
}

static inline float Gap_00268A40(float a0, float a1, float b0, float b1)
{
    float la = fabsf(a1 - a0);
    float lb = fabsf(b1 - b0);
    float lo = a0;
    if (a1 < lo) lo = a1;
    if (b0 < lo) lo = b0;
    if (b1 < lo) lo = b1;
    float hi = a0;
    if (hi < a1) hi = a1;
    if (hi < b0) hi = b0;
    if (hi < b1) hi = b1;
    float span = hi - lo;
    return la + lb - span;
}

static inline int Near_00268A40(float a, float b, float c, float d)
{
    return fabsf(a - b) < 6.0f && fabsf(b - c) < 6.0f && fabsf(c - d) < 6.0f;
}

struct Rail_00268A40 {
    char pad0[0x50];
    Node_00268A40* m50;
    char pad54[8];
    int m5C;
    void RemoveOverlaps();
};

void Rail_00268A40::RemoveOverlaps()
{
    func_00103F28(D_00376190);
    int removed = 0;
    for (int i = 0; i < m5C; i++) {
        Node_00268A40* a = &m50[i];
        if (!a->m50) continue;
        Vec_00268A40 pa = a->m30;
        Vec_00268A40 pb = a->m50->m30;
        Vec_00268A40 da = pb - pa;
        Norm_00268A40(da);
        Vec_00268A40 lo = a->m10;
        lo[0] -= 16.0f;
        lo[1] -= 16.0f;
        lo[2] -= 16.0f;
        Vec_00268A40 hi = a->m20;
        hi[0] += 16.0f;
        hi[1] += 16.0f;
        hi[2] += 16.0f;
        for (int j = i + 1; j < m5C && func_001CB7B8(a, 2); j++) {
            Node_00268A40* b = &m50[j];
            if (!b->m50) continue;
            Vec_00268A40* bl = &b->m10; Vec_00268A40* bh = &b->m20; if (bl->c[0] <= hi[0] && lo[0] <= bh->c[0] && bl->c[2] <= hi[2] && lo[2] <= bh->c[2] && bl->c[1] <= hi[1] && lo[1] <= bh->c[1]) {
                Vec_00268A40 qa = b->m30;
                Vec_00268A40 qb = b->m50->m30;
                Vec_00268A40 db = qb - qa;
                Norm_00268A40(db);
                float dot = da[0] * db[0] + da[1] * db[1] + da[2] * db[2];
                if (dot < -0.99f || 0.99f < dot) {
                    int n = 0;
                    Vec_00268A40 e = qa - pa;
                    Vec_00268A40 f = pb - pa;
                    Norm_00268A40(f);
                    Vec_00268A40 g = e;
                    func_001016A8(&g, &f);
                    if (sqrtf(g[0] * g[0] + g[1] * g[1] + g[2] * g[2]) < 6.0f) {
                        if (6.0f < Gap_00268A40(pa[0], pb[0], qa[0], qb[0])) n++;
                        if (6.0f < Gap_00268A40(pa[2], pb[2], qa[2], qb[2])) n++;
                        if (n + Near_00268A40(pa[0], pb[0], qa[0], qb[0]) + Near_00268A40(pa[2], pb[2], qa[2], qb[2]) >= 2) {
                            removed++;
                            if (a->m30[1] < b->m30[1])
                                func_0026B460(a, 2);
                            else
                                func_0026B460(b, 2);
                            break;
                        }
                    }
                }
            }
        }
    }
    func_00103F28(D_003761B8, removed);
}
