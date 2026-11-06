extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;

static inline void Tag_00161090(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add_00161090(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

void func_00161090(unsigned short* data, int n)
{
    Tag_00161090(0x50000000, (unsigned int)data);
    Add_00161090((unsigned short)D_00394280 | 0x3000000);
    Add_00161090(0x2000000);
    Add_00161090((unsigned short)n | 0x4000000);
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
    D_00394280 += data[1];
}
