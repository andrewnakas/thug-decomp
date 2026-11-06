extern "C" void func_001E28F8(int reg, int value, int a, int b);

extern "C" bool func_001E34F8(float x)
{
    int v = (int)(x * 163.83f);
    if (v >= 0x4000)
        v = 0x3FFF;
    func_001E28F8(0xB0, (v << 16) | v, 0, 0);
    return true;
}
