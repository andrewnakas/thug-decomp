/* fuzzy: 77.8 */
extern unsigned int* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_0039429C;
extern char D_3A8[];
extern "C" void func_00164298(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim, unsigned int pre,
                              unsigned int eop, unsigned int nloop, unsigned int ext);

static inline void Add_00167068(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline unsigned int Unpack_00167068(unsigned short addr, unsigned int cmd)
{
    return (addr & 0x3FF) | cmd;
}

struct Obj_00167068 {
    char pad0[0x50];
    unsigned int m50[16];
    void Fn();
};

extern "C" void func_00167A50(Obj_00167068* self);

void Obj_00167068::Fn()
{
    D_00394280 = 0;
    unsigned int* saved = D_00394274;
    D_00394274 = m50;
    Add_00167068(0x20000000);
    Add_00167068(0);
    Add_00167068(0x01000101);
    D_0039429C = 1;
    Add_00167068((unsigned short)D_00394280 & 0x3FF | 0x6C11C000);
    D_00394290 = 0x11;
    func_00164298(0xF, 1, 0, 0, 0, 0, 0x10, (unsigned int)D_3A8 >> 3);
    m50[0] |= 1;
    func_00167A50(this);
    D_00394274 = saved;
}
