extern unsigned int* D_00394274;
extern unsigned int* D_003942E4;

extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d)
{
    float f = (float)n * (1.0f / 8388608.0f);
    unsigned int bits = (n << 28) | (a << 26) | (b << 15) | (c << 14) | d;
    unsigned int* p = D_00394274;
    D_003942E4 = p;
    p[0] = *(unsigned int*)&f;
    p[1] = bits;
    p[2] = addr;
    p[3] = 0;
    D_00394274 = p + 4;
}
