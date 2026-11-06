extern "C" int func_001DED40();
extern "C" int func_001DEDE0(void* p, int v);
extern "C" bool func_001E36D8(float f, int h);

extern "C" int func_001DF0A8(void* p, float f)
{
    if (func_001DED40())
        return 1;
    int h = func_001DEDE0(p, 1);
    if (h >= 0) {
        func_001E36D8(f, h);
        return 1;
    }
    return 0;
}
