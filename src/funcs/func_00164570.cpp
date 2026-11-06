extern unsigned int* D_00394274;
extern unsigned int* D_003942E4;

static inline unsigned int Count_00164570()
{
    unsigned int* p = D_003942E4;
    unsigned int b = ((unsigned char*)p)[7];
    unsigned int nreg = b >> 4;
    if (((b >> 2) & 3) == 2)
        return ((char*)D_00394274 - (char*)p - 16) / 16;
    return (unsigned int)((char*)D_00394274 - (char*)p - 16) / (nreg << 4);
}

void func_00164570(unsigned int eop)
{
    unsigned int n = Count_00164570();
    *D_003942E4 |= (eop << 15) | n;
}
