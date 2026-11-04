extern "C" int func_001E3C58(int idx);
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" void* func_001126C0(void* a, void* b);
extern "C" void func_001E36D8(int idx, float z);
extern "C" int func_001E3548(int idx, float x, float y);
extern "C" int func_001E2E50(int a, void* p, int b);
extern int D_0038881C;
extern void* D_003F2CD4[];
extern int D_00351DF8[];

int Play_001E3868(void* a, int idx, float x, float y, float z)
{
    if (func_001E3C58(idx) != 1) return 0;
    if (D_0038881C || func_001E53A0(0x62DF9442, 0)) {
        if (!D_003F2CD4[0]) return 0;
        void* p = func_001126C0(a, D_003F2CD4[0]);
        if (p) {
            func_001E36D8(idx, z);
            func_001E3548(idx, x, y);
            return func_001E2E50(D_00351DF8[idx], p, 1);
        }
    }
    return 0;
}
