struct Net_002A9C80;
extern Net_002A9C80* D_00392068;
extern "C" int func_002A19A8(Net_002A9C80* n);
extern "C" int func_002A1A38(Net_002A9C80* n);
extern "C" int func_002A1968(Net_002A9C80* n);

extern "C" bool func_002A9C80()
{
    Net_002A9C80* n = D_00392068;
    if (!func_002A19A8(n))
        return false;
    if (!func_002A1A38(n))
        return false;
    return func_002A1968(n) == 1;
}
