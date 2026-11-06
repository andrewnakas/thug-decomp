extern unsigned int D_003940E8[2];
extern unsigned int D_003940F0[2];
extern "C" unsigned int func_001E2338(int pad);

extern "C" unsigned int func_001E2170(int pad)
{
    return (func_001E2338(pad) & ~D_003940E8[pad]) | ~D_003940F0[pad];
}
