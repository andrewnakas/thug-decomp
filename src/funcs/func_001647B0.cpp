extern unsigned int* D_00394274;

static inline void Put_001647B0(long v)
{
    D_00394274[0] = (int)v;
    D_00394274[1] = (int)(v >> 32);
    D_00394274 += 2;
}

void func_001647B0(unsigned int reg, long data)
{
    Put_001647B0(data);
    Put_001647B0(reg);
}
