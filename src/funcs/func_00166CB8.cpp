extern "C" int func_00165AC8(int v);
extern int D_0034EA10[][10];

int func_00166CB8(int unused, int a, int b)
{
    int i = func_00165AC8(a) - 1;
    int j = func_00165AC8(b) - 1;
    return D_0034EA10[j][i];
}
