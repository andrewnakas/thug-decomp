/* fuzzy: 65.8 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0016C6C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

static inline void Copy_0016C6C8(Vec_0016C6C8* d, const Vec_0016C6C8* s)
{
    *(qword*)d = *(const qword*)s;
}

static inline void Sub_0016C6C8(Vec_0016C6C8* r, const Vec_0016C6C8* a, const Vec_0016C6C8* b)
{
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
    r->w = a->w - b->w;
}

struct Quad_0016C6C8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Vec_0016C6C8 p[4];
    Vec_0016C6C8 n;
};

extern Quad_0016C6C8 D_003DDAA0[];
extern int D_0038BC14;
extern int D_0038BC10;

extern "C" void func_003233B8(Vec_0016C6C8* d, Vec_0016C6C8* s);

extern "C" void func_0016C6C8(Vec_0016C6C8* a, Vec_0016C6C8* b, Vec_0016C6C8* c, Vec_0016C6C8* d, int flags)
{
    D_003DDAA0[D_0038BC14].m0 = 0;
    D_003DDAA0[D_0038BC14].m4 = 1;
    D_003DDAA0[D_0038BC14].m8 = flags;
    Copy_0016C6C8(&D_003DDAA0[D_0038BC14].p[0], a);
    Copy_0016C6C8(&D_003DDAA0[D_0038BC14].p[1], b);
    Copy_0016C6C8(&D_003DDAA0[D_0038BC14].p[2], c);
    Copy_0016C6C8(&D_003DDAA0[D_0038BC14].p[3], d);
    Vec_0016C6C8 n;
    Vec_0016C6C8 e1;
    Vec_0016C6C8 e2;
    Sub_0016C6C8(&e1, b, a);
    Sub_0016C6C8(&e2, d, a);
    n.x = e1.y * e2.z - e1.z * e2.y;
    n.y = e1.z * e2.x - e1.x * e2.z;
    n.z = e1.x * e2.y - e1.y * e2.x;
    n.w = 0.0f;
    Copy_0016C6C8(&D_003DDAA0[D_0038BC14].n, &n);
    func_003233B8(&D_003DDAA0[D_0038BC14].n, &D_003DDAA0[D_0038BC14].n);
    D_0038BC10 = 0;
    D_0038BC14++;
}
