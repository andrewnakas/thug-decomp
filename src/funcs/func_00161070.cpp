extern unsigned short* D_003942A8;
extern unsigned short D_00394280;

unsigned short* Set_00161070()
{
    D_003942A8[1] |= D_00394280 & 0x3FF;
    return D_003942A8;
}
