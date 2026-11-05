extern int D_0038E150;
extern "C" int func_001DED20();
extern "C" void func_001E3958(int v);
extern "C" int func_001DF418(void* p);

int func_001DF9B0(void* p)
{
    if (func_001DED20())
        return 0;
    func_001E3958(0);
    int r = func_001DF418(p);
    D_0038E150 = 2;
    return r;
}
