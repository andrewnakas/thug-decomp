extern "C" void func_00103EB8(int quarter, int* x, int* y, int* z)
{
    int t;
    switch (quarter) {
    case 0:
        break;
    case 1:
        t = *x;
        *x = *z;
        *z = -t;
        break;
    case 2:
        *x = -*x;
        *z = -*z;
        break;
    case 3:
        t = *x;
        *x = -*z;
        *z = t;
        break;
    }
}
