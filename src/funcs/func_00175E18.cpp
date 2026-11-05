struct Obj_00175E18 {
    int m0;
    unsigned int m4;
};

extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern unsigned int D_0039429C;
extern unsigned int D_003942F0;
extern int D_00394004;
extern unsigned int D_00394008;
extern int D_0039400C;
extern unsigned int D_00394010;
extern int D_00394014;
extern unsigned int D_00394018;
extern unsigned int D_0039401C;
extern int D_0038BF80;
extern char D_290[];
extern char D_310[];
extern "C" void func_00175C70(int a);
extern "C" void func_00164298(int a, int b, int c, int d, int e, int f, int g, unsigned int h);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00175BE0(int a, unsigned int count, int b, int c, int d);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

extern "C" void func_00175E18(Obj_00175E18* obj)
{
    if (D_0039401C != D_00394018) {
        return;
    }
    if ((obj->m4 & 0x10) && 0x300 - ((D_00394294 + D_00394290 * D_0039429C + 1) & 0x3FF) < D_003942F0) {
        func_00175C70(0);
        Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C01C000);
        D_00394290 = 1;
        func_00164298(0, 0, 0, 0, 0, 1, 0, (unsigned int)D_290 >> 3);
        D_00394280 = 0;
        Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = D_00394280;
        Put(0x11000000);
    } else {
        func_00175C70(1);
        Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = D_00394280;
        Put(0x11000000);
    }
    D_00394010 -= D_0039401C;
    D_00394018 = D_003942F0 / D_00394008;
    if (D_00394010 < D_00394018) {
        D_00394018 = D_00394010;
    }
    func_001645F8(1, 0, 0);
    Reg(0, 0x7F);
    func_001646D0(0);
    func_00175BE0(D_00394004, D_00394008, D_0039400C, 1, D_00394014);
    D_0039401C = 0;
    D_0038BF80 = 1;
}
