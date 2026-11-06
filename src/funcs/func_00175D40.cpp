extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern unsigned int D_003942F0;
extern int D_00394004;
extern unsigned int D_00394008;
extern int D_0039400C;
extern unsigned int D_00394010;
extern int D_00394014;
extern unsigned int D_00394018;
extern int D_0039401C;
extern "C" void func_00175BE0(int a, unsigned int count, int b, int c, int d);

extern "C" void func_00175D40(int a, unsigned int stride, int b, unsigned int max, int d)
{
    D_00394004 = a;
    D_00394008 = stride;
    D_0039400C = b;
    D_00394010 = max;
    D_00394014 = d;
    D_00394018 = (D_003942F0 - ((D_00394280 - D_00394294) & 0x3FF) - 1) / stride;
    if (max < D_00394018) {
        D_00394018 = max;
    }
    func_00175BE0(a, stride, b, 1, d);
    D_0039401C = 0;
}
