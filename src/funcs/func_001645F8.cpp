extern unsigned int* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned int* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_0039429C;
extern char D_4C0[];
extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d);

static inline void Add_001645F8(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline void StCycl_001645F8(int cl, int wl)
{
    Add_001645F8(0x01000000 | (wl << 8) | cl);
    D_0039429C = cl;
}

static inline unsigned int Unpack_001645F8(unsigned short addr, unsigned short flag, unsigned int cmd)
{
    return (unsigned short)((flag << 15) | 0x4000 | (addr & 0x3FF)) | cmd;
}

extern "C" void func_001645F8(unsigned short flag, int b, int c)
{
    StCycl_001645F8(1, 1);
    Add_001645F8(Unpack_001645F8(D_00394280, flag, 0x6C010000));
    D_00394290 = 1;
    func_00164328(0xE, 1, 0, b, c, (unsigned int)D_4C0 >> 3);
    D_00394284 = 0x20;
    D_0039428C = 3;
    D_00394288 = D_00394274;
    Add_001645F8(Unpack_001645F8(D_00394280 + 1, flag, 0x68000000));
}
