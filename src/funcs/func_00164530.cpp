extern unsigned int* D_00394274;
extern unsigned int* D_003942E4;

void func_00164530(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim, unsigned int pre)
{
    unsigned int* p = D_00394274;
    D_003942E4 = p;
    p[0] = 0;
    p[1] = (nreg << 28) | (flg << 26) | (prim << 15) | (pre << 14);
    p[2] = regs;
    p[3] = 0;
    D_00394274 = p + 4;
}
