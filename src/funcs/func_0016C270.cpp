extern "C" int func_0031B980(int a, void* fn, int b);
extern "C" void func_0016B8B8();
extern int D_0038BB10;
extern int D_00393F3C;
extern int D_00393F40;

void Start_0016C270(int a)
{
    if (D_0038BB10 < 0) {
        D_00393F3C = a;
        D_00393F40 = 0;
        D_0038BB10 = func_0031B980(2, (void*)func_0016B8B8, -1);
    }
}
