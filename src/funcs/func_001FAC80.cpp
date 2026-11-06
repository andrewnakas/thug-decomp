extern "C" unsigned int func_001FAB88(void* p, int bits);

extern "C" int func_001FAC80(void* p, int bits)
{
    long v = func_001FAB88(p, bits);
    if (v & (1 << (bits - 1)))
        v |= -(1 << bits);
    return v;
}
