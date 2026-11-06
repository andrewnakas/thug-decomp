extern char D_00364658[];
extern int D_0038E278;

extern "C" void func_00320438();
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_001E2840();
extern "C" void func_001E2880();
extern "C" void func_0031D0E8(int cause, void (*handler)(), int arg);
extern "C" void func_00320490();
extern "C" void func_001E2AA8();
extern "C" void func_0031BF20(int a);
extern "C" void func_001E34A0();
extern "C" void func_001E28F8(int a, int b, int c, int d);

extern "C" void func_001E33F8()
{
    for (int i = 0; i < 3; i++) {
    }
    func_00320438();
    func_00103F28(D_00364658);
    func_0031D0E8(0, func_001E2840, 0);
    func_0031D0E8(2, func_001E2880, 0);
    func_00320490();
    func_001E2AA8();
    func_0031BF20(0);
    func_001E34A0();
    func_001E28F8(0, D_0038E278, 0, 0);
}
