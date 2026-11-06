extern unsigned int* D_00394274;
extern unsigned int* D_00394288;
extern unsigned int* D_003942E4;
extern unsigned int D_00394280;

static inline unsigned int Unpack_00164E48(unsigned int addr, unsigned int flag, unsigned int cmd)
{
    return (flag << 15) | ((addr & 0x3FF) | cmd);
}

void func_00164E48(unsigned int eop, unsigned int prim)
{
    unsigned int* p = D_00394274;
    *p = 0x01000101;
    p++;
    D_00394288 = p;
    *p = Unpack_00164E48(D_00394280, eop, 0x6C000000);
    p++;
    D_003942E4 = p;
    *p = 0x34000000;
    p++;
    *p = prim | 0x10000000;
    p++;
    *p = 0xF;
    p += 2;
    D_00394274 = p;
}
