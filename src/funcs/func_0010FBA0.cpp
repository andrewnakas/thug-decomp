extern long D_00393EC0;
extern volatile unsigned int D_00388D7C;
extern int D_00388830;
extern unsigned int D_00388D80;
extern "C" long func_0010FA98();
extern "C" unsigned int func_0033EBE0(float x);

extern "C" void func_0010FBA0()
{
    while (D_00393EC0 == func_0010FA98()) {
    }
    D_00393EC0 = func_0010FA98();
    unsigned int frames = D_00388D7C;
    int rate = D_00388830;
    D_00388D80 = func_0033EBE0((float)frames * (1000.0f / (float)rate));
}
