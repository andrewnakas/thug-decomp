struct Obj_001F6500 {
    char pad[0x40];
    int m40;
    int Stop();
};
extern "C" void func_001F5AF8(int ch);
extern "C" void func_0031BCB0(int s);

int Obj_001F6500::Stop()
{
    func_001F5AF8(5);
    *(volatile int*)0x1000B420 = 0;
    *(volatile int*)0x1000B410 = 0;
    *(volatile int*)0x1000B430 = 0;
    func_0031BCB0(m40);
    return 1;
}
