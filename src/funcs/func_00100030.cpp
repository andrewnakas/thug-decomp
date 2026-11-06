extern int D_00393E80;
extern int D_00393E84;
extern int D_00393E88;

extern "C" int func_00100030(int range)
{
    int a = D_00393E80 * D_00393E84 + D_00393E88;
    D_00393E80 = a;
    D_00393E84 = (D_00393E84 ^ a) + (a >> 4);
    D_00393E88 += 0xEFEFEFF0 + (a >> 3);
    return ((a & 0xFFFF) * range) >> 16;
}
