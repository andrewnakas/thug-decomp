extern int D_00393E8C;
extern int D_00393E90;
extern int D_00393E94;

extern "C" int func_00100080(int range)
{
    int r = D_00393E8C * D_00393E90 + D_00393E94;
    D_00393E8C = r;
    D_00393E90 = (D_00393E90 ^ r) + (r >> 4);
    D_00393E94 += 0xEFEFEFF0 + (r >> 3);
    return ((r & 0xFFFF) * range) >> 16;
}
