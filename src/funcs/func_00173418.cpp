struct Ctx_00173418 {
    char pad0[0x138];
    long m138;
    long m140;
};

struct Obj_00173418 {
    char pad0[0x10];
    long* m10;
    char pad14[8];
    Ctx_00173418* m1C;
    char pad20[0x14];
    unsigned int m34;
};

extern Ctx_00173418* D_0038BDC0;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_4C0[];
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00164408(int a, int b, int c, int d, int e, unsigned int f);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

extern "C" void func_00173418(Obj_00173418* obj)
{
    Ctx_00173418* ctx = D_0038BDC0;
    if (!ctx) {
        ctx = obj->m1C;
    }
    int one = 1;
    unsigned int unpack = 0x6C000000;
    Tag(0x10000000, 0);
    D_00394294 = D_00394280;
    func_001645F8(0, 0, 0);
    Reg(*obj->m10, 0x40);
    Reg(ctx->m138, 6);
    Reg(ctx->m140, 0x14);
    Reg(0x44, 0x42);
    Reg(one, 0x46);
    Reg(obj->m34, one);
    func_001646D0(0);
    Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C014000);
    D_00394290 = one;
    func_00164408(0x53, 2, 0, 0x156, 1, (unsigned int)D_4C0 >> 3);
    D_00394284 = 0x20;
    D_00394288 = D_00394274;
    D_0039428C = 4;
    Put((((unsigned short)D_00394280 + 1) & 0x3FF) | unpack);
}
