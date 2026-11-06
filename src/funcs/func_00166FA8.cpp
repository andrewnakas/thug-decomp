extern unsigned int* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_0039429C;
extern char D_3A8[];
extern "C" void func_00164298(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim, unsigned int pre,
                              unsigned int eop, unsigned int nloop, unsigned int ext);

static inline void Add_00166FA8(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

struct Obj_00166FA8 {
    char pad0[0x50];
    unsigned int m50[16];
    void Fn();
};

void Obj_00166FA8::Fn()
{
    unsigned int* saved = D_00394274;
    D_00394274 = m50;
    D_00394280 = 0;
    Add_00166FA8(0x20000000);
    Add_00166FA8(0);
    Add_00166FA8(0x01000101);
    D_0039429C = 1;
    Add_00166FA8((unsigned short)D_00394280 & 0x3FF | 0x6C06C000);
    D_00394290 = 6;
    func_00164298(0xF, 1, 0, 0, 0, 0, 5, (unsigned int)D_3A8 >> 3);
    D_00394274 = saved;
}
