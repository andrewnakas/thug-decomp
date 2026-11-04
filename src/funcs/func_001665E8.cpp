extern "C" int func_00165AC8(int v);
extern int D_0034E6F0[][10];

int func_001665E8(int unused, int a, int b)
{
    int i = func_00165AC8(a) - 1;
    int j = func_00165AC8(b) - 1;
    return D_0034E6F0[j][i];
}
