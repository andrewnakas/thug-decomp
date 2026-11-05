extern void* D_0039427C;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_310[];

extern "C" void func_001617A0(void* c);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);

static inline void Tag(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

extern "C" void func_00161650(void* ctx)
{
    if (D_0039427C != ctx) {
        func_001617A0(ctx);
    }
    Tag(0x70000000, 0);
    Add((unsigned short)D_00394280 | 0x3000000);
    Add(0x2000000);
    D_00394280 = 0;
    func_001645F8(1, 0, 0);
    unsigned int* p = D_00394274;
    p[0] = 1;
    p[1] = 1;
    p[2] = 0x60;
    D_00394274 = p + 3;
    func_001646D0(1);
    Add((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
    ((unsigned short*)D_00394278)[1] |= D_00394280 & 0x3FF;
}
