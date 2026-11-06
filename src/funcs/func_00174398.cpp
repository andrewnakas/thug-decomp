extern int D_0038BE38;
extern int D_0038BE3C;
extern "C" int func_0031C338(int cause);
extern "C" int func_0031B9D0(int cause, int id);
extern "C" int func_0031C268(int ch);
extern "C" int func_0031B9A0(int ch, int id);

void func_00174398()
{
    func_0031C338(2);
    if (D_0038BE38 >= 0) {
        func_0031B9D0(2, D_0038BE38);
        D_0038BE38 = -1;
    }
    func_0031C268(0);
    if (D_0038BE3C >= 0) {
        func_0031B9A0(0, D_0038BE3C);
        D_0038BE3C = -1;
    }
}
