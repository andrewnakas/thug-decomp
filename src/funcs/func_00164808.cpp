extern unsigned int* D_00394274;

static inline void Put_00164808(long v)
{
    D_00394274[0] = (int)v;
    D_00394274[1] = (int)(v >> 32);
    D_00394274 += 2;
}

unsigned int* func_00164808(unsigned int reg, long data)
{
    unsigned int* p = D_00394274;
    Put_00164808(data);
    Put_00164808(reg);
    return p;
}
