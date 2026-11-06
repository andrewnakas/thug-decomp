extern "C" int func_00320438();
extern "C" int func_00320490();

extern "C" void func_001F5A88(unsigned int v)
{
    func_00320438();
    *(volatile unsigned int*)0x1000F590 = *(volatile unsigned int*)0x1000F520 | 0x10000;
    *(volatile unsigned int*)0x1000B000 = v;
    *(volatile unsigned int*)0x1000F590 = *(volatile unsigned int*)0x1000F520 & 0xFFFEFFFF;
    func_00320490();
}
