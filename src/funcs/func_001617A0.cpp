struct Ctx_001617A0 {
    char pad0[0x38];
    unsigned int m38;
    unsigned int* m3C;
};

extern Ctx_001617A0* D_0039427C;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;

static inline void Tag_001617A0(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add_001617A0(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

void func_001617A0(Ctx_001617A0* c)
{
    if (D_0039427C) {
        unsigned int type = *D_00394278 >> 28;
        if (type == 5 || type == 3) {
            Tag_001617A0(0x20000000, 0);
            Add_001617A0(0);
            Add_001617A0(0);
        } else if (type == 1) {
            ((unsigned char*)D_00394278)[3] = 0x20;
        }
        D_0039427C->m38 = D_00394280;
        D_0039427C->m3C = D_00394278;
    }
    D_0039427C = c;
    if (c) {
        D_00394280 = c->m38;
        D_00394278 = c->m3C;
        D_00394278[1] = (unsigned int)D_00394274;
    }
}
