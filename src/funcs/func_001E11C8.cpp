extern "C" int func_001DED40(int a);
extern "C" int func_001DEDE0(int a, int b);

extern "C" bool func_001E11C8(int a)
{
    if (func_001DED40(a)) return false;
    if (func_001DEDE0(a, 0) > -1) return true;
    return false;
}
