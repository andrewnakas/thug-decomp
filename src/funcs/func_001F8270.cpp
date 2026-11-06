struct Param_001F8270 {
    int m0;
    void* m4;
    int m8;
    int mC;
};
extern "C" void func_0031BF20(int a);
extern "C" int func_0031C060(Param_001F8270* p, int n);
extern "C" int func_0031C040(int id);

extern "C" int func_001F8270(void* dst, int a, int size)
{
    if (size <= 0)
        return 0;
    Param_001F8270 p;
    p.m0 = a;
    p.m4 = dst;
    p.m8 = size;
    p.mC = 0;
    func_0031BF20(0);
    int id = func_0031C060(&p, 1);
    while (func_0031C040(id) >= 0)
        ;
    return size;
}
