extern unsigned int* D_003942E4;
extern unsigned int D_00394290;
extern unsigned int D_0039429C;
extern unsigned int D_00394280;

void func_001643B8(unsigned int eop)
{
    unsigned int* p = D_003942E4;
    unsigned int n = D_00394290;
    unsigned int m = D_0039429C;
    *p |= (eop << 15) | n;
    D_003942E4[3] = n * m;
    D_00394280 += D_00394290 * D_0039429C + 1;
}
