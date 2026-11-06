extern "C" int func_0031B9A0(int a, int b);
extern int D_0038BB10;

void Stop_0016C2B0()
{
    if (D_0038BB10 >= 0) {
        func_0031B9A0(2, D_0038BB10);
        D_0038BB10 = -1;
    }
}
