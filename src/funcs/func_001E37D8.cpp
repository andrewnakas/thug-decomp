extern int D_0038881C;
extern int D_003F2DDC[4];
extern void* D_0038E284;

extern "C" int func_001E3C08();
extern "C" int func_001E53A0(unsigned int crc, int a);
extern "C" void func_0010FE68();
extern "C" void* func_001126C0(int id, int tbl);
extern "C" bool func_001E2E50(void* mgr, void* p, int a);

extern "C" bool func_001E37D8(int id)
{
    if (func_001E3C08() != 1)
        return false;
    if (!D_0038881C && !func_001E53A0(0x47AC7BA5, 0))
        return false;
    func_0010FE68();
    int tbl = D_003F2DDC[0];
    if (!tbl)
        return false;
    void* p = func_001126C0(id, tbl);
    if (!p)
        return false;
    return func_001E2E50(D_0038E284, p, 1);
}
