extern int D_0038E120;
extern "C" int func_001DED20(void* p);
extern "C" int func_001E3E30(void* p);

extern "C" int func_001E1060(void* p)
{
    if (func_001DED20(p))
        return 0;
    int r = func_001E3E30(p);
    D_0038E120 = r;
    return r;
}
