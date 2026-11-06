extern "C" int func_00320438();
extern "C" int func_00320490();

extern "C" void func_001F5AF8(unsigned int chcr)
{
    func_00320438();
    *(volatile unsigned int*)0x1000F590 = *(volatile unsigned int*)0x1000F520 | 0x10000;
    *(volatile unsigned int*)0x1000B400 = chcr;
    *(volatile unsigned int*)0x1000F590 = *(volatile unsigned int*)0x1000F520 & ~0x10000;
    func_00320490();
}
