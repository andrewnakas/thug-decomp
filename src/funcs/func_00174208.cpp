struct Buf_00174208 {
    unsigned long m_lo : 32;
    unsigned long m_hi : 32;
};

extern Buf_00174208* D_003942AC;

extern "C" void func_0031B490(int a);
extern "C" void func_00331238();
extern "C" void func_0031B308(int a);
extern "C" void func_001651F8(int a, int b, int c, int d);
extern "C" void func_001742D0();
extern "C" void func_00345160(int a);
extern "C" void func_0031BF20(int a);
extern "C" void func_003312D8(int a, int b);

extern "C" void func_00174208()
{
    func_0031B490(1);
    func_00331238();
    func_0031B308(1);
    func_001742D0();
    func_00345160(0);
    func_0031BF20(0);
    *(volatile int*)0x10009020 = 0;
    *(volatile int*)0x10009030 = D_003942AC->m_hi;
    *(volatile int*)0x10009000 = 0x145;
    func_003312D8(0, 0);
    func_001651F8(1, 0, 0, 0);
}
