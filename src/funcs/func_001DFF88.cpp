extern "C" bool func_001DED20();
extern "C" void func_001E3CD8(int a, int b);

extern int D_0038E160;
extern int D_0038E164;

extern "C" void func_001DFF88(int mode)
{
    if (func_001DED20())
        return;
    switch (mode) {
    case -1:
        if (!D_0038E164)
            func_001DFF88(0);
        break;
    case 1:
        D_0038E164 = D_0038E160;
        D_0038E160 = mode;
        func_001E3CD8(1, 1);
        break;
    case 0:
        D_0038E160 = 0;
        func_001E3CD8(0, 1);
        break;
    }
}
