extern int D_00388DA8;
extern "C" void func_0010F808();
extern "C" int func_0010F8B8(int cause);
extern "C" int func_0031B980(int cause, int (*handler)(int), int next);
extern "C" int func_0031C2D0(int cause);

extern "C" void func_0010F8E0()
{
    func_0010F808();
    D_00388DA8 = func_0031B980(2, func_0010F8B8, 0);
    func_0031C2D0(2);
}
