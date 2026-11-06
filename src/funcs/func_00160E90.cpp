extern unsigned char* D_00394274;
extern unsigned int D_003942A4;
extern unsigned char* D_003942A8;
extern int D_00394280;

long func_00160E90()
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 15) & ~15);
    while (D_00394274 < end)
        *D_00394274++ = 0;
    long tag = ((long)(int)D_003942A8 << 32) | ((unsigned long)D_003942A4 << 28) | (unsigned int)((D_00394280 & 0x3FF) << 16);
    if (D_003942A4 == 3)
        tag |= (int)(D_00394274 - D_003942A8) >> 4;
    return tag;
}
