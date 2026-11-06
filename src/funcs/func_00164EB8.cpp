extern unsigned char* D_00394274;
extern unsigned char* D_00394288;
extern unsigned int* D_003942E4;
extern unsigned int D_00394280;

static inline void Close_00164EB8(unsigned int eop, unsigned int n)
{
    *D_003942E4 |= (eop << 15) | n;
    D_003942E4[3] = n;
}

void func_00164EB8(unsigned int eop)
{
    int n = (D_00394274 - D_00394288 - 4) >> 4;
    D_00394288[2] = n;
    Close_00164EB8(eop, n - 1);
    D_00394280 += n;
}
