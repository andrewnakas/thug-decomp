struct Net_002D1FE0;
extern Net_002D1FE0* D_00392068;
extern "C" int func_002A39F8(Net_002D1FE0* n);

extern "C" int func_002D1FE0(int a, int mode)
{
    switch (mode) {
    case 0:
        return 0x10;
    case 1:
        return func_002A39F8(D_00392068);
    case 2:
    default:
        return 0;
    }
}
