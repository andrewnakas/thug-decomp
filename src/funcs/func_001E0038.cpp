extern int D_0038E168;
extern int D_0038E16C;
extern "C" int func_001DED40();
extern "C" void func_001E3CD8(int a, int b);

extern "C" void func_001E0038(int mode)
{
    if (func_001DED40()) return;
    switch (mode) {
    case -1:
        if (!D_0038E16C) func_001E0038(0);
        break;
    case 1:
        D_0038E16C = D_0038E168;
        D_0038E168 = 1;
        func_001E3CD8(1, 0);
        break;
    case 0:
        D_0038E168 = 0;
        func_001E3CD8(0, 0);
        break;
    }
}
