extern unsigned int D_0038E280;
extern "C" int func_001E28A8(unsigned int* out);

extern "C" void func_001E3308()
{
    unsigned int v;
    if (!func_001E28A8(&v))
        return;
    for (int i = 0; i < 4; i++)
        D_0038E280 &= ~((0x100 << i) | (0x1000 << i));
    D_0038E280 |= v;
}
