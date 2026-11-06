extern unsigned int* D_00394274;

void func_00164298(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim, unsigned int pre,
                   unsigned int eop, unsigned int nloop, unsigned int ext)
{
    union {
        float f;
        unsigned int u;
    } c;
    unsigned int count = nreg * nloop;
    c.f = (float)nreg * 1.1920929e-07f;
    unsigned int* p = D_00394274;
    p[0] = c.u | (eop << 15) | nloop;
    p[1] = (nreg << 28) | (flg << 26) | (prim << 15) | (pre << 14) | ext;
    p[2] = regs;
    p[3] = count;
    D_00394274 = p + 4;
}
