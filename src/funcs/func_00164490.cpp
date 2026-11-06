extern unsigned int* D_003942E4;
extern unsigned int D_00394290;
extern unsigned int D_00394280;

void func_00164490(unsigned int eop)
{
    unsigned int* p = D_003942E4;
    unsigned int n = D_00394290;
    *p |= (eop << 15) | (n / (((unsigned char*)p)[7] >> 4));
    D_003942E4[3] = n;
    D_00394280 += D_00394290 + 1;
}
