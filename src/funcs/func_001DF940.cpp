extern "C" int func_001DED40(int id);
extern "C" int func_001DEDE0(int id, int a);
extern "C" bool func_001E3AD0(int voice, float l, float r, float pitch);

extern "C" bool func_001DF940(int id, float* vol, float pitch)
{
    if (func_001DED40(id))
        return false;
    int v = func_001DEDE0(id, 1);
    if (v >= 0)
        return func_001E3AD0(v, vol[0], vol[1], pitch);
    return false;
}
