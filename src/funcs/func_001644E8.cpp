extern unsigned int* D_00394274;

void func_001644E8(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim, unsigned int pre,
                   unsigned int eop, unsigned int nloop)
{
    unsigned int* p = D_00394274;
    p[0] = (eop << 15) | nloop;
    p[1] = (nreg << 28) | (flg << 26) | (prim << 15) | (pre << 14);
    p[2] = regs;
    p[3] = 0;
    D_00394274 = p + 4;
}
