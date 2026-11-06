extern int D_0038881C;
extern int D_003F2CD4[];
extern void* D_00351DF8[];

extern "C" int func_001E3C58(int ch);
extern "C" int func_001E53A0(unsigned int crc, int a);
extern "C" int func_001126C0(int a, int b);
extern "C" int func_001E2E50(void* a, int p, int b);

extern "C" int func_001E39E8(int name, int ch)
{
    if (func_001E3C58(ch) != 1)
        return 0;
    if (!D_0038881C && !func_001E53A0(0x62DF9442, 0))
        return 0;
    if (!D_003F2CD4[0])
        return 0;
    int p = func_001126C0(name, D_003F2CD4[0]);
    if (!p)
        return 0;
    return func_001E2E50(D_00351DF8[ch], p, 0);
}
