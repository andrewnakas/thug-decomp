extern int D_00394094;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern int D_0039429C;
extern char D_280[];

static inline void Tag(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Tag3(unsigned int qwc, unsigned int id, unsigned int addr)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = (id << 28) | qwc;
    p[1] = addr;
    D_00394274 = p + 2;
}

static inline void Add(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline void StCycl(int cl, int wl)
{
    Add(0x01000000 | (wl << 8) | cl);
    D_0039429C = cl;
}

struct Ctx_001614C8 {
    char pad0[0x18];
    unsigned int* start[4];
    int used[4];
    int m38;
    unsigned int* m3C;
    void Begin();
};

void Ctx_001614C8::Begin()
{
    used[D_00394094] = 0;
    start[D_00394094] = D_00394274;
    Tag3(0, 1, 0xFF000000);
    Add(0x11000000);
    Add(0x20000000);
    Add(0);
    Add(0x05000000);
    StCycl(1, 1);
    Add(0x03000000);
    Add(0x02000000);
    Add((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
    Tag(0x20000000, 0);
    Add(0);
    Add(0);
    m38 = 0;
    m3C = D_00394278;
}
