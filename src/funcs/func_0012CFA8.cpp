struct Mgr_0012CFA8;
extern Mgr_0012CFA8* D_00389A30;
extern int D_00389A34;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" Mgr_0012CFA8* func_0012D050(void* p);

extern "C" Mgr_0012CFA8* func_0012CFA8(int create)
{
    if (!D_00389A30 && create) {
        D_00389A30 = func_0012D050(func_00104760(0x678, 0, 1));
    }
    D_00389A34++;
    return D_00389A30;
}
