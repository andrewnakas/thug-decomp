/* fuzzy: 84.9 */
struct Tag_00161250 {
    unsigned int m0 : 16;
    unsigned int m2 : 16;
    float m4;
    unsigned int m8 : 16;
};

struct Pair_00161250 {
    float m_key;
    Tag_00161250* m_tag;
};

extern int D_003942B0;
extern int D_0039409C;
extern unsigned int D_00394280;
extern Tag_00161250* D_003E2718[];
extern "C" Tag_00161250* func_00161168(Tag_00161250* t, int a);
extern "C" int func_00161218(const void* a, const void* b);
extern "C" void func_00334658(void* base, int n, int size, int (*cmp)(const void*, const void*));

static inline unsigned int Id_00161250(Tag_00161250* t)
{
    return *(unsigned int*)t >> 28;
}

extern "C" Tag_00161250* func_00161250(Tag_00161250* t)
{
    Pair_00161250* marks[4];
    int i;
    D_003942B0 = 0;
    Pair_00161250* base = (Pair_00161250*)0x70000000;
    Pair_00161250* out = base;
    int nmarks = 0;
    Tag_00161250* last = 0;
    unsigned int id = Id_00161250(t);
    while (id != 7) {
        for (i = 0; i < D_0039409C; i++) {
            if (t == D_003E2718[i])
                marks[nmarks++] = out;
        }
        if (id == 1) {
            out->m_tag = t;
            out->m_key = t->m4;
            out++;
        }
        t = func_00161168(t, 0);
        id = Id_00161250(t);
    }
    Tag_00161250* end = t;
    int count = out - base;
    if (nmarks) {
        for (i = 0; i < nmarks - 1; i++)
            func_00334658(marks[i], marks[i + 1] - marks[i], 8, func_00161218);
        func_00334658(marks[i], out - marks[i], 8, func_00161218);
    }
    for (Pair_00161250* q = (Pair_00161250*)0x70000000; q < base + count; q++) {
        t = q->m_tag;
        do {
            last = t;
            t = func_00161168(last, 0);
        } while (Id_00161250(t) != 1 && Id_00161250(t) != 7);
        *(Tag_00161250**)&last->m4 = q[1].m_tag;
    }
    *(Tag_00161250**)&last->m4 = end;
    D_00394280 = 0;
    t = ((Pair_00161250*)0x70000000)->m_tag;
    unsigned int w = *(unsigned int*)t;
    while ((w >> 28) != 7) {
        if (w & 0x3FF0000) {
            unsigned short* h = (unsigned short*)t;
            h[4] &= 0xFC00;
            h[4] |= D_00394280;
            D_00394280 += h[1];
        }
        t = func_00161168(t, 0);
        w = *(unsigned int*)t;
    }
    return ((Pair_00161250*)0x70000000)->m_tag;
}
