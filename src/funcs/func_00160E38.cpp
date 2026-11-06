extern unsigned char* D_00394274;
extern int D_003942A4;
extern unsigned char* D_003942A8;
extern int D_00394294;
extern int D_00394280;

void func_00160E38(int type)
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 15) & ~15);
    while (D_00394274 < end)
        *D_00394274++ = 0;
    D_003942A4 = type;
    D_003942A8 = D_00394274;
    D_00394294 = 0;
    D_00394280 = 0;
}
