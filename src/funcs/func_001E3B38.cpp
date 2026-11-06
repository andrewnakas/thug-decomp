extern int D_0038881C;
extern int D_003F2DDC[];
extern int D_0038E284;

extern "C" int func_001E3C08(int a);
extern "C" int func_001E53A0(unsigned int name, int b);
extern "C" int func_001126C0(int a, int b);
extern "C" int func_001E2E50(int a, int b, int c);

extern "C" int func_001E3B38(int a)
{
    if (func_001E3C08(a) != 1)
        return 0;
    if (!D_0038881C && !func_001E53A0(0x47AC7BA5, 0))
        return 0;
    if (!D_003F2DDC[0])
        return 0;
    int v = func_001126C0(a, D_003F2DDC[0]);
    if (!v)
        return 0;
    return func_001E2E50(D_0038E284, v, 0);
}
