extern int D_0038BE38;
extern int D_0038BE3C;
extern char D_00360F90[];
extern char D_00360FB0[];

extern "C" int func_00164920(int cause);
extern "C" int func_00164AC8(int cause);
extern "C" int func_0031B9B0(int cause, int (*handler)(int), int next);
extern "C" int func_0031B980(int cause, int (*handler)(int), int next);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00334148(int code);
extern "C" int func_0031C3A0(int cause);
extern "C" int func_0031C2D0(int cause);

extern "C" void func_001742D0()
{
    D_0038BE38 = func_0031B9B0(2, func_00164920, 0);
    if (D_0038BE38 == -1) {
        func_00103F28(D_00360F90);
        func_00334148(1);
    }
    *(volatile int*)0x1000E010 = 4;
    func_0031C3A0(2);
    D_0038BE3C = func_0031B980(0, func_00164AC8, 0);
    if (D_0038BE3C == -1) {
        func_00103F28(D_00360FB0);
        func_00334148(1);
    }
    *(volatile long*)0x12001010 = 0xFE00;
    func_0031C2D0(0);
    *(volatile int*)0x10003010 = 0;
}
