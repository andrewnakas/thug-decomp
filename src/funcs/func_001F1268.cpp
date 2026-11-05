extern int D_00351EB0[];

extern "C" bool func_001F1268(int a, int b)
{
    if (a == b) return true;
    return D_00351EB0[a] <= D_00351EB0[b];
}
